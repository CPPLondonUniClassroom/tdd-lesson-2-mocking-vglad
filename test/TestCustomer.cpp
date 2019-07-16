#include "catch.hpp"
#include "catch2/trompeloeil.hpp"

#include "Customer.h"

using trompeloeil::deathwatched;



class MockRentable : public IRentable {
    MAKE_CONST_MOCK0(Title, const std::string&(), override);
    MAKE_CONST_MOCK0(Type, const std::string&(), override);
    MAKE_CONST_MOCK0(RentalStart, clock_time(), override);
    MAKE_CONST_MOCK0(RentalEnd, clock_time(), override);
    MAKE_CONST_MOCK0(CostPerDay, Money(), override);
    MAKE_CONST_MOCK0(PenaltyPerDay, Money(), override);

    MAKE_MOCK1(RentalStart, void(clock_time), override);
    MAKE_MOCK1(RentalEnd, void(clock_time), override);
};

TEST_CASE("Customer class correctly assign name John Smith") {
    Customer custImpl{"John Smith", ""};
    const ICustomer& cust = custImpl;
    REQUIRE(cust.Name() == "John Smith");
}

TEST_CASE("Customer class correctly assign name Judge Dredd") {
    Customer custImpl{"Judge Dredd", ""};
    const ICustomer& cust = custImpl;
    REQUIRE(cust.Name() == "Judge Dredd");
}

TEST_CASE("Customer class correctly stores and deletes some Rentable Items") {
    auto item = std::make_unique<deathwatched<MockRentable>>();
    REQUIRE_DESTRUCTION(*item);

    Customer custImpl{"Johnny Smith", ""};
    ICustomer& cust = custImpl;

    cust.AssignRental(std::move(item));
    REQUIRE(cust.Rentals().size() == 1);
    cust.RemoveRental(0);
    REQUIRE(cust.Rentals().size() == 0);

}

TEST_CASE("The rest of Customer clas is implemented correctly") {
    Customer custImpl{"Johnny Smith", "1 Infinite Loop"};
    ICustomer& cust = custImpl;

    CHECK(cust.Name() == "Johnny Smith");
    CHECK(cust.Address() == "1 Infinite Loop");
    CHECK(cust.Balance() == Money{0, 0});
    cust.AdjustBalance({3, 46});
    CHECK(cust.Balance() == Money{3, 46});
    cust.AdjustBalance({-1, -16});
    CHECK(cust.Balance() == Money{2, 30});


}
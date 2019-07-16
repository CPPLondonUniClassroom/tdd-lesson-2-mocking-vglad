#include "Money.h"
#include "catch.hpp"

TEST_CASE("A Money class with 5.14 + 1.99 returns 7.13"){
    Money sum {5, 14};
    sum += Money{1, 99};

    CHECK(sum.Pounds() == 7);
    CHECK(static_cast<int>(sum.Pence()) == 13);
}

TEST_CASE("A Money class with 2.45 - 0.46 returns 1.99"){
    Money sum {2, 45};
    sum += Money{0, -46};

    CHECK(sum.Pounds() == 1);
    CHECK(static_cast<int>(sum.Pence()) == 99);
}

TEST_CASE("A Money class correctly adjust 2.123 to 3.23"){
    Money sum {2, 123};

    CHECK(sum.Pounds() == 3);
    CHECK(static_cast<int>(sum.Pence()) == 23);
}

TEST_CASE("A Money class correctly add 0.99 + 0.99 returns 1.88"){
    Money sum {0, 99};
    sum += Money{0, 99};

    CHECK(sum.Pounds() == 1);
    CHECK(static_cast<int>(sum.Pence()) == 98);
}

TEST_CASE("A Money class correctly subtract 0.10 - 0.30 returns -0.20"){
    Money sum {0, 10};
    sum += Money{0, -30};

    CHECK(sum.Pounds() == 0);
    CHECK(static_cast<int>(sum.Pence()) == -20);
}

TEST_CASE("Equality operator behaves correctly"){
    CHECK(Money{12, 99} == Money {12, 99});
    CHECK((Money{1,12} == Money{0, 34}) == false);
}

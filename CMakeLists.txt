cmake_minimum_required(VERSION 3.11)
project(Blockbuster)

set(CMAKE_CXX_STANDARD 17)

add_executable(Blockbuster
        main.cpp
        include/interface/IRentable.h
        include/interface/ICustomer.h
        include/Video.h
        src/Video.cpp
        include/Money.h
        include/Customer.h
        src/Customer.cpp test/mocks/MockRentable.h test/mocks/MockCustomer.h)

target_include_directories(Blockbuster PRIVATE include)

add_executable(TestBlockbuster
        test/catch.hpp
        test/trompeloeil.hpp
        test/testmain.cpp
        test/TestCustomer.cpp
        include/Customer.h
        src/Customer.cpp test/TestRentalController.cpp)

target_include_directories(TestBlockbuster PRIVATE include)
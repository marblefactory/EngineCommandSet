//
//  test_result.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "result.hpp"
#include <string>

using namespace std;

// Tries to convert the string to an integer, returning an error if not
// successful.
Result<int> r_stoi(string str) {
    try {
        return Result<int>(stoi(str));
    }
    catch(...) {
        return Result<int>::error("error");
    }
}

TEST_CASE("Results can contain result containing a value", "[Result]") {
    SECTION("contains a value") {
        auto r = Result<string>("2");
        
        REQUIRE(r.contains_value);
        REQUIRE(r.get_value() == "2");
    }
    
    SECTION("bind produces a new value") {
        auto r = Result<string>("10").bind(r_stoi);
        
        REQUIRE(r.contains_value);
        REQUIRE(r.get_value() == 10);
    }
    
    SECTION("bind produces a result containing nothing") {
        auto r = Result<string>("value").bind(r_stoi);
        
        REQUIRE(!r.contains_value);
    }
}

TEST_CASE("Results can contain an error message", "[Result]") {
    SECTION("does not contain a value") {
        auto r = Result<string>::error("message");
        
        REQUIRE(!r.contains_value);
    }
    
    SECTION("accessing throws an error") {
        auto r = Result<string>::error("message");
        
        CHECK_THROWS_AS(r.get_value(), exception);
    }
    
    SECTION("bind produces a result containing nothing") {
        auto r = Result<string>::error("message").bind(r_stoi);
        
        REQUIRE(!r.contains_value);
    }
}

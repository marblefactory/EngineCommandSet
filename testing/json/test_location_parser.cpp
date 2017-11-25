//
//  test_location_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "json.hpp"
#include "location_parser.hpp"

using namespace json_parsing;

SCENARIO("Parsing Locations") {
    GIVEN("JSON where the type is missing") {
        json j = {
            {"place_name", "Room 6B"}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(parse_location(j));
        }
    }
    
    GIVEN("JSON where the type is invalid") {
        json j = {
            {"type", "what is this type"}
        };
        THEN("an exception is thrown") {
            REQUIRE_THROWS(parse_location(j));
        }
    }
} 

SCENARIO("Parsing an AbsoluteLocation") {
    GIVEN("valid JSON") {
        json j = {
            {"type", "absolute"}
        };
        
        THEN("an AbsoluteLocation is parsed") {
            AbsoluteLocation *l = (AbsoluteLocation*)parse_location(j);
        }
    }
}

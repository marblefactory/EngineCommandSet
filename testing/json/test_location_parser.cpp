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
            {"room_name", "Room 6B"}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(ParseLocation(j));
        }
    }
    
    GIVEN("JSON where the type is invalid") {
        json j = {
            {"type", "what is this type"},
            {"room_name", "Room 6B"}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(ParseLocation(j));
        }
    }
}

SCENARIO("Parsing an AbsoluteLocation") {
    GIVEN("valid JSON") {
        json j = {
            {"type", "absolute"},
            {"room_name", "Room 1"}
        };
        
        THEN("an AbsoluteLocation is parsed") {
            AbsoluteLocation *l = (AbsoluteLocation*)ParseLocation(j);
            
            REQUIRE(l->room_name == "Room 1");
        }
    }
    
    GIVEN("JSON where the room_name is missing") {
        json j = {
            {"type", "absolute"}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(ParseLocation(j));
        }
    }
}

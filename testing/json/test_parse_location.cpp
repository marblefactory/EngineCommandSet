//
//  test_parse_location.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "json.hpp"
#include "location_parser.hpp"

SCENARIO("Parsing AbsoluteLocations") {
    GIVEN("valid JSON") {
        json j = {
            {"type", "absolute"},
            {"room_name", "Room 6B"}
        };
        
        THEN("the AbsoluteLocation is parsed") {
            AbsoluteLocation* l = ParseAbsoluteLocation(j);
            
            REQUIRE(l->room_name == "Room 6B");
        }
    }
    
    GIVEN("JSON where the room_name is missing") {
        json j = {
            {"type", "absolute"}
        };
        
        THEN("the AbsoluteLocation is not parsed") {
            REQUIRE_THROWS(ParseAbsoluteLocation(j));
        }
    }
}

SCENARIO("Parsing Locations") {
    GIVEN("JSON for an absolute location") {
        json j = {
            {"type", "absolute"},
            {"room_name", "Room 1"}
        };
        
        THEN("an AbsoluteLocation is parsed") {
            AbsoluteLocation *l = (AbsoluteLocation*)ParseLocation(j);
            
            REQUIRE(l->room_name == "Room 1");
        }
    }
    
    GIVEN("JSON where the location type is missing") {
        json j = {
            {"room_name", "Room 6B"}
        };
        
        THEN("the Location is not parsed") {
            REQUIRE_THROWS(ParseLocation(j));
        }
    }
    
    GIVEN("JSON where the location type is invalid") {
        json j = {
            {"type", "what is this type"},
            {"room_name", "Room 6B"}
        };
        
        THEN("the Location is not parsed") {
            REQUIRE_THROWS(ParseLocation(j));
        }
    }
}

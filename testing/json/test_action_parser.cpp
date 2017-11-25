//
//  test_action_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "action.hpp"
#include "action_parser.hpp"

using namespace json_parsing;

SCENARIO("Parsing Actions") {
    GIVEN("JSON where the type is missing") {
        json j = {
            {"dest",{
                {"name", "door"},
                {"location", {
                    {"type", "absolute"},
                    {"room_name", "Room 6B"}
                }}
            }}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(parse_action(j));
        }
    }
    
    GIVEN("JSON where the type is invalid") {
        json j = {
            {"type", "not a type"},
            {"dest",{
                {"name", "door"},
                {"location", {
                    {"type", "absolute"},
                    {"room_name", "Room 6B"}
                }}
            }}
        };
        
        THEN("an exception is thrown") {
            REQUIRE_THROWS(parse_action(j));
        }
    }

}

SCENARIO("Parsing Move Actions") {
    GIVEN("valid JSON") {
        json j = {
            {"type", "move"},
            {"dest",{
                {"name", "door"},
                {"location", {
                    {"type", "absolute"}
                }}
            }}
        };
        
        THEN("a Move is parsed") {
            Move *move = (Move*)parse_action(j);
            AbsoluteLocation *loc = (AbsoluteLocation*)move->dest->location;
            
            REQUIRE(move->dest->name == "door");
        }
    }
}


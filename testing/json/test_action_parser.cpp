//
//  test_action_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include <stdio.h>

//using namespace json_parsing;

//SCENARIO("Parsing Objects") {
//    GIVEN("Valid JSON") {
//        json j = {
//            {"name", "door"},
//            {"location", {
//                {"type", "absolute"},
//                {"room_name", "Room 6B"}
//            }}
//        };
//        
//        Object *obj = ParseObject(j);
//        AbsoluteLocation *loc = (AbsoluteLocation*)obj->location;
//        
//        REQUIRE(obj->name == "door");
//        REQUIRE(loc->room_name == "Room 6B");
//    }
//    
//    GIVEN("JSON where the name is missing") {
//        THEN("an exception is thrown") {
//            json j = {
//                {"location", {
//                    {"type", "absolute"},
//                    {"room_name", "Room 6B"}
//                }}
//            };
//            
//            REQUIRE_THROWS(ParseObject(j));
//        }
//    }
//    
//    GIVEN("JSON where the location is missing") {
//        THEN("an exception is thrown") {
//            json j = {
//                {"name", "door"}
//            };
//            
//            REQUIRE_THROWS(ParseObject(j));
//        }
//    }
//}

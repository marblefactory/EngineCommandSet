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

TEST_CASE("AbsoluteLocations can be parsed from JSON") {
    json j = {
        {"type", "absolute"},
        {"room_name", "Room 6B"}
    };
    
    Result<AbsoluteLocation*> r = ParseAbsoluteLocation(j);
    
    REQUIRE(r.get_value()->room_name == "Room 6B");
}

TEST_CASE("AbsoluteLocations cannot be parsed from JSON if missing a room_name") {
    json j = {
        {"type", "absolute"}
    };
    
    Result<AbsoluteLocation*> r = ParseAbsoluteLocation(j);
    
    REQUIRE(!r.contains_value);
}

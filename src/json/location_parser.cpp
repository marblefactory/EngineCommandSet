//
//  location_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "location_parser.hpp"
#include "json_helper.hpp"

namespace json_parsing {
    // Returns a parsed AbsoluteLocation, or throws if parsing was unsuccessful.
    AbsoluteLocation* parse_absolute_location(json j) throw(exception) {
        auto room_name = j["room_name"];
        
        if (room_name.is_null()) {
            throw MissingJsonFieldParseError("room_name", "AbsoluteLocation");
        }
        
        return new AbsoluteLocation(room_name.get<string>());
    }
    
    // Returns a parsed Location, or an throws if parsing was unsuccessful.
    Location* parse_location(json j) throw(exception) {
        auto type = j["type"];
        
        if (type.is_null()) {
            throw MissingJsonFieldParseError("type", "Location");
        }
        
        string str_type = type.get<string>();
        
        if (str_type == "absolute") {
            return parse_absolute_location(j);
        }
        
        throw UnknownJsonFieldParseError("type", "Location");
    }
}

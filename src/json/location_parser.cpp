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
    // Returns a parsed Location, or an throws if parsing was unsuccessful.
    Location* parse_location(json j) throw(exception) {
        auto type = j["type"];
        
        if (type.is_null()) {
            throw MissingJsonFieldParseError("type", "Location");
        }
        
        string str_type = type.get<string>();
        
        if (str_type == "absolute") {
            return new AbsoluteLocation();
        }
        
        throw UnknownJsonFieldParseError("type", "Location");
    }
}

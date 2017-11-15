//
//  location_parser.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef location_parser_h
#define location_parser_h

#include "locations.hpp"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;
using namespace std;

// Returns a parsed AbsoluteLocation, or throws if parsing was unsuccessful.
AbsoluteLocation* ParseAbsoluteLocation(json j) throw(exception) {
    auto room_name = j["room_name"];
    
    if (room_name.is_null()) {
        throw runtime_error("Missing room_name for AbsoluteLocation");
    }
    
    return new AbsoluteLocation(room_name.get<string>());
}

// Returns a parsed Location, or an throws if parsing was unsuccessful.
Location* ParseLocation(json j) throw(exception) {
    auto type = j["type"];
    
    if (type.is_null()) {
        throw runtime_error("Missing location type");
    }
    
    string str_type = type.get<string>();
    
    if (str_type == "absolute") {
        return ParseAbsoluteLocation(j);
    }
    
    throw runtime_error("Unrecognised location type");
}

#endif /* location_parser_h */

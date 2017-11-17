//
//  location_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "location_parser.hpp"

using runtime_error = std::runtime_error;

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

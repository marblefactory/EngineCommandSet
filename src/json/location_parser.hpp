//
//  location_parser.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef location_parser_h
#define location_parser_h

#include "result.hpp"
#include "locations.hpp"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

// Returns a parsed Location, or an error message if parsing was unsuccessful.
Result<Location*> ParseLocation(json j) {
    return Result<Location*>::error("Err");
}

// Returns a parsed AbsoluteLocation, or an error message if parsing was
// unsuccessful.
Result<AbsoluteLocation*> ParseAbsoluteLocation(json j) {
    auto room_name = j["room_name"];
    
    if (room_name.is_null()) {
        return Result<AbsoluteLocation*>::error("No room_name for AbsoluteLocation");
    }
    
    AbsoluteLocation *loc = new AbsoluteLocation(room_name.get<string>());
    return Result<AbsoluteLocation*>(loc);
}

#endif /* location_parser_h */

//
//  object_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "object_parser.hpp"
#include "location_parser.hpp"
#include "json_helper.hpp"

namespace json_parsing {
    // Returns the parsed Object, or throws if parsing was unsuccessful.
    Object *ParseObject(json j) throw(exception) {
        auto name_json = j["name"];
        auto location_json = j["location"];
        
        if (name_json.is_null()) {
            throw MissingJsonFieldParseError("name", "Object");
        }
        
        if (location_json.is_null()) {
            throw MissingJsonFieldParseError("location", "Object");
        }
        
        Location *loc = ParseLocation(location_json);
        
        return new Object(name_json.get<string>(), loc);
    }
}

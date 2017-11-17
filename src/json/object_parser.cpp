//
//  object_parser.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "object_parser.hpp"
#include "location_parser.hpp"

using runtime_error = std::runtime_error;

namespace json_parsing {
    // Returns the parsed Object, or throws if parsing was unsuccessful.
    Object *ParseObject(json j) throw(exception) {
        auto name_json = j["name"];
        auto location_json = j["location"];
        
        if (name_json.is_null()) {
            throw runtime_error("Missing name in object");
        }
        
        if (location_json.is_null()) {
            throw runtime_error("Missing location in object");
        }
        
        Location *loc = ParseLocation(location_json);
        
        return new Object(name_json.get<string>(), loc);
    }
}

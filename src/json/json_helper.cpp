//
//  json_helper.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 18/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "json_helper.hpp"

namespace json_parsing {
    // Creates an exception saying that missing_field_name was missing from
    // the JSON used to try and parse an object of type class_name.
    runtime_error MissingJsonFieldParseError(string missing_field_name, string class_name) {
        return runtime_error("Missing '" + missing_field_name + "' when parsing '" + class_name + "'");
    }
    
    // Creates an exception saying that the value of unknown_field_name was
    // unrecognised, from the JSON used to try and parse an object of type
    // class_name.
    runtime_error UnknownJsonFieldParseError(string unknown_field_name, string class_name) {
        return runtime_error("Unknown value for field '" + unknown_field_name + "' when parsing '" + class_name + "'");
    }
}

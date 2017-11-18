//
//  json_helper.hpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef json_helper_hpp
#define json_helper_hpp

#include <string>

using runtime_error = std::runtime_error;
using string = std::string;

namespace json_parsing {
    // Creates an exception saying that missing_field_name was missing from
    // the JSON used to try and parse an object of type class_name.
    runtime_error MissingJsonFieldParseError(string missing_field_name, string class_name);
    
    // Creates an exception saying that the value of unknown_field_name was
    // unrecognised, from the JSON used to try and parse an object of type
    // class_name.
    runtime_error UnknownJsonFieldParseError(string unknown_field_name, string class_name);
}

#endif /* json_helper_hpp */

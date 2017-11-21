//
//  object_parser.hpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef object_parser_hpp
#define object_parser_hpp

#include "json.hpp"
#include "object.hpp"

using json = nlohmann::json;
using exception = std::exception;

namespace json_parsing {
    // Returns the parsed Object, or throws if parsing was unsuccessful.
    Object *parse_object(json j) throw(exception);
}

#endif /* object_parser_hpp */

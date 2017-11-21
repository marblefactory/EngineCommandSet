//
//  action_parser.hpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef action_parser_hpp
#define action_parser_hpp

#include "json.hpp"
#include "object.hpp"
#include "action.hpp"

using json = nlohmann::json;
using exception = std::exception;

namespace json_parsing {
    // Parses an Action, throws if parsing was unsuccessful.
    Action *parse_action(json j) throw(exception);
}

#endif /* action_parser_hpp */

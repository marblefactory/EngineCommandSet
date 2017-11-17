//
//  location_parser.hpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 17/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef location_parser_hpp
#define location_parser_hpp

#include "locations.hpp"
#include "json.hpp"

using json = nlohmann::json;
using exception = std::exception;

// Returns a parsed AbsoluteLocation, or throws if parsing was unsuccessful.
AbsoluteLocation* ParseAbsoluteLocation(json j) throw(exception);

// Returns a parsed Location, or an throws if parsing was unsuccessful.
Location* ParseLocation(json j) throw(exception);

#endif /* location_parser_hpp */

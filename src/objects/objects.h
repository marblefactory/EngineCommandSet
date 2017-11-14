//
//  object.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef object_h
#define object_h

#include <string>
#include "locations.h"

using namespace std;

// Represents an object, e.g. the table in room 812.
class Object {
public:
    const string name;
    const Location &location;
    
    Object(string name, Location location): name(name), location(location) {
    }
};

#endif /* object_h */

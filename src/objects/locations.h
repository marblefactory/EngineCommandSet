//
//  locations.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef locations_h
#define locations_h

#include <string>

using namespace std;

class Location {
};

class AbsoluteLocation: public Location {
public:
    // The name of the location in the game, e.g. Room 6B.
    const string room_name;
    
    AbsoluteLocation(string room_name): room_name(room_name) {
    }
};


#endif /* locations_h */

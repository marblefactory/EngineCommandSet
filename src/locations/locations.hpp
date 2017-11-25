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
#include "location_visitor.hpp"

using std::string;

class Location {
public:
    virtual void accept(LocationVisitor &visitor) = 0;
};

class AbsoluteLocation: public Location {
public:
    AbsoluteLocation() {
    }
    
    void accept(LocationVisitor &visitor) override {
        visitor.visit(*this);
    }
};


#endif /* locations_h */

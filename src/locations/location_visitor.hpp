//
//  location_visitor.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef location_visitor_h
#define location_visitor_h

// Forward declarations.
class AbsoluteLocation;

class LocationVisitor {
public:
    virtual void visit(AbsoluteLocation &location) = 0;
};

#endif /* location_visitor_h */

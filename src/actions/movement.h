//
//  movement.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef movement_h
#define movement_h

#include "objects.h"
#include "actions.h"

// Represents a move the spy can make.
class Move: public Action {
public:
    // The destination of the movement, i.e. where the spy will end up after
    // executing the movement.
    Object &dest;
    
    Move(Object &dest): dest(dest) {
    }
    
    void accept(ActionVisitor &visitor) override {
        visitor.visit(*this);
    }
};

#endif /* movement_h */

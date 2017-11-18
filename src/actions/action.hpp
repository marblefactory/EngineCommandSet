//
//  action.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef action_h
#define action_h

#include "action_visitor.hpp"
#include "object.hpp"

// Parent class for other actions, e.g. movement, interaction, etc
class Action {
public:
    virtual void accept(ActionVisitor &visitor) = 0;
};

// Represents a move the spy can make.
class Move: public Action {
public:
    // The destination of the movement, i.e. where the spy will end up after
    // executing the movement.
    Object *dest;
    
    Move(Object *dest): dest(dest) {
    }
    
    void accept(ActionVisitor &visitor) override {
        visitor.visit(*this);
    }
};

#endif /* action_h */

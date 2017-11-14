//
//  movement.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef movement_h
#define movement_h

#include "actions.h"

// Represents a move the spy can make.
class Move: public Action {
public:
    void accept(ActionVisitor &visitor) {
        visitor.visit(*this);
    }
};

#endif /* movement_h */

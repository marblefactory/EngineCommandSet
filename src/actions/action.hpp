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

// Parent class for other actions, e.g. movement, interaction, etc
class Action {
public:
    virtual void accept(ActionVisitor &visitor) = 0;
};

#endif /* action_h */

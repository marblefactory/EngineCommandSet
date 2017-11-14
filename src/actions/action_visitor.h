//
//  action_visitor.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef action_visitor_h
#define action_visitor_h

// Forward declarations.
class Move;

class ActionVisitor {
public:
    virtual void visit(Move &move) = 0;
};

#endif /* action_visitor_h */

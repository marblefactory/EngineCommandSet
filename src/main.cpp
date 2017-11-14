//
//  main.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include <iostream>
#include "objects.h"
#include "actions.h"
#include "locations.h"
#include "movement.h"

using namespace std;

class PrintLocVisitor: public LocationVisitor {
public:
    void visit(AbsoluteLocation &location) override {
        cout << "in " << location.room_name;
    }
};
        
class PrintActionVisitor: public ActionVisitor {
public:
    void visit(Move &move) override {
        cout << "Moving to " << move.dest.name << " ";
        
        PrintLocVisitor v;
        move.dest.location.accept(v);
    }
};


int main(int argc, const char * argv[]) {
    AbsoluteLocation l("Room B");
    Object obj("table", l);
    Move move(obj);
    
    PrintActionVisitor v;
    move.accept(v);
    
    cout << endl;
    
    return 0;
}

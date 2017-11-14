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

int main(int argc, const char * argv[]) {
    AbsoluteLocation l("Room B");
    Object obj("table", l);
    
    cout << obj.name << endl;
    
    return 0;
}

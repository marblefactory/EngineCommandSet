//
//  test_location_visitor.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "locations.hpp"

// Used for testing. Stores the location it last visited.
class MockLocationVisitor: public LocationVisitor {
public:
    Location *visited_loc = nullptr;
    
    void visit(AbsoluteLocation &location) override {
        this->visited_loc = &location;
    }
};

SCENARIO("Visiting AbsoluteLocations") {
    AbsoluteLocation loc;
    MockLocationVisitor visitor;
    
    loc.accept(visitor);
    REQUIRE(visitor.visited_loc == &loc);
}

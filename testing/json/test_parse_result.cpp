//
//  test_parse_result.cpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#include "catch.hpp"
#include "parse_result.hpp"

ParseResult<int> mult10(int r) {
    return ParseResult<int>(r * 10);
}

TEST_CASE("parse results can be initialised to contain a value", "[ParseResult]") {
    auto r = ParseResult<int>(10);
    
    REQUIRE(r.value() == 10);
}

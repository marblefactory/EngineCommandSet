//
//  parse_result.hpp
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef parse_result_hpp
#define parse_result_hpp

#include <string>

using namespace std;

// Represents the monad result of parsing json.
template<typename T> class ParseResult {
    // Used to store either the value, or an error message.
    union Data  {
        T value;
        char *error_msg;
    } data;
    
    // Whether data contains a value or error message.
    bool contains_value;
    
    // Initialises the result with an error message.
    ParseResult(char *error_msg): contains_value(false) {
        data = { .error_msg = error_msg };
    }
    
public:
    // Initialises the result with a value.
    ParseResult(T value): contains_value(true) {
        data = { .value = value };
    }
    
    static ParseResult<T> error(string error_msg) {
        return ParseResult(*error_msg.c_str());
    }
    
    template<typename U> ParseResult<U> bind(ParseResult<U>(*transform)(T)) {
        if (contains_value) {
            return transform(this->data->value);
        }
        return ParseResult<U>::error(this->data->error_msg);
    }
    
    // Returns the value contained in the result, or throws an error if the
    // result contains no value.
    T value() throw(char*) {
        if (!contains_value) {
            throw this->data.error_msg;
        }
        return this->data.value;
    }
};

#endif /* parse_result_hpp */

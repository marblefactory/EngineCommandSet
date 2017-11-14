
//
//  result.h
//  EngineCommandSet
//
//  Created by Albie Baker-Smith on 14/11/2017.
//  Copyright © 2017 Albie Baker-Smith. All rights reserved.
//

#ifndef result_h
#define result_h

#include <string>

using namespace std;

// Represents either a value or an error.
template<typename T> class Result {
private:
    T value;
    string error_msg;
    
    Result(string error_msg, bool contains_value): error_msg(error_msg), contains_value(contains_value) {
    }
    
public:
    // Whether the result contains a value (true) or an error (false).
    bool contains_value;
    
    Result(T value): value(value), contains_value(true) {
    }
    
    static Result<T> error(string message) {
        return Result(message, false);
    }
    
    // Returns the value contained in the result, or throws an error if the
    // result contains no value.
    T get_value() throw(exception) {
        if (!contains_value) {
            throw runtime_error(error_msg);
        }
        return value;
    }
    
    // Monadic bind.
    template<typename U> Result<U> bind(Result<U>(*transform)(T)) {
        if (contains_value) {
            return transform(value);
        }
        return Result<U>::error(error_msg);
    }
};

#endif /* result_h */

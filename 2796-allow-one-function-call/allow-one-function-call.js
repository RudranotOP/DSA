/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let hasBeenCalled = false; // 1. State variable to track execution
    let result;                // 2. Variable to store the first result (optional depending on interpretation, see below)

    return function(...args){
        if (!hasBeenCalled) {
            hasBeenCalled = true;      // 3. Update state
            return fn(...args);        // 4. Call fn and return its result
        }
        return undefined;              // 5. Return undefined on subsequent calls
    }
};
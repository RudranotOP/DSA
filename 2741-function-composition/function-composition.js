/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        // 1. Initialize the result with the input value 'x'
        let val = x;

        // 2. Iterate through the functions array in REVERSE order (right to left)
        for (let i = functions.length - 1; i >= 0; i--) {
            // 3. Update 'val' by passing it into the current function
            val = functions[i](val);
        }

        // 4. Return the final transformed value
        return val;
    };
};
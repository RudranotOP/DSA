/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    
    // We create a local variable 'current' to track changes.
    // 'init' stays unchanged so we can use it for the reset later.
    let current = init;

    return {
        increment: function() {
            current += 1;
            return current;
        },
        decrement: function() {
            current -= 1;
            return current;
        },
        reset: function() {
            current = init; // Restore the original value
            return current;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
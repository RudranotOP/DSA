/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    // The 'args' parameter collects all passed arguments into an array.
    // We simply return the length of that array.
    return args.length;
};
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // 1. Schedule the task (The Pizza Order)
    // We save the 'id' so we can find this specific timer later.
    const timerId = setTimeout(() => {
        fn(...args); // Execute the function with its arguments
    }, t);

    // 2. Create the cancellation button (The Special Phone Number)
    // This is the function the user will call if they want to stop it.
    const cancelFn = () => {
        clearTimeout(timerId);
    };

    // 3. Hand the button to the user
    return cancelFn;
};
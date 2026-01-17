/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // 1. Requirement: Execute the function immediately (at t=0)
    fn(...args);

    // 2. Start the repeating timer (The Loop)
    // We save the ID so we can stop it later
    const timerId = setInterval(() => {
        fn(...args);
    }, t);

    // 3. Create the cancellation function (The Stop Button)
    const cancelFn = () => {
        clearInterval(timerId);
    };

    // 4. Return the button to the user
    return cancelFn;
};
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // Wait for both promises to resolve in parallel
    const [val1, val2] = await Promise.all([promise1, promise2]);
    
    // Return the sum
    return val1 + val2;
};
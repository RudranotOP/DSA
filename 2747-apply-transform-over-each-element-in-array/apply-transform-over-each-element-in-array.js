/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // 1. Create a new array to store the results
    const result = [];

    // 2. Iterate over the input array
    for (let i = 0; i < arr.length; i++) {
        // 3. Apply the function 'fn' to the current element and its index
        //    The prompt specifies fn(arr[i], i)
        const transformedValue = fn(arr[i], i);

        // 4. Push the transformed value into the new array
        result.push(transformedValue);
    }

    // 5. Return the new array
    return result;
};
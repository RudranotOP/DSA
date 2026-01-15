/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // 1. Create a new array to store the filtered elements
    const filteredArr = [];

    // 2. Iterate through the input array
    for (let i = 0; i < arr.length; i++) {
        // 3. Apply the filtering function 'fn' to the current element and index
        //    We check if the result is "truthy"
        if (fn(arr[i], i)) {
            // 4. If true, keep the element by pushing it to the new array
            filteredArr.push(arr[i]);
        }
    }

    // 5. Return the result
    return filteredArr;
};
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    // 1. Initialize the accumulator with the 'init' value
    let accumulator = init;

    // 2. Iterate through each number in the array
    for (let i = 0; i < nums.length; i++) {
        // 3. Update the accumulator by passing the current result 
        //    and the current element to the reducer function 'fn'
        accumulator = fn(accumulator, nums[i]);
    }

    // 4. Return the final accumulated value
    return accumulator;
};
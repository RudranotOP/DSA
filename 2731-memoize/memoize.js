/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = {}; // 1. The Closure: This object persists across calls

    return function(...args) {
        // 2. Create a unique key for the inputs (e.g., [2, 3] becomes "[2,3]")
        const key = JSON.stringify(args); 
        
        // 3. Check if we've seen this key before
        if (key in cache) {
            return cache[key]; // Return cached value
        }
        
        // 4. If not, calculate the result
        const result = fn(...args);
        
        // 5. Store it in the cache for next time
        cache[key] = result;
        
        return result;
    }
}
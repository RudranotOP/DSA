/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const byId = new Map();

    for (const item of arr1) {
        byId.set(item.id, { ...item });
    }

    for (const item of arr2) {
        if (byId.has(item.id)) {
            byId.set(item.id, { ...byId.get(item.id), ...item });
        } else {
            byId.set(item.id, { ...item });
        }
    }

    return Array.from(byId.values()).sort((a, b) => a.id - b.id);
};
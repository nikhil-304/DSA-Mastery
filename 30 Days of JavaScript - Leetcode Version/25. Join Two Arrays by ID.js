/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
  // Map will store: id -> object
  // Helps us quickly check and update objects by id
  const map = new Map();

  // Step 1: Insert all objects from arr1 into map
  for (let obj of arr1) {
    // obj.id is the key
    // { ...obj } creates a shallow copy (avoids reference issues)
    // map.set(1, {id:1, x:2})
    // Means: store: 1 -> {id:1, x:2}
    map.set(obj.id, { ...obj });
  }

  // Step 2: Process arr2
  for (let obj of arr2) {
    // Check if this id already exists in map
    if (map.has(obj.id)) {
      // Get existing object from arr1
      const existing = map.get(obj.id);

      // Merge objects:
      // Spread existing first, then obj
      // If keys clash, obj (arr2) overrides existing (arr1)
      const merged = { ...existing, ...obj };

      // Update map with merged object
      map.set(obj.id, merged);
    } else {
      // If id not present, just insert it
      map.set(obj.id, { ...obj });
    }
  }

  // Step 3: Convert map values to array
  const result = Array.from(map.values());
  // map.values()
  // gives something like:
  // Iterator -> {id:1}, {id:2}
  // Array.from(...): Converts iterable -> array

  // Step 4: Sort by id in ascending order
  result.sort((a, b) => a.id - b.id);

  return result;
};

//Problem Link: https://leetcode.com/problems/join-two-arrays-by-id/

// map.has(id) → check if id exists
// map.get(id) → get old object
// map.set(id, obj) → insert/update

// { ...obj1, ...obj2 }
// copy obj1, then overwrite with obj2

// arr2 overrides arr1
// shallow merge (no deep merge)

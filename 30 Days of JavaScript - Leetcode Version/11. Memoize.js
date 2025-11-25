/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  let cache = {}; // store previous results

  return function (...args) {
    let key = JSON.stringify(args); // unique key for input

    if (cache[key] !== undefined) {
      return cache[key]; // return cached value
    }

    let result = fn(...args); // call original function
    cache[key] = result; // store result
    return result;
  };
}

// Problem Link: https://leetcode.com/problems/memoize/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */

/**
 * MEMOIZATION EXPLANATION
 * -------------------------------------------------------
 * Memoization means:
 * → Remembering previous function results (caching them)
 * → So if same inputs come again, we don’t recompute.
 *
 * In simple words:
 * "Don’t repeat the work you’ve already done — just reuse the answer!"
 *
 * -------------------------------------------------------
 * HOW IT WORKS
 * -------------------------------------------------------
 * Step 1: You pass your original function to `memoize(fn)`
 * Step 2: It returns a NEW version of that function
 *         which has a hidden memory (cache) inside.
 * Step 3: When you call that new function:
 *          - It first checks if result for those inputs is already stored.
 *          - If yes → returns the cached value (no real function call).
 *          - If no  → calls the real function, stores the result, and returns it.
 *
 * -------------------------------------------------------
 * LEETCODE'S TEST STYLE
 * -------------------------------------------------------
 * They call it like this:
 *
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *    callCount += 1;     // they track real calls from outside
 *    return a + b;
 * });
 *
 * memoizedFn(2, 3);  // computed → callCount = 1
 * memoizedFn(2, 3);  // cached   → callCount = 1 (not increased)
 *
 * So, your memoize function should ensure that
 * the original fn() is NOT called again for same inputs.
 *
/**
 * -------------------------------------------------------
 * 🧩 DRY RUN EXAMPLE
 * -------------------------------------------------------
 *
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *   callCount += 1;
 *   return a + b;
 * });
 *
 * memoizedFn(2, 3);   // 1️⃣ Not in cache → calls fn(2,3)
 *                     //    callCount = 1
 *                     //    stores cache["[2,3]"] = 5
 *                     //    returns 5
 *
 * memoizedFn(2, 3);   // 2️⃣ Already in cache
 *                     //    does NOT call fn again
 *                     //    returns 5 from cache
 *                     //    callCount still = 1
 *
 * memoizedFn(1, 2);   // 3️⃣ New input
 *                     //    calls fn(1,2)
 *                     //    callCount = 2
 *                     //    stores cache["[1,2]"] = 3
 *
 * memoizedFn(2, 3);   // 4️⃣ Already cached
 *                     //    returns 5
 *                     //    callCount still = 2
 *
 * ✅ Final cache:
 * {
 *   "[2,3]": 5,
 *   "[1,2]": 3
 * }
 *
 * ✅ Final callCount = 2
 *
 * -------------------------------------------------------
 * 🧩 SUMMARY TABLE
 * -------------------------------------------------------
 * | Step | Input  | Computed or Cached? | Returned | callCount |
 * |------|---------|---------------------|-----------|------------|
 * | 1    | (2,3)   | computed            | 5         | 1 |
 * | 2    | (2,3)   | cached              | 5         | 1 |
 * | 3    | (1,2)   | computed            | 3         | 2 |
 * | 4    | (2,3)   | cached              | 5         | 2 |
 *
 * -------------------------------------------------------
 * 🧠 QUICK RECAP
 * -------------------------------------------------------
 * - memoize() returns a new function that remembers old results.
 * - The cache lives inside memoize via closure.
 * - The function passed inside memoize is only called
 *   if that exact input hasn’t been seen before.
 * - In LeetCode, they track how many times fn() is called
 *   using an outside variable (callCount).
 * - Our job: make sure fn() is not called twice with same args.
 *
 */

/* ------------------------------------------------------------------
Explanation for this one-liner:
---------------------------------------------------------------------
const memoizedFn = memoize(function (a, b) {
  callCount += 1;
  return a + b;
});

Step-by-step breakdown:

1.  "memoize" is a higher-order function — meaning it takes a function as
     an input (here, an anonymous function `(a, b) => { ... }`) and returns
     a *new function* that has extra features (in this case: caching results).

2.  So when you write:
     const memoizedFn = memoize(fn);

     It doesn’t call "fn" immediately.
     It just passes "fn" into memoize(), and stores the returned function
     (the one with cache) inside "memoizedFn".

3.  Inside memoize(), it returns:
     return function(...args) { ... }   ← this is the function that handles
     caching and calling the original function.

4.  Now, whenever you later call:
     memoizedFn(2, 3);

     ➤ It executes that inner returned function.
     ➤ That function checks if the result is already in cache.
     ➤ If not, it calls the original function (the one you passed here):
           function (a, b) { callCount += 1; return a + b; }
       So only now, "callCount += 1" actually runs.

5.  Meaning:
     - When you define `memoizedFn = memoize(fn)` → function is *wrapped*.
     - When you *call* `memoizedFn(2,3)` → the original function *executes*
       only if the result wasn’t cached.

6.  In simple words:
     - "memoize" gives the original function a *memory*.
     - "memoizedFn" is the new smart version of your function.

Dry Run Example:

let callCount = 0;
const memoizedFn = memoize(function (a, b) {
  callCount += 1;
  return a + b;
});

memoizedFn(2, 3);  // First call → cache empty → fn runs → callCount = 1 → stores { "2,3": 5 }
memoizedFn(2, 3);  // Second call → cache hit → returns 5 → fn not called → callCount = 1
memoizedFn(1, 2);  // New args → fn runs again → callCount = 2 → stores { "1,2": 3 }

So callCount increases only for unique argument pairs.
------------------------------------------------------------------ */

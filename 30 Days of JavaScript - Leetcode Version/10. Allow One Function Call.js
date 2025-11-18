/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
  let called = false;
  return function (...args) {
    if (!called) {
      called = true;
      return fn(...args);
    }
    return undefined;
  };
};

// Problem Link: https://leetcode.com/problems/allow-one-function-call/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */

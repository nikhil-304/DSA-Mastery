/**
 * @param {number} n
 * @return {Function} counter
 */
/*
A closure is a special type of function that remembers the environment in which it was created, including all the local variables in its scope at that time.
*/
var createCounter = function (n) {
  let funcCallCounter = 0; // local variable inside createCounter
  return function () {
    return n + funcCallCounter++; // Increment on each call
  };
};

// Problem Link: https://leetcode.com/problems/counter/

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

/*
When the counter function is created (by calling createCounter), it captures the initial state of the variables like n = 10 and funcCallCounter = 0. Then, with each subsequent call to counter(), it uses those captured values and increments funcCallCounter as expected. This is the essence of how closures work in JavaScript.

1. First Call to counter(): return 10 + 0++; // returns 10
2. Second Call to counter(): return 10 + 1++; // returns 11
3. Third Call to counter(): return 10 + 2++; // returns 12
                       (first add, then increment)
*/

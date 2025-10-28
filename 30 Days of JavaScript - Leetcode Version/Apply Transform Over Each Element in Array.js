/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
  let newArray = [];

  for (let i = 0; i < arr.length; i++) {
    newArray.push(fn(arr[i], i));
  }

  return newArray;
};

// Problem Link: https://leetcode.com/problems/apply-transform-over-each-element-in-array/?envType=study-plan-v2&envId=30-days-of-javascript

// Function Flexibility in JavaScript:
// In JavaScript, functions are flexible with the number of arguments they can take.
// Even if a function is defined to accept fewer arguments, it can still be called with more arguments,
// and the extra ones will just be ignored.
//
// Example:
// Let's define a simple function that only takes one argument but is called with two arguments:
/*
function addOne(n) {
    return n + 1;  // This function only uses the first argument.
}
*/
// Calling the function with one argument:
//console.log(addOne(5));  // Output: 6

// Calling the function with two arguments (extra argument is ignored):
//console.log(addOne(5, 10));  // Output: 6  (The second argument '10' is ignored)

// This flexibility allows functions to be called in different ways without breaking, making code more reusable.
// For example, in the 'map' function, you can pass a function that takes both the element
// and its index, even though the function might only need one or the other.
// This makes your code more adaptable to different situations.

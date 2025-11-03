/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  return function (x) {
    let result = x;

    for (let i = functions.length - 1; i >= 0; i--) {
      result = functions[i](result);
      // Example with functions = [x => x + 1, x => 2 * x] and initial result = 4
      // 1st Iteration (i = 1):
      // functions[1] is x => 2 * x
      // functions  // 2 * 4 = 8
      // So, result now becomes 8

      // 2nd Iteration (i = 0):
      // functions[0] is x => x + 1
      // functions  // 8 + 1 = 9
      // Now, result is 9 (final result after all functions are applied)
    }
    return result;
  };
};

// Problem Link: https://leetcode.com/problems/function-composition/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */

/*
var compose = function(functions) {
    return function(x) {
        // Use reduceRight to apply functions from right to left
        return functions.reduceRight((acc, fn) => fn(acc), x);
    }
};
*/

/*
functions: This is your array of functions, like [x => x + 1, x => 2 * x].
reduceRight: This method iterates over functions from the last element to the first.
(acc, fn) => fn(acc): This is the callback function passed to reduceRight.
acc (short for "accumulator") is the running total that gets updated as you go through each function in the array.
fn is the current function being processed in the array.
So, each iteration, you apply the function (fn) to the accumulator (acc), and that updates the accumulator for the next iteration.
x: This is the initial value for acc in the first iteration, which is the input you give to the final composed function.
*/

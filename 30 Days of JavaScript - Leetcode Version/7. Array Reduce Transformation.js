/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
  if (nums.length === 0) return init;

  let val = init;

  for (let i = 0; i < nums.length; i++) {
    val = fn(val, nums[i]);
  }

  return val;
};

// Problem Link: https://leetcode.com/problems/array-reduce-transformation/?envType=study-plan-v2&envId=30-days-of-javascript

/*
nums.reduce((accumulator, currentValue) => {
  // your logic here
}, initialValue);

return nums.reduce((val, num) => {
    return fn(val, num);  // Apply fn to the accumulator (val) and the current element (num)
}, init);  // Set the initial value to `init`
*/

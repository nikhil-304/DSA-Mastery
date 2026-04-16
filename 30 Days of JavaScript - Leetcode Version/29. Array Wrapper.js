/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    // Store the input array in the instance
    this.arr = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    // Return the sum of all elements in the array
    return this.arr.reduce((sum, num) => sum + num, 0);
    /*
    sum -> running total
    num -> current element
    0 -> starting value
    */

    /*
    new ArrayWrapper([1,2]).valueOf() -> 3
    new ArrayWrapper([3,4]).valueOf() -> 7
    obj1 + obj2 → 3 + 7 = 10
    */
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    // Return the array as a comma-separated string surrounded by brackets
    return "[" + this.arr.join(",") + "]";
}

// Problem Link: https://leetcode.com/problems/array-wrapper/

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */

/*
Think of valueOf() like this:

It answers the question:
“If I treat this object like a number, what number should it be?”

Simple analogy

Imagine you have a box:
let box = {
  valueOf() {
    return 10;
  }
};

Now if you do:
console.log(box + 5);

JavaScript thinks:
“Hmm, I need a number… what is box?”

So it calls:
box.valueOf() → 10

Then:
10 + 5 = 15

Without valueOf()
let box = {};
console.log(box + 5);

Now JavaScript gets confused and does weird stuff like:

"[object Object]5"

Your code case
ArrayWrapper.prototype.valueOf = function() {

You are telling JavaScript:

“If someone uses my object in math, use THIS value.”

Example:

class ArrayWrapper {
  constructor(arr) {
    this.arr = arr;
  }

  valueOf() {
    return this.arr.length;
  }
}

let a = new ArrayWrapper([1,2,3]);

console.log(a + 2); // 5

Why?

a.valueOf() → 3
3 + 2 = 5

One-line summary
valueOf() = what your object becomes when used like a number
*/
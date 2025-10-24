/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  let obj = {
    toBe: function (otherVal) {
      if (val === otherVal) {
        return true;
      } else {
        throw new Error("Not Equal");
      }
    },

    notToBe: function (otherVal) {
      if (val !== otherVal) {
        return true;
      } else {
        throw new Error("Equal");
      }
    },
  };
  return obj;
};

//Problem Link: https://leetcode.com/problems/to-be-or-not-to-be/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */

/*
Step 1: expect(5)
When you call expect(5), you're invoking the expect() function, which is defined as:

var expect = function(val) {
    let obj = {
        // methods like toBe and notToBe
    };
    return obj;
}
Here, val is the argument passed to the expect function. In this case, val will be 5 because that's the value you provided when calling expect(5).
Inside the expect() function, an object obj is created with two methods: toBe and notToBe.

let obj = {
    toBe: function(otherVal) { ... },
    notToBe: function(otherVal) { ... }
};


Calling toBe(5)
Once expect(5) returns the object with the toBe and notToBe methods, you chain the call to toBe by doing expect(5).toBe(5).
So, expect(5) gives us an object, and then .toBe(5) is called on that object.
*/

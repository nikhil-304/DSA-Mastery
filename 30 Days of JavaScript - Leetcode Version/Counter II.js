/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let initCntr = init;
  let obj = {
    increment: function () {
      return ++initCntr;
    },
    decrement: function () {
      return --initCntr;
    },
    reset: function () {
      return (initCntr = init);
    },
  };

  return obj;
};

// Problem Link: https://leetcode.com/problems/counter-ii/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

/*
//Why use Pre-increment/decrement over Post?
    First it'll increment, then return
    eg. init = 5 ; ++5 => 6 then return

    Other case: later increment, then return
    eg. init = 5 ; 5++ => returned 5 then increment
*/

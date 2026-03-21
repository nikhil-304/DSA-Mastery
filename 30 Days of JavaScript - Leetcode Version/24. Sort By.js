/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function (arr, fn) {
  return arr.sort((a, b) => fn(a) - fn(b));
  /*
    What sort is doing internally
    - It takes two elements at a time
    - Calls your comparator:
        (a, b) => fn(a) - fn(b)
    Based on result:
        negative -> a comes before b
        positive -> b comes before a
        zero -> same
    */
};

//Too good to be ignored
//Sorting Basics: https://www.youtube.com/watch?v=CTHhlx25X-U

/*
--------------- Test Case 1 -----------------
arr = [5, 4, 1, 2]
fn = (x) => x

(Actual order depends on JS engine, but conceptually:)

Compare (5, 4)
fn(5) - fn(4) = 5 - 4 = 1
positive -> swap
[4, 5, 1, 2]

Compare (5, 1)
5 - 1 = 4
positive -> swap
[4, 1, 5, 2]

Compare (5, 2)
5 - 2 = 3
positive -> swap
[4, 1, 2, 5]

Compare (4, 1)
4 - 1 = 3
positive -> swap
[1, 4, 2, 5]

Compare (4, 2)
4 - 2 = 2
positive -> swap
[1, 2, 4, 5]

Final Sorted Array:
[1, 2, 4, 5]

--------------- Test Case 2 -----------------

arr = [{x: 3}, {x: 1}, {x: 2}]
fn = (d) => d.x

Compare ({x:3}, {x:1})
3 - 1 = 2 -> swap --- [{x: 1}, {x: 3}, {x: 2}]
Compare ({x:3}, {x:2})
3 - 2 = 1 -> swap --- [{x: 1}, {x: 2}, {x: 3}]
Compare ({x:1}, {x:2})
1 - 2 = -1 -> keep --- [{x: 1}, {x: 2}, {x: 3}]

Final:
[{x:1}, {x:2}, {x:3}]
*/

/*
var sortBy = function(arr, fn) {
    let temp = arr.map(x => [fn(x), x]);
    temp.sort((a, b) => a[0] - b[0]);
    return temp.map(x => x[1]);
};

This technique is called:
Schwartzian Transform

Used when:
- fn is expensive
- You don’t want to recompute it again & again
*/

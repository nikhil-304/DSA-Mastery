/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newArray = [];

    for(let i=0 ; i<arr.length ; i++){
        if(fn(arr[i], i)) newArray.push(arr[i]);
    }

    return newArray;
};

// Problem Link: https://leetcode.com/problems/filter-elements-from-array/?envType=study-plan-v2&envId=30-days-of-javascript
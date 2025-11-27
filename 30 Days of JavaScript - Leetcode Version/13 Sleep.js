/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(resolve => setTimeout(resolve, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */

/*
After 100 milliseconds, when the event loop has processed all other synchronous code, it will run the resolve() function that you passed to setTimeout:

The promise is now fulfilled.

This causes the .then() block to be executed. Inside that .then() block, you can now call Date.now() again.

Here’s the thing:
Date.now() is always getting the current timestamp when it is called. The timestamp reflects the current time when the .then() callback is executed.

Date.now() - t calculates the time difference between when t was initially recorded (just before sleep(100) was called) and the current time when the .then() block runs (which is 100ms later, assuming no other delays).
*/
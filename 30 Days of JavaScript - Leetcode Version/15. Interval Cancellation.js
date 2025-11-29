/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // Immediately call the function to push the 0ms result
    fn(...args);

    // Start the interval to call the function every `t` ms
    let timerID = setInterval(()=>{
        fn(...args);
    }, t);

    // Return cancel function to stop the interval
    let cancelFunc = function(){
        clearInterval(timerID);
    }

    return cancelFunc;
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 2;
 *  const args = [4], t = 35, cancelTimeMs = 190;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  setTimeout(cancel, cancelTimeMs);
 *
 *  setTimeout(() => {
 *      console.log(result); // [
 *                           //     {"time":0,"returned":8},
 *                           //     {"time":35,"returned":8},
 *                           //     {"time":70,"returned":8},
 *                           //     {"time":105,"returned":8},
 *                           //     {"time":140,"returned":8},
 *                           //     {"time":175,"returned":8}
 *                           // ]
 *  }, cancelTimeMs + t + 15)
 */

/*
Flow Summary (Detailed Version):
1. cancellable is called, and log is invoked immediately (first time: 0ms)

What happens:
The cancellable function is invoked with log, args, and t as arguments.
Immediately, the log function is called once by cancellable to push the first log entry to the result array with { "time": 0, "returned": 8 }.

Where does it go?:
When the log function is called, it is executed synchronously (i.e., directly on the call stack).
The call stack handles this execution.
The result ({"time": 0, "returned": 8}) is immediately pushed into the result array.

2. The setInterval starts running every 35ms and calls log repeatedly

What happens:
setInterval is called inside cancellable, with a delay of t = 35ms.
SetInterval sets up an interval timer that will call log every 35ms.

Where does it go?:
WebAPI: setInterval goes to the WebAPI (part of the browser environment, handled by the event loop), where the timer is set to trigger the callback (the log function) every 35ms.

WebAPI is responsible for managing the timers in the browser, keeping track of how long it takes for 35ms to pass.

Event loop is watching the callback queue for any ready functions to execute.
Also the cancellable function returns the cancelFunc that will be used to cancel (clear) the interval

3. setTimeout(cancel, 190) schedules cancel to stop the interval after 190ms

What happens:
setTimeout(cancel, 190) schedules the cancel function to be called after 190ms, which clears the interval set by setInterval.

Cancel will stop the interval after 190ms, meaning the log function will stop executing.

Where does it go?:
WebAPI: The setTimeout function itself goes into the WebAPI and starts counting down.

After 190ms, the WebAPI places the cancel function into the callback queue.

The event loop will pick up the cancel function and execute it once the call stack is empty.

4. The event loop picks up log calls from the callback queue and pushes results into result[] every 35ms

What happens:

Every 35ms, the log function is triggered by the setInterval.

Since setInterval is running asynchronously, the log function gets placed into the callback queue every 35ms by the WebAPI.

The event loop checks the callback queue. If the call stack is empty, the event loop picks up the log function and pushes the results into the result[] array.

Where does it go?:

WebAPI: The setInterval callback (log) is placed into the callback queue.

Event Loop: The event loop continually checks if the call stack is empty. If so, it picks up the log function from the callback queue and executes it.

Call Stack: Each time log is executed, it's pushed to the call stack and run synchronously.

Result: The time (diff) and the result of fn(...args) are pushed into the result[] array.

5. After 190ms, cancel stops the interval

What happens:

After 190ms, the setTimeout(cancel, 190) will execute, calling the cancel function.

cancel clears the interval, stopping the repeated execution of log every 35ms.

Where does it go?:

WebAPI: The setTimeout call was placed in the WebAPI when it was first triggered. After 190ms, the cancel function is placed in the callback queue by the WebAPI.

Event Loop: Once the call stack is empty, the event loop picks up the cancel function and executes it, which clears the interval set by setInterval.

6. After another 15ms, the second setTimeout runs, logging the results from the result[] array

What happens:

After 240ms (190ms + 35ms + 15ms), the second setTimeout (which logs result[]) is triggered.

This second setTimeout logs the final results of the result[] array, which now contains all the entries that were pushed by log during the 190ms window before cancel was called.

Where does it go?:

WebAPI: The second setTimeout is placed into the WebAPI.

After the timeout of 240ms, the event loop picks up the console.log(result) function from the callback queue (once the call stack is empty) and logs the result[] array.

7. The final logged result shows the timestamps at 0, 35, 70, 105, 141, 176ms for each interval

What happens:

The output is printed by console.log(result) after 240ms.

The result[] contains the entries at the timestamps of 0ms, 35ms, 70ms, 105ms, 141ms, and 176ms — the exact times when the log function was executed.

Where does it go?:

Callback Queue: The second setTimeout puts console.log(result) into the callback queue after 240ms.

Event Loop: The event loop picks up console.log(result) from the callback queue and executes it after ensuring the call stack is empty.
*/
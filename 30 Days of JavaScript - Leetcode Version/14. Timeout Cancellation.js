/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // Step 1: Schedule the function to run after 't' milliseconds
    let timerID = setTimeout(()=>{
        fn(...args);
    }, t);

    // Step 2: Return a function that can cancel the timeout
    const cancelFunc = function() {
        clearTimeout(timerID); // Cancels the scheduled execution
    };

    return cancelFunc;
};

/*
 * Example usage:
const result = [];

const fn = (x) => {
    result.push(x * 2);
    console.log("Function executed, result =", result);
};

const args = [5];
const t = 1000; // 1 second

const cancelFn = cancellable(fn, args, t); // schedules fn(5) after 1s

// Let's say we cancel it after 500ms
setTimeout(() => {
    cancelFn();
    console.log("Cancelled before execution");
}, 500);
*/

/*
SYNCHRONOUS AND ASYNCHRONOUS CODE HANDLING
CONCEPT OF CALL STACK AND CALLBACK QUEUE
The call stack and the callback queue (or event queue) are fundamental components of how JavaScript handles code execution, particularly in a single-threaded environment with asynchronous operations.

CALL STACK:
    The call stack is a Last-In, First-Out (LIFO) data structure that keeps track of the execution context of synchronous function calls.
    When a function is called, it is pushed onto the top of the call stack.

When a function completes its execution, it is popped off the stack.
This ensures that the currently executing function is always at the top of the stack.


CALLBACK QUEUE (EVENT QUEUE):
    The callback queue is a First-In, First-Out (FIFO) data structure that stores callback functions associated with asynchronous operations.
    When an asynchronous operation (like setTimeout, fetch, or a user event) completes, its associated callback function is added to the callback queue.
    These callbacks wait in the queue until the call stack is empty.

How They Work Together (The Event Loop):
    The event loop is a mechanism that continuously monitors both the call stack and the callback queue.
    When the call stack is empty (meaning all synchronous code has finished executing), the event loop takes the first callback function from the callback queue and pushes it onto the call stack for execution.

This allows JavaScript to handle asynchronous tasks without blocking the main thread, ensuring a responsive user experience.
*/

/*
Step-by-Step Inside the JS Engine
\U0001f9e0 1. Main thread executes cancellable(fn, args, 1000)

A timer is registered in the Web API environment (not in the call stack yet).

setTimeout(() => fn(...args), 1000) tells the browser:
→ “After 1000 ms, put this callback into the callback queue.”

It’s not sitting on the call stack yet — it’s “scheduled” off to the side in the browser’s timer system.

\U0001f9f1 2. The main thread continues, stack becomes empty
Once the synchronous part of your code finishes, the event loop keeps checking:
“Is the call stack empty? Any expired timers ready to move to the callback queue?”

⏱ 3. Now another setTimeout(..., 500) is registered
The browser now has two timers:

One to run after 500 ms (cancelFn() → clearTimeout)

One to run after 1000 ms (fn(...args))

Both are counting down independently in the browser’s timer system.

⏳ 4. After 500 ms
The 500 ms timer expires first (naturally, since it’s smaller).

Its callback (cancelFn()) is moved from the Web API → callback queue.

The event loop sees the call stack is empty → pushes that callback onto the call stack → executes cancelFn().

✅ cancelFn() calls clearTimeout(timerId)
→ This removes the 1000 ms timer from the Web API timers list.

So by the time 1000 ms passes, there’s nothing left to execute — because that callback has been cleared (deleted).
*/
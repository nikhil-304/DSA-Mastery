/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    try{
        // Waits for the promise to resolve
        const promise1Result = await promise1;
        const promise2Result = await promise2;
        return promise1Result + promise2Result;
    }
    catch(error){
        console.log(error); // Catch error if rejected
    }
    finally{
        // Always runs after try/catch
        console.log("Addition of Promises request complete");
    }
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
*/

/*
Workflow:

async/await:
Execution is paused at the await expression until the promise is settled.
You can easily work with the result or handle the error in a structured, try-catch way, which resembles synchronous error handling.
The code structure tends to be cleaner, especially for multiple sequential asynchronous operations.
*/
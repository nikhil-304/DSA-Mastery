class EventEmitter {
  // When class obj is created, constructor automatically runs
  // it creates eventsStorage map container to store mappings
  constructor() {
    this.eventsStorage = new Map();
  }

  /**
   * @param {string} eventName
   * @param {Function} callback
   * @return {Object}
   */
  subscribe(eventName, callback) {
    // check if event exists
    if (!this.eventsStorage.has(eventName)) {
      // if not, create array
      this.eventsStorage.set(eventName, [callback]);
    }
    // else, add to existing array
    else {
      const arr = this.eventsStorage.get(eventName);
      arr.push(callback);
    }

    return {
      unsubscribe: () => {
        // Get current callbacks for this event
        // eg. arr = [fn1, fn2]
        const arr = this.eventsStorage.get(eventName);
        if (!arr) return;

        // Find the position of THIS specific callback
        // index = arr.indexOf(fn1) -> 0
        const index = arr.indexOf(callback);
        if (index !== -1) {
          // If found, remove it from the array
          // splice -> remove fn1
          arr.splice(index, 1);
        }
      },
    };
  }

  /**
   * @param {string} eventName
   * @param {Array} args
   * @return {Array}
   */
  emit(eventName, args = []) {
    // 1. get callbacks
    const callbacks = this.eventsStorage.get(eventName);
    // 2. if none return -> []
    if (!callbacks) return [];

    // 3. create results array to store results
    const results = [];

    // 4. loop a particular event's callbacks fncs
    for (const fn of callbacks) {
      // 5. call fn and store in a variable
      const res = fn(...args);
      // 6. push result
      results.push(res);
    }

    return results;
  }
}

// Problem Link: https://leetcode.com/problems/event-emitter/

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */

/*
Why "this" keyword is necessary

Because you want:
const e1 = new EventEmitter();
const e2 = new EventEmitter();

Now each should have separate storage:

e1.eventsStorage -> Map A
e2.eventsStorage -> Map B

If you didn’t use this, you'd lose that separation.

What happens if you DON'T use this?

If you wrote:

eventsStorage = new Map();

Then:

it’s not attached to the object
methods can’t access it properly
or it becomes global / undefined depending on context
*/

/*
In JavaScript, the splice() method is a built-in Array.prototype function used to change the contents of an array by removing, replacing, or adding elements in place.
1. Core Characteristics

- Mutates the Original Array: Unlike many other methods, splice() directly modifies the array it is called upon.
- Return Value: It returns a new array containing the elements that were removed. If no elements were removed, it returns an empty array [].

2. Syntax

array.splice(start, deleteCount, item1, item2, ..., itemN)

- start (Required): The zero-based index where changes begin. A negative index counts back from the end of the array.
- deleteCount (Optional): The number of elements to remove. If omitted, all elements from the start index to the end are removed.
- item1, item2, ... (Optional): The new elements to add at the start index.

3. Common Use Cases

- Removing Elements: Specify the index and the number of items to delete.
    - Example: arr.splice(1, 2) removes 2 elements starting at index 1.

- Adding Elements: Set deleteCount to 0 and provide the new items.
    - Example: arr.splice(2, 0, 'NewItem') inserts "NewItem" at index 2 without deleting anything.

- Replacing Elements: Remove specific items and insert new ones in their place.
    - Example: arr.splice(1, 1, 'Replacement') removes the element at index 1 and replaces it with "Replacement".
*/

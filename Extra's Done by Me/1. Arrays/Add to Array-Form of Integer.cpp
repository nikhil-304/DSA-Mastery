class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> result;
        
        // Traverse the array from the last digit
        for (int i = n - 1; i >= 0 || k > 0; i--) {
            if (i >= 0) {
                k += num[i];  // Add the digit to k (simulating the addition)
            }
            result.push_back(k % 10);  // Append the last digit of k
            k /= 10;  // Carry over the remaining value to the next iteration
        }
        
        // Since we've added digits in reverse order, reverse the result
        reverse(result.begin(), result.end());
        
        return result;
    }
};

//Problem Link: https://leetcode.com/problems/add-to-array-form-of-integer/description/

/*
Time Complexity: O(n + m), where n is the number of digits in num[] and m is the number of digits in k.
Space Complexity: O(n), where n is the number of digits in num[].
*/

/*
For num = [1, 2, 3] and k = 7:

    Start with num = [1, 2, 3] and k = 7.
    Add k to the least significant digit:
        3 + 7 = 10, so we append 0 to the result, and carry over 1.
    Next, add the carry to 2:
        2 + 1 = 3, so we append 3 to the result.
    Finally, add the carry to 1:
        1 + 0 = 1, so we append 1 to the result.
    Result before reversing: [0, 3, 1].
    Reverse the result: [1, 3, 0].

Final output: [1, 3, 0].
*/

/*
Let’s take an example with num = [2, 4, 3] (which represents 243), and k = 765.

We want to calculate 243 + 765, which is 1008.
Initial Setup:

    num = [2, 4, 3] (represents the number 243).
    k = 765.
    result = [] (empty array for storing the result).

Now let's go through each step in the loop.
Step-by-Step Iteration:
First Iteration (i = 2):

    num[i] = 3 (last digit of 243).
    k = 765.

We add num[i] to k:

    k = k + num[i] = 765 + 3 = 768.

Now, we push the last digit of 768 (which is 768 % 10 = 8) into result:

    result = [8].

Next, we carry over the remaining value by dividing k by 10:

    k = 768 / 10 = 76.

Second Iteration (i = 1):

    num[i] = 4 (second digit of 243).
    k = 76.

We add num[i] to k:

    k = k + num[i] = 76 + 4 = 80.

Now, we push the last digit of 80 (which is 80 % 10 = 0) into result:

    result = [8, 0].

Next, we carry over the remaining value by dividing k by 10:

    k = 80 / 10 = 8.

Third Iteration (i = 0):

    num[i] = 2 (first digit of 243).
    k = 8.

We add num[i] to k:

    k = k + num[i] = 8 + 2 = 10.

Now, we push the last digit of 10 (which is 10 % 10 = 0) into result:

    result = [8, 0, 0].

Next, we carry over the remaining value by dividing k by 10:

    k = 10 / 10 = 1.

Fourth Iteration (i = -1):

At this point, we have no more digits left in num[], so i becomes -1. However, the loop condition i >= 0 || k > 0 ensures that we keep going until k is fully processed.

    i = -1, so num[i] is not accessible. This is where the logic of treating the missing digits as 0 comes in.
    We are conceptually adding 0 from num[] because we've exhausted all digits. So, we add the remaining carry k (which is 1) to the result.
    k = 1.

Now, we push the last digit of k (which is 1 % 10 = 1) into result:

    result = [8, 0, 0, 1].

Next, we carry over the remaining value by dividing k by 10:

    k = 1 / 10 = 0.

Since k = 0, the loop will terminate.
Reversing the Result:

The result array result = [8, 0, 0, 1] is in reverse order. So, we reverse it to get the final result:

    reverse(result.begin(), result.end()) ? result = [1, 0, 0, 8].

Final Output:

The final result is [1, 0, 0, 8], which represents 1008.
*/

/*
My First Approach :)

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> arrForm;
        long long extractedNum = 0;

        // Step 1: Convert num (array of digits) to an integer number
        for (int i = 0; i < num.size(); ++i) {
            extractedNum = extractedNum * 10 + num[i];
        }

        // Step 2: Add k to the number formed
        long long calculatedNum = extractedNum + k;

        // Step 3: Extract digits from the calculated number and store them in arrForm
        while (calculatedNum > 0) {
            arrForm.push_back(calculatedNum % 10);
            calculatedNum = calculatedNum / 10;
        }

        if (arrForm.empty()) {
            arrForm.push_back(0);
            // If the calculatedNum is 0, 
            //ensure at least one element (handle k being 0)
        }

        reverse(arrForm.begin(), arrForm.end());

        return arrForm;
    }
};

O(N + D), where N is the number of digits in num and D is the number of digits in the result of extractedNum + k.
*/

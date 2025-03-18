class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Step 1: Count the frequency of each relevant character.
        unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }

        // Step 2: Check for the required characters: 'b', 'a', 'l', 'o', 'n'.
        // 'l' and 'o' appear 2 times in "balloon", so divide their counts by 2.
        int bCount = freq['b'];
        int aCount = freq['a'];
        int lCount = freq['l'] / 2;  // Need two 'l's for each "balloon"
        int oCount = freq['o'] / 2;  // Need two 'o's for each "balloon"
        int nCount = freq['n'];

        // Step 3: Return the minimum number of "balloon" words that can be formed.
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};

//Problem Link: https://leetcode.com/problems/maximum-number-of-balloons/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Input: nlaebolko

Step-by-step dry run:
Step 1: Count the frequency of each character in the string

We start by creating a frequency map for the characters in the input string. This is how the unordered_map will look like after iterating through the string:

unordered_map<char, int> freq;

We iterate through the string "nlaebolko", and count the occurrences of each character:

    For 'n', we increase its count to 1.
    For 'l', we increase its count to 1.
    For 'a', we increase its count to 1.
    For 'e', we increase its count to 1.
    For 'b', we increase its count to 1.
    For 'o', we increase its count to 1.
    For 'l', we increase its count to 2.
    For 'k', we increase its count to 1.
    For 'o', we increase its count to 2.

At the end of this step, the frequency map looks like this:

freq = {
    'n': 1,
    'l': 2,
    'a': 1,
    'e': 1,
    'b': 1,
    'o': 2,
    'k': 1
}

Step 2: Extract the relevant counts for the characters in "balloon"

Now, we only care about the characters 'b', 'a', 'l', 'o', and 'n'. So, we extract their counts from the freq map:

    bCount = freq['b'] = 1
    aCount = freq['a'] = 1
    lCount = freq['l'] = freq['l'] / 2 = 2 / 2 = 1 (since we need 2 'l's per "balloon")
    oCount = freq['o'] = freq['o'] / 2 = 2 / 2 = 1 (since we need 2 'o's per "balloon")
    nCount = freq['n'] = 1

So, after this step, we have:

    bCount = 1
    aCount = 1
    lCount = 1
    oCount = 1
    nCount = 1

Step 3: Compute the minimum of the counts

The maximum number of "balloon" words that can be formed is limited by the character that appears the fewest times based on the required frequency.

So, we calculate:

return min(bCount, aCount, lCount, oCount, nCount);

Substituting the values:

return min(1, 1, 1, 1, 1);  // The minimum is 1

Step 4: Return the result

The result is 1, which means we can form the word "balloon" exactly 1 time from the string "nlaebolko".
Conclusion:

The final output is 1 because there is enough of each character to form exactly one "balloon".
*/

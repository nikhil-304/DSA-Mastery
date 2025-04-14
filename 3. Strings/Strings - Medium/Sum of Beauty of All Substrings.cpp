int getMinCount(vector<int> &freq){
    // Finding the minimum freq of element which is != 0
    int minCount = INT_MAX;

    for(int count : freq){
        if (count != 0) {
            minCount = min(minCount, count);
        }
    }
    return minCount;
}

int getMaxCount(vector<int> &freq){
    // Finding the maximum freq of element
    int maxCount = INT_MIN;

    for(int count : freq){
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        // Generating all substrings
        for(int i=0 ; i<n ; i++){
            // Frequency array for a-z
            vector<int> freq(26, 0);

            for(int j=i ; j<n ; j++){
                // Increment frequency of current character
                freq[s[j] - 'a']++;
                int beauty = getMaxCount(freq) - getMinCount(freq);

                sum += beauty;
            }
        }
        return sum;
    }
};

//Problem Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

/*
Time Complexity: O(n^2)
Space Complexity: O(1) (constant 26-sized vector)
*/

/*
Input: "aabcb"

We generate all substrings and calculate the "beauty" of each one.

\U0001f4a1 Definition:
Beauty of a substring = max freq of any character - min freq (ignoring 0s)

Step-by-step substrings and calculations:

1. i = 0:
   - j = 0 ? "a" ? freq = [1] ? beauty = 1 - 1 = 0
   - j = 1 ? "aa" ? freq = [2] ? beauty = 2 - 2 = 0
   - j = 2 ? "aab" ? freq = [2,1] ? beauty = 2 - 1 = 1
   - j = 3 ? "aabc" ? freq = [2,1,1] ? beauty = 2 - 1 = 1
   - j = 4 ? "aabcb" ? freq = [2,2,1] ? beauty = 2 - 1 = 1

2. i = 1:
   - j = 1 ? "a" ? freq = [1] ? beauty = 0
   - j = 2 ? "ab" ? freq = [1,1] ? beauty = 1 - 1 = 0
   - j = 3 ? "abc" ? freq = [1,1,1] ? beauty = 1 - 1 = 0
   - j = 4 ? "abcb" ? freq = [1,2,1] ? beauty = 2 - 1 = 1

3. i = 2:
   - j = 2 ? "b" ? freq = [0,1] ? beauty = 0
   - j = 3 ? "bc" ? freq = [0,1,1] ? beauty = 1 - 1 = 0
   - j = 4 ? "bcb" ? freq = [0,2,1] ? beauty = 2 - 1 = 1

4. i = 3:
   - j = 3 ? "c" ? beauty = 0
   - j = 4 ? "cb" ? freq = [0,1,1] ? beauty = 1 - 1 = 0

5. i = 4:
   - j = 4 ? "b" ? beauty = 0

? Now, summing all the beauties:
  = 0 + 0 + 1 + 1 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 + 0 + 0 + 0 = **5**

? So, the output is 5.
*/

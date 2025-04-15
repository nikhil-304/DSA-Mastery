class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;
 
        for(int i=0 ; i<n ; i++){    //Inserting elements into the set takes O(N)
            st.insert(nums[i]);      //O(1) for Lookup operations
        }

        for (auto it : st) { 
            // If num - 1 is not in the set, num is the start of a new sequence
            if (st.find(it - 1) == st.end()) {
                int current = it;
                int count = 1;

                // Count the length of the sequence starting from 'current'
                while (st.find(current + 1) != st.end()) {
                    current++;  
                    count++;
                }

                // Update the longest sequence length
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

/*
Problem Link:
LeetCode:https://leetcode.com/problems/longest-consecutive-sequence/
Code360: https://www.naukri.com/code360/problems/longest-consecutive-sequence_759408
*/

/*
Iteration 4: Processing it = 1

    Step 1: Check if it - 1 is in the set (st.find(1 - 1) == st.end()):
        1 - 1 = 0, and 0 is not in the set.
        This means that 1 is the start of a potential sequence.

    Step 2: Try to find the longest consecutive sequence starting from 1:
        Start with current = 1 and count the consecutive numbers:
            st.find(1 + 1) != st.end() -> 2 is in the set, so continue the sequence.
            st.find(2 + 1) != st.end() -> 3 is in the set, so continue the sequence.
            st.find(3 + 1) != st.end() -> 4 is in the set, so continue the sequence.
        Now the sequence is [1, 2, 3, 4] and the length is 4.

    Step 3: Update longest:
        The length of the sequence is 4. Since longest = 1, we update longest.
        longest = max(1, 4) -> longest = 4.

Time Complexity: O(n)
Space Complexity: O(n)
*/

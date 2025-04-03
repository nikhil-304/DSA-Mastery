class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> cntOfAlpha(26, 0);

        for(int i=0 ; i<s.size() ; i++){
            cntOfAlpha[s[i] - 'a']++;  // Increase count for s
            cntOfAlpha[t[i] - 'a']--;  // Decrease count for t
        }

        for (int c : cntOfAlpha) {
            if (c != 0) return false;
        }
        return true;
    }
};

//Problem Link: https://leetcode.com/problems/valid-anagram/

/*
Approach:
1. We use a frequency count array of size 26 (for letters 'a' to 'z') to track the occurrence of each character.
2. We iterate through both strings `s` and `t` simultaneously:
   - Increase the count for `s[i]` (indicating presence of the letter).
   - Decrease the count for `t[i]` (canceling out the letter if it appears in `t`).
3. If `s` and `t` are anagrams, the count array should be all zeros at the end.
4. We check if all values in the count array are zero and return `true` if they are, otherwise return `false`.

Intuition:
- An anagram means both strings contain the **same letters** in the **same quantity**, but in any order.
- By **incrementing for `s`** and **decrementing for `t`**, every letter that appears in `s` should be canceled out by `t`.
- If the final count array has only zeros, the strings have matching character frequencies ? they are anagrams.
- If any value is nonzero, `s` and `t` do not have the same character count, so they are **not anagrams**.

Time Complexity: O(n) (single pass over both strings)
Space Complexity: O(1) (fixed array of size 26)
*/


// Index  |  s[i]  | s[i] - 'a' (Index) | Operation          | t[i]  | t[i] - 'a' (Index) | Operation            | Final count[]
//------------------------------------------------------------------------------------------------------------
//   0    |   'a'  |   0               | count[0]++         |   'n' |   13               | count[13]--          | [ 1, 0, 0, ..., -1, 0, 0 ]
//   1    |   'n'  |   13              | count[13]++        |   'a' |   0                | count[0]--           | [ 0, 0, 0, ..., 0, 0, 0 ]
//   2    |   'a'  |   0               | count[0]++         |   'g' |   6                | count[6]--           | [ 1, 0, 0, 0, 0, 0, -1, ..., 0,0 ]
//   3    |   'g'  |   6               | count[6]++         |   'a' |   0                | count[0]--           | [ 0, 0, 0, 0, 0, 0, 0, ..., 0, 0 ]
//   4    |   'r'  |   17              | count[17]++        |   'r' |   17               | count[17]--          | [ 0, 0, 0, 0, 0, 0, 0, ..., 0, 0 ]
//   5    |   'a'  |   0               | count[0]++         |   'a' |   0                | count[0]--           | [ 0, 0, 0, 0, 0, 0, 0, ..., 0, 0 ]
//   6    |   'm'  |   12              | count[12]++        |   'm' |   12               | count[12]--          | [ 0, 0, 0, 0, 0, 0, 0, ..., 0, 0 ]



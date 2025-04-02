class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, char> mapS, mapT;

        for(int i=0 ; i<s.size() ; i++){
            char ch1 = s[i], ch2 = t[i];

            if(mapS.find(ch1) != mapS.end() && mapS[ch1] != ch2) return false;
            if(mapT.find(ch2) != mapT.end() && mapT[ch2] != ch1) return false;

            mapS[ch1] = ch2;
            mapT[ch2] = ch1;
        }
        return true;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/isomorphic-strings/description/
Code360: https://www.naukri.com/code360/problems/check-if-two-given-strings-are-isomorphic-to-each-other_1117636
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Approach:
1. If the lengths of 's' and 't' are different, return false.
2. Use two unordered maps:
   - 'mapS' to store mappings from 's' to 't'.
   - 'mapT' to store mappings from 't' to 's'.
3. Traverse both strings simultaneously:
   - If 's[i]' is already mapped, check if it maps correctly to 't[i]'.
   - If 't[i]' is already mapped, check if it maps correctly to 's[i]'.
   - If any mismatch is found, return false.
   - Otherwise, store the mapping in both maps.
4. If all mappings are consistent, return true.
*/

/*
Dry Run for: s = "paper", t = "title"

Step 1: Initialize two unordered maps: mapS (s -> t) and mapT (t -> s)

Step 2: Start iterating over both strings:

Index 0:
s[i] = 'p', t[i] = 't'
- 'p' is not mapped in mapS, and 't' is not mapped in mapT.
- Add mapping: 'p' ? 't' in mapS and 't' ? 'p' in mapT.

Current Mappings:
mapS: { 'p' ? 't' }
mapT: { 't' ? 'p' }

-------------------------------------------------
Index 1:
s[i] = 'a', t[i] = 'i'
- 'a' is not mapped in mapS, and 'i' is not mapped in mapT.
- Add mapping: 'a' ? 'i' in mapS and 'i' ? 'a' in mapT.

Current Mappings:
mapS: { 'p' ? 't', 'a' ? 'i' }
mapT: { 't' ? 'p', 'i' ? 'a' }

-------------------------------------------------
Index 2:
s[i] = 'p', t[i] = 't'
- 'p' is already mapped to 't' in mapS ?
- 't' is already mapped to 'p' in mapT ?
- Both mappings are correct, continue.

Current Mappings:
mapS: { 'p' ? 't', 'a' ? 'i' }
mapT: { 't' ? 'p', 'i' ? 'a' }

-------------------------------------------------
Index 3:
s[i] = 'e', t[i] = 'l'
- 'e' is not mapped in mapS, and 'l' is not mapped in mapT.
- Add mapping: 'e' ? 'l' in mapS and 'l' ? 'e' in mapT.

Current Mappings:
mapS: { 'p' ? 't', 'a' ? 'i', 'e' ? 'l' }
mapT: { 't' ? 'p', 'i' ? 'a', 'l' ? 'e' }

-------------------------------------------------
Index 4:
s[i] = 'r', t[i] = 'e'
- 'r' is not mapped in mapS, and 'e' is not mapped in mapT.
- Add mapping: 'r' ? 'e' in mapS and 'e' ? 'r' in mapT.

Final Mappings:
mapS: { 'p' ? 't', 'a' ? 'i', 'e' ? 'l', 'r' ? 'e' }
mapT: { 't' ? 'p', 'i' ? 'a', 'l' ? 'e', 'e' ? 'r' }

-------------------------------------------------
Since we never found an inconsistency, return true.
Output: True
*/

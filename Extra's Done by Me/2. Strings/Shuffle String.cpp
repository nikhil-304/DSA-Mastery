class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> result(s.size());

        // Place each character in the correct position according to the indices
        for (int i = 0; i < s.size(); ++i) {
            result[indices[i]] = s[i];
        }

        return string(result.begin(), result.end());
    }
};

//Problem Link: https://leetcode.com/problems/shuffle-string/description/

/*
Time Complexity: O(2n)
Filling the vector: For each character, you are directly assigning it to the correct index in the vector, which takes O(1) time for each operation. Since you do this for all n characters, the time complexity is O(n).
Building the result string: Converting the vector to a string takes O(n).

Space Complexity: O(n)
*/


/*
s = "codeleet", indices = [4,5,6,7,0,2,1,3]

At beginning result will have 
result = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}

    indices[0] = 4, so place s[0] = 'c' in result[4].
    indices[1] = 5, so place s[1] = 'o' in result[5].
    indices[2] = 6, so place s[2] = 'd' in result[6].
    indices[3] = 7, so place s[3] = 'e' in result[7].
    indices[4] = 0, so place s[4] = 'l' in result[0].
    indices[5] = 2, so place s[5] = 'e' in result[2].
    indices[6] = 1, so place s[6] = 'e' in result[1].
    indices[7] = 3, so place s[7] = 't' in result[3].

After this process, the result vector looks like this: ['l', 'e', 'e', 't', 'c', 'o', 'd', 'e'].
*/


/*
My Solution Approach
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int, char> map;

        // Mapping the string s according to the indices
        for (int i = 0; i < s.size(); ++i) {
            map[indices[i]] = s[i];
        }
    
        string result = "";
        for (const auto& pair : map) {
            result += pair.second;
        }

        return result;
    }
};

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        // Check if the both the str lengths are equal
        if (s.length() != goal.length()) {
            //if not equal then definately the goal is not a rotated string
            return false;
        }

        string cncat_str = s+s;

        if(cncat_str.find(goal) != string:: npos){
            return true;
        }
        return false;
    }
};

//Problem Link: https://leetcode.com/problems/rotate-string/description/

/*
Time Complexity: O(n^2) (because of the concatenation and the find() operation).
1.) The time complexity for string concatenation is O(n)
2.) find() is O(2n * n), which simplifies to O(n^2).

Space Complexity: O(n) (because of the space needed for the concatenated string cncat_str).
*/

/*
Intuition:
1. To check if 'goal' is a rotation of string 's', we can concatenate string 's' with itself.
2. By doing so, we create a new string 'cncat_str' that contains all possible rotations of 's'.
   For example, if s = "abc", then s + s = "abcabc", which contains "abc", "bca", and "cab" as substrings.
3. If 'goal' is a valid rotation of 's', it will appear as a substring in 'cncat_str'.
4. We then use the `find()` function to check if 'goal' exists as a substring within 'cncat_str'.
5. If 'goal' is found, return true (indicating 'goal' is a valid rotation of 's'); otherwise, return false.
*/

/*
s = "abc", goal = "abc"

1. Check Lengths:

    The length of s = "abc" is 3, and the length of goal = "abc" is also 3.
    Since the lengths are equal, we proceed to the next step.

2. Concatenate s with itself:

    cncat_str = s + s = "abc" + "abc" = "abcabc"

3. Find goal in cncat_str:

    We need to check if "abc" is a substring of "abcabc".
    "abc" is indeed a substring of "abcabc", starting at index 0.

4. Check if find() did not return string::npos:

    The find() function returned a valid index (0), so the condition cncat_str.find(goal) != string::npos is true.

5. Return true:

    Since the substring was found, the function will return true, indicating that "abc" is a valid rotation of "abc".
*/

// Understanding string::npos
// string::npos is a constant defined in the C++ Standard Library for the std::string class, and it represents an invalid or non-existent position when dealing with string operations like find()
// when you use the find() function to search for a substring in a string, find() returns string::npos if it doesn't find the substring.

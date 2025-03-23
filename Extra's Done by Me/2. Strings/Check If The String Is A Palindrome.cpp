#include <bits/stdc++.h> 

string cleanString(const string& input) {
    string result = "";  // String to store the cleaned result
    
    for (char c : input) {
        // If the character is alphanumeric (letter or digit)
        if (isalnum(c)) {
            // If the character is uppercase, convert to lowercase
            result += tolower(c);
        }
    }
    
    return result;
}

bool checkPalindrome(string s)
{
    string cleaned = cleanString(s);

    int left = 0;
    int right = cleaned.size() - 1;

    while(left < right){
        if(cleaned[left] != cleaned[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

//Problem Links:
//Code360: https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633
//LeetCode: https://leetcode.com/problems/valid-palindrome/description/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

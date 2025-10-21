class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int X = 0;

        for (auto &op : operations) {
            // Check if the operation is an increment
            if (op == "++X" || op == "X++") X++;
            // Otherwise, it must be a decrement
            else X--;
        }
        return X;
    }
};

//Problem Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

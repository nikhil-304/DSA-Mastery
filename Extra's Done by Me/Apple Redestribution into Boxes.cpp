class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        
        // Edge case: if no apples or no boxes, return 0
        if (n == 0 || m == 0) return 0;

        int totApple = 0;
        int boxCnt = 0;

        for(int i=0 ; i<n ; i++){
            totApple += apple[i];
        }

        sort(capacity.begin(), capacity.end(), [](int a, int b) {
            return a > b;  // a is greater than b for descending order
        });

        // sort(capacity.begin(), capacity.end(), greater<int>());

        for (int j = 0; j < m; j++) {
            totApple = totApple - capacity[j];
            boxCnt++; 

            if (totApple <= 0) {
                break;
            }
        }
        return boxCnt;
    }
};

//Problem Link: https://leetcode.com/problems/apple-redistribution-into-boxes/description/

/*
Time Complexity: O(n + m log m), where n is the size of the apple array (for summing apples) and m log m is the time complexity for sorting the capacity array.
Summing the apples (O(n)).
Sorting the capacities (O(m log m)).
Filling the boxes (O(m)).

Space Complexity: O(1)
*/

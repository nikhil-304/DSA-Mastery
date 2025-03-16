class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = hours.size();
        int empCnt = 0;

        for(int i=0 ; i<n ; i++){
            if(hours[i] >= target){
                empCnt++;
            }
        }
        return empCnt;
    }
};

//Problem Link: https://leetcode.com/problems/number-of-employees-who-met-the-target/description/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Optimal Approach
        int n = nums.size();

        int j = -1;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i=j+1 ; i<n ; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

Problem Link: https://leetcode.com/problems/move-zeroes/description/

/*//Brute-Force Approach
vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;

    //Taking non-zero elements in temp array
    for(int i=0 ; i<n ; i++){
        if(a[i] != 0){
            temp.push_back(a[i]);
        }
    }

    //Adding non-zero elements in main array
    int nz = temp.size();
    for(int i=0 ; i<nz ; i++){
        a[i] = temp[i];
    }

    //Adding the remaining empty places with zero
    for(int i=nz ; i<n ; i++){
        a[i] = 0;
    }

    return a;
}
*/


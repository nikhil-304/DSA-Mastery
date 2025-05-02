class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Compute the sum of the first k elements
        double currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }

        // Initialize maxAvg with the sum of the first k elements / k
        double maxAvg = currentSum / k;

        // Slide the window across the array
        for (int i = k; i < n; ++i) {
            //Update the sum by adding the new element and removing the old element
            currentSum += nums[i] - nums[i - k];
            
            // Update maxAvg if we found a larger average
            maxAvg = max(maxAvg, currentSum / k);
        }
        return maxAvg;
    }
};

//Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/



/*
Brute Force Approach - My Version
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;

        for(int i=0 ; i<n ; i++){
            double avg = 0;
            int cnt = 0;
            for(int j=i ; j<n ; j++){
                avg += nums[j];
                cnt++;

                double tempavg = 0;

                if(cnt == k){
                    tempavg = avg;
                    tempavg = tempavg / k;

                    maxAvg = max(tempavg, maxAvg);
                    break;
                }
            }
        }
        return maxAvg;
    }
};

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

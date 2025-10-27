class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevRowDevices = 0;

        for (string row : bank) {
            // Count number of '1's (devices) in current row
            int currentRowDevices = 0;
            for (char cell : row) {
                if (cell == '1') currentRowDevices++;
            }

            // If current row has no devices, skip it
            if (currentRowDevices == 0) continue;

            // Multiply with devices of previous non-empty row
            totalBeams += prevRowDevices * currentRowDevices;

            // Update previous row devices
            prevRowDevices = currentRowDevices;
        }

        return totalBeams;
    }
};

//Problem Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

/*
Time Complexity: O(m*n)
Space Complexity: O(1)
*/

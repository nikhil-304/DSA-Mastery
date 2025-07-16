int findFirstOccurrence(const vector<int>& arr, int X) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == X) {
            result = mid;  // Found X, but continue to find the first occurrence
            right = mid - 1; // Move left to find earlier occurrences
        }
        else if (arr[mid] < X) {
            left = mid + 1;  // Move right
        }
        else {
            right = mid - 1; // Move left
        }
    }

    return result;
}

// Function to find the last occurrence of X using binary search
int findLastOccurrence(const vector<int>& arr, int X) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == X) {
            result = mid;  // Found X, but continue to find the last occurrence
            left = mid + 1; // Move right to find later occurrences
        }
        else if (arr[mid] < X) {
            left = mid + 1;  // Move right
        }
        else {
            right = mid - 1; // Move left
        }
    }

    return result;
}

// Function to count the occurrences of X in ARR
int countOccurrences(const vector<int>& arr, int X) {
    int first = findFirstOccurrence(arr, X);
    if (first == -1) {
        return 0;  // X is not found
    }

    int last = findLastOccurrence(arr, X);
    return last - first + 1;  // Number of occurrences is the distance between first and last occurrence
}

/*
Problem Link:
LeetCode: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Code360: https://www.naukri.com/code360/problems/frequency-in-a-sorted-array_893286
*/

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/

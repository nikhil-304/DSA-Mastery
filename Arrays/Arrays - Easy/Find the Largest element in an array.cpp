#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) 
{
    int largest = arr[0];
    for(int i=1 ; i<n ; i++)
    {
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

//Problem Link: https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

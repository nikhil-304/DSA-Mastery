#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5}, n = 5;

  printf("%s", isSorted(arr, n) ? "True" : "False");

}

//Problem Link: https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/


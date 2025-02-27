int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(k > n + m || k <= 0) return -1;  // Edge case: k is out of bounds

    int n1 = n;
    int n2 = m;

    int cnt = 0;

    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == k-1) return arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == k-1) return arr2[j];
            cnt++;
            j++;
        }
    }

    // If arr2 is exhausted but arr1 still has elements
    while(i < n1){
        if(cnt == k-1) return arr1[i];
        cnt++;
        i++;
    }

    // If arr1 is exhausted but arr2 still has elements
    while(j < n2){
        if(cnt == k-1) return arr2[j];
        cnt++;
        j++;
    }
    return -1;
}

/*
Time Complexity: O(n + m), where n is the size of arr1 and m is the size of arr2.
Space Complexity: O(1)
*/
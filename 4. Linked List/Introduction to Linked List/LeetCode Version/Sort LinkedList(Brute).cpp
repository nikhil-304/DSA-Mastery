/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        //Initialise an empty array
        vector<int> LLvals;

        //Traverse the LL and push the values to LLvals
        while(temp != NULL){
            LLvals.push_back(temp->val);
            temp = temp->next;
        }

        //Sort the array
        sort(LLvals.begin(), LLvals.end());

        temp = head;
        //Data Replacement
        //LL vals replaced with sorted array vals
        for(int i=0 ; i<LLvals.size() ; i++){
            temp->val = LLvals[i];
            temp = temp->next;
        }

        //Sorted LL
        return head;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/sort-list/description/
Code360: https://www.naukri.com/code360/problems/merge-sort-linked-list_920473
*/

/*
Time Complexity: O(N) + O(N log N) + O(N)
Space Complexity: O(N)
*/

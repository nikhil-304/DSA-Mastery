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
//Optimal Approach

ListNode* middleOfLL(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeLL(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if(list1 != NULL) temp->next = list1;
    else temp->next = list2;

    ListNode* result = dummyNode->next;
    delete dummyNode;
    return result;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = middleOfLL(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeLL(left, right);
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/sort-list/description/
Code360: https://www.naukri.com/code360/problems/merge-sort-linked-list_920473
https://www.naukri.com/code360/problems/mergesort-linked-list_630514
*/

/*
Time Complexity: O(N log N) Finding the middle node of the linked list 
requires traversing it linearly taking O(N) time complexity and to reach the 
individual nodes of the list, it has to be split log N times 
(continuously halve the list until we have individual elements).
Space Complexity : O(1)
*/

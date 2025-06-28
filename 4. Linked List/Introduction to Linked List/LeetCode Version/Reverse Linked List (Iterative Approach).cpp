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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative Approach
        ListNode* temp = head;
        ListNode* front;
        ListNode* prev = NULL;

        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front; 
        }
        return prev;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/reverse-linked-list/
Code360: https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

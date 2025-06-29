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
        // Recursive Approach
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        head->next = NULL;
        front->next = head;

        return newHead;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/reverse-linked-list/
Code360: https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897
*/

/*
Time Complexity: O(n)
Space Complexity: O(1) No additional space is used explicitly for data structures or allocations.
However, it's important to note that there is an implicit use of stack space due to recursion.
This recursive stack space stores function calls and associated variables during the recursive traversal and reversal of the linked list.
*/

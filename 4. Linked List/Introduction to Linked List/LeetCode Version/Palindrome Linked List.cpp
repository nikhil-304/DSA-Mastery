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

ListNode* reverseLL(ListNode* head){
    //Iterative Approach
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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true; 
        }

        //Finding the middle Node
        ListNode* slow = head;
        ListNode* fast = head;
                // Odd                      Even
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the Nodes which are after the middle node
        ListNode* newHead = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        // Check the leftmost original Nodes and rightmost(reversed) nodes
        while(second != NULL){
            if(first->val != second->val){
                // If both are not same, re-reverse the rightmost nodes to original then return false
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // If both are same, re-reverse the rightmost nodes to original then return true
        reverseLL(newHead);
        return true;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/palindrome-linked-list/
Code360: https://www.naukri.com/code360/problems/palindrom-linked-list_799352
https://www.naukri.com/code360/problems/check-if-linked-list-is-palindrome_985248
*/

/*
Time Complexity: O (2* N) The algorithm traverses the linked list twice, 
dividing it into halves. During the first traversal, it reverses one-half 
of the list, and during the second traversal, it compares the elements of 
both halves. As each traversal covers N/2 elements, the time complexity is 
calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately 
representing O(N). 

Space Complexity: O(1)
*/

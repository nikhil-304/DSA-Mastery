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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        // Case where the list has only one node and we need to remove it
        if(head->next == NULL && n == 1) return NULL;

        ListNode* temp = head;
        int pos = 0;

        //Iterate through the entire list to find its length
        while(temp != NULL){
            pos++;
            temp = temp->next;
        }

        temp = head;
        ListNode* prev = NULL;

        //Special case: If the node to be removed is the head (position == n)
        //that means we're removing the first node from the list.
        if(pos == n){
            temp = temp->next;
            delete head;
            return temp;
        }
        
        // Now, we need to traverse the list again to find the node just before
        // the node that we want to remove. This is to ensure we can modify the
        // next pointer of the previous node to skip over the target node.
        while(temp != NULL && pos != n){
            prev = temp;
            temp = temp->next;
            pos--;
        }

        // Now `temp` is pointing to the N-th node from the end.
        // We remove it by connecting the previous node (`prev`) to the node
        // after the N-th node (skipping the N-th node).
        prev->next = temp->next;
        delete temp;

        return head;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Code360: https://www.naukri.com/code360/problems/delete-kth-node-from-end-in-linked-list_799912
*/

//Brute-Force Approach by Nikhil

/*
Time Complexity: O(L) where L is the length of the linked list.
Space Complexity: O(1)
*/

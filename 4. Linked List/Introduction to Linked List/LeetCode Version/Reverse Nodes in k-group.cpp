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

ListNode* getKthNode(ListNode* temp, int k){
    k = k - 1;  // Decrease k by 1 to match 0-based indexing
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next; 
    }
    return temp;
}

ListNode* reverseLinkedList(ListNode* head) {
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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            
            reverseLinkedList(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};

/*
Problem Link: 
Leetcode: https://leetcode.com/problems/reverse-nodes-in-k-group/
Code360: https://www.naukri.com/code360/problems/reverse-blocks_763406
https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644
*/

/*
Time Complexity: O(2n)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //Tortoise and Hare Algorithm
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            //Additional step to find the node where the cycle begins
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
Code360: https://www.naukri.com/code360/problems/detect-the-first-node-of-the-loop_1112628
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

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
    bool hasCycle(ListNode *head) {
        //Tortoise and Hare Algorithm
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/linked-list-cycle/
Code360: https://www.naukri.com/code360/problems/cycle-detection-in-a-singly-linked-list_628974
https://www.naukri.com/code360/problems/detect-the-cycle_1822910
*/

/*
Tortoise and Hare Algorithm to detect a cycle(loop) in a LL
During the traversal, at one point, both slow and fast pointers will overlap, proving the detection of a cycle in the LL.
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

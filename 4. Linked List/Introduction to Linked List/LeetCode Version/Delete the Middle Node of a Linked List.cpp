class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        // Skipping one iteration so that slow points one prev than middle
        fast = head->next->next;
		
		//Skipping one time will lead the fast to reach to NULL || fast->next
    	//to NULL, making the slow ptr point to one node back of middle node
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
		
		//slow one node back of middle node, we can easily delete the middle node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};

/*
Problem Link:
LeetCode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
Code360: https://www.naukri.com/code360/problems/delete-middle-node_763267
*/

/*
Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).
Space Complexity: O(1) 
*/

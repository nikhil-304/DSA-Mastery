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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0; // To keep track of the carry during addition

        //Traverse both lists as long as there's a node left
        while (temp1 != NULL || temp2 != NULL) {
            // Start with the carry from the previous iteration
            int sum = carry;

            // If there is a node in l1, add its value to sum
            if (temp1 != NULL) sum += temp1->val;
            // If there is a node in l2, add its value to sum
            if (temp2 != NULL) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            //Attach the new node to the result list
            current->next = newNode;
            current = current->next;  //Move the current pointer forward

            // Move to the next node in l1 and l2 if possible
            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }

        // If there is still a carry left, add a new node with carry value
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }
        return dummyNode->next;
    }
};

/*
Problem Link:
Leetcode: https://leetcode.com/problems/add-two-numbers/description/
Code360: https://www.naukri.com/code360/problems/add-two-numbers-as-linked-lists_1170520
*/

/* 
    Intuition & Approach:
    - The task is to add two numbers that are represented as linked lists in reverse order.
    - Each node in the list represents a single digit, and the digits are stored in reverse order, i.e., the head of the list contains the least significant digit.
    
    The approach works as follows:
    1. Create a dummy node to simplify the logic of adding nodes to the result linked list.
    2. Use two pointers (`temp1` and `temp2`) to traverse both input linked lists.
    3. Initialize a `carry` variable to store any carry-over during addition (like the carry in regular addition).
    4. In each iteration, we add the corresponding digits of both linked lists (if they exist), along with the carry from the previous step.
    5. The result of the addition (sum) is split into two parts:
        - The unit's place digit is added to the result linked list.
        - The tens place digit (carry) is carried over to the next addition.
    6. After iterating through both lists, if there is still a carry left, we add a final node with the carry value.
    7. Finally, the list starts from `dummyNode->next` since the dummy node is only a placeholder.
    
    Example:
    Consider adding two numbers: (7 -> 8 -> 9) and (5 -> 6 -> 4). These represent the numbers 987 and 465 respectively.  
    - Start with carry = 0.
    - First iteration: 7 + 5 + carry (0) = 12 ? New node with value 2, carry = 1.
    - Second iteration: 8 + 6 + carry (1) = 15 ? New node with value 5, carry = 1.
    - Third iteration: 9 + 4 + carry (1) = 14 ? New node with value 4, carry = 1.
    - After the loop ends, we still have carry = 1, so we add a final node with value 1.
    - The result will be (2 -> 5 -> 4 -> 1), which represents the number 1452.

    Time Complexity: O(max(m, n))
    - We are traversing both input lists once, where `m` is the length of `l1` and `n` is the length of `l2`. Therefore, the time complexity is the maximum of both lengths.

    Space Complexity: O(max(m, n))
    - We are creating a new linked list, and in the worst case, we create as many nodes as the larger of the two input lists. Hence, the space complexity is O(max(m, n)).
*/


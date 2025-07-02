/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    //Tortoise and Hare Algorithm
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        //Addition to find the length of Cycle
        if(slow == fast){
            int length = 1;
            slow = slow->next;
            while(slow != fast){
                length++;
                slow = slow->next;
            }
            return length;
        }
    }
    return 0;
}

//Problem Link: https://www.naukri.com/code360/problems/find-length-of-loop_8160455

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/


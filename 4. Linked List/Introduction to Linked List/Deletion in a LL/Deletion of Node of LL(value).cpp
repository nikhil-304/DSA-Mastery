#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int>* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete (temp);
}

//Problem Link: https://www.naukri.com/code360/problems/delete-node-in-a-linked-list_1105578

/*
Code for skipping and not actually deleting
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

[4] -> [5] -> [1] -> [9]    node = [5]
[4] -> [1] -> [1] -> [9]
[4] -> [1] -> [9]

Time Complexity: O(1)
Space Complexity: O(1)
*/

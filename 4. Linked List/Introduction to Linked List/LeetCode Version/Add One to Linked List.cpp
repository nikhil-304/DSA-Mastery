#include <bits/stdc++.h> 
/*****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/
int addOneRecursive(LinkedListNode<int> *node) {
    // Stop recursion at NULL or -1 node (treat -1 as terminator)
    if (node == NULL || node->data == -1) {
        return 1;
    }

    int carry = addOneRecursive(node->next);
    node->data += carry;
    
    if (node->data < 10) return 0;
    node->data = 0;
    return 1;
}

LinkedListNode<int>* addOneToList(LinkedListNode<int> *head) {
    int carry = addOneRecursive(head);
    
    if (carry == 1) {
        LinkedListNode<int>* newHead = new LinkedListNode<int>(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

//Problem Link: https://www.naukri.com/code360/problems/add-one-to-linked-list_920456

/*
Time Complexity: O(n)
Space Complexity: O(n) Recursive Stack Space
*/


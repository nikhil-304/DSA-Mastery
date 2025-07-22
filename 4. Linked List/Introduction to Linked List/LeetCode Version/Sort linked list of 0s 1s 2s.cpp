/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    // Connect three lists
    zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

/*
Problem Link: 
https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937
*/

/*
Intuition:

This problem is similar to the Dutch National Flag algorithm. 
We're given a linked list with nodes having values 0, 1, or 2 in random order.
We need to sort the linked list in-place such that all 0s come first, 
then all 1s, and then all 2s ? while maintaining their original relative order.

Approach:

1. Create three dummy nodes to act as the heads of three separate linked lists:
   - zeroHead for all nodes with value 0
   - oneHead for all nodes with value 1
   - twoHead for all nodes with value 2

2. Traverse the original list once, and attach each node to the appropriate list 
   (based on whether the node's data is 0, 1, or 2).

3. After traversal, connect the three lists together:
   - zero list should point to the one list (if it exists), otherwise directly to the two list.
   - one list should point to the two list.
   - Set the end of the two list to NULL.

4. Return the head of the merged list: zeroHead->next

This method has:
- Time Complexity: O(n) single traversal
- Space Complexity: O(1) no new nodes created, only pointers rearranged
- Stability: Maintains the original order of 0s, 1s, and 2s
*/


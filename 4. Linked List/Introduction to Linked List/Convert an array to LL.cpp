/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    // Step 1: Initialize the head of the linked list with the first element in the array
    Node *head = new Node(arr[0]);  // The first node is created with the first element of the array
    Node *mover = head;   // Initialize the 'mover' pointer to the head of the linked list
    
    // Step 2: Traverse the remaining elements of the array to build the rest of the linked list
    for(int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);  // Create a new node for each element in the array
        mover->next = temp;            // Link the 'mover' node to the new node (temp)
        mover = temp;                  // Move the 'mover' pointer to the newly created node
    }
    return head;
}

//Problem Link: https://www.naukri.com/code360/problems/introduction-to-linked-list_8144737

/*
arr = [1, 2, 3, 4]

head -> [1] -> NULL
       mover

head -> [1] -> [2] -> NULL
              mover

head -> [1] -> [2] -> [3] -> NULL
                     mover

head -> [1] -> [2] -> [3] -> [4] -> NULL
                            mover

head -> [1] -> [2] -> [3] -> [4] -> NULL
*/


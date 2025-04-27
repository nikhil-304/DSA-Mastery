/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *head){
    if(head == nullptr || head->next == nullptr) return nullptr;

    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

//Problem Link: https://www.naukri.com/code360/problems/delete-head-of-linked-list_8160463?leftPanelTabValue=PROBLEM

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

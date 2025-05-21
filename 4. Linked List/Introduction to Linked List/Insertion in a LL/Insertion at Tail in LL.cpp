#include <iostream>
#include <vector>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert the head of the linked list
Node* insertTail(Node* head, int val) {
    if(head == NULL){
    	return new Node(val);
	}
	
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node* newNode = new Node(val);
	temp->next = newNode;
	return head;
}

// Function to convert an array to a linked list
Node* convertArr2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};  // Correct initialization
    Node* head = convertArr2LL(arr);  // Convert array to linked list

    head = insertTail(head, 100);
    print(head);  // Print the remaining list

    return 0;
}



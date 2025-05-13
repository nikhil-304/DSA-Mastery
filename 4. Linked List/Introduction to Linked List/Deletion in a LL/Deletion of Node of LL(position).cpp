/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* deleteNode(Node *head, int pos) {
    // Check for empty list
    if (head == NULL) return head;
    
    // If the list has only one node, handle deletion
    if (head->next == NULL) {
        return head;
    }

    // Delete the head node if position is 0
    if (pos == 0) {
        Node* temp = head;
        head = head->next;  // Move head to the next node
        free(temp);  // Delete the old head
        return head;
    }

    int cnt = 0;
    Node* prev = NULL;
    Node* temp = head;

    // Traverse the list to find the node to delete
    while (temp != NULL) {
        if (cnt == pos) {
            prev->next = temp->next;  // Skip the node to delete
            free(temp);  // Delete the node
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    // If position is out of bounds, just return the head (no deletion)
    return head;
}

//Problem Link: https://www.naukri.com/code360/problems/delete-node-in-ll_5881

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/


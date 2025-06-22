/************************************************************

    Following is the LinkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/

Node* insertBeforeValue(Node * head, int el, int val) {
    if(head == NULL){
        return NULL;
    }
    
    if(head->data == val){
    	Node* temp = new Node(el);
    	temp->next = head;
    	return temp;
	}

    Node* temp = head;

    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

/*
int main()
{
	{12, 5, 8, 7}
	head = insertBeforeValue(head, 100, 5);
	print(head);
}
*/


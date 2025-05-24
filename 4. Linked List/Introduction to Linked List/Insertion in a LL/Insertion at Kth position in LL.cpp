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

Node * insert(Node * head, int n, int pos, int val) {
    if(head == NULL){
        if(pos == 0){
            Node* newNode = new Node(val);
        }
        else{
            return head;
        }
    }

    if(pos == 0){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        if(cnt == (pos-1)){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        cnt++;
        temp = temp->next;
    }
    return head;
}

//Problem Link: https://www.naukri.com/code360/problems/insertion-in-a-singly-linked-list_4609646

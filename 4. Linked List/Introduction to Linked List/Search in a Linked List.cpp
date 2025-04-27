int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *temp = head;

    while(temp != nullptr){
        if(temp->data == k){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//Problem Link: https://www.naukri.com/code360/problems/search-in-a-linked-list_975381?leftPanelTabValue=PROBLEM

/*
Time complexity: O(n)
Space Complexity: O(1)
*/

struct Node {
    Node* next;
    int val;

    Node(int val){
        this->val  = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* temp = head;
        if(head == nullptr){
            return -1;
        }

        while(index>0 && temp){
            temp = temp->next;
            index--;
        }
        if(index>0 || temp == nullptr){
            return -1;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
        return;
        
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        if (head == nullptr){
            head = new Node(val);
            return ;
        }
            
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = new Node(val);
        return ;
    }
    
    void addAtIndex(int index, int val) {
        Node* temp = head;
        if(head == nullptr && index == 0){
            head = new Node(val);
        }
        else if(head == nullptr && index>0){
            return ;
        }
        
        Node* prev = temp;

        Node* newNode = new Node(val);
        if(index == 0){
            head = newNode;
            newNode->next = prev;
            return ;
        }

        while(index>0 && temp){
            prev = temp;
            temp = temp->next;
            index--;
        }
        
        prev->next = newNode;
        newNode->next = temp;

        return ;
    }
    
    void deleteAtIndex(int index) {
        if (head == nullptr){
            return ;
        }
        if(index == 0){
            head = head->next;
            return ;
        }
        Node* prev = head;
        Node* temp = head;
        while(index>0 && temp){
            prev = temp;
            temp = temp->next;
            index--;
        }
        if(index>0 || temp == nullptr){
            return ;
        }
        prev->next = temp->next;
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
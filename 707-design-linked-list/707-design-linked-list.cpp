class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) {
            val = v;
            next = nullptr;
        }
    };
    
    Node* head;
    unsigned int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (head == nullptr) {
            return -1;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
            if (curr == nullptr) {
                return -1;
            }
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        size++;
    }
    
    void addAtTail(int val) {
        Node* n = new Node(val);
        size++;
        if (head == nullptr) {
            head = n;
            return;
        }
        
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = n;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index > size) {
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        size++;
        Node* n = new Node(val);
        prev->next = n;
        n->next = curr;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == 0) {
            //deleting head is a special case
            if (head == nullptr){
                return;
            } 
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            size--;
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        size--;
    }
    
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
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
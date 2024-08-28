#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};

class SinglyLinkedList {

    Node* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Insert at a specific index
    void insertAt(int index, int value) {
        if (index < 0 || index > size) return;
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // Delete element at a specific index
    void deleteAt(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        size--;
    }

    // Returns the size of the linked list
    int getSize() {
        return size;
    }

    // Checks if the linked list is empty
    bool isEmpty() {
        return size == 0;
    }

    // Rotates the linked list to the right by k positions
    void rotateRight(int k) {
        if (size <= 1 || k % size == 0) return;
        k = k % size;
        Node* newHead = head;
        Node* newTail = nullptr;
        int count = 1;
        while (count < size - k) {
            newHead = newHead->next;
            count++;
        }
        newTail = newHead;
        newHead = newHead->next;
        newTail->next = nullptr;
        Node* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        head = newHead;
    }

    // Reverses the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Appends an element to the end of the linked list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Prepends an element to the beginning of the linked list
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Merges two linked lists
    void merge(SinglyLinkedList& other) {
        if (other.isEmpty()) return;
        if (isEmpty()) {
            head = other.head;
            size = other.size;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = other.head;
            size += other.size;
        }
        other.head = nullptr;
        other.size = 0;
    }

    // Interleaves two linked lists
    void interleave(SinglyLinkedList& other) {
        Node* temp1 = head;
        Node* temp2 = other.head;
        SinglyLinkedList result;
        while (temp1 || temp2) {
            if (temp1) {
                result.append(temp1->data);
                temp1 = temp1->next;
            }
            if (temp2) {
                result.append(temp2->data);
                temp2 = temp2->next;
            }
        }
        head = result.head;
        size = result.size;
    }

    // Returns the middle element of the linked list
    int getMiddle() {
        if (isEmpty()) throw runtime_error("List is empty");
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // Returns the index of the first occurrence of an element
    int indexOf(int value) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == value) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Splits the linked list into two at a specified index
    void split(int index, SinglyLinkedList& list1, SinglyLinkedList& list2) {
        if (index < 0 || index >= size) return;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        list1.head = head;
        list1.size = index + 1;
        list2.head = temp->next;
        list2.size = size - (index + 1);
        temp->next = nullptr;
        size = index + 1;
    }

   



    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int a ,b,c;
    cin>>a>>b>>c;
    cout<<endl;
    list.append(a);
    list.append(b);
    list.insertAt(1, c);
    list.display(); 
    list.display(); 
    cout << "Size: " << list.getSize() << endl; 
    return 0;
}

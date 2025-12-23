#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList{
    private:
    Node* head;
    public:
    SinglyLinkedList() {
        head = nullptr;
    }
    void InsertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void InsertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void InsertBetween(Node* prevNode, int val, int pos) {
        if (prevNode == nullptr) {
            cout << "The given previous node cannot be nullptr." << endl;
            return;
        }
        Node* newNode = new Node(val);
        for(int i = 1; i < pos; i++) {
            if (newNode->next == nullptr) break;
            newNode = newNode->next;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main(){
    SinglyLinkedList sll;
    sll.InsertAtEnd(10);
    sll.InsertAtEnd(20);
    sll.InsertAtEnd(30);
    cout << "Singly Linked List contents:" << endl;
    sll.Display();
    
    return 0;
}
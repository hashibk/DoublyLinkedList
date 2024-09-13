#include <iostream>
using namespace std;

template <typename T>
class doublylinkedlist;

template <typename T>
class Node{
    T data;
    Node<T> *next;
    Node<T> *prev;

public:

    Node (T d){
        data=d;
        next=nullptr;
        prev=nullptr;
    }

    friend class doublylinkedlist<T>;

};

template <typename T>
class doublylinkedlist{
    Node<T> *head;
    Node<T> *tail;

    public:

    doublylinkedlist(){
        head=nullptr;
        tail=nullptr;
    }

    void insertatstart(T d){
        Node<T> *newnode = new Node<T> (d);

        if (head==nullptr){
            head=tail=newnode;
        }

        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void insertatend(T d){
        Node<T> *newnode = new Node<T> (d);

        if (head==nullptr){
            head=tail=newnode;
        }

        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    void deletefromstart(){
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }

        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void deletefromend(){
        if (head == nullptr){
            return;
        } 
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void print(){
        Node<T> *temp=head;
        while (temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverseprint(){
        Node<T> *temp=tail;
        while (temp){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    void insertatmiddle (T d){
        Node<T> *slow=head;
        Node<T> *fast=head;
        Node<T> *newnode=new Node<T>(d);

        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        newnode->next=slow->next;
        if (slow->next != nullptr) {
            slow->next->prev = newnode;
        }
        else {
            tail = newnode;
        }
        slow->next = newnode;
        newnode->prev = slow;
    }

    void removeduplicates() {
        Node<T>* temp = head;

        while (temp) {
            Node<T>* temp2 = temp->next;
            while (temp2) {
                if (temp->data == temp2->data) {
                    Node<T>* duplicate = temp2;

                    if (temp2->prev) {
                        temp2->prev->next = temp2->next;
                    }
                    if (temp2->next) {
                        temp2->next->prev = temp2->prev;
                    } else {
                        // If temp2 is tail, update tail
                        tail = temp2->prev;
                    }

                    temp2 = temp2->next;
                    delete duplicate;
                } else {
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
    }

    bool insertBefore(T const v1, T const v2) {
        if (!head) return false;

        Node<T>* newnode = new Node<T>(v1);
        Node<T>* temp = head;

        if (head->data == v2) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return true;
        }

        while (temp) {
            if (temp->data == v2) {
                newnode->next = temp;
                newnode->prev = temp->prev;

                if (temp->prev) {
                    temp->prev->next = newnode;
                }
                temp->prev = newnode;

                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    void middleNode(){
        Node<T> *fast=head;
        Node<T> *slow=head;

        while (fast && fast->next){
            fast=fast->next;
            slow=slow->next;
            fast=fast->next;
        }

        cout<<slow->data<<endl;
    }

    void nodeswap(int k) {
        if (k <= 0) return; // Invalid position

        Node<T> *first = head;
        Node<T> *end = tail;
        int count = 1;

        // Find the k-th node from the start
        while (first && count < k) {
            first = first->next;
            count++;
        }

        count = 1;
        // Find the k-th node from the end
        while (end && count < k) {
            end = end->prev;
            count++;
        }

        // If either node is null or they are the same, no need to swap
        if (!first || !end || first == end) return;

        // If nodes are adjacent
        if (first->next == end) {
            Node<T>* prevFirst = first->prev;
            Node<T>* nextEnd = end->next;

            // Swap adjacent nodes
            if (prevFirst) {
                prevFirst->next = end;
            } else {
                head = end; // Update head if first was head
            }
            end->prev = prevFirst;
            end->next = first;
            first->prev = end;
            first->next = nextEnd;
            if (nextEnd) {
                nextEnd->prev = first;
            } else {
                tail = first; // Update tail if end was tail
            }
        } else {
            // Nodes are not adjacent
            Node<T>* prevFirst = first->prev;
            Node<T>* nextFirst = first->next;
            Node<T>* prevEnd = end->prev;
            Node<T>* nextEnd = end->next;

            // Swap nodes
            if (prevFirst) {
                prevFirst->next = end;
            } else {
                head = end; // Update head if first was head
            }
            if (prevEnd) {
                prevEnd->next = first;
            } else {
                head = first; // Update head if end was head
            }

            first->next = nextEnd;
            first->prev = prevEnd;
            end->next = nextFirst;
            end->prev = prevFirst;

            if (nextEnd) {
                nextEnd->prev = first;
            } else {
                tail = first; // Update tail if nextEnd was tail
            }
            if (nextFirst) {
                nextFirst->prev = end;
            } else {
                tail = end; // Update tail if nextFirst was tail
            }
        }
    }
};

int main(){

    doublylinkedlist<int> dll;
    dll.insertatend(7);
    dll.insertatend(9);
    dll.insertatstart(9);
    dll.insertatend(10);
    dll.insertatend(9);
    dll.insertatmiddle(15);
    dll.print();
    dll.removeduplicates();
    dll.insertBefore(6,10);
    dll.print();
    dll.reverseprint();
    dll.insertatend(10);
    dll.print();
    dll.middleNode();
    dll.nodeswap(2);
    dll.print();
}

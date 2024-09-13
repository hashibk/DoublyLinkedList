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

}

#include<iostream>
using namespace std;


class Node{

    public:

        int Data;
        Node *prev;
        Node *next;

        Node(int userI){
            this->Data = userI;
            this->prev = nullptr;
            this->next = nullptr;
        }
};


class Linked_list{

    public:

        Node *head;
        Node *tail;
        Node *ptr;

        Linked_list(){
            this->head = nullptr;
            this->tail = nullptr;
            this->ptr = nullptr;
        }

        void createList(){

            int userI;
            cout<<"Enter the value: "<<endl;
            cin>>userI;


            Node *newList = new Node(userI);

            if(head == nullptr){
                head = newList;
                tail = head;
            }

            else{

                tail->next = newList;
                newList->prev = tail;
                tail = newList;

            }
        }


        void printForwordList(){

            Node *curr = head;

            while(curr != nullptr){
                cout<<curr->Data<<" ";
                curr = curr->next;
            }cout<<endl;
        }

        void printBackwordList(){

            Node *curr = tail;

            while(curr != nullptr){
                cout<<curr->Data<<" ";
                curr = curr->prev;
            }cout<<endl;

        }
};

int main(){
    Linked_list obj;

    // Linked list create
    obj.createList();
    obj.createList();
    obj.createList();
    obj.createList();

    // Linked List Print Forword
    cout<<"Forword Move linked list: "<<endl;
    obj.printForwordList();

    cout<<"Backword Move linked list: "<<endl;
    // Linked list Print Backword
    obj.printBackwordList();
    
    return 0;

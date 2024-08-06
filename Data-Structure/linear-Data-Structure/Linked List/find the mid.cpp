#include<iostream>
using namespace std;


class Node{

    public:
        int Data;
        Node *next;

        Node(int userI){
            this->Data = userI;
            this->next = nullptr;
        }
};


class Linked_List{

    public:

        Node *head;
        Node *tail;

        Linked_List(){
            this->head = nullptr;
            this->tail = nullptr;
        }


        void createList(){

            int x;
            cout<<"Enter the value in the linked List:"<<endl;
            cin>>x;

            Node *newList = new Node(x);

            if(head == nullptr){
                head = newList;
            }

            else{
                tail = head;

                while(tail->next != nullptr){
                    tail = tail->next;
                }

                tail->next = newList;
            }
        }

        int MiddenNumber(){

            if(head == nullptr){
                return -1;
            }

            if(head->next == nullptr){
                return head->Data;
            }

           Node *fast = head;
           Node *slow = head;

            while(fast != nullptr && fast->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
            }

            return slow->Data;
        }
};





int main(){
    Linked_List obj;
    obj.createList();
    obj.createList();
    obj.createList();
    obj.createList();
    obj.createList();

    // check the midden element
    int midd = obj.MiddenNumber();
    if(midd == -1){
        cout<<"Empty linked list"<<endl;
    }
    else{
        cout<<"mid element in the linked list "<<midd<<endl;
    }
    return 0;
}
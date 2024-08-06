#include<iostream>
using namespace std;

// Single Linked List

class Node{
    public:

        int Data;
        Node *next;

        Node(int value){
            this->Data = value;
            this->next = nullptr;
        }

};

class Linked_List{
    public:

        Node *head;
        Node * tail;

        Linked_List(){
           head  = nullptr;
           tail = nullptr;
        }

        void insertion(){

            int userI;
            cout<<"Enter the value :"<<endl;
            cin>>userI;

            // create the node
            Node *newN = new Node(userI);

            if(head == nullptr){
                head = newN;
            }

            else{

                tail = head;

                while(tail->next != nullptr){
                    tail = tail->next;
                }

                // new Node Connect
                tail->next = newN;
            }
        }


        // print the data;

        void printLinked_List(){

            Node *Current = head;

            while(Current != nullptr){

                cout<<Current->Data<<" ";

                Current = Current->next;
            }cout<<endl;
        }


        int listL(){

            Node *Current = head;

            int lenght = 0;

            while(Current != nullptr){

                lenght++;

                Current = Current->next;
            }

            return lenght;
        }

        void reverseLinked(){

            if(head == nullptr){
                cout<<"empty Linked List"<<endl;
            }

            if(head->next == nullptr){
                cout<<"Reverse the Linked List"<<endl;
            }

            // three pointer threw reverse
            Node *prev = nullptr;
            Node *Next = nullptr;
            Node *curr = head;

            while(curr != nullptr){
                Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
            }

            // we will reverse throw the head
            head = prev;

        }

        int sumAll(){

            int sum = 0;

            Node *curr = head;

            while(curr != nullptr){
                sum += curr->Data;
                curr = curr->next;
            }

            return sum;
        }

        void removeElement(int userI) {
            if (head == nullptr) {
                cout << "Empty linked list" << endl;
                return;
            }

            // Handle the case where the head node itself needs to be removed
            while (head != nullptr && head->Data == userI) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }

            Node* curr = head;
            Node* prev = nullptr;

            while (curr != nullptr) {

                if (curr->Data == userI) {
                    prev->next = curr->next;
                    delete curr; // Free the memory of the removed node
                    curr = prev->next; // Move to the next node
                } 
                
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        bool searchingElement(int userI){

            Node *curr = head;

            while(curr != nullptr){
                if(curr->Data == userI){
                    return true;
                }
                curr = curr->next;
            }

            return false;
        }
};


int main(){
    
    Linked_List obj;

    // insert the element
    obj.insertion();
    obj.insertion();
    obj.insertion();
    obj.insertion();
    obj.insertion();
    obj.insertion();

    // print the linked list
    cout<<"Your Linked List "<<endl;
    obj.printLinked_List();


    // searching the element
    int elementS;
    cout<<"Searching Element: "<<endl;
    cin>>elementS;

    bool result = obj.searchingElement(elementS);
    if(result == true){
        cout<<"Element is present"<<endl;
    }else{
        cout<<"Element is not present"<<endl;
    }


    // remove the element by the value
    int userI;
    cout<<"Enter the value to Remove"<<endl;
    cin>>userI;

    obj.removeElement(userI);
    obj.printLinked_List();


    // find the lenght
    int lenght = obj.listL();
    cout<<"Length of the linked list: "<<lenght<<endl;


    // reverse the single linked list
    cout<<"reverse the single linked list :"<<endl;
    obj.reverseLinked();
    obj.printLinked_List();

    // Sum of the linked list
    int Sum = obj.sumAll();
    cout<<"Sum of the Linked list Element :"<<Sum<<endl;



    
    return 0;
}


// if you wanna the class function and attribute then you have to inisilize the obj then we can access
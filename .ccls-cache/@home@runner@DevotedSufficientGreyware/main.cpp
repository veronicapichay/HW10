//******************************************************************
//Program Name: Singly Linked List 
//Author: Veronica Pichay
//IDE Used: Repl.it
//Created : ‎Tuesday, ‎July ‎21, ‎2020,
//Program description: Creates linked list with fx to insert or delete and print, search and destroy the linked list
//*****************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

struct LinkedList
{
    int value;
    LinkedList *next;
};

LinkedList* appendNode(LinkedList * &, int);
LinkedList* insertNode(LinkedList *&, int, int);
LinkedList* deleteNode(LinkedList *&, int);
LinkedList* destroyList(LinkedList *&);
void printList(LinkedList *&);
void searchNode(LinkedList *&, int);

int main()
{
    //Declaration
    LinkedList *head = nullptr;
    LinkedList *ptr = nullptr;
    LinkedList *newNode = nullptr;
    int elmnts, num, index;
  
    cout << "\nEnter the number of nodes for this linked list : ";
    cin >> elmnts;
    //IVL
    while (elmnts < 1)
    {
        cout <<"Error! Enter element number/s greater than one!: " ;
        cin >> elmnts;
    }
    //Comment # 1 Create linked list using append fx
    for(int i = 0; i < elmnts; i++)
    {
        cout << "Enter element # " <<i  <<": ";
        cin >> index;
        head = appendNode(head, index); 
    }
    cout <<"\nHere are the initial values in the linked list:" << endl;
    printList(head);
    cout << endl;
    //Comment # 2 Inserting a new node using insert fx
    cout << "Enter the index number that you want to insert the new node: ";
    cin >> index;
    cout << "Enter number: ";
    cin >>  num;
    insertNode (head,num,index);
    cout <<"\nHere is the updated linked list:" << endl;
    printList(head);
    cout << endl;
    //Comment # 3 Deleting a node using deletenode fx
    cout << "Enter the value that you want to delete from the linked list: ";
    cin >> num;
    deleteNode(head, num);
    cout << endl;
    cout << "Here is the updated linked list:" << endl;
    printList(head);
    cout << endl;
    //Comment # 5 Search the linked list for user input node
    cout << "Enter the value that you want to search for in the list: ";
    cin >> index;
    searchNode(head, index);
    cout << endl;
    //Comment # 6 Destroy the entire list
    head = destroyList(head);
cout << "\nPress and key to continue...";

return 0;
}
//Comment # 7 Creates a linked list 
LinkedList* appendNode(LinkedList *& head, int item)
{
    LinkedList *newNode = new LinkedList;
    newNode->value = item;
    newNode->next = nullptr;

    if(head == nullptr)
        head = newNode;
    else {
        LinkedList *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
}
//Comment # 8 Inserts a node
LinkedList* insertNode(LinkedList *& head, int newNum, int index)
{
    LinkedList *newNode = new LinkedList; //Comment # 9 Allocates heap memory for new node
    newNode->value = newNum;
    newNode->next = nullptr;
    LinkedList *ptr = head;

//Comment # 10 If user enter number zero or less, it assumes that new node will be inseted in the beginning of the list
if(index <=  0) 
{
       newNode -> next = ptr;
       head =newNode;
}

else //Comment # 10 stops when the pointer in pointing before the given index
{
        for (int i = 0; i < (index - 1) && ptr->next != nullptr; i++, ptr = ptr->next);

      	newNode->next = ptr->next;
		ptr->next = newNode;
}
   return head;
}
//Comment # 11 Deletes a node from the list
LinkedList* deleteNode(LinkedList *&head, int num)
{
    LinkedList *prev = nullptr;
    LinkedList *ptr = head;
    //Comment # 12 Loop that continues to look for the user node value
    while(ptr != nullptr && ptr->value != num)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    ////Comment # 13 Loop that continues to look for the user node valueCondition for finding the value in the list
    if(ptr == nullptr)//If value not found in list
        return head;

    if(ptr == head)//Moves pointers forward
        head = head->next;
    else
        prev->next = ptr->next; //Deletes the node
    delete ptr;

return head;
}
//Comment # 14  Searches the list to find user choice node 
void searchNode (LinkedList *& head, int num)
{
    LinkedList *ptr = head;
    int idx = 0;
   //Comment # 15 Loop that continues to look for the user node value
    while(ptr != nullptr && ptr->value != num) 
    {
        ptr = ptr->next;
        idx++;
    
    }
    //Condition cout if number is found in the list
    if(ptr == nullptr)
    {
        cout << "\nTry again, cannot locate number!" << endl;
    }
    else
    {
        cout << "\nNumber found at index " << idx + 1 << " in the linked list" << endl;
    }
}
//Displays all the values in the linked list
void printList(LinkedList *& head)
{
    LinkedList *ptr = head;
    while(ptr != nullptr)
    {
        cout << ptr -> value << endl;
        ptr = ptr->next;
    }
}
//Deletes the whole linked list by using delete node fx
LinkedList* destroyList(LinkedList * &head)
{
    while(head != nullptr)
    {
    head = head -> next;
    head = deleteNode(head, head->value);
    delete head;
    }    
return head;
}
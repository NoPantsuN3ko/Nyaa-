#include <iostream>
using namespace std;
//THIS IS ABOUT LINKEDLIST.

// LINKED LIST CONCEPT:
//  1->2->3->4
// elements are connected to each other.
struct Node
{
    int data;
    Node *next; // purpose is to point to another node(or element)
    Node *prev; // purpose is to point to the previous node(or element)
};

void initNode(Node *tmpHead, int n) // it is actually deferencing. for ex: initNode(head, 1). This will actually trigger the first element
{
    tmpHead->data = n; // equivalent to *(tmpHead).data
    tmpHead->next = NULL;
    tmpHead->prev = NULL; 
}

int getTotNodes(Node *cur)
{ 
    int count = 0;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

void addNode(Node *cur, int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    while (cur->next)
    {
        cur = cur->next; // loop until you encounter null
    }

    // due to the loop, it now points to the very next element, which is currently empty/NULL.
  
    cur->next = newNode; // finally insert the new element.
    newNode->prev = cur; //cur is actually already pointing to prev, hence doing newNode->prev allows us to point to the previous value. 
}

void displayNodes(Node *cur)
{

    while (cur) // equivalent to saying while true.
    {
        cout << cur->data << "->";
        cur = cur->next;
        // loop will break once cur->next is pointing to             NULL. NULL is considered a falsy value, hence breaks.
    }

    cout << endl;
}

void displayReverse(Node *cur) {
  while (cur->next != NULL) { 
    cur = cur->next; 
  }
    while (cur) // equivalent to saying while true.
    {
        cout << cur->data << "->";
        cur = cur->prev;
        // loop will break once cur->next is pointing to             NULL. NULL is considered a falsy value, hence breaks.
    }
}

void addFront(Node **tmpHead, int n)
{ 
  // dereferencing what head's pointing to, which is A NEW     NODE. Recall -> Node *head = new Node; 
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *tmpHead; // if you deference it the first time, it is by default pointing on the FIRST element of the array/list, hence it is exactly what we want in this scenario

    *tmpHead = newNode;
}

void removeFront(Node **tempHead)
{
    if ((*tempHead)->next)
    { // basically if there exist an element that oldNode is pointing to.
      *tempHead = (*tempHead)->next;
      delete((*tempHead)->prev);
    }
    else
    {
        cout << "There is only one Node. Deletion not possible.";
    }
}

int main()
{
    //*head is pointing to a new Node
    Node *head = new Node;
    // head is now an array.
    initNode(head, 22);
    cout << "Total Nodes : " << getTotNodes(head) << endl;
    addNode(head, 33);
    addNode(head, 44);

    cout << endl;
    displayNodes(head);
    displayReverse(head);

    cout << endl << "addfront occurs" << endl;
    cout << endl;

    addFront(&head, 11);

    cout << endl << "Total Nodes : " << getTotNodes(head) << endl;
    displayNodes(head);
    displayReverse(head);
  
    removeFront(&head);

    cout << endl << "deletion occurs" << endl;
    cout << endl;


    cout << endl << "Total Nodes : " << getTotNodes(head) << endl;
    displayNodes(head);
    displayReverse(head);
    return 0;
}




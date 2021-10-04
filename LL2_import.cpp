#include<bits/stdc++.h>
using namespace std;

class node 
{
    public:
    int data;
    node* next;
    node(int value)
    {
        data=value;
        next=NULL;
    }

};

void display(node* &head)
{
    node* temp = head;

    while(temp!=NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lenLL(node* &head)
{
    int count = 0;
    node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void addAnywhere(node* &head, int value, int pos)
{
    node* newnode = new node(value);
    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    if(pos > lenLL(head)+1 || pos < 0)
    {
        cout << "please enter valid place" << endl;
        return;
    }
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    node* temp = head;
    int i = 2;
    while(i != pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void addBack(node* &head, int value)
{
    addAnywhere(head, value, lenLL(head)+1);
}

void addFront(node* &head, int value)
{
    addAnywhere(head, value, 1);
}

node* revLL(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* p1 = NULL;
    node* p2 = head;
    node* p3;

    while(p2 != NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;        
    }
    return p1;

}

node* recursiveRev(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* new_head = recursiveRev(head->next); // this is to return the new head 

    head->next->next = head; // this makes the heads next node point to the head itself thus breaking ties with the none

    head->next = NULL; // points the current head finally to NULL 

    return new_head; // return the new head to the outer program. 
}




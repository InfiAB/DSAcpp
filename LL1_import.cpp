#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};


void tailInsert(node* &head, int val)
{
    node* new_node = new node(val);

    if(head == NULL)
    {
        head = new_node;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void headInsert(node* &head, int val)
{
    node* new_node = new node(val);
    new_node->next = head;
    head = new_node;
}

void displayLL(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteLast(node* &head)
{
    node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node* temp1 = temp;
    temp1->next = NULL;
    temp = temp-> next;
    delete temp;
}

void deleteFirst(node* &head)
{
    node* temp = head;
    head = head->next;
    delete temp;
}

node* reverseList(node* &head)
{
    if(head == NULL)
    {
        return head;
    }
    node* prev = NULL;
    node* current = head;
    node* nex;

    while(current != NULL)
    {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    } 
    return prev;
}

void delete_mid(node* &head, int val)
{
    if(head == NULL)
    {
        return;
    }
    if(head->data == val)
    {
        deleteFirst(head);
        return;
    }
    node* temp = head;
    while(temp->next->data == val)
    {
        temp = temp->next;
    }
    node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

node* reverseRec(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    
    }

    node* newhead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}




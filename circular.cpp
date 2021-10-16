#include<bits/stdc++.h>
using namespace std;

class cirNode 
{
public:
    cirNode* next;
    int data;
    cirNode(int val)
    {
        data = val; 
    }
};

class cll
{
private:
    cirNode* head = NULL;
public:
    void pushL(int val)
    {
        cirNode* newnode = new cirNode(val);

        if(head == NULL)
        {
            head = newnode;
            newnode->next = newnode;
            return;
        }

        newnode->next = head;
        cirNode* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }    

        temp->next = newnode;
        //head = newnode;
    }

    void print()
    {
        cirNode* temp = head;

        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp != head);
        
        cout <<"LOOP" << endl;
    }

    void deleteL()
    {
        if(head == NULL)
            return;
        
        cirNode* temp = head;
        
        if(temp->next == head)
        {
            head = NULL;
        }

        while(temp->next->next == head)
        {
            temp = temp->next;
        }
        cirNode* del = temp->next;
        temp->next = head;
        delete del;
    }
};

int main()
{
    cll cll1;
    cll1.pushL(1);
    cll1.pushL(2);
    cll1.pushL(3);
    cll1.pushL(4);
    cll1.deleteL();
    cll1.print(); 
}
#include<bits/stdc++.h>
#include"LL1_import.cpp"
using namespace std;


int main()
{
    node* head = NULL;

    tailInsert(head, 1);
    tailInsert(head, 2);
    tailInsert(head, 3);
    tailInsert(head, 4);
    headInsert(head, 0);

    displayLL(head);

    head = reverseRec(head);
    delete_mid(head, 3);
    displayLL(head);
    return 0;
}
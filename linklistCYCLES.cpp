#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int data)
{
    this->data=data;
    this->next=NULL;
}
};
void insert(Node* &head,int data)
{
    Node *newNode=new Node(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void display(Node* &head)
{
    if (head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    
    Node* temp=head;
    while (temp!=NULL)
    {   if(temp->next==NULL)
    {
        cout<<temp->data;
    }
    else{
         cout<<temp->data<<"->";
    }
       
        temp=temp->next;
    }
    
    cout<<endl;

}

bool detectCycle(Node * &head)
{
    Node* slow=head;
    Node* fast=head;
    
    while (fast!=NULL && fast->next!=NULL)
    {
       fast=fast->next->next;
       slow=slow->next;
       if (fast==slow)  
       {
           return true;
       }
    }
    return false;
}
void makeCycle(Node* &head,int pos)
{
    Node* temp=head;
    Node* start;
    int count=1;
    while (temp->next!=NULL)
    {   
        if (count==pos)
        {
            start=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=start;
    
}
void removeCycle(Node* &head)
{
    Node* fast=head;
    Node* slow=head;
    fast=fast->next->next;
    slow=slow->next;
    while (fast!=slow)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    fast=head;

    while (fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}
int length(Node* &head)
{
    int len=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
Node* kappend(Node* &head,int k)
{
    int l=length(head);
    Node *newhead;
    Node *newtail;
    Node *tail=head;
    k=k%l;
    int count=1;
    while (tail->next!=NULL)
    {
        if(count==l-k)
        {
            newtail=tail;
        }
        if(count==l-k+1)
        {
            newhead=tail;
        }
        count++;
        tail=tail->next;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
}
Node* mappend(Node* head,int k)
{
    Node *newhead;
    Node *newtail;
    Node *tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while (tail->next!=NULL)
    {   
        if(count==l-k)
        {
            newtail=tail;
        }
        if(count==l-k+1)
        {
            newhead=tail;
        }
        count++;
        tail=tail->next;
    }
    tail->next=head;
    newtail->next=NULL;
    return newhead;
}
int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,6);
    insert(head,7);
    display(head);
    cout<<detectCycle(head)<<endl;      //0
    makeCycle(head,4);
    cout<<detectCycle(head)<<endl;     //1
    removeCycle(head);
    cout<<detectCycle(head)<<endl;     //0
    display(head);
    Node* newhead=kappend(head,3);
    display(newhead);
}




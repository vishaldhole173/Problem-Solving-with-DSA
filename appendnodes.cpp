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
        cout<<temp->data<<"->NULL";
    }
    else{
         cout<<temp->data<<"->";
    }
       
        temp=temp->next;
    }
    
    cout<<endl;

}
int length(Node* &head)
{   if (head==NULL)
{
    return 0;
}

    Node *temp=head;
    int len=1;
    while (temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
Node* appendknodes(Node* &head, int k)	
{	
    Node* tail=head;	
    Node* newhead;	
    Node* newtail;	
    int l=length(head);	
    int count=1;	
    k=k%l;	
    while (tail->next!=NULL)	
    {	
        if (count==l-k)	
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
int main()
{
    Node* head1=NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);
    insert(head1,6);
    insert(head1,7);
    display(head1);
    Node* newhead=appendknodes(head1,3);
    display(newhead);
}
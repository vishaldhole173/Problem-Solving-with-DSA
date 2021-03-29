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
void evenAfterOdd(Node* &head1)
{
    Node* odd=head1;
    Node* evenstart=head1->next;
    Node* even=head1->next;
    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    if (odd->next!=NULL)
    {
        even->next=NULL;
    }
    odd->next=evenstart;
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
    evenAfterOdd(head1);
    display(head1);
}
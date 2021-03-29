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
Node* merge(Node* &head1,Node* &head2)
{   
    Node* temp1=head1;
    Node* temp2=head2;
    Node *newNode=new Node(-1);
    Node *temp=newNode;
    while (temp1!=NULL && temp2!=NULL)
    {
        if (temp1->data<temp2->data)
        {
            temp->next=temp1;
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data){
            temp->next=temp2;
            temp2=temp2->next;
        } 
        temp=temp->next;
    }
    while(temp1!=NULL)
    {
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }
    while (temp2!=NULL)
    {
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }
   
    return newNode->next;
}
int main()
{
     Node* head1=NULL;
     Node* head2=NULL;
    insert(head1,1);
    insert(head1,4);
    insert(head1,5);
    insert(head1,7);
    insert(head2,2);
    insert(head2,3);
    insert(head2,6);
    display(head1);
    display(head2);
    Node *head3=merge(head1,head2);
    display(head3);

}
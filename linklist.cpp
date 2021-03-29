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
void insertNode(int data,Node * &head)
{   
    Node *newNode=new Node(data);
    if (head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void print(Node * &head)
{
    if (head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"NULL"<<endl;
    }
    
}
void insertAfter(int n,int data,Node * &head)
{
    Node *newNode=new Node(data);
    Node *temp=head;
    while(temp->data!=n)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void insertAthead(int data,Node* &head)
{
    Node *newNode=new Node(data);
    if (head==NULL)
    {
        head=newNode;
    }

    newNode->next=head->next;
    head->next=newNode;
    
}
void deleteNode(int data,Node* &head)
{
    Node *temp=head;
    while (temp->next->data!=data)
    {
        temp=temp->next;
    }
    Node *toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
Node* reverselist(Node* &head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* nextptr;
    while (curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nextptr;
    }
    return prev;
}
Node* reverseRecursive(Node* &head)
{   
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
Node* reversek(Node *head,int k)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* nextptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if (nextptr!=NULL)
    {
        head->next=reversek(nextptr,k);
    }
    return prev;
    
}
Node *reversek1(Node* &head,int k)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* nextptr;
    int count=0;
    while (curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
    head->next=reversek1(nextptr,k);
    }
    
    return prev;

    
}
int main()
{
    Node *head=NULL;
    insertNode(1,head);
    insertNode(2,head);
    insertNode(3,head);
    insertAfter(3,4,head);
    insertAfter(4,5,head);
    insertNode(6,head);
    insertAthead(0,head);
    print(head);
    
    deleteNode(3,head);
    print(head);
    //Node *newhead=reverselist(head);
    //Node* newhead=reverseRecursive(head);
    Node* newhead=reversek1(head,2);
    print(newhead);
    
}
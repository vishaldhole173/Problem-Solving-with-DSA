#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(Node* &head,int data)
{
    Node* newNode=new Node(data);

    newNode->next=head;
    if(head!=NULL) head->prev=newNode;
    head=newNode;
}
void insertAtTail(Node* &head,int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    Node* newNode=new Node(data);
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
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
    {   
        if (temp->next==NULL)
    {
        cout<<temp->data<<endl;
    }
    else{
        cout<<temp->data<<"->";
    }
        temp=temp->next;
    }
    
}
void deleteNode(Node* &head,int key)
{
    Node* temp=head;
    while (temp->data!=key)
    {
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    if (temp->next==NULL)
    {
       temp->next->prev=temp->prev;
    }
    
    delete temp;
}
int main()
{
    Node *head=NULL;
    insertAtHead(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    deleteNode(head,3);
    deleteNode(head,2);
    display(head);
}
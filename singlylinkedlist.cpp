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

void insert(Node * &head,int data)
{
    Node *n=new Node(data);
    if(head==NULL)
    {
        head=n;
        return; 
    }
    Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void insertAtHead(Node* &head,int data)
{
    Node* n=new Node(data);
    if(head==NULL)
    {
        head=n;
    }
    n->next=head;
    head=n;

}
void insertAfter(Node* &head,int element,int data)
{
    Node *n=new Node(data);
    Node *temp=head;
    while (temp->data!=element)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;

}
void display(Node *head)
{
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
bool search(Node* &head,int key)
{   
    if (head==NULL)
    {
        return false;
    }
    
    Node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==key) return true;
        temp=temp->next;
    }
    
    return false;
    
}
int main()
{
    Node *head=NULL;
    
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insertAfter(head,4,-4);
    insertAtHead(head,0);
    insertAtHead(head,-1);
    display(head);
    cout<<search(head,5)<<endl;
}
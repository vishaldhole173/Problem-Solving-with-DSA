#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void push(Node* &head,int data)
{
    Node *newNode= new Node(data);
    if (head==NULL)
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

int main()
{
    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    insertAtTail(head,11);
    insertAtTail(head,12);
    //insertinbetween(head,44,4);
    display(head);
}
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

void insertAtTail(Node* &head,int data)
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
Node* reverseLinklist(Node* &head)
{
    Node* prev=NULL;
    Node* next=NULL;
    Node* curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;  //1 2 null
        prev=curr;
        curr=next;
    }
    return prev;
}
Node* reversreRecursively(Node* &head)
{   
    Node *temp=head;
    if(temp==NULL || temp->next==NULL)
    {
        return temp;
    }
   
    Node* rest=reversreRecursively(temp->next);
    temp->next->next=temp;
    temp->next=NULL;
    return rest;
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
void insertinbetween(Node* &head,int val,int location)
{
    Node *temp=head;
    int len=length(temp);
    int count=1;
    while (count!=(location-1))
    {   
        count++;
        temp=temp->next;
    }
    if(count>len)
    {
        return;
    }
    
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;
    
}
Node* reversreRecursively1(Node* head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* rest=reversreRecursively1(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
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
    insertinbetween(head,44,4);
    display(head);
    Node *newhead=reversreRecursively1(head);
    display(newhead);

}
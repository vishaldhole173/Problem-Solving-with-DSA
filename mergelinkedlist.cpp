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

Node* mergell(Node* &head1,Node* &head2)
{
    Node* p1=head1;
    Node* p2=head2;
    Node *dummy=new Node(-1);
    Node *p3=dummy;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while (p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }  
    return dummy->next;
}

Node* mergelinklist(Node* &head1,Node* &head2)
{
    Node* p1=head1;
    Node* p2=head2;
    Node *dummy=new Node(-1);
    Node *p3=dummy;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while (p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    
    return dummy->next;
}
Node* mergeRecursively(Node* &head1,Node* &head2)
{
    if(head1==NULL)
    {
       return head2;
    }
    if (head2==NULL)
    {
        return head1;
    }
    
    Node* result;
    if (head1->data<head2->data)
    {
        result=head1;
        result->next= mergeRecursively(head1->next,head2);
    }
    else
    {
        result=head2;
        result->next= mergeRecursively(head1,head2->next);
    }
    return result;
}
int main()
{
    Node *head1=NULL;
    Node *head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,7);
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,6);
    display(head1);
    display(head2);
    Node* newhead=mergelinklist(head1,head2);
    display(newhead);
    // Node* newheadd=mergeRecursively(head1,head2);
    // display(newheadd);
    //we can either run recursively or itteratively

}
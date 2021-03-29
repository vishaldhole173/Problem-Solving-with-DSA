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
void intersect(Node* &head1,Node* &head2,int pos)
{
    Node* temp=head1;
    pos--;
    while (pos)
    {
        temp=temp->next;
        pos--;
    }
    Node *temp2=head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
}
int detectIsertion(Node* &head1,Node* &head2)
{
    int l1=length(head1);
    int l2=length(head2);
    int p=0;
    Node* temp1;
    Node* temp2;
    if (l1>l2)
    {
        p=l1-l2;
        temp1=head1;
        temp2=head2;
    }
    else{
        p=l2=l1;
        temp1=head2;
        temp2=head1;
    }
    
    while (p)
    {   
        p--;
        if(temp1==NULL)
        {
            return -1;
        }
        temp1=temp1->next;
    }
    while (temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
        {
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;

    }
    
    
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
    Node* head2=NULL;
    insert(head2,8);
    insert(head2,9);
    intersect(head1,head2,5);
    display(head1);
    display(head2);
    cout<<detectIsertion(head1,head2)<<endl;
}
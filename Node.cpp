#include<iostream>
#include<bits/stdc++.h>
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
Node* takeinput()
{   cout<<"enter data"<<endl;
    int data;
    cin>>data;
    Node *head=NULL;
    while (data!= -1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *temp;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
       cin>>data;
    }
     return head;

}
Node* input()
{
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while (data!=-1)
    {
        Node *newNode=new Node(data);
        
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;

        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{   Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    
}
Node * insert(Node *head,int i,int data)
{
    Node *newNode=new Node(data);
    int count=0;
    Node *temp=head;
    if(temp!=NULL && i==0)
    {
        newNode->next=temp;
        head=newNode;
        return head;
    }
    while (temp!=NULL && count<(i-1))
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        Node *a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;
}
Node * deleteNode(Node *head,int i)
{
    Node *temp=head;
    int count=0;
    if(temp!=NULL && i!=0)
    {
        while (count<(i-1))
        {
            temp=temp->next;
            count++;
        }
        Node *b=temp->next;
        delete b;
        Node *a=temp->next->next;
        temp->next=a;

        
    }
    if(temp!=NULL && i==0)
    {
        temp=temp->next;
        head=temp;
    }
    return head;
}
int findLength(Node *head)
{   
    Node *temp=head;
    Node *slow=temp;
    Node *fast=temp->next;
    int len=0;
    while (fast!=NULL || fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
        len++;

    }
    
    return len;
}

Node *reverseLink(Node *head)  //Time Complexity 0(n^2)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *small=reverseLink(head->next);
    Node *temp=small;
    while (temp->next!=NULL)    
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return small;
    
}
int main()
{
    Node *head=input();
   
    //head=insert(head,5,99);
    //head=deleteNode(head,0);
    print(head);
    cout<<endl;
    head=reverseLink(head);
    print(head);
    head=reverseLink(head);
    print(head);
    // int len=findLength(head);
    // cout<<len<<endl;
    
    delete  head;
    
}
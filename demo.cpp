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
class Pair{
    public:
    Node *head;
    Node *tail;
};
Pair reverseLink(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reverseLink(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;

}
Node * reverseLL(Node *head)
{
    return reverseLink(head).head;
}
Node * insert()
{
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    Node *head=NULL;
    while (data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
        }
        Node *temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
        cin>>data;
    }
    return head;
}
Node* reverseLinkList(Node *head)
{
    if(head==NULL || head=>next=NULL)
    {
        return head;
    }
    Node *smallAns=reverseLinkList(head->next);
    Node *tail=head->next;
}
void print(Node * head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"LL is empty"<<endl;

    }
    else
    {
        while (temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        
    }
    
}
int main()
{
    Node *head=insert();
    print(head);
    cout<<endl;
    head=reverseLL(head);
    print(head);
}
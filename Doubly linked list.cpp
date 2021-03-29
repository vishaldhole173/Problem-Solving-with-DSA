#include<iostream>
using  namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert_front(struct Node** head,int newdata)
{
struct Node* newnode=new Node;
newnode->data=newdata;
newnode->next= (*head);
newnode->prev=NULL;

if((*head)!=NULL)
{
    (*head)->prev=newnode;
}
(*head)=newnode;
}

void insert_After(struct Node* prev_node,int newdata)
{
    if(prev_node=NULL)
    {
        return;
    }
    struct Node* newnode=new Node;
    newnode->data=newdata;
    newnode->next=prev_node->next;
    prev_node->next=newnode;
    newnode->prev=prev_node;
    if(newnode->next!=NULL)
    {
        newnode->next->prev=newnode;
    }
}

void insert_end(struct Node ** head,int newdata)
{
    struct Node* newnode=new Node;
    struct Node* last=new Node;
    newnode->data=newdata;
    newnode->next=NULL;

    if((*head)==NULL)
    {
        newnode->prev=NULL;
        *head=newnode;
        return;
    }

   while (last->next!=NULL)
   {
       last=last->next;
   }

   last->next=newnode;
   newnode->prev=last;
   
    return;
}

void display(struct Node* node)
{
    struct Node* last;
    while (node!=NULL)
    {
        cout<<node->data<<"<==>";
        last=node;
        node=node->next;
    }

    if(node=NULL)
    {
        cout<<"NULL";
    }
    
}

int main()
{
    struct Node* head=NULL;

    
   // Insert 40 as last node
   insert_end(&head, 40);
  
   // insert 20 at the head
   insert_front(&head, 20);
  
   // Insert 10 at the beginning.
   insert_front(&head, 10);
  
   // Insert 50 at the end.
   insert_end(&head, 50);
  
   // Insert 30, after 20.
   insert_After(head->next, 30);
  
   cout<<"Doubly linked list is as follows: "<<endl;
   displayList(head);
   return 0;
    
}
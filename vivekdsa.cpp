#include<stdio.h>
#include<iostream>
struct Node
{
    int data;
    struct Node* next;
}s1;
typedef struct Node Node;
int main()
{
    s1.data=10;
    s1.next=NULL;
    //cout<<s1.data<<"->"<<s1.next;
    printf("%d",s1.data);
    Node* head= (Node*) malloc(sizeof(Node));
}
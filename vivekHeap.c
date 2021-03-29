#include<stdio.h>
void insert(int a[],int val)
{
    a[++a[0]]=val;
    int current=a[0];
    while(current!=1)
    {
        if(a[current]>a[current/2])
        {
            int temp=a[current];
            a[current]=a[current/2];
            a[current/2]=temp;
        }
        else{
            break;
        }
        current=current/2;
    }
}
void createHeap(int a[])
{
    printf("enter number of elementa\n");
    int n;
    scanf("%d",&n);
    a[0]=0;
    for (int i = 0; i <n; i++)
    {
        int val;
        printf("enter element: ");
        scanf("%d",&val);
        insert(a,val);
    }
    
}
void printHeap(int a[])
{
    for (int i = 0; i <= a[0]; i++)
    {
        printf("%d\t",a[i]);
    }
    
}
int deleteMax(int a[])
{   
    if(a[0]==0)
    {
        return -1;
    }
    int max=a[1];
    a[1]=a[a[0]--];
    int parent=1;
    int leftchild=parent*2;
    int rightchild=leftchild+1;
    while (leftchild<=a[0] && rightchild<=a[0])
    {
        if(leftchild>rightchild)
        {
            int temp=leftchild;
            leftchild=parent;
            parent=leftchild;
        }
        else
        {
            int temp=rightchild;
            rightchild=parent;
            parent=rightchild;
        }
    }
    
}

int main()
{   
   
    int a[20];
    createHeap(a);
    printf("\n");
    printHeap(a);
}
/*
priority-> 1. min priority queue 2. max priority queue
should be implemented using Balanced BST but there is problem of balancing and storage
So we use heaps for implementing priority queues
Complete binary tree:- trees whose all level are completely filled from left to right, except last level and that last level should 
also be filled from left to right
height of CBT is always log(N), hence problem of balancing height of BST is solved by CBT
Also we can store CBT in form of array, hence storing problem of BST is also solved by CBT 
In CBT, left child 2i+1, right child 2i+2 where i is array index
min nodes in CBT= 2^(h-1) 
max nodes in CBT= 2^h-1
Properties of heap: complete binary tree & heap order property 
In min heap, root should be less than left and right child (consider only parent child relationship)
In max heap, root should be greater than left and right child (consider only parent child relationship)
*/
#include<iostream>
#include<vector>
using namespace std;
class PriorityQueueue{

vector<int> pq;
public:

PriorityQueueue()
{
//     pq={10,100,12,200,400,18,15};
}

bool isEmpty()
{
    return (pq.size()==0);
}

int getSize()
{
    return pq.size();
}

int getMin()
{   
    if (isEmpty())
    {
       return 0; 
    }
    
    return pq.at(0);
}
// to insert one element time complexity is O(logn)
void insert(int element)
{
    pq.push_back(element);
    int childindex=pq.size()-1;
    
    while (childindex>0)
    {
        int parentindex=(childindex-1)/2;
        if(pq[childindex]<pq[parentindex])
        {
            int temp=pq[childindex];
            pq[childindex]=pq[parentindex];
            pq[parentindex]=temp;
        }
        else
        {
            break;
        }
        childindex=parentindex;
    }
    
}
//Heap sort
// Time complexity= O(nlogn)
// Space complexity= O(n)

int removeMin()  
{   
    if (isEmpty())
    {
        return 0; //Checking is priority queue empty
    }
    int ans=pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();

    //down heapify

    int parentindex=0;
    int leftchildindex=2*parentindex+1;
    int rightchildindex=2*parentindex+2;
    while ( leftchildindex<pq.size() )
    {
        int minIndex=parentindex;
        if (pq[minIndex]>pq[leftchildindex])
        {
            minIndex=leftchildindex;
        }
        if(rightchildindex<pq.size() && pq[minIndex]>pq[rightchildindex] )
        {
            minIndex=rightchildindex;
        }
        if (minIndex==parentindex)
        {
            break;
        }
        int temp=pq[minIndex];
        pq[minIndex]=pq[parentindex];
        pq[parentindex]=temp;

        parentindex=minIndex;
        leftchildindex=2*parentindex+1;
        rightchildindex=2*parentindex+2;
    }
    
    return ans;
}
};

int main()
{
    PriorityQueueue p;               //10,100,12,200,400,18,15
    cout<<"size: "<<p.getSize()<<endl;
    cout<<"min element: "<<p.getMin()<<endl;
    p.insert(5);                    
    cout<<"min element: "<<p.getMin()<<endl;
    cout<<"is empty: "<<p.isEmpty()<<endl;
    cout<<endl;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    int n=8;
    while(n--)
    {
        cout<<p.removeMin()<<" ";
    }
    
    
}
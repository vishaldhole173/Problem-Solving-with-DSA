#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class BinaryTree{
  public:
  int data;
  BinaryTree* left;
  BinaryTree* right;
  BinaryTree(int data)
  {
      this->data=data;
      this->left=NULL;
      this->right=NULL;
  }
};
BinaryTree* arraytoBST(int a[],int start,int end){
    if (start > end)  
    return NULL;  
  
    int mid = (start + end)/2;  
    BinaryTree *root =new BinaryTree(a[mid]);  
    
    root->left = arraytoBST(a, start,mid - 1);  
  
    root->right = arraytoBST(a, mid + 1, end);  
  
    return root;  
}
BinaryTree * BSTtosortedLL(BinaryTree *root)
{
    
}
vector<int> *getRootToNodePath(BinaryTree *root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftoutput=getRootToNodePath(root->left,data);
    if(leftoutput!=NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int>* rightoutput=getRootToNodePath(root->right,data);
    if(rightoutput!=NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
    {
        return NULL;
    }
    
}
void inorder(BinaryTree *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(BinaryTree *root){
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
	{
	    cin>>a[i];
	}
	BinaryTree *root=arraytoBST(a,0,size-1);
	//preorder(root);
    inorder(root);
	}
	return 0;
}


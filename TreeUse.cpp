#include<iostream>
#include<queue>
#include "Tree.h"
using namespace std;

void printTree(TreeNode *root)
{
    cout<<root->data<<":"<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    
    
}

void printTreee(TreeNode *root)
{
    queue<TreeNode *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size()!=0)
    {
        TreeNode *front=pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<": ";
        int child=front->children.size();
        for (int i = 0; i < child; i++)
        {
            cout<<front->children[i]->data<<",";
            pendingNode.push(front->children[i]);
        }
        cout<<endl;    
    }
}
TreeNode * takeInput()
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    TreeNode *root=new TreeNode(rootdata);

    queue<TreeNode *> pendingNodes;

    pendingNodes.push(root);

    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    }
    return root;

}
int numNodes(TreeNode *root)
{   if (root==NULL)
{
    return 0;
}

    int ans=1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans+=numNodes(root->children[i]);
    }
    return ans;
    
}
int sum(TreeNode *root)
{   if (root==NULL)
{
    return 0;
}

    int ans=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans+=sum(root->children[i]);
    }
    return ans;
}
int maxNode(TreeNode *root)
{   if (root==NULL)
{
    return 0;
}

    int max=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int a=maxNode(root->children[i]);
        if(a>max)
        {
            max=a;
        }
    }
    return max;
}
void printAtLevelK(TreeNode *root,int k)
{   if (root==NULL)
{
    return;
}

    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
    
}
int numLeafNodes(TreeNode *root)
{
    int num=0;
    if (root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        num+=numLeafNodes(root->children[i]);
    }
    return num;
}
void preOrder(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"\t";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}
//postorder
void postorder(TreeNode *root)
{   if (root==NULL)
    {
    return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<"\t";
}

void deleteTree(TreeNode *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
    
}


int main()
{   //Tree: 1 3 2 3 4 2 5 6 2 7 8 0 1 9 0
    
    TreeNode *root=takeInput();
    printTreee(root);
    cout<<endl<<numNodes(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<maxNode(root);
    //find height
    int k;
    cout<<endl<<"enter k"<<endl;
    cin>>k;
    printAtLevelK(root,k);
    cout<<endl<<"number of lesf nodes: "<<numLeafNodes(root)<<endl;
    preOrder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    deleteTree(root);  
    delete root; //deleting with help of destructor

}
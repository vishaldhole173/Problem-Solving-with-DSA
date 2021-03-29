#include<iostream>
#include<queue>
using namespace std;

class BinaryTee{
    public:
    int data;
    BinaryTee *left;
    BinaryTee *right;

    BinaryTee(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~BinaryTee()
    {
        delete left;
        delete right;
    }
};
BinaryTee* takeInput()
{
    cout<<"Enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    if (rootdata==-1)
    {
        return NULL;
    }
    BinaryTee *root=new BinaryTee(rootdata);
    queue<BinaryTee *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)  
    {
        BinaryTee *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child data of "<<front->data<<endl;
        int leftdata;
        cin>>leftdata;
        if (leftdata!=-1)
        {
            BinaryTee *leftchild=new BinaryTee(leftdata);
            front->left=leftchild;
            pendingNodes.push(leftchild);
        }
        cout<<"Enter right child data of "<<front->data<<endl;
        int rightdata;
        cin>>rightdata;
        if (rightdata!=-1)
        {
            BinaryTee *rightchild=new BinaryTee(rightdata);
            front->right=rightchild;
            pendingNodes.push(rightchild);
        }
        
        
    }
    
    return root;
}

void print(BinaryTee *root)
{
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if (root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<" ";
    }
    if (root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
    
}

int numNodes(BinaryTee *root)
{
    if (root==NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);

}
void printLevelwise(BinaryTee *root)
{
    if (root==NULL)
    {
        return;
    }
    queue<BinaryTee *> level;
    level.push(root);
    while (level.size()!=0)
    {
        BinaryTee *front=level.front();
        level.pop();
        cout<<front->data<<": ";
        if (front->left!=NULL)
        {
            cout<<"L"<<front->left->data<<" ";
            level.push(front->left);
        }
        if (front->right!=NULL)
        {
            cout<<"R"<<front->right->data<<" ";
            level.push(front->right);
        }
        cout<<endl;
    }
    
    
}

void inorder(BinaryTee *root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);   
}
int height(BinaryTee *root)
{
    if (root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
    
}
int diameter(BinaryTee *root)
{
    if (root==NULL)
    {
        return 0;   
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
    
}
pair<int,int> heightDiameter(BinaryTee *root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftans=heightDiameter(root->left);
    pair<int,int> rightans=heightDiameter(root->right);
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;
    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}
void search(BinaryTee *root, int k)
{
    if (root==NULL)
    {
        return;
    }
    if (root->data==k)
    {
        cout<<"Element is present"<<endl;
    }
    
    if (k<root->data)
    {
        search(root->left,k);
    }
    if (k>=root->data)
    {
        search(root->right,k);
    } 
}
void printBetweenK1K2(BinaryTee *root,int k1,int k2)
{
    if (root==NULL)
    {
        return;
    }
    if (root->data>=k1 && root->data<=k2)
    {
        cout<<root->data<<endl;
    }
    if (root->data>k1)
    {
        printBetweenK1K2(root->left,k1,k2);
    }
    if(root->data<=k2)
    {
        printBetweenK1K2(root->right,k1,k2);
    }  
}
int maximum(BinaryTee *root)
{
    if (root==NULL)
    {
        return INT8_MIN;
    }

    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTee *root)
{
    if (root==NULL)
    {   
        return INT8_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTee *root)
{
    if (root==NULL)
    {
        return true;
    }
    int lefttmax=maximum(root->left);
    int rightmin=minimum(root->right);
    bool output= (root->data>lefttmax) && (root->data<=rightmin)  && isBST(root->left) && isBST(root->right);
    return output;
}
bool isBST2(BinaryTee *root,int min=INT8_MIN,int max=INT8_MAX)
{
    if (root==NULL)
    {
        return true;
    }
    if (root->data<min || root->data>max)
    {
        return false;
    }
    bool isLeftOK=isBST2(root->left,min,root->data-1);
    bool isRightOK=isBST2(root->right,root->data,max);
    return isLeftOK && isRightOK;
    
}
int main()
{  
   /* 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
    5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1 */
   BinaryTee *root=takeInput();
   printLevelwise(root);
   cout<<"Total Nodes are "<<numNodes(root);
   cout<<endl;
   inorder(root);
   cout<<endl<<diameter(root)<<endl;
   cout<<isBST(root)<<endl;
   cout<<isBST2(root)<<endl;
   cout<<"Enter element to be searched"<<endl;
   int k;
   cin>>k;
   search(root,k);
   printBetweenK1K2(root,2,4);
   delete root;
}
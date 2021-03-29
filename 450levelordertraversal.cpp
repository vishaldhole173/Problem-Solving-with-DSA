#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
Node* input()
{
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1) 
    {
        return NULL;
    }
    Node* root=new Node(rootdata);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {   
        Node* front=q.front();
        q.pop();
        cout<<"enter left child data of "<<front->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            Node* leftchild= new Node(leftdata);
            front->left=leftchild;
            q.push(leftchild);
        }
        cout<<"enter right child data of "<<front->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            Node* rightchild=new Node(rightdata);
            front->right=rightchild;
            q.push(rightchild);
        }
    }
    return root;
}
Node* input1()
{
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    queue<Node*> q;
    Node* root=new Node(rootdata);
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout<<"enter left child data of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            Node* leftchild=new Node(leftdata);
            temp->left=leftchild;
            q.push(leftchild);
        }
        cout<<"emter right child data of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            Node* rightchild=new Node(rightdata);
            temp->right=rightchild;
            q.push(rightchild);
        }
    }
    return root;
}
vector<int> levelOrder(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        ans.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
    }
    return ans;
}
void reverseOrder(Node* root)
{
    vector<int> ans;
    if(!root)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        ans.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int height(Node* root)
{
    if(!root) return 0;
    int x=height(root->left);
    int y=height(root->right);
    return (max(x,y)+1);
}
int ma;
int func(Node* root)
{
    if(!root) return 0;
    int x=func(root->left);
    int y=func(root->right);
    ma=max(ma,(x+y+1));
    return (max(x,y)+1);
}
int diameter(Node* root)
{
    ma=INT_MIN;
    int x=func(root);
    return ma;
}
vector<int> leftview(Node* root)
{
    vector<int> ans;
    queue<Node*> q;
    if(!root) return ans;
    q.push(root);
    while(!q.empty())
    {   
        int size=q.size();
        ans.push_back(q.front()->data);
        while (size--)
        {
            Node* temp=q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
        }
        
    }
    return ans;
}
vector<int> rightview(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp;
        int size=q.size();
        while(size--)
        {
            temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(temp->data);
    }
    return ans;
}
void topview(Node* root)
{
    map<int,int> m;
    if(!root) return;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        Node* t=q.front().first;
        int h=q.front().second;
        q.pop();
        if(!m[h]) m[h]=t->data;
        if(t->left) q.push({t->left,h-1});
        if(t->right) q.push({t->right,h+1});
    }
    for(auto z:m) cout<<z.second<<" ";
    cout<<endl;
}
vector<int> zigzag(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
     int level=1;
    while(!q.empty())
    {
        int size=q.size();
       vector<int> t;
        while(size--)
        {   
            
            Node* temp=q.front();
            q.pop();
            t.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(level%2==0) reverse(t.begin(),t.end());
        for(int i=0;i<t.size();i++) ans.push_back(t[i]);
        level++;
    }
    return ans;
}
int main()
{
    Node* root=input1();
    vector<int> ans=levelOrder(root);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    reverseOrder(root);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
    vector<int> ans1=leftview(root);
    for(auto i:ans1) cout<<i<<" ";
    cout<<endl;
    vector<int> ans2=rightview(root);
    for(auto i:ans2) cout<<i<<" ";
    cout<<endl;
    topview(root);
    vector<int> ans3=zigzag(root);
    for(auto i:ans3) cout<<i<<" ";
    cout<<endl;
}
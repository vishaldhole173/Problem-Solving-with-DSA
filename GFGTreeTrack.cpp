#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
void printLevel(Node *root)
{

    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            q.push(NULL);
            cout<<"\n";
            continue;
        }
        cout<<curr->data<<" ";
        if(curr->left) q.push(root->left);
        if(curr->right) q.push(root->right);
    }

}
int main()
{
    Node *root;

}
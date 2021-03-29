#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *left,*right;
};
typedef struct BSTNode BSTNode;
BSTNode* insert(BSTNode* root,int val)
{
    if (root==NULL)
    {
        root=(BSTNode*) malloc(sizeof(BSTNode));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
        if (val>root->data)
        {
            root->right=insert(root->right,val);
        }
        else
        {
            root->left=insert(root->left,val);
        }
    return root;
}

void preorder(BSTNode* root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(BSTNode* root)
{
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
    
}
void inorder(BSTNode* root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->right);
    printf("%d\t",root->data);
    inorder(root->left);
}
// int height(BSTNode* root)
// {
//     if (root==NULL)
//     {
//         return 0;
//     }
//     int lefth=height(root->left);
//     int righth=height(root->right);
//     int ans=1+max(lefth,righth);
//     return ans;
// }
BSTNode* mirrorTree(BSTNode* root)
{
    
    if (root == NULL)
        return root;
    BSTNode* t = root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}
BSTNode* mirrorTree1(BSTNode* root)
{
    if (root==NULL)
    {
        return root;
    }
    BSTNode* t=root->left;
    root->left=root->right;
    root->right=t;

    if(root->left) mirrorTree1(root->left);

    if(root->right) mirrorTree1(root->right);

    return root;
}
int main()
{
    int n;
    printf("enter number of nodes\n");
    scanf("%d",&n);
    BSTNode *root=NULL;
    int val;
    for (int i = 0; i < n; i++)
    {   
        
        printf("Enter element\n");
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("\npreorder  ");
    preorder(root);
    printf("\npostorder  ");
    postorder(root);
    printf("\ninorder before mirroring ");
    inorder(root);
    printf("\ninorder after mirroring  ");
    BSTNode* newroot=mirrorTree1(root);
    inorder(newroot);
    // int h=height(root);
    // printf("\n%d",h);
}
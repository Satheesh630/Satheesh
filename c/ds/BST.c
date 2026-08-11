#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *left,*right;
}Node;

Node * createNode(int val)
{
	Node * new=(Node *) malloc(sizeof(Node));
	new->val=val;
	new->left=NULL;
	new->right=NULL;
	return new;
}
Node * insert(Node *root,int val)
{
	if(!root)
		return createNode(val);
	if(root->val > val)
		root->left=insert(root->left,val);
	else if(root ->val < val)
		root->right=insert(root->right,val);
	return root;
}
void inorder(Node *root)
{
	if(!root)
		return ;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);

}
void preorder(Node * root)
{
	if(!root)
		return;
	printf("%d ",root->val);
	postorder(root->left);
	postorder(root->right);

}
void postorder(Node *root)
{
	if(!root)	return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->val);
}
int main()
{
	Node *root=insert(NULL,15);
	insert(root,20);
	insert(root,10);
	insert(root,11);
	insert(root,14);
	inorder(root);
	printf("\n Post order: ");
	postorder(root);
	printf("\nPre Order:");
	preorder(root);
}

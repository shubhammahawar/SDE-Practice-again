#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Check if a tree is Balanced Binary Tree

a binary tree in which the left and right subtrees of 
every node differ in height by no more than 1.

height(Tree)=height(Leftsubtree)-height(Rightsubtree)
            ={-1,0,1}

T.C= O(N)
S.C= O(N)

 Analysis - we will use the concept of maximum height of left
            and right subtree and once if their diff
            is >1 it means it is unbalanced 
            So we willreturn -1
            and if any subtree return -1 it means it is unbalanced



*/

lli checkbalanced(TreeNode*root)
{
	if(root==NULL)
		return 0;

	lli l=checkbalanced(root->left);
	lli r=checkbalanced(root->right);

	if(l==-1 || r==-1)
		return -1;

	if(abs(r-l)>1)
		return -1;

	return max(l,r)+1;
}


bool isBalanced(TreeNode* root) {

	if(root==NULL)
		return true;

	int ans=checkbalanced(root);

	if(ans==-1)
		return 0;

	else
		return 1;
}
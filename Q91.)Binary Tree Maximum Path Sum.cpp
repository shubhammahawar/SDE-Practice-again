#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes 
where each pair of adjacent nodes in the sequence
has an edge connecting them. A node can only appear
in the sequence at most once. Note that 
the path does not need to pass through the root.


T.C = O(N)
S.C = O(N)

Analysis - We will traverse through left and right subtree
           and take one variable maxe to store  
           maximum sum path from left and right subtree
           and return the max(l,r)+root->val to the parent root





*/



  int maximumpath(TreeNode* root,int &maxe)
{
	if(root==NULL)
		return 0;

	int l=max(0,maximumpath(root->left,maxe));
	int r=max(0,maximumpath(root->right,maxe));


  maxe=max(maxe,l+r+root->val);

  return max(l,r)+root->val;

}


 int maxPathSum(TreeNode* root) {

 	lli maxe=INT_MIN;

 	maximumpath(root,maxe);

 	return maxe;

 }
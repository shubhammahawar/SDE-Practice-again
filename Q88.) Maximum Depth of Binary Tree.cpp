#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Find maximum depth of a binary tree

A binary tree's maximum depth is the number of nodes
 along the longest path from the root node down to 
 the farthest leaf node.

 T.C= O(N)
 S.C=O(N)

 Analysis -: Here we will use the concept of maximum height between
             left and right subtree and that will be the maximum depth
             

*/

int maxDepth(TreeNode* root) {


	if(root==NULL)
		return 0;

	lli l=maxDepth(root->left);
	lli r=maxDepth(root->right);

	return max(l,r)+1;
}
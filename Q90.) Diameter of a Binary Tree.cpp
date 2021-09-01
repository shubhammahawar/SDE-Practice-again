#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Diameter of Binary Tree

The diameter of a binary tree is the length of 
the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented
 by the number of edges between them.

 T.C=O(N)
 S.C=O(N)


 Analysis - We will again find the height of left and right
            subtree with including changes that if 
            (left_height + right_height)> maxi
            we will store this our maximum diameter till now
            and return the maximum height from left and right subtree



*/

lli finddm(TreeNode* root,lli &maxi)
{
	if(root==NULL)
		return 0;

	lli l=finddm(root->left,maxi);
	lli r=finddm(root->right,maxi);

   maxi=max(maxi,l+r);

   return max(l,r)+1;


}



  lli diameterOfBinaryTree(TreeNode* root) {

  	lli maxi=INT_MIN;

  	finddm(root,maxi);

  	return maxi;
  }


















#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Check for a Symmetrical Binary Tree---

T.C = O(N)
S.C = O(N)

Input -          1
             2        2
           3    4 4      3

 Output - True both are symmetrical


 Analysis - In a mirror symmtry left is symmetrical to right symmetrical
            we will simaltenously travel left and right 
            and accordingly check the symmtry.

*/

class Solution {

bool mirror(TreeNode*r1, TreeNode*r2)
{
	if(r1==NULL || r2==NULL)
		return (r1==r2);

	if(r1->data!=r2->data)
		return false;

	return (mirror(r1->left,r2->right) && mirror(r1->right,r2->left));
}

public:

	 bool isSymmetric(TreeNode* root) {

	 	return (root==NULL || mirror(root->left,root->right) );
	 }
	}
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Print Root to Node Path in Binary Tree

T.C = O(N)
S.C = O(H)

Input       1
         2     3
       4   5  6   7

       Output 1->2->5

 Analysis - We will take inorder traversal and store evry node value
            in vector if for any left subtree or right subtree
            we got the desired node value we will return true
            other wise false and pop out the value from vector      

*/

bool check(TreeNode* A, int B,vector<int>&v)
{
	if(A==NULL)
		return false;

	v.push_back(A->val);

	if(A->val==B)
		return true;

	if(check(A->left,B,v) || check(A->right,B,v))
		return true;

	v.pop_back();
	return false;

}


vector<int> Solution::solve(TreeNode* A, int B) {

	vector<int>v;
	check(A,B,v);

	return v;
}
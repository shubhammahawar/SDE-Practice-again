#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Iterative PostOrder Traversal using 2 Stack-

T.C= O(N)
S.C= O(N)

Analysis- We are using 2 stack in 1st stack we are traversing
          node as left->right->root
          and in second stack everytime popping the node
          from 1st stack and pushing it  into 2nd stack


*/


void preinpos(TreeNode*root)
{

vector<lli>ans;
stack<TreeNode*>st1;
stack<TreeNode*>st2;


if(root==NULL)
	return ans;

st1.push(root);


while(!st1.empty())
{

   TreeNode*r=st1.top();
   st1.pop();
   s2.push(r);

   if(r->left)
   	st1.push(r->left);

   if(r->right)
   	st1.push(r->right);

}

while(!s2.empty())
{
	ans.push_back(s2.top()->val);
}



return ans;
}



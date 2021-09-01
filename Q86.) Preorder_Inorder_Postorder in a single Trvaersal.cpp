#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Print the Preorder ,Inorder and Postorder in a single Traversal

T.C =O(3*N)
S.C =O(N)


*/



void preinpos(TreeNode*root)
{

 vector<lli>pre;
 vector<lli>in;
 vector<lli>post;

 stack<pair<TreeNode*,int>> st;
 st.push({root,1});


while(!st.empty())
{
	auto it=st.top();

	if(it->second==1)
	{
		pre.push_back(it->first->val);
		it->second++;
		if(it-first->left)
			st.push({it->first->left,1});
	}

   else if(it->second==2)
   {
   	in.push_back(it->first->val);
   	it->second++;
   	if(it->first->right)
   		st.push({it->first->right,1});
   }

   else
   {
   	post.push_back(it->first->val);
   	st.pop();
   }

}
cout<<"Preorder Traversal ";
for(i=0;i<pre.size();i++)
	cout<<pre[i]<<" ";

cout<<"\n";

cout<<"Inorder Traversal ";

for(i=0;i<in.size();i++)
	cout<<in[i]<<" ";

cout<<"\n";
cout<<"Postorder Traversal ";

for(i=0;i<post.size();i++)
	cout<<post[i]<<" ";






}
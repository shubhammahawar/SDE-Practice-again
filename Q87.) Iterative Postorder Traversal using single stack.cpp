#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Iterative PostOrder Traversal using Single Stack-

T.C= O(N)
S.C= O(N)

Analysis- We are using single stack
          and as postorder says left->right->root

          We are keep moving left and pushing it into stack
          and once left is over moving to right
          and once right also over thats our element poping it from
          stack and pushing into list.

*/


vector<int> preinpos(TreeNode*root)
{

vector<lli>ans;
stack<TreeNode*>st;


if(root==NULL)
return ans;

TreeNode*cur=root;
TreeNode*temp;

while(cur!=NULL ||!st1.empty())
{

   if(cur!=NULL)
   {
   	st.push(cur);
   	cur=cur->left;
   }

  else
  {
  	temp=st.top()->right;

    if(temp==NULL)
    {
      temp=st.top();
      st.pop();
      ans.push_back(temp->val);

     while(!st.empty() && temp==st.top()->right ) // when left and right both over
                                                 //  and this temp is right of stack top
     {
     	temp=st.top();
     	st.pop();
     	ans.push_back(temp->val);
     }

    }

   else
   {
   	cur=temp;
   }



  }

}

return ans;
}
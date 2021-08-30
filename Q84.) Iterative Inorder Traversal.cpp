#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Print the Iterative Inorder Traversal of a Tree 
T.C = O(N)
S.C = O(N)

Input -        5
            6     11
          4     13   16

Output -4 6 5 13 11 16

Analysis - We will use the Stack here
           and we will store in a same manner like we were
           doing in the stack call


*/

class Solution {
  
    
public:
    vector<int> preorderTraversal(TreeNode* root){
        
        vector<int>arr;
   
      if(root==NULL)
      	return arr;
      
        TreeNode*r=root;
        stack<TreeNode*>st;


       while(true)
       {

        if(r!=NULL)
        {
        	st.push(r);
        	r=r->left;
        }

        else
        {
        	if(st.empty()==true)
        		break;
        	r=st.top();
        	arr.push_back(r->val);
        	r=r->right;
            

        }


       }

       return arr;
   }
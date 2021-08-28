 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Print the preorder Traversal of a Tree Iteratively

T.C = O(N)
S.C = O(N)

Input -        5
            6     11
          4     13   16

Output -5 6 4 11 13 16

Analysis - We will use the Stack here
           and instead of storing Left first, we will store
           right first cz of the stack property LIFO
           and traverse until stack is empty 


*/



class Solution {
  
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>arr;
        
        if(root==NULL)
            return arr;
        stack<TreeNode*>st;
        st.push(root);
        
        
        while(!st.empty())
        {
            int p=st.size();
            
                TreeNode* r=st.top();
                st.pop();
                arr.push_back(r->val);
                
                if(r->right)
                    st.push(r->right);
                
                if(r->left)
                    st.push(r->left);   
                
            //    st.pop();
            
        }

        return arr;
        
    }
};













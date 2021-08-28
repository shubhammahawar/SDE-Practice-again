 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* Level order Traversal of a Binary Tree

T.C = O(N)
S.C = O(N)

Input -        5
            6     11
          4     13   16

Output - 5 6 11 4 13 16

Analysis - We will use the Queue
           and for every level we will store if queue's
           front of left and right is there
           and store in 1d vector
           and pop out the queue front element
           We will run this until Queue is not completly empty



*/

class Solution {
public:
    
        
    
        queue<TreeNode*>q;
        vector<vector<int>>arr;
        if(!root)
            return arr;
        
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>v;
            
            int p=q.size();
           
            
            for(int i=0;i<p;i++)
            {
                 TreeNode*r=q.front();
                if(r->left)
                    q.push(r->left);
                
                if(r->right)
                    q.push(r->right);
                
                v.push_back(q.front()->val);
                q.pop();
            }
            
            arr.push_back(v);
        }
        
        return arr;   
        
        
        
        
    }
};

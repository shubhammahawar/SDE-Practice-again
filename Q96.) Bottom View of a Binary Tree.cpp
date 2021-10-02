#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* Bottom view of a Binary Tree

T.C = O(N)
S.C = O(N)

Input -             1
                 2      6
              3
                 4  7       8
                    5   


  Out put - 3 4 5 6 8
  
  Analysis -  We will use one pair of queue that will store node
              and vertical line cordinate
              when we move left line-1 and when we move right line+1
              and in map the value of every line will be updated
              so its just like for every line store the last node value
              in map


*/


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>v;
        
        if(root==NULL)
        return v;
        
        queue<pair<Node*,int>>qu;
        map<int,int>mp;
        qu.push({root,0});
        
        while(!qu.empty())
        {
            auto temp=qu.front();
            qu.pop();
            Node*p=temp.first;
            int q=temp.second;
            
            mp[q]=p->data;
            
            if(p->left)
            qu.push({p->left,q-1});
            
            if(p->right)
            qu.push({p->right,q+1});
            
        }
        
        for(auto it:mp)
        v.push_back(it.second);
        
        return v;
    }
};
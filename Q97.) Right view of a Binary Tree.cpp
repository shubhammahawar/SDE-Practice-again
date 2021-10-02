#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

class Solution {
public:

//1st solution using Iterative Level Order Trversal
/*
	T.C = O(N)
	S.C = O(N)


Analysis - We will use the Level order Trvaersal and 
           for every level , the last node is the right vire of 
           a binary tree 

*/	

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>v;
        if(root==NULL)
            return v;
        
        queue<pair<TreeNode*,int>>qu;
        map<int,int>mp;
        qu.push({root,0});
        
        while(!qu.empty())
        {
            auto temp=qu.front();
            qu.pop();
            TreeNode*p=temp.first;
            int q=temp.second;
            
           mp[q]=p->val;
            
            if(p->left)
                qu.push({p->left,q+1});
            
            if(p->right)
                qu.push({p->right,q+1});
        }
        
       for(auto it:mp)
           v.push_back(it.second);
        
        return v;
    }



// 2bd solution using Recursive solution

/*
    T.C = O(N)
    S.C = O(H)

  Analysis - we will use recursive inverse of preorder  Traversal
             i.e Root->Right->Left
             and we will compare if datastructure size is equal 
             to level no then its the first element of a particular
             level i.e right side view

    */


void recursive(TreeNode*root,int lv,vector<int>&v)
    {
        if(root==NULL)
            return ;
        
        if(v.size()==lv)
            v.push_back(root->val);
        
        recursive(root->right,lv+1,v);
        recursive(root->left,lv+1,v);
            
    }


vector<int> rightSideView(TreeNode* root) {
    
         vector<int>v;
       
        recursive(root,0,v);
        
        return v;
    }

};

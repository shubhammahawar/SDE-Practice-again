#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Binary Tree Zigzag Level Order Traversal

T.C = O(N)
S.C = O(N)

Example -

Input        3
          6     11
            5       17
          18      10

 Output - 3 11 6 5 17 10 18
 
Analysis - We will take one variable through which we will traverse
           if left=1 we will store from left to right
           if left=0 we will store from right to left

           and store the element of every level into one queue

            */


 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


 		queue<TreeNode*>q;
     vector<vector<int>>ans;
        
        if(root==NULL)
            return ans;
 	q.push(root);

 	int left=1;


 	while(!q.empty())
 	{
 		int sz=q.size();
 		vector<int>arr(sz,0);

 		for(int i=0;i<sz;i++)
 		{
 			TreeNode* temp=q.front();
 			q.pop();

 			int ind=left?i:sz-i-1;

 			arr[ind]=temp->val;

 			if(temp->left)
 				q.push(temp->left);

 			if(temp->right)
 				q.push(temp->right);

 		}
 		left=!left;
        ans.push_back(arr);
 	}

 	return ans;
    }
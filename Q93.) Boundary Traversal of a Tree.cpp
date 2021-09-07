#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Find the Boundary Traversal of binary tree

1. - Left Boundary Node(Top to Bottom order)
2. - Leaf Nodes
3. - Right Boundary Nodes(Bottom to top order)

T.C = O(N)
S.C = O(N)

Analysis - First we will store the Left Boundary Nodes i.e(Move left->left and 
            if left is not present move right)
           
           Then we will store the Leaf node(Using Inorder Traversal)
          
           Then Right Boundary Nodes i.e(Move right->right and 
            if right is not present move left)


*/




class Solution {
    
   bool isleaf(Node*root)
{
	return !root->left && !root->right;
}
    
   void addLeftNode(Node*root,vector<int>&ans)
{
	Node*cur=root->left;

	while(cur)
	{
		if(!isleaf(cur))
			ans.push_back(cur->data);

		if(cur->left)
			cur=cur->left;

		else
			cur=cur->right;
	}
}


void addLeafNode(Node*root,vector<int>&ans)
{
	if(isleaf(root))
	{
		ans.push_back(root->data);
		return ;
	}

    if(root->left)
	addLeafNode(root->left,ans);
	
	if(root->right)
	addLeafNode(root->right,ans);
}


void addRightNode(Node*root,vector<int>&ans)
{

	Node*cur=root->right;
	vector<int>temp;

	while(cur)
	{
		if(!isleaf(cur))
		{
			temp.push_back(cur->data);
		}

		if(cur->right)
			cur=cur->right;

       else
       	cur=cur->left;
	}
	
	for(int i=temp.size()-1;i>=0;i--)
	ans.push_back(temp[i]);
	 
}

    
public:
   vector <int> printBoundary(Node *root)
    {

    	vector<int>ans;

    	if(root==NULL)
    		return ans;

    	if(!isleaf(root))
    		ans.push_back(root->data);

    	addLeftNode(root,ans);
    	addLeafNode(root,ans);
    	addRightNode(root,ans);

    	return ans;

    }
};


#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*
Top View of a Binary Tree

T.C = O(N)
S.C = O(N)

EG - input             1
                    2     3
                       5 6   7


     Output- 2 1 3 7


     Analysis-  We will go by cordinate wise i.e while traverse 
                left i.e co-1 and traverse right co+1
                and for every cordinate the first element will be stored
                in map and at last we traverse map values to vector.


*/



class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {

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

    		if(mp.find(q)==mp.end())
    			mp[q]=p->data;

    		if(p->left!=NULL)
    			qu.push({p->left,q-1});

    		if(p->right!=NULL)
    			qu.push({p->right,q+1});
    	}

    	for(auto it:mp)
    		v.push_back(it.second);
    
        return v;
        }


    }
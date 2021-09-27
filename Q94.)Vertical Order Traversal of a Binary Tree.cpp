#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*

Vertical Order Traversal of a Binary Tree

T.C= O(NLOGN) // N for traversing , LOGN for multiset
S.C= O(N)

Input -                2
                   3       5
                7      8 9     11

                8 & 9 are in same position

 Output - 7 3 2 8 9 5 11

 Analysis - Here we will use the concept of (vertex,level)
            if we move left and down (vertex-1,level+1)
            if we move right and down(vertex+1,level+1)

            and use a queue that will store Node,vertex,level
            and a map that will store vertex -> level->(all node of that particular level)


           Eg- 0->{0,2}
               0->{1,8}  multiset cz for 1 levels many element can be present
               0->{1,9} 
             
             and traverse all the nodes by level order traversal


*/


 vector<vector<int>> verticalTraversal(TreeNode* root) 
 {
  
  
  map<int,map<int,multiset<int>>>mp;
  queue<pair<TreeNode*,pair<int,int>>>qu;
  vector<vector<int>>ans;


qu.push({root,{0,0}});


while(!qu.empty())
{
	auto p=qu.front();
   qu.pop();

   TreeNode*temp=p.first;
   int a=p.second.first;
   int b=p.second.second;

   mp[a][b].insert(temp->val);

   if(temp->left)
   	qu.push({temp->left,{a-1,b+1}});

   if(temp->right)
   	qu.push({temp->right,{a+1,b+1}});

}


for(auto st:mp)
{
	vector<int>ilu;

	for(auto ed:st.second)
		ilu.insert(ilu.end(),ed.second.begin(),ed.second.end());

 ans.push_back(ilu);
}


return ans;
  }
        
      
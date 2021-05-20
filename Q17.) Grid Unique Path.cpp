#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*
A robot is located at the top-left corner of a m x n grid .

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3


Here we have used 3 approach

1. Recursive Approach  
       T.C = O(exponential ) S.C = (exponential) cz using stack based recursion

2. Dynamic Programing 
       T.C = O(N*M) S.C = O(N*M)

3. Optimise Approach
        T.C = O(M-1) OR O(N-1)
        S.C = O(1)


        */

// Method 1- Recursive 

lli RecursiveSol(lli i,lli j,lli m,lli n)
{
    if(i==m-1 && j==n-1)
    	return 1;

    if(i>=m || j>=n)
    	return 0;
    else
    {
    	lli dn=RecursiveSol(i+1,j,m,n);
    	lli rt=RecursiveSol(i,j+1,m,n);

    	return (dn+rt);
    }
}

//Method 2- Dynamic Programing
lli DpSol(lli i,lli j,lli m,lli n,vector<vector<lli>>&dp)
{
	if(i==m-1 && j==n-1)
		return 1;

	if(i>=m || j>=n)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

else
	return dp[i][j]=DpSol(i+1,j,m,n,dp) +DpSol(i,j+1,m,n,dp);
}

// Method 3 - Optimised Approach
lli OptimiseApproach(lli m,lli n)
{
	lli totalcom=m+n-2;
	lli k=m-1,res=1,i;
 
  for(i=0;i<k;i++)
  {
  	res*=(totalcom-i);
  	res/=(i+1);
  }

return res;
}






	int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
     
     lli m,n;
     cin>>m>>n;

     lli uniquepath=0;


     uniquepath=RecursiveSol(0,0,m,n);

     cout<<"Using Recursive solution No of unique path to travel from (0,0) to (m-1,n-1) is "<<uniquepath<<"\n";
     cout<<"\n";

      vector<vector<lli>>dp(m,vector<lli>(n,-1));
     lli uniquepath1=DpSol(0,0,m,n,dp);

     cout<<"Using Dp solution No of unique path to travel from (0,0) to (m-1,n-1) is "<<uniquepath1<<"\n";
     cout<<"\n";


   lli uniquepath2=OptimiseApproach(m,n);
   cout<<"Using OptimiseApproach No of unique path to travel from (0,0) to (m-1,n-1) is "<<uniquepath2<<"\n";



}
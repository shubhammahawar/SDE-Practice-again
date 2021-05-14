#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



/* Q7) Given an m x n matrix. If an element is 0, set its entire row and column to 0. 
         Do it in-place.

         T.C.= 2*O(N*M)
         S.C.=O(1)

         */

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


    vector<vector<lli>>mat;
    lli m,n,i,j,val,col0=1;

    

    cin>>m>>n;

    for(i=0;i<m;i++)
    {   vector<lli>temp;
    	for(j=0;j<n;j++)
    	{
    		cin>>val;
    		temp.push_back(val);
    	}
    	mat.push_back(temp);

    }

    
    for(i=0;i<m;i++)
    {
    	if(mat[i][0]==0)
    		col0=0;
    	for(j=1;j<n;j++)
    	{
    		if(mat[i][j]==0)
    		{
    			mat[0][j]=0;
    			mat[i][0]=0;
    		}
    	}
    }

  for(i=m-1;i>=0;i--)
  {
  	for(j=n-1;j>=1;j--)
  	{
  		if(mat[i][0]==0 || mat[0][j]==0)
  			mat[i][j]=0;
  	}

  	if(col0==0)
  		mat[i][0]=0;
  }






    cout<<"Matrix after setting rows and columns to 0  of a particular position having 0 value"<<"\n";


    for(i=0;i<m;i++)
    {  
    	for(j=0;j<n;j++)
    	{
    		cout<<mat[i][j]<<" ";
    	}
    	cout<<"\n";

    }





}
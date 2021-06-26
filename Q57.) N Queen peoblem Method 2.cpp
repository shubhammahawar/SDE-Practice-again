#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*

N- QUEEN PROBLEM- Place N- queens in a N*N chess board

T.C = O(N) 

S.C = O(N) 

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Analysis : Here we used three diferent Array's just to check 
           directly find if already queen is present at any of
           the same row or upper diagonal or lower diagonal
           and recursively find out the combinations and storing it.

*/           

void solvemethod2(lli col,lli n,vector<lli>&left,vector<lli>&upperdiagonal,
	              vector<lli>&lowerdiagonal,vector<string>&temp,
	              vector<vector<string>>&ans)
{
    if(col==n)
    {
    	ans.push_back(temp);
    	return;
    }

	for(lli row=0;row<n;row++)
	{
		if(left[row]==0 && upperdiagonal[n-1+col-row]==0
			&& lowerdiagonal[row+col]==0)
		{
           left[row]=1;
           upperdiagonal[n-1+col-row]=1;
           lowerdiagonal[row+col]=1;
           temp[row][col]='Q';

           solvemethod2(col+1,n,left,upperdiagonal,lowerdiagonal,temp,ans);

           left[row]=0;
           upperdiagonal[n-1+col-row]=0;
           lowerdiagonal[row+col]=0;
           temp[row][col]='.';
		}
	}
}

void Nqueenproblemapproach2(lli n)
{
	vector<vector<string>>ans;
	vector<string>temp(n);

	vector<lli>left(n,0);
	vector<lli>upperdiagonal(2*n-1,0);
	vector<lli>lowerdiagonal(2*n-1,0);

	lli i,j;

	string s(n,'.');
	for(lli i=0;i<n;i++)
	{
		temp[i]=s;
	}

  solvemethod2(0,n,left,upperdiagonal,lowerdiagonal,
  	temp,ans);

  cout<<"The possible combination where we can place N*N queens without attacking each other are\n";

  for(lli i=0;i<ans.size();i++)
  {
  	for(lli j=0;j<ans[i].size();j++)
  		cout<<ans[i][j]<<"\n";

  	cout<<"\n";
  }

}




int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n;
	cin>>n;

	Nqueenproblemapproach2(n);
}
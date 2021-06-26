#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* 

N- QUEEN PROBLEM- Place N- queens in a N*N chess board

T.C = O(N)*(O(N)+O(N)+O(N)) 

these 3 O(N) - to check the Queen place at lower diagonal,upper diagonal  and same
row

S.C = O(N) 

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Analysis : Here we will recursively find out all the possB
ible
           combination and check every combination's
           upper diagonal,lowerdiagonal and left row 
           if there is already a Queen 'Q' at that positions
           we will return out as Queen will attack each other.
           otherwise store thsi combination as a one result.


*/



bool isSafe(lli row,lli col,lli n,vector<string>&temp)
{
	lli rcp=row;
	lli ccp=col;

 while(row>=0 && col>=0)
 {
 	if(temp[row][col]=='Q')
 		return false;
 	row--;
 	col--;
 }

row=rcp;
col=ccp;
 while(col>=0)
 {
 	if(temp[row][col]=='Q')
 		return false;

 	col--;
 }

 row=rcp;
 col=ccp;

while(row<n && col>=0)
{
	if(temp[row][col]=='Q')
		return false;

	row++;
	col--;
}


return true;

}


void solve(lli col,lli n,vector<string>&temp,vector<vector<string>>&ans)
{

if(col==n)
{
	ans.push_back(temp);
	return;
}
	for(lli row=0;row<n;row++)
	{
		if(isSafe(row,col,n,temp))
		{
			temp[row][col]='Q';
			solve(col+1,n,temp,ans);
			temp[row][col]='.';
		}
	}
}


void Nqueenproblem(lli n)
{
	vector<vector<string>>ans;
	vector<string>temp(n);
	lli i,j;

	string s(n,'.');
	for(lli i=0;i<n;i++)
	{
		temp[i]=s;
	}

  solve(0,n,temp,ans);

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

	Nqueenproblem(n);
}
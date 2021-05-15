#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*.Q8) Return first n rows of Pascal's traingle

        T.C=O(N^2)
        S.C=O(N^2)

            1
          1   1
        1   2    1
      1   3    3   1
    1   4    6   4    1 

 */   

void PascalTraingle(lli n)
{
	vector<vector<lli>>v(n);
	lli i,j;


	for(i=0;i<n;i++)
	{
		v[i].resize(i+1); // means every row has no of elements 
		                 // equal to row number
		v[i][0]=v[i][i]=1; // 1st and last column always 1


		for(j=1;j<i;j++)
			v[i][j]=v[i-1][j-1]+v[i-1][j];
	}

cout<<"Pascal Traingle for given"<<n<<"rows"<<"\n";

for(i=0;i<v.size();i++)
{
	for(j=0;j<v[i].size();j++)
	cout<<v[i][j]<<" ";

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

  PascalTraingle(n);


}
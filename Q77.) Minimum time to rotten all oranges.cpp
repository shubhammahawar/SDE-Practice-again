 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


T.C = O(N*N)*4
S.C = O(N*N)

Example-     Output - 2 mins
0 1 0 1
2 1 1 0
1 0 0 2


Analysis -- We will use the concept of BFS so queue will be used
            First we will caluclate all fresh and rotten oranges
            and push all the rotten oranges into queue.

            Since one rotten orange can rot in 4 direction
            so took a array for it.

            Now at every time whatever be the queue size
            we will traverse all the cordinates and if it rot any other
            fresh orange we will store in queue again.

*/



void Rottenoranges(vector<vector<lli>>&arr)
{

	lli r=arr.size();
	lli c=arr[0].size();

	lli tot=0,cnt=0,time=0,i,j;

   queue<pair<lli,lli>>qu;

   for(i=0;i<r;i++)
   {
   	for(j=0;j<c;j++)
   	{
   		if(arr[i][j]!=0)
   			tot++;

   		if(arr[i][j]==2)
   			qu.push({i,j});
   	}
   }

   lli row[]={0,0,1,-1};
   lli col[]={1,-1,0,0};


 while(!qu.empty())
 {
 	lli k=qu.size();
 	cnt+=k;   // this step will tell whether all the rotten and 
 	          // and nonrotten oranges are taken into queue or not

  while(k--)
  {
  	lli x=qu.front().first;
  	lli y=qu.front().second;
  	qu.pop();

  	for(i=0;i<4;i++)
  	{
       lli dx=x+row[i];
       lli dy=y+col[i];

      if(dx<0 || dy<0 || dx>=r || dy>=c || arr[dx][dy]!=1)
      	continue;

      arr[dx][dy]=2;
      qu.push({dx,dy});
  	}


  }

   if(!qu.empty())
   	time++;

 }
lli ans= tot==cnt?time:-1;


cout<<"Minimum amount of time taken to rotten all fresh oranges is\n";
cout<<ans<<"\n";

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


   vector<vector<lli>>arr;

	lli r,c,i,j;
	cin>>r>>c;

	for(i=0;i<r;i++)
	{
		vector<lli>temp;
		for(j=0;j<c;j++)
		{
		lli val;
		cin>>val;
		temp.push_back(val);
	    }
	    arr.push_back(temp);
    }

    Rottenoranges(arr);
}
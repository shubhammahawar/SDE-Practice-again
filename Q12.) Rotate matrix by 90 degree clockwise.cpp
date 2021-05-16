#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise) (inplace)


T.C - O(N^2)
S.C - O(1)

Eg- I/p - 8 1 3 4    O/p - 7 4 3 8
          3 7 5 9          2 2 7 1
          4 2 1 7          3 1 5 3
          7 2 3 6          6 7 9 4

   Analysis -- First Transpose the matrix
               Second rotate every row of matrix.


               */       



void swap(lli *a,lli *b)
{
	lli temp=*a;
	*a=*b;
	*b=temp;
}

void RotateMatrix(vector<vector<lli>>&arr,lli n)
{
	lli i,j;

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			lli temp=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=temp;
		}
	}

  for(i=0;i<n;i++)
  {
  	for(j=0;j<n/2;j++)
  	{
  		swap(&arr[i][j],&arr[i][n-j-1]);
  	}
  }


cout<<"matrix after rotating it by 90 degree"<<"\n";
for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";

}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vector<vector<lli>>arr;

	lli i,n,j;

	cin>>n;

	for(i=0;i<n;i++)
	{
		vector<lli>v;
		for(j=0;j<n;j++)
		{ lli val;
			cin>>val;
			v.push_back(val);
		}
		arr.push_back(v);
	}


  RotateMatrix(arr,n);
}


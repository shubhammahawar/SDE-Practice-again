#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


void swap(lli *a,lli*b)
{
	lli temp=*a;
	*a=*b;
	*b=temp;
}

void sortval(vector<lli>&arr,lli n)
{
	
   lli low=0,mid=0,high=n-1;

   while(mid<=high)
   {
   	 if(arr[mid]==0)
   	 {
   	 	swap(&arr[low],&arr[mid]);
   	 	low++;
   	 	mid++;
   	 }

    else if(arr[mid]==1)
    	mid++;

    else
    {
    	swap(&arr[mid],&arr[high]);
    	high--;
    }

   }
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

vector<lli>arr;

lli val,n,i;
cin>>n;

for(i=0;i<n;i++)


{
	cin>>val;
	arr.push_back(val);
}

cout<<"array before sorting"<<"\n";

for(i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
cout<<"\n";
sortval(arr,n);

cout<<"array after sorting"<<"\n";
for(i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}

}
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


// Q- MERGE TWO SORTED ARRAYS in their respective length

// Method 1.
// T.C.=O(M*N) Linear traversing takes M and Ordering takes N
// S.C=O(1)

/* Method 2
T.C=O(N*LOGN)  // LOGN for gap and N for linearly iterating on every gap
S.C=O(1)
*/

void swap(lli *a,lli *b)
{
 // cout<<"swaping"<<endl;
// cout<<*a<<" "<<*b<<endl;
	lli temp=*a;
	*a=*b;
	*b=temp;
  // cout<<*a<<" "<<*b<<endl;
}

// Method 1------------------------
 void mergesortedarray(vector<lli>&v1,vector<lli>&v2,
	lli m,lli n)
{
   lli i=0,j=0,p,q;

   while(i<m)
   {
 //  	cout<<"i value"<<i<<" ";
   	  if(v1[i]>v2[j])
   	  {
   	  	swap(&v1[i],&v2[j]);
   	  

     
   	  for(lli p=1;p<n;p++)
   	  {
          lli key=v2[p];
          q=p-1;

          while(q>=0 && v2[q]>key)
          {
          	v2[q+1]=v2[q];
          	q=q-1;
          }
          v2[q+1]=key;

   	  }
     }
     i++;



}


} 

// Method 2-------------
void Gapmethod(vector<lli>&v1,vector<lli>&v2,lli m,lli n)
{

  lli gap=(m+n)/2 +(m+n)%2;
  lli i,j;


while(gap>=1)
{
  for(i=0;(i+gap)<m;i++)
    if(v1[i]>v1[i+gap])
      swap(&v1[i],&v1[i+gap]);


for(j=gap>m?gap-m:0;i<m && j<n;i++,j++)
    if(v1[i]>v2[j])
      swap(&v1[i],&v2[j]);

      if(j<n)
      {
    for(j=0;j+gap<n;j++)
      if(v2[j]>v2[j+gap])
        swap(&v2[j],&v2[j+gap]);
    }


       //1 cout<<"gap"<<gap<<endl;
       if((gap/2)<1)
        break;
      gap=(gap/2)+(gap%2);
     
        
}



}








int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


vector<lli>v1,v2;
lli m,n,val,i,j;

cin>>m>>n;

for(i=0;i<m;i++)
{
   cin>>val;
   v1.push_back(val);
}

for(i=0;i<n;i++)
{
   cin>>val;
   v2.push_back(val);
}

cout<<"Both the sorted  array before merging\n";

for(i=0;i<m;i++)
{
  cout<<v1[i]<<" ";
}
cout<<"\n";

for(i=0;i<n;i++)
{
  cout<<v2[i]<<" ";
}
cout<<"\n";


//1.method using inserion sort

// mergesortedarray(v1,v2,m,n);


// 2.METHOD USING GAP METHOD

Gapmethod(v1,v2,m,n);





cout<<"Both the sorted  array  after merging\n";


for(i=0;i<m;i++)
{
  cout<<v1[i]<<" ";
}
cout<<"\n";

for(i=0;i<n;i++)
{
  cout<<v2[i]<<" ";
}
cout<<"\n";



}
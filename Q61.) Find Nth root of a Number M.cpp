#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/* Find Nth root of a No. M

T.C = N*Log(M*10)^d 

since our search area is M but we are not going like 1.2.3..M
we are going like 1.1 1.2 1.3....1.10 2.1..2.10....27.10

so for M numbers for 1 decimal places-M*10

but what if  5 decimal places..10 decimal places...
for find the answer trimmed of d decimal places - 

so our search space is (M*10)^d

and we are running loop for multiply till N


Analysis -- We are using Binary Search  here,
            Binary Search is use anywhere having monotonic
            increasing or decreasing function.

            Like-
            1 x 1 x 1 = 1
            2 x 2 x 2 = 8
            3 x 3 x 3 = 27
            .
            .
            monotonically increasing

           so our search space is 1......M
           
           we will find  mid =high+low/2
           then if mid*mid*mid<m then our low = mid
           else high=mid

           we will continue this until 10^-6 that is high-low<10^-6

           and return the ans  


*/



double multiply(double mid,lli n)
{
	lli res=1;
	for(lli i=0;i<n;i++)
		res=mid*res;

	return res;
}

void NthrootofM(lli n,lli m)
{
  double low=1;
  double high=m;
  double dec=1e-6,mid;

  while((high-low)>dec)
  {
  	mid=(high+low)/2.0;

  	if(multiply(mid,n)<m)
  		low=mid;
  	else
  		high=mid;
  }
//return mid;

cout<<n<<"th root of a No "<<m <<" is\n";
cout<<mid<<"\n";
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,m;
	cin>>n>>m;

	NthrootofM(n,m);
}

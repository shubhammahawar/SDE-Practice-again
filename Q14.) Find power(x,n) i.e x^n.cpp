#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

  T.C = O(Logn)
  S.C= O(1);

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25 


Analysis - if n is even 
              x=x*x and n= n/2;

              else if n is odd
              ans=ans*x and n= n-1



              */






void powerxn(double x,double n)
{
   double ans=1.0,xe=x;
   lli nc=n;
   if(nc<0)
   	nc=-1*nc;


   while(nc>=1)
   {
   	if(nc%2==0)
   	{
   		x=x*x;
   		nc=nc/2;
   	}
   	else
   	{
   		ans=ans*x;
   		nc=nc-1;
   	}
   }


   if(n<0)
   	ans=(double)(1.0)/(double)(ans);
   
cout<<" power of "<<xe <<" to "<<n<<" (x^n) is"<<ans<<"\n";
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	double x,n;
	cin>>x>>n;

	powerxn(x,n);
}
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* 
Kth Permutation Sequence

T.C= O(n)*O(n) = O(n^2)
O(n) for finding out n elements and
O(n) for erasing everytime on element that will take O(n)

S.C= O(n) to store n elements

Input n= 4 k=17

Output - 3412

Analysis - Instead of doing recursion and find out all sequence
           We will be finding the direct Kth sequence one by one

           

*/

void KthpermutationSequence(lli n,lli k)
{
	lli fact=1;
    vector<lli>nums;
    lli k1=k;

	for(int i=1;i<n;i++)
	{
		fact=fact*i;
		nums.push_back(i);
	}
	nums.push_back(n);
    string str=" ";
    k=k-1;

    while(true)
    {
    	str+=to_string(nums[k/fact]);
    	nums.erase(nums.begin()+k/fact);

    	if(nums.size()==0)
    		break;
    
        k=k%fact;
        fact=fact/nums.size();

    }
cout<<k1 <<"th permutation of "<<n<<" numbers is\n";
cout<<str;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	lli n,k;
	cin>>n>>k;


	KthpermutationSequence(n,k);

}
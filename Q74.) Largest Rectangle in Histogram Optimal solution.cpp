#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/* Optimal approach to get maximum size rectangle from a histogram

T.C= O(N)+O(N)(stack traverse time)
S.C= O(N) (for stack only)

Example -
 Input - 6
3 1 5 6 2 3

Output - 10

Analysis - Maximum size rectangle formed is by index 2 &3
           i.e height 5 and width=2 (5*2=10)

           We will use only stack here
           If the element of height array is greater than
           stack array put it into stack 

           but if its smaller it means current stack top element's
           right smaller element is height[i] and left smaller element
           is before the top element.

           but run the loop to i==n cz for element which
           are left they will caluclated based on last index.
           





*/



 int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size(),i;
        stack<int>st;


         int maxe=0;
        for(i=0;i<=n;i++)
        {
            while( !st.empty() && ((i==n) ||  (!st.empty() && heights[i]<=heights[st.top()]) ) )
            {
                int pos=st.top();
                st.pop();
                if(st.empty())
                {
                    if( (i*heights[pos])>=maxe)
                        maxe=i*heights[pos];
                    
         //           cout<<"i "<<i<<" "<<maxe<<"\n";
                }
                else
                {
                    if( ((i-st.top()-1)*heights[pos])>=maxe) 
                    maxe= (i-st.top()-1)*heights[pos];
                    
          //          cout<<"i "<<i<<" "<<maxe<<"\n";
                }
            }
          //  if(!st.empty() &&heights[i]>st.top())
                st.push(i);
        }
        
        
        
        
        return maxe;
        
               
    }
        


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

int n;
cin>>n;

vector<int>arr;

for(int i=0;i<n;i++)
{
	int val;
	cin>>val;
	arr.push_back(val);
}

int ans=largestRectangleArea(arr);
cout<<"Maximum size rectangle that can be made from a histogram is "<<ans<<"\n"; 

}
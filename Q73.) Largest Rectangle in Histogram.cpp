#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*  Given an array of integers heights 
representing the histogram's bar height where 
the width of each bar is 1, return the area of
 the largest rectangle in the histogram.


T.C = O(N)+O(N)+O(N) -~ O(N)
S.C = O(3N)

Example -
 Input - 6
3 1 5 6 2 3

Output - 10

Analysis - Maximum size rectangle formed is by index 2 &3
           i.e height 5 and width=2 (5*2=10)

           We will use a concept of Next samller element in stack concept
           
           First for every correspond element their left
           smallest element ans store in left array
           then for every correspond element their right
           smallest element and store in right array.
           
           and then ans will be 
           (right smallest index-left smallestindex+1)*height[i]








 */




 int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size(),i;
        stack<int>st;
        
       vector<int>lf(n,0);
        vector<int>rt(n,0);
        
        for(i=0;i<n;i++)
        {
            
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                
                if(!st.empty())
                {
                    lf[i]=st.top()+1;
                   
                }
                else
                {
                     lf[i]=0;
                   
                }
             st.push(i);
            
        }
       
        while(!st.empty())
            st.pop();
        
        for(i=n-1;i>=0;i--)
        {
            
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                
                if(!st.empty())
                {
                    rt[i]=st.top()-1;
                   
                }
                else
                {
                     rt[i]=n-1;
                   
                }
             st.push(i);
            
        }
        
     

        int maxe=0;
        for(i=0;i<n;i++)
        {
            if( ( (rt[i]-lf[i]+1) *heights[i])>=maxe)
                maxe=(rt[i]-lf[i]+1)*heights[i];
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
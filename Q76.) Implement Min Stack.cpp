 #include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


/*
Implement a Min Stack with all operation in constant time.

S.C= O(2*N)
T.C= O(1) for all operation

Analysis - : We will use the concept of storing pair wise elements
             in stack i.e <element,minelement>


*/


class MinStack {
    
    stack<pair<long,long>>st;
    int mine;
public:
    /** initialize your data structure here. */
    
    MinStack()
    {
        mine=INT_MAX;
    }
  
    
    void push(int x) {
        
      if(st.empty())
      {
          st.push({x,x});
      }
        else
        {
            if(x<st.top().second)
                mine=x;
            else
                mine=st.top().second;
            
         
            st.push({x,mine});
        }
        
        
    }
    
    void pop() {
       st.pop();
    }
    
    int top() {
        return st.top().first;
         }
    
    int getMin() {
        return st.top().second;
        
    }
};
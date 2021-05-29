#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;


void deleteNode(struct ListNode* node) {
    
  
    node->val=node->next->val;
    node->next=node->next->next;


}
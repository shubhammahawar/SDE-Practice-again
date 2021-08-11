#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



//Implementing LRU Cache .......

i.e get(key)
    put(key,value)  in O(1)

 // using Double linked list and unordered_map for this
 // also for Unordered_map for best and average case O(1) T.C   


class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node*next;
        node*prev;
        node(int key1,int value1) // CONSTRUCTOR
        {
            key=key1;
            value=value1;
        }
        
        
    };
    
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>mp;
    
    
    LRUCache(int capacity) {  // constructor of LRU cache
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    
    void addnode(node*newnode)   // TO ADD node
    {
        node*temp=head->next;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
        
        
    }
    
    
    
    void deletenode(node*existnode) // to delete node
    {
        existnode->prev->next=existnode->next;
        existnode->next->prev=existnode->prev;
    }
    
    
    
    
    
    int get(int key) {   // to get the value of a key
        
        if(mp.find(key)!=mp.end())
        {
            node*found=mp[key];
            int data=found->value;
            mp.erase(key);
            deletenode(found);
            addnode(found);
            mp[key]=head->next;
            return data;
        }
       return -1; 
        
    }
    
    void put(int key, int value) // to put the data 
                                 // in DLL and in map.
     {
        
        if(mp.find(key)!=mp.end())
        {
            node*existnode=mp[key];
            mp.erase(key);
            deletenode(existnode);
        }
        
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key]=head->next;
        
        
        
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

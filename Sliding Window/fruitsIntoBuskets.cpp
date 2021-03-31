/*
Problem:
Given an array of characters where each character represents a fruit tree,
you are given two baskets and your goal is to put maximum number of fruits
in each basket. The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree. You will 
pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick 
from a third fruit type.

Solution:
Lot like longest substring with K distinct characters. Only thing to remeber is the value of
K is 2

Time Complexity: O(N+N)
*/

#include<bits/stdc++.h>
using namespace std;

int findMaximumFruits(string s)
{
    int n = s.size();
    int start = 0, max_start = 0, maxWindowLength = 0;
    unordered_map<char, int> mp;
    
    for (int i=0; i<n; i++)
    {
        mp[s[i]]++;
        
        //shrink the size of the window as long as it has 2 distinct characters
        while(mp.size() > 2)
        {
            mp[s[start]]--;
            if(mp[s[start]] == 0)
                mp.erase(s[start]);
            start++;
        }
        
        if(maxWindowLength < i-start+1){
            maxWindowLength = i - start + 1;
            max_start = start;
        }
    }
    //cout<<"Maximum number of fruits: "<<s.substr(max_start, maxWindowLength)<<endl;
    return maxWindowLength;
}

int main()
{
    string s1 = "abbcaabc";
    cout<<findMaximumFruits(s1)<<endl;
    string s2 = "abcbbc";
    cout<<findMaximumFruits(s2)<<endl;    
}




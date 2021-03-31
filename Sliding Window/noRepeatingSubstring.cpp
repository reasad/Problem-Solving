/*
Problem:
Given a string, find the length of the longest substring which has no repeating characters.

Solution:
Same window + hashmap strategy. But this time we need to check that if a character is already
present in the hashmap before increasing the window size. If the character is already present
then we would shring the window size as long as the character is not removed. If the character
is not present in the hashmap we would insert it in the hash map.

Time Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

//this function returns the size of longest substring with distinct characters
int longestSubstring(string s)
{
    int n = s.size();
    int start = 0, max_start = 0, maxWindowLength = 0;
    unordered_map<char, int> mp;
    
    for (int i=0; i<n; i++)
    {
        mp[s[i]]++;
        
        //shrink the size of the window as long as the window has multiple copy of that character 
        while(mp[s[i]] > 1)
        {
            mp[s[start]]--;
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
    string s1 = "aabccbb", s2 = "abbbb", s3 = "abccde";
    
    cout<<longestSubstring(s1)<<endl;
    cout<<longestSubstring(s2)<<endl;
    cout<<longestSubstring(s3)<<endl;    
}




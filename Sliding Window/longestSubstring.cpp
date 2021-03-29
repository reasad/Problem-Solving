/*
Question:
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Solution:
Combination of window method and hashmap.
We will keep increasing the window size as long as the hashmap size is not greater than the K.
If it window has more than K distinct values we will keep shrinking the window size as long 
as the hashmap size is equal to K

Time Complexity: O(N+N) because in inner loop shirinking will happen once for each character
*/
#include<bits/stdc++.h>
using namespace std;

int findLongestSubstring(string s, int k)
{
    int n = s.size();
    int start = 0, max_start = 0, maxWindowLength = 0;
    map<char, int> mp;
    
    for (int i=0; i<n; i++)
    {
        mp[s[i]]++;
        
        if(mp.size() > k)
        {
            //shrink the size of the window as long as it has k distinct characters
            while(mp.size() > k)
            {
                mp[s[start]]--;
                if(mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
        }
        
        if(maxWindowLength < i-start+1){
            maxWindowLength = i - start + 1;
            max_start = start;
        }
    }
    //cout<<"longest substring having "<<k<<" distinct characters is: "<<s.substr(max_start, maxWindowLength)<<endl;
    return maxWindowLength;
}

int main()
{
    string s1 = "araaci";
    cout<<findLongestSubstring(s1, 2)<<endl;
    string s2 = "araaci";
    cout<<findLongestSubstring(s2, 1)<<endl;    
}


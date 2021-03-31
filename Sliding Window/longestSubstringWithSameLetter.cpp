/*
Question:
Given a string with lowercase letters only, if you are allowed to replace no more than
‘k’ letters with any letter, find the length of the longest substring having the same
 letters after replacement.

Solution: (detail explanation)
dynamic window + hashing technique. 
Idea is to keep track of the maximum repeating letter in the window. If other letters exceed the size of
k we need to shrink the size of the window. After that we need to keep update the maxWindow by comparing
with the current window.

Example: string s = "aabccbb" and k = 2
1. a, mp[a] = 1, maxRepeat = max(maxRepeat,1) = 1, other letters(0) <= k(2), window = 1, maxWindow = 1
2. a, mp[a] = 2, maxRepeat = max(maxRepeat,2) = 2, other letters(0) <= k(2), window = 2, maxWindow = 2
3. b, mp[b] = 1, maxRepeat = max(maxRepeat, mp[b]) = 2, other letters(1) <= k(2), window = 3, maxWindow = 3
4. c, mp[c] = 1, maxRepeat = max(maxRepeat, mp[c]) = 2, other letters(2) <= k(2), window = 4, maxWindow = 4
5. c, mp[c] = 2, maxRepeat = max(maxRepeat, mp[c]) = 2, other letters(3) > k(2), window = 4, maxWindow = 4
6. c, mp[b] = 2, maxRepeat = max(maxRepeat, mp[b]) = 2, other letters(3) > k(2), window = 4, maxWindow = 4
7. c, mp[b] = 3, maxRepeat = max(maxRepeat, mp[b]) = 3, other letters(2) <= k(2), window = 5, maxWindow = 5


Time Complexity: O(N)
*/
#include<bits/stdc++.h>
using namespace std;

int findLongestSubstring(string s, int k)
{
    int n = s.size();
    int start = 0, maxWindowLength = 0, maxRepeatLetterCount = 0;
    unordered_map<char, int> mp;
    
    for (int i=0; i<n; i++)
    {
        mp[s[i]]++;
        maxRepeatLetterCount = max(maxRepeatLetterCount, mp[s[i]]);
        
        //other letter except maximum repeating letter in window is greater than k
        if(i - start + 1 - maxRepeatLetterCount > k)
        {
            mp[s[start]]--;
            start++;
        }
        maxWindowLength = max(maxWindowLength, i - start + 1);
    }
    
    return maxWindowLength;
}

int main()
{
    string s1 = "aabccbb";
    cout<<findLongestSubstring(s1, 2)<<endl;
    string s2 = "abbcb";
    cout<<findLongestSubstring(s2, 1)<<endl;    
    string s3 = "abccde";
    cout<<findLongestSubstring(s3, 1)<<endl; 
}


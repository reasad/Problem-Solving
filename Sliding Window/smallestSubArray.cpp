/*
Question:
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous 
subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Solution:
This time we have a variable length window size. First we find the window that sums up atleast 
's'. 
Then we try to shrink the window size from the begining of the window as long as the sum of all
the values of the window is greater the 's'.
This way we can find the next window. While doing this we need to keep track of the minimum window
size. 

Time Complexity: O(N+N) 
*/
#include<bits/stdc++.h>
using namespace std;

int findMinSubArray(int a[], int n, int s)
{
    int start = 0;
    int minLength = INT_MAX, windowSum = 0;
    
    for (int i = 0; i<n; i++)
    {
        windowSum += a[i];
        
        //shrink the window size as long as the window sum is larger than s
        while(windowSum >= s)
        {
            minLength = min(minLength, i - start + 1);
            windowSum -= a[start];
            start++;
        }
    }
    
    return minLength; 
}

int main()
{
    int a[] = {2, 1, 5, 1, 5, 2};
    int n = sizeof(a)/ sizeof(a[0]);
    
    cout<<findMinSubArray(a, n, 7)<<endl;

    int b[] = {2, 1, 5, 2, 8};
    int m = sizeof(a)/ sizeof(a[0]);
    
    cout<<findMinSubArray(b, m, 7)<<endl;

    
}


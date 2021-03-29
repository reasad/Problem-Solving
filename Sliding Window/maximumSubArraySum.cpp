/*
Question:
Given an array of positive numbers and a positive number k,
find the maximum sum of any contiguous subarray of size k.

We will use the same sliding window approach but this time we will
keep track of the maximum sum of the window
*/
#include<bits/stdc++.h>
using namespace std;

int findAverages(int a[], int n, int k)
{
    int start = 0;
    int maxSum = INT_MIN, windowSum = 0;
    
    for (int i = 0; i<n; i++)
    {
        windowSum += a[i];
        if(i >= k-1)
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= a[start++];
        }
    }
    return maxSum; 
}

int main()
{
    int a[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(a)/ sizeof(a[0]);
    
    cout<<findAverages(a, n, 3)<<endl;
    
}

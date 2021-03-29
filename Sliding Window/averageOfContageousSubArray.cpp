/*
Question:
Given an array, find the average of all contiguous
 subarrays of size  K in it.

Solution:
We will use sliding window method. We will have have sliding
window of size K and a sum variable. For finding the next next 
sum we will slide the window by one element and subtract the element
going out of the window

Time complexity: O(n)  
*/
#include<bits/stdc++.h>
using namespace std;

vector<float> findAverages(int a[], int n, int k)
{
    int start = 0;
    float sum = 0.0;
    vector<float> vec;
    for (int i = 0; i<n; i++)
    {
        sum += a[i];
        if(i >= k-1)
        {
            vec.push_back(sum/k);
            sum -= a[start++];
        }
    }
    return vec; 
}

int main()
{
    int a[] = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int n = sizeof(a)/ sizeof(a[0]);
    
    vector<float> vec = findAverages(a, n, 3);
    int m = vec.size();
    for (int i=0; i<m; i++)
        cout<<vec[i]<<" ";
}
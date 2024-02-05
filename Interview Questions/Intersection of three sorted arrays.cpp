/*
Question : 1213. Intersection of Three Sorted Arrays
Date : 04-02-24
Problem Difficulty level : Easy
Related Topics : Array, Sorting, Searching
Problem Statement:
Given 3 integer arrays , find and print the common elements between the three arrays.

Example 1:
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only common elements in A, B and C.

Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> result;
            int i = 0, j = 0, k = 0;

            while (i < n1 && j < n2 && k < n3) {
                if (A[i] == B[j] && A[i] == C[k]) {
                    if(result.empty() || A[i] != result.back()){
                        result.push_back(A[i]);
                    }
                    i++;
                    j++;
                    k++;
                } else {
                    if (A[i] < B[j]) {
                        i++;
                    } else if (B[j] < C[k]) {
                        j++;
                    } else {
                        k++;
                    }
                }
            }

            return result;
        }
};

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
    // Time complexity = O(n1 + n2 +n3)
    // Space complexity = O(n1 + n2 +n3)
}


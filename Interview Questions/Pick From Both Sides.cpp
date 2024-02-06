INTERVIEW BIT

Problem Description:
(Programming ) ( Arrays)
Given an integer array A of size N.

    You have to pick exactly B elements from either left or
    right end of the array A to get the maximum sum.

    Find and return this maximum possible sum.

    NOTE : Suppose B = 4 and array A contains 10 elements then

You can pick the first four elements or can pick the last four elements or can pick 1 from the front and 3 from the back etc.
you need to return the maximum possible sum of elements you can pick.

Solution : 
int Solution::solve(vector<int> &A, int B) {
    int curr_sum = 0;
    int max_sum = INT_MIN;
    int N = A.size();
    
    for(int i=0; i<B; i++)
    {
        curr_sum += A[i];
    }
    
    max_sum = curr_sum;
    int j = N-1;
    int i = B-1;
    
    while(i>=0)
    {
        curr_sum += A[j] - A[i];
        max_sum = max(max_sum, curr_sum)        ;
        i--;
        j--;
    }
    
    return max_sum;
}

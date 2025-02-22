/*
! {Interview Bit} Question 60: Repeat and Missing Number Array
* Problem Difficulty level : Medium
? Related Topics : Array, Math

! Problem Statement:

There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

? Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.

! You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input: [3 1 2 5 3] 

Output: [3, 4] 

A = 3, B = 4
*/


//!  CODE :
// brute force 
/*
 
* BRUTE APPROACH - LNEAR SEARCH -> O(n^2) time and constant space

int[] arr = new int[] (2,3,5,1,6,8,5,4);
int n = arr.length;
int missing = -1, repeated = -1;

for(int i =0;i<n-1; i++)
    for( intj=i+1;j<n; j++)
        if(arrf == arr[il)
        repeated = arr[i);

int actualSum = 0;

for( int num : arr){
    actualSum += num;
    }
    
    int sum = (n*(n+1) /2;

    int diff = actualSum - repeated; 

    int missing sum - diff,

    
    
    */
// better approach - hashing
/*
* BETTER APPROACH - HASHING -> linear space and time
int freq = new int[n+-1); // freq[2], freq[31, freq[4], freq[5], freq[4] =[0,0,1,1,2,1]
for(int i=0; i<n; i++) (
freq[arr )++;


for(int i=1;i=n;i++(
if(freq[i] == 0)
missing =i;
if(freq[i] == 2)
repeated = i;

*/

// optimised approach
/*

* linear time and constant space
 
class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int slow = nums[0], fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while(slow!=fast);

        fast = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    time complextiy = O(n)
    space compelxity = O(1)
}
 */


//  best approach
public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int[] repeatedNumber(final int[] A) {

        long n = A.length;
        
        long Sn =  (n*(n+1))/2;
        long S2n = (n*(n+1)*(2*n+1))/6;
        
        long S = 0;
        long S2 = 0;
        
        for(int num : A){
            S += num;
            S2 += (long)num*num;
        }
        
        long val1 = S - Sn;             // val1 = X - Y
        long val2 = (S2 - S2n)/val1;    // val2 = X + Y
        
        int repeated = (int)(val1 + val2)/2;
        int missing = (int)val2 - repeated;
        
        return new int[] {repeated, missing};
        
        // time complexity = O(N)
        // space complexity = O(1)
    }
}

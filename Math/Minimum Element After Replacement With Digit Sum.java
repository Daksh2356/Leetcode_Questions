/*
! Question: 3330. Minimum Element After Replacement With Digit Sum
* Problem Difficulty level : Easy
? Related Topics : Array, Math
Problem Statement:

! You are given an integer array nums.

! You replace each element in nums with the sum of its digits.

! Return the minimum element in nums after all replacements.

? Example 1:
Input: nums = [10,12,13,14]
Output: 1
* Explanation:
* nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

? Example 2:
Input: nums = [1,2,3,4]
Output: 1
* Explanation:
* nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

? Example 3:
Input: nums = [999,19,199]
Output: 10
* Explanation:
* nums becomes [27, 10, 19] after all replacements, with minimum element 10.
 
? Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 10^4

*/

//!  CODE (1);
class Solution {
    
    //     function to find sum of digits of a number
        public int findSum(int num){
            
            int sum=0;
            
            while(num!=0){
                sum += num%10;
                num /=10;
            }
            
            return sum; 
        }
    
    //     function to find minimum among the newly replaced array
        public int minElement(int[] nums) {
            
            int n = nums.length;
            int x = Integer.MAX_VALUE;  // Integer.MAX_VALUE => INFINITY
            
            for(int i=0; i<n; i++){
                nums[i] = findSum(nums[i]);
                x = Math.min(x, nums[i]);
            }
            
            return x;
        }

            // time = O(N)
            // space = O(1)
        
        
    }

//!  CODE (2);
class Solution {
    public int minElement(int[] nums) {
        int x = Integer.MAX_VALUE;

        for(int num : nums){
            num = digitSum(num);
            x = Math.min(x, num);
        }

        return x;
    }

    public int digitSum(int number){
       String str = String.valueOf(number);
       int sum = 0;
       
       for(Character ch : str.toCharArray()){
            sum += ch - '0'; // char to int conversion!
       }

       return sum;
    }
    // time = O(N)
    // space = O(1)
}
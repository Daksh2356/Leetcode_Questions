/*

Problem statement :
You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of 

the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.

? Example 1:
! Input: nums = [37,100]
! Output: 1

* Explanation: Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
* Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
* Thus, the minimum number of swaps required to rearrange nums is 1.

? Example 2:
! Input: nums = [22,14,33,7]
! Output: 0
* Explanation: Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
* Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
* Thus, the minimum number of swaps required to rearrange nums is 0.

? Example 3:
! Input: nums = [18,43,34,16]
! Output: 2
* Explanation: Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
* Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
* Thus, the minimum number of swaps required to rearrange nums is 2.
 
! Constraints:
? 1 <= nums.length <= 105
? 1 <= nums[i] <= 109
* nums consists of distinct positive integers.

* Note: Please do not copy the description during the contest to maintain the integrity of your submissions.©leetcode *
 
 */

 code :
class Solution {

    static class Pair {
    int digitSum;
    int value;
    int originalIndex;

        public Pair(int digitSum, int value, int originalIndex) {
            this.digitSum = digitSum;
            this.value = value;
            this.originalIndex = originalIndex;
        }
    }

    private int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num/=10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {

        int n = nums.length;
        List<Pair> pairs = new ArrayList<>();

        // Create pairs
        for (int i = 0; i < n; i++) {
            pairs.add(new Pair(digitSum(nums[i]), nums[i], i));
        }
        
        // Sort by digitSum, then value
        Collections.sort(pairs, (a,b )-> {
            if(a.digitSum != b.digitSum){
                return Integer.compare(a.digitSum, b.digitSum);
            } else{
                return Integer.compare(a.value, b.value);
            }
        });
        
        boolean[] visited = new boolean[n];
        int swaps = 0;
        for(int i=0; i<n; i++){
            if(visited[i] || pairs.get(i).originalIndex == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                j = pairs.get(j).originalIndex;
                cycle_size +=1;
            }

            if(cycle_size > 1){
                swaps += (cycle_size - 1);
            }   
        }
        return swaps;
    }

    // time complexity = O(n*logn) [sorting]
    // space complexity = O(n) [storing]
}

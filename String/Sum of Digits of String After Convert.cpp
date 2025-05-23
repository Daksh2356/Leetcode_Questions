/*
! Question: 1945. Sum of Digits of String After Convert
* Problem Difficulty level : Easy
? Related Topics : String, Simluation

Problem Statement:

! You are given a string s consisting of lowercase English letters, and an integer k. Your task is to convert the 
! string into an integer by a special process, and then transform it by summing its digits repeatedly k times.
! More specifically, perform the following steps:

? 1. Convert s into an integer by replacing each letter with its position in the alphabet (i.e. replace 'a' with 1, 'b' 
?    with 2, ..., 'z' with 26).
? 2. Transform the integer by replacing it with the sum of its digits.
? 3. Repeat the transform operation (step 2) k times in total.
? For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

? 1. Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
? 2. Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
? 3. Transform #2: 17 ➝ 1 + 7 ➝ 8
? Return the resulting integer after performing the operations described above.

! Example 1:
Input: s = "iiii", k = 1

Output: 36

Explanation:
The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.

! Example 2:
Input: s = "leetcode", k = 2

Output: 6

Explanation:

The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.

! Example 3:
Input: s = "zbax", k = 2

Output: 8
 
? Constraints:
1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.

? Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

//!  CODE :
class Solution {
    public int getLucky(String s, int k) {
        int num = 0;

        for(Character ch : s.toCharArray()){
            int val = ch - 'a' + 1; // every alphabet being transformed
            num += (val >=10) ? val/10 + val%10 : val;  // creating the num directly
        }

        while(k-- > 1 && num>=10 ){
            num = digitSum(num);   // remaining k-1 summations
        }

        return num; // final output value
    }

    public int digitSum(int num){
        int sum = 0;

        while(num!=0){     // sum each digit till num equals 0!
            sum += num%10;
            num/=10;
        }

        return sum;
    }

    // time complexity = O(n + log m)
    // space complexity = O(1)
        
}


//  Other way to solve this question (for small k, as above one was for large K):

class Solution {
    public int getLucky(String s, int k) {
        // Step 1: Convert each character to its corresponding alphabet position
        StringBuilder numStr = new StringBuilder();
        for (char c : s.toCharArray()) {
            numStr.append(c - 'a' + 1); // Convert 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
        }

        // Convert to integer and apply digit sum transformation k times
        int num = getDigitSum(numStr.toString());

        for (int i = 1; i < k; i++) {
            num = getDigitSum(String.valueOf(num));
        }

        return num;
    }

    // Helper function to calculate the sum of digits
    private int getDigitSum(String numStr) {
        int sum = 0;
        for (char c : numStr.toCharArray()) {
            sum += c - '0'; // Convert char to integer and add
        }
        return sum;
    }

    // Time Complexity: O(n + k log n)
    // Space Complexity: O(n) 
}
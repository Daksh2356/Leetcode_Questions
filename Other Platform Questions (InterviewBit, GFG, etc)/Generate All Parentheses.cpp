/*
Problem Description
 
Given a string A, containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Note:  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Problem Constraints
1 <= |A| <= 10^6

Input Format
The first and only argument is a string A.

Output Format
Return an integer, 0 / 1 ( 0 for false, 1 for true )

Example Input
Input 1:
A = "()[]{}"
Input 2:
A = "([)]"


Example Output
Output 1:
1
Output 2:
0

*/

// code : 
int Solution::isValid(string A) {
     std::stack<int> brackets;
        for(char c : A)        
        {
            if( c == '[' || c == '{' || c == '(')
            {
                brackets.push(c);
            }
            else
            {
                if(brackets.empty())
                return false;

                char top = brackets.top();
                brackets.pop();

                if( (c == ')' && top!='(')  || 
                (c == ']' && top!='[') || 
                (c == '}' && top!='{' ) ) 
                return false;
            }
        }

        return brackets.empty();

        // time complexity = O(n)
        // space complexity = O(n)
}
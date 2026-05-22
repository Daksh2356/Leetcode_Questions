/*
Question : 621. Task Scheduler
Date : 19-03-24
Problem Difficulty level : Medium
Related Topics : Array Hash Table Greedy Sorting Heap (Priority Queue) Counting

Problem Statement:
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of
one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to
cooling time.

​Return the minimum number of intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can
be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of
these tasks.



Constraints:
1 <= tasks.length <= 10^4
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};

        for (char task : tasks)
        {
            freq[task - 'A']++; // count of each task is stored
        }

        sort(begin(freq), end(freq)); // ascending order => takes constant time only
        int chunk = freq[25] - 1;     // chunk of tasks
        int idle = chunk * n;         // idle time along with cooling constraint

        for (int i = 24; i >= 0; i--)
        {
            idle -= min(chunk, freq[i]); // updating remaining idle time
        }

        return idle < 0 ? tasks.size() : tasks.size() + idle;
    }
    // time complexity = O(n)
    // space complexity = O(1)
};


// More easier approach with same time and space complexity but more readable code (JAVA langugage)

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int countMax = 0;
        int max = freq[0];
        for (int val : freq) {
            if (val == max)
                countMax += 1;
            if (max < val) {
                max = val;
                countMax = 1;
            }
        }

        int minimumLength = countMax + (max - 1) * (n + 1);
        int ans = Math.max(minimumLength, tasks.length);
        return ans;

        // T.C = O(N), S.C = O(1)
    }
}
// solution try
class Solution
{
private:
    int binarySearch(vector<int> &arr, int target) // time => O(logn)
    {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0, result = -1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] <= target)
            {
                low = mid + 1;
                result = mid;
            }
            else
                high = mid - 1;
        }

        return result;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // time => O(nlogn)
        int minOperations = n;

        for (int i = 0; i < n; i++) // time => O(n)
        {
            int rightIndex = binarySearch(nums, nums[i] + n - 1); // (nums[i] + n-1) is the rightmost element required for satisfying the diff condition

            int operations = n - (rightIndex - i + 1);
            minOperations = min(minOperations, operations);
        }

        return minOperations;
    }

    // Time complexity = O(nlogn) -> sorting has same time as (linear loop + binary search)
    // Space Complexity = O(1) -> constant extra space is used in this solution
};
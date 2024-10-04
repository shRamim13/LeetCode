fclass Solution{
    public :
        int search(vector<int> & nums, int target){
            int lt = 0;
int rt = nums.size() - 1;
while (lt <= rt)
{
    int mid = lt + (rt - lt) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[lt] <= nums[mid])
    {
        if (nums[lt] <= target && target < nums[mid])
        {
            rt = mid - 1;
        }
        else
        {
            lt = mid + 1;
        }
    }
    else
    {
        if (nums[mid] < target && target <= nums[rt])
        {
            lt = mid + 1;
        }
        else
        {
            rt = mid - 1;
        }
    }
}
return -1;
}
}
;

// 4 5 6 7 8 9 0 1 2
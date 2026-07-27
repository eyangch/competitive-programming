func maxProduct(nums []int) int {
    slices.Sort(nums)
    return (nums[len(nums)-1] - 1) * (nums[len(nums)-2] - 1)
}


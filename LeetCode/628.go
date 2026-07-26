func maximumProduct(nums []int) int {
    pos := make([]int, 0)
    neg := make([]int, 0)
    hasZero := false
    for _, x := range(nums) {
        if x == 0 {
            hasZero = true
        } else if x > 0 {
            pos = append(pos, -x)
        } else {
            neg = append(neg, x)
        }
    }
    slices.Sort(pos)
    slices.Sort(neg)
    ans := -1000000000
    if hasZero {
        ans = 0
    }
    if len(pos) >= 3 {
        ans = -pos[0] * pos[1] * pos[2]
    }
    if len(pos) >= 1 && len(neg) >= 2 {
        ans = max(ans, -pos[0] * neg[0] * neg[1])
    }
    if len(neg) >= 3 {
        ans = max(ans, neg[len(neg)-1] * neg[len(neg)-2] * neg[len(neg)-3])
    }
    if len(pos) >= 2 && len(neg) >= 1 {
        ans = max(ans, pos[len(pos)-1] * pos[len(pos)-2] * neg[len(neg)-1])
    }
    return ans
}


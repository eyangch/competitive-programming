func minimumPushes(word string) int {
    occ := make([]int, 26)
    for _, c := range(word) {
        nc := c - 'a'
        occ[nc]++
    }
    slices.Sort(occ)
    slices.Reverse(occ)
    ans := 0
    for i, n := range(occ) {
        ans += (i / 8 + 1) * n
    }
    return ans
}


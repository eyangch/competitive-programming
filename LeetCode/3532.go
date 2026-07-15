func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []bool {
    cur := 0
    val := make([]int, n)
    for i := 1; i < n; i++ {
        if nums[i] - nums[i-1] > maxDiff {
            cur++
        }
        val[i] = cur
    }
    res := make([]bool, len(queries))
    for i, q := range(queries) {
        res[i] = val[q[0]] == val[q[1]]
    }
    return res
}
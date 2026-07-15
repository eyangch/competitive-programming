

func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []int {
    ixSorted := make([]int, n)
    for i := range(ixSorted) {
        ixSorted[i] = i
    }
    slices.SortFunc(ixSorted, func (a int, b int) int {
        return nums[a] - nums[b]
    })

    revIx := make([]int, n)
    for i := range(revIx) {
        revIx[ixSorted[i]] = i
    }

    slices.Sort(nums)

    jmpIx := 0
    jmp := make([][]int, 18)
    for i := range(jmp) {
        jmp[i] = make([]int, n)
    }
    for i, x := range(nums) {
        for jmpIx < n && nums[jmpIx] - x <= maxDiff {
            jmpIx++
        }
        jmp[0][i] = jmpIx - 1
    }
    for i := 1; i < 18; i++ {
        for j := range(nums) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]]
        }
    }

    ans := make([]int, len(queries))
    for i, q := range(queries) {
        q[0] = revIx[q[0]]
        q[1] = revIx[q[1]]
        start := min(q[0], q[1])
        end := max(q[0], q[1])
        if jmp[17][start] < end {
            ans[i] = -1
            continue
        }
        res := 0
        if start == end {
            ans[i] = 0
            continue
        }
        for j := 17; j >= 0; j-- {
            if jmp[j][start] < end {
                res |= (1 << j)
                start = jmp[j][start]
            }
        }
        ans[i] = res + 1
    }

    return ans
}
func removeCoveredIntervals(intervals [][]int) int {
    slices.SortFunc(intervals, func(a, b []int) int {
        if a[0] == b[0] {
            return b[1] - a[1]
        }
        return a[0] - b[0]
    })
    end := 0
    ans := len(intervals)
    for _, v := range(intervals) {
        if end >= v[1] {
            ans--
        }
        end = max(end, v[1])
    }
    return ans
}
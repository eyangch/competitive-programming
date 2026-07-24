func extractPairXor(a1 []int, a2 []int) []int {
    exists := make([]bool, 2049)
    for _, x := range(a1) {
        for _, y := range(a2) {
            exists[x ^ y] = true
        }
    }
    ret := make([]int, 0)
    for i, b := range(exists) {
        if b {
            ret = append(ret, i)
        }
    }
    return ret
}

func uniqueXorTriplets(nums []int) int {
    return len(extractPairXor(nums, extractPairXor(nums, nums)))
}


func sequentialDigits(low int, high int) []int {
    ans := make([]int, 0)

    for i := 0; i < 9; i++ {
        for j := 1; j + i <= 9; j++ {
            nu := 0
            for k := j; k <= j + i; k++ {
                nu = nu * 10 + k
            }
            if nu >= low && nu <= high {
                ans = append(ans, nu)
            }
        }
    }
    
    return ans
}
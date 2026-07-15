var MOD int64 = 1000000007

func sumAndMultiply(s string, queries [][]int) []int {
    pfxSum := make([]int64, len(s)+1)
    pfxNum := make([]int64, len(s)+1)
    pfxPow := make([]int64, len(s)+1)
    pow10 := make([]int64, len(s)+1)
    pow10[0] = 1
    for i, c := range(s) {
        pow10[i+1] = pow10[i] * 10 % MOD
        digit := int64(c) - int64('0')
        pfxSum[i+1] = pfxSum[i] + digit
        if digit == 0 {
            pfxPow[i+1] = pfxPow[i]
            pfxNum[i+1] = pfxNum[i]
        } else {
            pfxPow[i+1] = pfxPow[i] + 1
            pfxNum[i+1] = (pfxNum[i] * int64(10) + digit) % MOD
        }
    }
    res := make([]int, len(queries))
    for i, q := range(queries) {
        l, r := q[0], q[1]
        res[i] = int(((pfxNum[r+1] - pfxNum[l] * pow10[pfxPow[r+1] - pfxPow[l]]) % MOD * (pfxSum[r+1] - pfxSum[l]) % MOD + MOD) % MOD)
    }
    return res
}
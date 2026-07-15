const MOD int = 1000000007
const MX int = 200

func iterGCD(a int, b int) int {
    for b != 0 {
        t := a
        a = b
        b = t % b
    }
    if a < 0 {
        return -a
    }
    return a
}

func subsequencePairCount(nums []int) int {
    gcd := make([][]int, MX+1)
    for i := range(gcd) {
        gcd[i] = make([]int, MX+1)
        for j := range(gcd[i]) {
            if i == 0 || j == 0 {
                continue
            }
            gcd[i][j] = iterGCD(i, j)
        }
    }

    n := len(nums)
    dp := make([][][]int, 2)
    for i := range(dp) {
        dp[i] = make([][]int, MX+1)
        for j := range(dp[i]) {
            dp[i][j] = make([]int, MX+1)
        }
    }
    dp[1][0][0] = 1
    for i := 0; i < n; i++ {
        cur := dp[i & 1]
        old := dp[^i & 1]
        v := nums[i]

        for j := 0; j <= MX; j++ {
            if old[0][j] == 0 {
                continue
            }
            for k := 0; k <= MX; k++ {
                cur[j][k] = old[j][k]
            }
        }

        // add to empty seq
        for j := 0; j <= MX; j++ {
            if old[0][j] == 0 {
                continue
            }
            cur[v][j] += old[0][j]
            cur[j][v] += old[j][0]
            if cur[v][j] > MOD {
                cur[v][j] -= MOD
            }
            if cur[j][v] > MOD {
                cur[j][v] -= MOD
            }
        }

        for j := 1; j <= MX; j++ {
            if old[0][j] == 0 {
                continue
            }
            nj := gcd[j][v]
            cur[0][nj] += old[0][j]
            cur[nj][0] += old[j][0]
            if cur[0][nj] > MOD {
                cur[0][nj] -= MOD
            }
            if cur[nj][0] > MOD {
                cur[nj][0] -= MOD
            }
        }

        for j := 1; j <= MX; j++ {
            if old[0][j] == 0 {
                continue
            }
            for k := 1; k <= MX; k++ {
                if old[0][k] == 0 {
                    continue
                }
                nj := gcd[j][v]
                nk := gcd[k][v]

                cur[nj][k] += old[j][k]
                cur[j][nk] += old[j][k]

                if cur[nj][k] > MOD {
                    cur[nj][k] -= MOD
                }
                if cur[j][nk] > MOD {
                    cur[j][nk] -= MOD
                }
            } 
        }
    }

    ans := 0
    for i := 1; i <= MX; i++ {
        ans += dp[^n & 1][i][i]
        if ans > MOD {
            ans -= MOD
        }
    }

    return ans
}
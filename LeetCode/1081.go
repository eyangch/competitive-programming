func smallestSubsequence(s string) string {
    n := len(s)
    btmsk := make([]int, n+1)
    next26 := make([][]int, 26)
    for i := n-1; i >= 0; i-- {
        c := int(s[i]) - int('a')
        btmsk[i] = btmsk[i+1] | (1 << c)
    }
    for i := 0; i < 26; i++ {
        nxt := -1
        next26[i] = make([]int, n)
        for j := n-1; j >= 0; j-- {
            if int(s[j]) - int('a') == i {
                nxt = j
            }
            next26[i][j] = nxt
        }
    }
    cur := ^btmsk[0]
    ix := 0
    ans := make([]rune, 0)
    for ^cur != 0 {
        for i := 0; i < 26; i++ {
            if (cur & (1 << i)) == 0 {
                ix2 := next26[i][ix]
                if ^(cur | btmsk[ix2]) == 0 {
                    ans = append(ans, rune(i + int('a')))
                    cur |= (1 << i)
                    ix = ix2+1
                    break
                }
            }
        }
    }
    return string(ans)
}


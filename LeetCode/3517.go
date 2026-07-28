func smallestPalindrome(s string) string {
    half_len := len(s) / 2
    ans := []rune(s[:half_len])
    slices.Sort(ans)
    rev_half := slices.Clone(ans)
    slices.Reverse(rev_half)
    if len(s) % 2 == 1 {
        ans = append(ans, rune(s[half_len]))
    }
    ans = append(ans, rev_half...)
    return string(ans)
}


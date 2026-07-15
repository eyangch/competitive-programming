func sumAndMultiply(n int) int64 {
    digitsum, x, mult := int64(0), int64(0), int64(1)
    for n > 0 {
        digitsum += int64(n) % 10
        if n % 10 != 0 {
            x += mult * int64(n % 10)
            mult *= 10
        }
        n /= 10
    }
    return digitsum * x
}
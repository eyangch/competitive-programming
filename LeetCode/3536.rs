impl Solution {
    pub fn max_product(n: i32) -> i32 {
        let mut mx1 = 0;
        let mut mx2 = 0;
        let mut n = n;
        while n > 0 {
            let digit = n % 10;
            if digit >= mx1 {
                mx2 = mx1;
                mx1 = digit;
            } else if digit >= mx2 {
                mx2 = digit;
            }
            n = n / 10;
        }
        mx1 * mx2
    }
}


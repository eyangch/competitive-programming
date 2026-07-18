impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        // i don't know how to write a for loop in rust
        let min = *nums.iter().min().unwrap();
        let max = *nums.iter().max().unwrap();

        let mut ans = min;
        loop {
            if min % ans == 0 && max % ans == 0 {
                return ans;
            }
            ans -= 1
        }
    }
}

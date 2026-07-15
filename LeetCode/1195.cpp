class FizzBuzz {
private:
    int n;
    int cur = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock lk(m);
        while(true){
            cv.wait(lk, [this](){ return cur % 3 == 0 && cur % 5 || cur > n; });
            if(cur > n){
                return;
            }
            printFizz();
            cur++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock lk(m);
        while(true){
            cv.wait(lk, [this](){ return cur % 5 == 0 && cur % 3 || cur > n; });
            if(cur > n){
                return;
            }
            printBuzz();
            cur++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock lk(m);
        while(true){
            cv.wait(lk, [this](){ return cur % 15 == 0 || cur > n; });
            if(cur > n){
                return;
            }
            printFizzBuzz();
            cur++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock lk(m);
        while(true){
            cv.wait(lk, [this](){ return cur % 5 && cur % 3 || cur > n; });
            if(cur > n){
                return;
            }
            printNumber(cur);
            cur++;
            cv.notify_all();
        }
    }
};
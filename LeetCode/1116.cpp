class ZeroEvenOdd {
private:
    int n;
    int turn = 0;
    mutex m;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn = 2;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock lk(m);
        for(int i = 0; i < n; i++){
            cv.wait(lk, [this](){return (turn == 2);});
            turn = i%2;
            printNumber(0);
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock lk(m);
        for(int i = 2; i <= n; i += 2){
            cv.wait(lk, [this](){return (turn == 1);});
            turn = 2;
            printNumber(i);
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock lk(m);
        for(int i = 1; i <= n; i += 2){
            cv.wait(lk, [this](){return (turn == 0);});
            turn = 2;
            printNumber(i);
            cv.notify_all();
        }
    }
};
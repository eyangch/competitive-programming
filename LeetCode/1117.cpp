class H2O {
public:
    int nh = 0;
    mutex m;
    condition_variable cv;
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock lk(m);
        cv.wait(lk, [this](){ return nh < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        nh++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock lk(m);
        cv.wait(lk, [this](){ return nh == 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        nh = 0;
        cv.notify_all();
    }
};
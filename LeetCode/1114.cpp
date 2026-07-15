class Foo {
public:
    mutex m1, m2, m3;
    Foo() {
        m2.lock(), m3.lock();
    }

    void first(function<void()> printFirst) {
        m1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
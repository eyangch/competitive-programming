class FooBar {
private:
    int n;

public:
    mutex m_foo, m_bar;
    FooBar(int n) {
        this->n = n;
        m_bar.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            m_foo.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m_bar.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            m_bar.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m_foo.unlock();
        }
    }
};
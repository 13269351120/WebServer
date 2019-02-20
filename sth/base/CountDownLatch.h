#ifndef STH_BASE_COUNTDOWNLATCH_H
#define STH_BASE_COUNTDOWNLATCH_H

#include <sth/base/Condition.h>
#include <sth/base/Mutex.h>

namespace sth
{

class CountDownLatch
{
    public:
        explicit CountDownLatch(int count);

        void wait();

        void countDown();

        int getCount() const;

    private:
        mutable MutexLock mutex_;
        Condition condition_ GUARDED_BY(mutex_);
        int count_ GUARDED_BY(mutex_);
};
} //namespace sth

#endif //define

#ifndef STH_BASE_CURRENTTHREAD_H
#define STH_BASE_CURRENTTHREAD_H

#include <sth/base/Types.h>

namespace sth
{
namespace CurrentThread
{
    extern __thread int t_cacheTid;
    extern __thread char t_tidString[32];
    extern __thread int t_tidStringLength;
    extern __thread const char* t_threadName;
    void cacheTid();

    inline int tid()
    {
        if(__builtin_expect(t_cacheTid == 0 , 0))
        {
            cacheTid();
        }
        return t_cacheTid;
    }

    inline const char* tidString() //for logging
    {
        return t_tidString;
    }

    inline int tidStringLength() //for logging
    {
        return t_tidStringLength;
    }

    inline const char* name()
    {
        return t_threadName;
    }

    bool isMainThread();

    void sleepUsec(int64_t usec);  //for testing

    string stackTrace(bool demangle);

} //namespace CurrentThread

} //namespace sth

#endif //define

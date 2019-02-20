#ifndef STH_BASE_NONCOPYABLE_H
#define STH_BASE_NONCOPYABLE_H

namespace sth
{
class noncopyable
{
    public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

    protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} //namespace sth

#endif 

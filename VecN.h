#ifndef VECN_H
#define VECN_H

#include <cstring>

template<typename T, unsigned N>
class Vec
{
private:
    T mData[N] = { 0 };

public:
    Vec() {}
    ~Vec() {}

    Vec(T initial) {
        std::memset(mData, initial, N);
    }
    template<typename Iter>
    Vec(Iter begin, Iter end) {
        for (unsigned i = 0; i < N, begin != end; i++, begin++)
            mData[i] = *begin;
    }
    Vec(const Vec<T, N>& other) {
        for (unsigned i = 0; i < N; i++)
            this->mData[i] = other.mData[i];
    }


    const T operator[](unsigned index) const {
        return mData[index];
    }
    T& operator[](unsigned index) {
        return mData[index];
    }

    Vec<T, N> operator+(const Vec<T, N> &other) {
        Vec<T, N> res;
        for (unsigned i = 0; i < N; i++)
            res[i] = mData[i] + other[i];
        return res;
    }
    Vec<T, N> operator-(const Vec<T, N> &other) {
        Vec<T, N> res;
        for (unsigned i = 0; i < N; i++)
            res[i] = mData[i] - other[i];
        return res;
    }
    Vec<T, N> operator*(const T scalar) {
        Vec<T, N> res;
        for (unsigned i = 0; i < N; i++)
            res[i] = mData[i] * scalar;
        return res;
    }
    friend Vec<T, N> operator*(const T scalar, const Vec<T, N> &other) {
        Vec<T, N> res;
        for (unsigned i = 0; i < N; i++)
            res[i] = scalar * other.mData[i];
        return res;
    }
    Vec<T, N> operator/(const T scalar) {
        Vec<T, N> res;
        for (unsigned i = 0; i < N; i++)
            res[i] = mData[i] / scalar;
        return res;
    }

};


#endif
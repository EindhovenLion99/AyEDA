#pragma once
#include <iostream>
#include <cassert>

template <class TData>
class Vector_T
{
private:
    int sz_, start_, end_;
    TData *vp_;

public:
    Vector_T(int sz = 0, int start = 0);
    Vector_T(const Vector_T<TData> &other_v);

    ~Vector_T(void);

    int size(void) const { return sz_; };
    int start(void) const { return start_; }
    int end(void) const { return end_; }
    bool empty(void) const { return size() == 0; }

    void back_resize(int &nsz);

    TData &at(int pos);
    TData &at(int pos) const;

    void push_back(TData value);

    std::ostream &write(std::ostream &os) const;

    // OPERATORS
    TData &operator[](int pos);
    TData operator[](int pos) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, Vector_T<U> &);

private:
    void create(void);

    void copy(Vector_T v);
    void destroy(void);
};

// PUBLIC METHODS

template <class TData>
Vector_T<TData>::Vector_T(int sz, int start) : vp_(0),
                                               sz_(sz),
                                               start_(start)
{

    end_ = (sz_ == 0) ? 0 : (sz - 1 + start);
    create();
}

template <class TData>
Vector_T<TData>::Vector_T(const Vector_T<TData> &other_v) : vp_(NULL),
                                                            sz_(other_v.size())
{
    create();
    copy(other_v);
}

template <class TData>
Vector_T<TData>::~Vector_T(void)
{
    destroy();
}

template <class TData>
TData &Vector_T<TData>::at(int pos) const
{
    assert(pos >= start_ && pos <= end_);
    return vp_[sz_ - end_ + pos - 1];
}

template <class TData>
TData &Vector_T<TData>::at(int pos)
{
    assert(pos >= start_);
    assert(pos <= end_);
    return vp_[sz_ - end_ + pos - 1];
}

template <class TData>
void Vector_T<TData>::back_resize(int &nsz)
{
    int aux_s = start_;
    int aux_e = end_;
    destroy();

    sz_ = nsz;
    create();

    start_ = aux_s;
    if (sz_ == 1)
    {
        end_ = start_;
    }
    else
    {
        end_ = aux_e + 1;
    }
}

template <class TData>
void Vector_T<TData>::push_back(TData value)
{
    Vector_T<TData> aux_v(sz_, start_);
    for (int i = 0; i < sz_; i++)
    {
        aux_v.vp_[i] = vp_[i];
    }
    int newsize = sz_ + 1;
    back_resize(newsize);

    vp_[sz_ - 1] = value;
    for (int i = 0; i < sz_ - 1; i++)
    {
        vp_[i] = aux_v.vp_[i];
    }
}

template <class TData>
std::ostream &Vector_T<TData>::write(std::ostream &os) const
{
    if (empty())
    {
        return os << "| EMPTY | \n";
    }
    os << "|";
    if (sz_ > 2)
    {
        for (int i = start_; i <= end_; i++)
        {
            os << " [" << i << "] " << at(i) << " |";
        }

        os << std::endl;

        return os;
    }
    else if (sz_ == 1)
    {
        os << " [" << end_ << "] " << at(end_) << " |";

        os << std::endl;

        return os;
    }
    else if (sz_ == 2)
    {

        os << " [" << start_ << "] " << at(start_) << " |";

        os << " [" << end_ << "] " << at(end_) << " |";
        os << std::endl;

        return os;
    }
}

// OPERATORS

template <class TData>
TData &Vector_T<TData>::operator[](int pos)
{
    return at(pos);
}

template <class TData>
TData Vector_T<TData>::operator[](int pos) const
{
    return at(pos);
}

template <class TData>
std::ostream &operator<<(std::ostream &os, Vector_T<TData> &v)
{
    v.write(os);
    return os;
}

// PRIVATE METHODS

template <class TData>
void Vector_T<TData>::create(void)
{
    if (sz_ > 0)
    {
        vp_ = new TData[sz_];
        for (int i = 0; i < sz_; i++)
            vp_[i] = 0;
    }
    else if (sz_ == 0)
        vp_ = 0;
}

template <class TData>
void Vector_T<TData>::copy(Vector_T<TData> v)
{
    for (int i = 0; i < sz_; i++)
        vp_[i] = v[i];
}

template <class TData>
void Vector_T<TData>::destroy(void)
{
    if (vp_ != NULL)
        delete[] vp_;
    vp_ = NULL;
}
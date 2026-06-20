#ifndef __RESTAURANT__
#define __RESTAURANT__
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include "establishment.hpp"
typedef size_t ll;
using std::cout;
using std::endl;
template<typename T>
class Restaurant: virtual public Establishment{
protected:
    T kitchen;
    double price_per_person;
public:
    //Restaurant():Establishment(), kitchen(new T()), price_per_person(0){}
    Restaurant(const char* name,
               const ll& capacity,
               const T& kitchen,
               const double& price_per_person): Establishment(name, capacity), kitchen(kitchen), price_per_person(price_per_person){}
    const char* type()const override{
        return "Restaurant";
    }
    Establishment* clone()const override{
        return (new Restaurant(*this));
    }
    double max_profit()const override{
        return (price_per_person*(double)capacity);
    }
    ~Restaurant() override = default;
};

#endif


#ifndef __PIANOBAR__
#define __PIANOBAR__
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include "establishment.hpp"
#include "restaurant.hpp"
#include "musicvenue.hpp"
typedef size_t ll;
using std::cout;
using std::endl;
template<typename T>
class PianoBar: public Restaurant<T>, public MusicVenue{
private:


public:
   // PianoBar(): Establishment(), Restaurant<T>(), MusicVenue(){}
    PianoBar(const char* name, const ll& capacity, const T& kitchen,
             const double& price_per_person, const char* music_type,
             const double& ticket_price):
                 Establishment(name, capacity),
                 Restaurant<T>(name, capacity, kitchen, price_per_person),
                 MusicVenue(name, capacity, music_type, ticket_price){}
    const char* type()const{
        return "PianoBar";
    }
    Establishment* clone()const{
        return (new PianoBar(*this));
    }
    double max_profit()const{
        return ((double)capacity*(ticket_price+Restaurant<T>::price_per_person));
    }
    ~PianoBar() = default;
};

#endif

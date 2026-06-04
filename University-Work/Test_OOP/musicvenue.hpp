#ifndef __MUSICVENUE__
#define __MUSICVENUE__
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include "establishment.hpp"
typedef size_t ll;
using std::cout;
using std::endl;
class MusicVenue: virtual public Establishment{
protected:
    char* music_type;
    double ticket_price;
private:
    void copy(const char* str){
        ll len = strlen(str)+1;
        music_type = new char[len];
        strcpy(music_type, str);
    }
public:
    //MusicVenue(): Establishment(), music_type(nullptr), ticket_price(0){}
    MusicVenue(const char* name,
               const ll& capacity,
               const char* music_type,
               const double& ticket_price): Establishment(name, capacity), ticket_price(ticket_price){
        copy(music_type);
    }
    ~MusicVenue(){
        delete[] music_type;
    }
    MusicVenue(const MusicVenue& other): Establishment(other){
        ticket_price = other.ticket_price;
        copy(other.music_type);
    }
    MusicVenue(MusicVenue&& other): Establishment(std::move(other)){
        ticket_price = other.ticket_price;
        music_type = other.music_type;
        other.music_type = nullptr;
    }
    MusicVenue& operator=(const MusicVenue& other){
        if(this != &other){
            Establishment::operator=(other);
            delete[] music_type;
            copy(other.music_type);
            ticket_price = other.ticket_price;
        }
        return *this;
    }
    MusicVenue& operator=(MusicVenue&& other) noexcept {
        if(this != &other){
            delete[] music_type;
            Establishment::operator=(std::move(other));
            music_type = other.music_type;
            other.music_type = nullptr;
            ticket_price = other.ticket_price;
        }
        return *this;
    }
    const char* type()const{
        return "MusicVenue";
    }
    Establishment* clone()const{
        return (new MusicVenue(*this));
    }
    double max_profit()const {
        return ((double)capacity*ticket_price);
    }
};

#endif


#ifndef __ESTABLISHMENT__
#define __ESTABLISHMENT__
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
typedef size_t ll;
using std::cout;
using std::endl;
class Establishment{
protected:
    char* name;
    ll capacity;
private:
    void copy(const char* str){
        ll len = strlen(str)+1;
        this->name = new char[len];
        strcpy(name, str);
    }
public:
    //Establishment(): name(nullptr), capacity(0){}
    Establishment(const char* name, const ll& capacity): capacity(capacity){
        copy(name);
    }
    virtual ~Establishment(){
        delete[] name;
    }
    Establishment(const Establishment& other){
        capacity = other.capacity;
        copy(other.name);
    }
    Establishment(Establishment&& other) noexcept {
        capacity = other.capacity;
        name = other.name;
        other.name = nullptr;
    }
    Establishment& operator=(const Establishment& other){
        if(this != &other){
            delete[] name;
            capacity = other.capacity;
            copy(other.name);
        }
        return *this;
    }
    Establishment& operator=(Establishment&& other) noexcept {
        if(this != &other){
            delete[] name;
            capacity = other.capacity;
            name = other.name;
            other.name = nullptr;
        }
        return *this;
    }
    virtual const char* type() const = 0;
    virtual Establishment* clone() const = 0;
    virtual double max_profit()const = 0;
};

#endif

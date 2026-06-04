#ifndef __ESTABLISHMENT_SYSTEM__
#define __ESTABLISHMENT_SYSTEM__
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include "establishment.hpp"

typedef size_t ll;
using std::cout;
using std::endl;

class EstablishmentSystem{
private:
    Establishment** est;
    ll size;
    ll capacity;
    void clear(){
        for(ll i = 0; i < size; ++i){
            delete est[i];
        }
        delete[] est;
    }
    void resize(const ll& size){
        if(size >= this->capacity){
            this->capacity = size * 2 + 1;
            Establishment** tmp;
            tmp = new Establishment*[this->capacity];
            if(this->size != 0){
                for(ll i = 0; i < this->size; ++i){
                    tmp[i] = est[i];
                }
                delete[] est;
            }
            est = tmp;
        }
    }

    void copy_from(const EstablishmentSystem& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->est = new Establishment*[this->capacity];
        for (ll i = 0; i < this->size; ++i) {
            this->est[i] = other.est[i]->clone();
        }
    }

public:
    EstablishmentSystem(): est(nullptr), size(0), capacity(0){}

    EstablishmentSystem(const EstablishmentSystem& other){
        copy_from(other);
    }
    EstablishmentSystem& operator=(const EstablishmentSystem& other){
        if(this != &other){
            clear();
            copy_from(other);
        }
        return *this;
    }
    EstablishmentSystem(EstablishmentSystem&& other) noexcept {
        est = other.est;
        other.est = nullptr;
        capacity = other.capacity;
        size = other.size;
        other.capacity = 0;
        other.size = 0;
    }
    EstablishmentSystem& operator=(EstablishmentSystem&& other) noexcept {
        if(this != &other){
            clear();
            est = other.est;
            other.est = nullptr;
            capacity = other.capacity;
            size = other.size;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }


    void add_establishment(const Establishment& new_est){
        add_establishment_ptr(&new_est);
    }
    void add_establishment_ptr(const Establishment* new_est){
        resize(size);
        est[size] = new_est->clone();
        size++;
    }
    void print_max_profit()const{
        for(ll i = 0; i < size; ++i){
            cout << est[i]->max_profit() << endl;
        }
    }

    Establishment& operator[](const ll index){
        if(index >= size){
            throw std::out_of_range("Index out of bounds!");
        }
        return *est[index];
    }
    const Establishment& operator[](const ll index)const {
        if(index >= size){
            throw std::out_of_range("Index out of bounds!");
        }
        return *est[index];
    }
    ll get_size()const{
        return size;
    }
    ~EstablishmentSystem(){
        clear();
    }
};


#endif

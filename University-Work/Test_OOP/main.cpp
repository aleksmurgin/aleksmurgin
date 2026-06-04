#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include "establishmentsystem.hpp"
#include "restaurant.hpp"
#include "musicvenue.hpp"
#include "pianobar.hpp"
using std::cout;
using std::endl;
typedef size_t ll;
int main(){
    //showcase for creating objects
    Restaurant<char> r("Restaurant", 3, 'a', 3.4);
    MusicVenue m("Music", 3, "jazz", 4.2);
    PianoBar<char> p("Piano", 3, 'a', 4.2, "rock", 32.2);

    EstablishmentSystem est;

    //showcase for adding new establishments

    est.add_establishment(r);
    est.add_establishment(m);
    est.add_establishment(p);

    //showcase for print method
    est.print_max_profit();

    //showcase for operator[]
    for(ll i = 0; i < est.get_size(); ++i){
        cout<<est[i].type()<<endl;
        cout<<est[i].max_profit()<<endl;
    }

    return 0;
}

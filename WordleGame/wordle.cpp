#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>
#include "check.cpp"
using namespace std;
vector<string> validwords;
int wordcnt;
vector<string> validanswers;
int answercnt;
vector<string> guessedwords;
bool currmode; /// 0 - easy 1 - hard
int guesses;
string wordle_answer;
void vh(){
    ifstream myfile;
    myfile.open("valid-words.txt");
    string a;
    while(myfile.good()){
        myfile>>a;
        validwords.push_back(a);
        //cout<<a<<"\n";
    }
    wordcnt=validwords.size();
    myfile.close();
    myfile.open("valid-answers.txt");
    while(myfile.good()){
        myfile>>a;
        validanswers.push_back(a);
    }
    myfile.close();
    answercnt=validanswers.size();
}
void results(){
    if(guesses==1) cout<<"You got lucky on this one, good job!\n";
    else if(guesses <= 3){
        cout<<"Wow! Good job you guessed the word in "<<guesses<<" tries!\n";
    }else if(guesses<=5){
        cout<<"Good job! It was not easy but you managed to guess the word in "<<guesses<<" tries.\n";
    }else if(guesses==6){
        cout<<"Close one! You guessed it on the last try! Good job!\n";
    }else{
        cout<<"Ooof, you didn't guess the word D: It's alright though we can still play another word.\n";
    }
    cout<<"The mystery word was ";
    check(wordle_answer,wordle_answer);
    sleep(2);
    cout<<"\nWanna play one more?\n";
}
void replay(){
    guesses = 0;
    clear_letters();
    system("cls");
    currmode = false;
    guessedwords.clear();
}
int isValid(string guess){ /// 0 - nevaliden zaradi nesyshtestvuvane -1 e nevaliden zaradi hard mode 1 - validen -2
    if(guess.size()!=5) return -2;
    bool fl = false;
    for(int i=0;i<wordcnt;i++){
        if(guess==validwords[i]){
            fl=true;
        }
    }
    if(!fl) return 0;
    if(currmode){ //hard
        bool used[6]={0,0,0,0,0,0}; /// proverena li e
        for(int i=1;i<=5;i++){
            if(keyboard_colors[guess[i-1]]==143){
                return -1;
            }
            if(locked[i]!=0){
                if(locked[i]!=guess[i-1]) return -1;
                used[i-1]=true;
            }
        }
        /// v checka pri jultite prosto shte se dobavqt vsichki julti bukvi koito ima na posledniq guess
        for(int i=0;i<julti.size();i++){
            fl=false;
            for(int j=0;j<5;j++){
                if(guess[j]==julti[i] and used[j]==false){
                    used[j]=true;
                    fl=true;
                    break;
                }
            }
            if(!fl) return -1;
        }
    }
    return 1;
}
string mode(){
    if(currmode)return "Current game mode: hard";
    else return "Current game mode: easy";
}
void goodbye(){
    cout<<"Ok D; Hope you had a great time!\n";
    cout<<"Bye!\n";
}
int main () {
    vh();
    string input;
    srand (time(NULL));
    while(true){
        wordle_answer = validanswers[rand()%answercnt];
        while(true){
            cout<<"Hard mode or easy mode?\n";
            cin>>input;
            if(input=="hard" or input=="Hard" or input=="HARD" or input=="Hard mode" or input=="hard mode" or input=="HARD MODE"){
                currmode = true;
                break;
            }else if(input=="easy" or input=="Easy" or input=="EASY" or input=="Easy mode" or input=="easy mode" or input=="EASY MODE"){
                break;
            }
            system("cls");
        }
        system("cls");
        cout<<mode()<<"\nYou have 6 guesses to find out what the mystery word is:";
        for(int i=1;i<=6;i++){
            cout<<"\n"<<i<<": ";
            cin>>input;
            while(isValid(input)!=1){
                cout<<"Your guess isn't valid!\n";
                if(isValid(input)==-2){
                    cout<<"The length of your guess is not 5.\n";
                }
                else if(isValid(input)==-1){
                    cout<<"You should use the letters you already have.\n";
                }else{
                    cout<<"This word doesn't exist.\n";
                }
                sleep(2.5);
                system("cls");
                cout<<mode()<<"\nYou have 6 guesses to find out what the mystery word is:\n";
                for(int j=0;j<(int)guessedwords.size();j++){
                    cout<<j+1<<": ";
                    check(wordle_answer,guessedwords[j]);
                }
                if(i>1) print_keyboard(guesses-1);
                cout<<"\n"<<i<<": ";
                cin>>input;
            }
            guessedwords.push_back(input);
            system("cls");
            cout<<mode()<<"\nYou have 6 guesses to find out what the mystery word is:\n";
            for(int j=0;j<(int)guessedwords.size();j++){
                cout<<j+1<<": ";
                check(wordle_answer,guessedwords[j]);
            }
            print_keyboard(guesses);
            guesses++;
            if(input==wordle_answer){
                break;
            }
        }
        if(input!=wordle_answer) guesses++;
        cout<<"\n\n";
        sleep(1.2);
        results();
        cin>>input;
        if(input=="yes" or input=="Yes" or input=="YES" or input=="yeah" or input=="YEAH" or input=="Yeah") replay();
        else{
            goodbye();
            break;
        }
        //else break;
    }
    return 0;
}

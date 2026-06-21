#include<map>
#include<string>
#include <windows.h>
#include <vector>
using namespace std;
map<char,int> keyboard;
map<char,int> keyboard_colors;
char locked[6];
vector<char> julti;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void color(char guess, int colour){
    SetConsoleTextAttribute(hConsole,colour);
    cout<<guess;
    SetConsoleTextAttribute(hConsole,15);
}
void check(string curr_ans, string guess){
        bool used2[6]={0,0,0,0,0,0};
        bool used[6]={0,0,0,0,0,0};
        for(int i=0;i<5;i++){
            if(guess[i]==curr_ans[i]){
                used2[i]=true;
                used[i]=true;
                locked[i+1]=guess[i];
                keyboard[guess[i]]=2;
                keyboard_colors[guess[i]]=175;
            }
        }
        julti.clear();
        for(int i=0;i<5;i++){
            if(used[i]!=0){
                color(guess[i],175);
            }else{
                bool fl=false;
                for(int j=0;j<5;j++){
                    if(guess[i]==curr_ans[j] and !used2[j] and !used[i]){
                        //if(locked[j+1]==0){
                            julti.push_back(guess[i]);
                            color(guess[i],111);
                            used2[j]=true;
                            used[i]=true;
                            if(keyboard[guess[i]]!=2){
                                keyboard[guess[i]]=1;
                                keyboard_colors[guess[i]]=111;
                            }
                            fl=true;
                        //}
                    }
                }
                if(!fl){
                    if(keyboard_colors[guess[i]]==0||keyboard_colors[guess[i]]==15){
                        keyboard[guess[i]]=3;
                        keyboard_colors[guess[i]]=143;
                    }
                    color(guess[i],143);
                }
            }
        }
    SetConsoleTextAttribute(hConsole,15);
    cout<<endl;
}

void print_letter(char c,int col){
    if(col==0){
        col=15;
    }
    SetConsoleTextAttribute(hConsole,col);
    cout<<c;
    SetConsoleTextAttribute(hConsole,15);
    cout<<" ";
}
void print_keyboard(int kolko){
    for(int i=8-kolko;i>=0;i--) cout<<"\n";
    print_letter('Q',keyboard_colors['q']);
    print_letter('W',keyboard_colors['w']);
    print_letter('E',keyboard_colors['e']);
    print_letter('R',keyboard_colors['r']);
    print_letter('T',keyboard_colors['t']);
    print_letter('Y',keyboard_colors['y']);
    print_letter('U',keyboard_colors['u']);
    print_letter('I',keyboard_colors['i']);
    print_letter('O',keyboard_colors['o']);
    print_letter('P',keyboard_colors['p']);
    SetConsoleTextAttribute(hConsole,15);
    cout<<endl<<" ";
    print_letter('A',keyboard_colors['a']);
    print_letter('S',keyboard_colors['s']);
    print_letter('D',keyboard_colors['d']);
    print_letter('F',keyboard_colors['f']);
    print_letter('G',keyboard_colors['g']);
    print_letter('H',keyboard_colors['h']);
    print_letter('J',keyboard_colors['j']);
    print_letter('K',keyboard_colors['k']);
    print_letter('L',keyboard_colors['l']);
    SetConsoleTextAttribute(hConsole,15);
    cout<<" "<<endl<<"   ";
    print_letter('Z',keyboard_colors['z']);
    print_letter('X',keyboard_colors['x']);
    print_letter('C',keyboard_colors['c']);
    print_letter('V',keyboard_colors['v']);
    print_letter('B',keyboard_colors['b']);
    print_letter('N',keyboard_colors['n']);
    print_letter('M',keyboard_colors['m']);
    SetConsoleTextAttribute(hConsole,15);
    cout<<"   ";
}
void clear_letters(){
    for(int i='a';i<'a'+27;i++){
        char c=i;
        keyboard[c]=0;
        keyboard_colors[c]=15;
    }
    locked[1]=0;
    locked[2]=0;
    locked[3]=0;
    locked[4]=0;
    locked[5]=0;
}


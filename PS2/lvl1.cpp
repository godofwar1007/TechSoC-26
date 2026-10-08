#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;


class Bender{

    public:
    string element;
    int hp;
    int attack;
    int defense;
    int speed;
    int maxHp;
     vector<pair<string, int>> moves;
     string name;

     Bender(string name,string element,int hp,int attack,int defense,int speed,vector<pair<string,int>> moves){
        this->name=name;
        this->element=element;
        this->hp=hp;
        this->attack=attack;
        this->defense=defense;
        this->speed=speed;
        this->moves=moves;
        maxHp=hp;
     }

     void displayStats(){
        cout << name << " (" << element << ") - HP : " << hp << "/" << maxHp << ", Attack : " << attack << ", Defense : " << defense << ", Speed : " << speed << endl;
        cout << "Moves: ";
        for(int i=0;i<moves.size();i++){
            cout << moves[i].first << " (Power:" << moves[i].second << ")";
            if(i!=moves.size()-1){
                cout << ", ";
            }
        }
        cout << endl;
     }

     void Attack(Bender &opponent,int movesIndex){
        int power=moves[movesIndex].second;
        string moveName=moves[movesIndex].first;
        cout << name << " used " << moveName << "!\n";
        int damage=round((double)(attack*power)/(opponent.defense));
        opponent.hp-=damage;
        if(opponent.hp<0)
            opponent.hp=0;
            cout << opponent.name << " took " << damage << " damage!\n";
     }

     bool isFainted(){
        return hp<=0;
     }

};


int main(){
    Bender kael("Kael","Fire",100,58,38,88,{{"Ember Slash",40},{"Quick Jab",30},{"Focus",0},{"Flame Surge",70}});
    Bender mira("Mira","Water",92,50,45,60,{{"Water Whip",35},{"Tide Push",25},{"Mist Veil",0},{"Tidal Wave",60}});
    Bender zephyr("Zephyr","Air",28,12,50,95,{{"Gust",0},{"Wind Slap",18},{"Tumble",12},{"Cyclone",22}});
    Bender doran("Doran","Earth",145,80,75,40,{{"Boulder Throw",75},{"Rock Fist",42},{"Tremor",48},{"Mountain Crush",85}});
    /*kael.displayStats();
    mira.displayStats();
    kael.Attack(mira,0);
    mira.displayStats();
    cout << endl << endl;
     cout << "Mira fainted: "
         << (mira.isFainted() ? "True" : "False")
         << endl;
         zephyr.displayStats();
         doran.displayStats();
         doran.Attack(zephyr,0);
         zephyr.displayStats();
         cout << endl << endl;
         cout << "Zephyr fainted: "
         << (zephyr.isFainted() ? "True" : "False")
            << endl;
            kael.Attack(mira,3);
            mira.displayStats();
            cout << endl << endl;
            cout << "Mira fainted: "
            << (mira.isFainted() ? "True" : "False")
            << endl;
            return 0;*/


            string first,second;
            cout << "Enter the 2 benders you wish to battle\n";
            cin >> first >> second;


            Bender *b1,*b2;
            if(first=="Kael" || first=="kael" || first=="KAEL"){
                b1=&kael;
            }
            else if(first=="Mira" || first=="mira" || first=="MIRA"){
                b1=&mira;
            }
            else if(first=="Zephyr" || first=="zephyr" || first=="ZEPHYR"){
                b1=&zephyr;
            }
            else if(first=="Doran" || first=="doran" || first=="DORAN"){
                b1=&doran;
            }
            if(second=="Kael" || second=="kael" || second=="KAEL"){
                b2=&kael;
            }
            else if(second=="Mira" || second=="mira" || second=="MIRA"){
                b2=&mira;
            }
            else if(second=="Zephyr" || second=="zephyr" || second=="ZEPHYR"){
                b2=&zephyr;
            }
            else if(second=="Doran" || second=="doran" || second=="DORAN"){
                b2=&doran;
            }


                int turn;
                cout << "Enter 1 if you wish first bender to attack first,else enter 2\n";
                cin >> turn;
                int n; 


                if(turn==1){
                (*b1).displayStats();
                (*b2).displayStats();
                 cout << "Enter the index of the move you wish to be used\n";
                cin >> n;
                (*b1).Attack((*b2),n);
                (*b2).displayStats();
                cout << endl << endl;
                cout << (*b2).name << " fainted: "
                << ((*b2).isFainted() ? "True" : "False")
                << endl;
                }


                else{
                    (*b1).displayStats();
                    (*b2).displayStats();
                    cout << "Enter the index of the move you wish to be used\n";
                    cin >> n;
                    (*b2).Attack((*b1),n);
                    (*b1).displayStats();
                    cout << endl << endl;
                    cout << (*b1).name << " fainted: "
                    << ((*b1).isFainted() ? "True" : "False")
                    << endl;
                }

                
            return 0;
}
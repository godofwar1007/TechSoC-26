#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>



using namespace std;

class Bender{
    public:
    string name;
    string element;
    int hp;
    int attack;
    int defense;
    int speed;
    int maxHp;
    vector<pair<string,int>> moves;


    Bender(string name,string element,int hp,int attack,int defense,int speed,vector<pair<string,int>> moves){
        this->name=name;
        this->element=element;
        this->hp=hp;
        maxHp=hp;
        this->attack=attack;
        this->defense=defense;
        this->speed=speed;
        this->moves=moves;
    }


     void displayStats(){
        cout << name << " (" << element << ") - HP : " << hp << "/" << maxHp << ", Attack : " << attack << ", Defense : " << defense << ", Speed : " << speed << endl;
        cout << "Moves: ";
        for(int i=0;i<moves.size();i++){
            cout << moves[i].first << " (Power:" << moves[i].second << ")";
            if(i!=moves.size()-1)
                cout << ", ";
        }
        cout << endl;
    }


    int getMovePower(int index){
        return moves[index].second; 
    }


    string getMoveName(int index){
        return moves[index].first;
    }


    void damageTaken(int damage){
        hp-=damage;
        if(hp<=0)
        hp=0;
    }


    bool isFainted(){
        return hp<=0;
    }


};



double getTypeMultiplier(string attackerElement,string defenderElement){
            if(attackerElement=="Water" && defenderElement=="Fire")
            return 2.0;
              if(attackerElement=="Fire" && defenderElement=="Air")
            return 2.0;
              if(attackerElement=="Air" && defenderElement=="Earth")
            return 2.0;
              if(attackerElement=="Earth" && defenderElement=="Water")
            return 2.0;
              if(attackerElement=="Fire" && defenderElement=="Water")
            return 0.5;
              if(attackerElement=="Air" && defenderElement=="Fire")
            return 0.5;
              if(attackerElement=="Earth" && defenderElement=="Air")
            return 0.5;
              if(attackerElement=="Water" && defenderElement=="Earth")
            return 0.5;

            
            return 1.0;
    }




class Duel{
public:
Bender &b1;
Bender &b2;
int turns;
int criticalHits;
int superEffectiveHits;



Duel(Bender &bender1, Bender &bender2): b1(bender1), b2(bender2){
    turns=0;
    criticalHits=0;
    superEffectiveHits=0;
}



void attack(Bender &attacker,Bender &defender,int moveIndex){
    string moveName=attacker.getMoveName(moveIndex);
    int movePower=attacker.getMovePower(moveIndex);


    cout << attacker.name << " used "<< moveName << "!\n";


    double baseDamage=(double)(attacker.attack*movePower)/defender.defense;


    double typeMultiplier=getTypeMultiplier(attacker.element,defender.element);

    if(typeMultiplier==2.0){
        cout << "Super Effecticve! ("<< attacker.element << " is strong against "<< defender.element<< ")\n";
        superEffectiveHits++;
    }


     else if (typeMultiplier == 0.5) {
    cout << "Not very effective. ("<< attacker.element<< " is weak against "<< defender.element<< ")\n";
        }


        bool critical=(rand()%10==0);

        double criticalMultiplier;

        if(critical){
            cout << "Critical Hits!\n";
            criticalHits++;
            criticalMultiplier=2.0;
        }



        else
        criticalMultiplier=1.0;


        double finalDamage=baseDamage*typeMultiplier*criticalMultiplier;


        int damage=max(1,(int)round(finalDamage));


        defender.damageTaken(damage);
        cout << defender.name << " HP: " << defender.hp << "/" << defender.maxHp<< endl << endl;



}



void start_duel(){
    cout << "\n=== DUEL BEGINS! ===\n";
    cout << b1.name << " ("<< b1.element<< ", HP: " << b1.hp << "/" << b1.maxHp <<") VS ";
    cout << b2.name << " (" << b2.element << " , HP: " << b2.hp << "/" << b2.maxHp << ")" << endl << endl;




    Bender *first;
    Bender *second;



    if(b1.speed>b2.speed){
        first=&b1;
        second=&b2;
        cout << "Turn 1: " << first->name << " goes first! (Speed: "<< first->speed << " vs " << second->speed << ")"<< endl << endl;
    }




   else if(b1.speed<b2.speed){
        first=&b2;
        second=&b1;
        cout << "Turn 1: " << first->name << " goes first! (Speed: "<< first->speed << " vs " << second->speed << ")"<< endl << endl;
    }



    else{
        if(rand()%2==0){
             first=&b1;
        second=&b2;
        cout << "Turn 1: " << first->name << " goes first! (Speed: "<< first->speed << " vs " << second->speed << ")"<< endl << endl;
    }
    else{
         first=&b2;
        second=&b1;
        cout << "Turn 1: " << first->name << " goes first! (Speed: "<< first->speed << " vs " << second->speed << ")"<< endl << endl;
        }
    }



    while(!first->isFainted() && !second->isFainted()){
        turns++;


        int move1;
        cout << "Turn " << turns << ": " << first->name << "attacks!\n";
        first->displayStats();
        cout << "Enter move index(0-3):";
        cin >> move1;
        cout << endl;
        attack(*first,*second,move1);
        if(second->isFainted()){
            cout << second->name << " fainted!\n";
            break;
        }


        turns++;
        int move2;
        cout << "Turn " << turns << ": " << second->name << " strikes back!\n";
        second->displayStats();
        cout << "Enter move index(0-3):";
        cin >> move2;
        cout << endl;
        attack(*second,*first,move2);
        if(first->isFainted()){
            cout << first->name << " fainted!\n";
            break;
        }
    }




    Bender *winner;
    if(b1.isFainted())
    winner=&b2;
    else
    winner=&b1;





    cout << "Hurray!!!!" << winner->name << " wins the duel!\n";
    cout << "\nDuel Summary:\n";
    cout << "- Winner: " << winner->name<< endl;
    cout << "-Turns: " << turns << endl;
    cout << "-Critical Hits: " << criticalHits << endl;
    cout << "- Super Effective Hits: " << superEffectiveHits << endl;
}
};
int main(){
    Bender kael("Kael","Fire",100,58,38,88,{{"Ember Slash",40},{"Quick Jab",30},{"Focus",0},{"Flame Surge",70}});
    Bender mira("Mira","Water",92,50,45,60,{{"Water Whip",35},{"Tide Push",25},{"Mist Veil",0},{"Tidal Wave",60}});
    Bender zephyr("Zephyr","Air",28,12,50,95,{{"Gust",0},{"Wind Slap",18},{"Tumble",12},{"Cyclone",22}});
    Bender doran("Doran","Earth",145,80,75,40,{{"Boulder Throw",75},{"Rock Fist",42},{"Tremor",48},{"Mountain Crush",85}});





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



            
            Duel duel(*b1,*b2);
            duel.start_duel();
    return 0;

}
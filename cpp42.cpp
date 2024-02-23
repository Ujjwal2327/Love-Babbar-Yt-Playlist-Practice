/*
object
entity having two things- state/ property and behaviour
instance of class

OOPS
programming technique that revolves around object that leads to increase the readability, extensibility, etc

class
user defined data type
a kind of template
takes memory

*/

#include<iostream>
#include "cpp42_2.cpp"
using namespace std;

class hero{
    // properties or data members
    char name[100];
    char move;

    public:

    int health;
    char level;

    void print(){
        cout<<name<<'\n';
    }

    // getter
    char getmove(){
        return move;
    }
    
    int getHealth(){
        return health;
    }
    
    char getLevel(){
        return level;
    }

    // setter
    void setmove(char m){
        move=m;
    }
    
    void setmove2(char m){      //here now condition is applied that only hero with name Ujjwal can change the move
        if(name=="Ujjwal")
            move=m;
    }

    void setName(char *n, int num){
        for(int i=0; i<num; i++){
            name[i]=n[i];
        }
        name[num]='\0';
    }
};

class emptyhero{
    // no properties
};

class hero2{
    public:
    hero2(){
        cout<<"default constructor of hero2 class is called\n";
    }
};

int main(){

    hero h1;    //instanciate of an object of class / type hero
    //ek hero type ka object bna diya
    // here now it has gv in all of its properties

    cout<<"size of h1 (object) is "<<sizeof(h1)<<'\n';
    cout<<"size of hero (class) is "<<sizeof(hero)<<'\n';
    cout<<"address of h1 (object) is "<<&(h1)<<'\n';
    // cout<<"address of hero (class) is "<<&(hero)<<'\n';      //will give ERROR
    cout<<'\n';

    emptyhero h2;
    cout<<"size of h2 (object) is "<<sizeof(h2)<<'\n';
    cout<<"size of emptyhero (class) is "<<sizeof(emptyhero)<<'\n';
    cout<<"address of h2 (object) is "<<&(h2)<<'\n';
    // just for identification and keeping track of class and object, they get 1 byte
    cout<<'\n';

    newhero h3;
    cout<<"size of h3 (object) is "<<sizeof(h3)<<'\n';      //HOW 108????   because of padding
    cout<<"size of newhero (class) is "<<sizeof(newhero)<<'\n';
    cout<<'\n';

    // access properties or data members using dot operator(.)
    /*
    access modifiers
    public
    can access anywhere

    private (by default)
    can only access inside that class

    protected

    */
    // cout<<"name: "<<h1.name<<'\n';       //only name is private
    cout<<"h1.health: "<<h1.health<<'\n';   // both have gv
    cout<<"h1.level: "<<h1.level<<'\n';     // both have gv
    cout<<'\n';

    h1.health=70;
    h1.level='A';
    cout<<"h1.level: "<<h1.level<<'\n';
    cout<<"h1.health: "<<h1.health<<'\n';
    cout<<'\n';

    /*
    getter / setter
    for accessing the private properties and data members

    */

    cout<<"h1 move is "<<h1.getmove()<<" (gv)"<<'\n';
    h1.setmove('K');
    cout<<"h1 move is "<<h1.getmove()<<'\n';
    // h1.setName("Ujjwal", 6);
    // cout<<"h1 name is "<<h1.getmove()<<'\n';
    // h1.setmove2('P');
    // cout<<"h1 move is "<<h1.getmove()<<'\n';
    cout<<'\n';

    // dynamic allocation
    hero*h4= new hero;
    cout<<"size of *h4 (object) is "<<sizeof(*h4)<<'\n';
    cout<<"size of hero (class) is "<<sizeof(hero)<<'\n';
    cout<<"address of *h4 (object) is h4 is "<<h4<<'\n';
    cout<<"(*h4).level: "<<(*h4).level<<'\n';           // gv
    cout<<"(*h4).health: "<<(*h4).health<<'\n';         // gv
    cout<<"h4->level: "<<h4->level<<'\n';               // gv
    cout<<"h4->getHealth(): "<<h4->getHealth()<<'\n';   // gv
    cout<<"h4->getmove(): "<<h4->getmove()<<'\n';       // gv
    cout<<'\n';

    /*
    at time of object creation-> constructor calling
    consturctor->   invoke at the time of object creation
                    no return type
                    no input parameter
    hero h1;    it calls h1.hero() function
                when you make a class, the constructor with its same class name is created by default and h1.hero() is a default constructor

    */

    // statically
    hero2 h5;
    cout<<'\n';
    // hero2() h6;
    cout<<'\n';

    // dynamically
    hero2*h7= new hero2;
    cout<<'\n';
    hero2*h8= new hero2();
    cout<<'\n';

    


    /*
    HOMEWORK
    padding
    greedy alignment

    */

    return 0;
}
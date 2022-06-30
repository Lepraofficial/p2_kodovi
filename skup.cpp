#include <iostream>

using namespace std;

class Skup {
     int* niz;
     int kapacitet, popunjeno;

    public:

    Skup(int kap = 10):kapacitet(kap), popunjeno(0){
        niz = new int[kapacitet];
    }

    ~Skup(){delete[]niz;};
    Skup(const Skup& org){
        kapacitet= org.kapacitet;
        popunjeno = org.popunjeno;

        niz = new int[kapacitet];

        for(int i(0);i<popunjeno;i++){
           niz[i] = org.niz[i];
        }

    };

    void operator=(const Skup &org){
        kapacitet= org.kapacitet;
        popunjeno = org.popunjeno;
        delete [] niz;
        niz = new int[kapacitet];

        for(int i(0);i<popunjeno;i++){
           niz[i] = org.niz[i];
        }
    };

    void dodaj(int novi){
        if(popunjeno >= kapacitet){
            cout<<"popunjen skup"<<endl;
        }
        else{
            niz[popunjeno] = novi;
            popunjeno++;
        }
    };

    friend bool imal(Skup s, int el){
        for(int i(0); i<s.popunjeno;i++){
            if(s.niz[i] == el) return true;
        }
        return false;
    }

    void dodajAkoNema(int el){
        for( int i(0);i<popunjeno+1;i++){
            if(el == niz[i] && !(popunjeno == 0)) break;
            if(i == popunjeno) {dodaj(el); break;};
        }
    };

    void ispisi(){
        cout<<"{"<<niz[0]<<", ";
        for(int i(1); i<popunjeno;i++){
            cout<<niz[i]<<", ";
        }
        cout<<"}";
    };

    friend void presjek(Skup s1, Skup s2){
        Skup novi(s1.popunjeno + s2.popunjeno + 5);

        for(int i(0);i<s1.popunjeno;i++){
            for(int j(0);j<s2.popunjeno;j++){
                if(s1.niz[i] == s2.niz[j]) novi.dodajAkoNema(s1.niz[i]);
            }
        }

        novi.ispisi();
    };

    friend void unija(Skup s1, Skup s2) {
        Skup novi(s1.popunjeno + s2.popunjeno + 5);

        for( int i(0); i<s1.popunjeno;i++){novi.dodajAkoNema(s1.niz[i]);}
        for( int i(0); i<s2.popunjeno;i++){novi.dodajAkoNema(s2.niz[i]);}

        novi.ispisi();
    }

    friend void razlika(Skup s1, Skup s2){
    Skup novi(s1.popunjeno + s2.popunjeno + 5);

        for(int i(0);i<s1.popunjeno;i++){
            for(int j(0);j<s2.popunjeno;j++){
                if(s1.niz[i] == s2.niz[j]) novi.dodajAkoNema(s1.niz[i]);
            }
        }

    Skup razlikaa(s1.popunjeno + s2.popunjeno + 5);

    for(int i(0);i<s1.popunjeno;i++){
            if(!imal(novi, s1.niz[i])) razlikaa.dodajAkoNema(s1.niz[i]);
        }
    for(int i(0);i<s2.popunjeno;i++){
            if(!imal(novi, s2.niz[i])) razlikaa.dodajAkoNema(s2.niz[i]);
        }
    razlikaa.ispisi();
    };


};

int main(){
    Skup prvi, drugi(5);

    for(int i(0);i<10;i++){prvi.dodaj(i);}
    prvi.ispisi(); cout<<endl;
    for(int i(4);i<8;i++){drugi.dodaj(i);}
    drugi.dodaj(12);
    drugi.dodaj(14);

    drugi.ispisi(); cout<<endl;
    cout<<endl<<"------------------"<<endl<<"presjek: ";
    presjek(prvi, drugi);
    cout<<endl<<"------------------"<<endl<<"unija: ";
    unija(prvi, drugi);

    cout<<endl<<"------------------"<<endl<<"razlika: ";
    razlika(prvi, drugi);

}

#include <iostream>
#include <cstring>

using namespace std;

class Website{
private:
    char ime[50];
    char domain[50];
    int posetiteli;
public:
    Website(){

    }

    Website(char *_ime,char *_domain,int _posetiteli){
        strcpy(ime,_ime);
        strcpy(domain,_domain);
        posetiteli=_posetiteli;
    }
    ~Website(){}

    void setName(char *_ime){
        strcpy(ime,_ime);
    }
    void setDomain(char *_domain){
        strcpy(domain,_domain);
    }
    void setVisitors(int _posetiteli){
        posetiteli=_posetiteli;
    }
    char *getIme(){
        return ime;
    }
    char *getDomain(){
        return domain;
    }
    int getVisitors(){
        return posetiteli;
    }

    void print(){
        cout<<"Name: www."<<ime<<"."<<domain<<endl;
        cout<<"Visitors: "<<posetiteli<<endl;
    }
};

void bestWebsite(Website *sites,int n){
    int i,max=0,I;
    for(i=0;i<n;i++){
        if(sites[i].getVisitors()>max){
            max=sites[i].getVisitors();
            I=i;
        }
    }
    sites[I].print();
}

/*
 * DA NE SE PRAVAT PROMENI VO MAINOT !
 */
int main() {
    int n;
    cin >> n;

    Website sites[100];

    for(int i = 0; i < n-1; i++) {
        char name[50], domain[10];
        int visitors;

        cin >> name >> domain >> visitors;
        sites[i] = Website(name, domain, visitors);
    }

    cout << "-- PASSED REGULAR INPUT --" << "\n\n";
    cout << "-- Testing set & print methods --" << "\n";

    char name[50], domain[10];
    int visitors;
    cin >> name >> domain >> visitors;

    sites[n-1] = Website();
    sites[n-1].setName(name);
    sites[n-1].setDomain(domain);
    sites[n-1].setVisitors(visitors);

    sites[n-1].print();
    cout << "\n";

    cout << "-- Testing bestWebsite function --" << '\n';

    bestWebsite(sites, n);

    return 0;
}

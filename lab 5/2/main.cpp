#include <iostream>
#include <cstring>
using namespace std;

//your code here

enum s{
    neispraven,sePoprava,ispraven
};

class Airplane{
private:
    char registracija[16];
    char *imeKompaniija;
    char aerodrom[20];
    int sostojba;
    int casovi;

    void copy(const Airplane &other){
        strcpy(this->registracija,other.registracija);
        this->imeKompaniija = new char[strlen(other.imeKompaniija)+1];
        strcpy(imeKompaniija,other.imeKompaniija);
        strcpy(aerodrom,other.aerodrom);
        this->casovi = other.casovi;
        this->sostojba = other.sostojba;
    }
public:
    Airplane(char *registracija="", char *imeKompanija="", char *aerodrom="", int casovi=0, int sostojba=0){
        strcpy(this->registracija,registracija);
        this->imeKompaniija = new char[strlen(imeKompanija)+1];
        strcpy(this->imeKompaniija,imeKompanija);
        strcpy(this->aerodrom,aerodrom);
        this->sostojba=sostojba;
        this->casovi=casovi;
    }
    Airplane(const Airplane &other){
        copy(other);
    }
    Airplane &operator = (const Airplane &other){
        if(this!=&other){
            delete [] imeKompaniija;
            copy(other);
        }
        return *this;
    }
    void print(){
        cout<<"ID: "<<registracija<<" - ";
        if(sostojba==0){
            cout<<"NOT_WORKING ";
        }
        else if(sostojba==1){
            cout<<"REPAIRING ";
        }
        else if(sostojba==2){
            cout<<"WORKING ";
        }
        cout<<imeKompaniija<<", "<<casovi<<", "<<aerodrom<<endl;
    }
    int getSostojba(){
        return sostojba;
    }
    void setSostojba(int _sostojba){
        this->sostojba = _sostojba;
    }
    bool istaKompanija(const Airplane &other){
        if(strcmp(this->imeKompaniija,other.imeKompaniija)==0){
            return true;
        }
        return false;
    }
    bool povekecasovilet(const Airplane &other){
        if(this->casovi > other.casovi){
            return true;
        }
        return false;
    }
    int getCasovi(){
        return casovi;
    }
    char *getIme(){
        return aerodrom;
    }

};

class AirportService{
private:
    char imeAerodrom[20];
    Airplane *niza;
    int n;

    void copy(const AirportService &other){
        strcpy(this->imeAerodrom,other.imeAerodrom);
        this->n = other.n;
        this->niza = new Airplane[other.n];
        for(int i=0;i<n;i++){
            this->niza[i] = other.niza[i];
        }
    }
public:
    AirportService(char *imeAerodrom="", int n=0, Airplane *niza=0){
        strcpy(this->imeAerodrom,imeAerodrom);
        this->n = n;
        this->niza = new Airplane[n];
        for(int i=0;i<n;i++){
            this->niza[i] = niza[i];
        }
    }
    AirportService(const AirportService &other){
        copy(other);
    }
    AirportService & operator =(const AirportService &other){
        if(this!=&other){
            delete [] niza;
            copy(other);
        }
        return *this;
    }
    void addAirplane(Airplane plane){
        if(plane.getSostojba() != 0){
            return;
        }
        bool najden = false;
        for(int i=0;i<n;i++){
            if(niza[i].istaKompanija(plane)){
                najden = true;
                if(niza[i].povekecasovilet(plane)==false){
                    plane.setSostojba(1);
                    niza[i] = plane;
                }
            }
        }
        if(najden==false){
            Airplane *tmp = new Airplane[n+1];
            for(int i=0;i<n;i++){
                tmp[i] = niza[i];
            }
            plane.setSostojba(1);
            tmp[n++] = plane;
            delete [] niza;
            niza = tmp;
        }
    }
    Airplane serviceOldestAirplane(){
        int max,I;
        for(int i=0;i<n;i++){
            if(i==0){
                max = niza[i].getCasovi();
                I=i;
            }
            else if(niza[i].getCasovi()>max){
                max = niza[i].getCasovi();
                I=i;
            }
            else if(niza[i].getCasovi()==max && strcmp(imeAerodrom, niza[i].getIme())==0){
                max = niza[i].getCasovi();
                I=i;
            }
        }
        niza[I].setSostojba(2);
        Airplane *tmp2 = new Airplane[n];
        for(int i=0;i<n;i++){
            tmp2[i] = niza[i];
        }
        //return niza[I]; //important
        Airplane *tmp = new Airplane[n-1];
        int j=0;
        for(int i=0;i<n;i++){
            if(i!=I){
                tmp[j++] = niza[i];
            }
        }
        n--;
        delete [] niza;
        niza = tmp;
        return tmp2[I];
    }
    void print(){
        cout<<imeAerodrom<<endl;
        for(int i=0;i<n;i++){
            niza[i].print();
        }
    }
};
int main() {
    int testCase;
    cin >> testCase;
    char ID[12];
    char company_name[20];
    char company_airport[20];
    int flight_hours;
    int state;
    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR AIRPLANE" << endl;
        Airplane a;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Airplane a2("ZHN-96-TA", "FINKI1-Airline", "TMF", 13, 0);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR AIRPLANE" << endl;
        Airplane p("ZHN-96-TA", "FINKI-Airline", "TMF", 13, 0);
        Airplane p1(p);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Airplane p2;
        p2 = p;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING PRINT() FOR AIRPLANE" << endl;
        cin>>ID>>company_name>>company_airport>>flight_hours>>state;
        Airplane p(ID, company_name, company_airport, flight_hours, state);
        p.print();
    } else if (testCase == 4) {
        cout << "TESTING CONSTRUCTOR FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING ADD() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        as.print();
    } else if (testCase == 6) {
        cout << "TESTING serviceOldestAirplane() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        Airplane p = as.serviceOldestAirplane();
        cout<<"Removed plane:"<<endl;
        p.print();
        cout<<"-----------------"<<endl;
        as.print();
    }  else if (testCase == 7) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        as.addAirplane(a1);

        AirportService s1 = as; //copy constructor
        AirportService s2;
        s2 = s1; //operator =
        s1.print();
        s2.print();
    }
    return 0;
}
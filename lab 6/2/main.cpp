#include <iostream>
#include <cstring>
using namespace std;

class RealEstate {
private:
    char *adress;
    int *id;
    int kvadratura;
public:
    RealEstate(){
        adress= nullptr;
        id= nullptr;
    }


    RealEstate(char *adress, int *id ,int kvadratura){
        this->adress = new char [strlen(adress)+1];
        strcpy(this->adress,adress);
        this->kvadratura=kvadratura;
        this->id =new int [5];
        for (int i = 0; i < 5; ++i) {
            this-> id[i] = id[i];
        }
    }
    RealEstate(RealEstate const &re){
        this->adress = new char [strlen(re.adress)+1];
        strcpy(this->adress,re.adress);
        this->kvadratura=re.kvadratura;
        this->id = new int [5];
        for (int i = 0; i < 5; ++i) {
            this->id[i] = re.id[i];
        }
    }

    RealEstate &operator=(RealEstate const &re){
        if (this != &re){
            delete [] adress;
            delete [] id;
            this->adress = new char [strlen(re.adress)+1];
            strcpy(this->adress,re.adress);
            this->kvadratura=re.kvadratura;
            this->id =new int [5];
            for (int i = 0; i < 5; ++i) {
                this->id[i] = re.id[i];
            }
        }
        return *this;
    }

    bool operator == (RealEstate &re){
        for (int i = 0; i < 5; ++i) {
            if (id[i] != re.id[i]){
                return false;
            }
        }
        return true;
    }

    friend  ostream &operator<<(ostream &out,const RealEstate &re){
        out<<"Address: "<<re.adress<< " id: [ ";

        for (int i = 0; i < 5; ++i) {
            out<<re.id[i]<<" ";
        }
        out<<"]"<<endl;
        return out;
    }

    ~RealEstate(){
        delete [] adress;
        delete [] id;
    }

    int getKV(){
        return kvadratura;
    }
};



class RealEstateAgency{
private:
    char name[100];
    RealEstate *niza;
    int n;

    void copy(const RealEstateAgency &rea){
        strcpy(this->name,rea.name);
        this->n = rea.n;
        for (int i = 0; i < rea.n; ++i) {
            this->niza[i] = rea.niza[i];
        }
    }

public:
    RealEstateAgency(char *name =""){
        strcpy(this->name,name);
        n=0;
        niza= nullptr;
    }
    RealEstateAgency(const RealEstateAgency &rea){
        copy(rea);
    }
    RealEstateAgency&operator=(const RealEstateAgency &rea){
        if (this != &rea){
            delete [] niza;
            copy(rea);
        }
        return *this;
    }
    RealEstateAgency &operator +=(RealEstate &re){
        RealEstate *tmp = new RealEstate[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i]=niza[i];
        }
        tmp[n++]=re;
        delete [] niza;
        niza =tmp;
        return *this;
    }

    RealEstateAgency &operator -=(RealEstate &re){
        int I;
        RealEstate *tmp =new RealEstate [n-1];
        for (int i = 0; i < n; ++i) {
            if (re == niza[i]){
                I=i;
            }
        }
        int j=0;
        for (int i = 0; i < n; ++i) {
            if (I != i){
                tmp[j++]=niza[i];
            }
        }
        n--;
        delete[]niza;
        niza=tmp;
        return *this;
    }

    friend ostream &operator <<(ostream &out, RealEstateAgency &real){
        out<<real.name<<endl;
        for (int i = 0; i < real.n; ++i) {
            out<<real.niza[i];
        }
        return out;
    }
    void printAboveSize(int size){
        cout<<name<<endl;
        for (int i = 0; i < n; ++i) {
            if (niza[i].getKV()>size){
                cout<<niza[i];
            }
        }
    }

};
int main()
{
    int testCase;

    cin>>testCase;

    if(testCase==1){
        cout<<"TESTING REALESTATE CLASS CONSTRUCTORS"<<endl;
        int id[5];
        id[0]=3;
        id[1]=6;
        id[2]=2;
        id[3]=1;
        id[4]=6;
        RealEstate realEstate = RealEstate("Address 1/21", id , 200);

        cout<<realEstate;

        cout<<"TESTING REALESTATE CLASS OPERATORS"<<endl;

        RealEstate realEstate1 = RealEstate("Address 1/23", id , 250);
        if(realEstate==realEstate1){
            cout<<realEstate;
        }
        else{
            cout<<"Ne se isti nedviznini";
        }
    }
    else if(testCase==2){
        cout<<"TESTING REALESTATE CLASS CONSTRUCTORS"<<endl;
        int id[5];
        id[0]=3;
        id[1]=6;
        id[2]=2;
        id[3]=1;
        id[4]=6;
        RealEstate realEstate = RealEstate("Address 1/21", id , 200);

        cout<<realEstate;

        cout<<"TESTING REALESTATE CLASS OPERATORS"<<endl;

        id[3]=2;

        RealEstate realEstate1 = RealEstate("Address 1/23", id , 250);
        if(realEstate==realEstate1){
            cout<<realEstate;
        }
        else{
            cout<<"Ne se isti nedviznini";
        }
    }
    else if(testCase==3){
        RealEstateAgency agencija("RealEstate-FINKI");
        int n;
        cin>>n;

        for (int i=0;i<n;i++)
        {
            char address[100];
            int id[5];
            int sqFeet;

            cin >> address;

            for (int j=0;j<5;j++)
                cin >> id[j];

            cin >> sqFeet;

            RealEstate nov=RealEstate(address, id, sqFeet);

            //dodavanje na nedviznina
            agencija+=nov;

        }

        cout<<"TESTING REALESTATEAGENCY OPERATOR += AND PRINTALL METHOD"<<endl;

        cout<<agencija;
    }
    else if(testCase==4){
        RealEstateAgency agencija("RealEstate-FINKI");
        int n;
        cin>>n;

        for (int i=0;i<n;i++)
        {
            char address[100];
            int id[5];
            int sqFeet;

            cin >> address;

            for (int j=0;j<5;j++)
                cin >> id[j];

            cin >> sqFeet;

            RealEstate nov=RealEstate(address, id, sqFeet);

            //dodavanje na nedviznina
            agencija+=nov;

        }

        cout<<"TESTING REALESTATEAGENCY OPERATOR -= AND PRINTALL METHOD"<<endl;

        //se cita grehsna nedviznina, za koj shto nedviznina so ista id treba da se izbrishe
        char address[100];
        int id[5];
        int sqFeet;
        cin >> address;
        for (int i=0;i<5;i++)
            cin >> id[i];
        cin >> sqFeet;

        RealEstate greshka=RealEstate(address, id, sqFeet);

        //brishenje na nedviznina
        agencija-=greshka;

        cout<<agencija;
    }
    else if(testCase==5){
        RealEstateAgency agencija("RealEstate-FINKI");
        int n;
        cin>>n;

        for (int i=0;i<n;i++)
        {
            char address[100];
            int id[5];
            int sqFeet;

            cin >> address;

            for (int j=0;j<5;j++)
                cin >> id[j];

            cin >> sqFeet;

            RealEstate nov=RealEstate(address, id, sqFeet);

            //dodavanje na nedviznina
            agencija+=nov;

        }

        cout<<"TESTING REALESTATEAGENCY OPERATOR -= AND PRINTABOVESIZE METHOD"<<endl;

        //se cita grehsna nedviznina, za koj shto nedviznina so ista id treba da se izbrishe
        char address[100];
        int id[5];
        int sqFeet;
        cin >> address;
        for (int i=0;i<5;i++)
            cin >> id[i];
        cin >> sqFeet;

        RealEstate greshka=RealEstate(address, id, sqFeet);

        //brishenje na nedviznina
        agencija-=greshka;

        agencija.printAboveSize(60);
    }
}



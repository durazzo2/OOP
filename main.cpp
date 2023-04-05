#include <iostream>
#include <cstring>

using namespace std;

class DisciplinaryAction{
private:
    char *ime;
    int index;
    char *prichina;

    void copy(const DisciplinaryAction &dp){
        this->ime = new char [strlen(dp.ime)+1];
        strcpy(this->ime,dp.ime);
        this->prichina=new char [strlen(dp.prichina)+1];
        strcpy(this->prichina,dp.prichina);
        this->index=dp.index;
    }
public:
    DisciplinaryAction(char *ime="",int _index=0,char *prichina=""){
        index=_index;
        this->ime = new char [strlen(ime)+1];
        strcpy(this->ime,ime);
        this->prichina=new char [strlen(prichina)+1];
        strcpy(this->prichina,prichina);
    }
    DisciplinaryAction(const DisciplinaryAction & dp){
        copy(dp);
    }
    DisciplinaryAction & operator= (const DisciplinaryAction & dp){
        if(this!=&dp){
            delete [] ime;
            delete [] prichina;
            copy(dp);
        }
        return *this;
    }
    ~DisciplinaryAction(){
        delete [] ime;
        delete [] prichina;
    }
    void setIndex(int index){
       this-> index = index;
    }
    int getIndex(){
        return index;
    }

     void print(){
        cout<<"Student: "<<ime<<endl;
        cout<<"Student's index: "<<index<<endl;
        cout<<"Reason: "<<prichina<<endl;
    }


};


/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}
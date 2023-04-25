#include <iostream>
#include <cstring>
using namespace std;

class DisciplinaryAction{
private:
    char *name;
    int index;
    char *reason;
    int restrictions;

public:
    DisciplinaryAction(){}
    DisciplinaryAction(char* n, int i, char* r, int rest){
        name = new char[strlen(n)+1];
        strcpy(name,n);
        reason = new char[strlen(r)+1];
        strcpy(reason,r);
        index = i;
        restrictions = rest;
    }
    DisciplinaryAction(DisciplinaryAction &other){
        name = new char[strlen(other.name)+1];
        strcpy(name,other.name);
        reason = new char[strlen(other.reason) + 1];
        strcpy(reason,other.reason);
        index = other.index;
        restrictions = other.restrictions;
    }
    ~DisciplinaryAction(){};

    //operators
    DisciplinaryAction& operator=(const DisciplinaryAction &other){
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name,other.name);
        this->reason = new char[strlen(other.reason) +1];
        strcpy(this->reason,other.reason);
        this->index = other.index;
        this->restrictions = other.restrictions;
        return *this;
    }
    DisciplinaryAction& operator++(){
        restrictions = restrictions + 1;
        return *this;
    }

    bool operator>=(const DisciplinaryAction &x){
        return restrictions>=x.restrictions;
    }


    //get
    int getIndex(){
        return index;
    }
    //set
    void setIndex(int i){
        index = i;
    }
    //methods
    void print(){
        cout<<"Student: "<<name<<endl;
        cout<<"Student's index: "<<index<<endl;
        cout<<"Reason: "<<reason<<endl;
        cout<<"Sessions: "<<restrictions<<endl;
    }


};

ostream& operator<<(ostream& os, DisciplinaryAction &x){
    x.print();
    return os;
}

// 1
int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}
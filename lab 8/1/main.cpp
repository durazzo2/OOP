#include <iostream>
using namespace std;

class Room{
public:
    virtual void displayRoomInfo()=0;
    virtual  void displayRoomPrice()=0;
};
class StandardRoom:public Room{
private:
    bool hasBathroom;
public:
    StandardRoom(bool hasBathroom=false){
        this->hasBathroom=hasBathroom;
    }
    void displayRoomInfo(){
        cout<<"This is a standard room with a queen-sized bed";
        if(hasBathroom)cout<<" and a bathroom";
        cout<<"."<<endl;
    }
    void displayRoomPrice(){ cout<<"The price for a standard room is ";
        if(hasBathroom)cout<<"$100";
        else cout<<"$80";
        cout<<" per night."<<endl;
    }
};
class DeluxeRoom:public Room{
private:
    bool hasBalcony;
public:
    DeluxeRoom(bool hasBalcony=false){
        this->hasBalcony=hasBalcony;
    }
    void displayRoomInfo(){
        cout<<"This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge";
        if(hasBalcony)cout<<" and a balcony"; cout<<"."<<endl;
    }
    void displayRoomPrice(){
        cout<<"The price for a deluxe room is ";
        if(hasBalcony)cout<<"$200";
        else cout<<"$160";
        cout<<" per night."<<endl;
    }
};


// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    Room* rooms[5];

    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "TEST CASE 1: TESTING STANDARD ROOM CLASS" << endl;

        for (int i = 0; i < 5; i++) {
            rooms[i] = new StandardRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else if (testCase == 2) {
        cout << "TEST CASE 2: TESTING DELUXE ROOM CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            rooms[i] = new DeluxeRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else {
        cout << "TEST CASE 3: TESTING BOTH CLASSES" << endl;
        for (int i = 0; i < 5; i++) {
            if (i % 2) {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new DeluxeRoom(hasBalcony);
            }
            else {
                bool hasBathroom;
                cin >> hasBathroom;
                rooms[i] = new StandardRoom(hasBathroom);
            }
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    }

    return 0;
}
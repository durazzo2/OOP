
#include <iostream>
#include <cstring>
using namespace std;

class Accommodation{
protected:
    char *type;
    int num;

    void copy(const Accommodation &other){
        this->num = other.num;
        this->type = new char [strlen(other.type) + 1];
        strcpy(this->type,other.type);
    }
public:
    Accommodation(char *type="", int num=0){
        this->num = num;
        this->type = new char [strlen(type) + 1];
        strcpy(this->type,type);
    }
    virtual float getPrice() = 0;

    virtual char *getType(){
        return type;
    }

    virtual int getNum(){
        return num;
    }

    bool operator >(Accommodation &a){
        return (getPrice() > a.getPrice());
    }

    virtual ~Accommodation(){
        delete [] type;
    }
};

class HotelRoom : public Accommodation{
private:
    int numBeds;
    float pricePerBed;

    void copy(const HotelRoom &other){
        Accommodation::copy(other);
        this->numBeds = other.numBeds;
        this->pricePerBed = other.pricePerBed;
    }
public:
    HotelRoom(char *type = "", int num = 0, int numBeds = 1, float pricePerBed = 1.0)
    :Accommodation(type,num){
        this->numBeds = numBeds;
        this->pricePerBed = pricePerBed;
    }
    HotelRoom(const HotelRoom &other){
        copy(other);
    }
    float getPrice(){
        return numBeds * pricePerBed; //mojt da trebit uste *num ama ce vidime tamu
    }
    ~HotelRoom(){}
};
class Apartment : public Accommodation{
private:
    int numRooms;
    int pricePerRoom;

    void copy(const Apartment &other){
        Accommodation::copy(other);
        this->numRooms = other.numRooms;
        this->pricePerRoom = other.pricePerRoom;
    }
public:
    Apartment(char *type = "", int num = 0, int numRooms = 1, int pricePerRoom = 1)
    : Accommodation(type,num){
        this->numRooms = numRooms;
        this->pricePerRoom = pricePerRoom;
    }
    Apartment(const Apartment &other){
        copy(other);
    }
    float getPrice(){
        return pricePerRoom * numRooms;
    }
};

Accommodation *getMaxAccommodation(Accommodation **pAcc, int n){
    Accommodation *max = pAcc[0];
//    for(int i=0;i<n;i++){
//        if(*(pAcc[i]) > *max){
//            max = pAcc[i];
//        }
//    }
    for(int i=1;i<n;i++){
        if((pAcc[i]->getPrice()) > max->getPrice()){
            max = pAcc[i];
        }
    }
    return max;
}
int main() {
    Accommodation *p;
    int n;
    cin >> n;

    char type[30];
    int size;
    int numBeds, numRooms;
    float pricePerBed, pricePerRoom;

    Accommodation *items[n];

    for (int i = 0; i < n; ++i) {
        cin >> type;
        cin >> size;


        if (strcmp(type, "HotelRoom") == 0) {
            cin >> numBeds;
            cin >> pricePerBed;

            items[i] = new HotelRoom(type, size, numBeds, pricePerBed);
        } else {
            cin >> numRooms;
            cin >> pricePerRoom;

            items[i] = new Apartment(type, size, numRooms, pricePerRoom);
        }


    }

    Accommodation *it = getMaxAccommodation(items, n);
    cout << "Type: " << it->getType() << endl;
    cout << "The max price is: " << it->getPrice() << endl;
    cout << "Rooms available: " << it->getNum() << endl;
    return 0;
}
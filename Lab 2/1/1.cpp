#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class BasketballPlayer{
private:
    char name[100];
    char surname[100];
    int jerseyNumber;
    int firstGamePoints;
    int secondGamePoints;
    int thirdGamePoints;

public:
    BasketballPlayer(char * name,char* surname,int jerseyNumber,int firstGamePoints,
                     int secondGamePoints,int thirdGamePoints){

        strcpy(this->name, name);
        strcpy(this->surname,surname);
        this->jerseyNumber=jerseyNumber;
        this->firstGamePoints=firstGamePoints;
        this->secondGamePoints=secondGamePoints;
        this->thirdGamePoints=thirdGamePoints;
    }
    string getName(){
        return name;
    }
    string getSurname(){
        return surname;
    }
    int getJerseyNumber(){
        return jerseyNumber;
    }
    int getFirstGamePoints(){
        return firstGamePoints;
    }
    int getSecondGamePoints(){
        return secondGamePoints;
    }
    int getThirdGamePoints(){
        return thirdGamePoints;
    }
    double getAveragePoints(){
        return (firstGamePoints + secondGamePoints + thirdGamePoints)/3.0;
    }

    void printPlayerInfo(){
        cout<<"Player: "<<name<<" "<<surname<<" "<<"with number: "<<getJerseyNumber()<<" has "<<getAveragePoints()<<" points on average"<<endl;
    }
};

int main (){

    char name[100];
    char surname[100];
    int jerseyNumber,firstGamePoints,secondGamePoints,thirdGamePoints;

    cin>>name;
    cin>>surname;

    cin>>jerseyNumber;
    cin>>firstGamePoints;
    cin>>secondGamePoints;
    cin>>thirdGamePoints;

    BasketballPlayer player (name,surname,jerseyNumber,firstGamePoints,secondGamePoints,thirdGamePoints);
    player.printPlayerInfo();


    return 0;
}

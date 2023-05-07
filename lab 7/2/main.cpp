#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer{
protected:
    char *name;
    char team[40];
    double average_points;
    double average_assists;
    double average_jumps;
public:
    NBAPlayer(){
        name = nullptr;
        strcpy(team, "");
        average_points = 0;
        average_assists = 0;
        average_jumps = 0;
    }
    NBAPlayer(char *name, char *team, double average_points, double average_assists, double average_jumps){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        strcpy(this->team, team);
        this->average_points = average_points;
        this->average_assists = average_assists;
        this->average_jumps = average_jumps;
    }
    NBAPlayer(const NBAPlayer &other){
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        strcpy(team, other.team);
        average_points = other.average_points;
        average_assists = other.average_assists;
        average_jumps = other.average_jumps;
    }
    ~NBAPlayer(){
        delete[] name;
    }

    NBAPlayer &operator=(const NBAPlayer &other){
        if(this != &other){
            delete[] name;
            name = new char[strlen(other.name)+1];
            strcpy(name, other.name);
            strcpy(team, other.team);
            average_points = other.average_points;
            average_assists = other.average_assists;
            average_jumps = other.average_jumps;
        }
        return *this;
    }

    virtual double rating(){
        return (0.45 * average_points)+(0.30 * average_assists)+(0.25 * average_jumps);
    }

    virtual void print(){
        cout << name << " - " << team << endl;
        cout << "Points: " << average_points << endl;
        cout << "Assists: " << average_assists << endl;
        cout << "Rebounds: " << average_jumps << endl;
        cout << "Rating: " << NBAPlayer::rating() << endl;
    }
};

class AllStarPlayer: public NBAPlayer{
private:
    double allStarPoints;
    double allStarAssists;
    double allStarJumps;
public:
    AllStarPlayer(): NBAPlayer(){
        allStarPoints = 0;
        allStarAssists = 0;
        allStarJumps = 0;
    }
    AllStarPlayer(char *name, char *team, double average_points, double average_assists, double average_jumps, double allStarPoints, double allStarAssists, double allStarJumps): NBAPlayer(name, team, average_points, average_assists, average_jumps){
        this->allStarPoints = allStarPoints;
        this->allStarAssists = allStarAssists;
        this->allStarJumps = allStarJumps;
    }
    AllStarPlayer(const AllStarPlayer &other): NBAPlayer(other){
        allStarPoints = other.allStarPoints;
        allStarAssists = other.allStarAssists;
        allStarJumps = other.allStarJumps;
    }
    AllStarPlayer(const NBAPlayer &other, double allStarPoints, double allStarAssists, double allStarJumps): NBAPlayer(other){
        this->allStarPoints = allStarPoints;
        this->allStarAssists = allStarAssists;
        this->allStarJumps = allStarJumps;
    }
    ~AllStarPlayer() = default;

    double allStarRating(){
        return (0.30 * allStarPoints)+(0.40 * allStarAssists)+(0.30 * allStarJumps);
    }
    double rating() override{
        return ((NBAPlayer::rating()+allStarRating()) / 2);
    }
    void print() override{
        NBAPlayer::print();
        cout << "All Star Rating: " << allStarRating() << endl;
        cout << "New Rating: " << rating() << endl;
    }
};

int main() {

    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer * players = new NBAPlayer[5];
    AllStarPlayer * asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            players[i].print();
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints,allStarAssists,allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
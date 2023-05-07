#include <iostream>
using namespace std;

class Kvadrat {
protected:
    double a;

    void copy(const Kvadrat &k) {
        a = k.a;
    }
public:
    Kvadrat(double a = 0) { this->a = a;}
    Kvadrat(const Kvadrat &k) { copy(k);}

    double Perimetar() { return 4*a;}
    double Plostina() {return a*a;}

    void pecati() {
        cout << "Kvadrat so dolzina a=" << a << " ima plostina P=" << Plostina() << " i perimetar L=" << Perimetar() << endl;
    }
};

class Pravoagolnik : public Kvadrat {
private:
    double x, y;

    void copy(const Pravoagolnik &p) {
        x = p.x;
        y = p.y;
    }
public:
    Pravoagolnik(const Kvadrat &k = Kvadrat(), double x = 0, double y = 0) : Kvadrat(k), x(x), y(y) {}

    Pravoagolnik(const Pravoagolnik &p) : Kvadrat(p) { copy(p);}

    double Plostina() {return (a + x) * (a + y);}
    double Perimetar() {return 2 * (a + x) + 2 * (a + y);}

    void pecati() {
        if((a+x) != (a+y))
            cout << "Pravoagolnik so strani: " << a+x  << " i " << a+y << " ima plostina P=" << Plostina() << " i perimetar L=" << Perimetar() << endl;
        else
            cout << "Kvadrat so dolzina a=" << a+x << " ima plostina P=" << Plostina() << " i perimetar L=" << Perimetar() << endl;
    }
};

// main za 1.
int main() {
    int n;
    double a,x,y;
    Kvadrat * kvadrati;
    Pravoagolnik * pravoagolnici;

    cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

    for (int i=0;i<n;i++){
        cin>>a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i=0;i<n;i++){
        cin>>x>>y;

        pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===Testiranje na klasata Kvadrat==="<<endl;
        for (int i=0;i<n;i++)
            kvadrati[i].pecati();
    }
    else {
        cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
        for (int i=0;i<n;i++)
            pravoagolnici[i].pecati();
    }
}

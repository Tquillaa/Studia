#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int masa_ciala;
    double wzrost;

    cout<<"Podaj mase ciala [kg]: ";
    cin>>masa_ciala;

    cout<<"Podaj wzrost [m]: ";
    cin>>wzrost;

    double BMI = masa_ciala/(wzrost * wzrost);
    
    if(BMI<16)
        cout<<"Wyglodzenie"<<endl;
        else if(BMI<17)
            cout<<"Wychudzenie"<<endl;
            else if(BMI<18.5)
                cout<<"Niedowaga"<<endl;
                else if(BMI<25)
                    cout<<"Waga prawidlowa"<<endl;
                    else if(BMI<30)
                        cout<<"Nadwaga"<<endl;
                        else if(BMI<35)
                            cout<<"I stopien otylosci"<<endl;
                            else if(BMI<40)
                                cout<<"II stopien otylosci"<<endl;
                                else cout<<"otylosc skrajna"<<endl;
    
    return 0;
}
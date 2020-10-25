#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int a, b;
    int sumaDzielA=0, sumaDzielB=0;

    cout<<"Podaj 2 liczby calkowite wieksze od 1 oddzielone spacja: ";
    cin>>a>>b;

    for(int i=1;i<=a/2;i++)
        if(!(a%i)) sumaDzielA+=i;
    if(sumaDzielA != b+1){
        cout<<"Podane liczby nie sa skojarzone"<<endl;
        return 0;
    }
    for(int i=1;i<=b/2;i++)
        if(!(b%i)) sumaDzielB+=i;
    if(sumaDzielB != a+1){
        cout<<"Podane liczby nie sa skojarzone"<<endl;
        return 0;
    }

    cout<<"Podane liczby sa skojarzone"<<endl;

    return 0;
}
#include <iostream>
using namespace std;
void pokazMacierz23(int x[2][3]){
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            cout<<x[i][j]<<" ";
    cout<<endl;
    }
}

int main(int argc, char* argv[]){
    int macierz1[2][3] = { 0 };
    int macierz2[2][3] = { 0 };

    cout<<"Podaj 6 liczb calkowitych oddzielonych spacja do wypelnienia macierzy A: ";
    for(int i=0;i<6;i++) cin>>macierz1[i/3][i%3];
    pokazMacierz23(macierz1);

    cout<<"Podaj 6 liczb calkowitych oddzielonych spacja do wypelnienia macierzy B: ";
    for(int i=0;i<6;i++) cin>>macierz2[i/3][i%3];
    pokazMacierz23(macierz2);

    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            macierz2[i][j] += macierz1[i][j];
    
    
    cout<<"Macierz po dodaniu obu: "<<endl;
    pokazMacierz23(macierz2);

    return 0;
}
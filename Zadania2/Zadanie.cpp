#include <iostream>
using namespace std;

void zadanie1(int *a, int *b){
    if(*b < *a){
        int x = *a;
        *a=*b;
        *b=x;
    }
}

void zadanie2(int &a, int &b){
    int x = b;
    b=a;
    a=x;
}

void zadanie3(int &a, int *b){
    int x = a;
    a=*b;
    *b=x;
}

int zadanie4(int &a, int b){
    int iloczyn = a*b;
    a+=b;
    return iloczyn;
}

void zadanie5(int *a, int *b){
    int x = *a;
    *a=*b;
    *b=x;
}
//zadanie6
template <class T> void swap ( T* a, T* b )
{
  T c = a; a=b; b=c;
}

int main(){

    int x,y;

    cout<<"Podaje dwie liczby calkowite oddzielone spacja: ";
    cin>>x>>y;
    int a=x,b=y;

    cout<<endl<<"Zadanie 1."<<endl;
    cout<<"Przed wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;
    zadanie1(&x,&y);
    cout<<"Po wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;

    cout<<endl<<"Zadanie 2."<<endl;
    cout<<"Przed wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;
    zadanie2(x,y);
    cout<<"Po wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;

    cout<<endl<<"Zadanie 3."<<endl;
    cout<<"Przed wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;
    zadanie3(x,&y);
    cout<<"Po wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;

    cout<<endl<<"Zadanie 4."<<endl;
    cout<<"Przed wykonaniu funnkcji. x = "<<x<<" ,y = "<<y<<endl;
    int iloczyn = zadanie4(x,y);
    cout<<"Suma x i y = "<<x<<"      Iloczyn x i y = "<<iloczyn<<endl;

    //przywrócenie wartości początkowych
    x=a,y=b;

    cout<<endl<<"Zadanie 5."<<endl;
    cout<<"Adres x: "<<&x<<" wartosc x: "<<x<<endl;
    cout<<"Adres y: "<<&y<<" wartosc y: "<<y<<endl;
    zadanie5(&x,&y);
    cout<<"Adres x po wykonaniu funkcji: "<<&x<<" wartosc x: "<<x<<endl;
    cout<<"Adres y po wykonaniu funkcji: "<<&y<<" wartosc y: "<<y<<endl;
    
    cout<<endl<<"Zadanie 6."<<endl;
    cout<<"Przeciazony swap wyglada nastepujaco: "<<endl;
    cout<<"template <class T> void swap ( T* a, T* b )"<<endl<<"{"<<endl<<"\tT c = a; a=b; b=c;"<<endl<<"}"<<endl;

    return 0;
}
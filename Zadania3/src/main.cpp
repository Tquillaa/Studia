#include <iostream>

#include <Zadania3/matrix.hpp>

using namespace std;

int main(){

    //Stworzenie 4 macierzy
    Matrix m1(4,2);
    Matrix m2(2,4);
    Matrix m3(5);
    Matrix m4(5);

    //Wypisanie ich - sa wyzerowane
    cout<<"Tablice po stworzeniu sa wyzerowane";
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;
    m3.print();
    cout<<endl;
    m4.print();
    cout<<endl;

    cout<<endl<<"Ustawienie tablicom wartosci";
    //wypelnienie m1 jedynkami
    for(int i = 0;i<m1.cols();i++){
        for(int j = 0;j<m1.rows();j++){
            m1.set(i,j,1.0);
        }
    }

    //wypelnienie m2 dwojkami
    for(int i = 0;i<m2.cols();i++){
        for(int j = 0;j<m2.rows();j++){
            m2.set(i,j,2.0);
        }
    }

    //wypelnienie m3 piatkami
    for(int i = 0;i<m3.cols();i++){
        for(int j = 0;j<m3.rows();j++){
            m3.set(i,j,5.0);
        }
    }

    //wypelnienie m4 czworkami
    for(int i = 0;i<m4.cols();i++){
        for(int j = 0;j<m4.rows();j++){
            m4.set(i,j,4.0);
        }
    }

    //Wypisanie ich - set dziala
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;
    m3.print();
    cout<<endl;
    m4.print();
    cout<<endl;

    //Dodanie macierzy m3 i m4
    cout<<endl<<"Dodanie macierzy m3 i m4";
    //Matrix dodawanie = m3.add(m4);
    Matrix dodawanie = m3 + m4;
    dodawanie.print();

    //Odejmowanie mecierzy m4 i m3
    cout<<endl<<"Odjecie od m4 macierzy m3";
    //Matrix odejmowanie = m4.subtract(m3);
    Matrix odejmowanie = m4 - m3;
    odejmowanie.print();

    //Mnozenie macierzy m1 i m2
    cout<<endl<<"Mnozenie macierzy m1 i m2";
    //Matrix mnozenie = m1.multiply(m2);
    Matrix mnozenie = m1 * m2;
    mnozenie.print();

    //Zwrocenie ile ma wierszy
    cout<<endl<<"M1 ma "<<m1.rows()<<" wierszy";

    //Zwrocenie ile ma kolumn
    cout<<endl<<"M2 ma "<<m2.cols()<<" kolumn";

    cout<<endl<<endl<<"Macierz m1 zostanie wpisana do D:\\macierz.txt"<<endl;
    m1.store("macierz.txt","D:\\");

    cout<<endl<<"Macierz m5 zostanie wczytana z pliku macierz.txt w tym katalogu gdzie sie znajdujesz"<<endl;
    Matrix m5("macierz.txt");
    cout<<"Wczytana macierz:";
    m5.print();
    
    return 0;
}
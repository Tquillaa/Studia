#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <Zadania3/matrix.hpp>
using namespace std;

class RoznicaWierszy : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba wierszy w obu macierzach nie zgadza sie";
    }
};
class RoznicaKolumn : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba kolumn w obu macierzach nie zgadza sie";
    }
};
class KolumnyRozneWiersze : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba kolumn 1-szej macierzy rozna od liczby wierszy 2-gier macierzy";
    }
};
class WierszeRozneKolumny : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba wierszy 1-szej macierzy rozna od liczby kolumn 2-gier macierzy";
    }
};
class BladPliku : public exception
{
    virtual const char *what() const throw()
    {
        return "My exception :)";
    }
};

Matrix::Matrix(int n, int m){
       this->tab = new double[n*m]();
       this->n = n;
       this->m = m;
}
Matrix::Matrix(int n){
        this->tab = new double[n*n]();
        this->n = n;
        this->m = n;
}
Matrix::Matrix(const Matrix &m2) : Matrix(m2.m,m2.n){
    memcpy(this->tab,m2.tab,m2.n*m2.m*sizeof(double));
}
Matrix::Matrix(string path){
    ifstream f(path);
    if(f.good()){
        int n,m;
        f>>n>>m;
        this->n = (int) n;
        this->m = (int) m;
        this->tab = new double[n*m]();
        for(int i = 0;i<n*m;i++){
            f>>this->tab[i];
        }
        f.close();
    }
    else {
        cout<<"Brak pliku"<<endl;
        this->n=0;
        this->m=0;
        this->tab=nullptr;
    }
}
Matrix::~Matrix(){
    delete [] this->tab;
}
void Matrix::set(int n, int m, double val){
    this->tab[n*this->n+m] = val;
}
double Matrix::get(int n, int m){
    return this->tab[n*this->n+m];
}
Matrix Matrix::add(Matrix &m2){
    RoznicaWierszy rw;
    RoznicaKolumn rk;
    try {
        if(this->n != m2.n) throw rw;
        if(this->m != m2.m) throw rk;
         Matrix m3(this->n, this->m);
        for(int i = 0;i<this->rows();i++){
               for(int j = 0;j<this->cols();j++){
                  m3.tab[i*this->n+j] = this->tab[i*this->n+j] + m2.tab[i*this->n+j];
               }
        }
        return m3;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}
Matrix Matrix::subtract(Matrix &m2){
    RoznicaWierszy rw;
    RoznicaKolumn rk;
    try {
        if(this->n != m2.n) throw rw;
        if(this->m != m2.m) throw rk;
        Matrix m3(this->n, this->m);
        for(int i = 0;i<this->rows();i++){
               for(int j = 0;j<this->cols();j++){
                  m3.tab[i*this->n+j] = this->tab[i*this->n+j] - m2.tab[i*this->n+j];
               }
        }
        return m3;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}
Matrix Matrix::multiply(Matrix &m2){
    KolumnyRozneWiersze krw;
    WierszeRozneKolumny wrk;
    try {
        if(this->n != m2.m) throw wrk;           
        if(this->m != m2.n) throw krw;
        Matrix m3(this->n, m2.m);
        for(int i = 0;i<this->n;i++){
              for(int j = 0;j<m2.m;j++){
                double suma = 0;
                   for(int k = 0;k <this->m;k++)
                    suma += this->tab[j * m + k] * m2.tab[k * m2.m + i];
                   m3.tab[j * m2.m + i] = suma;
            }
        }
        return m3;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}
int Matrix::rows(){
    return n;
}
int Matrix::cols(){
    return m;
}
void Matrix::print(){
    for(int i=0;i<this->n*this->m;i++){
        if(i%m==0) cout<<endl;
        cout<<this->tab[i]<<" ";
    }
}
void Matrix::store(string filename, string path){
    BladPliku bp;
    try {
        ofstream f(path+filename);
        if(!f) throw bp;
        f<<this->n<<" "<<this->m<<endl;
        for(int i = 0;i<this->n*this->m;i++){
            if(i!= 0 && i%m==0) f<<endl;
            f<<this->tab[i]<<" ";
        }
        f.close();
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
} 
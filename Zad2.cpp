#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    string slowo = argv[1];
    int length = slowo.length();
    for(int i=0;i<length/2;i++)
          if(slowo[i]!=slowo[length-1-i]){
              cout<<"Podane slowo nie jest palindromem tekstowym"<<endl;
              return 0;
          }
    
    cout<<"Podane slowo jest palindromem tekstowym"<<endl;

    return 0;
}
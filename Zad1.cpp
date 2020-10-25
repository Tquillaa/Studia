#include <iostream>
using namespace std;

void swap(void* a, void* b){
    void* x = a;
    a = b;
    b = x;
    x = NULL;
}

int main(int argc, char* argv[]){
    for(int i=0;i<argc-1;i++)
        for(int j=0;j<argc-1;j++){
            if(atoi(argv[j])>atoi(argv[j+1])){
                swap(argv[j],argv[j+1]);
            }
        }

    for(int i=1;i<argc;i++)
        cout<<argv[i]<<" ";

    return 0;
}
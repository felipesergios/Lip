#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAX_T=512;
struct pixel{
    int r;
    int g;
    int b;
};

int main() {
    int NL,NC,C_MAX,i,j;
    pixel V[MAX_T][MAX_T];

    char Texto[100];
    //int Desprezivel;
    char N[100];
    char D[100];
    fstream arq;
    ofstream novo;
    cout<<"Digite o nome do arquivo para abrir"<<endl;
    cin>>N;
    cout<<"Digite o nome do novo arquivo"<<endl;
    cin>>D;
    novo.open(D);
    arq.open(N);
    if(!arq.is_open()){
        cout<<"Arquivo nao encontrado"<<endl;
        exit(0);
    }else{
    cout<<"Arquivo encontrado"<<endl;
    arq.getline(Texto,101);
    arq>>NL;
    //NL=NL/2;
    arq>>NC;
    //NC=NC/2;
    arq>>C_MAX;
    if(strcmp(Texto,"P3")==0){
    cout<<NL<<endl;
    cout<<NC<<endl;
    novo<<Texto<<endl;
    novo<<NL<<" "<<NC<<endl;
    novo<<C_MAX<<endl;
    for(i=0;i<=NL;i++){
        for(j=0;j<=NC;j++){
            arq>>V[i][j].r;
             arq>>V[i][j].g;
              arq>>V[i][j].b;
        }
    }

     for(i=0;i<=NL;i++){
        for(j=0;j<=NC;j++){
            novo<<V[i][j].r<<" ";
             novo<<V[i][j].g<<" ";
              novo<<V[i][j].b<<" ";
        }
        novo<<endl;
    }




        }
    }
    arq.close();
    novo.close();
  return 0;
}

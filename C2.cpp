#include <iostream>
using namespace std;
    void LerV(int vet[], int n){
    int i;
    int valor;
    for(i = 0; i < n; i++){
    cout<<"Digite Valor Para Posicao "<<i<<" Do Vetor";
    cin>>valor;
    vet[i] = valor;
        }
    }
    bool Tchala(int vet[],int n,int x){
    int i;
    //bool R;
    int C=0;
    for(i=0;i<n;i++){
        if(vet[i]==x){
            C++;
           }
        }
        if(C>=1){
            return true;
        }
        else{
            return false;
        }

    }
    int main(){
        int n,x;

    cout<<"Digite o Tamanho do Vetor :";
    cin >> n;
    cout<<"Digite Valor de Ref :";
    cin >> x;
    int v[n];
    LerV(v,n);
    if(Tchala(v,n,x)){
        cout<<" Sim, ocorreu uma venda cujo valor foi R$"<<x<<endl;
    }else{cout<<"Is Not";}
    cout << endl;
    return 0;

    }

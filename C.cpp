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
    int SomaVet(int vet[],int x,int r,int n){
    int i;
    r=0;
    LerV(vet,n);
    for(i=0;i<n;i++){
        if(vet[i]>x){
          r+=vet[i];
        }
    }
    return r;
    }
    int main(){
        int n,x,r;
    cout<<"Digite o Tamanho do Vetor";
    cin >> n;
    cout<<"Digite Valor de Ref";
    cin >> x;
    int v[n], i;
    cout<<SomaVet(v,x,r,n);
    cout << endl;
    return 0;

    }

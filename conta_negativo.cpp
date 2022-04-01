#include <iostream>
using namespace std;

    //Ler um vetor de Tamanho N 
    void LerV(int vet[], int n){
    int i;
    int valor;
    for(i = 0; i < n; i++){
    cout<<"Digite Valor Para Posicao  "<<i<<"  Do Vetor";
    cin>>valor;
    vet[i] = valor;
        }
    }
    // Realiza a varredura no vetor e quando o número for negativo (N<0) acresce o contador
    int ContaNegativos(int vet[]){
        int i;
        int contador=0;
        for(i=0;i<5;i++){
            if(vet[i]<0){
                contador++;
            }
        }
        return contador;
    }
    
    // Função principal que chama a leitura e a função secundária de contagem de negativos
    int main(){
    int n,x,r;
    cout<<"Digite o Tamanho do Vetor";
    cin >> n;
    int v[n], i;
    LerV(v,n);
    cout<<ContaNegativos(v);
    return 0;

    }

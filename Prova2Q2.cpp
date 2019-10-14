#include <iostream>
using namespace std;
const int MAX=100;
void Preencher_M(int n[][MAX],int nl,int nc){
int i,j;
for(i=0;i<nl;i++){
    for(j=0;j<nc;j++){
        cin>>n[i][j];
        }
    }
}
void imprimir_M(int n[][MAX],int nl,int nc){
int i,j;
for(i=0;i<nl;i++){
    for(j=0;j<nc;j++){
        cout<<n[i][j]<<" ";
        }
        cout<<endl;
    }

}
void Nilpoten(int n[][MAX],int mat_R[][MAX],int n2[][MAX] ,int nl,int nc,int & X){
int i,j;
for(i=0;i<nl;i++){
    for(j=0;j<nc;j++){
        mat_R[i][j]=n[j][i]*n2[i][j];
        X+=mat_R[i][j];
        }
    }
}

int main() {
  int nl,nc,x,y;
  int n[MAX][MAX]; int mat_R[MAX][MAX];
  int n2[MAX][MAX];
  int X=0;
  cout<<"Ordem da Matriz NL:";
  cin>>nl;
   cout<<"Ordem da Matriz NC:";
  cin>>nc;
  cout<<"Digite os termos da matriz 1";
  Preencher_M(n,nl,nc);
  cout<<"Digite os termos da matriz 2";
  Preencher_M(n2,nl,nc);

  Nilpoten(n,mat_R,n2,nl,nc,X);

  imprimir_M(mat_R,nl,nc);
  cout<<"a soma dos termos vale:"<<X<<endl;
  if(X==0){
    cout<<"Essa matriz é nilpotente de indice 2";
    }else{
    cout<<"Essa matriz não é nilpotente de indice 2";
    }
  return 0;
}

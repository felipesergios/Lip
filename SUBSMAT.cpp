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
void Subtracao(int n[][MAX],int mat_R[][MAX],int n2[][MAX] ,int nl,int nc){
int i,j;
for(i=0;i<nl;i++){
    for(j=0;j<nc;j++){
        mat_R[i][j]=n[i][j]-n2[i][j];
        }
    }
}

int main() {
  int nl,nc,x,y;
  int n[MAX][MAX]; int mat_R[MAX][MAX];
  int n2[MAX][MAX];
  cout<<"Ordem da Matriz NL:";
  cin>>nl;
   cout<<"Ordem da Matriz NC:";
  cin>>nc;
  Preencher_M(n,nl,nc);
  Preencher_M(n2,nl,nc);
  //imprimir_M(n,nl,nc);
  Subtracao(n,mat_R,n2,nl,nc);
  //cout<<"####"<<endl;
  imprimir_M(mat_R,nl,nc);
  return 0;
}

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
void Transposta(int n[][MAX],int mat_R[MAX][MAX],int nl,int nc,int& x,int& y){
int i,j;
for(i=0;i<nl;i++){
    for(j=0;j<nc;j++){
        mat_R[j][i]=n[i][j];
        }
    }
x=nc;
y=nl;
}

int main() {
  int nl,nc,x,y;
  int n[MAX][MAX]; int mat_R[MAX][MAX];
  cout<<"Ordem da Matriz N:";
  cin>>nl;
  cin>>nc;
  Preencher_M(n,nl,nc);
  //imprimir_M(n,nl,nc);
  Transposta(n,mat_R,nl,nc,x,y);
  //cout<<"####"<<endl;
  imprimir_M(mat_R,x,y);
  return 0;
}

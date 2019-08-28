#include <iostream>
using namespace std;
float menorNota(float N1,float N2,float N3){
if(N1<=N2&&N1<=N3){
    return N1;
    }
 else if(N2<=N1&&N2<=N3){
    return N2;
 }
 else if(N3<=N2&&N3<=N1){
    return N3;
 }
}

void calcNota(float N1,float N2,float N3,bool& Pass,float& M,float& Saida){
    float Menor=menorNota(N1,N2,N3);
M=(N1+N2+N3)/3;
    if(N1>=3&&N2>=3&&N3>=3&&M<5){
        Saida=15-(N1+N2+N3-Menor);
        Pass=true;
    }else{Pass=false;}
}
int main() {
    float N1,N2,N3,M,Saida;
    bool Pass;
  cout <<"Suas Notas:"<<endl;
  cin>>N1;
  cin>>N2;
  cin>>N3;
  calcNota(N1,N2,N3,Pass,M,Saida);
  cout<<Pass<<endl;
  cout<<Saida;
  //cout<<menorNota(N1,N2,N3);
  return 0;
}


#include <iostream>
using namespace std;
int MDC(int x, int y) {
    int resto=x%y;
    while(resto!=0){
        x=y;
        y=resto;
        resto=x%y;
    }
    return y;
}
int MMC(int x, int y) {
    int R=(x*y)/MDC(x,y);
    return R;
}
void Gerador(int x,int y,int& saida1,int& saida2){
saida1=MMC(x,y);
saida2=MDC(x,y);
}

int main() {
    int X ,Y,saida1,saida2;
    cout<<"ENTRE COM OS VALORES"<<endl;
  cin>>X;
  cin>>Y;
  Gerador(X,Y,saida1,saida2);
  cout<<"MMC vale: "<<saida1<<endl;
  cout<<"MDC vale: "<<saida2<<endl;
  return 0;
}

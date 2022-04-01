#include <iostream>
#include <iomanip>
using namespace std;

void conta_valores(int valor,int indice){
    
    if(valor>0 and valor <= 25){
        indice++;
        cout<<"a condição é verdade 0<N>25";
        cout<<"O ultimo valor do contdor é : "<<indice<<endl;
    }
}


int main() {
    int x;
    int indice=0;
    int indice2=0;
    int indice3=0;
    int indice4=0;
    int indice5=0;
    int valor_total=0;
    float porcent = 0;
    while(cin>>ws>>x){
        
        if(x>=0 and x<25){
            indice++;
        }
        if(x>=25 and x<50){
            indice2++;
        }
        if(x>=50 and x<75){
            indice3++;
        }
        if(x>=75 and x<100){
            indice4++;
        }
        
        if(x<0 or x>100){
            indice5++;
        }
        
    }
    cout<<"Fim do programa I: "<<indice<<endl;
    cout<<"Fim do programa II : "<<indice2<<endl;
    cout<<"Fim do programa III :"<<indice3<<endl;
    cout<<"Fim do programa IV : "<<indice4<<endl;
    cout<<"Fora de intervalo : "<<indice5<<endl;
    valor_total=indice+indice2+indice3+indice4+indice5;
    cout<<"Valor de todos os elementos "<<valor_total;
    porcent=((indice*1.0)/valor_total)*100;
    cout<<setprecision(4)<<"Porcentagem do valor I: "<<porcent;
    return 0;    
}

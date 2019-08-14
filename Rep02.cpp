#include <iostream>
using namespace std;

int main() {
    int i , n , menor;
    cout<<"Valor :";
    cin>>n;
    menor = n;
        while(i!=0){
                cout<<"Valor :";
                cin>>i;
                if(i<=menor){
                    menor=i;
                }


        }
        cout<<"Menor Valor :"<<menor;
}

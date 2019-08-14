#include <iostream>
using namespace std;

int main() {
int i = 0;
int n = 0;
int a = 0;
int soma = 0;
int media = 0;
    cout<<"Valor de N:"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Digite:"<<endl;
        cin>>a;
        soma += a;
    }
    media=soma/n;
    cout<<media;
}

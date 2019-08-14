#include <iostream>
using namespace std;

int main() {
int N;
int i;
int div = 0;
cout<<"Digite:"<<endl;
cin>>N;
    for(i=1;i<N;i++){
        if(N%i==0){
          div+=i;
        }
    }
    if(div==N){
        cout<<"O numero  "<<N<<"e perfeito"<<endl;
    }else{
    cout<<"O numero  "<<N<<"NAO e perfeito"<<endl;
    }


}

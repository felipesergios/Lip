#include <iostream>
using namespace std;

int main() {
int N;
int i;
int div = 0;
cout<<"Digite:"<<endl;
cin>>N;
    for(i=1;i<=N;i++){
        if(N%i==0){
          div++;
        }
    }
    if(div==2){
        cout<<"Primo"<<endl;
    }else{
    cout<<"N Primo";
    }


}

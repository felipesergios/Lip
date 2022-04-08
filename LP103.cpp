#include <iostream>

using namespace std;

int main()
{
    int m , n , aux , result = 0;
    cin>>m;
    cin>>n;
    
    
    if(n>0){
        aux=m;
        for(int i=0;i<n;i++){
            cout<<aux;
            result+=aux;
            aux++;
            
        }
    }
    
    if(n<0){
        aux=m;
        for(int i=m;i>=n;i--){
            cout<<i;
            result+=aux;
            aux--;
            
        }
    }
    
    
    if(n==0){
        cout<<m;
    }
    cout<<"A soma é :"<<result;
    return 0;
}

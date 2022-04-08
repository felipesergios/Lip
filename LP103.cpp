#include <iostream>

using namespace std;

int main()
{
    int m , n , aux = 0;
    cin>>m;
    cin>>n;
    
    if(n>0){
        aux=m;
        for(int i=0;i<n;i++){
            cout<<aux;
            aux++;
            
        }
    }
    
    if(n<0){
        aux=m;
        for(int i=10;i>n;i--){
            cout<<i;
            aux--;
            
        }
    }
    
    
    if(n==0){
        cout<<m;
    }
    return 0;
}

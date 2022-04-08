
#include <iostream>

using namespace std;

int main()
{
    int m , n , aux = 0;
    int  reverse = 0;
    int reverse_result = 0;
    cin>>m;
    cin>>n;
    
    
    if(n>0){
        aux=m;
        for(int i=0;i<n;i++){
            reverse_result+=aux;
            aux++;
            
        }
    }
    
   if(n<0){
        aux=n*(-1);
        reverse=m;
        for(int i=0;i<aux;i++){
          reverse_result+=reverse;
            reverse-=1;
        }
    }
    
    
    if(n==0){
        cout<<m;
        return 0;
    }
    cout<<reverse_result;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    int t1 = 0;
    int t2 = 1;
    cin>>n;
    int cont = 3;
    cout<<"-> "<<t1<<" ->"<<t2;
    while(cont<= n){
        int t3=t1+t2;
        if(t3 < n){
    cout<<" -> "<<t3;
 
    t1=t2;
    t2=t3;
    cont +=1;
        }else{
            return 0;
        }
        
    }
    return 0;
}

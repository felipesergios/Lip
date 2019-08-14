#include <iostream>
using namespace std;

int main() {
int i = 0;
cout<<"####Digite $ Para Sair###"<<endl;
char A;
  do {
    cout<<"Digite Uma Letra Minuscula"<<endl;;
    cin>>A;
    if(isupper(A)){
      cout<<"Caractere Invalido redigite :";   
    }else if (islower(A))
    {
    
      cout<<"é minuscula"<<endl;
      if (A=='a'||A=='e'||A=='i'||A=='o'||A=='u')
      {
        cout<<"Vogal"<<endl;
      }else
      {
        cout<<"Consoante"<<endl;
      }
    }
    
  }
  while (A!='$');
}
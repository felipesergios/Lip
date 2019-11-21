#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int const M_MAX=1560;

void Menu();
int main(){

  Menu();
    
   

}
void Menu(){
    int OP;
    //Mensagem Inicial do Programa MENU
    cout<<"Seja Bem Vindo "<<endl;
    system("whoami");
    cout<<"Voce está executando esse programa no Directory : "<<endl;
    system("pwd"); 
    //system("uptime") ;
    cout<<"Por favor Certifique-se Que os Arquivos .ppm se encontram nesse mesmo diretorio . "<<endl;
    cout<<"Seu Tempo de Atividade : "<<endl;
	system("uptime");
    //TEXTO COM AS OP
    cout<<"SUAS OPCOES SAO :  "<<endl<<"[1]Cortar Imagem "<<endl<<"[2]Binarizar"<<endl<<"[3]EROSAO"<<endl<<"[0]Sair"<<endl<<"Digite sua OPCAO:"<<endl;
    cin>>OP;
    while (OP!=0)
    {
    switch (OP)
    {
    case 1:
	system("clear");
        cout<<"Digitou 1"<<endl;
        cout<<"Digite Sua opcao :(Caso queira sair digite [0]) "<<endl;
        cin>>OP;
        
        break;
     case 2:
	cout<<M_MAX<<endl;
        cout<<"Digitou 2"<<endl;
        cin>>OP;
        
        break;
     case 3:
        cout<<"Digitou 3"<<endl;
        cin>>OP;
        
        break;        
    
    default:
    cin>>OP;
        
        break;
    }
    }

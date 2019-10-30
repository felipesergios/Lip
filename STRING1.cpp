#include <iostream>
#include <cstring>
using namespace std;
const int STRMAX=100;
struct Data{
int dia;
int mes;
int ano;
};
//Criando a Class Funcionario
struct Funcionario{
char Nome[50];
//char Data[STRMAX];
Data ad_data;
float Salario;
};

int Busca(Funcionario v[],char nome[],int n){
int i;
for(i=0;i<n;i++){
        if(strcmp(v[i].Nome,nome)==0){
           return i;
           }

        }
        return -1;
    }





int main() {
    int i,n,id_Pos=0;
    char Id[51];
cout<<"Digite o N:";
cin>>n;
Funcionario F1[n];
cin.ignore();
for(i=0;i<n;i++){
    cout<<"Digite o nome do Funcionario"<<endl;
    cin.getline(F1[i].Nome,51);
    cout<<"Digite o dia da data de admissao"<<endl;
    cin>>F1[i].ad_data.dia;
     cout<<"Digite o Mes"<<endl;
    cin>>F1[i].ad_data.mes;
     cout<<"Digite o Ano"<<endl;
    cin>>F1[i].ad_data.ano;
    //FIM
    cout<<"Digite o salario"<<endl;
    cin>>F1[i].Salario;
    cin.ignore();
}
for(i=0;i<n;i++){
    cout << "Nome do Funcionario: " << F1[i].Nome << endl;
    cout<<"DATA DE ADMISSAO"<<endl;
    cout << "DIA: " << F1[i].ad_data.dia << endl;
    cout << "MES: " << F1[i].ad_data.mes << endl;
    cout << "ANO: " << F1[i].ad_data.ano  << endl;
    cout << "Salario do funcionario : " << F1[i].Salario << endl;
    cout<<"###############################"<<endl;
}
cin.ignore();
cout<<"Digite um valor para buscar"<<endl;
cin.getline(Id,STRMAX);
cin.ignore();

cout<<"NOME:"<<F1[Busca(F1,Id,n)].Nome<<endl;
cout<<"SALARIO:"<<F1[Busca(F1,Id,n)].Salario<<endl;




  return 0;
    }

#include<iostream>
#include<cstring>
#include<fstream>
const int SMAX = 50;
const int MAX = 1256;
using namespace std;
struct RGB{

    int R;
    int G;
    int B;

};

struct Img{
    int Largura;
    int Altura;
    char Tipo[SMAX];
    char nome[SMAX];
    int MaxPixel;
    RGB Matriz[MAX][MAX];

};

void abre_arquivo(char nome[],Img& img){
    fstream arq;

    arq.open(nome);
char p[] = "P3";


    if(arq.is_open()){
        //Todo code aqui
            arq.getline(img.Tipo,SMAX);
            if(strcmp(img.Tipo,p) == 0){
            arq >> img.Largura;
            arq >> img.Altura;
            arq >> img.MaxPixel;

            for(int i = 0; i<img.Largura; i++){
                for(int j =0; j<img.Altura; j++){
                    arq >> img.Matriz[i][j].R;
                    arq >> img.Matriz[i][j].G;
                    arq >> img.Matriz[i][j].B;
                }
                }
                cout << "Aquivo aberto com sucesso"<< endl;
                cout << "Largura; " << img.Largura << " Altura: " << img.Altura << endl;
            }else{
                cout << "Aqruivo errado" << endl;

                }





    }else{
        cout << "ERRO" << endl;
    }


}
void salva_arquivo(char nome[SMAX], Img img){

ofstream arq;

arq.open(nome);


    if(arq.is_open()){
        //Todo code aqui
            arq << img.Tipo << endl;
            arq << img.Largura << " ";
            arq << img.Altura << endl;
            arq << img.MaxPixel << endl;

            for(int i = 0; i<img.Largura; i++){
                for(int j =0; j<img.Altura; j++){
                    arq << img.Matriz[i][j].R << " " <<  img.Matriz[i][j].G  << " " << img.Matriz[i][j].B <<" ";


                }
                cout << endl;
            }



        cout << "Imagem salva com sucesso"<< endl;


    }
}
void converte_para_cinza(Img img, Img& img_out){



int media = 0;

                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Largura;
                img_out.Altura = img.Altura;
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Largura; i++){
                for(int j =0; j<img.Altura; j++){
                   media+=img.Matriz[i][j].R;
                   media+=img.Matriz[i][j].G;
                   media+=img.Matriz[i][j].B;

                   media/=3;

                   img_out.Matriz[i][j].R = media;
                   img_out.Matriz[i][j].G = media;
                   img_out.Matriz[i][j].B = media;

                    media = 0;
                }

            }


}
//INT MAIN


void menu(){
int op;
char nome[SMAX];
char nome_novo[SMAX];
Img img;
Img img_out;

cout<<"[1]Tons de cinza"<<endl<<"[0]Sair"<<endl;
cin>>op;
cin.ignore();
while(op!=0){
    if(op==1){
    system("color 4");
    cout <<"Entre com o nome do arquivo" << endl;
    cin.getline(nome,SMAX);
    system("cls");
    abre_arquivo(nome,img);
    system("pause");
    cout << "Entre com o nome do novo arquivo" << endl;
    system("color 3");
    cin.getline(nome_novo, SMAX);
    system("cls");
    cout<<"Aplicando o Filtro"<<endl;
    converte_para_cinza(img , img_out);
    system("pause");
    cout<<"Salvando o arquivo"<<endl;
    salva_arquivo(nome_novo, img_out);
    system("cls");

        //Fim do codigo dessa parte
        system("color 2");
        cout<<"[0] para sair "<<endl;
        cin>>op;
        cin.ignore();
        }
    if(op==2){
    cout <<"Entre com o nome do arquivo" << endl;
    cin.getline(nome,SMAX);
    abre_arquivo(nome,img);
    system("cls");
        cout<<"[0] para sair "<<endl;
        cin>>op;
        cin.ignore();

        }
    }
}


int main(){
menu();

}

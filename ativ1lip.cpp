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
void abre_arquivo(char nome[SMAX],Img& img);

void converte_para_cinza(Img img_in, Img& img_out);

void salva_arquivo(char nome[SMAX], Img img);

int main(){

char nome[SMAX];
char nome_novo[SMAX];
Img img;
Img img_out;
bool confirma;
    cout <<"Entre com o nome do arquivo" << endl;
    cin.getline(nome,SMAX);
    abre_arquivo(nome,img);


    cout << "Entre com o nome do novo arquivo" << endl;
    cin.getline(nome_novo, SMAX);

    converte_para_cinza(img , img_out);

    salva_arquivo(nome_novo, img_out);


return 0;
}

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

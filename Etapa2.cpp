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

void rot_antihorario(Img img_in, Img& img_out);

void salva_arquivo(char nome[SMAX], Img img);

void erosao(Img img, Img& img_out);

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

    rot_antihorario(img , img_out); // para erosão troque a função.

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

            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){
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

            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){
                    arq << img.Matriz[i][j].R << " " <<  img.Matriz[i][j].G  << " " << img.Matriz[i][j].B <<" ";


                }
                cout << endl;
            }



        cout << "Imagem salva com sucesso"<< endl;


    }
}
void rot_antihorario(Img img, Img& img_out){



int media = 0;

                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Altura; //Atribui nova de colunas.
                img_out.Altura = img.Largura; //Atribui nova de linhas.
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){

                   img_out.Matriz[img.Largura-j-1][i].R = img.Matriz[i][j].R;
                   img_out.Matriz[img.Largura-j-1][i].G = img.Matriz[i][j].G;
                   img_out.Matriz[img.Largura-j-1][i].B = img.Matriz[i][j].B;
                }

            }


}

void erosao(Img img, Img& img_out){



int media = 0;

                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Largura; //Atribui nova de colunas.
                img_out.Altura = img.Altura; //Atribui nova de linhas.
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){

                   media+=img.Matriz[i][j].R;
                   media+=img.Matriz[i][j].G;
                   media+=img.Matriz[i][j].B;

                   media/=3;

                    if(img.Matriz[i][j].R && img.Matriz[i+1][j].R && img.Matriz[i][j+1].R && img.Matriz[i+1][j+1].R){

                   img_out.Matriz[i][j].R = 255;
                   img_out.Matriz[i][j].G = 255;
                   img_out.Matriz[i][j].B = 255;
                    }else{
                   img_out.Matriz[i][j].R = 0;
                   img_out.Matriz[i][j].G = 0;
                   img_out.Matriz[i][j].B = 0;

                    }

            media = 0;







}


        }
}

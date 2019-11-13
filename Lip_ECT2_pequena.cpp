

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

void cortar(Img img_in, Img& img_out);

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

    cortar(img , img_out);

    salva_arquivo(nome_novo, img_out);


return 0;
}

void abre_arquivo(char nome[],Img& img){
    fstream arq;

    arq.open(nome);
char p[] = "P3";


    if(arq.is_open()){
        //Todo code aqui
            arq.getline(img.Tipo,SMAX); //Ler Primeira Linha
            if(strcmp(img.Tipo,p) == 0){
            arq >> img.Largura; // Ler Segunda Linha
            arq >> img.Altura;  // Ler Terceira Linha
            arq >> img.MaxPixel; // Ler Quarta Linha

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
            arq << img.Tipo << endl;  //Escreve na 1º linha
            arq << img.Largura << " "; //Escreve na 2º linha
            arq << img.Altura << endl; //Escreve na 3º linha
            arq << img.MaxPixel << endl; //Escreve na 4º linha

            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){
                    arq << img.Matriz[i][j].R << " " <<  img.Matriz[i][j].G  << " " << img.Matriz[i][j].B <<" ";


                }
                cout << endl;
            }



        cout << "Imagem salva com sucesso"<< endl;


    }
}
void cortar(Img img, Img& img_out){





                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Largura/2; // atribui a nova largura da img_out.
                img_out.Altura = img.Altura/2;
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Altura; i++){
                for(int j = 0; j<img.Largura; j++){
                        if(i%2==0 && j%2==0){
                img_out.Matriz[j/2][i/2].R = img.Matriz[j][i].R;
                img_out.Matriz[j/2][i/2].G = img.Matriz[j][i].G;
                img_out.Matriz[j/2][i/2].B = img.Matriz[j][i].B;
                        }



                }

            }


}


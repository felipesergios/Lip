#include<iostream>
#include<cstring>
#include<fstream>

const int SMAX = 50;
const int MAX = 512;

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
void S_MENU();
void Menu();
void abre_arquivo(char nome[SMAX],Img& img);
void rot_antihorario(Img img_in, Img& img_out);
void salva_arquivo(char nome[SMAX], Img img);
void converte_para_cinza(Img img_in, Img& img_out);
void erosao(Img img, Img& img_out);
void Conta_vetor(Img img,int canalR[], int canalG[],int canalB[]);
void equaliza_histograma(Img img, Img& img_out);
int soma_P(int v[],int n);

int main(){
Menu();



return 0;
}

void S_MENU(){
cout<<"SUAS OPCOES SAO :  "<<endl<<"[1]Rotacao Anti-Horario."<<endl<<"[2]Erosao."<<endl<<"[3]Histograma."<<endl<<"[4]Escala de cinza."<<endl;
    cout << endl;
    cout << "[5]Abrir Arquivo.      [6]Salvar.       [7] Ver Opcoes.    [0]Sair"<<endl;
    cout << endl;
cout<<"Nota: Antes de operar (funcoes de 1 - 4 ), abra seu arquivo .ppm op [5] "<<endl;
}
void Menu(){
char nome[SMAX];
char nome_novo[SMAX];
Img img;
Img img_out;
int OP;
    //Mensagem Inicial do Programa MENU
    cout<<"Seja Bem Vindo "<<endl;
    cout<<"Por favor Certifique-se Que os Arquivos .ppm se encontram nesse mesmo diretorio . "<<endl;
    cout<<"Nota: Quando Solicitado Digite o nome do arquivo e sua extensão "<<endl;
    cout<<"SUAS OPCOES SAO :  "<<endl<<"[1]Rotacao Anti-Horario."<<endl<<"[2]Erosao."<<endl<<"[3]Histograma."<<endl<<"[4]Escala de cinza."<<endl;
    cout << endl;
    cout << "[5]Abrir Arquivo.      [6]Salvar.       [7] Ver Opcoes.    [0]Sair"<<endl;
    cout << endl;
    cout<<"Digite sua OPCAO:"<<endl;
    cin>>OP;
    while (OP!=0)
    {
    switch (OP)
    {
    case 1:
        rot_antihorario(img , img_out); // para erosão troque a função.
        //salva_arquivo(nome_novo, img_out);
        cout<<"Aplicando Filtro De Rotacao Anti-Horario"<<endl;
        cout<<"Digite sua opcao ([0]Sair , [6]Salvar , [7]Voltar ao menu .)"<<endl;
        cin>>OP;

        break;
     case 2:
        erosao(img , img_out);
       // salva_arquivo(nome_novo, img_out);
        cout<<"Aplicando Filtro De Erosao"<<endl;
        cout<<"Digite sua opcao ([0]Sair , [6]Salvar , [7]Voltar ao menu .)"<<endl;
        cin>>OP;

        break;
     case 3:
        equaliza_histograma(img,img_out);
        //salva_arquivo(nome_novo, img_out);
        cout<<"Aplicando Filtro De Equaliza Histograma"<<endl;
        cout<<"Digite sua opcao ([0]Sair , [6]Salvar , [7]Voltar ao menu .)"<<endl;
        cin>>OP;

        break;
         case 5:
        cout <<"Entre com o nome do arquivo" << endl;
        cout <<"Nota : Lembre-se de colocar a extensao (.ppm) no final do nome do arquivo." << endl;
        cin.ignore();
        cin.getline(nome,SMAX);
        abre_arquivo(nome,img);
        cout<<"Digite Sua opcao :(Para Sair[0],[7]Ver Opcoes)"<<endl;
        cin>>OP;

        break;
         case 6:
        cout << "Digite o Nome Para o Novo Arquivo ." << endl;
        cout << "Nota:o nome desse arquivo deve ser diferente do original"<<endl<<"caso digite igual o programa vai sobescrever o seu arquivo" << endl;
        cin.ignore();
        cin.getline(nome_novo, SMAX);
        salva_arquivo(nome_novo, img_out);
       cout<<"Digite Sua opcao :(Para Sair[0],[7]Ver Opcoes)"<<endl;
        cin>>OP;

        break;

        case 4:
        converte_para_cinza(img , img_out);
        // salva_arquivo(nome_novo, img_out);
        cout<<"Aplicando Filtro De Conversao Para Cinza"<<endl;
        cout<<"Digite sua opcao ([0]Sair , [6]Salvar , [7]Voltar ao menu .)"<<endl;
        cin>>OP;

        break;

        case 7:
        S_MENU();
        cout<<"Digite sua opcao ([0]Sair , [6]Salvar , [7]Exibir menu novamente  .)"<<endl;
        cin>>OP;

        break;

    default:
        cout<<"Opcao invalida:"<<endl;
        S_MENU();
        cout<<"Digite Sua opcao :(Para Sair[0],[7]Ver Opcoes)"<<endl;
    cin>>OP;

        break;
    }
    }
}


void abre_arquivo(char nome[],Img& img){
    fstream arq;

    arq.open(nome);
char p[] = "P3";


    if(arq.is_open()){

            arq.getline(img.Tipo,SMAX);
            if(strcmp(img.Tipo,p) == 0){
            arq >> img.Largura;
            arq >> img.Altura;
            arq >> img.MaxPixel;
            if(img.Altura<=512 && img.Largura<=512){
            for(int i = 0; i<img.Altura; i++){
                for(int j =0; j<img.Largura; j++){
                    arq >> img.Matriz[i][j].R;
                    arq >> img.Matriz[i][j].G;
                    arq >> img.Matriz[i][j].B;
                }
                }
                cout << "Aquivo aberto com sucesso"<< endl;
                cout << "Largura; " << img.Largura << " Altura: " << img.Altura << endl;
            }else{cout<<"ERRO:Dimensao Invalida."<<endl;}
            }else{cout<<"ERRO:Arquivo Invalido ."<<endl;}
    }else{
        cout << "ERRO:Nao foi possivel abrir o arquivo ." << endl;
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

                    if(i<=img.Altura && j<=img.Largura){
                    if(img.Matriz[i][j].R && img.Matriz[i+1][j].R && img.Matriz[i][j+1].R && img.Matriz[i+1][j+1].R){

                   img_out.Matriz[i][j].R = 255;
                   img_out.Matriz[i][j].G = 255;
                   img_out.Matriz[i][j].B = 255;
                    }else{
                   img_out.Matriz[i][j].R = 0;
                   img_out.Matriz[i][j].G = 0;
                   img_out.Matriz[i][j].B = 0;

                        }
                    }

            media = 0;







}


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

int soma_p(int v[],int n)
{
    int soma = 0;

    for(int i=0; i<=n; i++)
    {

        soma+=v[i];
    }
    return soma;
}


void equaliza_histograma(Img img, Img& img_out){
int vetor_R [256] = {};
int vetor_G [256] = {};
int vetor_B [256] = {};
float s = (img.MaxPixel/float(img.Altura*img.Largura));

                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Largura;
                img_out.Altura = img.Altura;
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Altura; i++){
                for(int j = 0; j<img.Largura; j++){
                        for(int k=0 ; k<img.MaxPixel; k++){

                        if(img.Matriz[i][j].R == k ){

                            vetor_R[k] +=1;

                        }
                        if(img.Matriz[i][j].G == k ){

                            vetor_G[k] +=1;

                        }
                        if(img.Matriz[i][j].B == k ){

                            vetor_B[k] +=1;

                        }




                    }

            }
        }


       int somatorio_R = 0;
       int somatorio_G = 0;
       int somatorio_B = 0;
       int k = 0;
       int l = 0;
       int a = 0;
       int i = 0;
       int j = 0;


        for(i = 0; i<img.Altura; i++){
            for(j = 0; j<img.Largura; j++){
            somatorio_R=soma_p(vetor_R,img.Matriz[i][j].R);
            somatorio_G=soma_p(vetor_G,img.Matriz[i][j].G);
            somatorio_B=soma_p(vetor_B,img.Matriz[i][j].B);
            img_out.Matriz[i][j].R = (s*somatorio_R);
            img_out.Matriz[i][j].G = (s*somatorio_G);
            img_out.Matriz[i][j].B = (s*somatorio_B);
            //cout<<img_out.Matriz[i][j].R<<endl;

            }
            cout<<endl;
        }


}




void equaliza_histograma(Img img, Img& img_out){


int vetor_R [256] = {};
int vetor_G [256] = {};
int vetor_B [256] = {};

                strcpy(img_out.Tipo,img.Tipo);//copia nome
                img_out.Largura  = img.Largura;
                img_out.Altura = img.Altura;
                img_out.MaxPixel = img.MaxPixel;

            for(int i = 0; i<img.Altura; i++){
                for(int j = 0; j<img.Largura; j++){
                        for(int k=0 ; k<256; k++){

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


        for(int i = 0; i<img.Altura; i++){
            for(int j = 0; j<img.Largura; j++){
                for(int k = 0; k<=img.Matriz[i][j].R; k++) {

                 somatorio_R+= vetor_R[k];

                }


                img_out.Matriz[i][j].R = ((255/img.Altura*img.Largura)*somatorio_R);

                

                for(int l = 0; l<=img.Matriz[i][j].G; l++) {

                somatorio_G+= vetor_G[l];


                }

                img_out.Matriz[i][j].G = ((255/img.Altura*img.Largura)*somatorio_G);

                

                for(int a = 0; a<=img.Matriz[i][j].B; a++) {

                somatorio_B+= vetor_B[a];


                }
                img_out.Matriz[i][j].B = ((255/img.Altura*img.Largura)*somatorio_B);

               




            }

        }


}

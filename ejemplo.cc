#include <global.hh>
#include <Timer.hpp>
#include <iostream>
#include <random>
#include <iomanip>

#include <iostream>
#include <random>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>


#include <iostream>
#include <boost/dynamic_bitset.hpp>

void help(){
    std::cout << "---------Comando help ejecutado, se ignoraras los demas parametros---------"  << std::endl;
    std::cout << "Descripcion: Este programa simula el juego de la vida de conway que se pidio" << std::endl;
    std::cout << "para la tarea 03, el programa se puede ejecutar con distintos parametros"     << std::endl;
    std::cout << "que variara en la ejecucion de el mismo, a continuacion se mostraran los"     << std::endl;
    std::cout << "parametros permitidos y los valores que pueden tomar."                        << std::endl;
    std::cout << std::endl;
    std::cout << "-ncol  ---> sirve para especificar la cantidad de columnas con las que se"    << std::endl;
    std::cout << "simulara el juego de la vida, este tiene que ir acompañado con un valor"      << std::endl;
    std::cout << "numerico entero mayor a 0 (de esto depende directamente cuanto se demorara"   << std::endl;
    std::cout << "en ejecutar el programa)"                                                     << std::endl;
    std::cout << std::endl;
    std::cout << "-nfil  ---> sirve para especificar la cantidad de filas con las que se"       << std::endl;
    std::cout << "simulara el juego de la vida, este tiene que ir acompañado con un valor"      << std::endl;
    std::cout << "numerico entero mayor a 0 (de esto depende directamente cuanto se demorara"   << std::endl;
    std::cout << "en ejecutar el programa)"                                                     << std::endl;
    std::cout << std::endl;
    std::cout << "-nt  ---> sirve para especificar la cantidad de procesos con las que se"      << std::endl;
    std::cout << "simulara el juego de la vida, este tiene que ir acompañado con un valor"      << std::endl;
    std::cout << "numerico entero mayor a 0 (esto afectara al tiempo que tardara )"             << std::endl;
    std::cout << "en ejecutar el programa)"                                                     << std::endl;
    std::cout << std::endl;
    std::cout << "-nt  ---> sirve para especificar la cantidad de procesos con las que se"      << std::endl;
    std::cout << "simulara el juego de la vida, este tiene que ir acompañado con un valor"      << std::endl;
    std::cout << "numerico entero mayor a 0 (esto afectara al tiempo que tardara"               << std::endl;
    std::cout << "en ejecutar el programa) no es compatible con el parametro -seq"              << std::endl;
    std::cout << std::endl;
    std::cout << "-plive  ---> sirve para especificar la probabilidad de que una celula este"   << std::endl;
    std::cout << "viva en la generacion inicial del juego de la vida, tiene que tomar valores"  << std::endl;
    std::cout << "entre 0 y 1, por ejemplo 0.5"                                                 << std::endl;
    std::cout << std::endl;
    std::cout << "-seq  ---> sirve para ejecutar la version secuencial del programa"            << std::endl;
    std::cout << std::endl;
    std::cout << "-show  ---> mostrar las generaciones a medida que se simula el juego de la"   << std::endl;
    std::cout << "vida, no es recomendable si el tablero es mayor a 30x30"                      << std::endl;
    std::cout << std::endl;
    std::cout << "-iter  ---> sirve para especificar cuantas generaciones se quieren generar"   << std::endl;
    std::cout << "tiene que ir acompañado por un numero entero mayor a 0"                       << std::endl;
    std::cout << std::endl;
    std::cout << "-bit  ---> ejecuta el programa usando bits como tipo de datos, no es"         << std::endl;
    std::cout << "compatible con los parametros -int (por defecto se usan chars"                << std::endl;
    std::cout << std::endl;
    std::cout << "-int  ---> ejecuta el programa usando enteros como tipo de datos, no es"      << std::endl;
    std::cout << "compatible con los parametros -bit (por defecto se usan chars"                << std::endl;
    std::cout << std::endl;
}

//Comienza funciones globales
bool* get_vecinos(int x, int y, int fil, int col){
    bool* vecinosB=new bool[8];
    int vecinos[8][2]={{x-1,y-1},{x,y-1},{x+1,y-1},{x-1,y},{x+1,y},{x-1,y+1},{x,y+1},{x+1,y+1}};
    for (int i=7 ; i>=0 ; i--){
        if(vecinos[i][0]<0 || vecinos[i][0]>(col-1) || vecinos[i][1]<0 || vecinos[i][1]>(fil-1)){
            vecinosB[i]=false;
        }else{
            vecinosB[i]=true;
        }
    }
    return vecinosB;
}

float generar_numero(){
    return (float)(rand())/RAND_MAX;
}
//Termina funciones globales


//Comienza generacion de matrices vacias
boost::dynamic_bitset<> generar_matriz_bit(int fil, int col){
    boost::dynamic_bitset<> x(fil*col);
    return x;
}

char** generar_vacia_char(int fil, int col){
    char** matriz = new char*[fil];
    for (int i=0 ; i<fil ; i++){
        matriz[i] = new char[col];
        for (int j=0 ; j<col ; j++){
            matriz[i][j]='#';
        }
    }
    return matriz;
}

int** generar_vacia_int(int fil, int col){
    int** matriz = new int*[fil];
    for (int i=0 ; i<fil ; i++){
        matriz[i] = new int[col];
        for (int j=0 ; j<col ; j++){
            matriz[i][j]=0;
        }
    }
    return matriz;
}
//Termina generacion de matrices vacias


//Comienza seccion de mostrar matrices
void mostrar_bit(boost::dynamic_bitset<> matriz, int fil, int col){
    int cont=0;
    for(int i=0;i< fil;i++){
        for(int j=0;j< col;j++){
            std::cout << matriz[(i*col)+j];
            cont++;
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}

void mostrar_char(char **matriz, int fil, int col){
    for(int i=0;i< fil;i++){
        for(int j=0;j< col;j++){
            std::cout<<matriz[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}

void mostrar_int(int **matriz, int fil, int col){
    for(int i=0;i< fil;i++){
        for(int j=0;j< col;j++){
            std::cout<<matriz[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}


//Termina seccion de mostrar matrices


//Comienza seccion de ejecucion del juego de la vida con procesamiento paralelo
boost::dynamic_bitset<> stepP_bit(boost::dynamic_bitset<> matriz, int fil, int col, int32_t nt){
    boost::dynamic_bitset<> vacia=generar_matriz_bit(fil,col);
    #pragma omp parallel for num_threads(nt)
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);
            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    if(matriz[(vecinos[k][0]*col)+vecinos[k][1]]==1){
                        cont=cont+1;
                    }
                }
            }


            if(matriz[(i*col)+j]==0 && cont==3){
                vacia[(i*col)+j]=1;
            }else if(matriz[(i*col)+j]==1 && (cont==2 || cont==3)){
                vacia[(i*col)+j]=1;
            }else{
                vacia[(i*col)+j]=0;
            }

        }
    }
    return vacia;
}

char** stepP_char(char **matriz, int fil, int col, int32_t nt){
    char** vacia=generar_vacia_char(fil,col);
    #pragma omp parallel for num_threads(nt)
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);

            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    if(matriz[vecinos[k][0]][vecinos[k][1]]=='*'){
                        cont=cont+1;
                    }
                }
            }


            if(matriz[i][j]=='#' && cont==3){

                vacia[i][j]='*';
            }else if(matriz[i][j]=='*' && (cont==2 || cont==3)){
                vacia[i][j]='*';
            }else{
                vacia[i][j]='#';
            }

        }
    }
    return vacia;
}

int** stepP_int(int **matriz, int fil, int col, int32_t nt){
    int** vacia=generar_vacia_int(fil,col);
    #pragma omp parallel for num_threads(nt)
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);
            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    if(matriz[vecinos[k][0]][vecinos[k][1]]==1){
                        cont=cont+1;
                    }
                }
            }

            if(matriz[i][j]==0 && cont==3){

                vacia[i][j]=1;
            }else if(matriz[i][j]==1 && (cont==2 || cont==3)){
                vacia[i][j]=1;
            }else{
                vacia[i][j]=0;
            }

        }
    }
    return vacia;
}
//Termina seccion de ejecucion del juego de la vida con procesamiento paralelo

//Comienza seccion de ejecucion del juego de la vida con procesamiento secuencial
boost::dynamic_bitset<> stepS_bit(boost::dynamic_bitset<> matriz, int fil, int col){
    boost::dynamic_bitset<> vacia=generar_matriz_bit(fil,col);
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);
            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    if(matriz[(vecinos[k][0]*col)+vecinos[k][1]]==1){
                        cont=cont+1;
                    }
                }
            }


            if(matriz[(i*col)+j]==0 && cont==3){
                vacia[(i*col)+j]=1;
            }else if(matriz[(i*col)+j]==1 && (cont==2 || cont==3)){
                vacia[(i*col)+j]=1;
            }else{
                vacia[(i*col)+j]=0;
            }

        }
    }
    return vacia;
}

char** stepS_char(char **matriz, int fil, int col){
    char** vacia=generar_vacia_char(fil,col);
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            std::cout << "(" << i << "," << j << ")" << std::endl;
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);
            std::cout << "(vecinos)" << std::endl;
            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    std::cout << "(" << vecinos[k][0] << "," << vecinos[k][1] << ")" << std::endl;
                    if(matriz[vecinos[k][0]][vecinos[k][1]]=='*'){
                        cont=cont+1;
                    }
                }
            }
            if(matriz[i][j]=='#' && cont==3){
                vacia[i][j]='*';
            }else if(matriz[i][j]=='*' && (cont==2 || cont==3)){
                vacia[i][j]='*';
            }else{
                vacia[i][j]='#';
            }
            

        }
    }
    return vacia;
}

int** stepS_int(int **matriz, int fil, int col){
    int** vacia=generar_vacia_int(fil,col);
    for (int i=0 ;  i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            int cont=0;
            int vecinos[8][2]={{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j},{i+1,j},{i-1,j+1},{i,j+1},{i+1,j+1}};
            bool* vecinosB=get_vecinos(i,j,fil,col);
            for (int k=0; k<8 ; k++){
                if(vecinosB[k]){
                    if(matriz[vecinos[k][0]][vecinos[k][1]]==1){
                        cont=cont+1;
                    }
                }
            }
            if(matriz[i][j]==0 && cont==3){
                vacia[i][j]=1;
            }else if(matriz[i][j]==1 && (cont==2 || cont==3)){
                vacia[i][j]=1;
            }else{
                vacia[i][j]=0;
            }
            

        }
    }
    return vacia;
}
//Termina seccion de ejecucion del juego de la vida con procesamiento secuencial

int main(int argc , char *argv []){
    int col=5;
    int fil=5;
    float prob=0.5;
    int32_t nt=omp_get_max_threads();
    bool seq=false;
    bool show=false;
    int iter=5;
    bool d_int=false;
    bool d_bit=false;
    bool flag=false;
    std::string mystr;
    int cont_datos=0;
    for (int i=0; i < argc; i++) {
        mystr=argv[i];
        if (mystr == "-ncol") {
            col = atoi(argv[i+1]);
        }
        if (mystr == "-nfil") {
            fil = atoi(argv[i+1]);
        }
        if (mystr == "-nt") {
            flag=true;
            nt = atoi(argv[i+1]);
        }
        if (mystr == "-plive") {
            prob = atoi(argv[i+1]);
        }
        if (mystr == "-seq") {
            seq = true;
        }
        if (mystr == "-show") {
            show = true;
        }
        if (mystr == "-iter") {
            iter = atoi(argv[i+1]);
        }
        if (mystr == "-bit") {
            d_bit=true;
            cont_datos++;
        }
        if (mystr == "-int") {
            d_int=true;
            cont_datos++;
        }
        if (mystr == "-help" || mystr == "-h") {
            help();
            return (EXIT_SUCCESS);
        }
    }
    if(cont_datos>1){
        std::cout << "solo puede ingresar 1 tipo de dato a la vez, revise los parametros" << std::endl;
        return (EXIT_SUCCESS);
    }

    if(flag && seq){
        std::cout << "los parametros -seq y -nt no son compatibles, porfavor elimine uno de los 2" << std::endl;
        return (EXIT_SUCCESS);
    }


    if(d_bit){
        boost::dynamic_bitset<> matriz = generar_matriz_bit(fil,col);
        int cont=0;
        for (int i=0 ; i<fil ; i++){
            for (int j=0 ; j<col ; j++){
                if(prob>=generar_numero()){
                    matriz[cont]=1;
                }
                cont++;
            }
        }

        if(show){
            mostrar_bit(matriz,fil,col);
        }
        std::cout << std::endl;
        Timer t1;
        double time=0;
        for (int i=0 ; i<iter ; i++){
            t1.start();
            if(seq){
                matriz=stepS_bit(matriz,fil,col);
            }else{
                matriz=stepP_bit(matriz,fil,col,nt);
            }
            t1.stop();
            time=time+t1.elapsed<std::chrono::milliseconds>();
            if(show){
                mostrar_bit(matriz,fil,col);
            }
            
        }
        std::cout << "elapsed:" << time << "ms\n";
        std::cout << "elapsed everage per iteration:" << time/iter << "ms\n";
    }else if(d_int){
        int** matriz = new int*[fil];
        for (int i=0 ; i<fil ; i++){
            matriz[i] = new int[col];
            for (int j=0 ; j<col ; j++){
                if(prob>=generar_numero()){
                    matriz[i][j]=1;
                }else{
                    matriz[i][j]=0;
                }
            }
        }
        if(show){
            mostrar_int(matriz,fil,col);
        }
        Timer t1;
        double time=0;
        for (int i=0 ; i<iter ; i++){
            t1.start();
            if(seq){
                matriz=stepS_int(matriz,fil,col);
            }else{
                matriz=stepP_int(matriz,fil,col,nt);
            }
            t1.stop();
            time=time+t1.elapsed<std::chrono::milliseconds>();
            if(show){
                mostrar_int(matriz,fil,col);
            }
            
        }
        std::cout << "elapsed:" << time << "ms\n";
        std::cout << "elapsed everage per iteration:" << time/iter << "ms\n";
    }else{
        char** matriz = new char*[fil];
        for (int i=0 ; i<fil ; i++){
            matriz[i] = new char[col];
            for (int j=0 ; j<col ; j++){
                if(prob>=generar_numero()){
                    matriz[i][j]='*';
                }else{
                    matriz[i][j]='#';
                }
            }
        }
        if(show){
            mostrar_char(matriz,fil,col);
        }
        Timer t1;
        double time=0;
        for (int i=0 ; i<iter ; i++){
            t1.start();
            if(seq){
                matriz=stepS_char(matriz,fil,col);
            }else{
                matriz=stepP_char(matriz,fil,col,nt);
            }
            t1.stop();
            time=time+t1.elapsed<std::chrono::milliseconds>();
            if(show){
                mostrar_char(matriz,fil,col);
            }
            
        }
        std::cout << "elapsed:" << time << "ms\n";
        std::cout << "elapsed everage per iteration:" << time/iter << "ms\n";
    }
    
    

    return (EXIT_SUCCESS);
}

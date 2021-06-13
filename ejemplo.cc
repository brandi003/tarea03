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

int buscar_matriz(boost::dynamic_bitset<> matriz, int x, int y, int fil, int col){
    return matriz[(y*col)+x];
}

boost::dynamic_bitset<> generar_matriz(int fil, int col){
    boost::dynamic_bitset<> x(fil*col);
    return x;
}
/*
int main()
{
    boost::dynamic_bitset<> x(64); // all 0's by default
    x[0] = 1;
    x[1] = 1;
    x[4] = 1;
    std::cout << sizeof(x) << std::endl; 
    std::cout << sizeof(x[1]) << std::endl;
    for (boost::dynamic_bitset<>::size_type i = 0; i < x.size(); ++i)
        std::cout << x[i];
    std::cout << "\n";
    std::cout << x << "\n";

    return 0;
}*/

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

void mostrar(boost::dynamic_bitset<> matriz, int fil, int col){
    int cont=0;
    for(int i=0;i< fil;i++){
        for(int j=0;j< col;j++){
            std::cout << buscar_matriz(matriz,j,i,fil,col);
            cont++;
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}

boost::dynamic_bitset<> stepP(boost::dynamic_bitset<> matriz, int fil, int col, int32_t nt){
    boost::dynamic_bitset<> vacia=generar_matriz(fil,col);
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
            //std::cout<< i << " " << j << " " << buscar_matriz(matriz,j,i,fil,col) << std::endl;
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
/*
char** stepS(char **matriz, int fil, int col){
    char** vacia=generar_vacia(fil,col);
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
}*/

int main(int argc , char *argv []){
    int col=5;
    int fil=5;
    float prob=0.5;
    int32_t nt=omp_get_max_threads();
	bool seq=false;
	bool show=false;
	int iter=5;

	std::string mystr;
	for (int i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-ncol") {
			col = atoi(argv[i+1]);
		}
		if (mystr == "-nfil") {
			fil = atoi(argv[i+1]);
		}
		if (mystr == "-nt") {
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
	}


    boost::dynamic_bitset<> matriz = generar_matriz(fil,col);
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
		mostrar(matriz,fil,col);
	}
    mostrar(matriz,fil,col);
    std::cout<< matriz[(0*col)+0] <<std::endl;
    std::cout<< matriz[(0*col)+1] <<std::endl;
    std::cout<< matriz[(0*col)+2] <<std::endl;
    std::cout<< matriz[(0*col)+3] <<std::endl;
    std::cout<< matriz[(0*col)+4] <<std::endl;
	Timer t1;
	double time=0;
    for (int i=0 ; i<iter ; i++){
		t1.start();
    	if(seq){
    		//matriz=stepS(matriz,fil,col);
    	}else{
    		matriz=stepP(matriz,fil,col,nt);
    	}
    	t1.stop();
    	time=time+t1.elapsed<std::chrono::milliseconds>();
		if(show){
			mostrar(matriz,fil,col);
		}
    	
    }
    std::cout << "elapsed:" << time << "ms\n";
    std::cout << "elapsed everage per iteration:" << time/iter << "ms\n";
    

    return (EXIT_SUCCESS);
}

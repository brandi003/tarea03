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

void mostrar(bool **matriz, int fil, int col){
    for(int i=0;i< fil;i++){
        for(int j=0;j< col;j++){
            std::cout<<matriz[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}

bool** generar_vacia(int fil, int col){
	bool** matriz = new bool*[fil];
    for (int i=0 ; i<fil ; i++){
    	matriz[i] = new bool[col];
        for (int j=0 ; j<col ; j++){
            matriz[i][j]=0;
        }
    }
    return matriz;
}

bool** stepP(bool **matriz, int fil, int col, int32_t nt, bool **vacia){
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
    		/*
    		#pragma omp critical
    		{
    			std::cout << "(" << i << "," << j << ")" << std::endl;
    		}*/
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

bool** stepS(bool **matriz, int fil, int col, bool **vacia){
    
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
    		//std::cout << "(" << i << "," << j << ")" << std::endl;
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

int main(int argc , char *argv []){
    int col=5;
    int fil=5;
    float prob=0.8;
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


    bool** matriz = new bool*[fil];
    for (int i=0 ; i<fil ; i++){
    	matriz[i] = new bool[col];
        for (int j=0 ; j<col ; j++){
            if(prob>=generar_numero()){
                matriz[i][j]=1;
            }else{
               	matriz[i][j]=0;
            }
        }
    }
    if(show){
		mostrar(matriz,fil,col);
	}
	Timer t1;
	double time=0;
    for (int i=0 ; i<iter ; i++){
    	bool** vacia=generar_vacia(fil,col);
		t1.start();
    	if(seq){
    		matriz=stepS(matriz,fil,col,vacia);
    	}else{
    		matriz=stepP(matriz,fil,col,nt,vacia);
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


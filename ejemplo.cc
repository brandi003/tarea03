#include <global.hh>
#include <Timer.hpp>
#include <iostream>
#include <random>
#include <iomanip>

#include <iostream>
#include <random>
#include <iomanip>

int col;
int fil;

float generar_numero(){
    return (float)(rand())/RAND_MAX;
}
/*
void mostrar(auto matriz, int filas, int columnas){
	for(int i=0;i< filas;i++){
        for(int j=0;j< columnas;j++){
            std::cout<<matriz[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}*/

int main(){
    col=5;
    fil=5;
    float prob=0.8;
    char matriz[fil][col];
    for (int i=0 ; i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            if(prob>=generar_numero()){
                matriz[i][j]='*';
            }else{
                matriz[i][j]='#';
            }
        }
    }
    
    return (EXIT_SUCCESS);
}



/*
int main(int argc , char *argv []) {
	std::random_device dev;  
	
	//Por omisión, se paraleliza con la capacidad del HW
	int32_t nt    = omp_get_max_threads();
	int32_t aSize = 20;
	std::cout << nt << std::endl;
	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
		if (mystr == "-asize") {
			aSize = atoi(argv[i+1]);
		}
	}
	
	auto datos = new uint32_t[aSize];

	std::mt19937 gen(dev()); 
	std::uniform_int_distribution<> unif(0, 10000);

	//LLenar vector con algo...
	Timer t1;
	
	t1.start();
	#pragma omp parallel for num_threads(nt)
	for(size_t i = 0; i < aSize; ++i){	
		datos[i] = unif(gen);
		
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
			std::cout << "thID:" << thID << ", dato[" << i << "]="<< datos[i] << std::endl;
		}
	}
	t1.stop();
	
	std::cout << "elapsed:" <<  t1.elapsed<std::chrono::milliseconds>() << "ms\n";
	
	
	
	return(EXIT_SUCCESS);
}*/

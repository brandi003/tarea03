#include <global.hh>
#include <Timer.hpp>

void get_vecinos(int x, int y, char* matriz, char* vacia){
	fil=sizeof(matriz)/sizeof(matriz[0]);
	col=sizeof(matriz[0])/sizeof(matriz[0][0]);
	int vecinos[]=[[x-1,y-1],[x,y-1],[x+1,y-1],[x-1,y],[x+1,y],[x-1,y+1],[x,y+1],[x+1,y+1]];

	for (size_t i=8;i>=0;i--){
		if(vecinos[i][0]<0 || vecinos[i][0]>(col-1)){
			std::erase(vecinos,vecinos[i]);
			continue;
		}
		if(vecinos[i][1]<0 || vecinos[i][1]>(col-1)){
			std::erase(vecinos,vecinos[i]);
			continue;
		}
	}
}

void mostrar(char* matriz){
	for (size_t i = 0 ; i<(sizeof(matriz)/sizeof(matriz[0])) : i++){
		for (size_t j = 0 ; j < (sizeof(matriz[0])/sizeof(matriz[0][0])) ; j++){
			std::cout << matriz[i][j] << ",";
		}
		std::cout << std:endl;
	}
}

char* matriz_vacia(int col, int fil){
	char[fil][col] vacia;
	for (size_t i = 0 ; i < fil ; i++){
		for (size_t j = 0 ; j < col ; j++){
			vacia[i][j]="#"
		}
	}
	return matriz;
}

int main(int argc , char *argv []) {
	std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0, 1);
	int col=5;
	int fil=5;
	float prob=0.8;
	char[fil][col] matriz;
	for (size_t i = 0 ; i < fil ; i++){
		for (size_t j = 0 ; j < col ; j++){
			if(prob>=distr(eng)){
				matriz[i][j]="*";
			}else{
				matriz[i][j]="#"
			}
		}
	}
	mostrar(matriz);

	return(EXIT_SUCCESS);
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

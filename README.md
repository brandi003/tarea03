---------Comando help ejecutado, se ignoraras los demas parametros--------- 
Descripcion: Este programa simula el juego de la vida de conway que se pidio
para la tarea 03, el programa se puede ejecutar con distintos parametros    
que variara en la ejecucion de el mismo, a continuacion se mostraran los    
parametros permitidos y los valores que pueden tomar.                       
-ncol  ---> sirve para especificar la cantidad de columnas con las que se   
simulara el juego de la vida, este tiene que ir acompañado con un valor     
numerico entero mayor a 0 (de esto depende directamente cuanto se demorara  
en ejecutar el programa)                                                    
-nfil  ---> sirve para especificar la cantidad de filas con las que se      
simulara el juego de la vida, este tiene que ir acompañado con un valor     
numerico entero mayor a 0 (de esto depende directamente cuanto se demorara  
en ejecutar el programa)                                                    
-nt  ---> sirve para especificar la cantidad de procesos con las que se     
simulara el juego de la vida, este tiene que ir acompañado con un valor     
numerico entero mayor a 0 (esto afectara al tiempo que tardara              
en ejecutar el programa) no es compatible con el parametro -seq             
-plive  ---> sirve para especificar la probabilidad de que una celula este  
viva en la generacion inicial del juego de la vida, tiene que tomar valores 
entre 0 y 1, por ejemplo 0.5                                                
-seq  ---> sirve para ejecutar la version secuencial del programa           
-show  ---> mostrar las generaciones a medida que se simula el juego de la  
vida, no es recomendable si el tablero es mayor a 30x30                     
-iter  ---> sirve para especificar cuantas generaciones se quieren generar  
tiene que ir acompañado por un numero entero mayor a 0                      
-int  ---> ejecuta el programa usando enteros como tipo de datos, no es     
compatible con los parametros -bit (por defecto se usan bits)               
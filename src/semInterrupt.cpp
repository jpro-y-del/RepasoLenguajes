#include <Arduino.h>

/*realiazr una solucion programable de un semaforo que contiene tanto uno de
 peatones como uno para vehículos con el detalle que el de peatones cuanta
con un boton para ponerlo en rojo luego de 5 seg, tendran que hacer que el 
semaforo actue normalemente sincronizado a los dos y teniendo en cuenta al 
boton*/ 
int sema1 [3] = {1,2,3};
int sema2 [2] = {4,5};
int i, a, puls, tpred= 0, delaya= 5000;
int sem1 [4] [3]{
  {1,0,0},
  {0,1,0},
  {0,0,1},
  {0,1,0}
};
int sem2 [4] [2]{
  {1,0},
  {1,0},
  {0,1},
  {1,0}
};
void setup (){
  for (i=0;i<3;i++){
    pinMode (sema1[i], OUTPUT);
  }
  for (i=0;i<2;i++){
    pinMode (sema2[i], OUTPUT);
  }
  pinMode (puls,INPUT);
}
void loop (){
  int t_actual= millis();
  for (i=0; i<4; i++){
    if (sem1 [i][1]==1){
      if (t_actual - tpred >= delaya){
        for(a=0;a<3;a++){
          tpred= t_actual;
          digitalWrite (sema1[a], sem1[i][a]);
        }
      }
    }
    else {
        
    }
  }
}
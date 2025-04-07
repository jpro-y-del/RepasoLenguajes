#include <Arduino.h>
/*holi :)*/
/*-realizar dos semaforos utilizando matrices y arrays y millis*/
int i,j, antes = 0, delay= 10000;
int  antes_A = 0, delay_A= 5000;
int t_actual = millis();
int sem1[3]= {1,2,3};
int sem2[3]= {4,5,6};
int semvar1 [6][3]{
  {1,0,0},
  {1,0,0},
  {0,1,0},//2
  {0,0,1},
  {0,1,0},//4
  {1,0,0}
};
int semvar2 [6][3]{
  {0,0,1},
  {0,1,0},//1
  {1,0,0},
  {1,0,0},
  {1,0,0},
  {0,1,0} //5
};

void setup() {
for (i=0;i<3;i++){
pinMode(sem1[i], OUTPUT);
pinMode(sem2[i], OUTPUT);
}
}

void loop() {

  for(j=0;j<6;i++){ //si esta en rojo amarillo o verde
    if(semvar1[j][1]==1||semvar2[j][1]==1){
      for(i=0;i<3;i++){// poner los estados en los pines
        if(t_actual - antes_A>= delay_A){
          antes_A = t_actual;
          digitalWrite(sem1[i],semvar1[j][i]);
          digitalWrite(sem2[i],semvar2[j][i]);
        }
      }
    }
    else{
      for(i=0;i<3;i++){
        if(t_actual - antes>= delay){
          antes = t_actual;
          digitalWrite(sem1[i],semvar1[j][i]);
          digitalWrite(sem2[i],semvar2[j][i]);
        }
      }
      
    }

  }
}
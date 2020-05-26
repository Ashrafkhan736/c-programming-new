#include <stdio.h>
#include <stdlib.h>

struct working_info{
  int month;
  double contribution;
  double rate_of_return;
};
typedef struct working_info retire_info;

double compute(double p, double r, double q){
  p = p + (p * r);
  p = p + q;
  return p;
}

void retirment(int startAge, double initial, retire_info working, retire_info retired){
  int i =0;
  do{
    printf("Age %3d month %2d you have $%.2f\n",(i + startAge)/12, (i + startAge)%12, initial);
  initial = compute(initial, working.rate_of_return, working.contribution);
  i++;
    }
  while(i < working.month );
  int w = 0;
  do{
     printf("Age %3d month %2d you have $%.2f\n",(w + startAge + working.month)/12, (w + startAge + working.month)%12, initial);
    initial = compute(initial, retired.rate_of_return, retired.contribution);

 w++;
  }
  while(w < retired.month);
}

int main(void){
  retire_info working;
  retire_info retired;

  working.month = 489;
  working.rate_of_return = 0.045/12;
  working.contribution = 1000;

  retired.month = 384;
  retired.rate_of_return = 0.01/12;
  retired.contribution = -4000;

  int startAge = 327;
  double initial = 21345;

  retirment(startAge, initial, working, retired);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double compute(double p, double r, double q){
  p = p + (p * r);
  p = p + q;
  return p;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  int i =0;
  do{
    printf("Age %3d month %2d you have $%.2f\n",(i + startAge)/12, (i + startAge)%12, initial);
  initial = compute(initial, working.rate_of_return, working.contribution);
  i++;
    }
  while(i < working.months );
  int w = 0;
  do{
     printf("Age %3d month %2d you have $%.2f\n",(w + startAge + working.months)/12, (w + startAge + working.months)%12, initial);
    initial = compute(initial, retired.rate_of_return, retired.contribution);

 w++;
  }
  while(w < retired.months);
}

int main(void){
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.rate_of_return = 0.045/12;
  working.contribution = 1000;

  retired.months = 384;
  retired.rate_of_return = 0.01/12;
  retired.contribution = -4000;

  int startAge = 327;
  double initial = 21345;

  retirement(startAge, initial, working, retired);
  return 0;
}

// ------------------------------------------
// Solve for Gauge coupling 
//
// Last Modified: Nov 30 2024
// Author: Yasutoki Takamura
// email: y_takamura@hep.s.kanazawa-u.ac.jp
// -----------------------------------------

/*
    Note of math.h
    Usage the value "pi": M_PI
    Power the value: pow(a,b)=a^b
*/

#include<stdio.h>
#include<math.h>
#include<float.h>

# define N 10000 // calculation size

// main plogram
int main(void){

// physical values
  
  double g, a, b;
  double t, t_max, dt;
  double mu, mu_max;
  
/* Table of Standard model
  rge.g1.initialValue = 0.463
  rge.g2.initialValue = 0.654
  rge.g3.initialValue = 1.220
  energy scale = 91.876
*/

  g     = 1.220;
  b     = -7.0;
  mu     = 91.876;       // Initial Energy Scale
  mu_max = pow(10,20);

  t =     log(mu);
  t_max = log(mu_max);

  dt    = t_max/N;
  
  a = pow(g,2.0)/(4.0*M_PI);
  a = pow(a,-1); // Taking inverse for calculation
  b = b/(2*M_PI);
  for(t; t<t_max; t=t+dt){
    printf("%f %f\n", exp(t), a);
    a = a - (b*dt);
  }
  return 0;
}
// EOF

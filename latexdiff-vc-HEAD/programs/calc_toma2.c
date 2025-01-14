// ------------------------------------------
// Solve for Gauge coupling 
//   Add 200 irrep fermion
//
// Last Modified: Dec 02 2024
// Author: Yasutoki Takamura
// email: y_takamura@hep.s.kanazawa-u.ac.jp
// -----------------------------------------

/* Note of math.h
    Usage the value "pi": M_PI
    Power the value: pow(a,b)=a^b
*/

#include<stdio.h>
#include<math.h>
#include<float.h>

# define N 10000 // calculation size

// main plogram
int main(void){

  FILE *fp;

// physical values 
  double g, a, b_in, b, b2, b_F;
  double t, t_max, dt;
  double mu, mu_max;
  double mu_F;

/* Table of Standard model
  rge.g1.initialValue = 0.461425
  rge.g2.initialValue = 0.65184
  rge.g3.initialValue = 1.2143
  energy scale = 91.876
  cf. hep-ph 1306.6879
*/

// Initial condition
  g      =  1.220;      // Coupling constant at Energy = mu
  mu     =  91.876;     // Initial Energy Scale
  b_in   =  -7.0;       // coefficient of one loop

// Calculation setting

  mu_max =  pow(10,20); // Calculation energy range

// 200 Fermion added
  mu_F = 14.0*pow(10,3);
  b_F  = 20.0/3.0;



// Main program ------------------
  t =     log(mu);
  t_max = log(mu_max);

  dt    = t_max/N;
  
  a = pow(g,2.0)/(4.0*M_PI);
  a = pow(a,-1);             // Taking inverse for calculation
  b = b_in/(2*M_PI);
  b2 = b + b_F/(2*M_PI);

  fp = fopen("data.dat","w");

// Calculatin Differential Equation
  printf("g= %f, b_in= %f\n", g, b_in);
  for(t; t<t_max; t=t+dt){
    fprintf(fp, "%f %f\n", exp(t), a);
    if(t>log(mu_F)){
      b = b2;
    }
    a = a - (b*dt);
  }

  fclose(fp);
  return 0;
}
// EOF

// ------------------------------------------
// Solve for Gauge coupling 
// Calculation for 15 representation Higgs
//
// Last Modified: Feb 4 2025
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

# define N 1000000 // calculation size

// main plogram
int main(void){

  FILE *fp;

// physical values 
  double g, a, b_in, b, b2, b3, b_1, b_2;
  double t, t_max, dt;
  double mu, mu_max;
  double mu_1, mu_2;

/* Table of Standard model
  rge.g1.initialValue = 0.461425   b_1 = 41.0/10.0
  rge.g2.initialValue = 0.65184    b_2 = -19.0/6.0
  rge.g3.initialValue = 1.2143     b_3 = -7.0
  energy scale = 91.876
  cf. hep-ph 1306.6879
*/

// Initial condition
// NOTE: This program is fixed for SU(2) (regularized in SU(5)) running gauge coupling.
  g      =  0.65184;      // Coupling constant at Energy = mu
  mu     =  91.876;       // Initial Energy Scale [GeV]
  b_in   =  -19.0/6.0;    // coefficient of one loop

// Calculation setting

  mu_max =  pow(10,20); // Calculation energy range

//  Intermediate Particle
  mu_1 = 1800; // The Scale where the particle added [GeV]
  b_1  = 1.0/2.0; // Value of Additional b value

  mu_2 = 7060000000000; // The Scale where the particle added [GeV]
  b_2  = 2.0/3.0; // Value of Additional b value

// Main program ------------------
// DO NOT EDIT BELOW
// ---------------------
  t =     log(mu);
  t_max = log(mu_max);

  dt    = t_max/N;
  
  a = pow(g,2.0)/(4.0*M_PI);
  a = pow(a,-1);             // Taking inverse for calculation
  b = b_in/(2*M_PI);
  b2 = b + b_1/(2*M_PI);
  b3 = b2 + b_1/(2*M_PI);

  fp = fopen("data.dat","w");

// Calculatin Differential Equation
  printf("g= %f, b_in= %f\n", g, b_in);
  for(t; t<t_max; t=t+dt){
    fprintf(fp, "%f %f\n", exp(t), a);
    if(t>log(mu_1) && log(mu_2)>t ){
      b = b2;
    }
    if(t>log(mu_2)){
      b = b3;
    }
    a = a - (b*dt);
  }
  fclose(fp);
  return 0;
}
// EOF

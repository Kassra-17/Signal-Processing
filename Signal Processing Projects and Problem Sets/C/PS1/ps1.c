#include <stdio.h> // standard input / output library
#include <complex.h> // includes complex number library 
#include <math.h> // includes math ibrary 


void problem1(void) {
    double magnitude=0.5; // defines the magnitude of the complex number as a double = 0.5 
    double angle = M_PI/4.0; // assigns the argument of the complex number using M_PI as pi 
    double complex z=magnitude*cexp(I*angle); //  defines our complex value z 
    double complex z_conj=conj(z); // conjugates z 
    double complex z_sum=z+z_conj; // sums z and its conjugate for more efficient computation for f 

    printf("Re(z)=%.3f\n", creal(z)); // prints real componetn of z 
    printf("Im(z)=%.3f\n", cimag(z)); // prints imag componetn of z 
    printf("|z|=%.3f\n", cabs(z)); // prints magnitude of z 
    printf("Arg(z)=%.3f\n", carg(z)); // prints arg of z 
    printf("z* = %.3f %+.3fi\n", creal(z_conj), cimag(z_conj));  
    printf("z+z* = %.3f %+.3fi\n", creal(z_sum), cimag(z_sum));  
}


int main(void) { 
    problem1(); 
}
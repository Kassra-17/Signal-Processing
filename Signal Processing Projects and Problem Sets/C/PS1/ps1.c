#include <stdio.h> // standard input / output library
#include <complex.h> // includes complex number library 
#include <math.h> // includes math ibrary 
#include <stdlib.h> // 


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


// problems 2 - 4, not applicable in c, require symbolic evaluation of functions 

void problem5(void) { 
    double magnitude = 2.0/3.0; // makes the magnitude of our new complex number 2/3 
    double angle = M_PI/6.0;  // defines the angle of our complex number 
    double complex z=magnitude*cexp(I*angle); // defines z as the complex number for plotting later 

    double complex z_conj=conj(z); // defines z_conj as the complex conjugate of z 
    double complex z_squared=cpow(z,2.0); // uses cpow from math.h to raise z to the 2nd power 
    double complex iz=I*z; // computes i*z 
    double complex zzstar=z*conj(z); // computes z*z^* 
    double complex zoverzstar=z/conj(z); // computes z/z^* 
    double complex oneoverz=1/z; // computes 1/z 


    typedef struct { // defines a new type of structure called complexcoord which consists of two side by side doubles, the real and imag are the field placeholders 
        double real; 
        double imag; 
    } complexcoord; 

    complexcoord a = {creal(z_conj), cimag(z_conj)}; // defines a as a structure of type complexcoord consisting of real and imag components of z_conj 
    complexcoord b = {creal(z_squared), cimag(z_squared)}; // defines b as a structure of type complexcoord consisting of real and imag components of z_squared
    complexcoord c = {creal(iz), cimag(iz)}; // defines c as a structure of type complexcoord consisting of real and imag components of iz 
    complexcoord d = {creal(zzstar), cimag(zzstar)}; // defines d as a structure of type complexcoord consisting of real and imag components of zzstar
    complexcoord e = {creal(zoverzstar), cimag(zoverzstar)}; // defines e as a structure of type complexcoord consisting of real and imag components of zoverzstar 
    complexcoord f = {creal(oneoverz), cimag(oneoverz)}; // defines f as a structure of type complexcoord consisting of real and imag components of oneoverz

    FILE *fp = fopen("/Users/penguin/Desktop/Signal-Processing/Signal Processing Projects and Problem Sets/C/PS1/problem5_data.csv", "w"); // either opens or writes problem5_data.csv 
    if (fp == NULL) {perror("fopen failed");
        return; 
    }

    fprintf(fp,"label,real,imag\n"); // creates csv header using fprintf and fp to write directly
    fprintf(fp,"z*,%f,%f\n",a.real,a.imag); // each of a - f here is printed to our file using fprintf and fp 
    fprintf(fp,"z^2,%f,%f\n",b.real, b.imag);
    fprintf(fp,"iz,%f,%f\n",c.real,c.imag);
    fprintf(fp,"zz*,%f,%f\n",d.real,d.imag);
    fprintf(fp,"z/z*,%f,%f\n",e.real,e.imag);
    fprintf(fp,"1/z,%f,%f\n",f.real,f.imag);
fclose(fp); // finishes the writing process 

int result = system("/Users/penguin/Desktop/Signal-Processing/.venv/bin/python3 \"/Users/penguin/Desktop/Signal-Processing/Signal Processing Projects and Problem Sets/C/PS1/plot_problem5.py\"");
    if (result !=0) {
    printf("Plot script failed to execute. \n"); 
    }

}



void problem7(void) {
    double t_min = 2.0; // defines lower bound when constructing our linspace 
    double t_max = 100.0; // defines upper bound for linspace (100 is our approximation of infinite here) 
    double del_t = 0.1; // gives granularity for the linspace array
    int n_steps = (int) (t_max-t_min)/(del_t); // translates bounds / granularity into an integer 
    double *t_values=malloc(n_steps*sizeof(double)); // allocates memory using malloc, according to the memory allocation for 1 double * the number of elements we need 
    double *ft=malloc(n_steps*sizeof(double)); // allocates memory using malloc, according to the memory allocation for 1 double * the number of elements we need 
    double integral=0.0; // preallocates for the double that will contain the "answer" to the integral 

    for (int i=0; i < n_steps; i++) { // builds a forloop that indexes from i = 0 until i < n_steps, i++ iterates i by 1 per loop 
        t_values[i]=t_min+i*del_t; // iteratively populate t_values at the ith index 
        ft[i]=exp(-3.0*t_values[i]); // iterativly populates ft 
        integral += ft[i]*del_t; // uses f(t)*del_t to compute the "integrand", then uses += iteratively to loop the sum, giving an estimate of the definite integral 

    }
            printf("Integral from 2 to inf. of e^(-3t) is approximately: %.3f\n", integral);   // print command attempt 


}


int main(void) { 
    problem1(); 
    problem5(); 
    problem7(); 

}

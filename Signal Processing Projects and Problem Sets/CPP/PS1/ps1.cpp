#include <iostream> // grabs input/output streams
#include <cmath> // grabs math functions 
#include <complex> // grabs complex math functions 
#include <ginac/ginac.h> // grabs symbolic math library and supporting cast for that 
#include <numbers> // allows us to use things like pi 
#include "matplotlibcpp.h"
namespace plt=matplotlibcpp; // defines namespace plt for matplotlib-cpp 
using namespace std::numbers; // allows us to recognize pi as a pre-defined function 
using namespace std::literals::complex_literals; // allows the script to access the cmplex_literals namesspace for easier access to complex i 
using namespace GiNaC; // enables namespace GiNaC 

void problem1() { // opens an "undefined" block of code that allows us to perform a section of computations distinct to problem1 
auto z = 0.5 * std::exp(1i*pi/4.0); // defines the parent function of z 


// Problem 1 
auto a1=std::real(z);  // defines the real part of z 
auto b1=std::imag(z); // defines the imag part of z 
auto c1=std::abs(z); // magnitude of z 
auto d1=std::arg(z); // argument of z 
auto e1=std::conj(z); // takes complex conjugate of  z
auto f1=z+std::conj(z); // sums z and its complex conjugate 

std::cout << "Problem 1a:" << a1 << "\n"; // print commands 
std::cout << "Problem 1b:" << b1 << "\n"; 
std::cout << "Problem 1c:" << c1 << "\n";
std::cout << "Problem 1d:" << d1 << "\n";
std::cout << "Problem 1e:" << e1 << "\n";
std::cout << "Problem 1f:" << f1 << "\n";


}



// Problem 2 

void problem2() { // opens a new void for problem 2, allowing us to define the "funciton" of problem 2 for later calling 

    realsymbol a("a"), b("b"); // defines two variables, a, and b 
    ex z = a+b*I; // ex is used to define an expression 
    ex lhsa = real_part(z); // defines that the left hand side is real(z) 
    ex rhsa = (z + conjugate(z))/2; // rhs is z +z* 
    ex rhs_simpa=rhsa; // declares rhs_simp before using it later 

    rhs_simpa=rhsa.normal(); // sample simplifcation for rhs to see what it can do for printing 

    ex diffa = (lhsa - rhs_simpa).normal(); // defines an expression diff that allows us to subtract lhs from simplified rhs

    ex lhsb = imag_part(z)*I; // defines the lhs of the proof for problem 2b 
    ex rhsb = (z-conjugate(z))/2; // defines rhs of the proof for 2b 
    ex rhs_simpb = rhsb; // declarses rhs_simmpb as an expression 

    rhs_simpb=rhsb.normal(); // simplifies rhs of the equation 
    ex diffb = (lhsb - rhs_simpb).normal(); // defines diff to check if difference of lhs and rhs is 0 later 
    
    std::cout << "2a: Re(z)=(z+z^*)/2 is " << (diffa.is_zero() ? "true\n" : "false\n"); // prints a verbal confirmation of the equality that was verified via diff 
    std::cout << "2b: Im(z)*I=(z-z^*)/2 is " << (diffb.is_zero() ? "true\n" : "false\n"); // prints a verbal confirmation of the equality that was verified via diff 



}



// Problem 3 

void problem3() { // opens void for problem 3 

    realsymbol theta("theta"); // defines a variable theta 
    ex EI_lhs=exp(I*theta); // defines lhs of eulers identity 
    ex EI_rhs=cos(theta)+I*sin(theta); // rhs of eulers 
    ex EI_lhs_neg=exp(-I*theta); // defines lhs of eulers identity 
    ex EI_rhs_neg=cos(theta)-I*sin(theta); // rhs of eulers 
    ex lhs_a = cos(theta); // defines the lefthandside as cosine 
    ex lhs_b = sin(theta); // defines lefthandside of b as sin theta 
    ex rhs_a=(exp(I*theta)+exp(-I*theta))/2;  // defines rhs of proof relationship 
    ex rhs_b=(exp(I*theta)-exp(-I*theta))/(2*I); // defines rhs of proof relationship   
    ex rhs_sub_a=rhs_a.subs(EI_lhs == EI_rhs).subs(EI_lhs_neg==EI_rhs_neg); 
    ex rhs_sub_b=rhs_b.subs(EI_lhs == EI_rhs).subs(EI_lhs_neg==EI_rhs_neg); 
    ex rhs_simplify_a=rhs_sub_a.normal(); // simplifies rhs of equation 
    ex rhs_simplify_b=rhs_sub_b.normal(); // simplifies rhs of equation 
    ex diff_a=(lhs_a-rhs_simplify_a).normal(); // simplifies the expression lhs - rhs 
    ex diff_b=(lhs_b-rhs_simplify_b).normal(); // simplifies the expression lhs - rhs 

    std::cout << "3a: (cos(theta)=exp(i*theta)+exp(-i*theta))/2 is " << (diff_a.is_zero() ? "true\n" : "false\n"); // checks if diff_a is zero and outputs differnet resonses based on outcome 
    std::cout << "3b: (sin(theta)=exp(i*theta)+exp(-i*theta))/2i is " << (diff_b.is_zero() ? "true\n" : "false\n"); // checks if diff_a is zero and outputs differnet resonses based on outcome 


}



// Problem 4 

void problem4() {


    realsymbol r("r"), theta("theta)"); // defines r and theta for polar coordinate evaluation 
    ex z=r*exp(I*theta); // defines polar z 
    ex a4=conjugate(z); // defines 4a as the conjugate of z 
    ex b4 = z*z; // defines 4b as z^2 
    ex c4 = I*z; // defines 4c as Iz 
    ex c4_simplified=c4.normal(); // simplifies expression d4 
    ex d4 = z*conjugate(z); // 4d as z times its conjugate 
    ex d4_simplified=d4.normal(); // simplifies expression d4 
    ex e4 = z/conjugate(z); // 4e as z/ its conjugate 
    ex e4_simplified=e4.normal(); // simplifies expression d4 

    ex f4 = 1/z; 


std::cout << "Problem 4a:" << a4 << "\n"; // print commands 
std::cout << "Problem 4b:" << b4 << "\n"; 
std::cout << "Problem 4c:" << c4_simplified << "\n";
std::cout << "Problem 4d:" << d4_simplified << "\n";
std::cout << "Problem 4e:" << e4_simplified << "\n";
std::cout << "Problem 4f:" << f4 << "\n";



}









int main() { // allows us to start the code 
    problem1(); 
    problem2(); 
    problem3(); 
    problem4();



    std::vector<double> x {1, 2, 3, 4, 5};
    std::vector<double> y {1, 4, 9, 16, 25};

    plt::plot(x, y);
    plt::title("matplotlib-cpp Smoke Test");
    plt::show();

    return 0;
}
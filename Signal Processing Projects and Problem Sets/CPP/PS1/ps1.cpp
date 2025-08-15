#include <iostream> // grabs input/output streams
#include <cmath> // grabs math functions 
#include <complex> // grabs complex math functions 
#include <vector> // includes vector functions from std 
#include <string> // includes strings 
#include <ginac/ginac.h> // grabs symbolic math library and supporting cast for that 
#include <numbers> // allows us to use things like pi 
#include "matplotlibcpp.h" // allows for matplotlib like plotting in cpp 
#include <stdexcept> // 
#include <algorithm>// 
#include <utility>// 
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

void problem5() { 

    auto z=2.0/3.0*std::exp(pi/6.0*1i); // defines a numerical z formula
    
    auto a5=std::conj(z); // defines 4a as the conjugate of z 
    auto b5 = z*z; // defines 4b as z^2 
    auto c5 = 1i*z; // defines 4c as Iz 
    auto d5 = z*std::conj(z); // 4d as z times its conjugate 
    auto e5 = z/std::conj(z); // 4e as z/ its conjugate 
    auto f5 = 1.0/z; 

    std::vector<std::complex<double>> z_vals {a5,b5, c5,d5,e5,f5}; // defines a vector z_vals which constains complex doubles a5 --> f5
    
    std::vector<std::string> labels = { // legend labels 
        "conj(z)",
        "z*z",
        "i*z",
        "z*conj(z)",
        "z/conj(z)",
        "1/z"
    };



for (size_t i=0; i < z_vals.size(); ++i) { // builds forloop, looping i from 0 to zvals.size() which returns a size_t variable type, ++i indexes the counter, increasing by 1 per loop 
 const auto& zi = z_vals[i];   // const prevents zi from being modified in loop, auto& indexes zi rather than copy the zi^th element of z_vals 
    std::vector<double> xs {0.0, std::real(zi)}; // defines a vector xs corresponding to the real part of the element of z_vals referenced by zi 
    std::vector<double> ys {0.0, std::imag(zi)}; // defines a vector xs corresponding to the imag part of the element of z_vals referenced by zi
    plt::plot(xs,ys, {{"label", labels[i]}, {"marker","o"}}); // plots in the loop, assigns labels based on legend labels defined earlier 


}

    plt::axhline(0.0, 0.0, 1.0, {{"color","black"},{"linestyle","--"}});// plotting modifiers 
    plt::axvline(0.0, 0.0, 1.0, {{"color","black"},{"linestyle","--"}});
    plt::axis("equal"); 
    plt::title("Problem 5 Plots");
    plt::xlabel("Real Axis");
    plt::ylabel("Imaginary Axis");
    plt::grid(true); 
    plt::legend(); 
    plt::show(); 


}


void problem6() {
    realsymbol x("x"), t("t"); // defines x and t for symbolic evaluation 
    ex xt=-1.0/3.0*t+1; // defines the main function x(t) 
    std::vector<double> t_vals; // defines a vector double t_vals 
    int N=2; // defines the number of points in t_vals as an integer 
    double start = 0.0; // defines double for starting point 
    double end = 3.0; // defines double for ending point 
    double step = (end-start)/(N-1); // defines the stepsize based on end-start/(N-1)

    for (int i=0; i <N; ++i) { // sets up the forloop to iterate from integer i=0 so long as i<N, ++i means iterate by counts of 1 
        t_vals.push_back(start +i*step); // uses push_back to populate t_vals based on i 
    }

    std::vector<GiNaC::ex> t_transforms{-t, t+2, 2*t+2, 1-3*t}; // defines a vector of symbolic GiNac expressions that is populatedby 4 transforms applied to t
    std::vector<std::pair<double,double>> t_bounds_new; // makes a vector which consists of doubles called t_bounds_new
    std::vector<std::pair<double,double>> y_evals_new; // makes a vector which consists of doubles called y_evals_new

    std::vector<GiNaC::ex> xt_transform(t_transforms.size()); // creates a container for our transformed xt functions based on size of t_transforms 
    t_bounds_new.reserve(t_transforms.size()); // preallocates memory to t_bounds_new based on the size of t_transforms which is defined 1 line above 

    std::vector<std::string> labels = { // legend labels 
        "-t",
        "t+2",
        "2t+2",
        "1-3t"
    };


    for (size_t i=0; i< t_transforms.size(); ++i) { // defines the forloop as iterating from i=0 until the size_t of t_transforms and iterates in increments of 1 (++i)
        ex t_min_transformed=t_transforms[i] - *std::min_element(t_vals.begin(),t_vals.end()); // generates an expression for t_min_transformed which uses the current transform based on forloop and the min bound of our original t val to be simplified later 
        ex t_max_transformed=t_transforms[i] - *std::max_element(t_vals.begin(),t_vals.end()); // generates an expression for t_max_transformed which uses the current transform based on forloop and the max bound of our original t val to be simplified later 
        t_min_transformed = lsolve(t_min_transformed==0,t); // solves for the root of t_min transformed in terms of t
        t_max_transformed = lsolve(t_max_transformed==0,t); // solves for the root of t_min transformed in terms of t
        t_min_transformed=t_min_transformed.evalf(); // evaluates the expression t_min_transformed numerically using evalf 
        t_max_transformed=t_max_transformed.evalf(); // evaluates the expression t_min_transformed numerically using evalf 
        double t1 = ex_to<numeric>(t_min_transformed).to_double(); // converts from ex to double 
        double t2 = ex_to<numeric>(t_max_transformed).to_double(); // converts from ex to double 


        ex xt_substitute = xt.subs(t==t_transforms[i]); // substitutes the transforms for t_transforms into xt and converts to an expression 
        xt_substitute = xt_substitute.normal(); 
        xt_transform[i]=xt_substitute; 

        



        if (t1 > t2) std::swap(t1,t2); // if t1 is larger than t2,swap their ordering
        t_bounds_new.emplace_back(t1,t2); // appends t1,t2 into t_bounds new, so that at the end of the forloop we will have our transformed bounds 

        // auto [t1,t2] = t_bounds_new[i]; // pulls t1 and t2 from t_bounds_new[i] for use in evaluating the transformed xts at the right new bounds 
        double y1=ex_to<numeric>(xt_transform[i].subs(t==t1).evalf()).to_double(); 
        double y2=ex_to<numeric>(xt_transform[i].subs(t==t2).evalf()).to_double(); 
        y_evals_new.emplace_back(y1,y2); // appends y1 and y2 into y_bounds new 

        std::vector<double> xs {t1,t2}; // stores the t bounds in a double for plotting 
        std::vector<double> ys {y1,y2}; // stores the relevant y bounds in a double for plotting 
        plt::plot(xs,ys, {{"label", labels[i]}});
        
    }

        plt::axhline(0.0, 0.0, 1.0, {{"color","black"},{"linestyle","--"}}); // adds axis lines 
        plt::axvline(0.0, 0.0, 1.0, {{"color","black"},{"linestyle","--"}});

        plt::axis("equal"); // axis scaling 
        plt::title("Problem 6 Plots"); // title 
        plt::xlabel("t");// x label 
        plt::ylabel("x(t)");// ylabel 
        plt::grid(true); // gridlines 
        plt::legend(); // legend 
        plt::show(); 
        



// for (const auto& [t1, t2] : t_bounds_new) {
//     std::cout << "(" << t1 << ", " << t2 << ")\n";
// }


// for (size_t i = 0; i < xt_transform.size(); ++i) {
//     std::cout << "Transform " << i << ": " << xt_transform[i] << "\n";
// }


}






int main() { // allows us to start the code 
    problem1(); 
    problem2(); 
    problem3(); 
    problem4();
    problem5(); 
    problem6(); 
    problem7(); 

}
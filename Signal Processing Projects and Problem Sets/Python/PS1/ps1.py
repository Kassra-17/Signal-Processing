import numpy as np
import sympy as sp 
import matplotlib.pyplot as plt
z=0.5*np.exp(1j*np.pi/4) # Defines an equation for problem 1 outside of the functions that will utilize it later 

def problem1a(z): # defines function problem1a as a function of z 
    return z.real # actually acheives the function, which is to take the real component of z 
def problem1b(z): # defines function problem1b as a function of z 
    return z.imag # actually acheives the function, which is to take the imaginary component of z 
def problem1c(z): # defines function problem1c as a function z 
    return np.abs(z) # acutally acheives the function which is to take the magnitude of our complex number 
def problem1d(z): # defines function problem1d as function of z  
    return np.angle(z) # actually achieves function which is to take the argument/phase angle of z
def problem1e(z): # defines function problem1e as function of z 
    return np.conjugate(z) # actually acheives the function which is to take the complex conjugate of z 
def problem1f(z): # defines function problem1f as a function of z 
    return z+np.conjugate(z) # actually acheives the function which is to sum z and it's complex conjugate 

result1a=problem1a(z) # returns function problem1a(z) to result1a 
result1b=problem1b(z) # returns function problem1b(z) to result1b 
result1c=problem1c(z) # returns function problem1c(z) to result1c 
result1d=problem1d(z) # returns function problem1d(z) to result1d 
result1e=problem1e(z) # returns function problem1e(z) to result1e 
result1f=problem1f(z) # returns function problem1f(z) to result1f 

print("1a:", result1a) # prints answer for 1a
print("1b:", result1b) # prints answer for 1b
print("1c:", result1c) # prints answer for 1c
print("1d:", result1d) # prints answer for 1d
print("1e:", result1e) # prints answer for 1e
print("1f:", result1f) # prints answer for 1f


a,b=sp.symbols('a b', real=True) # defines a and b as symbolic variables that are real (non imaginary)
z=a+b*sp.I # defines z as an arbitrary imaginary number consisting 
z_conj=sp.conjugate(z) 
lhs=sp.re(z) # defines left hand side of our "proof"
rhs=(z+z_conj)/2 # defines right hand side of our "proof"
proof = sp.simplify(lhs-rhs)==0 # defines proof as checking if simplification of lhs-rhs is 0, true if = 0, false if =/=0
print(f"2a: {lhs} = {rhs} -> {proof}") # prints our "proof" answer, indicating the rhs = lhs check is true 

lhs=sp.I*sp.im(z) # defines left hand side of our "proof"
rhs=(z-z_conj)/2 # defines right hand side of our "proof"
proof = sp.simplify(lhs-rhs)==0 # defines proof as checking if simplification of lhs-rhs is 0, true if = 0, false if =/=0
print(f"2b: {lhs} = {rhs} -> {proof}") # prints our "proof" answer, indicating the rhs = lhs check is true 


theta=sp.symbols('theta',real=True) # defines theta as a symbolic variable that is real 
lhs=sp.cos(theta) # defines the left hand side of our "proof"
rhs=(sp.exp(sp.I*theta)+sp.exp(-1*sp.I*theta))/2 # defines the right hand side of our proof 
proof = sp.simplify(lhs-rhs)==0 # defines proof as checking if simplifcation of lhs-rhs is 0, true if = 0 and, false if =/=0 
print(f"3a: {lhs} = {rhs} -> {proof}")


# lhs=sp.sin(theta) # defines the left hand side of our "proof"
# rhs=(sp.exp(sp.I*theta)-sp.exp(-1*sp.I*theta))/(2*sp.I) 
# diff=sp.simplify(lhs-rhs)
# proof=sp.simplify(lhs-rhs)==(0)
# print(f"3b: {lhs} = {rhs} -> {proof}")

z,r,theta=sp.symbols('z r theta', real=True, positive=True) # defines z and r as symbolic variables that is real 
z=r*sp.exp(sp.I*theta) # defines z as an imaginary number with polar form 

def problem4a(z): # defines function problem4a as a function of z 
    return sp.conjugate(z) # acheives the function which is to take the complex conjugate of z symbolically 
def problem4b(z): # defines function problem4b as a function of z 
    return z**2 # acheives the fucntion which is to take the square of z symbolically 
def problem4c(z): # defines the function problem4c as a function of z 
    return sp.I*z  # acheives the function which is to multiply i by z
def problem4d(z): # defines the function problem4d as a function of z 
    return z*sp.conjugate(z) # acheives the function which is to multiply z by its complex conjugate 
def problem4e(z): # defines the function problem4e as a function of z 
    return z/sp.conjugate(z) # acheives the function which is to take z and divide it by its complex conjgate 
def problem4f(z): # defines the function problem4f as a function of z 
    return 1/z # acheives the function which is to take the inverse of z 



result4a=problem4a(z) # calls function problem4a using caller result4a
result4b=problem4b(z) # calls function problem4b using caller result4b
result4c=problem4c(z) # calls function problem4c using caller result4c
result4d=problem4d(z) # calls function problem4c using caller result4d
result4e=problem4e(z) # calls function problem4d using caller result4e 
result4f=problem4f(z) # calls function problem4e using caller result4f

print("4a:", result4a) # prints result for 4a 
print("4b:", result4b) # prints result for 4b
print("4c:", result4c) # prints result for 4c 
print("4d:", result4d) # prints result for 4d
print("4e:", result4e) # prints result for 4e 
print("4f:", result4f) # prints result for 4e 


z=2/3*np.exp(1j*np.pi/6) # defines z globally for use in problem 5 

def problem5a(z): # defines function problem5a as a function of z 
    return np.conj(z) # acheives the function which is to take the complex conjugate of z symbolically 
def problem5b(z): # defines function problem5b as a function of z 
    return z**2 # acheives the fucntion which is to take the square of z symbolically 
def problem5c(z): # defines the function problem5c as a function of z 
    return 1j*z  # acheives the function which is to multiply i by z 
def problem5d(z): # defines the function problem5d as a function of z 
    return z*np.conj(z) # acheives the function which is to multiply z by its complex conjugate 
def problem5e(z): # defines the function problem5e as a function of z 
    return z/np.conj(z) # acheives the function which is to take z and divide it by its complex conjgate 
def problem5f(z): # defines the function problem5f as a function of z 
    return 1/z # acheives the function which is to take the inverse of z 

z_vals=[  # defines the z_values to iterate through via forloop for plotting in problem 5
    problem5a(z),
    problem5b(z),
    problem5c(z),
    problem5d(z),
    problem5e(z),
    problem5f(z)]

labels =[ # adds labels for use in the legend 
    r"z$^*$",
    r"z$^2$",
    "iz",
    r"zz$^*$",
    r"z/z$^*$",
    "1/z"

]


plt.figure(1,figsize=(6,6)) # creates a 6x6 inch figure for plotting 


for zi,label in zip(z_vals, labels):  # zi loops through z_vals, zi is not an index but the actual z_vals values, the label in zip also applies the legend labels 
    plt.plot([0,zi.real],[0,zi.imag],label=label, marker='o') # plots a line on the figure, format is ([x1,y1]) ([x2,y2])

plt.axhline(0,color='black',linestyle='--') # defines horizontal (x) axis, colors axis black, uses -- for dashes in axis 
plt.axvline(0,color='black',linestyle='--') # defines vertical (y) axis, colors axis black, uses -- for dashes in axis 
plt.grid(True) # adds a grid to the plot 
plt.gca().set_aspect('equal') # makes the axes equal in widht/verticality? 
plt.title('Problem 5 Plots') # adds a title 
plt.legend() # adds a legend to the plot 
plt.xlabel('Real Axis') # adds x axis title 
plt.ylabel('Imaginary Axis') # adds y axis title 

plt.show()


def x(t): # defines the parent function x(t) for problem 6 
    return -1/3*t-1

t=np.linspace(0,3,2) # defines the linear array t that will be used in problem 5 

t_min=np.min(t) # extracts min of t array 
t_max=np.max(t)  # extracts max of t array
t_sym=sp.symbols('t_sym',real=True) # defines t as a symbolic variable for domain shift re-evaluations 

# xt_sym=-1/3 * t_sym +1 # defines a symbolic version of x(t)  

lhs=[-t_sym,
     t_sym+2, 
     2*t_sym+2,
     1-3*t_sym] # defines the domain transforms for problem 6a-6d

labels=[ # labels for the legend 
    "a",
    "b",
    "c",
    "d"
]

t_input=np.zeros((len(lhs),len(t))) # defines t bound as a 4x2 array of zeros to be populated with the modified domains after the forloop 
x_transforms=np.zeros((len(lhs),len(t))) # defines x_transforms where we will apply the computed transforms later 

for (i, lhs_i), label in zip(enumerate(lhs),labels):  # sets up the forloop 
    t_min_transformed=sp.solve(lhs_i-t_min,t_sym)[0]  # 
    t_max_transformed=sp.solve(lhs_i-t_max,t_sym)[0]  # solves the equation by setting the lhs functions to the origianl bounds for this problem 
    t_min_transformed=sp.simplify(t_min_transformed) # computes the new bounds for the domain symbolically using sp.simplify 
    t_max_transformed=sp.simplify(t_max_transformed) 
    t1=float(t_min_transformed)
    t2=float(t_max_transformed) # converts the outputs of the transformed domain bounds from symbols to a numerical version 
    t_start,t_end = sorted([t1,t2]) # sorts the new domains so that we have the lower value first 
    t_input[i,:]=np.linspace(t_start,t_end,len(t)) # generates array for the adjusted domain for each loop 
    x_funcs=sp.lambdify(t_sym, sp.simplify(-1/3*lhs_i+1)) # symbolically evaluates x(t) then converts using lambdify into a function that can accept numerical strings 
    x_transforms[i,:]=x_funcs(t_input[i,:]) # plugs the transformed t into x(t) 
    plt.plot(t_input[i,:],x_transforms[i,:],label=label) # plots the adjusted domains vs the adjusted signal 


plt.legend() # adds a legend 
plt.axhline(0,color='black',linestyle='--') # defines horizontal (x) axis, colors axis black, uses -- for dashes in axis 
plt.axvline(0,color='black',linestyle='--') # defines vertical (y) axis, colors axis black, uses -- for dashes in axis 
plt.grid(True) # adds a grid to the plot 
plt.gca().set_aspect('equal') # makes the axes equal in widht/verticality? 
plt.title('Problem 6 Plots (FINALLY)') # adds a title 
plt.legend() # adds a legend to the plot 
plt.xlabel('x(t)') # adds x axis title 
plt.ylabel('t') # adds y axis title 
plt.show() # generates the plot 




t,a=sp.symbols('t a', real=True) # defines t and a symbolically for evaluation in the symbolic integral 
fa=sp.exp(-2*t) # defines the exponential function 


integral_a=sp.integrate(fa,(t,0,a)) # evaluates the integral symbolically from 0 to a 
print("7b:", integral_a) # prints the result 

fb=sp.exp(-3*t) # defines exp. function for problem b 
integral_b=sp.integrate(fb, (t, 0, sp.oo)) # evaluates integral from 0 to inf. for b 
print("7b:" ,integral_b)


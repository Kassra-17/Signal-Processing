import numpy as np
import sympy as sp 
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

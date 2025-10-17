import numpy as np
import matplotlib.pyplot as plt
import csv 


labels=[] # creates an empty variable called labels that we'll populate using the .csv later 
z_vals=[] # see above 

with open("problem5_data.csv", newline='') as csvfile: # uses with to read the csvfile, and uses newline ='' to keep things clean by deferring to .csvs defautl newline stuff , refers to the csvfile  as csvfile 
    reader = csv.DictReader(csvfile) # uses dcitReader from the csv library to convert csvfile into a row based dictionary for easy reference 
    for row in reader: # generates the forloop 
        print(row)
        labels.append(row["label"]) # for each iteration of forloop, append row corresponding to the top label "label" into the label variable 
        z_vals.append((float(row["real"]), float(row["imag"]))) # see above, but adapted for the real and imag values of z_vals 




plt.figure(1,figsize=(6,6)) # creates a 6x6 inch figure for plotting 


for (real,imag),label in zip(z_vals, labels):  # (real,imag),label loops through z_vals and labels zipped togehter  
    plt.plot([0, real],[0,imag],label=label, marker='o') # plots a line on the figure, format is ([x1,y1]) ([x2,y2])

plt.axhline(0,color='black',linestyle='--') # defines horizontal (x) axis, colors axis black, uses -- for dashes in axis 
plt.axvline(0,color='black',linestyle='--') # defines vertical (y) axis, colors axis black, uses -- for dashes in axis 
plt.grid(True) # adds a grid to the plot 
plt.gca().set_aspect('equal') # makes the axes equal in widht/verticality? 
plt.title('Problem 5 Plots') # adds a title 
plt.legend() # adds a legend to the plot 
plt.xlabel('Real Axis') # adds x axis title 
plt.ylabel('Imaginary Axis') # adds y axis title 

plt.show()




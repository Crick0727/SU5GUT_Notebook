using OrdinaryDiffEq, Plots
gr()

#Setup
#Physics constants
g_u = 137.035999177
tspan = (10^2, 10^(20))


F=3 #Family number
n_0=2F  

c_2=0
T_f=5*F/3

#Define coefficients
b=(-1/(4π)^2)*((11*c_2)/3-4T_f/3)

#Define the problem
radioactivedecay(g_u, p, t) = g_u^2 * b

#Pass to solver
prob = ODEProblem(radioactivedecay, g_u, tspan)
sol = solve(prob, Tsit5())

#Plot
plot(sol, linewidth = 2, title = "Carbon-14 half-life",
    xaxis = "Time in thousands of years", yaxis = "Percentage left",
    label = "Numerical Solution")


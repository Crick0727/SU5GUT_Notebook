#!/bin/zsh

gnuplot <<- EOF

set key bottom right
set logscale x
set format x "%T"
set ylabel font "Arial, 12"
set yrange[5:65]

set xlabel " log ({/Symbol m}/[GeV])"
set ylabel " {/Symbol a}_i^{-1}({/Symbol m})"

plot "data1.dat" with line title "{/Symbol a}_1^{-1}", "data2.dat" with line title "{/Symbol a}_2^{-1}", "data3.dat" with line title "{/Symbol a}_3^{-1}"

pause 300 "Press any keys.\n"
EOF

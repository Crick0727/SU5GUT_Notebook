#!/bin/sh

gnuplot << EOF

set terminal eps
set output "RGE.eps"

set key bottom right
set logscale x
set format x "%t"
set ylabel font "Arial, 12"

set xlabel " log {/Symbol m} [GeV]^{-1}"
set ylabel " {/Symbol a}_i^{-1}({/Symbol m})"

plot "data_1.dat" with line title "{/Symbol a}_1^{-1}", "data_2.dat" with line title "{/Symbol a}_2^{-1}", "data_3.dat" with line title "{/Symbol a}_3^{-1}"

exit
EOF

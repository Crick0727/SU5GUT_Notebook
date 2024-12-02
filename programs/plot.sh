#!/bin/sh

gnuplot << EOF

set terminal png
set output "RGE.png"

set logscale x
set key top right
set xlabel "log\mu"
set ylabel "\alpha^{-1}"

set xlabel font "Helvetica, 30"
set ylabel font "Helvetica, 30"

plot "data_1.dat" with line title "\alpha^{-1}", "data_2.dat" with line title "\alpha^{-2}", "data_3.dat" with line title "\alpha^{-3}"

exit
EOF

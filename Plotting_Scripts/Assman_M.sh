#
# GNUPLOT script to plot assman test case with reference
#
set terminal png size 800,2000
set output "0.5m_M.png"
set multiplot layout 3,1 title "Cu 50 MERLIN Test: 0.5m bin"
#
set tmargin 3
set title "x"
#
#~ unset key
set xrange[0:100]
set yrange[0:0.012]
set xlabel "x [micron]"
set ylabel "dN/dx N_0"
plot "Ref.dat" u 1:2 title "reference", "HEL_M_hist.txt" u 1:2 title "merged" 
#
set title "x'"
#
unset key
set xrange[0:100]
set yrange[0:0.01]
set xlabel "theta [microrad]"
set ylabel "dN/dtheta N_0"
plot "Ref.dat" u 1:3 title "reference", "HEL_M_hist.txt" u 1:3 title "merged" 
#
set title "dp"
#
unset key
#set xrange[0:100]
#set yrange[0:0.01]
set xlabel "dp"
set ylabel "dN/d dp N_0"
#~ set log x
plot "Ref.dat" u 1:4 title "reference", "HEL_M_hist.txt" u 1:4 title "merged" 
#
unset multiplot
#

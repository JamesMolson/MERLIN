#
# GNUPLOT script to plot phase ellipse
#
set terminal png size 800,800
#~ set output "Transport+normalHELProcess_no_RF.png"
#~ set output "Transport+SymplecticHELProcess.png"
set output "SYMPLECTIC+SymplecticHELProcess_thin_RF.png"
#~ set output "SYMPLECTIC+normalHELProcess.png"
#~ set multiplot layout 2,1 title "test"
#~ set tmargin 2
#
set pointsize 0.2
#
set xlabel "x [m]"
set ylabel "x' [rad]"
#
#
set xrange[-0.004:0.004]
set yrange[-2.5E-5:2.5E-5]
#~ plot "total_bunch.txt" u 3:4 title "DC TRANSPORT + HELProcess no_RF"
#~ plot "total_bunch.txt" u 3:4 title "DC TRANSPORT + SymplecticHELProcess"
plot "total_bunch.txt" u 3:4 title "DC SYMPLECTIC + SymplecticHELProcess thin_RF"
#~ plot "total_bunch.txt" u 3:4 title "DC SYMPLECTIC + HELProcess"
#
#
#~ unset key
#
#
#~ set xrange[0:100]
#~ set yrange[0:0.01]
#~ plot "total_bunch.txt" u ($3*1000):($4*1000) title "DC HL v1.2.1 TTDistn 1-10sig @ IP1"
#
#plot "Ref.dat" u 1:2 title "reference", "HEL_S_hist.txt" u 1:2 title "merged" 
#
#
#~ unset multiplot

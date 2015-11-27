#/bin/bash/sh
#s,betax,betay,alphax,alphay,dx,dy,x,y   betax,betay,alphax,alphay,dx, dy, x, y  madx data and then merlin      
#1, 2     3,    4       5     6  7 8 9     10   11    12     13    14  15 16 17 
cat LatticeFunctions.dat | awk '{printf "%4.3f %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e\n",$1,$8,$10,-$9,-$11,$12/$16,$14/$16,$2,$4 }'>  merlin_lf.dat
#s,betax,betay,alphax,alphay,dx,dy,x,y

#!/bin/bash
cat twiss.tfs | awk '{printf "%4.3f %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e\n",$3,$18,$19,$20,$21,$24,$25,$32,$34}'> madx_lf.dat
#s,betax,betay,alphax,alphay,dx,dy,x,y

join madx_lf.dat merlin_lf.dat > comparison_lf.dat
#cat comparison.dat | awk '{printf "%4.3f %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e\n",$1,($2-$10)/$2,($3-$11)/$3,($4-$12)/$4,($5-$13)/$5,($6-$14)/$6,($7-$15)/$7,($8-$16)/$8,($9-$17)/$9}'> optics_diff_noABS.dat
cat comparison_lf.dat | awk '{printf "%4.3f %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e %17.16e\n",$1,($2-$10),($3-$11),($4-$12),($5-$13),($6-$14),($7-$15),($8-$16),($9-$17)}'> optics_diff_noABS.dat
sed -e 's| -| |g' optics_diff_noABS.dat > optics_diff.dat
sed -e 's| -| |g' optics_diff_noABS.dat > optics_diff.dat

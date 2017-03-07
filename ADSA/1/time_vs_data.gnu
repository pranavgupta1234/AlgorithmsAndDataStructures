set term png 

set xlabel "Input Size"

set ylabel "Time Taken(in s)"

set output "analysis.png"

plot "result.dat" using 1:2 with lines

#gnuplot -e "load 'time_vs_data.gnu'"


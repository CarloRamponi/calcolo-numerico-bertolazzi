# gnuplot script

input_file = ARG1
output_file = ARG2
print "Plotting data from file: ", input_file , " to file ", output_file

set terminal pdf size 8, 5 font "Helvetiva,16"
set output output_file

plot input_file title 'Norma dei residui' with linespoints pointtype "O" linecolor "sea-green"
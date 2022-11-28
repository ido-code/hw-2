#!/bin/bash
read y
#echo $y
x=$(grep -cE "^([0-9])([0-9])([0-9])([0-9])([0-9])([0-9])$" <<< $y)
#echo $x
[[ (! x -eq 1) ]] && echo "Wrong number of arguments" >&2 && exit 1
file=$y".txt"
#echo $file
[[ (! -e $file) ]] && echo "Course not found" >&2 && exit 1
folder_for_stat=$y"_stat"
if [[ (-d $folder_for_stat)]]; then
	rm -r $folder_for_stat
fi
mkdir $folder_for_stat
$(touch $folder_for_stat/histogram.txt)
$(./hist.exe $file > $folder_for_stat/histogram.txt)
$(touch $folder_for_stat/statistic.txt)
score_for_stat=$(./min.exe $file)
score_for_stat+="	"
score_for_stat+=$(./max.exe $file)
score_for_stat+="	"
score_for_stat+=$(./median.exe $file)
score_for_stat+="	"
score_for_stat+=$(./mean.exe $file)
result_of_pass=$(./hist.exe $file 20)
#result_of_pass=$(./hist.exe 044101.txt 16)
result_of_pass+=" EOF"
#echo $result_of_pass
only_pass=$(echo $result_of_pass|grep -oE " ([0-9]+) ")
only_pass_num=$(echo $only_pass|grep -oE "([0-9]+)")
arr_all=($only_pass_num)
(( sum_all=0 ))
(( sum_all_pass=0 ))
for ((i=0;i<${#arr_all[@]};i++)); do
	(( sum_all+=${arr_all[i]} ))
	[[ i -gt 10 ]] && (( sum_all_pass+=${arr_all[i]} ))
done
(( res=100*$sum_all_pass/$sum_all ))
score_for_stat+="	"
score_for_stat+=$res
$(echo $score_for_stat > $folder_for_stat/statistic.txt)

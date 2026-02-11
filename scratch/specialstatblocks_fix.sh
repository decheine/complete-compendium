# snake
snake_stats=""
snake_txt=""


# Amphisbaena
# Boalisk
# Constrictor (Normal)
# Constrictor (Giant)
# Heway
# Poison (Normal)
# Poison (Giant)
# Sea, Giant
# Spitting

echo "" > snaketable_json.txt

title1=$(awk -F'|' 'NR == 1 { print $2 }' snaketable.csv)
title2=$(awk -F'|' 'NR == 1 { print $3 }' snaketable.csv)
title3=$(awk -F'|' 'NR == 1 { print $4 }' snaketable.csv)
title4=$(awk -F'|' 'NR == 1 { print $5 }' snaketable.csv)
title5=$(awk -F'|' 'NR == 1 { print $6 }' snaketable.csv)
title6=$(awk -F'|' 'NR == 1 { print $7 }' snaketable.csv)
title7=$(awk -F'|' 'NR == 1 { print $8 }' snaketable.csv)
title8=$(awk -F'|' 'NR == 1 { print $9 }' snaketable.csv)
title9=$(awk -F'|' 'NR == 1 { print $10 }' snaketable.csv)

awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $2 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$2"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $3 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$3"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $4 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$4"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $5 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$5"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $6 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$6"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $7 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$7"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $8 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$8"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $9 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$9"\""}' snaketable.csv >> snaketable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $10 }' snaketable.csv)" 'NR > 1 && NR < 23 { print "statblock_snake[\""title"\"][\""$1"\"] = \""$10"\""}' snaketable.csv >> snaketable_json.txt
# cat snaketable_json.txt

mapfile -t lines < "mammsmal_table_t.csv"

echo $lines


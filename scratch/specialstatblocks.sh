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

# mapfile -t lines < "mammsmal_table_t.csv"

# echo $lines

mammsmal_lines=$(awk -F";" '{ print $1 }' "mammsmal_table_t.csv")

echo "$mammsmal_lines"

echo "" > mammsmaltable_json.txt


echo "$(awk -F'|' 'NR == 1 { print $2 }' mammsmal_table_t.csv)"

awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $2  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$2"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $3  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$3"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $4  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$4"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $5  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$5"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $6  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$6"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $7  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$7"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $8  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$8"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $9  }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$9"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $10 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$10"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $11 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$11"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $12 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$12"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $13 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$13"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $14 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$14"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $15 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$15"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $16 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$16"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $17 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$17"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $18 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$18"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $19 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$19"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $20 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$20"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $21 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$21"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $22 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$22"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $23 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$23"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $24 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$24"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt
awk -F'|' -v title="$(awk -F'|' 'NR == 1 { print $25 }' mammsmal_table_t.csv)" 'NR > 1 && NR < 23 { print "statblock_mammsmal[\""title"\"][\""$1"\"] = \""$25"\""}' mammsmal_table_t.csv >> mammsmaltable_json.txt

cat mammsmaltable_json.txt

# for line in "${lines[@]}"; do
#     printf "${line}\n"
# done



# mammsmal_lines=$(awk -F";" '{ print $1 }' "mammsmal_table_t.csv")

# echo "$mammsmal_lines"

# echo "" > mammminitable_json.txt


# echo "$(awk -F'|' 'NR == 1 { print $2 }' mammmini_table_t.tsv)"

# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$2 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$3 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$4 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$5 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$6 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$7 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$8 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$9 "\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$10"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $11 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$11"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $12 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$12"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $13 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$13"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $14 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$14"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $15 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$15"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $16 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$16"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $17 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$17"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $18 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$18"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $19 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$19"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $20 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$20"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $21 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$21"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $22 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$22"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $23 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$23"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $24 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$24"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $25 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$25"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $26 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$26"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $27 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$27"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $28 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$28"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $29 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$29"\""}' mammmini_table_t.tsv >> mammminitable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $30 }' mammmini_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammmini[\""title"\"][\""$1"\"] = \""$30"\""}' mammmini_table_t.tsv >> mammminitable_json.txt

# cat mammminitable_json.txt





echo "" > mammher2table_json.txt

echo "$(awk -F'|' 'NR == 1 { print $2 }' mammher2table_json.tsv)"

awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$2 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$3 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$4 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$5 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$6 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$7 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$8 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$9 "\";"}' mammher2_table_t.tsv >> mammher2table_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' mammher2_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammher2[\""title"\"][\""$1"\"] = \""$10"\";"}' mammher2_table_t.tsv >> mammher2table_json.txt

cat mammher2table_json.txt




echo "" > mammgiantable_json.txt

awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$2 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$3 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$4 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$5 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$6 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$7 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$8 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$9 "\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' mammgian_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammgian[\""title"\"][\""$1"\"] = \""$10"\";"}' mammgian_table_t.tsv >> mammgiantable_json.txt

cat mammgiantable_json.txt



echo "" > mammaltable_json.txt

awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$2 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$3 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$4 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$5 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$6 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$7 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$8 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$9 "\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$10"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $11 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$11"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $12 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$12"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $13 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$13"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $14 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$14"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $15 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$15"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $16 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$16"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $17 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$17"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $18 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$18"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $19 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$19"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $20 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$20"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $21 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$21"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $22 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$22"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $23 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$23"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $24 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$24"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $25 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$25"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $26 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$26"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $27 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$27"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $28 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$28"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $29 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$29"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $30 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$30"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $31 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$31"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $32 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$32"\";"}' mammal_table_t.tsv >> mammaltable_json.txt
# awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $33 }' mammal_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_mammal[\""title"\"][\""$1"\"] = \""$33"\";"}' mammal_table_t.tsv >> mammaltable_json.txt

cat mammaltable_json.txt





echo "" > insecttable_json.txt

awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$2 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$3 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$4 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$5 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$6 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$7 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$8 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$9 "\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$10"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $11 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$11"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $12 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$12"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $13 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$13"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $14 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$14"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $15 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$15"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $16 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$16"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $17 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$17"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $18 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$18"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $19 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$19"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $20 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$20"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $21 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$21"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $22 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$22"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $23 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$23"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $24 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$24"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $25 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$25"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $26 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$26"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $27 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$27"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $28 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$28"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $29 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$29"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $30 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$30"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $31 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$31"\";"}' insect_table_t.tsv >> insecttable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $32 }' insect_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_insect[\""title"\"][\""$1"\"] = \""$32"\";"}' insect_table_t.tsv >> insecttable_json.txt

cat insecttable_json.txt




echo "" > humantable_json.txt

awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $2  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$2 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $3  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$3 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $4  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$4 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $5  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$5 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $6  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$6 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $7  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$7 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $8  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$8 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $9  }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$9 "\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $10 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$10"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $11 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$11"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $12 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$12"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $13 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$13"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $14 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$14"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $15 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$15"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $16 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$16"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $17 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$17"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $18 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$18"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $19 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$19"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $20 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$20"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $21 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$21"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $22 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$22"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $23 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$23"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $24 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$24"\";"}' human_table_t.tsv >> humantable_json.txt
awk -F'\t' -v title="$(awk -F'\t' 'NR == 1 { print $25 }' human_table_t.tsv)" 'NR > 1 && NR < 23 { print "statblock_human[\""title"\"][\""$1"\"] = \""$25"\";"}' human_table_t.tsv >> humantable_json.txt

cat humantable_json.txt
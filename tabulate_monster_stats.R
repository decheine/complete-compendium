
library(utils)

# .libPaths(c("./.Rlibs"))

package_deps <- c(
  "tidyverse",
  "rjson",
  "stringr",
  "rlist",
  "purrr",
  "tibble",
  "jsonlite"
)

# .libPaths(c('~/.Rlibs',.libPaths()))
dir.create(file.path("~/.Rlibs"), showWarnings = FALSE)

install.packages(package_deps, repos="https://cloud.r-project.org", lib='~/.Rlibs')

library(tidyverse, lib='~./.Rlibs')
library(rjson, lib='~./.Rlibs')
library(stringr, lib='~./.Rlibs')
library(rlist, lib='~./.Rlibs')
library(purrr, lib='~./.Rlibs')
library(tibble, lib='~./.Rlibs')
library(jsonlite, lib='~./.Rlibs')

quotemeta <- function(string) {
  str_replace_all(string, "(\\W)", "\\\\\\1")
}

# ---

json_file <- paste(getwd(), "/src/data/ALL_MONSTERS.json", sep="")
json_data <- rjson::fromJSON(paste(readLines(json_file), collapse=""), simplify=TRUE)



# ----
# 1 - Statblock Split Setup


result <- list()

stat_result_df <- data.frame(
  monster_key = character(),
  title = character(),
  statblock_title = character(),
  Activity_Cycle = character(),
  Alignment = character(),
  Armor_Class = character(),
  Climate_Terrain = character(),
  Damage_Attack = character(),
  Diet = character(),
  Frequency = character(),
  Hit_Dice = character(),
  Intelligence = character(),
  Magic_Resistance = character(),
  Morale = character(),
  Movement = character(),
  No_Appearing = character(),
  No_of_Attacks = character(),
  Organization = character(),
  Size = character(),
  Special_Attacks = character(),
  Special_Defenses = character(),
  THAC0 = character(),
  Treasure = character(),
  XP_Value = character()
)


for (i in seq_along(json_data))
{
  # result[[i]] = change_data_frame_to_named_list(json_data[[i]])
  monster_key <- json_data[[i]]$monster_key
  monster_title <- json_data[[i]]$title
  
  the_statblock <- json_data[[i]]$monster_data$statblock
  # result <- list.append(result, json_data[[i]]$monster_data$statblock)
  # Row
  # Each row is a df, with monster key and statblock title
  # c(monster_key, )
  
  
  for (j in seq_along(the_statblock)){
    # statblock_title <- json_data[[i]]$statblock_names[[j]]
    statblock_title <- names(the_statblock)[[j]]
    
    statblock_row <- the_statblock[[j]]
    statblock_row$monster_key = monster_key
    statblock_row$title = statblock_title
    
    activity_cycle <- statblock_row$`Activity Cycle`
    armor_class <- statblock_row$`Armor Class`
    # print(statblock_title)
    # print(ifelse(is.null(activity_cycle), NA, activity_cycle))
    stat_df <- data.frame(
      monster_key = list(monster_key),
      title = list(monster_title), 
      statblock_title = list(statblock_title),
      Activity_Cycle = list(ifelse(is.null(activity_cycle), NA, activity_cycle)),
      Alignment = list(ifelse(is.null(statblock_row$Alignment), NA, statblock_row$Alignment)),
      Armor_Class= list(ifelse(is.null(statblock_row$`Armor Class`), NA, statblock_row$`Armor Class`)),
      Climate_Terrain = list(ifelse(is.null(statblock_row$`Climate/Terrain`), NA, statblock_row$`Climate/Terrain`)),
      Damage_Attack = list(ifelse(is.null(statblock_row$`Damage/Attack`), NA, statblock_row$`Damage/Attack`)),
      Diet = list(ifelse(is.null(statblock_row$Diet), NA, statblock_row$Diet)),
      Frequency = list(ifelse(is.null(statblock_row$Frequency), NA, statblock_row$Frequency)),
      Hit_Dice = list(ifelse(is.null(statblock_row$`Hit Dice`), NA, statblock_row$`Hit Dice`)),
      Intelligence = list(ifelse(is.null(statblock_row$Intelligence), NA, statblock_row$Intelligence)),
      Magic_Resistance = list(ifelse(is.null(statblock_row$`Magic Resistance`), NA, statblock_row$`Magic Resistance`)),
      Morale = list(ifelse(is.null(statblock_row$Morale), NA, statblock_row$Morale)),
      Movement = list(ifelse(is.null(statblock_row$Movement), NA, statblock_row$Movement)),
      No_Appearing = list(ifelse(is.null(statblock_row$`No. Appearing`), NA, statblock_row$`No. Appearing`)),
      No_of_Attacks = list(ifelse(is.null(statblock_row$`No. of Attacks`), NA, statblock_row$`No. of Attacks`)),
      Organization = list(ifelse(is.null(statblock_row$Organization), NA, statblock_row$Organization)),
      Size = list(ifelse(is.null(statblock_row$Size), NA, statblock_row$Size)),
      Special_Attacks = list(ifelse(is.null(statblock_row$`Special Attacks`), NA, statblock_row$`Special Attacks`)),
      Special_Defenses = list(ifelse(is.null(statblock_row$`Special Defenses`), NA, statblock_row$`Special Defenses`)),
      THAC0 = list(ifelse(is.null(statblock_row$THAC0), NA, statblock_row$THAC0)),
      Treasure = list(ifelse(is.null(statblock_row$Treasure), NA, statblock_row$Treasure)),
      XP_Value = list(ifelse(is.null(statblock_row$`XP Value`), NA, statblock_row$`XP Value`))
    )
    
    stat_result_df[nrow(stat_result_df)+1,] <- stat_df
    
    # result <- list.append(result, as.data.frame(statblock_row, recursive=TRUE))
  }
}



# Statblock splitting

options(max.print=4000)

subset <- stat_result_df %>% select(monster_key, title, statblock_title, Hit_Dice) 
ordered_subset <- subset[order(subset$Hit_Dice, decreasing = FALSE), ]
# print(ordered_subset, n = 2000)



subset <- stat_result_df #%>% select(monster_key, title, statblock_title, Hit.Dice, XP.Value )
ordered_subset <- subset[order(subset$XP_Value, decreasing = FALSE), ]

ordered_subset$xp_filtered <- lapply(ordered_subset$XP_Value, function(x){as.numeric(gsub(",", "", x))})


ordered_subset$xp_filtered = strtoi(ordered_subset$xp_filtered, 10L)
ordered_subset <- ordered_subset[order(ordered_subset$xp_filtered, decreasing = FALSE), ]
# print(ordered_subset, n = 2000)

# Subtypes, splitting by Hit Dice, XP, and THAC0
thac0_with_br <- ordered_subset %>% filter(grepl("<br",THAC0))
xp_with_br <- ordered_subset %>% filter(grepl("(<br)|(, )",XP_Value))
hd_with_br <- ordered_subset %>% filter(grepl("<br", Hit_Dice))


# Output
# xp_with_br %>% arrange(monster_key)

# -----

# Extract the monster keys for each

split_thac0_keys <- thac0_with_br$monster_key
split_xp_keys <- xp_with_br$monster_key
split_hd_keys <- hd_with_br$monster_key


thac0_matches <- thac0_with_br$THAC0 %>% 
  str_match_all("<br>(.+?): (\\d+)")

xp_matches <- xp_with_br$XP_Value %>%
  str_match_all("<br>(.+?): (\\d|,)+")
# data.frame(xp_matches)

# keep cooking

# XP is the best field for detecting variants. The bulk of them are HD variants.
# For each of those rows, first try detecting how many variants there are

# returns number
get_variants <- function(xp_value) {
  matches <- str_match_all(xp_value, "(<br>|^)(.+?)(?::|) (\\d|,)+")
  num_variants <- NROW(matches[[1]])
  return(num_variants)
}

is_base_xp <- function(xp_value) {
  matches <- str_match_all(xp_value, "^(\\d|,)+(?:<)")
  return(NROW(matches[[1]]))
}



xp_with_br$variant_count = sapply(xp_with_br$XP_Value, get_variants)
xp_with_br$base = sapply(xp_with_br$XP_Value, is_base_xp)

# xp_with_br %>% select(monster_key, variant_count, Hit_Dice, THAC0, XP_Value, base)

tagged_df <- xp_with_br %>% select(monster_key, variant_count, Hit_Dice, THAC0, XP_Value, base)

# --- Split and combine


split_monsters_df <- xp_with_br[0,]
# split_monsters_df$variant_title <- NULL
split_monsters_df <- split_monsters_df %>% add_column(variant_title = "")

# split_monsters_df

# colnames(split_monsters_df)

split_add_rows <- function(row){
  monster_key = row["monster_key"] 
  title = row["title"] 
  statblock_title = row["statblock_title"] 
  Activity_Cycle = row["Activity_Cycle"] 
  Alignment = row["Alignment"] 
  Armor_Class = row["Armor_Class"] 
  Climate_Terrain = row["Climate_Terrain"] 
  Damage_Attack = row["Damage_Attack"] 
  Diet = row["Diet"] 
  Frequency = row["Frequency"] 
  Hit_Dice = row["Hit_Dice"] 
  Intelligence = row["Intelligence"] 
  Magic_Resistance = row["Magic_Resistance"] 
  Morale = row["Morale"] 
  Movement = row["Movement"] 
  No_Appearing = row["No_Appearing"] 
  No_of_Attacks = row["No_of_Attacks"] 
  Organization = row["Organization"] 
  Size = row["Size"] 
  Special_Attacks = row["Special_Attacks"] 
  Special_Defenses = row["Special_Defenses"] 
  THAC0 = row["THAC0"] 
  Treasure = row["Treasure"] 
  XP_Value = row["XP_Value"] 
  xp_filtered = row["xp_filtered"] 
  base = row["base"]
  
  
  # print(row)
  matches <- str_match_all(row["XP_Value"], "(?:<br>|^)*(.+?):* ([\\d|,]+)(?:<br>|$)")
  num_variants <- NROW(matches[[1]])
  if(num_variants){
    # print(num_variants)
  } else {
    return()
  }
  # print("begin")
  # print(matches[1])
  # print(num_variants[1])
  # if(num_variants)
  
  if(row["base"] == 1){
    tmp_thac0 <- THAC0
    # Need to add a base copy to the split df
    
    
    # Handle base case, add the original row to the new row 
    # in addition to the new rows.
  }
  # colnames(split_monsters_df)
  
  thac0_hd_matches_range <- str_match_all(THAC0, "([\\d|+|½|¼]{1,2} HD:|(\\d+)(?:-| or | to )(\\d+) HD:|) (\\d+)")
  
  tmp_thac0 <- 20
  # print(paste(monster_key, "num variants:", num_variants))
  for(row_num in 1:num_variants) {
    # print(row_num)
    # print(matches[[1]][row_num, 2])
    variant_title = matches[[1]][row_num, 2]
    
    # Check variant_title for <br> again with number. If so, delete it.
    if(str_detect(variant_title, "(.+)<br>(.+?)$")){
      # print("detected")
      # print(str_match_all(variant_title, "(.+)<br>(.+?)$")[[1]][3])
      # If it's the first one, add it too
      if(row_num == 1 & row["base"] == 1){
        # Add the base monster with the first xp total
        base_xp = str_match_all(variant_title, "(.+)<br>(.+?)$")[[1]][2]
        # print(paste("base", monster_key, "variants: ", base_xp))
        
        split_monsters_df <<- split_monsters_df %>%
          add_row(
            monster_key = monster_key,
            title = title,
            statblock_title = statblock_title,
            variant_title = NA,
            Activity_Cycle = Activity_Cycle,
            Alignment = Alignment,
            Armor_Class = Armor_Class,
            Climate_Terrain = Climate_Terrain,
            Damage_Attack = Damage_Attack,
            Diet = Diet,
            Frequency = Frequency,
            Hit_Dice = Hit_Dice,
            Intelligence = Intelligence,
            Magic_Resistance = Magic_Resistance,
            Morale = Morale,
            Movement = Movement,
            No_Appearing = No_Appearing,
            No_of_Attacks = No_of_Attacks,
            Organization = Organization,
            Size = Size,
            Special_Attacks = Special_Attacks,
            Special_Defenses = Special_Defenses,
            THAC0 = THAC0,
            Treasure = Treasure,
            XP_Value = base_xp,
            base = as.numeric(base)
          )
      }
      
      variant_title = str_match_all(variant_title, "(.+)<br>(.+?)$")[[1]][3]
      # print(paste(monster_key, "variants: ", num_variants, variant_title))
    }
    
    variant_xp = matches[[1]][row_num, 3]
    # Initialize new thac0 to original thac0
    new_thac0 <- THAC0
    
    # Here check for Hit Dice
    hd_matches <- str_match_all(variant_title, "^([\\d|+|½|¼]+)(?: |)(HD|Hit Dice)")
    
    variant_hd <- hd_matches[[1]][2]
    variant_hd_full <- hd_matches[[1]][1]
    
    # grep(paste0(variant_hd_full, "((\\d+)-(\\d+)|): (\\d+)"), THAC0)
    
    # Pull out thac0 ranges
    # print(paste("monster:", monster_key, ",", variant_title, "|xp:", variant_xp, "|hd:", variant_hd))
    # If thaco and xp rows are the same, then do it across.
    # If they are different, then check for ranges
    
    
    # print(paste("variants: ", num_variants))
    # print(paste("hd_matches: ", NROW(thac0_hd_matches_range[[1]])))
    if(num_variants ==  NROW(thac0_hd_matches_range[[1]])){
      # print("thac0 row")
      # if(row_num < NROW(thac0_hd_matches_range[[1]]) + 1 ){
      row_whole <- thac0_hd_matches_range[[1]][row_num,]
      
      row_label <- thac0_hd_matches_range[[1]][row_num, 2]
      row_lower <- thac0_hd_matches_range[[1]][row_num, 3]
      row_upper <- thac0_hd_matches_range[[1]][row_num, 4]
      row_thac0 <- thac0_hd_matches_range[[1]][row_num, 5]
      
      split_monsters_df <<- split_monsters_df %>%
        add_row(
          monster_key = monster_key,
          title = title,
          statblock_title = statblock_title,
          variant_title = variant_title,
          Activity_Cycle = Activity_Cycle,
          Alignment = Alignment,
          Armor_Class = Armor_Class,
          Climate_Terrain = Climate_Terrain,
          Damage_Attack = Damage_Attack,
          Diet = Diet,
          Frequency = Frequency,
          Hit_Dice = variant_hd,
          Intelligence = Intelligence,
          Magic_Resistance = Magic_Resistance,
          Morale = Morale,
          Movement = Movement,
          No_Appearing = No_Appearing,
          No_of_Attacks = No_of_Attacks,
          Organization = Organization,
          Size = Size,
          Special_Attacks = Special_Attacks,
          Special_Defenses = Special_Defenses,
          THAC0 = row_thac0,
          Treasure = Treasure,
          XP_Value = variant_xp,
          base = as.numeric(base)
        )
    } else {
      if(NROW(hd_matches) > 0){
        match_found <- FALSE
        # Go through each th_match and check for HD match
        for(hd_match_num in 1:nrow(thac0_hd_matches_range[[1]])){
          if(nrow(thac0_hd_matches_range[[1]]) > 0){
            
            row_label <- thac0_hd_matches_range[[1]][hd_match_num, 2]
            row_lower <- thac0_hd_matches_range[[1]][hd_match_num, 3]
            row_upper <- thac0_hd_matches_range[[1]][hd_match_num, 4]
            row_thac0 <- thac0_hd_matches_range[[1]][hd_match_num, 5]
            
            # print(paste("thac0 row", hd_match_num, "|", row_label, "|", row_thac0, "|", paste(variant_hd_full,":", sep=""), "lower/upper", row_lower, row_upper ))
            
            
            # print(paste("Comparing row_label to variant_hd_full", row_label, "|", variant_hd_full, ", ", row_thac0, "check:",  str_detect(row_label, quotemeta(variant_hd_full))))
            if(row_label != "" ){
              
              if(!is.na(variant_hd_full) &
                 str_detect(row_label, quotemeta(variant_hd_full))){
                tmp_thac0 <- row_thac0
                # print(paste("Match!", row_thac0, tmp_thac0, variant_hd_full))
                match_found <- TRUE
                match_found <<- TRUE
                break
              } else {
                # break
                if(!is.na(row_lower) & !is.na(as.numeric(variant_hd))){
                  if(as.numeric(variant_hd) >= as.numeric(row_lower) & as.numeric(variant_hd) <= as.numeric(row_upper)){
                    # print("Match (range)")
                    tmp_thac0 <- row_thac0
                    # print(paste("range", row_lower, variant_hd, row_upper, "newthac0", row_thac0, tmp_thac0))
                    match_found <- TRUE
                    match_found <<- TRUE
                    break;
                  }
                }
                # # Range
                # print("Match!")
                # new_thac0 <<- row_thac0
                # match_found <<- TRUE
                # }
              }
            }
          }
        }
        # print(paste('HD:', variant_hd, 'new thac0:', tmp_thac0))
        
        if(match_found){
          if(is.na(variant_hd)){
            variant_hd <- Hit_Dice
          }
          # print(paste("pushing", hd_match_num, "|hd", variant_hd, "|th", as.character(tmp_thac0)))
          split_monsters_df <<- split_monsters_df %>%
            add_row(
              monster_key = monster_key,
              title = title,
              statblock_title = statblock_title,
              variant_title = variant_title,
              Activity_Cycle = Activity_Cycle,
              Alignment = Alignment,
              Armor_Class = Armor_Class,
              Climate_Terrain = Climate_Terrain,
              Damage_Attack = Damage_Attack,
              Diet = Diet,
              Frequency = Frequency,
              Hit_Dice = variant_hd,
              Intelligence = Intelligence,
              Magic_Resistance = Magic_Resistance,
              Morale = Morale,
              Movement = Movement,
              No_Appearing = No_Appearing,
              No_of_Attacks = No_of_Attacks,
              Organization = Organization,
              Size = Size,
              Special_Attacks = Special_Attacks,
              Special_Defenses = Special_Defenses,
              THAC0 = as.character(tmp_thac0),
              Treasure = Treasure,
              XP_Value = variant_xp,
              base = as.numeric(base)
            )
        } else {
          # Calculate thac0 with HD
          if(is.na(variant_hd)){
            # Search again but with word field
            hd_variant = str_match_all(Hit_Dice, "(.+?): (\\d*)")[3]
            # print(paste("New hd:", hd_variant))
            
            tmp_thac0 <- 20 - as.numeric(Hit_Dice)
          } else{
            if(is.na(as.numeric(variant_hd))){
              # Check for a plus or minus?
              hd_dash_match = str_match_all(variant_hd, "(\\d+)(-|\\+)")
              # print(hd_dash_match[[1]][2])
              tmp_thac0 <- 20 - as.numeric(hd_dash_match[[1]][2])
            } else {
              tmp_thac0 <- 20 - as.numeric(variant_hd)
            }
            
          }
          # print(paste('HD:', variant_hd, 'CALC THAC0', new_thac0))
          
          if(is.na(tmp_thac0)){
            # All else fails, send original thac0
            # print(paste("pushing reg th", hd_match_num, "|hd",variant_hd, "|th", as.character(tmp_thac0), "|original hd", Hit_Dice, "|original th", THAC0))
            split_monsters_df <<- split_monsters_df %>%
              add_row(
                monster_key = monster_key,
                title = title,
                statblock_title = statblock_title,
                variant_title = variant_title,
                Activity_Cycle = Activity_Cycle,
                Alignment = Alignment,
                Armor_Class = Armor_Class,
                Climate_Terrain = Climate_Terrain,
                Damage_Attack = Damage_Attack,
                Diet = Diet,
                Frequency = Frequency,
                Hit_Dice = Hit_Dice,
                Intelligence = Intelligence,
                Magic_Resistance = Magic_Resistance,
                Morale = Morale,
                Movement = Movement,
                No_Appearing = No_Appearing,
                No_of_Attacks = No_of_Attacks,
                Organization = Organization,
                Size = Size,
                Special_Attacks = Special_Attacks,
                Special_Defenses = Special_Defenses,
                THAC0 = THAC0,
                Treasure = Treasure,
                XP_Value = variant_xp,
                base = as.numeric(base)
              )
            
          } else {
            # print(paste("pushing calc", hd_match_num, "|hd",variant_hd, "|th", as.character(tmp_thac0), "|original hd", Hit_Dice, "|original th", THAC0))
            
            split_monsters_df <<- split_monsters_df %>%
              add_row(
                monster_key = monster_key,
                title = title,
                statblock_title = statblock_title,
                variant_title = variant_title,
                Activity_Cycle = Activity_Cycle,
                Alignment = Alignment,
                Armor_Class = Armor_Class,
                Climate_Terrain = Climate_Terrain,
                Damage_Attack = Damage_Attack,
                Diet = Diet,
                Frequency = Frequency,
                Hit_Dice = Hit_Dice,
                Intelligence = Intelligence,
                Magic_Resistance = Magic_Resistance,
                Morale = Morale,
                Movement = Movement,
                No_Appearing = No_Appearing,
                No_of_Attacks = No_of_Attacks,
                Organization = Organization,
                Size = Size,
                Special_Attacks = Special_Attacks,
                Special_Defenses = Special_Defenses,
                THAC0 = as.character(tmp_thac0),
                Treasure = Treasure,
                XP_Value = variant_xp,
                base = as.numeric(base)
              )
          }
        }
        
        
        
      } else {
        # return()
        # Just XP Variant, so give it the same HD and THAC0 as before.
        # print(paste("pushing just xp"))
        
        
        split_monsters_df <<- split_monsters_df %>%
          add_row(
            monster_key = monster_key,
            title = title,
            statblock_title = statblock_title,
            variant_title = variant_title,
            Activity_Cycle = Activity_Cycle,
            Alignment = Alignment,
            Armor_Class = Armor_Class,
            Climate_Terrain = Climate_Terrain,
            Damage_Attack = Damage_Attack,
            Diet = Diet,
            Frequency = Frequency,
            Hit_Dice = Hit_Dice,
            Intelligence = Intelligence,
            Magic_Resistance = Magic_Resistance,
            Morale = Morale,
            Movement = Movement,
            No_Appearing = No_Appearing,
            No_of_Attacks = No_of_Attacks,
            Organization = Organization,
            Size = Size,
            Special_Attacks = Special_Attacks,
            Special_Defenses = Special_Defenses,
            THAC0 = THAC0,
            Treasure = Treasure,
            XP_Value = variant_xp,
            base = as.numeric(base)
          )
        
      }
    }
    
    
    
  }
  return()
  
}

# dim(xp_with_br$XP_Value)

results <- apply(xp_with_br, 1, split_add_rows)


# Merge split monsters with main monster table

# Get monster keys with base
base_monsters <- split_monsters_df %>% 
  filter(base == 1)
base_monsterkeys <- base_monsters$monster_key


# Replace monsters with base == 0
base0_monster_keys <- (split_monsters_df %>% filter(base == 0))$monster_key
base0_titles <- (split_monsters_df %>% filter(base == 0))$title
base1_monster_keys <- (split_monsters_df %>% filter(base == 1))$monster_key


# filter base by
# monster_key, title, and statblock_title
# It's removing good monsters. 



# Need to pull out the rows to delete. 

split_anti_join <- stat_result_df %>% 
  anti_join(split_monsters_df, by=c('monster_key', 'statblock_title'))

combined_monsters <- bind_rows(split_anti_join, split_monsters_df) 
combined_monsters$base <- NULL
combined_monsters$variant_count <- NULL
combined_monsters$xp_filtered <- NULL


# ---- Write out result




write(jsonlite::toJSON(combined_monsters, pretty = TRUE, auto_unbox = TRUE), "./src/data/stats_df.json")

print("Tabulation Complete!")

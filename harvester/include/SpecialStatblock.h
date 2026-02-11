#include <string>

// Jsoncpp
#include "json/value.h"
#include <json/json.h>
// #include <json/reader.h>
// Special handling of statblocks of the following monsters:
//
// human
// insect
// lycanthg
// mammal
// mammgian
// mammher2
// mammmini
// mammsmal
// modron
// snake

/*

"Activity Cycle"
"Alignment"
"Armor Class"
"Climate/Terrain"
"Damage/Attack"
"Diet"
"Frequency"
"Hit Dice"
"Intelligence"
"Magic Resistance"
"Morale"
"Movement"
"No. Appearing"
"No. of Attacks"
"Organization"
"Size"
"Special Attacks"
"Special Defenses"
"THAC0"
"Treasure"
"XP Value"

*/

class SpecialStatblock {

public:

Json::Value statblock;

// statblock[NAME][STATBLOCK_CATEGORY]

Json::Value statblock_human;
Json::Value statblock_insect;
Json::Value statblock_lycanthg;
Json::Value statblock_mammal;
Json::Value statblock_mammgian;
Json::Value statblock_mammher2;
Json::Value statblock_mammmini;
Json::Value statblock_mammsmal;
Json::Value statblock_modron;
Json::Value statblock_snake;

// Repeat following for each monster subtype
// statblock_[""]["Climate/Terrain"]   = "";
// statblock_[""]["Frequency"]         = "";
// statblock_[""]["Organization"]      = "";
// statblock_[""]["Activity Cycle"]    = "";
// statblock_[""]["Diet"]              = "";
// statblock_[""]["Intelligence"]      = "";
// statblock_[""]["Treasure"]          = "";
// statblock_[""]["Alignment"]         = "";
// statblock_[""]["No. Appearing"]     = "";
// statblock_[""]["Armor Class"]       = "";
// statblock_[""]["Movement"]          = "";
// statblock_[""]["Hit Dice"]          = "";
// statblock_[""]["THAC0"]             = "";
// statblock_[""]["No. of Attacks"]    = "";
// statblock_[""]["Damage/Attack"]     = "";
// statblock_[""]["Special Attacks"]   = "";
// statblock_[""]["Special Defenses"]  = "";
// statblock_[""]["Magic Resistance"]  = "";
// statblock_[""]["Size"]              = "";
// statblock_[""]["Morale"]            = "";
// statblock_[""]["XP Value"]          = "";

void fill_statblocks() {




//
// Using the following regex to extract titles:
// <th class="cn">(.*?)</th>

/////////////////////////////////////////////////////////////
// human

// Aborigine/Caveman
// Adventurer
// Bandit/Brigand
// Barbarian/Nomad
// Berserker/Dervish
// Farmer/Herder
// Gentry
// Knight
// Mercenary
// Merchant Sailor/Fisherman
// Merchant/Trader
// Middle Class
// Peasant/Serf
// Pilgrim
// Pirate/Buccaneer
// Police/Constabulary
// Priest
// Sailor
// Slaver
// Soldier
// Thief/Thug
// Tradesman/Craftsman
// Tribesman
// Wizard

statblock_human["Aborigine/Caveman"]["Frequency:"] = "Rare";
statblock_human["Aborigine/Caveman"]["Treasure:"] = "Nil";
statblock_human["Aborigine/Caveman"]["Alignment:"] = "Neutral";
statblock_human["Aborigine/Caveman"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Aborigine/Caveman"]["Armor Class:"] = "8";
statblock_human["Aborigine/Caveman"]["Hit Dice:"] = "1-6 hp/2 HD";
statblock_human["Aborigine/Caveman"]["THAC0:"] = "20 (19)";
statblock_human["Aborigine/Caveman"]["Morale:"] = "Average (9)";
statblock_human["Aborigine/Caveman"]["XP Value:"] = "15 (35)";
statblock_human["Bandit/Brigand"]["Frequency:"] = "Common";
statblock_human["Bandit/Brigand"]["Treasure:"] = "J,N,Q";
statblock_human["Bandit/Brigand"]["Alignment:"] = "Chaotic evil";
statblock_human["Bandit/Brigand"]["No. Appearing:"] = "20-200 (20d10)";
statblock_human["Bandit/Brigand"]["Armor Class:"] = "10 to 6";
statblock_human["Bandit/Brigand"]["Hit Dice:"] = "1-6 hp";
statblock_human["Bandit/Brigand"]["THAC0:"] = "20";
statblock_human["Bandit/Brigand"]["Morale:"] = "Average (9)";
statblock_human["Bandit/Brigand"]["XP Value:"] = "15";
statblock_human["Barbarian/Nomad"]["Frequency:"] = "Rare";
statblock_human["Barbarian/Nomad"]["Treasure:"] = "L,M";
statblock_human["Barbarian/Nomad"]["Alignment:"] = "Any";
statblock_human["Barbarian/Nomad"]["No. Appearing:"] = "30-300 (30d10)";
statblock_human["Barbarian/Nomad"]["Armor Class:"] = "10 to 6";
statblock_human["Barbarian/Nomad"]["Hit Dice:"] = "1-6 hp";
statblock_human["Barbarian/Nomad"]["THAC0:"] = "20";
statblock_human["Barbarian/Nomad"]["Morale:"] = "Average (9)";
statblock_human["Barbarian/Nomad"]["XP Value:"] = "15";
statblock_human["Berserker/Dervish"]["Frequency:"] = "Rare";
statblock_human["Berserker/Dervish"]["Treasure:"] = "Nil";
statblock_human["Berserker/Dervish"]["Alignment:"] = "Neutral/L. good";
statblock_human["Berserker/Dervish"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Berserker/Dervish"]["Armor Class:"] = "10 to 6";
statblock_human["Berserker/Dervish"]["Hit Dice:"] = "1-6 hp";
statblock_human["Berserker/Dervish"]["THAC0:"] = "20";
statblock_human["Berserker/Dervish"]["Morale:"] = "Fearless (20)";
statblock_human["Berserker/Dervish"]["XP Value:"] = "15";
statblock_human["Farmer/Herder"]["Frequency:"] = "Common";
statblock_human["Farmer/Herder"]["Treasure:"] = "Nil";
statblock_human["Farmer/Herder"]["Alignment:"] = "Neutral (good)";
statblock_human["Farmer/Herder"]["No. Appearing:"] = "1-20";
statblock_human["Farmer/Herder"]["Armor Class:"] = "10";
statblock_human["Farmer/Herder"]["Hit Dice:"] = "1-6 hp";
statblock_human["Farmer/Herder"]["THAC0:"] = "20";
statblock_human["Farmer/Herder"]["Morale:"] = "Average (9)";
statblock_human["Farmer/Herder"]["XP Value:"] = "15";
statblock_human["Gentry"]["Frequency:"] = "Common";
statblock_human["Gentry"]["Treasure:"] = "J,K,L,M,N,Q";
statblock_human["Gentry"]["Alignment:"] = "Any";
statblock_human["Gentry"]["No. Appearing:"] = "1-20";
statblock_human["Gentry"]["Armor Class:"] = "10";
statblock_human["Gentry"]["Hit Dice:"] = "1-6 hp";
statblock_human["Gentry"]["THAC0:"] = "20";
statblock_human["Gentry"]["Morale:"] = "Average (9)";
statblock_human["Gentry"]["XP Value:"] = "15";
statblock_human["Knight"]["Frequency:"] = "Very rare";
statblock_human["Knight"]["Treasure:"] = "L,M";
statblock_human["Knight"]["Alignment:"] = "Any lawful";
statblock_human["Knight"]["No. Appearing:"] = "1-4";
statblock_human["Knight"]["Armor Class:"] = "4 or 2";
statblock_human["Knight"]["Hit Dice:"] = "2+";
statblock_human["Knight"]["THAC0:"] = "19 or less";
statblock_human["Knight"]["Morale:"] = "Elite (14+)";
statblock_human["Knight"]["XP Value:"] = "Varies";
statblock_human["Mercenary"]["Frequency:"] = "Rare";
statblock_human["Mercenary"]["Treasure:"] = "L,M";
statblock_human["Mercenary"]["Alignment:"] = "Any";
statblock_human["Mercenary"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Mercenary"]["Armor Class:"] = "7 to 4";
statblock_human["Mercenary"]["Hit Dice:"] = "2-8 hp";
statblock_human["Mercenary"]["THAC0:"] = "20";
statblock_human["Mercenary"]["Morale:"] = "Steady (11-12)";
statblock_human["Mercenary"]["XP Value:"] = "15";
statblock_human["Merchant Sailor/Fisherman"]["Frequency:"] = "Common";
statblock_human["Merchant Sailor/Fisherman"]["Treasure:"] = "10-60 sp";
statblock_human["Merchant Sailor/Fisherman"]["Alignment:"] = "Any";
statblock_human["Merchant Sailor/Fisherman"]["No. Appearing:"] = "4-80 (4d20)";
statblock_human["Merchant Sailor/Fisherman"]["Armor Class:"] = "10 to 8";
statblock_human["Merchant Sailor/Fisherman"]["Hit Dice:"] = "1-6 hp";
statblock_human["Merchant Sailor/Fisherman"]["THAC0:"] = "20";
statblock_human["Merchant Sailor/Fisherman"]["Morale:"] = "Average (9)";
statblock_human["Merchant Sailor/Fisherman"]["XP Value:"] = "15";
statblock_human["Merchant/Trader"]["Frequency:"] = "Common";
statblock_human["Merchant/Trader"]["Treasure:"] = "10-1,000 gp";
statblock_human["Merchant/Trader"]["Alignment:"] = "Any";
statblock_human["Merchant/Trader"]["No. Appearing:"] = "30-300 (3d10>010)";
statblock_human["Merchant/Trader"]["Armor Class:"] = "10 to 5";
statblock_human["Merchant/Trader"]["Hit Dice:"] = "1-6 hp";
statblock_human["Merchant/Trader"]["THAC0:"] = "20";
statblock_human["Merchant/Trader"]["Morale:"] = "Average (9)";
statblock_human["Merchant/Trader"]["XP Value:"] = "15";
statblock_human["Middle Class"]["Frequency:"] = "Common";
statblock_human["Middle Class"]["Treasure:"] = "J,M,N";
statblock_human["Middle Class"]["Alignment:"] = "Any";
statblock_human["Middle Class"]["No. Appearing:"] = "2-40 (2d20)";
statblock_human["Middle Class"]["Armor Class:"] = "10";
statblock_human["Middle Class"]["Hit Dice:"] = "1-6 hp";
statblock_human["Middle Class"]["THAC0:"] = "20";
statblock_human["Middle Class"]["Morale:"] = "Average (9)";
statblock_human["Middle Class"]["XP Value:"] = "15";
statblock_human["Peasant/Serf"]["Frequency:"] = "Common";
statblock_human["Peasant/Serf"]["Treasure:"] = "Nil";
statblock_human["Peasant/Serf"]["Alignment:"] = "Any";
statblock_human["Peasant/Serf"]["No. Appearing:"] = "1-100";
statblock_human["Peasant/Serf"]["Armor Class:"] = "10";
statblock_human["Peasant/Serf"]["Hit Dice:"] = "1-6 hp";
statblock_human["Peasant/Serf"]["THAC0:"] = "20";
statblock_human["Peasant/Serf"]["Morale:"] = "Average (9)";
statblock_human["Peasant/Serf"]["XP Value:"] = "15";
statblock_human["Pilgrim"]["Frequency:"] = "Uncommon";
statblock_human["Pilgrim"]["Treasure:"] = "I";
statblock_human["Pilgrim"]["Alignment:"] = "Any";
statblock_human["Pilgrim"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Pilgrim"]["Armor Class:"] = "10 to 8";
statblock_human["Pilgrim"]["Hit Dice:"] = "1-6 hp";
statblock_human["Pilgrim"]["THAC0:"] = "20";
statblock_human["Pilgrim"]["Morale:"] = "Average (9)";
statblock_human["Pilgrim"]["XP Value:"] = "15";
statblock_human["Pirate/Buccaneer"]["Frequency:"] = "Common";
statblock_human["Pirate/Buccaneer"]["Treasure:"] = "J,M,N,Q";
statblock_human["Pirate/Buccaneer"]["Alignment:"] = "Any evil";
statblock_human["Pirate/Buccaneer"]["No. Appearing:"] = "30-300 (30d10)";
statblock_human["Pirate/Buccaneer"]["Armor Class:"] = "10 to 6";
statblock_human["Pirate/Buccaneer"]["Hit Dice:"] = "1-6 hp";
statblock_human["Pirate/Buccaneer"]["THAC0:"] = "20";
statblock_human["Pirate/Buccaneer"]["Morale:"] = "Average (9)";
statblock_human["Pirate/Buccaneer"]["XP Value:"] = "15";
statblock_human["Police/Constabulary"]["Frequency:"] = "Uncommon";
statblock_human["Police/Constabulary"]["Treasure:"] = "10-60 sp";
statblock_human["Police/Constabulary"]["Alignment:"] = "Any lawful";
statblock_human["Police/Constabulary"]["No. Appearing:"] = "2-20 (2d10)";
statblock_human["Police/Constabulary"]["Armor Class:"] = "7 to 4";
statblock_human["Police/Constabulary"]["Hit Dice:"] = "1-6 hp";
statblock_human["Police/Constabulary"]["THAC0:"] = "20";
statblock_human["Police/Constabulary"]["Morale:"] = "Steady (10)";
statblock_human["Police/Constabulary"]["XP Value:"] = "15";
statblock_human["Priest"]["Frequency:"] = "Very rare";
statblock_human["Priest"]["Treasure:"] = "J,K,M";
statblock_human["Priest"]["Alignment:"] = "Any";
statblock_human["Priest"]["No. Appearing:"] = "1-8";
statblock_human["Priest"]["Armor Class:"] = "Varies";
statblock_human["Priest"]["Hit Dice:"] = "1-6 hp";
statblock_human["Priest"]["THAC0:"] = "20";
statblock_human["Priest"]["Morale:"] = "Varies";
statblock_human["Priest"]["XP Value:"] = "Varies";
statblock_human["Sailor"]["Frequency:"] = "Common";
statblock_human["Sailor"]["Treasure:"] = "L,M";
statblock_human["Sailor"]["Alignment:"] = "Any";
statblock_human["Sailor"]["No. Appearing:"] = "4-80 (4d20)";
statblock_human["Sailor"]["Armor Class:"] = "10 to 8";
statblock_human["Sailor"]["Hit Dice:"] = "1-6 hp";
statblock_human["Sailor"]["THAC0:"] = "20";
statblock_human["Sailor"]["Morale:"] = "Average (9)";
statblock_human["Sailor"]["XP Value:"] = "15";
statblock_human["Slaver"]["Frequency:"] = "Common";
statblock_human["Slaver"]["Treasure:"] = "Nil";
statblock_human["Slaver"]["Alignment:"] = "Any";
statblock_human["Slaver"]["No. Appearing:"] = "1-100";
statblock_human["Slaver"]["Armor Class:"] = "10";
statblock_human["Slaver"]["Hit Dice:"] = "1-6 hp";
statblock_human["Slaver"]["THAC0:"] = "20";
statblock_human["Slaver"]["Morale:"] = "Average (9)";
statblock_human["Slaver"]["XP Value:"] = "15";
statblock_human["Soldier"]["Frequency:"] = "Uncommon";
statblock_human["Soldier"]["Treasure:"] = "I";
statblock_human["Soldier"]["Alignment:"] = "Any";
statblock_human["Soldier"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Soldier"]["Armor Class:"] = "8 to 4";
statblock_human["Soldier"]["Hit Dice:"] = "1-6 hp";
statblock_human["Soldier"]["THAC0:"] = "20";
statblock_human["Soldier"]["Morale:"] = "Steady (10-12)";
statblock_human["Soldier"]["XP Value:"] = "15";
statblock_human["Thief/Thug"]["Frequency:"] = "Common";
statblock_human["Thief/Thug"]["Treasure:"] = "J,M,N,Q";
statblock_human["Thief/Thug"]["Alignment:"] = "Any evil";
statblock_human["Thief/Thug"]["No. Appearing:"] = "1-8";
statblock_human["Thief/Thug"]["Armor Class:"] = "10 to 8";
statblock_human["Thief/Thug"]["Hit Dice:"] = "1 to 3";
statblock_human["Thief/Thug"]["THAC0:"] = "20";
statblock_human["Thief/Thug"]["Morale:"] = "Varies";
statblock_human["Thief/Thug"]["XP Value:"] = "Varies";
statblock_human["Tradesman/Craftsman"]["Frequency:"] = "Common";
statblock_human["Tradesman/Craftsman"]["Treasure:"] = "1-100 gp";
statblock_human["Tradesman/Craftsman"]["Alignment:"] = "Any";
statblock_human["Tradesman/Craftsman"]["No. Appearing:"] = "2-12 (2d6)";
statblock_human["Tradesman/Craftsman"]["Armor Class:"] = "10";
statblock_human["Tradesman/Craftsman"]["Hit Dice:"] = "1-6 hp";
statblock_human["Tradesman/Craftsman"]["THAC0:"] = "20";
statblock_human["Tradesman/Craftsman"]["Morale:"] = "Average (8-9)";
statblock_human["Tradesman/Craftsman"]["XP Value:"] = "15";
statblock_human["Tribesman"]["Frequency:"] = "Rare";
statblock_human["Tribesman"]["Treasure:"] = "Nil";
statblock_human["Tribesman"]["Alignment:"] = "Any";
statblock_human["Tribesman"]["No. Appearing:"] = "10-100 (10d10)";
statblock_human["Tribesman"]["Armor Class:"] = "8";
statblock_human["Tribesman"]["Hit Dice:"] = "1-6 hp";
statblock_human["Tribesman"]["THAC0:"] = "20";
statblock_human["Tribesman"]["Morale:"] = "Average (9)";
statblock_human["Tribesman"]["XP Value:"] = "15";
statblock_human["Wizard"]["Frequency:"] = "Very rare";
statblock_human["Wizard"]["Treasure:"] = "L,N,Q";
statblock_human["Wizard"]["Alignment:"] = "Any";
statblock_human["Wizard"]["No. Appearing:"] = "1-8";
statblock_human["Wizard"]["Armor Class:"] = "10";
statblock_human["Wizard"]["Hit Dice:"] = "Varies";
statblock_human["Wizard"]["THAC0:"] = "Varies";
statblock_human["Wizard"]["Morale:"] = "Varies";
statblock_human["Wizard"]["XP Value:"] = "Varies";


/////////////////////////////////////////////////////////////
// insect

// Ant, Giant
// Ant Lion, Giant
// Aratha
// Aspis, Cow
// Aspis, Drone
// Aspis, Larva
// Assassin Bug
// Bee, Worker
// Bee, Soldier
// Bumblebee
// Cave Cricket
// Dragonfly, Giant
// Dragonfly, Larva
// Ear Seeker
// Firefriend
// Fly, Bluebottle
// Fly, Horsefly
// Fyrefly
// Horax
// Hornet, Giant
// Pernicon
// Praying Mantis
// Termite, Giant Harvester, King
// Termite, Giant Harvester, Queen
// Termite, Giant Harvester, Soldier
// Termite, Giant Harvester, Worker
// Tick, Giant


statblock_insect["Ant, Giant"]["No. Appearing"] = "1-100";
statblock_insect["Ant, Giant"]["Armor Class"] = "3";
statblock_insect["Ant, Giant"]["Movement"] = "18";
statblock_insect["Ant, Giant"]["Hit Dice"] = "2 or 3";
statblock_insect["Ant, Giant"]["THAC0"] = "16";
statblock_insect["Ant, Giant"]["No. of Attacks"] = "1";
statblock_insect["Ant, Giant"]["Damage/Attack"] = "1-6 or 2-8";
statblock_insect["Ant, Giant"]["Morale"] = "Average (9)";
statblock_insect["Ant, Giant"]["XP Value"] = "Worker: 35 Warrior: 175";
statblock_insect["Ant Lion, Giant"]["No. Appearing"] = "1";
statblock_insect["Ant Lion, Giant"]["Armor Class"] = "2";
statblock_insect["Ant Lion, Giant"]["Movement"] = "9, Br 1";
statblock_insect["Ant Lion, Giant"]["Hit Dice"] = "8";
statblock_insect["Ant Lion, Giant"]["THAC0"] = "12";
statblock_insect["Ant Lion, Giant"]["No. of Attacks"] = "1";
statblock_insect["Ant Lion, Giant"]["Damage/Attack"] = "5-20";
statblock_insect["Ant Lion, Giant"]["Morale"] = "Average (8)";
statblock_insect["Ant Lion, Giant"]["XP Value"] = "1,400";
statblock_insect["Aratha"]["No. Appearing"] = "1";
statblock_insect["Aratha"]["Armor Class"] = "3";
statblock_insect["Aratha"]["Movement"] = "11";
statblock_insect["Aratha"]["Hit Dice"] = "9";
statblock_insect["Aratha"]["THAC0"] = "11";
statblock_insect["Aratha"]["No. of Attacks"] = "4";
statblock_insect["Aratha"]["Damage/Attack"] = "1-10(×4)";
statblock_insect["Aratha"]["Morale"] = "Elite (16)";
statblock_insect["Aratha"]["XP Value"] = "6,000";
statblock_insect["Aspis, Cow"]["No. Appearing"] = "1";
statblock_insect["Aspis, Cow"]["Armor Class"] = "7";
statblock_insect["Aspis, Cow"]["Movement"] = "3";
statblock_insect["Aspis, Cow"]["Hit Dice"] = "10";
statblock_insect["Aspis, Cow"]["THAC0"] = "11";
statblock_insect["Aspis, Cow"]["No. of Attacks"] = "1";
statblock_insect["Aspis, Cow"]["Damage/Attack"] = "3-18";
statblock_insect["Aspis, Cow"]["Morale"] = "Elite (13-14)";
statblock_insect["Aspis, Cow"]["XP Value"] = "2,000";
statblock_insect["Aspis, Drone"]["No. Appearing"] = "2-20";
statblock_insect["Aspis, Drone"]["Armor Class"] = "3";
statblock_insect["Aspis, Drone"]["Movement"] = "15";
statblock_insect["Aspis, Drone"]["Hit Dice"] = "6";
statblock_insect["Aspis, Drone"]["THAC0"] = "15";
statblock_insect["Aspis, Drone"]["No. of Attacks"] = "2";
statblock_insect["Aspis, Drone"]["Damage/Attack"] = "1d4 or weapon";
statblock_insect["Aspis, Drone"]["Morale"] = "Elite (13-14)";
statblock_insect["Aspis, Drone"]["XP Value"] = "650";
statblock_insect["Aspis, Larva"]["No. Appearing"] = "6-60";
statblock_insect["Aspis, Larva"]["Armor Class"] = "6";
statblock_insect["Aspis, Larva"]["Movement"] = "1, Sw 6";
statblock_insect["Aspis, Larva"]["Hit Dice"] = "2 to 5";
statblock_insect["Aspis, Larva"]["THAC0"] = "2 HD: 19 3-4 HD: 17 5 HD: 15";
statblock_insect["Aspis, Larva"]["No. of Attacks"] = "1";
statblock_insect["Aspis, Larva"]["Damage/Attack"] = "2-7";
statblock_insect["Aspis, Larva"]["Morale"] = "2-3 HD: Steady 4-5 HD: Elite";
statblock_insect["Aspis, Larva"]["XP Value"] = "2 HD: 65 3 HD: 120 4 HD: 175 5 HD: 270";
statblock_insect["Assassin Bug"]["No. Appearing"] = "2";
statblock_insect["Assassin Bug"]["Armor Class"] = "5";
statblock_insect["Assassin Bug"]["Movement"] = "6, Fl 18 (C)";
statblock_insect["Assassin Bug"]["Hit Dice"] = "1+1";
statblock_insect["Assassin Bug"]["THAC0"] = "20";
statblock_insect["Assassin Bug"]["No. of Attacks"] = "1";
statblock_insect["Assassin Bug"]["Damage/Attack"] = "1-4";
statblock_insect["Assassin Bug"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Assassin Bug"]["XP Value"] = "120";
statblock_insect["Bee, Worker"]["No. Appearing"] = "1-10";
statblock_insect["Bee, Worker"]["Armor Class"] = "6";
statblock_insect["Bee, Worker"]["Movement"] = "9, Fl 30 (D)";
statblock_insect["Bee, Worker"]["Hit Dice"] = "3+1";
statblock_insect["Bee, Worker"]["THAC0"] = "17";
statblock_insect["Bee, Worker"]["No. of Attacks"] = "1";
statblock_insect["Bee, Worker"]["Damage/Attack"] = "1-3+poison";
statblock_insect["Bee, Worker"]["Morale"] = "Steady (11-12)";
statblock_insect["Bee, Worker"]["XP Value"] = "175";
statblock_insect["Bee, Soldier"]["No. Appearing"] = "1";
statblock_insect["Bee, Soldier"]["Armor Class"] = "5";
statblock_insect["Bee, Soldier"]["Movement"] = "12, Fl 30 (C)";
statblock_insect["Bee, Soldier"]["Hit Dice"] = "4+2";
statblock_insect["Bee, Soldier"]["THAC0"] = "15";
statblock_insect["Bee, Soldier"]["No. of Attacks"] = "1";
statblock_insect["Bee, Soldier"]["Damage/Attack"] = "1-4+poison";
statblock_insect["Bee, Soldier"]["Morale"] = "Champion (15-16)";
statblock_insect["Bee, Soldier"]["XP Value"] = "270";
statblock_insect["Bumblebee"]["No. Appearing"] = "1";
statblock_insect["Bumblebee"]["Armor Class"] = "5";
statblock_insect["Bumblebee"]["Movement"] = "6, Fl 24 (E)";
statblock_insect["Bumblebee"]["Hit Dice"] = "6+4";
statblock_insect["Bumblebee"]["THAC0"] = "13";
statblock_insect["Bumblebee"]["No. of Attacks"] = "1";
statblock_insect["Bumblebee"]["Damage/Attack"] = "1-6+poison";
statblock_insect["Bumblebee"]["Morale"] = "Elite (13-14)";
statblock_insect["Bumblebee"]["XP Value"] = "650";
statblock_insect["Cave Cricket"]["No. Appearing"] = "1-8";
statblock_insect["Cave Cricket"]["Armor Class"] = "4";
statblock_insect["Cave Cricket"]["Movement"] = "6, Hop 3";
statblock_insect["Cave Cricket"]["Hit Dice"] = "1+3";
statblock_insect["Cave Cricket"]["THAC0"] = "20";
statblock_insect["Cave Cricket"]["No. of Attacks"] = "Nil";
statblock_insect["Cave Cricket"]["Damage/Attack"] = "Nil";
statblock_insect["Cave Cricket"]["Morale"] = "Unreliable (2-4)";
statblock_insect["Cave Cricket"]["XP Value"] = "15";
statblock_insect["Dragonfly, Giant"]["No. Appearing"] = "1-6";
statblock_insect["Dragonfly, Giant"]["Armor Class"] = "3";
statblock_insect["Dragonfly, Giant"]["Movement"] = "3, Fl 36 (B)";
statblock_insect["Dragonfly, Giant"]["Hit Dice"] = "7";
statblock_insect["Dragonfly, Giant"]["THAC0"] = "13";
statblock_insect["Dragonfly, Giant"]["No. of Attacks"] = "1";
statblock_insect["Dragonfly, Giant"]["Damage/Attack"] = "3-12";
statblock_insect["Dragonfly, Giant"]["Morale"] = "Steady (11-12)";
statblock_insect["Dragonfly, Giant"]["XP Value"] = "1,400";
statblock_insect["Dragonfly, Larva"]["No. Appearing"] = "1";
statblock_insect["Dragonfly, Larva"]["Armor Class"] = "3";
statblock_insect["Dragonfly, Larva"]["Movement"] = "9, Sw 3 (jet 24)";
statblock_insect["Dragonfly, Larva"]["Hit Dice"] = "6+1";
statblock_insect["Dragonfly, Larva"]["THAC0"] = "15";
statblock_insect["Dragonfly, Larva"]["No. of Attacks"] = "1";
statblock_insect["Dragonfly, Larva"]["Damage/Attack"] = "3-18";
statblock_insect["Dragonfly, Larva"]["Morale"] = "Steady (11-12)";
statblock_insect["Dragonfly, Larva"]["XP Value"] = "650";
statblock_insect["Ear Seeker"]["No. Appearing"] = "1-4";
statblock_insect["Ear Seeker"]["Armor Class"] = "9";
statblock_insect["Ear Seeker"]["Movement"] = "1";
statblock_insect["Ear Seeker"]["Hit Dice"] = "1 hp";
statblock_insect["Ear Seeker"]["THAC0"] = "20";
statblock_insect["Ear Seeker"]["No. of Attacks"] = "1";
statblock_insect["Ear Seeker"]["Damage/Attack"] = "See below";
statblock_insect["Ear Seeker"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Ear Seeker"]["XP Value"] = "15";
statblock_insect["Firefriend"]["No. Appearing"] = "1-4";
statblock_insect["Firefriend"]["Armor Class"] = "4";
statblock_insect["Firefriend"]["Movement"] = "3, Fl 18 (B)";
statblock_insect["Firefriend"]["Hit Dice"] = "1+4";
statblock_insect["Firefriend"]["THAC0"] = "20";
statblock_insect["Firefriend"]["No. of Attacks"] = "1";
statblock_insect["Firefriend"]["Damage/Attack"] = "1-2";
statblock_insect["Firefriend"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Firefriend"]["XP Value"] = "35";
statblock_insect["Fly, Bluebottle"]["No. Appearing"] = "1-10";
statblock_insect["Fly, Bluebottle"]["Armor Class"] = "6";
statblock_insect["Fly, Bluebottle"]["Movement"] = "9, Fl 30 (D)";
statblock_insect["Fly, Bluebottle"]["Hit Dice"] = "3";
statblock_insect["Fly, Bluebottle"]["THAC0"] = "19";
statblock_insect["Fly, Bluebottle"]["No. of Attacks"] = "1";
statblock_insect["Fly, Bluebottle"]["Damage/Attack"] = "1-8";
statblock_insect["Fly, Bluebottle"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Fly, Bluebottle"]["XP Value"] = "65";
statblock_insect["Fly, Horsefly"]["No. Appearing"] = "1-4";
statblock_insect["Fly, Horsefly"]["Armor Class"] = "5";
statblock_insect["Fly, Horsefly"]["Movement"] = "6, Fl 27 (D)";
statblock_insect["Fly, Horsefly"]["Hit Dice"] = "6";
statblock_insect["Fly, Horsefly"]["THAC0"] = "17";
statblock_insect["Fly, Horsefly"]["No. of Attacks"] = "1";
statblock_insect["Fly, Horsefly"]["Damage/Attack"] = "2-16";
statblock_insect["Fly, Horsefly"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Fly, Horsefly"]["XP Value"] = "270";
statblock_insect["Fyrefly"]["No. Appearing"] = "1";
statblock_insect["Fyrefly"]["Armor Class"] = "5, Fl 18 (A)";
statblock_insect["Fyrefly"]["Movement"] = "1 hp";
statblock_insect["Fyrefly"]["Hit Dice"] = "15";
statblock_insect["Fyrefly"]["THAC0"] = "1";
statblock_insect["Fyrefly"]["No. of Attacks"] = "1";
statblock_insect["Fyrefly"]["Damage/Attack"] = "Steady (11)";
statblock_insect["Fyrefly"]["Morale"] = "175";
statblock_insect["Fyrefly"]["XP Value"] = "";
statblock_insect["Horax"]["No. Appearing"] = "3-30";
statblock_insect["Horax"]["Armor Class"] = "3";
statblock_insect["Horax"]["Movement"] = "15";
statblock_insect["Horax"]["Hit Dice"] = "4";
statblock_insect["Horax"]["THAC0"] = "17";
statblock_insect["Horax"]["No. of Attacks"] = "1";
statblock_insect["Horax"]["Damage/Attack"] = "2d8";
statblock_insect["Horax"]["Morale"] = "Average (10)";
statblock_insect["Horax"]["XP Value"] = "Adult: 270 Young: 15";
statblock_insect["Hornet, Giant"]["No. Appearing"] = "1";
statblock_insect["Hornet, Giant"]["Armor Class"] = "2";
statblock_insect["Hornet, Giant"]["Movement"] = "6, Fl 24 (B)";
statblock_insect["Hornet, Giant"]["Hit Dice"] = "5";
statblock_insect["Hornet, Giant"]["THAC0"] = "15";
statblock_insect["Hornet, Giant"]["No. of Attacks"] = "1";
statblock_insect["Hornet, Giant"]["Damage/Attack"] = "1-4";
statblock_insect["Hornet, Giant"]["Morale"] = "Average (8-10)";
statblock_insect["Hornet, Giant"]["XP Value"] = "650";
statblock_insect["Pernicon"]["No. Appearing"] = "4-200";
statblock_insect["Pernicon"]["Armor Class"] = "3";
statblock_insect["Pernicon"]["Movement"] = "12";
statblock_insect["Pernicon"]["Hit Dice"] = "1 hp";
statblock_insect["Pernicon"]["THAC0"] = "20";
statblock_insect["Pernicon"]["No. of Attacks"] = "1";
statblock_insect["Pernicon"]["Damage/Attack"] = "1-10";
statblock_insect["Pernicon"]["Morale"] = "Unreliable (4)";
statblock_insect["Pernicon"]["XP Value"] = "15";
statblock_insect["Praying Mantis"]["No. Appearing"] = "1-2";
statblock_insect["Praying Mantis"]["Armor Class"] = "5";
statblock_insect["Praying Mantis"]["Movement"] = "15";
statblock_insect["Praying Mantis"]["Hit Dice"] = "2 to 12";
statblock_insect["Praying Mantis"]["THAC0"] = "2 HD: 19 4 HD: 17 6 HD: 15 8 HD: 13 10 HD: 11 12 HD: 9";
statblock_insect["Praying Mantis"]["No. of Attacks"] = "3";
statblock_insect["Praying Mantis"]["Damage/Attack"] = "2-4 HD: 1-2/1-2/1-4 6-8 HD: 1-4/1-4/1-8 10 HD: 1-6/1-6/1-10 12 HD: 1-8/1-8/1-12";
statblock_insect["Praying Mantis"]["Morale"] = "Fearless (19-20)";
statblock_insect["Praying Mantis"]["XP Value"] = "2 HD: 35 4 HD: 120 6 HD: 270 8 HD: 650 10 HD: 1,400 12 HD: 2,000";
statblock_insect["Termite, Giant Harvester"]["No. Appearing"] = "";
statblock_insect["Termite, Giant Harvester"]["Armor Class"] = "";
statblock_insect["Termite, Giant Harvester"]["Movement"] = "";
statblock_insect["Termite, Giant Harvester"]["Hit Dice"] = "";
statblock_insect["Termite, Giant Harvester"]["THAC0"] = "";
statblock_insect["Termite, Giant Harvester"]["No. of Attacks"] = "";
statblock_insect["Termite, Giant Harvester"]["Damage/Attack"] = "";
statblock_insect["Termite, Giant Harvester"]["Morale"] = "";
statblock_insect["Termite, Giant Harvester"]["XP Value"] = "";
statblock_insect["King"]["No. Appearing"] = "1";
statblock_insect["King"]["Armor Class"] = "5";
statblock_insect["King"]["Movement"] = "6";
statblock_insect["King"]["Hit Dice"] = "6+6";
statblock_insect["King"]["THAC0"] = "15";
statblock_insect["King"]["No. of Attacks"] = "1";
statblock_insect["King"]["Damage/Attack"] = "3-18";
statblock_insect["King"]["Morale"] = "Unreliable (2-4)";
statblock_insect["King"]["XP Value"] = "975";
statblock_insect["Queen"]["No. Appearing"] = "1";
statblock_insect["Queen"]["Armor Class"] = "4";
statblock_insect["Queen"]["Movement"] = "3";
statblock_insect["Queen"]["Hit Dice"] = "8+8";
statblock_insect["Queen"]["THAC0"] = "13";
statblock_insect["Queen"]["No. of Attacks"] = "1";
statblock_insect["Queen"]["Damage/Attack"] = "5-30";
statblock_insect["Queen"]["Morale"] = "Unsteady (5-7)";
statblock_insect["Queen"]["XP Value"] = "1,400";
statblock_insect["Soldier"]["No. Appearing"] = "3-18";
statblock_insect["Soldier"]["Armor Class"] = "2/8";
statblock_insect["Soldier"]["Movement"] = "9";
statblock_insect["Soldier"]["Hit Dice"] = "2+2";
statblock_insect["Soldier"]["THAC0"] = "19";
statblock_insect["Soldier"]["No. of Attacks"] = "1";
statblock_insect["Soldier"]["Damage/Attack"] = "1-4";
statblock_insect["Soldier"]["Morale"] = "Elite (13-14)";
statblock_insect["Soldier"]["XP Value"] = "120";
statblock_insect["Worker"]["No. Appearing"] = "6-60";
statblock_insect["Worker"]["Armor Class"] = "2/10";
statblock_insect["Worker"]["Movement"] = "9";
statblock_insect["Worker"]["Hit Dice"] = "1+2";
statblock_insect["Worker"]["THAC0"] = "20";
statblock_insect["Worker"]["No. of Attacks"] = "1";
statblock_insect["Worker"]["Damage/Attack"] = "1-2";
statblock_insect["Worker"]["Morale"] = "Average (8-10)";
statblock_insect["Worker"]["XP Value"] = "35";
statblock_insect["Tick, Giant"]["No. Appearing"] = "3-12";
statblock_insect["Tick, Giant"]["Armor Class"] = "3";
statblock_insect["Tick, Giant"]["Movement"] = "3";
statblock_insect["Tick, Giant"]["Hit Dice"] = "2 to 4";
statblock_insect["Tick, Giant"]["THAC0"] = "2 HD: 19 3-4 HD: 17";
statblock_insect["Tick, Giant"]["No. of Attacks"] = "1";
statblock_insect["Tick, Giant"]["Damage/Attack"] = "1-4";
statblock_insect["Tick, Giant"]["Morale"] = "Average (8-10)";
statblock_insect["Tick, Giant"]["XP Value"] = "2 HD: 35 3 HD: 65 4 HD: 120";
statblock_insect["Wasp, Giant"]["No. Appearing"] = "1-20";
statblock_insect["Wasp, Giant"]["Armor Class"] = "4";
statblock_insect["Wasp, Giant"]["Movement"] = "6, Fl 21 (B)";
statblock_insect["Wasp, Giant"]["Hit Dice"] = "4";
statblock_insect["Wasp, Giant"]["THAC0"] = "17";
statblock_insect["Wasp, Giant"]["No. of Attacks"] = "2";
statblock_insect["Wasp, Giant"]["Damage/Attack"] = "2-8/1-4";
statblock_insect["Wasp, Giant"]["Morale"] = "Average (8-10)";
statblock_insect["Wasp, Giant"]["XP Value"] = "420";



/////////////////////////////////////////////////////////////
// lycanthg
// Extra special. I could conceivably calculate all of the
// stats for each of the listed giant types. May come back
// to this later.


/////////////////////////////////////////////////////////////
// mammal

// Ape, Carnivorous
// Baboon, Wild
// Badger
// Banderlog
// Bhaergala
// Boar, Wild
// Chattur
// Cooshee
// Dakon
// Debbi
// Goat
// Gorilla
// Hsing-sing
// Hyena
// Jackal
// Losel
// Monkey Spider
// Porcupine
// Rothé
// Skunk
// Sleek
// Stag, Wild
// Stench Kow
// Taer
// Tyrg
// Warthog
// Weasel
// Wolverine

statblock_mammal["Ape, Carnivorous"]["No. Appearing"] = "2-8";
statblock_mammal["Ape, Carnivorous"]["Armor Class"] = "6";
statblock_mammal["Ape, Carnivorous"]["Movement"] = "12, 9 in trees";
statblock_mammal["Ape, Carnivorous"]["Hit Dice"] = "5";
statblock_mammal["Ape, Carnivorous"]["THAC0"] = "15";
statblock_mammal["Ape, Carnivorous"]["No. of Attacks"] = "3";
statblock_mammal["Ape, Carnivorous"]["Damage/Attack"] = "1-4/1-4/1-8";
statblock_mammal["Ape, Carnivorous"]["Morale"] = "Steady (11-12)";
statblock_mammal["Ape, Carnivorous"]["XP Value"] = "175";
statblock_mammal["Baboon, Wild"]["No. Appearing"] = "10-40";
statblock_mammal["Baboon, Wild"]["Armor Class"] = "7";
statblock_mammal["Baboon, Wild"]["Movement"] = "12, 12 in trees";
statblock_mammal["Baboon, Wild"]["Hit Dice"] = "1+1";
statblock_mammal["Baboon, Wild"]["THAC0"] = "19";
statblock_mammal["Baboon, Wild"]["No. of Attacks"] = "1";
statblock_mammal["Baboon, Wild"]["Damage/Attack"] = "1-4";
statblock_mammal["Baboon, Wild"]["Morale"] = "Unsteady (5-7)";
statblock_mammal["Baboon, Wild"]["XP Value"] = "35";
statblock_mammal["Badger"]["No. Appearing"] = "2-5";
statblock_mammal["Badger"]["Armor Class"] = "4";
statblock_mammal["Badger"]["Movement"] = "6, Br 3";
statblock_mammal["Badger"]["Hit Dice"] = "1+2";
statblock_mammal["Badger"]["THAC0"] = "19";
statblock_mammal["Badger"]["No. of Attacks"] = "3";
statblock_mammal["Badger"]["Damage/Attack"] = "1-2/1-2/1-3";
statblock_mammal["Badger"]["Morale"] = "Average (8-10)";
statblock_mammal["Badger"]["XP Value"] = "35";
statblock_mammal["Banderlog"]["No. Appearing"] = "4-24";
statblock_mammal["Banderlog"]["Armor Class"] = "6";
statblock_mammal["Banderlog"]["Movement"] = "6, 12 in trees";
statblock_mammal["Banderlog"]["Hit Dice"] = "4";
statblock_mammal["Banderlog"]["THAC0"] = "15";
statblock_mammal["Banderlog"]["No. of Attacks"] = "1";
statblock_mammal["Banderlog"]["Damage/Attack"] = "2-5";
statblock_mammal["Banderlog"]["Morale"] = "Average (8-10)";
statblock_mammal["Banderlog"]["XP Value"] = "120";
statblock_mammal["Bhaergala"]["No. Appearing"] = "1";
statblock_mammal["Bhaergala"]["Armor Class"] = "6";
statblock_mammal["Bhaergala"]["Movement"] = "15";
statblock_mammal["Bhaergala"]["Hit Dice"] = "4+4";
statblock_mammal["Bhaergala"]["THAC0"] = "15";
statblock_mammal["Bhaergala"]["No. of Attacks"] = "3";
statblock_mammal["Bhaergala"]["Damage/Attack"] = "1-6/1-6/1-8";
statblock_mammal["Bhaergala"]["Morale"] = "Elite (13-14)";
statblock_mammal["Bhaergala"]["XP Value"] = "650";
statblock_mammal["Boar, Wild"]["No. Appearing"] = "1-12";
statblock_mammal["Boar, Wild"]["Armor Class"] = "7";
statblock_mammal["Boar, Wild"]["Movement"] = "15";
statblock_mammal["Boar, Wild"]["Hit Dice"] = "3+3";
statblock_mammal["Boar, Wild"]["THAC0"] = "17";
statblock_mammal["Boar, Wild"]["No. of Attacks"] = "1";
statblock_mammal["Boar, Wild"]["Damage/Attack"] = "3-12";
statblock_mammal["Boar, Wild"]["Morale"] = "Average (8-12)";
statblock_mammal["Boar, Wild"]["XP Value"] = "175";
statblock_mammal["Chattur"]["No. Appearing"] = "2-24";
statblock_mammal["Chattur"]["Armor Class"] = "7";
statblock_mammal["Chattur"]["Movement"] = "12";
statblock_mammal["Chattur"]["Hit Dice"] = "1-1";
statblock_mammal["Chattur"]["THAC0"] = "20";
statblock_mammal["Chattur"]["No. of Attacks"] = "1";
statblock_mammal["Chattur"]["Damage/Attack"] = "1-4 (or weapon)";
statblock_mammal["Chattur"]["Morale"] = "Average (8-10)";
statblock_mammal["Chattur"]["XP Value"] = "15";
statblock_mammal["Cooshee"]["No. Appearing"] = "1-8";
statblock_mammal["Cooshee"]["Armor Class"] = "5";
statblock_mammal["Cooshee"]["Movement"] = "15, sprint 24";
statblock_mammal["Cooshee"]["Hit Dice"] = "3+3";
statblock_mammal["Cooshee"]["THAC0"] = "17";
statblock_mammal["Cooshee"]["No. of Attacks"] = "3";
statblock_mammal["Cooshee"]["Damage/Attack"] = "1-4/1-4/2-8";
statblock_mammal["Cooshee"]["Morale"] = "Steady (11-12)";
statblock_mammal["Cooshee"]["XP Value"] = "270";
statblock_mammal["Dakon"]["No. Appearing"] = "6-60";
statblock_mammal["Dakon"]["Armor Class"] = "5";
statblock_mammal["Dakon"]["Movement"] = "6";
statblock_mammal["Dakon"]["Hit Dice"] = "1+1";
statblock_mammal["Dakon"]["THAC0"] = "20";
statblock_mammal["Dakon"]["No. of Attacks"] = "2";
statblock_mammal["Dakon"]["Damage/Attack"] = "1-10/1-10";
statblock_mammal["Dakon"]["Morale"] = "Champion (15-16)";
statblock_mammal["Dakon"]["XP Value"] = "65";
statblock_mammal["Debbi"]["No. Appearing"] = "1-8";
statblock_mammal["Debbi"]["Armor Class"] = "7";
statblock_mammal["Debbi"]["Movement"] = "15, climb 6";
statblock_mammal["Debbi"]["Hit Dice"] = "1+1";
statblock_mammal["Debbi"]["THAC0"] = "19";
statblock_mammal["Debbi"]["No. of Attacks"] = "1";
statblock_mammal["Debbi"]["Damage/Attack"] = "1-4";
statblock_mammal["Debbi"]["Morale"] = "Unsteady (5-7)";
statblock_mammal["Debbi"]["XP Value"] = "65";
statblock_mammal["Goat"]["No. Appearing"] = "5-20";
statblock_mammal["Goat"]["Armor Class"] = "7";
statblock_mammal["Goat"]["Movement"] = "15";
statblock_mammal["Goat"]["Hit Dice"] = "1+2";
statblock_mammal["Goat"]["THAC0"] = "19";
statblock_mammal["Goat"]["No. of Attacks"] = "1";
statblock_mammal["Goat"]["Damage/Attack"] = "1-3";
statblock_mammal["Goat"]["Morale"] = "Average (8-10)";
statblock_mammal["Goat"]["XP Value"] = "35";
statblock_mammal["Gorilla"]["No. Appearing"] = "1-4";
statblock_mammal["Gorilla"]["Armor Class"] = "6";
statblock_mammal["Gorilla"]["Movement"] = "12";
statblock_mammal["Gorilla"]["Hit Dice"] = "4+1";
statblock_mammal["Gorilla"]["THAC0"] = "17";
statblock_mammal["Gorilla"]["No. of Attacks"] = "3";
statblock_mammal["Gorilla"]["Damage/Attack"] = "1-3/1-3/1-6";
statblock_mammal["Gorilla"]["Morale"] = "Average (8-10)";
statblock_mammal["Gorilla"]["XP Value"] = "175";
statblock_mammal["Hsing-sing"]["No. Appearing"] = "2-20";
statblock_mammal["Hsing-sing"]["Armor Class"] = "6";
statblock_mammal["Hsing-sing"]["Movement"] = "6, Sw 9";
statblock_mammal["Hsing-sing"]["Hit Dice"] = "2+1";
statblock_mammal["Hsing-sing"]["THAC0"] = "19";
statblock_mammal["Hsing-sing"]["No. of Attacks"] = "1";
statblock_mammal["Hsing-sing"]["Damage/Attack"] = "1-6 (or weapon)";
statblock_mammal["Hsing-sing"]["Morale"] = "Average (8-10)";
statblock_mammal["Hsing-sing"]["XP Value"] = "65";
statblock_mammal["Hyena"]["No. Appearing"] = "2-12";
statblock_mammal["Hyena"]["Armor Class"] = "7";
statblock_mammal["Hyena"]["Movement"] = "12";
statblock_mammal["Hyena"]["Hit Dice"] = "3";
statblock_mammal["Hyena"]["THAC0"] = "17";
statblock_mammal["Hyena"]["No. of Attacks"] = "1";
statblock_mammal["Hyena"]["Damage/Attack"] = "2-8";
statblock_mammal["Hyena"]["Morale"] = "Unsteady (5-7)";
statblock_mammal["Hyena"]["XP Value"] = "65";
statblock_mammal["Jackal"]["No. Appearing"] = "1-6";
statblock_mammal["Jackal"]["Armor Class"] = "7";
statblock_mammal["Jackal"]["Movement"] = "12";
statblock_mammal["Jackal"]["Hit Dice"] = "½";
statblock_mammal["Jackal"]["THAC0"] = "20";
statblock_mammal["Jackal"]["No. of Attacks"] = "1";
statblock_mammal["Jackal"]["Damage/Attack"] = "1-2";
statblock_mammal["Jackal"]["Morale"] = "Unreliable (2-4)";
statblock_mammal["Jackal"]["XP Value"] = "7";
statblock_mammal["Losel"]["No. Appearing"] = "3-30";
statblock_mammal["Losel"]["Armor Class"] = "7";
statblock_mammal["Losel"]["Movement"] = "6, 9 in trees";
statblock_mammal["Losel"]["Hit Dice"] = "2";
statblock_mammal["Losel"]["THAC0"] = "19";
statblock_mammal["Losel"]["No. of Attacks"] = "3";
statblock_mammal["Losel"]["Damage/Attack"] = "1-3/1-3/1-4";
statblock_mammal["Losel"]["Morale"] = "Unsteady (5-7)";
statblock_mammal["Losel"]["XP Value"] = "120";
statblock_mammal["Spider Monkey"]["No. Appearing"] = "20-60";
statblock_mammal["Spider Monkey"]["Armor Class"] = "6";
statblock_mammal["Spider Monkey"]["Movement"] = "18, climb 18";
statblock_mammal["Spider Monkey"]["Hit Dice"] = "1hp";
statblock_mammal["Spider Monkey"]["THAC0"] = "18";
statblock_mammal["Spider Monkey"]["No. of Attacks"] = "1";
statblock_mammal["Spider Monkey"]["Damage/Attack"] = "1";
statblock_mammal["Spider Monkey"]["Morale"] = "Fanatic (17-18)";
statblock_mammal["Spider Monkey"]["XP Value"] = "1";
statblock_mammal["Porcupine, Black"]["No. Appearing"] = "1-2";
statblock_mammal["Porcupine, Black"]["Armor Class"] = "6";
statblock_mammal["Porcupine, Black"]["Movement"] = "9, climb 2";
statblock_mammal["Porcupine, Black"]["Hit Dice"] = "½";
statblock_mammal["Porcupine, Black"]["THAC0"] = "20";
statblock_mammal["Porcupine, Black"]["No. of Attacks"] = "1";
statblock_mammal["Porcupine, Black"]["Damage/Attack"] = "1-3";
statblock_mammal["Porcupine, Black"]["Morale"] = "Unreliable (2-4)";
statblock_mammal["Porcupine, Black"]["XP Value"] = "15";
statblock_mammal["Porcupine, Brown"]["No. Appearing"] = "1-2";
statblock_mammal["Porcupine, Brown"]["Armor Class"] = "6";
statblock_mammal["Porcupine, Brown"]["Movement"] = "9, climb 2";
statblock_mammal["Porcupine, Brown"]["Hit Dice"] = "½";
statblock_mammal["Porcupine, Brown"]["THAC0"] = "20";
statblock_mammal["Porcupine, Brown"]["No. of Attacks"] = "1";
statblock_mammal["Porcupine, Brown"]["Damage/Attack"] = "1-4";
statblock_mammal["Porcupine, Brown"]["Morale"] = "Unreliable (2-4)";
statblock_mammal["Porcupine, Brown"]["XP Value"] = "15";
statblock_mammal["Rothé"]["No. Appearing"] = "2-20";
statblock_mammal["Rothé"]["Armor Class"] = "7";
statblock_mammal["Rothé"]["Movement"] = "9";
statblock_mammal["Rothé"]["Hit Dice"] = "2";
statblock_mammal["Rothé"]["THAC0"] = "19";
statblock_mammal["Rothé"]["No. of Attacks"] = "3";
statblock_mammal["Rothé"]["Damage/Attack"] = "1-3/1-3/1-8";
statblock_mammal["Rothé"]["Morale"] = "Elite (13-14)";
statblock_mammal["Rothé"]["XP Value"] = "35";
statblock_mammal["Skunk"]["No. Appearing"] = "1-6";
statblock_mammal["Skunk"]["Armor Class"] = "8";
statblock_mammal["Skunk"]["Movement"] = "12";
statblock_mammal["Skunk"]["Hit Dice"] = "¼";
statblock_mammal["Skunk"]["THAC0"] = "20";
statblock_mammal["Skunk"]["No. of Attacks"] = "1";
statblock_mammal["Skunk"]["Damage/Attack"] = "1";
statblock_mammal["Skunk"]["Morale"] = "Unsteady (57)";
statblock_mammal["Skunk"]["XP Value"] = "35";
statblock_mammal["Sleek"]["No. Appearing"] = "1-10";
statblock_mammal["Sleek"]["Armor Class"] = "3";
statblock_mammal["Sleek"]["Movement"] = "36";
statblock_mammal["Sleek"]["Hit Dice"] = "2+1";
statblock_mammal["Sleek"]["THAC0"] = "19";
statblock_mammal["Sleek"]["No. of Attacks"] = "3";
statblock_mammal["Sleek"]["Damage/Attack"] = "1-4/1-4/2-12";
statblock_mammal["Sleek"]["Morale"] = "Steady (11-12)";
statblock_mammal["Sleek"]["XP Value"] = "65";
statblock_mammal["Stag, Wild"]["No. Appearing"] = "1-4";
statblock_mammal["Stag, Wild"]["Armor Class"] = "7";
statblock_mammal["Stag, Wild"]["Movement"] = "24";
statblock_mammal["Stag, Wild"]["Hit Dice"] = "3";
statblock_mammal["Stag, Wild"]["THAC0"] = "17";
statblock_mammal["Stag, Wild"]["No. of Attacks"] = "1 or 2";
statblock_mammal["Stag, Wild"]["Damage/Attack"] = "1-3/1-3 or 2-8";
statblock_mammal["Stag, Wild"]["Morale"] = "Unsteady (5-7)";
statblock_mammal["Stag, Wild"]["XP Value"] = "65";
statblock_mammal["Stench Kow"]["No. Appearing"] = "15-60";
statblock_mammal["Stench Kow"]["Armor Class"] = "2";
statblock_mammal["Stench Kow"]["Movement"] = "15";
statblock_mammal["Stench Kow"]["Hit Dice"] = "3+3";
statblock_mammal["Stench Kow"]["THAC0"] = "17";
statblock_mammal["Stench Kow"]["No. of Attacks"] = "1";
statblock_mammal["Stench Kow"]["Damage/Attack"] = "2-8";
statblock_mammal["Stench Kow"]["Morale"] = "Average (8-10)";
statblock_mammal["Stench Kow"]["XP Value"] = "175";
statblock_mammal["Taer"]["No. Appearing"] = "10-40";
statblock_mammal["Taer"]["Armor Class"] = "4";
statblock_mammal["Taer"]["Movement"] = "18";
statblock_mammal["Taer"]["Hit Dice"] = "3+6";
statblock_mammal["Taer"]["THAC0"] = "17";
statblock_mammal["Taer"]["No. of Attacks"] = "3";
statblock_mammal["Taer"]["Damage/Attack"] = "1-6/1-4/1-4";
statblock_mammal["Taer"]["Morale"] = "Steady (11-12)";
statblock_mammal["Taer"]["XP Value"] = "270";
statblock_mammal["Tyrg"]["No. Appearing"] = "1-10";
statblock_mammal["Tyrg"]["Armor Class"] = "5";
statblock_mammal["Tyrg"]["Movement"] = "18";
statblock_mammal["Tyrg"]["Hit Dice"] = "5-8";
statblock_mammal["Tyrg"]["THAC0"] = "5-6 HD: 15 7-8 HD: 13";
statblock_mammal["Tyrg"]["No. of Attacks"] = "1";
statblock_mammal["Tyrg"]["Damage/Attack"] = "1-12";
statblock_mammal["Tyrg"]["Morale"] = "Elite (13-14)";
statblock_mammal["Tyrg"]["XP Value"] = "5 HD: 270 6 HD: 420 7 HD: 650 8 HD: 975";
statblock_mammal["Warthog"]["No. Appearing"] = "1-6";
statblock_mammal["Warthog"]["Armor Class"] = "7";
statblock_mammal["Warthog"]["Movement"] = "12";
statblock_mammal["Warthog"]["Hit Dice"] = "3";
statblock_mammal["Warthog"]["THAC0"] = "17";
statblock_mammal["Warthog"]["No. of Attacks"] = "2";
statblock_mammal["Warthog"]["Damage/Attack"] = "2-8/1-8";
statblock_mammal["Warthog"]["Morale"] = "Average (8-10)";
statblock_mammal["Warthog"]["XP Value"] = "120";
statblock_mammal["Weasel"]["No. Appearing"] = "1-2";
statblock_mammal["Weasel"]["Armor Class"] = "6";
statblock_mammal["Weasel"]["Movement"] = "15";
statblock_mammal["Weasel"]["Hit Dice"] = "¼";
statblock_mammal["Weasel"]["THAC0"] = "20";
statblock_mammal["Weasel"]["No. of Attacks"] = "1";
statblock_mammal["Weasel"]["Damage/Attack"] = "1";
statblock_mammal["Weasel"]["Morale"] = "Steady (11-12)";
statblock_mammal["Weasel"]["XP Value"] = "7";
statblock_mammal["Wolverine"]["No. Appearing"] = "1";
statblock_mammal["Wolverine"]["Armor Class"] = "5";
statblock_mammal["Wolverine"]["Movement"] = "12";
statblock_mammal["Wolverine"]["Hit Dice"] = "3";
statblock_mammal["Wolverine"]["THAC0"] = "17";
statblock_mammal["Wolverine"]["No. of Attacks"] = "3";
statblock_mammal["Wolverine"]["Damage/Attack"] = "1-4/1-4/2-5";
statblock_mammal["Wolverine"]["Morale"] = "Steady (11-12)";
statblock_mammal["Wolverine"]["XP Value"] = "120";


/////////////////////////////////////////////////////////////
// mammgian

// Badger, Giant
// Beaver, Giant
// Boar, Giant
// Hyena, Giant (Hyenodon)
// Otter, Giant
// Porcupine, Giant
// Skunk, Giant
// Weasel, Giant
// Wolverine, Giant

statblock_mammgian["Badger, giant"]["No. Appearing"] = "2-5";
statblock_mammgian["Badger, giant"]["Armor Class"] = "4";
statblock_mammgian["Badger, giant"]["Movement"] = "6, Br 3";
statblock_mammgian["Badger, giant"]["Hit Dice"] = "3";
statblock_mammgian["Badger, giant"]["THAC0"] = "17";
statblock_mammgian["Badger, giant"]["No. of Attacks"] = "3";
statblock_mammgian["Badger, giant"]["Damage/Attack"] = "1d3/1d3/1d6";
statblock_mammgian["Badger, giant"]["Morale"] = "Steady (11-12)";
statblock_mammgian["Badger, giant"]["Special Attacks"] = "Nil";
statblock_mammgian["Badger, giant"]["XP Value"] = "65";
statblock_mammgian["Beaver, giant"]["No. Appearing"] = "4-40";
statblock_mammgian["Beaver, giant"]["Armor Class"] = "6";
statblock_mammgian["Beaver, giant"]["Movement"] = "6, Sw 12";
statblock_mammgian["Beaver, giant"]["Hit Dice"] = "4";
statblock_mammgian["Beaver, giant"]["THAC0"] = "17";
statblock_mammgian["Beaver, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Beaver, giant"]["Damage/Attack"] = "4d4";
statblock_mammgian["Beaver, giant"]["Morale"] = "Average (8-10)";
statblock_mammgian["Beaver, giant"]["Special Attacks"] = "Nil";
statblock_mammgian["Beaver, giant"]["XP Value"] = "120";
statblock_mammgian["Boar, giant"]["No. Appearing"] = "2-8";
statblock_mammgian["Boar, giant"]["Armor Class"] = "6";
statblock_mammgian["Boar, giant"]["Movement"] = "12";
statblock_mammgian["Boar, giant"]["Hit Dice"] = "7";
statblock_mammgian["Boar, giant"]["THAC0"] = "13";
statblock_mammgian["Boar, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Boar, giant"]["Damage/Attack"] = "3d6";
statblock_mammgian["Boar, giant"]["Morale"] = "Steady (11-12)";
statblock_mammgian["Boar, giant"]["Special Attacks"] = "Special";
statblock_mammgian["Boar, giant"]["XP Value"] = "650";
statblock_mammgian["Hyena (hyenodon)"]["No. Appearing"] = "2-8";
statblock_mammgian["Hyena (hyenodon)"]["Armor Class"] = "7";
statblock_mammgian["Hyena (hyenodon)"]["Movement"] = "12";
statblock_mammgian["Hyena (hyenodon)"]["Hit Dice"] = "5";
statblock_mammgian["Hyena (hyenodon)"]["THAC0"] = "15";
statblock_mammgian["Hyena (hyenodon)"]["No. of Attacks"] = "1";
statblock_mammgian["Hyena (hyenodon)"]["Damage/Attack"] = "3d4";
statblock_mammgian["Hyena (hyenodon)"]["Morale"] = "Average (8-10)";
statblock_mammgian["Hyena (hyenodon)"]["Special Attacks"] = "Nil";
statblock_mammgian["Hyena (hyenodon)"]["XP Value"] = "175";
statblock_mammgian["Porcupine, giant"]["No. Appearing"] = "1-2";
statblock_mammgian["Porcupine, giant"]["Armor Class"] = "5";
statblock_mammgian["Porcupine, giant"]["Movement"] = "6";
statblock_mammgian["Porcupine, giant"]["Hit Dice"] = "6";
statblock_mammgian["Porcupine, giant"]["THAC0"] = "15";
statblock_mammgian["Porcupine, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Porcupine, giant"]["Damage/Attack"] = "3d6";
statblock_mammgian["Porcupine, giant"]["Morale"] = "Average (8-10)";
statblock_mammgian["Porcupine, giant"]["Special Attacks"] = "Nil";
statblock_mammgian["Porcupine, giant"]["XP Value"] = "650";
statblock_mammgian["Otter, giant"]["No. Appearing"] = "2-5";
statblock_mammgian["Otter, giant"]["Armor Class"] = "5";
statblock_mammgian["Otter, giant"]["Movement"] = "9, Sw 18";
statblock_mammgian["Otter, giant"]["Hit Dice"] = "5";
statblock_mammgian["Otter, giant"]["THAC0"] = "15";
statblock_mammgian["Otter, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Otter, giant"]["Damage/Attack"] = "2d4";
statblock_mammgian["Otter, giant"]["Morale"] = "Unsteady (5-7)";
statblock_mammgian["Otter, giant"]["Special Attacks"] = "Shoot quills";
statblock_mammgian["Otter, giant"]["XP Value"] = "175";
statblock_mammgian["Skunk, giant"]["No. Appearing"] = "1";
statblock_mammgian["Skunk, giant"]["Armor Class"] = "7";
statblock_mammgian["Skunk, giant"]["Movement"] = "9";
statblock_mammgian["Skunk, giant"]["Hit Dice"] = "5";
statblock_mammgian["Skunk, giant"]["THAC0"] = "15";
statblock_mammgian["Skunk, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Skunk, giant"]["Damage/Attack"] = "1d6";
statblock_mammgian["Skunk, giant"]["Morale"] = "Average (8-10)";
statblock_mammgian["Skunk, giant"]["Special Attacks"] = "Musk";
statblock_mammgian["Skunk, giant"]["XP Value"] = "420";
statblock_mammgian["Weasel, giant"]["No. Appearing"] = "14";
statblock_mammgian["Weasel, giant"]["Armor Class"] = "6";
statblock_mammgian["Weasel, giant"]["Movement"] = "15";
statblock_mammgian["Weasel, giant"]["Hit Dice"] = "3+3";
statblock_mammgian["Weasel, giant"]["THAC0"] = "17";
statblock_mammgian["Weasel, giant"]["No. of Attacks"] = "1";
statblock_mammgian["Weasel, giant"]["Damage/Attack"] = "2d6";
statblock_mammgian["Weasel, giant"]["Morale"] = "Elite (13-14)";
statblock_mammgian["Weasel, giant"]["Special Attacks"] = "Drain blood";
statblock_mammgian["Weasel, giant"]["XP Value"] = "175";
statblock_mammgian["Wolverine, giant"]["No. Appearing"] = "1";
statblock_mammgian["Wolverine, giant"]["Armor Class"] = "4";
statblock_mammgian["Wolverine, giant"]["Movement"] = "15";
statblock_mammgian["Wolverine, giant"]["Hit Dice"] = "4+4";
statblock_mammgian["Wolverine, giant"]["THAC0"] = "15";
statblock_mammgian["Wolverine, giant"]["No. of Attacks"] = "3";
statblock_mammgian["Wolverine, giant"]["Damage/Attack"] = "1d4+1/1d4+1/2d4";
statblock_mammgian["Wolverine, giant"]["Morale"] = "Elite (13-14)";
statblock_mammgian["Wolverine, giant"]["Special Attacks"] = ".+4 to hit, musk, intelligence";
statblock_mammgian["Wolverine, giant"]["XP Value"] = "975";


/////////////////////////////////////////////////////////////
// mammher2

// Bull (wild ox)
// Caribou
// Goat, Giant
// Hippopotamus
// Llama
// Ram, Giant
// Rhinoceros
// Stag, wild
// Giant Stag


statblock_mammher2["Bull (wild ox)"]["No. Appearing"] = "1-20";
statblock_mammher2["Bull (wild ox)"]["Armor Class"] = "7";
statblock_mammher2["Bull (wild ox)"]["Movement"] = "15";
statblock_mammher2["Bull (wild ox)"]["Hit Dice"] = "4";
statblock_mammher2["Bull (wild ox)"]["THAC0"] = "17";
statblock_mammher2["Bull (wild ox)"]["No. of Attacks"] = "2";
statblock_mammher2["Bull (wild ox)"]["Damage/Attack"] = "1d6/1d6";
statblock_mammher2["Bull (wild ox)"]["Morale"] = "Average (8-10)";
statblock_mammher2["Bull (wild ox)"]["Special Attacks"] = "Charge";
statblock_mammher2["Bull (wild ox)"]["XP Value"] = "175";
statblock_mammher2["Caribou"]["No. Appearing"] = "2-16";
statblock_mammher2["Caribou"]["Armor Class"] = "7";
statblock_mammher2["Caribou"]["Movement"] = "21";
statblock_mammher2["Caribou"]["Hit Dice"] = "3+2";
statblock_mammher2["Caribou"]["THAC0"] = "17";
statblock_mammher2["Caribou"]["No. of Attacks"] = "1";
statblock_mammher2["Caribou"]["Damage/Attack"] = "2d6 (1d3/1d3)";
statblock_mammher2["Caribou"]["Morale"] = "Unsteady (5-7)";
statblock_mammher2["Caribou"]["Special Attacks"] = "Nil";
statblock_mammher2["Caribou"]["XP Value"] = "120";
statblock_mammher2["Goat, giant"]["No. Appearing"] = "1-12";
statblock_mammher2["Goat, giant"]["Armor Class"] = "7";
statblock_mammher2["Goat, giant"]["Movement"] = "18";
statblock_mammher2["Goat, giant"]["Hit Dice"] = "3+1";
statblock_mammher2["Goat, giant"]["THAC0"] = "17";
statblock_mammher2["Goat, giant"]["No. of Attacks"] = "1";
statblock_mammher2["Goat, giant"]["Damage/Attack"] = "2d8";
statblock_mammher2["Goat, giant"]["Morale"] = "Unsteady (5-7)";
statblock_mammher2["Goat, giant"]["Special Attacks"] = "Charge";
statblock_mammher2["Goat, giant"]["XP Value"] = "175";
statblock_mammher2["Hippopotamus"]["No. Appearing"] = "2-12";
statblock_mammher2["Hippopotamus"]["Armor Class"] = "6";
statblock_mammher2["Hippopotamus"]["Movement"] = "9/12";
statblock_mammher2["Hippopotamus"]["Hit Dice"] = "8";
statblock_mammher2["Hippopotamus"]["THAC0"] = "12";
statblock_mammher2["Hippopotamus"]["No. of Attacks"] = "1";
statblock_mammher2["Hippopotamus"]["Damage/Attack"] = "2d6 or 3d6";
statblock_mammher2["Hippopotamus"]["Morale"] = "Average (8-10)";
statblock_mammher2["Hippopotamus"]["Special Attacks"] = "Special";
statblock_mammher2["Hippopotamus"]["XP Value"] = "975";
statblock_mammher2["Llama"]["No. Appearing"] = "1-12";
statblock_mammher2["Llama"]["Armor Class"] = "7";
statblock_mammher2["Llama"]["Movement"] = "15";
statblock_mammher2["Llama"]["Hit Dice"] = "2";
statblock_mammher2["Llama"]["THAC0"] = "19";
statblock_mammher2["Llama"]["No. of Attacks"] = "1";
statblock_mammher2["Llama"]["Damage/Attack"] = "1d3";
statblock_mammher2["Llama"]["Morale"] = "Unreliable (2-4)";
statblock_mammher2["Llama"]["Special Attacks"] = "Spit";
statblock_mammher2["Llama"]["XP Value"] = "65";
statblock_mammher2["Ram, giant"]["No. Appearing"] = "2-8";
statblock_mammher2["Ram, giant"]["Armor Class"] = "6";
statblock_mammher2["Ram, giant"]["Movement"] = "15";
statblock_mammher2["Ram, giant"]["Hit Dice"] = "4";
statblock_mammher2["Ram, giant"]["THAC0"] = "17";
statblock_mammher2["Ram, giant"]["No. of Attacks"] = "1";
statblock_mammher2["Ram, giant"]["Damage/Attack"] = "2d6";
statblock_mammher2["Ram, giant"]["Morale"] = "Average (8-10)";
statblock_mammher2["Ram, giant"]["Special Attacks"] = "Charge";
statblock_mammher2["Ram, giant"]["XP Value"] = "175";
statblock_mammher2["Rhinoceros, 1-horn"]["No. Appearing"] = "1-6";
statblock_mammher2["Rhinoceros, 1-horn"]["Armor Class"] = "6";
statblock_mammher2["Rhinoceros, 1-horn"]["Movement"] = "12";
statblock_mammher2["Rhinoceros, 1-horn"]["Hit Dice"] = "8";
statblock_mammher2["Rhinoceros, 1-horn"]["THAC0"] = "13";
statblock_mammher2["Rhinoceros, 1-horn"]["No. of Attacks"] = "1";
statblock_mammher2["Rhinoceros, 1-horn"]["Damage/Attack"] = "2d4";
statblock_mammher2["Rhinoceros, 1-horn"]["Morale"] = "Unsteady (5-7)";
statblock_mammher2["Rhinoceros, 1-horn"]["Special Attacks"] = "Charge";
statblock_mammher2["Rhinoceros, 1-horn"]["XP Value"] = "975";
statblock_mammher2["Rinoceros, 2-horn"]["No. Appearing"] = "1-6";
statblock_mammher2["Rinoceros, 2-horn"]["Armor Class"] = "6";
statblock_mammher2["Rinoceros, 2-horn"]["Movement"] = "12";
statblock_mammher2["Rinoceros, 2-horn"]["Hit Dice"] = "9";
statblock_mammher2["Rinoceros, 2-horn"]["THAC0"] = "11";
statblock_mammher2["Rinoceros, 2-horn"]["No. of Attacks"] = "1";
statblock_mammher2["Rinoceros, 2-horn"]["Damage/Attack"] = "2d6";
statblock_mammher2["Rinoceros, 2-horn"]["Morale"] = "Unsteady (5-7)";
statblock_mammher2["Rinoceros, 2-horn"]["Special Attacks"] = "Charge";
statblock_mammher2["Rinoceros, 2-horn"]["XP Value"] = "1,400";
statblock_mammher2["Stag, wild"]["No. Appearing"] = "1-4";
statblock_mammher2["Stag, wild"]["Armor Class"] = "7";
statblock_mammher2["Stag, wild"]["Movement"] = "24";
statblock_mammher2["Stag, wild"]["Hit Dice"] = "3";
statblock_mammher2["Stag, wild"]["THAC0"] = "17";
statblock_mammher2["Stag, wild"]["No. of Attacks"] = "1 (2)";
statblock_mammher2["Stag, wild"]["Damage/Attack"] = "2d4 (1d3/1d3)";
statblock_mammher2["Stag, wild"]["Morale"] = "Unsteady (5-7)";
statblock_mammher2["Stag, wild"]["Special Attacks"] = "Nil";
statblock_mammher2["Stag, wild"]["XP Value"] = "65";



/////////////////////////////////////////////////////////////
// mammmini

// Might calculate the "as animal" stats because it 
// would be pretty cool to have all of those stats
// in the database. 

/*
statblock_mammmini[""][Frequency:"] = "Very Rare"
statblock_mammmini[""][Alignment:"] = "Neutral (chaotic)"
statblock_mammmini[""][No. Appearing:"] = "As full size but 50% likely for twice the number rolled"
statblock_mammmini[""][Armor Class:"] = "As full size +2 (worse)"
statblock_mammmini[""][Movement:"] = "⅔ of full size"
statblock_mammmini[""][No. of Attacks:"] = "As full size or fewer (see below)"
statblock_mammmini[""][Special Attacks:"] = "+1 to surprise for carnivores"
statblock_mammmini[""][Special Defenses:"] = "-1 to attacker's surprise"
statblock_mammmini[""][Magic Resistance:"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death"
statblock_mammmini[""][Morale:"] = "Unreliable to Average (2-10)"
*/

// Ape, Gorilla
// Ape, Carnivorous
// Baboon
// Badger
// Bear, Black
// Bear, Brown
// Bear, Cave
// Boar, Wild
// Boar, Warthog
// Buffalo
// Bull
// Camel, Wild
// Dog, War
// Dog, Wild
// Elephant, African
// Elephant, Asian
// Hippopotamus
// Horse, Wild
// Hyena
// Jaguar
// Leopard
// Lion
// Lion, Mountain
// Lynx
// Mammoth
// Rhinoceros
// Stag
// Tiger
// Wolf

statblock_mammmini["Ape, Gorilla"]["Hit Dice"] = "1";
statblock_mammmini["Ape, Gorilla"]["THAC0"] = "19";
statblock_mammmini["Ape, Gorilla"]["No. of Attacks"] = "3";
statblock_mammmini["Ape, Gorilla"]["Damage/Attack"] = "1/1/1-2";
statblock_mammmini["Ape, Gorilla"]["XP Value"] = "15";
statblock_mammmini["Ape, Gorilla"]["Special Attacks"] = "No rending";
statblock_mammmini["Ape, Gorilla"]["Frequency"] = "Very Rare";
statblock_mammmini["Ape, Gorilla"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Ape, Gorilla"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Ape, Gorilla"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Ape, Gorilla"]["Movement"] = "⅔ of full size";
statblock_mammmini["Ape, Gorilla"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Ape, Gorilla"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Ape, Gorilla"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Ape, Gorilla"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Ape, Gorilla"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Ape, Carnivorous"]["Hit Dice"] = "1+2";
statblock_mammmini["Ape, Carnivorous"]["THAC0"] = "18";
statblock_mammmini["Ape, Carnivorous"]["No. of Attacks"] = "3";
statblock_mammmini["Ape, Carnivorous"]["Damage/Attack"] = "1/1/1-3";
statblock_mammmini["Ape, Carnivorous"]["XP Value"] = "35";
statblock_mammmini["Ape, Carnivorous"]["Special Attacks"] = "Rending for 1-2";
statblock_mammmini["Ape, Carnivorous"]["Frequency"] = "Very Rare";
statblock_mammmini["Ape, Carnivorous"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Ape, Carnivorous"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Ape, Carnivorous"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Ape, Carnivorous"]["Movement"] = "⅔ of full size";
statblock_mammmini["Ape, Carnivorous"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Ape, Carnivorous"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Ape, Carnivorous"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Ape, Carnivorous"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Ape, Carnivorous"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Baboon"]["Hit Dice"] = "¼";
statblock_mammmini["Baboon"]["THAC0"] = "20";
statblock_mammmini["Baboon"]["No. of Attacks"] = "1";
statblock_mammmini["Baboon"]["Damage/Attack"] = "1";
statblock_mammmini["Baboon"]["XP Value"] = "7";
statblock_mammmini["Baboon"]["Special Attacks"] = "-";
statblock_mammmini["Baboon"]["Frequency"] = "Very Rare";
statblock_mammmini["Baboon"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Baboon"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Baboon"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Baboon"]["Movement"] = "⅔ of full size";
statblock_mammmini["Baboon"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Baboon"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Baboon"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Baboon"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Baboon"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Badger"]["Hit Dice"] = "¼+1";
statblock_mammmini["Badger"]["THAC0"] = "20";
statblock_mammmini["Badger"]["No. of Attacks"] = "1";
statblock_mammmini["Badger"]["Damage/Attack"] = "1-2";
statblock_mammmini["Badger"]["XP Value"] = "7";
statblock_mammmini["Badger"]["Special Attacks"] = "-";
statblock_mammmini["Badger"]["Frequency"] = "Very Rare";
statblock_mammmini["Badger"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Badger"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Badger"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Badger"]["Movement"] = "⅔ of full size";
statblock_mammmini["Badger"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Badger"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Badger"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Badger"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Badger"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Bear, Black"]["Hit Dice"] = "1-1";
statblock_mammmini["Bear, Black"]["THAC0"] = "20";
statblock_mammmini["Bear, Black"]["No. of Attacks"] = "3";
statblock_mammmini["Bear, Black"]["Damage/Attack"] = "1/1/1-2";
statblock_mammmini["Bear, Black"]["XP Value"] = "15";
statblock_mammmini["Bear, Black"]["Special Attacks"] = "No hug";
statblock_mammmini["Bear, Black"]["Frequency"] = "Very Rare";
statblock_mammmini["Bear, Black"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Bear, Black"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Bear, Black"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Bear, Black"]["Movement"] = "⅔ of full size";
statblock_mammmini["Bear, Black"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Bear, Black"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Bear, Black"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Bear, Black"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Bear, Black"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Bear, Brown"]["Hit Dice"] = "1+3";
statblock_mammmini["Bear, Brown"]["THAC0"] = "18";
statblock_mammmini["Bear, Brown"]["No. of Attacks"] = "3";
statblock_mammmini["Bear, Brown"]["Damage/Attack"] = "1-2/1-2/1-2";
statblock_mammmini["Bear, Brown"]["XP Value"] = "35";
statblock_mammmini["Bear, Brown"]["Special Attacks"] = "Hug 1-3";
statblock_mammmini["Bear, Brown"]["Frequency"] = "Very Rare";
statblock_mammmini["Bear, Brown"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Bear, Brown"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Bear, Brown"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Bear, Brown"]["Movement"] = "⅔ of full size";
statblock_mammmini["Bear, Brown"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Bear, Brown"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Bear, Brown"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Bear, Brown"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Bear, Brown"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Bear, Cave"]["Hit Dice"] = "2+2";
statblock_mammmini["Bear, Cave"]["THAC0"] = "16";
statblock_mammmini["Bear, Cave"]["No. of Attacks"] = "3";
statblock_mammmini["Bear, Cave"]["Damage/Attack"] = "1-2/1-2/1-3";
statblock_mammmini["Bear, Cave"]["XP Value"] = "65";
statblock_mammmini["Bear, Cave"]["Special Attacks"] = "Hug 2-5";
statblock_mammmini["Bear, Cave"]["Frequency"] = "Very Rare";
statblock_mammmini["Bear, Cave"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Bear, Cave"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Bear, Cave"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Bear, Cave"]["Movement"] = "⅔ of full size";
statblock_mammmini["Bear, Cave"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Bear, Cave"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Bear, Cave"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Bear, Cave"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Bear, Cave"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Boar, Wild"]["Hit Dice"] = "1-1";
statblock_mammmini["Boar, Wild"]["THAC0"] = "20";
statblock_mammmini["Boar, Wild"]["No. of Attacks"] = "1";
statblock_mammmini["Boar, Wild"]["Damage/Attack"] = "1-4";
statblock_mammmini["Boar, Wild"]["XP Value"] = "15";
statblock_mammmini["Boar, Wild"]["Special Attacks"] = "-";
statblock_mammmini["Boar, Wild"]["Frequency"] = "Very Rare";
statblock_mammmini["Boar, Wild"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Boar, Wild"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Boar, Wild"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Boar, Wild"]["Movement"] = "⅔ of full size";
statblock_mammmini["Boar, Wild"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Boar, Wild"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Boar, Wild"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Boar, Wild"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Boar, Wild"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Boar, Warthog"]["Hit Dice"] = "1-1";
statblock_mammmini["Boar, Warthog"]["THAC0"] = "20";
statblock_mammmini["Boar, Warthog"]["No. of Attacks"] = "2";
statblock_mammmini["Boar, Warthog"]["Damage/Attack"] = "1-2/1-2";
statblock_mammmini["Boar, Warthog"]["XP Value"] = "15";
statblock_mammmini["Boar, Warthog"]["Special Attacks"] = "-";
statblock_mammmini["Boar, Warthog"]["Frequency"] = "Very Rare";
statblock_mammmini["Boar, Warthog"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Boar, Warthog"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Boar, Warthog"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Boar, Warthog"]["Movement"] = "⅔ of full size";
statblock_mammmini["Boar, Warthog"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Boar, Warthog"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Boar, Warthog"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Boar, Warthog"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Boar, Warthog"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Buffalo"]["Hit Dice"] = "1+2";
statblock_mammmini["Buffalo"]["THAC0"] = "18";
statblock_mammmini["Buffalo"]["No. of Attacks"] = "2";
statblock_mammmini["Buffalo"]["Damage/Attack"] = "1-2/1-2";
statblock_mammmini["Buffalo"]["XP Value"] = "35";
statblock_mammmini["Buffalo"]["Special Attacks"] = "-";
statblock_mammmini["Buffalo"]["Frequency"] = "Very Rare";
statblock_mammmini["Buffalo"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Buffalo"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Buffalo"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Buffalo"]["Movement"] = "⅔ of full size";
statblock_mammmini["Buffalo"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Buffalo"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Buffalo"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Buffalo"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Buffalo"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Bull"]["Hit Dice"] = "1";
statblock_mammmini["Bull"]["THAC0"] = "19";
statblock_mammmini["Bull"]["No. of Attacks"] = "2";
statblock_mammmini["Bull"]["Damage/Attack"] = "1-2/1-2";
statblock_mammmini["Bull"]["XP Value"] = "15";
statblock_mammmini["Bull"]["Special Attacks"] = "-";
statblock_mammmini["Bull"]["Frequency"] = "Very Rare";
statblock_mammmini["Bull"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Bull"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Bull"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Bull"]["Movement"] = "⅔ of full size";
statblock_mammmini["Bull"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Bull"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Bull"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Bull"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Bull"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Camel, Wild"]["Hit Dice"] = "1-1";
statblock_mammmini["Camel, Wild"]["THAC0"] = "20";
statblock_mammmini["Camel, Wild"]["No. of Attacks"] = "1";
statblock_mammmini["Camel, Wild"]["Damage/Attack"] = "1";
statblock_mammmini["Camel, Wild"]["XP Value"] = "15";
statblock_mammmini["Camel, Wild"]["Special Attacks"] = "-";
statblock_mammmini["Camel, Wild"]["Frequency"] = "Very Rare";
statblock_mammmini["Camel, Wild"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Camel, Wild"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Camel, Wild"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Camel, Wild"]["Movement"] = "⅔ of full size";
statblock_mammmini["Camel, Wild"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Camel, Wild"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Camel, Wild"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Camel, Wild"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Camel, Wild"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Dog, War"]["Hit Dice"] = "½+1";
statblock_mammmini["Dog, War"]["THAC0"] = "20";
statblock_mammmini["Dog, War"]["No. of Attacks"] = "1";
statblock_mammmini["Dog, War"]["Damage/Attack"] = "1-2";
statblock_mammmini["Dog, War"]["XP Value"] = "7";
statblock_mammmini["Dog, War"]["Special Attacks"] = "-";
statblock_mammmini["Dog, War"]["Frequency"] = "Very Rare";
statblock_mammmini["Dog, War"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Dog, War"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Dog, War"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Dog, War"]["Movement"] = "⅔ of full size";
statblock_mammmini["Dog, War"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Dog, War"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Dog, War"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Dog, War"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Dog, War"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Dog, Wild"]["Hit Dice"] = "¼";
statblock_mammmini["Dog, Wild"]["THAC0"] = "20";
statblock_mammmini["Dog, Wild"]["No. of Attacks"] = "1";
statblock_mammmini["Dog, Wild"]["Damage/Attack"] = "1";
statblock_mammmini["Dog, Wild"]["XP Value"] = "7";
statblock_mammmini["Dog, Wild"]["Special Attacks"] = "-";
statblock_mammmini["Dog, Wild"]["Frequency"] = "Very Rare";
statblock_mammmini["Dog, Wild"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Dog, Wild"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Dog, Wild"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Dog, Wild"]["Movement"] = "⅔ of full size";
statblock_mammmini["Dog, Wild"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Dog, Wild"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Dog, Wild"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Dog, Wild"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Dog, Wild"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Elephant, African"]["Hit Dice"] = "2+4";
statblock_mammmini["Elephant, African"]["THAC0"] = "16";
statblock_mammmini["Elephant, African"]["No. of Attacks"] = "5";
statblock_mammmini["Elephant, African"]["Damage/Attack"] = "1-4/1-4/1-3/1-2/1-2";
statblock_mammmini["Elephant, African"]["XP Value"] = "65";
statblock_mammmini["Elephant, African"]["Special Attacks"] = "-";
statblock_mammmini["Elephant, African"]["Frequency"] = "Very Rare";
statblock_mammmini["Elephant, African"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Elephant, African"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Elephant, African"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Elephant, African"]["Movement"] = "⅔ of full size";
statblock_mammmini["Elephant, African"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Elephant, African"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Elephant, African"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Elephant, African"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Elephant, African"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Elephant, Asian"]["Hit Dice"] = "2+6";
statblock_mammmini["Elephant, Asian"]["THAC0"] = "16";
statblock_mammmini["Elephant, Asian"]["No. of Attacks"] = "5";
statblock_mammmini["Elephant, Asian"]["Damage/Attack"] = "2-5/2-5/1-4/1-3/1-3";
statblock_mammmini["Elephant, Asian"]["XP Value"] = "65";
statblock_mammmini["Elephant, Asian"]["Special Attacks"] = "-";
statblock_mammmini["Elephant, Asian"]["Frequency"] = "Very Rare";
statblock_mammmini["Elephant, Asian"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Elephant, Asian"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Elephant, Asian"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Elephant, Asian"]["Movement"] = "⅔ of full size";
statblock_mammmini["Elephant, Asian"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Elephant, Asian"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Elephant, Asian"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Elephant, Asian"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Elephant, Asian"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Hippopotamus"]["Hit Dice"] = "1+2";
statblock_mammmini["Hippopotamus"]["THAC0"] = "18";
statblock_mammmini["Hippopotamus"]["No. of Attacks"] = "1";
statblock_mammmini["Hippopotamus"]["Damage/Attack"] = "1-4 or 3-6";
statblock_mammmini["Hippopotamus"]["XP Value"] = "35";
statblock_mammmini["Hippopotamus"]["Special Attacks"] = "-";
statblock_mammmini["Hippopotamus"]["Frequency"] = "Very Rare";
statblock_mammmini["Hippopotamus"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Hippopotamus"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Hippopotamus"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Hippopotamus"]["Movement"] = "⅔ of full size";
statblock_mammmini["Hippopotamus"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Hippopotamus"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Hippopotamus"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Hippopotamus"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Hippopotamus"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Horse, Wild"]["Hit Dice"] = "½+1";
statblock_mammmini["Horse, Wild"]["THAC0"] = "20";
statblock_mammmini["Horse, Wild"]["No. of Attacks"] = "1";
statblock_mammmini["Horse, Wild"]["Damage/Attack"] = "1";
statblock_mammmini["Horse, Wild"]["XP Value"] = "7";
statblock_mammmini["Horse, Wild"]["Special Attacks"] = "-";
statblock_mammmini["Horse, Wild"]["Frequency"] = "Very Rare";
statblock_mammmini["Horse, Wild"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Horse, Wild"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Horse, Wild"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Horse, Wild"]["Movement"] = "⅔ of full size";
statblock_mammmini["Horse, Wild"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Horse, Wild"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Horse, Wild"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Horse, Wild"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Horse, Wild"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Hyena"]["Hit Dice"] = "1-1";
statblock_mammmini["Hyena"]["THAC0"] = "20";
statblock_mammmini["Hyena"]["No. of Attacks"] = "1";
statblock_mammmini["Hyena"]["Damage/Attack"] = "1-2";
statblock_mammmini["Hyena"]["XP Value"] = "15";
statblock_mammmini["Hyena"]["Special Attacks"] = "-";
statblock_mammmini["Hyena"]["Frequency"] = "Very Rare";
statblock_mammmini["Hyena"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Hyena"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Hyena"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Hyena"]["Movement"] = "⅔ of full size";
statblock_mammmini["Hyena"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Hyena"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Hyena"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Hyena"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Hyena"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Jaguar"]["Hit Dice"] = "1";
statblock_mammmini["Jaguar"]["THAC0"] = "19";
statblock_mammmini["Jaguar"]["No. of Attacks"] = "3";
statblock_mammmini["Jaguar"]["Damage/Attack"] = "1/1/1-2";
statblock_mammmini["Jaguar"]["XP Value"] = "15";
statblock_mammmini["Jaguar"]["Special Attacks"] = "Surprised only on 1; rear claws 1/1";
statblock_mammmini["Jaguar"]["Frequency"] = "Very Rare";
statblock_mammmini["Jaguar"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Jaguar"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Jaguar"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Jaguar"]["Movement"] = "⅔ of full size";
statblock_mammmini["Jaguar"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Jaguar"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Jaguar"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Jaguar"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Jaguar"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Leopard"]["Hit Dice"] = "1";
statblock_mammmini["Leopard"]["THAC0"] = "19";
statblock_mammmini["Leopard"]["No. of Attacks"] = "3";
statblock_mammmini["Leopard"]["Damage/Attack"] = "1/1/1-2";
statblock_mammmini["Leopard"]["XP Value"] = "15";
statblock_mammmini["Leopard"]["Special Attacks"] = "Surprised only on 1; rear claws 1/1";
statblock_mammmini["Leopard"]["Frequency"] = "Very Rare";
statblock_mammmini["Leopard"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Leopard"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Leopard"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Leopard"]["Movement"] = "⅔ of full size";
statblock_mammmini["Leopard"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Leopard"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Leopard"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Leopard"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Leopard"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Lion"]["Hit Dice"] = "1+3";
statblock_mammmini["Lion"]["THAC0"] = "18";
statblock_mammmini["Lion"]["No. of Attacks"] = "3";
statblock_mammmini["Lion"]["Damage/Attack"] = "1/1/1-3";
statblock_mammmini["Lion"]["XP Value"] = "35";
statblock_mammmini["Lion"]["Special Attacks"] = "Surprised only on 1; rear claws 1/1";
statblock_mammmini["Lion"]["Frequency"] = "Very Rare";
statblock_mammmini["Lion"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Lion"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Lion"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Lion"]["Movement"] = "⅔ of full size";
statblock_mammmini["Lion"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Lion"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Lion"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Lion"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Lion"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Lion, Mountain"]["Hit Dice"] = "1-1";
statblock_mammmini["Lion, Mountain"]["THAC0"] = "20";
statblock_mammmini["Lion, Mountain"]["No. of Attacks"] = "3";
statblock_mammmini["Lion, Mountain"]["Damage/Attack"] = "1/1/1-2";
statblock_mammmini["Lion, Mountain"]["XP Value"] = "15";
statblock_mammmini["Lion, Mountain"]["Special Attacks"] = "Surprised only on 1; rear claws 1/1";
statblock_mammmini["Lion, Mountain"]["Frequency"] = "Very Rare";
statblock_mammmini["Lion, Mountain"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Lion, Mountain"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Lion, Mountain"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Lion, Mountain"]["Movement"] = "⅔ of full size";
statblock_mammmini["Lion, Mountain"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Lion, Mountain"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Lion, Mountain"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Lion, Mountain"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Lion, Mountain"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Lynx"]["Hit Dice"] = "¼";
statblock_mammmini["Lynx"]["THAC0"] = "20";
statblock_mammmini["Lynx"]["No. of Attacks"] = "1";
statblock_mammmini["Lynx"]["Damage/Attack"] = "1";
statblock_mammmini["Lynx"]["XP Value"] = "7";
statblock_mammmini["Lynx"]["Special Attacks"] = "Surprised only on 1";
statblock_mammmini["Lynx"]["Frequency"] = "Very Rare";
statblock_mammmini["Lynx"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Lynx"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Lynx"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Lynx"]["Movement"] = "⅔ of full size";
statblock_mammmini["Lynx"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Lynx"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Lynx"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Lynx"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Lynx"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Mammoth"]["Hit Dice"] = "3+4";
statblock_mammmini["Mammoth"]["THAC0"] = "16";
statblock_mammmini["Mammoth"]["No. of Attacks"] = "5";
statblock_mammmini["Mammoth"]["Damage/Attack"] = "3-6/3-6/2-5/1-3/1-3";
statblock_mammmini["Mammoth"]["XP Value"] = "120";
statblock_mammmini["Mammoth"]["Special Attacks"] = "-";
statblock_mammmini["Mammoth"]["Frequency"] = "Very Rare";
statblock_mammmini["Mammoth"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Mammoth"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Mammoth"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Mammoth"]["Movement"] = "⅔ of full size";
statblock_mammmini["Mammoth"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Mammoth"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Mammoth"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Mammoth"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Mammoth"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Rhinoceros"]["Hit Dice"] = "2+1";
statblock_mammmini["Rhinoceros"]["THAC0"] = "16";
statblock_mammmini["Rhinoceros"]["No. of Attacks"] = "1";
statblock_mammmini["Rhinoceros"]["Damage/Attack"] = "1-2 or 1-4";
statblock_mammmini["Rhinoceros"]["XP Value"] = "65";
statblock_mammmini["Rhinoceros"]["Special Attacks"] = "Charge 2-4 or 2-8";
statblock_mammmini["Rhinoceros"]["Frequency"] = "Very Rare";
statblock_mammmini["Rhinoceros"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Rhinoceros"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Rhinoceros"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Rhinoceros"]["Movement"] = "⅔ of full size";
statblock_mammmini["Rhinoceros"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Rhinoceros"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Rhinoceros"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Rhinoceros"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Rhinoceros"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Stag"]["Hit Dice"] = "1-1";
statblock_mammmini["Stag"]["THAC0"] = "20";
statblock_mammmini["Stag"]["No. of Attacks"] = "1 or 2";
statblock_mammmini["Stag"]["Damage/Attack"] = "1-2 or 1/1";
statblock_mammmini["Stag"]["XP Value"] = "15";
statblock_mammmini["Stag"]["Special Attacks"] = "-";
statblock_mammmini["Stag"]["Frequency"] = "Very Rare";
statblock_mammmini["Stag"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Stag"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Stag"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Stag"]["Movement"] = "⅔ of full size";
statblock_mammmini["Stag"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Stag"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Stag"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Stag"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Stag"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Tiger"]["Hit Dice"] = "2+1";
statblock_mammmini["Tiger"]["THAC0"] = "16";
statblock_mammmini["Tiger"]["No. of Attacks"] = "3";
statblock_mammmini["Tiger"]["Damage/Attack"] = "1-2/1-2/1-3";
statblock_mammmini["Tiger"]["XP Value"] = "65";
statblock_mammmini["Tiger"]["Special Attacks"] = "Surprised only on 1; rear claws 1-2/1-2";
statblock_mammmini["Tiger"]["Frequency"] = "Very Rare";
statblock_mammmini["Tiger"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Tiger"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Tiger"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Tiger"]["Movement"] = "⅔ of full size";
statblock_mammmini["Tiger"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Tiger"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Tiger"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Tiger"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Tiger"]["Morale"] = "Unreliable to Average (2-10)";
statblock_mammmini["Wolf"]["Hit Dice"] = "½";
statblock_mammmini["Wolf"]["THAC0"] = "20";
statblock_mammmini["Wolf"]["No. of Attacks"] = "1";
statblock_mammmini["Wolf"]["Damage/Attack"] = "1-2";
statblock_mammmini["Wolf"]["XP Value"] = "7";
statblock_mammmini["Wolf"]["Special Attacks"] = "-";
statblock_mammmini["Wolf"]["Frequency"] = "Very Rare";
statblock_mammmini["Wolf"]["Alignment"] = "Neutral (chaotic)";
statblock_mammmini["Wolf"]["No. Appearing"] = "As full size but 50% likely for twice the number rolled";
statblock_mammmini["Wolf"]["Armor Class"] = "As full size +2 (worse)";
statblock_mammmini["Wolf"]["Movement"] = "⅔ of full size";
statblock_mammmini["Wolf"]["No. of Attacks"] = "As full size or fewer (see below)";
statblock_mammmini["Wolf"]["Special Attacks"] = "+1 to surprise for carnivores";
statblock_mammmini["Wolf"]["Special Defenses"] = "-1 to attacker's surprise";
statblock_mammmini["Wolf"]["Magic Resistance"] = "+2 to most saves; +4 vs. charm effects; no bonus vs. poison, death";
statblock_mammmini["Wolf"]["Morale"] = "Unreliable to Average (2-10)";




/////////////////////////////////////////////////////////////
// mammsmal

/*
Some fields that are not described by the monster page:
Activity Cycle
*/

// Beaver
// Chipmunk
// Ermine
// Ferret
// Fox
// Gopher
// Hedgehog
// Mink
// Mole
// Monkey
// Mouse
// Muskrat
// Opossum
// Otter
// Otter, Sea
// Otter, Giant
// Pig, Domestic
// Pig, Wild
// Rabbit
// Raccoon
// Squirrel
// Squirrel, Flying
// Squirrel, Giant black
// Woodchuck

// statblock_mammsmal[""]["Climate/Terrain"]   = "Varies";
// statblock_mammsmal[""]["Frequency"]         = "Common";
// statblock_mammsmal[""]["Organization"]      = "";*
// statblock_mammsmal[""]["Activity Cycle"]    = "";*
// statblock_mammsmal[""]["Diet"]              = "";*
// statblock_mammsmal[""]["Intelligence"]      = "Animal (1)";
// statblock_mammsmal[""]["Treasure"]          = "";*
// statblock_mammsmal[""]["Alignment"]         = "";*
// statblock_mammsmal[""]["No. Appearing"]     = "";-
// statblock_mammsmal[""]["Armor Class"]       = "";-
// statblock_mammsmal[""]["Movement"]          = "";-
// statblock_mammsmal[""]["Hit Dice"]          = "";-
// statblock_mammsmal[""]["THAC0"]             = "20";
// statblock_mammsmal[""]["No. of Attacks"]    = "";-
// statblock_mammsmal[""]["Damage/Attack"]     = "";-
// statblock_mammsmal[""]["Special Attacks"]   = "";*
// statblock_mammsmal[""]["Special Defenses"]  = "";*
// statblock_mammsmal[""]["Magic Resistance"]  = "Nil";
// statblock_mammsmal[""]["Size"]              = "";*
// statblock_mammsmal[""]["Morale"]            = "Unreliable to Average (2-9)";
// statblock_mammsmal[""]["XP Value"]          = "";-

/*
 Missing
Organization
Activity Cycle
Diet
Treasure
Special Attacks
Special Defenses
Size
*/



statblock_mammsmal["Beaver"]["Hit Dice"] = "1-4 hp";
statblock_mammsmal["Beaver"]["Armor Class "] = "9";
statblock_mammsmal["Beaver"]["No. Appearing"] = "10-40";
statblock_mammsmal["Beaver"]["No. of Attacks"] = "1";
statblock_mammsmal["Beaver"]["Damage/Attack"] = "1";
statblock_mammsmal["Beaver"]["Movement"] = "4, Sw 12";
statblock_mammsmal["Beaver"]["XP Value"] = "7";
statblock_mammsmal["Beaver"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Beaver"]["Frequency"] = "Common";
statblock_mammsmal["Beaver"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Beaver"]["THAC0"] = "20";
statblock_mammsmal["Beaver"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Beaver"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Beaver"]["Alignment"] = "Neutral";
statblock_mammsmal["Chipmunk"]["Hit Dice"] = "1 hp";
statblock_mammsmal["Chipmunk"]["Armor Class "] = "7";
statblock_mammsmal["Chipmunk"]["No. Appearing"] = "1-6";
statblock_mammsmal["Chipmunk"]["No. of Attacks"] = "1";
statblock_mammsmal["Chipmunk"]["Damage/Attack"] = "1";
statblock_mammsmal["Chipmunk"]["Movement"] = "12, Br 1";
statblock_mammsmal["Chipmunk"]["XP Value"] = "0";
statblock_mammsmal["Chipmunk"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Chipmunk"]["Frequency"] = "Common";
statblock_mammsmal["Chipmunk"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Chipmunk"]["THAC0"] = "20";
statblock_mammsmal["Chipmunk"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Chipmunk"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Chipmunk"]["Alignment"] = "Neutral";
statblock_mammsmal["Ermine"]["Hit Dice"] = "1";
statblock_mammsmal["Ermine"]["Armor Class "] = "6";
statblock_mammsmal["Ermine"]["No. Appearing"] = "1-2";
statblock_mammsmal["Ermine"]["No. of Attacks"] = "1";
statblock_mammsmal["Ermine"]["Damage/Attack"] = "1";
statblock_mammsmal["Ermine"]["Movement"] = "15";
statblock_mammsmal["Ermine"]["XP Value"] = "15";
statblock_mammsmal["Ermine"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Ermine"]["Frequency"] = "Common";
statblock_mammsmal["Ermine"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Ermine"]["THAC0"] = "20";
statblock_mammsmal["Ermine"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Ermine"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Ermine"]["Alignment"] = "Neutral";
statblock_mammsmal["Ferret"]["Hit Dice"] = "1";
statblock_mammsmal["Ferret"]["Armor Class "] = "6";
statblock_mammsmal["Ferret"]["No. Appearing"] = "1-2";
statblock_mammsmal["Ferret"]["No. of Attacks"] = "1";
statblock_mammsmal["Ferret"]["Damage/Attack"] = "1";
statblock_mammsmal["Ferret"]["Movement"] = "15";
statblock_mammsmal["Ferret"]["XP Value"] = "15";
statblock_mammsmal["Ferret"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Ferret"]["Frequency"] = "Common";
statblock_mammsmal["Ferret"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Ferret"]["THAC0"] = "20";
statblock_mammsmal["Ferret"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Ferret"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Ferret"]["Alignment"] = "Neutral";
statblock_mammsmal["Fox"]["Hit Dice"] = "1";
statblock_mammsmal["Fox"]["Armor Class "] = "7";
statblock_mammsmal["Fox"]["No. Appearing"] = "1-2";
statblock_mammsmal["Fox"]["No. of Attacks"] = "1";
statblock_mammsmal["Fox"]["Damage/Attack"] = "1-3";
statblock_mammsmal["Fox"]["Movement"] = "15";
statblock_mammsmal["Fox"]["XP Value"] = "15";
statblock_mammsmal["Fox"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Fox"]["Frequency"] = "Common";
statblock_mammsmal["Fox"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Fox"]["THAC0"] = "20";
statblock_mammsmal["Fox"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Fox"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Fox"]["Alignment"] = "Neutral";
statblock_mammsmal["Gopher"]["Hit Dice"] = "1-3 hp";
statblock_mammsmal["Gopher"]["Armor Class "] = "8";
statblock_mammsmal["Gopher"]["No. Appearing"] = "1-20";
statblock_mammsmal["Gopher"]["No. of Attacks"] = "1";
statblock_mammsmal["Gopher"]["Damage/Attack"] = "1";
statblock_mammsmal["Gopher"]["Movement"] = "12, Br 2";
statblock_mammsmal["Gopher"]["XP Value"] = "27";
statblock_mammsmal["Gopher"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Gopher"]["Frequency"] = "Common";
statblock_mammsmal["Gopher"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Gopher"]["THAC0"] = "20";
statblock_mammsmal["Gopher"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Gopher"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Gopher"]["Alignment"] = "Neutral";
statblock_mammsmal["Hedgehog"]["Hit Dice"] = "1-2 hp";
statblock_mammsmal["Hedgehog"]["Armor Class "] = "8";
statblock_mammsmal["Hedgehog"]["No. Appearing"] = "1-2";
statblock_mammsmal["Hedgehog"]["No. of Attacks"] = "nil";
statblock_mammsmal["Hedgehog"]["Damage/Attack"] = "nil";
statblock_mammsmal["Hedgehog"]["Movement"] = "4";
statblock_mammsmal["Hedgehog"]["XP Value"] = "7";
statblock_mammsmal["Hedgehog"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Hedgehog"]["Frequency"] = "Common";
statblock_mammsmal["Hedgehog"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Hedgehog"]["THAC0"] = "20";
statblock_mammsmal["Hedgehog"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Hedgehog"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Hedgehog"]["Alignment"] = "Neutral";
statblock_mammsmal["Mink"]["Hit Dice"] = "1";
statblock_mammsmal["Mink"]["Armor Class "] = "6";
statblock_mammsmal["Mink"]["No. Appearing"] = "1-2";
statblock_mammsmal["Mink"]["No. of Attacks"] = "1";
statblock_mammsmal["Mink"]["Damage/Attack"] = "1";
statblock_mammsmal["Mink"]["Movement"] = "15, Br 1";
statblock_mammsmal["Mink"]["XP Value"] = "15";
statblock_mammsmal["Mink"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Mink"]["Frequency"] = "Common";
statblock_mammsmal["Mink"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Mink"]["THAC0"] = "20";
statblock_mammsmal["Mink"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Mink"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Mink"]["Alignment"] = "Neutral";
statblock_mammsmal["Mole"]["Hit Dice"] = "1 hp";
statblock_mammsmal["Mole"]["Armor Class "] = "10";
statblock_mammsmal["Mole"]["No. Appearing"] = "1";
statblock_mammsmal["Mole"]["No. of Attacks"] = "nil";
statblock_mammsmal["Mole"]["Damage/Attack"] = "nil";
statblock_mammsmal["Mole"]["Movement"] = "1, Br ½";
statblock_mammsmal["Mole"]["XP Value"] = "0";
statblock_mammsmal["Mole"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Mole"]["Frequency"] = "Common";
statblock_mammsmal["Mole"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Mole"]["THAC0"] = "20";
statblock_mammsmal["Mole"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Mole"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Mole"]["Alignment"] = "Neutral";
statblock_mammsmal["Monkey"]["Hit Dice"] = "1+1";
statblock_mammsmal["Monkey"]["Armor Class "] = "8";
statblock_mammsmal["Monkey"]["No. Appearing"] = "1-50";
statblock_mammsmal["Monkey"]["No. of Attacks"] = "1";
statblock_mammsmal["Monkey"]["Damage/Attack"] = "1";
statblock_mammsmal["Monkey"]["Movement"] = "9";
statblock_mammsmal["Monkey"]["XP Value"] = "35";
statblock_mammsmal["Monkey"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Monkey"]["Frequency"] = "Common";
statblock_mammsmal["Monkey"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Monkey"]["THAC0"] = "20";
statblock_mammsmal["Monkey"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Monkey"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Monkey"]["Alignment"] = "Neutral";
statblock_mammsmal["Mouse"]["Hit Dice"] = "1 hp";
statblock_mammsmal["Mouse"]["Armor Class "] = "7";
statblock_mammsmal["Mouse"]["No. Appearing"] = "1-100";
statblock_mammsmal["Mouse"]["No. of Attacks"] = "nil";
statblock_mammsmal["Mouse"]["Damage/Attack"] = "nil";
statblock_mammsmal["Mouse"]["Movement"] = "15, Br ½";
statblock_mammsmal["Mouse"]["XP Value"] = "0";
statblock_mammsmal["Mouse"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Mouse"]["Frequency"] = "Common";
statblock_mammsmal["Mouse"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Mouse"]["THAC0"] = "20";
statblock_mammsmal["Mouse"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Mouse"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Mouse"]["Alignment"] = "Neutral";
statblock_mammsmal["Muskrat"]["Hit Dice"] = "1-3 hp";
statblock_mammsmal["Muskrat"]["Armor Class "] = "10";
statblock_mammsmal["Muskrat"]["No. Appearing"] = "1-2";
statblock_mammsmal["Muskrat"]["No. of Attacks"] = "1";
statblock_mammsmal["Muskrat"]["Damage/Attack"] = "1";
statblock_mammsmal["Muskrat"]["Movement"] = "4";
statblock_mammsmal["Muskrat"]["XP Value"] = "7";
statblock_mammsmal["Muskrat"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Muskrat"]["Frequency"] = "Common";
statblock_mammsmal["Muskrat"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Muskrat"]["THAC0"] = "20";
statblock_mammsmal["Muskrat"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Muskrat"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Muskrat"]["Alignment"] = "Neutral";
statblock_mammsmal["Opossum"]["Hit Dice"] = "1-3 hp";
statblock_mammsmal["Opossum"]["Armor Class "] = "10";
statblock_mammsmal["Opossum"]["No. Appearing"] = "1-8";
statblock_mammsmal["Opossum"]["No. of Attacks"] = "1";
statblock_mammsmal["Opossum"]["Damage/Attack"] = "1";
statblock_mammsmal["Opossum"]["Movement"] = "4";
statblock_mammsmal["Opossum"]["XP Value"] = "7";
statblock_mammsmal["Opossum"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Opossum"]["Frequency"] = "Common";
statblock_mammsmal["Opossum"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Opossum"]["THAC0"] = "20";
statblock_mammsmal["Opossum"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Opossum"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Opossum"]["Alignment"] = "Neutral";
statblock_mammsmal["Otter"]["Hit Dice"] = "1-1";
statblock_mammsmal["Otter"]["Armor Class "] = "5";
statblock_mammsmal["Otter"]["No. Appearing"] = "1-4";
statblock_mammsmal["Otter"]["No. of Attacks"] = "1";
statblock_mammsmal["Otter"]["Damage/Attack"] = "1-2";
statblock_mammsmal["Otter"]["Movement"] = "12, Sw 18";
statblock_mammsmal["Otter"]["XP Value"] = "7";
statblock_mammsmal["Otter"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Otter"]["Frequency"] = "Common";
statblock_mammsmal["Otter"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Otter"]["THAC0"] = "20";
statblock_mammsmal["Otter"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Otter"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Otter"]["Alignment"] = "Neutral";
statblock_mammsmal["Otter Sea"]["Hit Dice"] = "1+1";
statblock_mammsmal["Otter Sea"]["Armor Class "] = "5";
statblock_mammsmal["Otter Sea"]["No. Appearing"] = "1-4";
statblock_mammsmal["Otter Sea"]["No. of Attacks"] = "1";
statblock_mammsmal["Otter Sea"]["Damage/Attack"] = "1-3";
statblock_mammsmal["Otter Sea"]["Movement"] = "12, Sw 18";
statblock_mammsmal["Otter Sea"]["XP Value"] = "35";
statblock_mammsmal["Otter Sea"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Otter Sea"]["Frequency"] = "Common";
statblock_mammsmal["Otter Sea"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Otter Sea"]["THAC0"] = "20";
statblock_mammsmal["Otter Sea"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Otter Sea"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Otter Sea"]["Alignment"] = "Neutral";
statblock_mammsmal["Otter, Giant"]["Hit Dice"] = "5";
statblock_mammsmal["Otter, Giant"]["Armor Class "] = "5";
statblock_mammsmal["Otter, Giant"]["No. Appearing"] = "2-5";
statblock_mammsmal["Otter, Giant"]["No. of Attacks"] = "1";
statblock_mammsmal["Otter, Giant"]["Damage/Attack"] = "3-18";
statblock_mammsmal["Otter, Giant"]["Movement"] = "9, Sw 18";
statblock_mammsmal["Otter, Giant"]["XP Value"] = "175";
statblock_mammsmal["Otter, Giant"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Otter, Giant"]["Frequency"] = "Common";
statblock_mammsmal["Otter, Giant"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Otter, Giant"]["THAC0"] = "20";
statblock_mammsmal["Otter, Giant"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Otter, Giant"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Otter, Giant"]["Alignment"] = "Neutral";
statblock_mammsmal["Pig, Domestic"]["Hit Dice"] = "2";
statblock_mammsmal["Pig, Domestic"]["Armor Class "] = "10";
statblock_mammsmal["Pig, Domestic"]["No. Appearing"] = "1-20";
statblock_mammsmal["Pig, Domestic"]["No. of Attacks"] = "1";
statblock_mammsmal["Pig, Domestic"]["Damage/Attack"] = "1-4";
statblock_mammsmal["Pig, Domestic"]["Movement"] = "12";
statblock_mammsmal["Pig, Domestic"]["XP Value"] = "35";
statblock_mammsmal["Pig, Domestic"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Pig, Domestic"]["Frequency"] = "Common";
statblock_mammsmal["Pig, Domestic"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Pig, Domestic"]["THAC0"] = "20";
statblock_mammsmal["Pig, Domestic"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Pig, Domestic"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Pig, Domestic"]["Alignment"] = "Neutral";
statblock_mammsmal["Pig, Wild"]["Hit Dice"] = "2";
statblock_mammsmal["Pig, Wild"]["Armor Class "] = "9";
statblock_mammsmal["Pig, Wild"]["No. Appearing"] = "1-8";
statblock_mammsmal["Pig, Wild"]["No. of Attacks"] = "1";
statblock_mammsmal["Pig, Wild"]["Damage/Attack"] = "1-4";
statblock_mammsmal["Pig, Wild"]["Movement"] = "12";
statblock_mammsmal["Pig, Wild"]["XP Value"] = "35";
statblock_mammsmal["Pig, Wild"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Pig, Wild"]["Frequency"] = "Common";
statblock_mammsmal["Pig, Wild"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Pig, Wild"]["THAC0"] = "20";
statblock_mammsmal["Pig, Wild"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Pig, Wild"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Pig, Wild"]["Alignment"] = "Neutral";
statblock_mammsmal["Rabbit"]["Hit Dice"] = "1-3 hp";
statblock_mammsmal["Rabbit"]["Armor Class "] = "6";
statblock_mammsmal["Rabbit"]["No. Appearing"] = "1-12";
statblock_mammsmal["Rabbit"]["No. of Attacks"] = "1";
statblock_mammsmal["Rabbit"]["Damage/Attack"] = "1";
statblock_mammsmal["Rabbit"]["Movement"] = "18";
statblock_mammsmal["Rabbit"]["XP Value"] = "7";
statblock_mammsmal["Rabbit"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Rabbit"]["Frequency"] = "Common";
statblock_mammsmal["Rabbit"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Rabbit"]["THAC0"] = "20";
statblock_mammsmal["Rabbit"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Rabbit"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Rabbit"]["Alignment"] = "Neutral";
statblock_mammsmal["Raccoon"]["Hit Dice"] = "1-6 hp";
statblock_mammsmal["Raccoon"]["Armor Class "] = "9";
statblock_mammsmal["Raccoon"]["No. Appearing"] = "1-4";
statblock_mammsmal["Raccoon"]["No. of Attacks"] = "1";
statblock_mammsmal["Raccoon"]["Damage/Attack"] = "1-2";
statblock_mammsmal["Raccoon"]["Movement"] = "5";
statblock_mammsmal["Raccoon"]["XP Value"] = "7";
statblock_mammsmal["Raccoon"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Raccoon"]["Frequency"] = "Common";
statblock_mammsmal["Raccoon"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Raccoon"]["THAC0"] = "20";
statblock_mammsmal["Raccoon"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Raccoon"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Raccoon"]["Alignment"] = "Neutral";
statblock_mammsmal["Squirrel"]["Hit Dice"] = "1 hp";
statblock_mammsmal["Squirrel"]["Armor Class "] = "8";
statblock_mammsmal["Squirrel"]["No. Appearing"] = "1-6";
statblock_mammsmal["Squirrel"]["No. of Attacks"] = "1";
statblock_mammsmal["Squirrel"]["Damage/Attack"] = "1";
statblock_mammsmal["Squirrel"]["Movement"] = "12";
statblock_mammsmal["Squirrel"]["XP Value"] = "0";
statblock_mammsmal["Squirrel"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Squirrel"]["Frequency"] = "Common";
statblock_mammsmal["Squirrel"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Squirrel"]["THAC0"] = "20";
statblock_mammsmal["Squirrel"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Squirrel"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Squirrel"]["Alignment"] = "Neutral";
statblock_mammsmal["Squirrel, Flying"]["Hit Dice"] = "1 hp";
statblock_mammsmal["Squirrel, Flying"]["Armor Class "] = "8";
statblock_mammsmal["Squirrel, Flying"]["No. Appearing"] = "7";
statblock_mammsmal["Squirrel, Flying"]["No. of Attacks"] = "1";
statblock_mammsmal["Squirrel, Flying"]["Damage/Attack"] = "1";
statblock_mammsmal["Squirrel, Flying"]["Movement"] = "12, Fl 15 (E)";
statblock_mammsmal["Squirrel, Flying"]["XP Value"] = "0";
statblock_mammsmal["Squirrel, Flying"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Squirrel, Flying"]["Frequency"] = "Common";
statblock_mammsmal["Squirrel, Flying"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Squirrel, Flying"]["THAC0"] = "20";
statblock_mammsmal["Squirrel, Flying"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Squirrel, Flying"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Squirrel, Flying"]["Alignment"] = "Neutral";
statblock_mammsmal["Squirrel, Giant black"]["Hit Dice"] = "1+1";
statblock_mammsmal["Squirrel, Giant black"]["Armor Class "] = "6";
statblock_mammsmal["Squirrel, Giant black"]["No. Appearing"] = "1-12";
statblock_mammsmal["Squirrel, Giant black"]["No. of Attacks"] = "1";
statblock_mammsmal["Squirrel, Giant black"]["Damage/Attack"] = "1+3";
statblock_mammsmal["Squirrel, Giant black"]["Movement"] = "12";
statblock_mammsmal["Squirrel, Giant black"]["XP Value"] = "35";
statblock_mammsmal["Squirrel, Giant black"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Squirrel, Giant black"]["Frequency"] = "Common";
statblock_mammsmal["Squirrel, Giant black"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Squirrel, Giant black"]["THAC0"] = "20";
statblock_mammsmal["Squirrel, Giant black"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Squirrel, Giant black"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Squirrel, Giant black"]["Alignment"] = "Neutral";
statblock_mammsmal["Woodchuck"]["Hit Dice"] = "1-6 hp";
statblock_mammsmal["Woodchuck"]["Armor Class "] = "9";
statblock_mammsmal["Woodchuck"]["No. Appearing"] = "1-2";
statblock_mammsmal["Woodchuck"]["No. of Attacks"] = "1";
statblock_mammsmal["Woodchuck"]["Damage/Attack"] = "1";
statblock_mammsmal["Woodchuck"]["Movement"] = "5, Br 2";
statblock_mammsmal["Woodchuck"]["XP Value"] = "7";
statblock_mammsmal["Woodchuck"]["Climate/Terrain"] = "Varies";
statblock_mammsmal["Woodchuck"]["Frequency"] = "Common";
statblock_mammsmal["Woodchuck"]["Intelligence"] = "Animal (1)";
statblock_mammsmal["Woodchuck"]["THAC0"] = "20";
statblock_mammsmal["Woodchuck"]["Magic Resistance"] = "Nil";
statblock_mammsmal["Woodchuck"]["Morale"] = "Unreliable to Average (2-9)";
statblock_mammsmal["Woodchuck"]["Alignment"] = "Neutral";



/////////////////////////////////////////////////////////////
// modron

// Monodrone
// Duodrone
// Tridrone
// Quadrone
// Pentadrone
// Decaton
// Nonaton
// Octon
// Septon
// Hexton
// Quinton
// Quarton
// Tertian
// Secundus
// Primus

// Monodrone
statblock_modron["Monodrone"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Monodrone"]["Frequency"]         = "Common";
statblock_modron["Monodrone"]["Organization"]      = "Hierarchy";
statblock_modron["Monodrone"]["Activity Cycle"]    = "Any";
statblock_modron["Monodrone"]["Diet"]              = "Special";
statblock_modron["Monodrone"]["Intelligence"]      = "Semi (2-4)";
statblock_modron["Monodrone"]["Treasure"]          = "Nil";
statblock_modron["Monodrone"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Monodrone"]["No. Appearing"]     = "12d12";
statblock_modron["Monodrone"]["Armor Class"]       = "7";
statblock_modron["Monodrone"]["Movement"]          = "6, Fl 18 (D)";
statblock_modron["Monodrone"]["Hit Dice"]          = "1+1 or 1-1";
statblock_modron["Monodrone"]["THAC0"]             = "19 or 20";
statblock_modron["Monodrone"]["No. of Attacks"]    = "1 or nil";
statblock_modron["Monodrone"]["Damage/Attack"]     = "1d4 or weapon";
statblock_modron["Monodrone"]["Special Attacks"]   = "Nil";
statblock_modron["Monodrone"]["Special Defenses"]  = "See below";
statblock_modron["Monodrone"]["Magic Resistance"]  = "Nil";
statblock_modron["Monodrone"]["Size"]              = "S";
statblock_modron["Monodrone"]["Morale"]            = "Fearless (20)";
statblock_modron["Monodrone"]["XP Value"]          = "1-1 HD:35<br>1+1 HD:120";
// Duodrone;
statblock_modron["Duodrone"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Duodrone"]["Frequency"]         = "Common";
statblock_modron["Duodrone"]["Organization"]      = "Hierarchy";
statblock_modron["Duodrone"]["Activity Cycle"]    = "Any";
statblock_modron["Duodrone"]["Diet"]              = "Special";
statblock_modron["Duodrone"]["Intelligence"]      = "Low (5-7)";
statblock_modron["Duodrone"]["Treasure"]          = "Nil";
statblock_modron["Duodrone"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Duodrone"]["No. Appearing"]     = "1d12";
statblock_modron["Duodrone"]["Armor Class"]       = "6";
statblock_modron["Duodrone"]["Movement"]          = "9, Fl 9 (E)";
statblock_modron["Duodrone"]["Hit Dice"]          = "2+2";
statblock_modron["Duodrone"]["THAC0"]             = "19";
statblock_modron["Duodrone"]["No. of Attacks"]    = "2";
statblock_modron["Duodrone"]["Damage/Attack"]     = "1d4+1 (×2) or weapon";
statblock_modron["Duodrone"]["Special Attacks"]   = "Nil";
statblock_modron["Duodrone"]["Special Defenses"]  = "See below";
statblock_modron["Duodrone"]["Magic Resistance"]  = "Nil";
statblock_modron["Duodrone"]["Size"]              = "S";
statblock_modron["Duodrone"]["Morale"]            = "Fearless (20)";
statblock_modron["Duodrone"]["XP Value"]          = "175";
// Tridrone;
statblock_modron["Tridrone"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Tridrone"]["Frequency"]         = "Uncommon";
statblock_modron["Tridrone"]["Organization"]      = "Hierarchy";
statblock_modron["Tridrone"]["Activity Cycle"]    = "Any";
statblock_modron["Tridrone"]["Diet"]              = "Special";
statblock_modron["Tridrone"]["Intelligence"]      = "Average (8-10)";
statblock_modron["Tridrone"]["Treasure"]          = "Nil";
statblock_modron["Tridrone"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Tridrone"]["No. Appearing"]     = "1d4";
statblock_modron["Tridrone"]["Armor Class"]       = "5";
statblock_modron["Tridrone"]["Movement"]          = "12";
statblock_modron["Tridrone"]["Hit Dice"]          = "3+3";
statblock_modron["Tridrone"]["THAC0"]             = "17";
statblock_modron["Tridrone"]["No. of Attacks"]    = "3";
statblock_modron["Tridrone"]["Damage/Attack"]     = "1d4+2 (×3)";
statblock_modron["Tridrone"]["Special Attacks"]   = "Nil";
statblock_modron["Tridrone"]["Special Defenses"]  = "See below";
statblock_modron["Tridrone"]["Magic Resistance"]  = "Nil";
statblock_modron["Tridrone"]["Size"]              = "M";
statblock_modron["Tridrone"]["Morale"]            = "Fearless (20)";
statblock_modron["Tridrone"]["XP Value"]          = "270";
// Quadrone;
statblock_modron["Quadrone"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Quadrone"]["Frequency"]         = "Uncommon";
statblock_modron["Quadrone"]["Organization"]      = "Hierarchy";
statblock_modron["Quadrone"]["Activity Cycle"]    = "Any";
statblock_modron["Quadrone"]["Diet"]              = "Special";
statblock_modron["Quadrone"]["Intelligence"]      = "Very (11-12)";
statblock_modron["Quadrone"]["Treasure"]          = "Nil";
statblock_modron["Quadrone"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Quadrone"]["No. Appearing"]     = "1d4";
statblock_modron["Quadrone"]["Armor Class"]       = "4";
statblock_modron["Quadrone"]["Movement"]          = "15, Fl 15 (D)";
statblock_modron["Quadrone"]["Hit Dice"]          = "4+4";
statblock_modron["Quadrone"]["THAC0"]             = "17";
statblock_modron["Quadrone"]["No. of Attacks"]    = "4 or 2";
statblock_modron["Quadrone"]["Damage/Attack"]     = "1d4+3 (×4), 1d5+5 (×5), or weapon";
statblock_modron["Quadrone"]["Special Attacks"]   = "Attacks as if 8 HD";
statblock_modron["Quadrone"]["Special Defenses"]  = "See below";
statblock_modron["Quadrone"]["Magic Resistance"]  = "Nil";
statblock_modron["Quadrone"]["Size"]              = "M";
statblock_modron["Quadrone"]["Morale"]            = "Fearless (20)";
statblock_modron["Quadrone"]["XP Value"]          = "650";
// Pentadrone;
statblock_modron["Pentadrone"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Pentadrone"]["Frequency"]         = "Rare";
statblock_modron["Pentadrone"]["Organization"]      = "Hierarchy";
statblock_modron["Pentadrone"]["Activity Cycle"]    = "Any";
statblock_modron["Pentadrone"]["Diet"]              = "Special";
statblock_modron["Pentadrone"]["Intelligence"]      = "Very (11-12)";
statblock_modron["Pentadrone"]["Treasure"]          = "Nil";
statblock_modron["Pentadrone"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Pentadrone"]["No. Appearing"]     = "1";
statblock_modron["Pentadrone"]["Armor Class"]       = "3";
statblock_modron["Pentadrone"]["Movement"]          = "18";
statblock_modron["Pentadrone"]["Hit Dice"]          = "5+5";
statblock_modron["Pentadrone"]["THAC0"]             = "15";
statblock_modron["Pentadrone"]["No. of Attacks"]    = "5";
statblock_modron["Pentadrone"]["Damage/Attack"]     = "1d4+4 (×5)";
statblock_modron["Pentadrone"]["Special Attacks"]   = "Paralysis gas";
statblock_modron["Pentadrone"]["Special Defenses"]  = "See below";
statblock_modron["Pentadrone"]["Magic Resistance"]  = "Nil";
statblock_modron["Pentadrone"]["Size"]              = "M";
statblock_modron["Pentadrone"]["Morale"]            = "Fearless (20)";
statblock_modron["Pentadrone"]["XP Value"]          = "2,000";
// Decaton;
statblock_modron["Decaton"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Decaton"]["Frequency"]         = "Rare";
statblock_modron["Decaton"]["Organization"]      = "Hierarchy";
statblock_modron["Decaton"]["Activity Cycle"]    = "Any";
statblock_modron["Decaton"]["Diet"]              = "Special";
statblock_modron["Decaton"]["Intelligence"]      = "High (13-14)";
statblock_modron["Decaton"]["Treasure"]          = "Nil";
statblock_modron["Decaton"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Decaton"]["No. Appearing"]     = "1 (of 100)";
statblock_modron["Decaton"]["Armor Class"]       = "2";
statblock_modron["Decaton"]["Movement"]          = "15, Fl 3 (E)";
statblock_modron["Decaton"]["Hit Dice"]          = "10+10";
statblock_modron["Decaton"]["THAC0"]             = "11";
statblock_modron["Decaton"]["No. of Attacks"]    = "10";
statblock_modron["Decaton"]["Damage/Attack"]     = "1d4×10";
statblock_modron["Decaton"]["Special Attacks"]   = "Spells";
statblock_modron["Decaton"]["Special Defenses"]  = "See below";
statblock_modron["Decaton"]["Magic Resistance"]  = "10%";
statblock_modron["Decaton"]["Size"]              = "M";
statblock_modron["Decaton"]["Morale"]            = "Fearless (20)";
statblock_modron["Decaton"]["XP Value"]          = "9,000";
// Nonaton;
statblock_modron["Nonaton"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Nonaton"]["Frequency"]         = "Rare";
statblock_modron["Nonaton"]["Organization"]      = "Hierarchy";
statblock_modron["Nonaton"]["Activity Cycle"]    = "Any";
statblock_modron["Nonaton"]["Diet"]              = "Special";
statblock_modron["Nonaton"]["Intelligence"]      = "High (13-14)";
statblock_modron["Nonaton"]["Treasure"]          = "Nil";
statblock_modron["Nonaton"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Nonaton"]["No. Appearing"]     = "1 (of 81)";
statblock_modron["Nonaton"]["Armor Class"]       = "0";
statblock_modron["Nonaton"]["Movement"]          = "18";
statblock_modron["Nonaton"]["Hit Dice"]          = "11+11";
statblock_modron["Nonaton"]["THAC0"]             = "9";
statblock_modron["Nonaton"]["No. of Attacks"]    = "9";
statblock_modron["Nonaton"]["Damage/Attack"]     = "1d6×9";
statblock_modron["Nonaton"]["Special Attacks"]   = "Spells";
statblock_modron["Nonaton"]["Special Defenses"]  = "See below";
statblock_modron["Nonaton"]["Magic Resistance"]  = "20%";
statblock_modron["Nonaton"]["Size"]              = "L";
statblock_modron["Nonaton"]["Morale"]            = "Fearless (20)";
statblock_modron["Nonaton"]["XP Value"]          = "10,000";
// Octon;
statblock_modron["Octon"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Octon"]["Frequency"]         = "Rare";
statblock_modron["Octon"]["Organization"]      = "Hierarchy";
statblock_modron["Octon"]["Activity Cycle"]    = "Any";
statblock_modron["Octon"]["Diet"]              = "Special";
statblock_modron["Octon"]["Intelligence"]      = "Exceptional (15-16)";
statblock_modron["Octon"]["Treasure"]          = "Nil";
statblock_modron["Octon"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Octon"]["No. Appearing"]     = "1 (of 64)";
statblock_modron["Octon"]["Armor Class"]       = "1";
statblock_modron["Octon"]["Movement"]          = "9, Fl 9 (B)";
statblock_modron["Octon"]["Hit Dice"]          = "12+12";
statblock_modron["Octon"]["THAC0"]             = "9";
statblock_modron["Octon"]["No. of Attacks"]    = "8";
statblock_modron["Octon"]["Damage/Attack"]     = "1d8 (×8)";
statblock_modron["Octon"]["Special Attacks"]   = "See below";
statblock_modron["Octon"]["Special Defenses"]  = "See below";
statblock_modron["Octon"]["Magic Resistance"]  = "30%";
statblock_modron["Octon"]["Size"]              = "L";
statblock_modron["Octon"]["Morale"]            = "Fearless (20)";
statblock_modron["Octon"]["XP Value"]          = "12,000";
// Septon;
statblock_modron["Septon"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Septon"]["Frequency"]         = "Very rare";
statblock_modron["Septon"]["Organization"]      = "Hierarchy";
statblock_modron["Septon"]["Activity Cycle"]    = "Any";
statblock_modron["Septon"]["Diet"]              = "Special";
statblock_modron["Septon"]["Intelligence"]      = "Exceptional (15-16)";
statblock_modron["Septon"]["Treasure"]          = "Nil";
statblock_modron["Septon"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Septon"]["No. Appearing"]     = "1 (of 49)";
statblock_modron["Septon"]["Armor Class"]       = "-1";
statblock_modron["Septon"]["Movement"]          = "9";
statblock_modron["Septon"]["Hit Dice"]          = "13+13";
statblock_modron["Septon"]["THAC0"]             = "7";
statblock_modron["Septon"]["No. of Attacks"]    = "7";
statblock_modron["Septon"]["Damage/Attack"]     = "1d10 (×7)";
statblock_modron["Septon"]["Special Attacks"]   = "See below";
statblock_modron["Septon"]["Special Defenses"]  = "See below";
statblock_modron["Septon"]["Magic Resistance"]  = "40%";
statblock_modron["Septon"]["Size"]              = "M";
statblock_modron["Septon"]["Morale"]            = "Fearless (20)";
statblock_modron["Septon"]["XP Value"]          = "13,000";
// Hexton;
statblock_modron["Hexton"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Hexton"]["Frequency"]         = "Very rare";
statblock_modron["Hexton"]["Organization"]      = "Hierarchy";
statblock_modron["Hexton"]["Activity Cycle"]    = "Any";
statblock_modron["Hexton"]["Diet"]              = "Special";
statblock_modron["Hexton"]["Intelligence"]      = "Genius (17-18)";
statblock_modron["Hexton"]["Treasure"]          = "Nil";
statblock_modron["Hexton"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Hexton"]["No. Appearing"]     = "1 (of 36)";
statblock_modron["Hexton"]["Armor Class"]       = "-2";
statblock_modron["Hexton"]["Movement"]          = "12, Fl 12 (C)";
statblock_modron["Hexton"]["Hit Dice"]          = "14+14";
statblock_modron["Hexton"]["THAC0"]             = "7";
statblock_modron["Hexton"]["No. of Attacks"]    = "6";
statblock_modron["Hexton"]["Damage/Attack"]     = "1d12 (×6)";
statblock_modron["Hexton"]["Special Attacks"]   = "See below";
statblock_modron["Hexton"]["Special Defenses"]  = "See below";
statblock_modron["Hexton"]["Magic Resistance"]  = "50%";
statblock_modron["Hexton"]["Size"]              = "L";
statblock_modron["Hexton"]["Morale"]            = "Fearless (20)";
statblock_modron["Hexton"]["XP Value"]          = "14,000";
// Quinton;
statblock_modron["Quinton"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Quinton"]["Frequency"]         = "Very rare";
statblock_modron["Quinton"]["Organization"]      = "Hierarchy";
statblock_modron["Quinton"]["Activity Cycle"]    = "Any";
statblock_modron["Quinton"]["Diet"]              = "Special";
statblock_modron["Quinton"]["Intelligence"]      = "Genius (17-18)";
statblock_modron["Quinton"]["Treasure"]          = "Nil";
statblock_modron["Quinton"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Quinton"]["No. Appearing"]     = "1 (of 25)";
statblock_modron["Quinton"]["Armor Class"]       = "-3";
statblock_modron["Quinton"]["Movement"]          = "6, Fl 6 (C)";
statblock_modron["Quinton"]["Hit Dice"]          = "15+15";
statblock_modron["Quinton"]["THAC0"]             = "5";
statblock_modron["Quinton"]["No. of Attacks"]    = "5";
statblock_modron["Quinton"]["Damage/Attack"]     = "2d8+1 (×5)";
statblock_modron["Quinton"]["Special Attacks"]   = "See below";
statblock_modron["Quinton"]["Special Defenses"]  = "See below";
statblock_modron["Quinton"]["Magic Resistance"]  = "60%";
statblock_modron["Quinton"]["Size"]              = "L";
statblock_modron["Quinton"]["Morale"]            = "Fearless (20)";
statblock_modron["Quinton"]["XP Value"]          = "15,000";
// Quarton;
statblock_modron["Quarton"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Quarton"]["Frequency"]         = "Very rare";
statblock_modron["Quarton"]["Organization"]      = "Hierarchy";
statblock_modron["Quarton"]["Activity Cycle"]    = "Any";
statblock_modron["Quarton"]["Diet"]              = "Special";
statblock_modron["Quarton"]["Intelligence"]      = "Supra (19-20)";
statblock_modron["Quarton"]["Treasure"]          = "Nil";
statblock_modron["Quarton"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Quarton"]["No. Appearing"]     = "1 (of 16)";
statblock_modron["Quarton"]["Armor Class"]       = "-4";
statblock_modron["Quarton"]["Movement"]          = "12, Fl 24 (B)";
statblock_modron["Quarton"]["Hit Dice"]          = "16+16";
statblock_modron["Quarton"]["THAC0"]             = "5";
statblock_modron["Quarton"]["No. of Attacks"]    = "4";
statblock_modron["Quarton"]["Damage/Attack"]     = "2d12+2 (×4)";
statblock_modron["Quarton"]["Special Attacks"]   = "See below";
statblock_modron["Quarton"]["Special Defenses"]  = "See below";
statblock_modron["Quarton"]["Magic Resistance"]  = "70%";
statblock_modron["Quarton"]["Size"]              = "L";
statblock_modron["Quarton"]["Morale"]            = "Fearless (20)";
statblock_modron["Quarton"]["XP Value"]          = "16,000";
// Tertian;
statblock_modron["Tertian"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Tertian"]["Frequency"]         = "Very rare";
statblock_modron["Tertian"]["Organization"]      = "Hierarchy";
statblock_modron["Tertian"]["Activity Cycle"]    = "Any";
statblock_modron["Tertian"]["Diet"]              = "Special";
statblock_modron["Tertian"]["Intelligence"]      = "Supra (19-20)";
statblock_modron["Tertian"]["Treasure"]          = "Nil";
statblock_modron["Tertian"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Tertian"]["No. Appearing"]     = "1 (of 9)";
statblock_modron["Tertian"]["Armor Class"]       = "-5";
statblock_modron["Tertian"]["Movement"]          = "12";
statblock_modron["Tertian"]["Hit Dice"]          = "17+17";
statblock_modron["Tertian"]["THAC0"]             = "3";
statblock_modron["Tertian"]["No. of Attacks"]    = "3";
statblock_modron["Tertian"]["Damage/Attack"]     = "5d8 (×3)";
statblock_modron["Tertian"]["Special Attacks"]   = "See below";
statblock_modron["Tertian"]["Special Defenses"]  = "See below";
statblock_modron["Tertian"]["Magic Resistance"]  = "80%";
statblock_modron["Tertian"]["Size"]              = "L";
statblock_modron["Tertian"]["Morale"]            = "Fearless (20)";
statblock_modron["Tertian"]["XP Value"]          = "18,000";
// Secundus;
statblock_modron["Secundus"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Secundus"]["Frequency"]         = "Very rare";
statblock_modron["Secundus"]["Organization"]      = "Hierarchy";
statblock_modron["Secundus"]["Activity Cycle"]    = "Any";
statblock_modron["Secundus"]["Diet"]              = "Special";
statblock_modron["Secundus"]["Intelligence"]      = "Godlike (21+)";
statblock_modron["Secundus"]["Treasure"]          = "Nil";
statblock_modron["Secundus"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Secundus"]["No. Appearing"]     = "1 (of 4)";
statblock_modron["Secundus"]["Armor Class"]       = "-6";
statblock_modron["Secundus"]["Movement"]          = "18, Fl 18 (B)";
statblock_modron["Secundus"]["Hit Dice"]          = "18+18";
statblock_modron["Secundus"]["THAC0"]             = "3";
statblock_modron["Secundus"]["No. of Attacks"]    = "2";
statblock_modron["Secundus"]["Damage/Attack"]     = "6d12 (×2)";
statblock_modron["Secundus"]["Special Attacks"]   = "See below";
statblock_modron["Secundus"]["Special Defenses"]  = "See below";
statblock_modron["Secundus"]["Magic Resistance"]  = "90%";
statblock_modron["Secundus"]["Size"]              = "L";
statblock_modron["Secundus"]["Morale"]            = "Fearless (20)";
statblock_modron["Secundus"]["XP Value"]          = "19,000";
// Primus;
statblock_modron["Primus"]["Climate/Terrain"]   = "Mechanus";
statblock_modron["Primus"]["Frequency"]         = "Unique";
statblock_modron["Primus"]["Organization"]      = "Hierarchy";
statblock_modron["Primus"]["Activity Cycle"]    = "Any";
statblock_modron["Primus"]["Diet"]              = "Special";
statblock_modron["Primus"]["Intelligence"]      = "Godlike (21+)";
statblock_modron["Primus"]["Treasure"]          = "Nil";
statblock_modron["Primus"]["Alignment"]         = "Lawful Neutral";
statblock_modron["Primus"]["No. Appearing"]     = "1";
statblock_modron["Primus"]["Armor Class"]       = "-10";
statblock_modron["Primus"]["Movement"]          = "24, Fl 24 (A)";
statblock_modron["Primus"]["Hit Dice"]          = "220 hp";
statblock_modron["Primus"]["THAC0"]             = "1";
statblock_modron["Primus"]["No. of Attacks"]    = "1";
statblock_modron["Primus"]["Damage/Attack"]     = "20d8 + special";
statblock_modron["Primus"]["Special Attacks"]   = "See below";
statblock_modron["Primus"]["Special Defenses"]  = "See below";
statblock_modron["Primus"]["Magic Resistance"]  = "100%";
statblock_modron["Primus"]["Size"]              = "L";
statblock_modron["Primus"]["Morale"]            = "Fearless (20)";
statblock_modron["Primus"]["XP Value"]          = "36,000";


/////////////////////////////////////////////////////////////
// snake
/*
The special part is the Elder and Jaculi labels on the
far left. In order to make existing parser scan it,
XP Value could be changed to include labels but with so many 
subtypes it would be too bulkyto put a label 
in each XP Value field

Table Conversion, HTML -> csv just using tr and sed 
< snaketable.html tr -d '\n' | sed -e 's/<tr>/\n/g' -e  's/<[\/]*table[^\/]*>//g' -e 's/<th>//g' -e 's/<\/th><td>/|/g' -e 's/<\/td><td>/|/g' -e 's/<\/td><\/tr>/|/g' -e 's/<tr class="bk"> <\/th>//g' -e 's/<th class="cn">/\|/g' -e 's/<\/t[hr]>//g' -e 's/\n//g' -e 's/   //g' -e 's/ |/|/g' > snaketable.csv
*/

// Amphisbaena
// Boalisk
// Constrictor (Normal)
// Constrictor (Giant)
// Heway
// Poison (Normal)
// Poison (Giant)
// Sea, Giant
// Spitting

statblock_snake["Amphisbaena"]["Climate/Terrain"] = "Any temperate";
statblock_snake["Amphisbaena"]["Frequency"] = "Very rare";
statblock_snake["Amphisbaena"]["Organization"] = "Solitary";
statblock_snake["Amphisbaena"]["Activity Cycle"] = "Day";
statblock_snake["Amphisbaena"]["Diet"] = "Carnivore";
statblock_snake["Amphisbaena"]["Intelligence"] = "Animal (1)";
statblock_snake["Amphisbaena"]["Treasure"] = "Nil";
statblock_snake["Amphisbaena"]["Alignment"] = "Neutral";
statblock_snake["Amphisbaena"]["No. Appearing"] = "1-3";
statblock_snake["Amphisbaena"]["Armor Class"] = "3";
statblock_snake["Amphisbaena"]["Movement"] = "12";
statblock_snake["Amphisbaena"]["Hit Dice"] = "6";
statblock_snake["Amphisbaena"]["THAC0"] = "15";
statblock_snake["Amphisbaena"]["No. of Attacks"] = "2";
statblock_snake["Amphisbaena"]["Damage/Attack"] = "1-3/1-3";
statblock_snake["Amphisbaena"]["Special Attacks"] = "Poison";
statblock_snake["Amphisbaena"]["Special Defenses"] = "See below";
statblock_snake["Amphisbaena"]["Magic Resistance"] = "Nil";
statblock_snake["Amphisbaena"]["Size"] = "M (13' long)";
statblock_snake["Amphisbaena"]["Morale"] = "Average (9)";
statblock_snake["Amphisbaena"]["XP Value"] = "650<br>Elder: 1,400<br>Jaculi: 975";
statblock_snake["Boalisk"]["Climate/Terrain"] = "Any tropical";
statblock_snake["Boalisk"]["Frequency"] = "Rare";
statblock_snake["Boalisk"]["Organization"] = "Solitary";
statblock_snake["Boalisk"]["Activity Cycle"] = "Day";
statblock_snake["Boalisk"]["Diet"] = "Carnivore";
statblock_snake["Boalisk"]["Intelligence"] = "Animal (1)";
statblock_snake["Boalisk"]["Treasure"] = "Nil";
statblock_snake["Boalisk"]["Alignment"] = "Neutral";
statblock_snake["Boalisk"]["No. Appearing"] = "1-3";
statblock_snake["Boalisk"]["Armor Class"] = "5";
statblock_snake["Boalisk"]["Movement"] = "12";
statblock_snake["Boalisk"]["Hit Dice"] = "5+1";
statblock_snake["Boalisk"]["THAC0"] = "17";
statblock_snake["Boalisk"]["No. of Attacks"] = "2";
statblock_snake["Boalisk"]["Damage/Attack"] = "1-3/2-7";
statblock_snake["Boalisk"]["Special Attacks"] = "Gaze and constrict";
statblock_snake["Boalisk"]["Special Defenses"] = "Nil";
statblock_snake["Boalisk"]["Magic Resistance"] = "Nil";
statblock_snake["Boalisk"]["Size"] = "L (25' long)";
statblock_snake["Boalisk"]["Morale"] = "Average (10)";
statblock_snake["Boalisk"]["XP Value"] = "975<br>Elder: 2,000<br>Jaculi: 1,400";
statblock_snake["Constrictor (Normal)"]["Climate/Terrain"] = "Any warm";
statblock_snake["Constrictor (Normal)"]["Frequency"] = "Uncommon";
statblock_snake["Constrictor (Normal)"]["Organization"] = "Solitary";
statblock_snake["Constrictor (Normal)"]["Activity Cycle"] = "Any";
statblock_snake["Constrictor (Normal)"]["Diet"] = "Carnivore";
statblock_snake["Constrictor (Normal)"]["Intelligence"] = "Animal (1)";
statblock_snake["Constrictor (Normal)"]["Treasure"] = "Nil";
statblock_snake["Constrictor (Normal)"]["Alignment"] = "Neutral";
statblock_snake["Constrictor (Normal)"]["No. Appearing"] = "1-2";
statblock_snake["Constrictor (Normal)"]["Armor Class"] = "6";
statblock_snake["Constrictor (Normal)"]["Movement"] = "9";
statblock_snake["Constrictor (Normal)"]["Hit Dice"] = "3+2";
statblock_snake["Constrictor (Normal)"]["THAC0"] = "17";
statblock_snake["Constrictor (Normal)"]["No. of Attacks"] = "2";
statblock_snake["Constrictor (Normal)"]["Damage/Attack"] = "1/1-3";
statblock_snake["Constrictor (Normal)"]["Special Attacks"] = "Constrict";
statblock_snake["Constrictor (Normal)"]["Special Defenses"] = "Nil";
statblock_snake["Constrictor (Normal)"]["Magic Resistance"] = "Nil";
statblock_snake["Constrictor (Normal)"]["Size"] = "M (10-20' long)";
statblock_snake["Constrictor (Normal)"]["Morale"] = "Average (8)";
statblock_snake["Constrictor (Normal)"]["XP Value"] = "175<br>Elder: 420<br>Jaculi: 270";
statblock_snake["Constrictor (Giant)"]["Climate/Terrain"] = "Any warm";
statblock_snake["Constrictor (Giant)"]["Frequency"] = "Uncommon";
statblock_snake["Constrictor (Giant)"]["Organization"] = "Solitary";
statblock_snake["Constrictor (Giant)"]["Activity Cycle"] = "Any";
statblock_snake["Constrictor (Giant)"]["Diet"] = "Carnivore";
statblock_snake["Constrictor (Giant)"]["Intelligence"] = "Animal (1)";
statblock_snake["Constrictor (Giant)"]["Treasure"] = "Nil";
statblock_snake["Constrictor (Giant)"]["Alignment"] = "Neutral";
statblock_snake["Constrictor (Giant)"]["No. Appearing"] = "1-2";
statblock_snake["Constrictor (Giant)"]["Armor Class"] = "5";
statblock_snake["Constrictor (Giant)"]["Movement"] = "9";
statblock_snake["Constrictor (Giant)"]["Hit Dice"] = "6+1";
statblock_snake["Constrictor (Giant)"]["THAC0"] = "15";
statblock_snake["Constrictor (Giant)"]["No. of Attacks"] = "2";
statblock_snake["Constrictor (Giant)"]["Damage/Attack"] = "1-4/2-8";
statblock_snake["Constrictor (Giant)"]["Special Attacks"] = "Constrict";
statblock_snake["Constrictor (Giant)"]["Special Defenses"] = "Nil";
statblock_snake["Constrictor (Giant)"]["Magic Resistance"] = "Nil";
statblock_snake["Constrictor (Giant)"]["Size"] = "L (30'+ long)";
statblock_snake["Constrictor (Giant)"]["Morale"] = "Average (9)";
statblock_snake["Constrictor (Giant)"]["XP Value"] = "650<br>Elder: 1,400<br>Jaculi: 975";
statblock_snake["Heway"]["Climate/Terrain"] = "Desert oases";
statblock_snake["Heway"]["Frequency"] = "Uncommon";
statblock_snake["Heway"]["Organization"] = "Solitary";
statblock_snake["Heway"]["Activity Cycle"] = "Dawn and dusk";
statblock_snake["Heway"]["Diet"] = "Carnivore";
statblock_snake["Heway"]["Intelligence"] = "Low (5-7)";
statblock_snake["Heway"]["Treasure"] = "Nil";
statblock_snake["Heway"]["Alignment"] = "Neutral";
statblock_snake["Heway"]["No. Appearing"] = "1-2";
statblock_snake["Heway"]["Armor Class"] = "7";
statblock_snake["Heway"]["Movement"] = "12, Sw 6";
statblock_snake["Heway"]["Hit Dice"] = "1+3";
statblock_snake["Heway"]["THAC0"] = "19";
statblock_snake["Heway"]["No. of Attacks"] = "1";
statblock_snake["Heway"]["Damage/Attack"] = "1-3";
statblock_snake["Heway"]["Special Attacks"] = "Poison and hypnotic stare";
statblock_snake["Heway"]["Special Defenses"] = "Nil";
statblock_snake["Heway"]["Magic Resistance"] = "Nil";
statblock_snake["Heway"]["Size"] = "M (12' long)";
statblock_snake["Heway"]["Morale"] = "Unsteady (6)";
statblock_snake["Heway"]["XP Value"] = "175<br>Elder: 420";
statblock_snake["Poison (Normal)"]["Climate/Terrain"] = "Any land";
statblock_snake["Poison (Normal)"]["Frequency"] = "Uncommon";
statblock_snake["Poison (Normal)"]["Organization"] = "Solitary";
statblock_snake["Poison (Normal)"]["Activity Cycle"] = "Any";
statblock_snake["Poison (Normal)"]["Diet"] = "Carnivore";
statblock_snake["Poison (Normal)"]["Intelligence"] = "Animal (1)";
statblock_snake["Poison (Normal)"]["Treasure"] = "Nil";
statblock_snake["Poison (Normal)"]["Alignment"] = "Neutral";
statblock_snake["Poison (Normal)"]["No. Appearing"] = "1-6";
statblock_snake["Poison (Normal)"]["Armor Class"] = "6";
statblock_snake["Poison (Normal)"]["Movement"] = "15";
statblock_snake["Poison (Normal)"]["Hit Dice"] = "2+1";
statblock_snake["Poison (Normal)"]["THAC0"] = "19";
statblock_snake["Poison (Normal)"]["No. of Attacks"] = "1";
statblock_snake["Poison (Normal)"]["Damage/Attack"] = "1";
statblock_snake["Poison (Normal)"]["Special Attacks"] = "Poison";
statblock_snake["Poison (Normal)"]["Special Defenses"] = "Nil";
statblock_snake["Poison (Normal)"]["Magic Resistance"] = "Nil";
statblock_snake["Poison (Normal)"]["Size"] = "S (5' long)";
statblock_snake["Poison (Normal)"]["Morale"] = "Average (8)";
statblock_snake["Poison (Normal)"]["XP Value"] = "175<br>Elder: 420<br>Jaculi: 270";
statblock_snake["Poison (Giant)"]["Climate/Terrain"] = "Any land";
statblock_snake["Poison (Giant)"]["Frequency"] = "Uncommon";
statblock_snake["Poison (Giant)"]["Organization"] = "Solitary";
statblock_snake["Poison (Giant)"]["Activity Cycle"] = "Any";
statblock_snake["Poison (Giant)"]["Diet"] = "Carnivore";
statblock_snake["Poison (Giant)"]["Intelligence"] = "Animal (1)";
statblock_snake["Poison (Giant)"]["Treasure"] = "Nil";
statblock_snake["Poison (Giant)"]["Alignment"] = "Neutral";
statblock_snake["Poison (Giant)"]["No. Appearing"] = "1-6";
statblock_snake["Poison (Giant)"]["Armor Class"] = "5";
statblock_snake["Poison (Giant)"]["Movement"] = "15";
statblock_snake["Poison (Giant)"]["Hit Dice"] = "4+2";
statblock_snake["Poison (Giant)"]["THAC0"] = "17";
statblock_snake["Poison (Giant)"]["No. of Attacks"] = "1";
statblock_snake["Poison (Giant)"]["Damage/Attack"] = "1-3";
statblock_snake["Poison (Giant)"]["Special Attacks"] = "Poison";
statblock_snake["Poison (Giant)"]["Special Defenses"] = "Nil";
statblock_snake["Poison (Giant)"]["Magic Resistance"] = "Nil";
statblock_snake["Poison (Giant)"]["Size"] = "M (12' long)";
statblock_snake["Poison (Giant)"]["Morale"] = "Average (9)";
statblock_snake["Poison (Giant)"]["XP Value"] = "420<br>Elder: 975<br>Jaculi: 650";
statblock_snake["Sea, Giant"]["Climate/Terrain"] = "Tropical marine";
statblock_snake["Sea, Giant"]["Frequency"] = "Uncommon";
statblock_snake["Sea, Giant"]["Organization"] = "Solitary";
statblock_snake["Sea, Giant"]["Activity Cycle"] = "Any";
statblock_snake["Sea, Giant"]["Diet"] = "Carnivore";
statblock_snake["Sea, Giant"]["Intelligence"] = "Animal (1)";
statblock_snake["Sea, Giant"]["Treasure"] = "Nil";
statblock_snake["Sea, Giant"]["Alignment"] = "Neutral";
statblock_snake["Sea, Giant"]["No. Appearing"] = "1-8";
statblock_snake["Sea, Giant"]["Armor Class"] = "5";
statblock_snake["Sea, Giant"]["Movement"] = "12, Sw 12";
statblock_snake["Sea, Giant"]["Hit Dice"] = "10";
statblock_snake["Sea, Giant"]["THAC0"] = "11";
statblock_snake["Sea, Giant"]["No. of Attacks"] = "2";
statblock_snake["Sea, Giant"]["Damage/Attack"] = "1-6/3-18";
statblock_snake["Sea, Giant"]["Special Attacks"] = "Poison, constrict";
statblock_snake["Sea, Giant"]["Special Defenses"] = "Nil";
statblock_snake["Sea, Giant"]["Magic Resistance"] = "Nil";
statblock_snake["Sea, Giant"]["Size"] = "G (50'+ long)";
statblock_snake["Sea, Giant"]["Morale"] = "Steady (11)";
statblock_snake["Sea, Giant"]["XP Value"] = "3,000<br>Elder: 5,000";
statblock_snake["Spitting"]["Climate/Terrain"] = "Tropical land";
statblock_snake["Spitting"]["Frequency"] = "Rare";
statblock_snake["Spitting"]["Organization"] = "Solitary";
statblock_snake["Spitting"]["Activity Cycle"] = "Any";
statblock_snake["Spitting"]["Diet"] = "Carnivore";
statblock_snake["Spitting"]["Intelligence"] = "Animal (1)";
statblock_snake["Spitting"]["Treasure"] = "Nil";
statblock_snake["Spitting"]["Alignment"] = "Neutral";
statblock_snake["Spitting"]["No. Appearing"] = "1-4";
statblock_snake["Spitting"]["Armor Class"] = "5";
statblock_snake["Spitting"]["Movement"] = "12";
statblock_snake["Spitting"]["Hit Dice"] = "4+2";
statblock_snake["Spitting"]["THAC0"] = "17";
statblock_snake["Spitting"]["No. of Attacks"] = "2";
statblock_snake["Spitting"]["Damage/Attack"] = "1-3";
statblock_snake["Spitting"]["Special Attacks"] = "Spit Poison";
statblock_snake["Spitting"]["Special Defenses"] = "Nil";
statblock_snake["Spitting"]["Magic Resistance"] = "Nil";
statblock_snake["Spitting"]["Size"] = "M (8' long)";
statblock_snake["Spitting"]["Morale"] = "Average (9)";
statblock_snake["Spitting"]["XP Value"] = "650<br>Elder: 1,400<br>Jaculi: 975";



}



};
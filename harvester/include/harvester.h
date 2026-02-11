#ifndef LOMION_INCLUDE_HARVESTER_H_
#define LOMION_INCLUDE_HARVESTER_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <filesystem>
#include <typeinfo>
#include <set>
#include <chrono>

#include <json/value.h>
#include "ThreadsafeData.h"
#include "ThreadsafeArray.h"
#include "SpecialStatblock.h"

class Harvester
{
private:
    // lists of filenames, filepaths
    std::vector<std::string> filenames;
    std::vector<std::filesystem::path> filepaths;
    // map with all html file data, mapped to the file names
    std::map<std::string, std::string> monsterStringContentsMap;
    std::set<std::string> monsterNames;

    // list of strings of monster_keys with empty bodies
    // need to make it thread safe
    ThreadsafeArray emptyMonsterKeys;

    // Json::Value monsterData;
    ThreadsafeData monsterData;

    // Special Statblocks
    SpecialStatblock special_statblocks;

public:
    bool debug;

    Json::Value Catalogue;
    Json::Value BookCategories;
    

    void HarvestAll(bool threaded);
    int GetFileData();
    std::string ReadFileIntoString2(const std::string &path);
    void PrintMap();
    std::map<std::string, std::string> getMonsterStrings();
    std::string getMonsterString(std::string monster_key);
    bool hasMonsterString(std::string monster_key);
    // void AddMonsterData(Json::Value monster);
    void LaunchThread(std::set<std::string> monsterNames);

    Json::Value HarvestNickNames();

    std::string GetTitle(std::string &in);
    Json::Value GetTSR(std::string &in);
    Json::Value GetStatsTable(std::string in);
    std::string GetPrimaryMonster(std::string in);
    std::vector<std::string> GetTables(std::string in);

    Json::Value GetImages(std::string in);

    std::string GetFullBody(std::string in, std::string monster_key);

    // Texts
    std::string GetCombat(std::string &in);
    std::string GetHabitatSociety(std::string &in);
    std::string GetEcology(std::string &in);

    Json::Value GetBody(std::string in);
    Json::Value GetBonusMonsters(std::string &in, std::string monster_name);

    Json::Value ExtractH2s(std::string in);
    int GetNumberTypes(std::string in);

    bool HasList(std::string in);
    Json::Value ParseList(std::string in);
    Json::Value ParseGeneral(std::string &in);
    Json::Value ParseTable(std::string in);

    // Psionics
    bool HasPsionics(std::string &in);
    Json::Value GetPsionicTable(std::string in);

    // Pruning
    std::string PruneImages(std::string &in);

    // Extras
    std::vector<std::string> GetPictures(std::string in);

    std::vector<std::string> GetUniqueTSRList();

    //Utility
    void SaveMonsterJson(std::string monsterName, Json::Value monsterJson);
    void SaveJsonToPath(std::string jsonPath, Json::Value jsonValue);
    void TestRun();
    std::vector<std::string> split(const std::string &str, const std::string &delim);

    std::string GetCategory(std::string imgString);

    /// Returns int as status code
    // 0 - Good
    // 1 - Warning
    // 2 - Null statblock
    // 3 - 
    // 4 - Dragon mag
    int RunMonster(std::string monsterName);
    
    void TestMonsterParser(std::string monsterName);
    void ListMonsters();
    bool IdentifyGeneralInfo(std::string in);
    void PrintCatalogue();
    void SaveCatalogue();
    void SaveCategories();
    void SaveTitles(Json::Value monster_json);
    void SaveStatistics();

    void ExportAPIJson(Json::Value monster_json);
};

#endif // LOMION_INCLUDE_HARVESTER_H_
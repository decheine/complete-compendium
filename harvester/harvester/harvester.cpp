// Standard includes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
// #include <experimental/regex>
#include <regex>
#include <filesystem>
#include <typeinfo>
#include <set>
#include <chrono>
#include <thread>
#include <algorithm>
#include <locale>  
// boost
// #include <boost/algorithm/string.hpp>

// Jsoncpp
#include <json/value.h>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>

#include "harvester.h"
// #include "BlockHarvester.h"

// #include "psionic_reader.h"

class Table
{
public:
    std::vector<std::vector<std::string>> tableVector;
    void addRow(std::vector<std::string> row);
};

// TESTING
void Harvester::TestMonsterParser(std::string monsterName)
{
    auto startTime = std::chrono::high_resolution_clock::now();
    std::string monsterString = getMonsterStrings()[monsterName + ".html"];
    std::string category;
    Json::Value monsterJson;
    Json::Value blank;
    auto GetTitle_start = std::chrono::high_resolution_clock::now();
    monsterJson["title"] = GetTitle(monsterString);
    auto GetTitle_end = std::chrono::high_resolution_clock::now();

    auto TSR_start = std::chrono::high_resolution_clock::now();
    monsterJson["TSR"] = GetTSR(monsterString);
    auto TSR_end = std::chrono::high_resolution_clock::now();

    auto Images_start = std::chrono::high_resolution_clock::now();
    monsterJson["images"] = GetImages(monsterString);
    auto Images_end = std::chrono::high_resolution_clock::now();
    // Check if it's from Dragon Magazine to skip it

    auto TSR_proc_start = std::chrono::high_resolution_clock::now();
    for (auto x : monsterJson["TSR"])
    {
        if (!x.asString().find("Dragon#"))
        {
            // std::cout << " - Dragon Mag, skipped\n";
            return;
        }

        // Add monster to catalogue
        Catalogue[x.asString()].append(monsterName);
    }
    auto TSR_proc_end = std::chrono::high_resolution_clock::now();
    // Get category
    auto GetCategory_start = std::chrono::high_resolution_clock::now();
    category = GetCategory(monsterJson["images"][0].asString());
    auto GetCategory_end = std::chrono::high_resolution_clock::now();
    // check categories list

    auto existingBooks = BookCategories[category];

    Json::Value tsrs = monsterJson["TSR"];
    // std::cout << "category: " << category << "\n";
    std::vector<Json::Value> res;
    std::vector<std::string> existingInCategory;
    bool entryFound = false;
    // Check if tsrs is an array or singular

    auto CheckTSR_start = std::chrono::high_resolution_clock::now();
    if (!tsrs.empty())
    {
        if (tsrs.isArray())
        {
            std::vector<std::string> tsr_elems;
            for (auto x : tsrs)
            {
                tsr_elems.emplace_back(x.asCString());
            }

            if (BookCategories[category].isArray())
            {
                for (auto x : BookCategories[category])
                {
                    existingInCategory.emplace_back(x.asCString());
                }
            }

            for (std::string y : tsr_elems)
            {
                if (std::find(existingInCategory.begin(), existingInCategory.end(), y) != existingInCategory.end())
                {
                }
                else
                {
                    BookCategories[category].append(y);
                }
            }
        }
        else
        {
            if (!(BookCategories[category].get(tsrs.asCString(), Json::nullValue)))
            {
                BookCategories[category].append(tsrs.asCString());
            }
        }
    }
    auto CheckTSR_end = std::chrono::high_resolution_clock::now();

    // Prune images
    if (debug)
        std::cout << "pruning images\n";
    // auto PruneImages_start = std::chrono::high_resolution_clock::now();
    // monsterString = PruneImages(monsterString);
    // auto PruneImages_end = std::chrono::high_resolution_clock::now();

    auto Statblock_start = std::chrono::high_resolution_clock::now();

    // std::chrono::_V2::system_clock::time_point ParseGeneral_start;
    // std::chrono::_V2::system_clock::time_point ParseGeneral_end;

    // std::chrono::_V2::system_clock::time_point GetStatsTable_start;
    // std::chrono::_V2::system_clock::time_point Psionics_start;
    // std::chrono::_V2::system_clock::time_point H2_start;
    // std::chrono::_V2::system_clock::time_point GetBody_start;
    // std::chrono::_V2::system_clock::time_point GetStatsTable_end;
    // std::chrono::_V2::system_clock::time_point Psionics_end;
    // std::chrono::_V2::system_clock::time_point H2_end;
    // std::chrono::_V2::system_clock::time_point GetBody_end;

    // General Information ID
    if (IdentifyGeneralInfo(monsterString))
    {
        // std::cout << "parsing general\n";
        // ParseGeneral_start = std::chrono::high_resolution_clock::now();
        Json::Value generalJson = ParseGeneral(monsterString);
        // ParseGeneral_end = std::chrono::high_resolution_clock::now();
        monsterJson["general"] = generalJson;
    }
    else
    {
        // GetStatsTable_start = std::chrono::high_resolution_clock::now();
        Json::Value statblock = GetStatsTable(monsterString);
        // GetStatsTable_end = std::chrono::high_resolution_clock::now();
        // std::cout << "statblock: \n";
        // std::cout << statblock.toStyledString() << "\n";

        monsterJson["statblock"] = statblock;

        Json::Value psionics;
        Json::Value psionicTable;
        // Psionics_start = std::chrono::high_resolution_clock::now();
        // if (HasPsionics(monsterString))
        // {
        //     if (debug)
        //         std::cout << "has psionics\n";

        //     // PsionicReader psionicReader;
        //     psionicReader.debug = debug;

        //     psionics = psionicReader.parsePowerTree(monsterString);
        //     monsterJson["psionics"] = psionics;

        //     // prune psionic table
        //     if (debug)
        //         std::cout << "pruning psionics\n";
        //     monsterString = psionicReader.prunePsionics(monsterString);

        //     if (debug)
        //         std::cout << "pruned psionics\n";
        // }
        // Psionics_end = std::chrono::high_resolution_clock::now();

        // Check how many types there are
        int numTypes;
        numTypes = GetNumberTypes(monsterString);

        // parse h2 headers for multimonsters
        if (debug)
            std::cout << "Parsing h2's of " << numTypes << " types\n";
        // H2_start = std::chrono::high_resolution_clock::now();
        Json::Value multitypeHeaderData = ExtractH2s(monsterString);
        // H2_end = std::chrono::high_resolution_clock::now();

        std::vector<std::string> memberNames = multitypeHeaderData.getMemberNames();
        if (debug)
            std::cout << "membernames size " << memberNames.size() << "\n";
        // if there are h2's
        // GetBody_start = std::chrono::high_resolution_clock::now();
        if (memberNames.size() > 0)
        {
            // std::cout << "H2 member\n";

            for (std::string x : memberNames)
            {
                monsterJson["body"][x] = GetBody(multitypeHeaderData[x].asCString());
            }
        }
        else
        { // single type
            if (debug)
                std::cout << "getting body single type \n";
            monsterJson["body"] = GetBody(monsterString);
            if (debug)
                std::cout << "body: " << monsterJson["body"] << "\n";
        }
        // GetBody_end = std::chrono::high_resolution_clock::now();
    }

    auto Statblock_end = std::chrono::high_resolution_clock::now();
    Json::Value monsterDataJson;
    auto MonsterDataJson_start = std::chrono::high_resolution_clock::now();
    monsterDataJson[monsterName] = monsterJson;
    auto MonsterDataJson_end = std::chrono::high_resolution_clock::now();

    // append this monster to all monster json
    // monsterData[monsterName] = monsterJson;

    // Save json file
    // auto Savejson_start = std::chrono::high_resolution_clock::now();
    // SaveMonsterJson(monsterName, monsterDataJson);
    // auto Savejson_end = std::chrono::high_resolution_clock::now();

    // auto stop = std::chrono::high_resolution_clock::now();
    // auto totalDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - startTime);

    // std::cout << "Tabulating times...\n";

    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    // std::cout << duration.count() << std::endl;

    // std::cout << "Total duration:\t " << std::chrono::duration_cast<std::chrono::microseconds>(stop - startTime).count() << "\n";

    // std::cout << "GetTitle \t " << std::chrono::duration_cast<std::chrono::microseconds>(GetTitle_end - GetTitle_start).count() << "\n";
    // std::cout << "Statblock \t " << std::chrono::duration_cast<std::chrono::microseconds>(Statblock_end - Statblock_start).count() << "\n";

    if (IdentifyGeneralInfo(monsterString))
    {
        // std::cout << "ParseGeneral\t" << std::chrono::duration_cast<std::chrono::microseconds>(ParseGeneral_end - ParseGeneral_start).count() << "\n";
    }
    else
    {
        // std::cout << "\tGetStatsTable\t" << std::chrono::duration_cast<std::chrono::microseconds>(GetStatsTable_end - GetStatsTable_start).count() << "\n";
        // std::cout << "\tPsionics\t" << std::chrono::duration_cast<std::chrono::microseconds>(Psionics_end - Psionics_start).count() << "\n";
        // std::cout << "\tH2\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(H2_end - H2_start).count() << "\n";
        // std::cout << "\tGetBody\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(GetBody_end - GetBody_start).count() << "\n";
    }



    // GetTitle
    // TSR
    // Images
    // TSR_proc
    // GetCategory
    // CheckTSR
    // PruneImages
    // Statblock
    // Savejson

    return;
}

std::map<std::string, std::string> Harvester::getMonsterStrings()
{
    return monsterStringContentsMap;
}

std::string Harvester::getMonsterString(std::string monster_key){
    return monsterStringContentsMap[monster_key];
}

bool Harvester::hasMonsterString(std::string monster_key){
    if(monsterStringContentsMap.count(monster_key) == 1) {
        return true;
    } else {
        return false;
    }
}


/// SINGLE MONSTER TARGETS

Json::Value Harvester::ExtractH2s(std::string in)
{
    // s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
    // boost::replace_all(s, "\n", " ");
    // std::regex h2_exp("<h2>(.+?)</h2>((.|\n)+?)(?=<h2)", std::regex_constants::extended | std::regex_constants::ECMAScript);
    std::regex h2_exp("<h2>(.+)</h2>([^]+?)(?=<h2|<br )");

    // std::smatch h2m;
    Json::Value headerData;

    // std::regex_search(s, h2m, h2_exp);
    // std::cout << s << "\n";
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> a(in.begin(), in.end(), h2_exp, {1, 2});

    bool found = std::regex_search(in, h2_exp);
    if (found)
    {
        if (debug)
            std::cout << "h2 search found\n";
        std::vector<std::string> data;
        std::string tmpName;
        std::string tmpDescription;
        // std::cout << "original in: \n" << in << "\n";
        // while (a != rend)
        // {
        //     tmpName = *a++;
        //     tmpDescription = *a++;
        //     headerData[tmpName] = tmpDescription;
        //     std::cout << tmpName << "\n";
        //     std::cout << "Description: " << tmpDescription << "\n";
        //     printf("\n\n\n");
        //     // delete tmpDescription from in
        //     boost::replace_all(in, tmpDescription, "");
        // }
        while (a != rend)
        {
            tmpName = *a++;
            // std::cout << "Name: " << tmpName << "\n";
            tmpDescription = *a++;
            // std::cout << "Description: " << tmpDescription << "\n";
            headerData[tmpName] = tmpDescription;
            // printf("\n\n");
        }

        for( auto t : headerData){
            // std::cout << ": " << t.asString() << "\n";
            // boost::replace_all(in, t.asString(), "");
        }
        in = in;
        // printf("modified string: %s\n", in.c_str());
        // std::cout << "headerData members: " <<  headerData.getMemberNames().size() << "\n";
        return headerData;
    }
    else
    {
        if (debug)
            std::cout << "h2 search not found\n";

        return headerData;
    }
}

Json::Value Harvester::ParseGeneral(std::string &in)
{
    Json::Value root;
    Json::Value body;
    //<p class=\"(?:f|ni)\">((?:<b>(.+?)</b>)*(.|\n|\r)+?)(?=<p class=\"f|<br )
    std::regex general("<p class=\"(?:f|ni)\">((?:<b>(.+?)</b>)*[^]+?)(?=<p class=\"f|<br )", std::regex_constants::extended | std::regex_constants::ECMAScript | std::regex::optimize);
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> a(in.begin(), in.end(), general, {1, 2});
    std::vector<std::string> data;
    std::string tmpCat;
    std::string tmpValue;

    int counter = 0;

    while (a != rend)
    {
        tmpValue = *a++;
        tmpCat = *a++;

        if (tmpCat.size() > 0)
        { // has a section label in bold
            body[counter][tmpCat] = tmpValue;
        }
        else
        { // no section label
            body[counter] = tmpValue;
        }

        // std::cout << tmpCat << "\n";
        counter++;
    }

    // std::cout << body.toStyledString() << "\n";
    return body;
}

// TSR Listing

// Get Unique TSR items

// only want one of each of them. This should be called after multitypes have been separated
Json::Value Harvester::GetBody(std::string in)
{
    //<p class=\"f\">(<b>)*([^<][^:]+?)(?=(<p class=\"f|<br |$))
    //<p class=\"f\">([^<][^]+?)(?=(<p class=\"f|<br |$))
    std::regex intro("<p class=\"f\">(<b>)*([^<][^:]+?)(?=(<p class=\"f|<br |$))", std::regex_constants::extended | std::regex_constants::ECMAScript | std::regex::optimize);
    std::regex_token_iterator<std::string::iterator> b(in.begin(), in.end(), intro);
    std::regex_token_iterator<std::string::iterator> rend;
    Json::Value body;
    // no while loop because it should only be called once.
    std::string tmpValue;
    if (b != rend)
    {
        tmpValue = *b++;

        body["intro"] = tmpValue;
    }

    std::regex sections("<p class=\"f\"><b>(.+?):</b>([^]+?)(?=(<p class|<br|<h2|$))", std::regex_constants::extended | std::regex_constants::ECMAScript | std::regex::optimize);

    std::regex_token_iterator<std::string::iterator> a(in.begin(), in.end(), sections, {1, 2});
    std::vector<std::string> data;
    std::string tmpCat;

    while (a != rend)
    {
        tmpCat = *a++;
        tmpValue = *a++;
        body[tmpCat] = tmpValue;
    }

    // std::cout << "body: \n" << body.toStyledString() << "\n";

    return body;
}

// Get Bonus Monster

Json::Value Harvester::GetBonusMonsters(std::string &in, std::string monster_name){
    Json::Value intros;

    // int name_count = monster_name.size();

    // printf("monster_names front: %s\n", monster_names.front().c_str());
    // std::string bonus_monster_regex = "<p class=\"f\"><b>" + monster_names.front() + "</b></p>(.+)(?=(<p class=\"f|<br |))";
    // std::regex intro(bonus_monster_regex.c_str(), std::regex_constants::extended | std::regex_constants::ECMAScript | std::regex::optimize);
    // std::vector<std::regex_token_iterator<std::string::iterator>> iterators;
    // iterators.assign(name_count, std::regex_token_iterator<std::string::iterator>(in.begin(), in.end(), intro, {1}));

    std::string bonus_monster_regex = "<p class=\"f\"><b>" + monster_name + "</b></p>(.+)(?=(<p class=\"f|<br |))";
    std::regex intro(bonus_monster_regex.c_str(), std::regex_constants::extended | std::regex_constants::ECMAScript | std::regex::optimize);
    std::vector<std::regex_token_iterator<std::string::iterator>> iterators;



    std::regex_token_iterator<std::string::iterator> b(in.begin(), in.end(), intro, {1});
    std::regex_token_iterator<std::string::iterator> rend;
    Json::Value body;
    // no while loop because it should only be called once.
    std::string tmpValue;
    if (b != rend)
    {
        tmpValue = *b++;

        body["intro"] = tmpValue;
    }

    // std::cout << "bonus body: \n" << body.toStyledString() << "\n";

    return body;


    // return;
};


std::vector<std::string> Harvester::split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

Json::Value Harvester::GetImages(std::string in)
{
    Json::Value images;

    std::regex regimg("<img.+?>");
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> b(in.begin(), in.end(), regimg);
    std::string tmpValue;
    // std::cout << "images\n";
    while (b != rend)
    {
        tmpValue = *b++;
        images.append(tmpValue);
        // std::cout << tmpValue << "\n";
    }
    return images;
}

std::string Harvester::GetTitle(std::string &in)
{
    //string to be searched
    std::string test;

    // regex expression for pattern to be searched
    std::regex regexp("<h1>(.+?)</h1>", std::regex::optimize);

    // flag type for determining the matching behavior (in this case on string objects)
    std::smatch m;

    // regex_search that searches pattern regexp in the string mystr
    std::regex_search(in, m, regexp);

    // std::cout << "tests " << test << "\n";

    // std::regex_replace(test, regexp, "[$1]");
    return std::regex_replace(m.str(1), regexp, "$1");
}

Json::Value Harvester::GetTSR(std::string &in)
{
    //string to be searched
    std::regex regexp("<p class=\"tsr\">(.*?)</p>", std::regex::optimize);
    std::regex regesc("(&diamondsuit;|&bull;|,)", std::regex::optimize);
    std::smatch m;
    std::regex_search(in, m, regexp);
    std::string test = m.str(1);
    test = std::regex_replace(test, regexp, "$1");
    test = std::regex_replace(test, regesc, ",");

    // split into vector
    std::vector<std::string> ids = split(test, ",");
    Json::Value sourceIds;
    for (std::string x : ids)
    {
        x.erase(remove(x.begin(), x.end(), ' '), x.end());
        sourceIds.append(x);
    }

    return sourceIds;
}
std::string Harvester::GetPrimaryMonster(std::string in)
{
    // get the table string
    // remove newlines
    in.erase(std::remove(in.begin(), in.end(), '\n'), in.end());

    // check monster string after removal
    // std::cout << "in: " << in << "\n";

    // Check for multitype
    // <th class="cn">(.+?)</th>
    std::regex multitypeE("<th class=\"cn\">(.+?)</th>", std::regex::optimize);
    std::smatch multitypeM;
    std::regex_token_iterator<std::string::iterator> multiRend;
    std::regex_token_iterator<std::string::iterator> multiA(in.begin(), in.end(), multitypeE, {1});
    std::vector<std::string> types;
    while (multiA != multiRend)
    {
        types.emplace_back(*multiA++);
    }
    // printf("prim: %s\n",types.back().c_str());
    return types.back();
}

Json::Value Harvester::GetStatsTable(std::string in)
{
    // printf("Getting Stats table for %s\n", in.c_str());
    Json::Value root;
    // get the table string
    // remove newlines
    // in.erase(std::remove(in.begin(), in.end(), '\n'), in.end());

    // Check for multitype
    // <th class="cn">(.+?)</th>
    std::regex multitypeE("<th class=\"cn\">(.+?)</th>", std::regex::optimize);
    std::smatch multitypeM;
    std::regex_token_iterator<std::string::iterator> multiRend;
    std::regex_token_iterator<std::string::iterator> multiA(in.begin(), in.end(), multitypeE, {1});
    int counter = 0;
    std::vector<std::string> types;
    while (multiA != multiRend)
    {
        types.emplace_back(*multiA++);
        counter++;
    }

    if (counter == 0)
    {
        // single monster
        counter = 1;
        // std::cout << "single monster\n";
        types.emplace_back(GetTitle(in));
    }
    else
    {
        // std::cout << "multitype monster with " << counter << " types\n";
    }

    std::regex_token_iterator<std::string::iterator> rend;

    std::regex catPattern("<th>(.*?):</th>", std::regex::optimize);
    std::smatch catMatch;
    std::regex_token_iterator<std::string::iterator> catIter(in.begin(), in.end(), catPattern, {1});

    std::regex statPattern("<td>(.*?)</td>", std::regex::optimize);
    std::smatch statMatch;
    std::regex_token_iterator<std::string::iterator> statIter(in.begin(), in.end(), statPattern, {1});

    Json::Value statblock;

    std::string tmpCategory;
    std::string tmpValue;
    int j = 0;
    while (catIter != rend)
    {
        tmpCategory = *catIter++;
        for (j = 0; j < counter; j++)
        {
            tmpValue = *statIter++;
            statblock[types[j]][tmpCategory] = tmpValue;
        }
    }

    // std::cout << "statblock: \n" << statblock.toStyledString() << "\n";

    return statblock;
}

std::vector<std::string> Harvester::GetTables(std::string in)
{
    std::vector<std::string> tmpVector;
    return tmpVector;
}

bool Harvester::HasPsionics(std::string &in)
{
    std::regex e("(Psionics Summary)", std::regex::optimize);

    return std::regex_search(in, e);
}

// Json::Value Harvester::GetPsionicTable(std::string in)
// {
//     Json::Value psionicTable;
//     PsionicReader psionicReader;

//     psionicTable = psionicReader.parsePowerTree(in);

//     return psionicTable;
// }

bool Harvester::IdentifyGeneralInfo(std::string in)
{
    std::regex pattern("<h1>(.+?)General Information</h1>", std::regex::optimize);
    // std::cout << in << "\n";
    // std::cout << "search for general information: " << result << "\n";

    return std::regex_search(in, pattern);
}

// std::string Harvester::PruneImages(std::string &in)
// {
//     std::regex imggex("<img.+?>", std::regex::optimize);
//     std::string returnstr = std::regex_replace(in, imggex, "");

//     return returnstr;
// }

bool Harvester::HasList(std::string in)
{
    std::regex listregex("<ul>([^]+?)</ul>", std::regex::optimize);
    return std::regex_search(in, listregex);
}

Json::Value Harvester::ParseList(std::string in)
{
    Json::Value textList;
    std::regex listregex("<ul>");
    return textList;
}

int Harvester::GetNumberTypes(std::string in)
{
    std::regex multitypeE("<th class=\"cn\">(.+?)</th>", std::regex::optimize);
    std::smatch multitypeM;
    std::regex_token_iterator<std::string::iterator> multiRend;
    std::regex_token_iterator<std::string::iterator> multiA(in.begin(), in.end(), multitypeE, {1});
    int counter = 0;
    std::vector<std::string> types;
    while (multiA != multiRend)
    {
        types.emplace_back(*multiA++);
        counter++;
    }

    if (counter == 0)
    {
        // single monster
        counter = 1;
        if (debug)
            std::cout << "single monster\n";
        types.emplace_back(GetTitle(in));
    }
    else
    {
        if (debug)
            std::cout << "multitype monster with " << counter << " types\n";
    }

    return counter;
}


void Harvester::LaunchThread(std::set<std::string> monsterNames){
    printf("launched thread. set size %i \n", (int)monsterNames.size());
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    int64_t time_diff;

    // std::vector<std::string> warning_monsters;
    int result = 0;
    for (std::string entry : monsterNames)
    {
        // std::cout << "Harvesting:\t" + entry << "\n";
        begin = std::chrono::steady_clock::now();
        result = RunMonster(entry);
        // if(result == 2){
        //     warning_monsters.emplace_back(entry);
        // }
        end = std::chrono::steady_clock::now();
        time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        // if (time_diff > 200)
            // printf("[%s] diff\t%zu [ms]\n", entry.c_str(), time_diff);
            // printf("*****\n");
    }
    printf("Warning monsters:\n");
    // for(std::string monster : warning_monsters){
    //     // printf("\t%s\n",monster.c_str());
    // }
}

/**
 * @brief Run the harvester on ALL monsters in cmm. 
 * Acts as the deploy function. 
 * Writes all the monsters to json files
 * 
 */
void Harvester::HarvestAll(bool threaded)
{
    std::cout << "Harvesting all!\n";
    printf("Harvesting All\n");
    auto full_start = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::high_resolution_clock::now();

    special_statblocks.fill_statblocks();


    std::set<std::string> skip = {
        // "modron",
        // "calldark",
        // "human",
        // "bird",
        // "fish",
        // "dragosea",
        // "dragorso",
        // "dragospi",
        "index"};

    std::set<std::string> searchingMonsterNames;
    std::set_difference(monsterNames.begin(), monsterNames.end(), skip.begin(), skip.end(),
                        std::inserter(searchingMonsterNames, searchingMonsterNames.begin()));

    std::vector<std::string> warning_monsters;

    if(threaded){
        // divide names.
        // get how many threads
        // how many names.

        int NUM_THREADS = 8;
        std::thread* threads[8];
        std::set<std::string> thread_sets[8];

        // split the set of names into 12 groups.
        //  get size of set
        int data_size = searchingMonsterNames.size();
        int i = 0;
        // n-1 group sizes: set_size / NUM_THREADS
        // nth group size: set_size % NUM_THREADS
        int set_sizes = data_size / NUM_THREADS;
        int last_set_size = data_size % NUM_THREADS;

        // iteratoring over set items?
        // count to set_sizes, then increment the set (start filling next set)
        // find what set this monster will be added to, then put it there.
        int total_index = 0;
        int n_set = 0;
        int n_index = 0;
        bool last = 0;
        printf("making %i sets of size %i and one set of size %i to fill %i items\n", NUM_THREADS - 1, set_sizes, last_set_size, data_size );

        std::set<std::string>::iterator itr;
        for (itr = searchingMonsterNames.begin(); itr != searchingMonsterNames.end(); itr++)
        {
            // printf("total_index: %i\tn_index: %i\tn_set: %i\t\n", total_index, n_index, n_set);
            thread_sets[n_set].emplace(*itr);

            if(last){
                // printf("last\n");
                if (n_index == last_set_size - 1){
                    // very last entry
                } else {
                    n_index++;
                }
            } else {
                if (n_index == set_sizes - 1){
                    n_set++;
                    n_index = 0;
                    // if next set will be last, set as last
                    if(n_set == NUM_THREADS-1){
                        last = 1; 
                    }
                } else {
                    n_index++; 
                }
            }
            total_index++;
        }

        int index = 0;

        for( const std::set<std::string> &set : thread_sets){
            printf("set size %zu\n", set.size());
            threads[index] = new std::thread(&Harvester::LaunchThread, this, set );
            index++;
        }

        // std::this_thread::sleep_for (std::chrono::seconds(1));

        for (int th = 1; th < NUM_THREADS; th++)
        {
            printf("joining thread %i\n", th);
            threads[th]->join();
        }
        threads[0]->join();
        printf("End of thread join\n");
    } else { // Single thread, contiguously
        for (std::string entry : searchingMonsterNames)
        {
            // printf("Harvesting:\t%s\n", entry.c_str());
            // if(skip.find(entry))
            RunMonster(entry);
            // i++;
            // if (i == 10)
            // {
            //     SaveCategories();
            //     break;
            // }
        }
    }
    
    printf("Processed monsters: %i\n", (int)searchingMonsterNames.size());
    // Print emptyMonsterKeys
    // emptyMonsterKeys.print();

    printf("Skipping emptyMonsterKeys until I can figure out why Docker isn't playing nice.\n");

    // Json::Value emptyKeys;
    // add emptyMonsterKeys to json
    // for (std::string key : emptyMonsterKeys.getArray()){
    //     emptyKeys.append(key);
    // }

    // printf("Calling Saving Empty Keys\n");

    // SaveMonsterJson("AA_EmptyKeys", emptyKeys);

    // Save emptyMonsterkeys

    // Save master json file
    ExportAPIJson(monsterData.GetJson());
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - full_start);
    // std::cout << "Duration:" << duration.count() << std::endl;
}

void Harvester::ExportAPIJson(Json::Value monster_json){
    Json::Value json_list;
    Json::Value tmp_json;
    Json::Value keys_titles;
    Json::Value catalog_books;
    Json::Value all_sources;
    Json::Value all_sources_settings; //?

    // Read in /data/sortedtsr.json
    // printf("Reading in sortedtsr.json\n");
    // std::ifstream sortedtsr_file("../data/sortedtsr.json");
    // Json::Value publish_id_to_title;
    // sortedtsr_file >> publish_id_to_title;

    printf("Reading in all_tsr.json\n");
    std::ifstream alltsr_file("../data/all_tsr.json");
    Json::Value all_tsr;
    alltsr_file >> all_tsr;

    // printf("Reading in settings.json\n");
    // std::ifstream settingsjson_file("../data/settings.json");
    // Json::Value settings_json;
    // alltsr_file >> settings_json;

    Json::Value tmp_book;
    Json::Value catalog_new;
    Json::Value tmp_catalog;

    printf("Export API JSON\n");
    for(auto entry : monster_json.getMemberNames()){
        // Iterates through every monster
        // printf("Monster: %s\t", entry.c_str());
        tmp_json["monster_key"] = entry;
        tmp_json["monster_data"] = monster_json[entry];
        tmp_json["sources"] = monster_json[entry]["TSR"];

        for(auto statblock_entry : monster_json[entry]["statblock"].getMemberNames()){
            tmp_json["statblock_names"].append(statblock_entry);
        }
        
        tmp_json["statblock_names"].clear();
        tmp_json["title"] = monster_json[entry]["title"];
        
        keys_titles[entry] = monster_json[entry]["title"];
        // printf("key %s | title %s \n",entry.c_str(), monster_json[entry]["title"].asString().c_str() );

        json_list.append(tmp_json);

        // Catalog
        // catalog_books is an array of objects of type
        // {
        //    "publish_id": string,
        //    "title": string,
        //    "monster_keys": string[]
        // }
        for(auto source : monster_json[entry]["TSR"]){
            // check if source is in catalog_books
            // printf("Source: %s\t", source.asString().c_str());
            // sanitize dungeon and dragon magazine names
            // remove " #" and "#" from within the string
            std::string source_sanitized = source.asString();
            source_sanitized.erase(std::remove(source_sanitized.begin(), source_sanitized.end(), ' '), source_sanitized.end());
            source_sanitized.erase(std::remove(source_sanitized.begin(), source_sanitized.end(), '#'), source_sanitized.end());
            bool found = 0;

            // Setting
            // monsterJson["setting"]

            for(auto &book : catalog_books){
                if(book["publish_id"] == source_sanitized){
                    found = 1;
                    book["monster_keys"].append(entry);

                }
            }
            if(!found){
                // new source, add to all_sources
                all_sources.append(source_sanitized);
                // printf("New source: %s\n", source_sanitized.c_str());
                tmp_book = Json::Value();
                tmp_book["publish_id"] = source_sanitized;
                // tmp_book["title"] = publish_id_to_title[source_sanitized];

                Json::Value book_object = all_tsr[source_sanitized];
                if(book_object.isNull()){
                    printf("book object was null with tsr: %s\n", source_sanitized.c_str());
                } else {
                    tmp_book["title"] = all_tsr[source_sanitized]["title"];
                }
                // printf("all_tsr[source] %s \n", all_tsr.toStyledString().c_str());
                // printf("attempting\n");
                // std::cout << "all_tsr " << all_tsr.toStyledString() << std::endl;
                tmp_book["author"] = all_tsr[source_sanitized]["author"];
                tmp_book["year"] = all_tsr[source_sanitized]["year"];
                tmp_book["monster_keys"].append(entry);
                // tmp_book["setting"] = monster_json[entry]["setting"];
                tmp_book["setting"] = all_tsr[source_sanitized]["setting"];
                catalog_books.append(tmp_book);
            }
        }
        // printf("\n");
    }
    printf("Saving Catalog\n");
    // Catalog path
    std::string catalog_path = std::filesystem::current_path().string() + "/../data/Full_Catalog.json";
    SaveJsonToPath(catalog_path, catalog_books);


    SaveMonsterJson("AA_Full_Catalog", catalog_books);
    SaveMonsterJson("AA_All_Sources", all_sources);

    printf("after loop\n");

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/AA_ALL_MONSTERS.json";
    // std::string filename = std::filesystem::current_path().string() + "/../data/ALL_MONSTERS.json";
    std::cout << "\t saving to: " << filename << "\n";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer->write(json_list, &outputFileStream);

    // Save key_titles json file
    SaveJsonToPath(std::filesystem::current_path().string() + "/../data/AA_KEYS_TITLES.json", keys_titles);
    SaveMonsterJson("AA_KEY_TITLES", keys_titles);
};



void Harvester::PrintCatalogue()
{
    std::cout << "Printing Catalogue\n";
    std::cout << Catalogue.toStyledString() << "\n";
}

void Harvester::SaveStatistics(){
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/AA_Statistics.json";
    std::cout << "\t saving to: " << filename << "\n";
    Json::Value monster_data = monsterData.GetJson();
    // The JSON file
    Json::Value statistics;

    Json::Value settings_count;
    Json::Value books_count;
    Json::Value pages_count;
    Json::Value unique_count;

    // get the Length of BookCategories
    int setting_count = BookCategories.size();
    std::cout << "Total Settings: " << setting_count << std::endl;
    settings_count["stat_key"] = "settings_count";
    settings_count["stat_value"] = setting_count; // ... implement

    // Length of Catalogue
    int catalogue_count = Catalogue.size();
    std::cout << "Total Books: " << catalogue_count << std::endl;
    books_count["stat_key"] = "books_count";
    books_count["stat_value"] = catalogue_count; // ... implement

    std::cout << "Total Pages: " << monster_data.size() << std::endl;
    pages_count["stat_key"] = "pages_count";
    pages_count["stat_value"] = monster_data.size();
    // Length of monster_data

    // For each monster in monsterData.GetJson();
    // check if it has the field "statblock_names"
    // if it does, then add the length of that array to unique_monsters
    int unique_monsters = 0;
    
    for(auto monster : monster_data.getMemberNames()){
        for(auto statblock_entry : monster_data[monster]["statblock"].getMemberNames()){
            unique_monsters++;
        }
    }

    unique_count["stat_key"] = "unique_count";
    unique_count["stat_value"] = unique_monsters; // ... implement

    std::cout << "Total Unique Monsters: " << unique_monsters << std::endl;

    // Combine Json's
    statistics.append(settings_count);
    statistics.append(books_count);
    statistics.append(pages_count);
    statistics.append(unique_count);


    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer->write(statistics, &outputFileStream);

    // Output good one
    return;
}

void Harvester::SaveCatalogue()
{
    std::cout << "Saving Catalogue\n";
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/AA_Catalogue.json";
    std::cout << "\t saving to: " << filename << "\n";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer->write(Catalogue, &outputFileStream);
    return;
}

void Harvester::SaveCategories()
{
    std::cout << "Saving Categories\n";
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/AA_Categories.json";
    // std::cout << "\t saving to: " << filename << "\n";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer->write(BookCategories, &outputFileStream);
}

std::string Harvester::GetCategory(std::string imgString)
{
    std::string category;

    //<img src="grf/sj.gif" width="150" height="75" border="0" alt="Spelljammer" title="Spelljammer" align="right">
    std::regex r("title=\"(.+?)\"");
    std::smatch m;
    std::regex_search(imgString, m, r);
    category = m.str(1);

    return category;
}


// custom split function for dividing a string into 3 parts, split at <body> and </body>
std::vector<std::string> split(std::string str, std::string token)
{
    std::vector<std::string>result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != std::string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}


std::string Harvester::GetFullBody(std::string in, std::string monster_key){
    if(debug)
        printf("Getting Full Body\n");
    // make a copy of in
    std::string monsterString = in;

    monsterString = std::regex_replace(monsterString, std::regex("</body>"), "<body>");
    

    if(debug)
        printf("splitting\n");
    Json::Value::Members splitTestResultMembers = split(monsterString, "<body>");
    std::string splitTestResult;
    if(splitTestResultMembers.size() > 1){
        if(debug)
            printf("Getting split results\n");
        splitTestResult = splitTestResultMembers[1];
        if(debug)
            printf("done\n");
        // if(debug)
        //     std::cout << "SplitTestResult " <<  splitTestResult << "]\n";

    } else {
        std::cerr << "Invalid Json split. for " << monster_key << "\n" << monsterString << "\n";
    }
    // Works, matches the two line breaks until the end.
    std::regex r("\r\n\r\n.+", std::regex::extended);
    std::smatch m;
    if(debug)
        printf("Split Searching\n");
    std::regex_search(splitTestResult, m, r);
    
    
    if(m.size() == 0){
        if(debug)
            printf("No double newlines. Likely a monster that does not have data yet.\n");
        // trying again?
        // if in contains the string "/img/spc/unknown.gif"
        // then return ""
        
        // push into emptyMonsterKeys
        emptyMonsterKeys.push_back(monster_key);

        if(in.find("/img/spc/unknown.gif") != std::string::npos){
            return "";
        }
        
        // printf("in %s\n", in.c_str());
        // printf("m.size(): %zu\n", m.size());
        // printf("m.str(): \n[%s]\n", m.str(0).c_str());
        // return "";
    }

    if(debug)
        printf("After split\n\n");

    

    std::string trimmedString = std::regex_replace(splitTestResult, r, "");
    // printf("trimmedString: \n[%s]\n", trimmedString.c_str());

    // Now try splitting by newline. now we have a vector. and we can remove the last x elements
    std::vector<std::string> splitByNewline = split(splitTestResult, "\n");
    // printf("splitByNewline.size(): %zu\n", splitByNewline.size());
    if (debug)
        printf("splitResult size: %zu", splitByNewline.size());
    // remove the last 3 elements
    splitByNewline.erase(splitByNewline.end() - 4, splitByNewline.end());
    // printf("splitByNewline.size(): %zu\n", splitByNewline.size());

    // preview first 5 elements
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("splitByNewline[%d]: \n[%s]\n", i, splitByNewline[i].c_str());
    // }

    // remove first 5 elements
    splitByNewline.erase(splitByNewline.begin(), splitByNewline.begin() + 5);

    if(debug)
        printf("replaced body\n");

    // combine back into string
    std::string combinedString;
    for(int i = 0; i < splitByNewline.size() - 4; i++){
        combinedString += splitByNewline[i] + "\n";
    }

    // printf("combinedString: \n[%s]\n", combinedString.c_str());

    // splitTestResult = std::regex_replace(splitTestResult, std::regex("\n\n(.|\n)+"), "");
    // splitTestResult = std::regex_replace(splitTestResult, std::regex("\n *"), "");

    // replace these three lines with ""
    // <hr.*?> first and second match
    // <img .*?> first match
    std::string updatedString;
    
    // <hr> 's
    updatedString = std::regex_replace(combinedString, std::regex("<hr.*?>"), "");

    // If needs image
    // img/cloaker.gif
    std::string needs_img_regex_str = "img/" + monster_key + ".gif"; 
    // std::regex(needs_img_regex_str);
    // 
    // if()
    if(in.find(needs_img_regex_str) != std::string::npos){
        updatedString = std::regex_replace(updatedString, std::regex("<img.*?>"), "", std::regex_constants::format_first_only);
    } else {
        // doesn't need to replace the first image
    }

    // First img
    // printf("updatedString: \n[%s]\n", updatedString.c_str());
    
    // Replace \r\n and such
    updatedString = std::regex_replace(updatedString, std::regex("\\r\\n +"), "");
    updatedString = std::regex_replace(updatedString, std::regex("\\n +"), "");
    // printf("updatedString: \n[%s]\n", updatedString.c_str());
    // printf("Split test result: %s\n", splitTestResult.c_str());

    return updatedString;
};

// Remove .html from 
std::string SanitizeLinks(std::string in){
    // regex replace .html with ""
    std::string out = std::regex_replace(in, std::regex("(\\w+?)[.]html"), "/appendix/$1");
    // if(debug)
    //     printf("Sanitized: %s\n", out.c_str());
    return out;
}

std::vector<std::string> statblock_special_monsters{
    // Excluding bird because all listed monsters have existing pages will full statblocks
    "bird", 
    "fish"
    "human",
    "insect",
    "lycanthg",
    // "mammal",
    "mammgian",
    "mammher2",
    // "mammmini",
    // "mammsmal",
    // "modron",
    "snake",
    "human",
    "modron",
    "mammal",
    "mammmini",
    "mammsmal"
};


/**
 * @brief Runs the harvester on one target monster file.
 * 
 * @param monsterName name of the monster html file without the .html extension
 */
int Harvester::RunMonster(std::string monsterName)
{
    // std::chrono::steady_clock::time_point begin;
    // std::chrono::steady_clock::time_point end;
    int64_t time_diff;

    // basically "for" loop entry for monsterName.
    printf("Processing monster: %s\n", monsterName.c_str());
    std::string monsterString;
    std::string monster_filename = monsterName + ".html";
    if(hasMonsterString(monster_filename)){
        monsterString = getMonsterString(monster_filename);
    } else {
        std::cerr << "Monster string not found for monster key: " << monsterName << "\n";
        exit(1);
    }
    // std::cout << "file string: " << monsterString << "\n   ";
    int return_code = 0;

    if(debug)
        printf("Running: %s\n", monsterName.c_str());

    // Just try getFullBody
    // std::string fullBody = GetFullBody(monsterString);
    // std::cout << "full body: " << fullBody << "\n   ";

   

    std::string category;
    Json::Value monsterJson;
    Json::Value blank;
    std::string sanitizedString = SanitizeLinks(monsterString);
    if(debug)
        printf("sanitized links\n");
    
    if(debug)
        std::cout << "getting full body\n";// << sanitizedString << "\n";

    monsterJson["fullBody"] = GetFullBody(sanitizedString, monsterName);
    if(debug)
        printf("got full body\n");
    monsterJson["title"] = GetTitle(monsterString);
    if(debug)
        printf("got title\n");
    monsterJson["TSR"] = GetTSR(monsterString);
    if(debug)
        printf("got tsr\n");
    monsterJson["images"] = GetImages(monsterString);
    if(debug)
        printf("got images\n");

    

    // Check if it's from Dragon Magazine to skip it
    for (auto x : monsterJson["TSR"])
    {
        {
            // if (!x.asString().find("Dragon#"))
                // std::cout << " - Dragon Mag, skipped\n";
                // return_code = 4;
                // return 4;
        }

        // Add monster to catalogue
        Catalogue[x.asString()].append(monsterName);
    }
    // Get category
    category = GetCategory(monsterJson["images"][0].asString());
    monsterJson["setting"] = category;
    // printf("Category: %s\n", category.c_str());

    auto existingBooks = BookCategories[category];

    Json::Value tsrs = monsterJson["TSR"];
    // std::cout << "category: " << category << "\n";
    std::vector<Json::Value> res;
    std::vector<std::string> existingInCategory;
    bool entryFound = false;
    // Check if tsrs is an array or singular

    // begin = std::chrono::steady_clock::now();    
    if (!tsrs.empty())
    {
        if (tsrs.isArray())
        {
            std::vector<std::string> tsr_elems;
            for (auto x : tsrs)
            {
                tsr_elems.emplace_back(x.asCString());
            }

            if (BookCategories[category].isArray())
            {
                for (auto x : BookCategories[category])
                {
                    existingInCategory.emplace_back(x.asCString());
                }
            }

            for (std::string y : tsr_elems)
            {
                if (std::find(existingInCategory.begin(), existingInCategory.end(), y) == existingInCategory.end()){
                    BookCategories[category].append(y);
                }
            }
        }
        else
        {
            if (!(BookCategories[category].get(tsrs.asCString(), Json::nullValue)))
            {
                BookCategories[category].append(tsrs.asCString());
            }
        }
    }
    
    // end = std::chrono::steady_clock::now();
    // time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    // printf("[%s] - tsrs \t%zu [ms]\n", monsterName.c_str(), time_diff);

    // Prune images
    if (debug)
        std::cout << "pruning images\n";
    // begin = std::chrono::steady_clock::now();

    // monsterString = PruneImages(monsterString);
    // end = std::chrono::steady_clock::now();
    // time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    // printf("[%s] - pruneimg \t%zu [ms]\n", monsterName.c_str(), time_diff);

    // begin = std::chrono::steady_clock::now();
    // General Information ID
    if(debug)
        std::cout << "GeneralInfo\n";
    if (IdentifyGeneralInfo(monsterString))
    {
        // std::cout << "parsing general\n";
        // Json::Value generalJson = ParseGeneral(monsterString);
        // monsterJson["general"] = generalJson;
    }
    else
    {
        if(debug)
            std::cout << "Getting Stats Table\n";
        if (std::find(std::begin(statblock_special_monsters), std::end(statblock_special_monsters), monsterName) != std::end(statblock_special_monsters)){
            // Inelegant but decisive and reliable solution
            // Switch statement for each of the special monsters
            // "human"
            // "insect"
            // "lycanthg"
            // "mammal"
            // "mammgian"
            // "mammher2"
            // "mammmini"
            // "mammsmal"
            // "modron"
            // "snake"
            printf("statblock_special! %s\n", monsterName.c_str());
            if (monsterName == "human"){
                monsterJson["statblock"] = special_statblocks.statblock_human;
            }else if (monsterName == "insect"){
                monsterJson["statblock"] = special_statblocks.statblock_insect;
            }else if (monsterName == "lycanthg"){
                // Not yet implemented
                // monsterJson["statblock"] = special_statblocks.statblock_lycanthg;
            }else if (monsterName == "mammal"){
                monsterJson["statblock"] = special_statblocks.statblock_mammal;
            }else if (monsterName == "mammgian"){
                monsterJson["statblock"] = special_statblocks.statblock_mammgian;
            }else if (monsterName == "mammher2"){
                monsterJson["statblock"] = special_statblocks.statblock_mammher2;
            }else if (monsterName == "mammmini"){   
                monsterJson["statblock"] = special_statblocks.statblock_mammmini;
            }else if (monsterName == "mammsmal"){
                monsterJson["statblock"] = special_statblocks.statblock_mammsmal;
            }else if (monsterName == "modron"){
                monsterJson["statblock"] = special_statblocks.statblock_modron;
            }else if (monsterName == "snake"){
                monsterJson["statblock"] = special_statblocks.statblock_snake;
            }else {
                // Should not reach
            } 
        
        } else {
            Json::Value statblock = GetStatsTable(monsterString);
            monsterJson["statblock"] = statblock;
        }

        // end = std::chrono::steady_clock::now();
        // time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        // // printf("[%s] - GetStatsTable \t%zu [ms]\n", monsterName.c_str(), time_diff);


        

        // Json::Value psionics;
        // Json::Value psionicTable;
        // if (HasPsionics(monsterString))
        // {
        //     if (debug)
        //         std::cout << "has psionics\n";

        //     PsionicReader psionicReader;
        //     psionicReader.debug = debug;

        //     psionics = psionicReader.parsePowerTree(monsterString);
        //     monsterJson["psionics"] = psionics;

        //     // prune psionic table
        //     if (debug)
        //         std::cout << "pruning psionics\n";
        //     monsterString = psionicReader.prunePsionics(monsterString);

        //     if (debug)
        //         std::cout << "pruned psionics\n";
        // }

        // // Check how many types there are
        // int numTypes;
        // numTypes = GetNumberTypes(monsterString);
        // std::cout << "numtypes: " << numTypes << "\n";

        // parse h2 headers for multimonsters
        // if(debug)
        //     printf("[%s] - GenStart \t%zu [ms]\n", monsterName.c_str(), time_diff);

        
       // Begin removing nonessential code now that the full body can be rendered

        // Instead, extract parts of monsterString as blocks of text
        // BlockHarvester blockHarvester(monsterString);
        // std::vector<std::string> body_blocks = blockHarvester.parseFunction(monsterString);
        // Json::Value bodyBlocks;

        // // iterate through body_blocks in order, append to bodyBlocks
        // for (auto x : body_blocks)
        // {
        //     bodyBlocks.append(x);
        // }


        // // Put the body blocks into monsterJson
        // monsterJson["bodyBlocks"] = bodyBlocks;


        // Json::Value multitypeHeaderData = ExtractH2s(monsterString);
        // for( auto t : multitypeHeaderData){
        //     // std::cout << ": " << t.asString() << "\n";
        //     boost::replace_all(monsterString, t.asString(), "");
        // }
        // printf("modified string: %s\n", monsterString.c_str());
        
        // printf("[%s] - H2s \t%zu [ms]\n", monsterName.c_str(), time_diff);

        // if(!statblock.isNull()){
        //     std::vector<std::string> memberNames = multitypeHeaderData.getMemberNames();
        //     if (debug)
        //         std::cout << "membernames size " << memberNames.size() << "\n";
        //     // if there are h2's
        //     if (memberNames.size() > 0)
        //     {
        //         // std::cout << "H2 member\n";
        //         begin = std::chrono::steady_clock::now();
        //         for (std::string x : memberNames)
        //         {
        //             // printf("member: %s\n", x.c_str());
        //             monsterJson["body"][x] = GetBody(multitypeHeaderData[x].asCString());
        //         }
        //         // Get Intro
        //         monsterJson["body"]["main"] = GetBody(monsterString);
        //         end = std::chrono::steady_clock::now();
        //         time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        //         // printf("[%s] - GetBodys \t%zu [ms]\n", monsterName.c_str(), time_diff);

                
        //     }
        //     else if (numTypes != memberNames.size() && numTypes > 1){ // multi-type but no headers. Check for afterwards
        //         // printf("types/memberNames mismatch %i != %zu | \n", numTypes, memberNames.size());
        //         // monsterJson["body"] = GetBody(monsterString);
        //         // get names from statblock keys
        //         std::vector<std::string> statblock_monster_names = statblock.getMemberNames();
        //         // Do first, "primary" monster's body
        //         std::string primary_monster = GetPrimaryMonster(monsterString);
        //         monsterJson["body"][primary_monster] = GetBody(monsterString);
        //         // pop front
        //         // statblock_monster_names.erase(statblock_monster_names.);
        //         // printf("about to erase\n");
        //         // statblock_monster_names.erase(std::remove(statblock_monster_names.begin(), statblock_monster_names.end(), primary_monster), statblock_monster_names.end());
        //         // printf("erased\n");
        //         // bad code, only works for 1 extra. Will see where there are errors
        //         for (std::string x : statblock_monster_names){
        //             // printf("monster: %s_%s\n", monsterJson["title"].asCString(), x.c_str());
        //             monsterJson["body"][x] = GetBonusMonsters(monsterString, x );
        //         }
        //     }
        //     else
        //     { // single type
        //         if (debug)
        //             std::cout << "getting body\n";
        //         std::string single_monster_name;
        //         single_monster_name = statblock.getMemberNames()[0];
        //         monsterJson["body"][single_monster_name] = GetBody(monsterString);
        //         if (debug)
        //             std::cout << "body: " << monsterJson["body"] << "\n";
        //     }
        //     int numBodies;
        //     numBodies = monsterJson["body"].size();
        //     if(numTypes != numBodies){
        //         // printf("type-body mismatch %i != %i | \n", numTypes, numBodies);
        //     }

        // } else {
        //     printf("\t[Warning] null statblock for %s\n", monsterName.c_str());
        //     return_code = 2;
        // }
    }
    // end = std::chrono::steady_clock::now();
    // time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    // printf("[%s] - general info tree \t%zu [ms]\n", monsterName.c_str(), time_diff);

    

    // Json::Value monsterDataJson;
    // monsterDataJson[monsterName] = monsterJson;
    // append this monster to all monster json

    // monsterData[monsterName] = monsterJson;
    // printf("Count of monsterData: %i \n", monsterData.size());
    if(debug)
        std::cout << "Adding " << monsterName << " Json data to monsterData\n";
    monsterData.AddMonster(monsterName, monsterJson);

    // Save json file
    // SaveMonsterJson(monsterName, monsterJson);

    // printf("Processed monster: %s\n", monsterName.c_str());
    // printf("\tEnding monster\n");

    return return_code;
}

Json::Value Harvester::HarvestNickNames()
{
    Json::Value namesJson;
    Json::Value namesToLinksJson;
    std::string indexFilename = std::filesystem::current_path().string() + "/bin/monster_files/_index.html";

    std::string indexString = ReadFileIntoString2(indexFilename);

    // search string

    std::regex r("<a href=\"(?=[^_])(.+?).html\">(.+?)</a>");

    std::regex_token_iterator<std::string::iterator> a(indexString.begin(), indexString.end(), r, {1, 2});
    std::regex_token_iterator<std::string::iterator> rend;
    std::string tmpMonster;
    std::string tmpName;

    while (a != rend)
    {
        tmpMonster = *a++;
        tmpName = *a++;
        namesJson[tmpMonster].append(tmpName);
        namesToLinksJson[tmpName] = tmpMonster;
    }

    // Go through it again to structure into new json
    Json::Value all_names;
    Json::Value tmp_name;

    for (Json::ValueIterator itr = namesJson.begin(); itr != namesJson.end(); itr++)
    {
        std::string monsterName = itr.key().asString();
        Json::Value monsterNames = namesJson[monsterName];

        tmp_name["monster_key"] = monsterName;
        tmp_name["titles"] = monsterNames;
        all_names.append(tmp_name);

        // for (Json::ValueIterator itr2 = monsterNames.begin(); itr2 != monsterNames.end(); itr2++)
        // {
        //     std::string name = itr2->asString();
        //     all_names[name] = monsterName;
        // }
    }

    SaveMonsterJson("AA_Monsterkey_titles", all_names);
    SaveMonsterJson("AAA_NAMES", namesJson);
    SaveMonsterJson("AAA_NAMESTOLINKS", namesToLinksJson);
    return namesJson;
}

void Harvester::SaveJsonToPath(std::string jsonPath, Json::Value jsonValue)
{
    if(debug){
        std::cout << "Saving monster Json for " << jsonPath << "\n";
    }
    // printf("Saving monster json: %s\n", monsterName.c_str());
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    // std::string filename = std::filesystem::current_path().string() + "/bin/json_files/" + monsterName + ".json";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/" + jsonPath + ".json";
    if(debug){
        std::cout << "MonsterJson: " << jsonValue.toStyledString() << "\n";
        std::cout << "\t saving to: " << filename << "\n";
    }


    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    // Open the file
    std::ofstream outputFileStream;
    outputFileStream.open(jsonPath);
    if(outputFileStream.is_open()){
        writer->write(jsonValue, &outputFileStream);
    } else {
        std::cout << "Unable to open json file for writing\n";
    }
    outputFileStream.close();

}

void Harvester::SaveMonsterJson(std::string monsterName, Json::Value monsterJson)
{
    if(debug){
        std::cout << "Saving monster Json for " << monsterName << "\n";
    }
    // printf("Saving monster json: %s\n", monsterName.c_str());
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    // std::string filename = std::filesystem::current_path().string() + "/bin/json_files/" + monsterName + ".json";
    std::string filename = std::filesystem::current_path().string() + "/bin/json_files/" + monsterName + ".json";
    if(debug){
        std::cout << "MonsterJson: " << monsterJson.toStyledString() << "\n";
        std::cout << "\t saving to: " << filename << "\n";
    }


    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    // Open the file
    std::ofstream outputFileStream;
    outputFileStream.open(filename);
    if(outputFileStream.is_open()){
        writer->write(monsterJson, &outputFileStream);
    } else {
        std::cout << "Unable to open json file for writing\n";
    }
    outputFileStream.close();

}

std::vector<std::string> Harvester::GetUniqueTSRList()
{
    std::vector<std::string> tsr_ids;
    std::string path = "monster_files";
    std::string tmpPath;
    std::cout << "Getting unique TSR...\n";
    Json::Value tsrTemp;
    for (auto entry : monsterNames)
    {
        tsrTemp = GetTSR(monsterStringContentsMap[entry]);
        // std::cout << tsrTemp << "\n";
        for (auto item : tsrTemp)
        {
            if (std::find(tsr_ids.begin(), tsr_ids.end(), item.asString()) == tsr_ids.end())
            {
                tsr_ids.emplace_back(item.asString());
                std::cout << entry << ": " << item.asString() << "\n";
            }
        }
    }

    // std::cout << "unique tsr ids:\n";
    for (std::string i : tsr_ids)
    {
        // std::cout << i << "\n";
    }
    return tsr_ids;
}

/**
 * 
 * Main big method that extracts all the data.
 * 
 */
int Harvester::GetFileData()
{
    std::string path = std::filesystem::current_path().generic_string() + "/bin/monster_files";
    std::string tmpPath;
    std::string tmpString;
    std::cout << "Reading monster files in " << path << " ...\n";
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.path().extension() == ".html" || entry.path().extension() == ".php")
        {
            if (entry.path().filename().string().at(0) != '_')
            {
                // std::cout << entry.path().filename().string() << "\n";
                filenames.emplace_back(entry.path().filename().string());
                filepaths.emplace_back(entry.path());

                tmpPath = entry.path().string();
                tmpString = entry.path().filename().replace_extension("").string();
                monsterStringContentsMap.emplace(entry.path().filename().string(), ReadFileIntoString2(tmpPath));
                monsterNames.insert(entry.path().filename().replace_extension("").string());
                // std::cout << "path: " << tmpString << "\n";
            }
        }
    }
    std::cout << "Monster files read.\n";
    std::cout << "monster names:\n";

    std::cout << "Testing Character: " << "×" << "\n";

    for (std::string x : monsterNames)
    {
        // std::cout << x << "\n";
    }

    return 0;
}

void Harvester::PrintMap()
{
}

std::string Harvester::ReadFileIntoString2(const std::string &path)
{
    // Locale stuff
    std::locale loc;
    const std::codecvt<wchar_t,char,mbstate_t>& myfacet = 
    std::use_facet<std::codecvt<wchar_t,char,mbstate_t> >(loc);
    // std::cout << "Characteristics of codecvt<wchar_t,char,mbstate_t>:\n";
    // std::cout << "Encoding: " << myfacet.encoding() << '\n';
    // std::cout << "Always noconv: " << myfacet.always_noconv() << '\n';
    // std::cout << "Max length: " << myfacet.max_length() << '\n';

    // std::cout << "read path: " + path + "\n";
    auto ss = std::ostringstream{};
    std::ifstream input_file(path);
    if (!input_file.is_open())
    {
        std::cerr << "Could not open the file - '"
                  << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

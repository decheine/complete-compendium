#include <map>
#include <iostream>
#include <regex>

#include "psionic_reader.h"

enum StringValue
{
    clairsentienceVal,
    psychokinesisVal,
    psychometabolismVal,
    psychoportationVal,
    telepathyVal,
    metapsionicsVal
};

static std::map<std::string, StringValue> s_mapStringValues;

/**
 * @brief 
 * 
 * @param in 
 * @return Json::Value 
 * 
 * Psionic Json will look like
 * {
 *      "table":
 *      {
 *          "Level": 1,
 *          "Powers":
 *          {
 *              "Dis": 4,
 *              "Sci": 5,
 *              "Dev": 15
 *          },
 *          "Attack/Defense":
 *          {
 *              "Attack": "EW, II",
 *              "Defense": "All"
 *          },
 *          "Score": "Int",
 *          "PSPs": "1d10+250"
 *      }
 *      "powers":
 *       {
 *          "Clairsentience":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          },
 *          "Psychokinesis":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          },
 *          "Psychometabolism":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          },
 *          "Psychoportation":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          },
 *          "Telepathy":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          },
 *          "Metapsionics":
 *          {
 *              "Sciences": {}, 
 *              "Devotions": {}
 *          }
 *       }
 * }
 */
Json::Value PsionicReader::parsePowerTree(std::string in)
{
    if (debug)
        std::cout << "parsing power tree\n";
    Json::Value root;
    // set up json tree

    Json::Value table;

    Json::Value disscidev;

    Json::Value attdef;

    Json::Value powers;

    Json::Value clairsentience;
    Json::Value psychokinesis;
    Json::Value psychometabolism;
    Json::Value psychoportation;
    Json::Value telepathy;
    Json::Value metapsionics;

    clairsentience["Sciences"] = "";
    psychokinesis["Sciences"] = "";
    psychometabolism["Sciences"] = "";
    psychoportation["Sciences"] = "";
    telepathy["Sciences"] = "";
    metapsionics["Sciences"] = "";

    clairsentience["Devotions"] = "";
    psychokinesis["Devotions"] = "";
    psychometabolism["Devotions"] = "";
    psychoportation["Devotions"] = "";
    telepathy["Devotions"] = "";
    metapsionics["Devotions"] = "";

    Initialize();

    Json::Value disciplines;

    std::string s = in;
    std::regex r("<tr class=\"cn\"><td>(.+?)</td><td>(.+?)</td><td>(.+?)/(.+?)</td><td>=* *(.+?)</td><td>(.+?)</td></tr>", std::regex::optimize);
    std::smatch m;

    std::regex_search(in, m, r);

    // put table values in json tree
    if (debug)
    {
        for (auto x : m)
        {
            std::cout << x << " \n";
        }
    }

    disscidev.append(Json::Value(m.str(2)));
    table["DisSciDev"] = disscidev;

    attdef.append(m.str(3));
    attdef.append(m.str(4));
    table["AttackDefense"] = attdef;
    table["Score"] = m.str(5);
    table["PSPs"] = m.str(6);

    table["Level"] = m.str(1);

    if (debug)
    {
        std::cout << "psionic table set\n";
    }

    // Parse psionic disciplines and abilities
    std::regex r2("<p class=\"ni\"><b>(.+?) -</b> <i>Science[s]*:</i>(.+?)[;.] <i>Devotion[s]*:</i>(.+?)[.]*</p>", std::regex::optimize);
    std::smatch m2;

    // default constructor = end-of-sequence:
    std::regex_token_iterator<std::string::iterator> rend;

    std::regex_search(in, m2, r2);
    std::string tmpString;
    std::string tmpDisc;
    std::string tmpSci;
    std::string tmpDev;

    // std::cout << "Powers list:\n";

    std::regex_token_iterator<std::string::iterator> a(in.begin(), in.end(), r2, {1, 2, 3});
    while (a != rend)
    {
        tmpDisc = *a++;
        tmpSci = *a++;
        tmpDev = *a++;
        if (debug)
            std::cout << "Discipline: " << tmpDisc << ", Sciences: " << tmpSci << ", Devotions: " << tmpDev << "\n";
        switch (s_mapStringValues[tmpDisc])
        {
        case clairsentienceVal:
            // std::cout << "clairsentience\n";
            clairsentience["Sciences"] = tmpSci;
            clairsentience["Devotions"] = tmpDev;
            powers["clairsentience"] = clairsentience;
            break;
        case psychokinesisVal:
            // std::cout << "psychokinesis\n";
            psychokinesis["Sciences"] = tmpSci;
            psychokinesis["Devotions"] = tmpDev;
            powers["psychokinesis"] = psychokinesis;
            break;
        case psychometabolismVal:
            // std::cout << "psychometabolism\n";
            psychometabolism["Sciences"] = tmpSci;
            psychometabolism["Devotions"] = tmpDev;
            powers["psychometabolism"] = psychometabolism;
            break;
        case psychoportationVal:
            // std::cout << "psychoportation\n";
            psychoportation["Sciences"] = tmpSci;
            psychoportation["Devotions"] = tmpDev;
            powers["psychoportation"] = psychoportation;
            break;
        case telepathyVal:
            // std::cout << "telepathy\n";
            telepathy["Sciences"] = tmpSci;
            telepathy["Devotions"] = tmpDev;
            powers["telepathy"] = telepathy;
            break;
        case metapsionicsVal:
            // std::cout << "metapsionics\n";
            metapsionics["Sciences"] = tmpSci;
            metapsionics["Devotions"] = tmpDev;
            powers["metapsionics"] = metapsionics;
            break;
        }
    }

    // if (debug)
    // {
    //     for (auto x : m2)
    //     {
    //         std::cout << x << " \n";
    //     }
    // }
    if (debug)
        std::cout << "setting root\n";
    root["table"] = table;
    root["powers"] = powers;

    return root;
}

std::string PsionicReader::prunePsionics(std::string in)
{
    // std::regex r("<p class=\"f\"><b>Psionics Summary</b></p>(\r|\n|.)+<p class=\"ni\">(.+?)</p>");
    std::regex psi("<p class=\"f\"><b>Psionics Summary</b></p>[^]+<p class=\"ni\">.+?</p>", std::regex_constants::extended | std::regex_constants::ECMAScript);

    std::string prunedText;
    std::string input = in;
    prunedText = std::regex_replace(input, psi, "");
    return prunedText;
}

// todo
void PsionicReader::clearPowerTree()
{
}

void PsionicReader::Initialize()
{
    s_mapStringValues["Clairsentience"] = clairsentienceVal;
    s_mapStringValues["Psychokinesis"] = psychokinesisVal;
    s_mapStringValues["Psychometabolism"] = psychometabolismVal;
    s_mapStringValues["Psychoportation"] = psychoportationVal;
    s_mapStringValues["Telepathy"] = telepathyVal;
    s_mapStringValues["Metapsionics"] = metapsionicsVal;
    return;
}
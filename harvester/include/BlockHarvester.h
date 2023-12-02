// Standard includes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/regex>
#include <filesystem>
#include <typeinfo>
#include <set>
#include <chrono>
#include <thread>
#include <algorithm>
// boost
// #include <boost/algorithm/string.hpp>

// Jsoncpp
// #include "json/value.h"
// #include <json/json.h>
// #include <json/reader.h>
// #include <json/writer.h>


/**
 * @brief Class to parse input string monsterString for a regex match to the following regular expression: 
 *  <([b|p|i])(>| class="f"|)(class="f"|)>(.+?)</\1>
 * 
 * For each match, call the parse function
 * again recursively.
 * @param monsterString The string to parse
 */
class BlockHarvester {
public:
    BlockHarvester(std::string monsterString);
    std::vector<std::string>  parseFunction(std::string inputString);
private:
    std::string monsterString;
    std::string regex;
    // std::function<void(std::string)> parseFunction;
};


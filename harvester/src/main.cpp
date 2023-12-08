// Standard includes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <typeinfo>
#include <chrono>

#include "harvester.h"

#include <array>
// #include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace a::b::c
{
    inline constexpr std::string_view str{"hello"};
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
    return {sizeof...(T), (args + ...)};
}

int main(int argc, char *argv[])
{
    auto full_start = std::chrono::steady_clock::now();

    Harvester harvester;
    harvester.debug = 0;

    harvester.GetFileData();

    // problem monsters (there are more):
    // tripheg 

    // std::cout << "harvesting nicknames...\n";
    // harvester.HarvestNickNames();

    // harvester.TestRunSel("fishtori");
    // harvester.RunMonster("yakman");
    // harvester.RunMonster("genizkda");
    // harvester.RunMonster("yeshom");

    // std::cout << "dao\n";
    // harvester.RunMonster("genizkda");
    // std::cout << "djinni\n";
    // harvester.RunMonster("genizkdj");
    // std::cout << "efreeti\n";
    // harvester.RunMonster("genizkef");
    // std::cout << "janni\n";
    // harvester.RunMonster("genizkjn");
    // std::cout << "marid\n";
    // harvester.RunMonster("genizkma");

    // printf("Done testing\n");

    harvester.HarvestAll(true);
    // harvester.RunMonster("human");
    // harvester.RunMonster("zombie");
    // harvester.RunMonster("yugoultr");
    

    // harvester.RunMonster("jakar");
    // harvester.RunMonster("element1");
    // harvester.RunMonster("lycaraki");
    
    // harvester.PrintCatalogue();
    printf("After Harvest\n");
    harvester.SaveCatalogue();
    // harvester.SaveCategories();
    harvester.SaveStatistics();
    // harvester.GetUniqueTSRList();
    auto stop = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - full_start);
    std::cout << "Duration:" << duration.count() << std::endl;
}
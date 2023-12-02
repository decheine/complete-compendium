

#include <string>

#include <json/value.h>

class PsionicReader
{
public:
    Json::Value parsePowerTree(std::string in); // parses tree, writes to power_tree
    std::string prunePsionics(std::string in);

    void clearPowerTree(); // erases power_tree so it can be rewritten
    void Initialize();     // initialize helper function for parsing

    bool debug;

private:
    Json::Value power_tree;
};
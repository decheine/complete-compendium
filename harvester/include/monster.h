#ifndef LOMION_INCLUDE_MONSTER_H_
#define LOMION_INCLUDE_MONSTER_H_

#include <string>
#include <json/value.h>

class Monster {
    public:
        

        void setPsionics(Json::Value psionicTable);

    private:
        std::string title;
        std::string TSR;
        std::string

        Json::Value psionicTable; 



};

#endif // LOMION_INCLUDE_MONSTER_H_
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

enum States {
    ST_BeginGame,
    ST_RunningGame,
    ST_GameOver
};

struct AdjustmentOptions {
    std::string shortenedTemp;
    std::string spokenTemp;
    std::string shortenedStrength;
    std::string spokenStrength;
    std::string spokenSize;

    AdjustmentOptions(): shortenedTemp(""), spokenTemp(""), shortenedStrength(""), spokenStrength(""), spokenSize("") {}

    void reset() {
        shortenedTemp = "";
        spokenTemp = "";
        shortenedStrength = "";
        spokenStrength = "";
        spokenSize = "";
    }
};

struct strengthOptions {
    int standard = 0;
    int weak = 1;
    int strong = 2;
    int extraStrong = 3;
};

bool tempPresence () {
    int temperatureNeeded = rand() % 3;
    bool tempPresence;

    if (temperatureNeeded == 0) {
        tempPresence = true;
    }
    else {
        tempPresence = false;
    }
    return tempPresence;
}

void generateTemp (std::string& spokenTemp, std::string& shortenedTemp) {
    int temperatureOptions = rand() % 3;

    if (temperatureOptions < 2) {
            spokenTemp = " hot";
            shortenedTemp = "Hot";
    }

    if (temperatureOptions == 2) {
            spokenTemp = " extra hot";
            shortenedTemp = "Ex. Hot";
    }

}

bool strengthPresence (std::string drinkType) {
    bool strPresence = false;
    if (drinkType == "Cl" || "Cap" || "FW" || "LB" || "Iced latte" || "HC" || "Pic") {
        int temperatureNeeded = rand() % 3;
        if (temperatureNeeded == 0) {
            strPresence = true;
        }
    }
    return strPresence;
}

void generateStrength (std::string& spokenStrength, std::string& shortenedStrength) {
    int strengthOptions = rand() % 3;

    if (strengthOptions < 2) {
            spokenStrength = " strong";
            shortenedStrength = "Str";
    }

    if (strengthOptions == 2) {
            spokenStrength = " weak";
            shortenedStrength = "Wk";
    }
}




class Drink {
    public: 
        Drink () {};
        std::string shortenedType;
        std::string spokenType;
        bool stmdMilkPresent = true;
        

        std::string generateDrinkType(std::string& spokenType, bool& stmdMilkPresent/*bool temp?*/) {
            int rdmDrinkType = rand() % 14;
            int rdmWording = rand() % 3;

            if (rdmDrinkType == 0) {
                shortenedType = "Cl";
                if (rdmWording < 2) {
                    spokenType = " latte";
                }
                else if (rdmWording == 2) {
                    spokenType = " cafe latte";
                }
            }

            else if (rdmDrinkType == 1) {
                shortenedType = "Cap";
                if (rdmWording < 2) {
                    spokenType = " cappucino";
                }
                else if (rdmWording == 2) {
                    spokenType = " cap";
                }
            }

            else if (rdmDrinkType == 2) {
                shortenedType = "FW";
                spokenType = " flat white";
            }

            else if (rdmDrinkType == 3) {
                shortenedType = "Magic";
                spokenType = " magic";
            }

            else if (rdmDrinkType == 4) {
                shortenedType = "ESP";
                stmdMilkPresent = false;
                if (rdmWording < 2) {
                    spokenType = " espresso";
                }
                else if (rdmWording == 2) {
                    spokenType = " short black";
                }
            }

            else if (rdmDrinkType == 5)
            {
                shortenedType = "DESP";
                stmdMilkPresent = false;
                spokenType = " double espresso";
            }

            else if (rdmDrinkType == 6) {
                shortenedType = "LB";
                stmdMilkPresent = false;
                spokenType = " long black";
            }

            else if (rdmDrinkType == 7) {
                shortenedType = "Iced latte";
                spokenType = " iced latte";
            }

            else if (rdmDrinkType == 8) {
                shortenedType = "Baby c";
                spokenType = " baby chino";
            }

            else if (rdmDrinkType == 9) {
                shortenedType = "HC";
                if (rdmWording == 0) {
                    spokenType = " hot chocolate";
                }
                else if (rdmWording == 1) {
                    spokenType = " hot choc";
                }
                else if (rdmWording == 2) {
                    spokenType = " hot choccy";
                }
            }

            else if (rdmDrinkType == 10) {
                shortenedType = "Chai";
                if (rdmWording < 2) {
                    spokenType = " chai latte";
                }
                else if (rdmWording == 2) {
                    spokenType = " chai";
                }
            }

            else if (rdmDrinkType == 11) {
                shortenedType = "L Mac";
                stmdMilkPresent = false;
                if (rdmWording < 2) {
                    spokenType = " long mac";
                }
                else if (rdmWording == 2) {
                    spokenType = " long macchiato";
                }
            }

            else if (rdmDrinkType == 12) {
                shortenedType = "S Mac";
                stmdMilkPresent = false;
                if (rdmWording < 2) {
                    spokenType = " short mac";
                }
                else if (rdmWording == 2) {
                    spokenType = " short macchiato";
                }
            }

            else if (rdmDrinkType == 13) {
                shortenedType = "Pic";
                spokenType = " picollo";
            }

            else if (rdmDrinkType == 14) {
                shortenedType = "";
                stmdMilkPresent = false;
                if (rdmWording < 2) {
                    spokenType = " filter coffee";
                }
                else if (rdmWording == 2) {
                    spokenType = " hot brew";
                }
            }

            return spokenType; // change to shortened?
        }

        // std::string generateSpokenType(std::string shortenedType) {
            
        // }

};

class Milk {
    public: 
        Milk () {};
        Drink drink;
        std::string spokenMilk = ""; // default
        std::string shortenedType = "";

        std::string generateMilk(std::string& spokenMilk) {
            int rdmMilkType = rand() % 5;
            int rdmWording = rand() % 3;

            if (rdmMilkType == 0) {
                if (rdmWording == 2) {
                    spokenMilk = " full cream";
                }
                // full cream milk
            }

            else if (rdmMilkType == 1) {
                shortenedType = "Sk";
                if (rdmWording < 2) {
                    spokenMilk = " skinny";
                }
                else if (rdmWording == 2) {
                    spokenMilk = " skim";
                }
            }

            else if (rdmMilkType == 2) {
                shortenedType = "Oat";
                spokenMilk = " oat";
            }

            else if (rdmMilkType == 3) {
                shortenedType = "Alm";
                spokenMilk = " almond";
            }

            else if (rdmMilkType == 4) {
                shortenedType = "Soy";
                spokenMilk = " soy";
            }

            return spokenMilk;
        }

};


class Sweetener {
    public: 
        Sweetener () {};
        std::string spokenSweetener = ""; // default
        std::string shortenedSweetener = "";
        bool sweetenerPresent = false;

        bool sweetenerPrescence(std::string drinkTypeShort, bool& sweetenerPresent) {

            if (drinkTypeShort == "" && drinkTypeShort == "Pic" && drinkTypeShort == "Baby c" && 
                drinkTypeShort == "S Mac" && drinkTypeShort == "L Mac" && drinkTypeShort == "ESP") {
                    sweetenerPresent = false;
                }
            else {
                int sweetenerChance = rand() % 3;
                if (sweetenerChance == 0) {
                    sweetenerPresent = true;
                }
                else {
                    sweetenerPresent = false;
                }
            }
            return sweetenerPresent;
        }

        std::string generateSweetenerType (bool sweetenerPresent, std::string& shortenedSweetener, std::string& spokenSweetener) {

            if (sweetenerPresent) {
                int rdmSweetenerType = rand() % 3;

                if (rdmSweetenerType == 0) {
                    spokenSweetener = "sugar";
                }

                else if (rdmSweetenerType == 1) {
                    shortenedSweetener = "+honey";
                    spokenSweetener = "honey";
                }

                else if (rdmSweetenerType == 2) {
                    shortenedSweetener = "+sweetener";
                    spokenSweetener = "sweetener";
                }
            }

            return shortenedSweetener;
        }

        std::string sweetenerAmount(std::string sweetenerType, std::string& shortenedSweetener) {
            int rdmAmount = rand() % 4;
            int rdmWording = rand() % 2;
            std::string spokenWording;

            if (sweetenerType == "+honey" || sweetenerType == "+sweetener") {
                if (rdmWording == 0) {
                    spokenWording = " some " + spokenSweetener;
                }
                else if (rdmWording == 1) {
                    spokenWording = " a bit of " + spokenSweetener;
                }
            }
            else {
                if (rdmAmount == 0) {
                    shortenedSweetener = "1";
                    if (rdmWording == 0) {
                        spokenWording = " a " + spokenSweetener;
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " one " + spokenSweetener;
                    }
                }
                else if (rdmAmount == 1) {
                    shortenedSweetener = "2";
                    if (rdmWording == 0) {
                        spokenWording = " two " + spokenSweetener + "s";
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " a couple of " + spokenSweetener + "s";
                    }
                }
                else if (rdmAmount == 2) {
                    shortenedSweetener = "3";
                    spokenWording = " three " + spokenSweetener + "s";             
                }
                else if (rdmAmount == 3) {
                    shortenedSweetener = "1/2";
                    if (rdmWording == 0) {
                        spokenWording = " half a " + spokenSweetener;
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " a half scoop of " + spokenSweetener;
                    }
                }
            }
            return spokenWording;
        }

        std::string generateSweetenerWording (std::string sweetenerPhrase) {
            std::string sweetenerSentence;
            int rdmSweetenerType = rand() % 3;

            if (rdmSweetenerType == 0) {
                sweetenerSentence = " with" + sweetenerPhrase;
            }

            else if (rdmSweetenerType == 1) {
                sweetenerSentence = " and add" + sweetenerPhrase;
            }

            else if (rdmSweetenerType == 2) {
                sweetenerSentence = " with" + sweetenerPhrase + " mixed in";
            }

            return sweetenerSentence;
        }

};

std::string generateIntroduction() {
    std::string generatedIntro;
    int randomChance = rand() % 5;

    if (randomChance == 0) {
        generatedIntro = "Hi, can I please have a";
    }

    else if (randomChance == 1) {
        generatedIntro = "One";
    }

    else if (randomChance == 2) {
        generatedIntro = "Can I get a";
    }

    else if (randomChance == 3) {
        generatedIntro = "I'll grab one";
    }

    else if (randomChance == 4) {
        generatedIntro = "I'll have a";
    }

    return generatedIntro;
}

// with skim milk
// skim "coffee order"


bool getUserReturn() {
    std::string inputLine;
    std::getline(std::cin, inputLine);

    if (inputLine == "q") {
        return false;
    } 
    else if (!inputLine.empty()) {
        return true;
    }
    else {
        // Handle empty inputLine (user pressed return without entering anything)
        return true; // or false, depending on your preference
    }
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string customerIntro;
    std::string drinkType;

    States curState = ST_BeginGame;

    std::cout << std::endl << std::endl
    << "Hi! Welcome to Cafe Simulator" << std::endl << std::endl 
    << "Read the customers order and enter the shortened version line by line to the terminal"
    << std::endl << std::endl << "Remember to add the time at the bottom of each order. Enter 'q' to quit at any time." << std::endl << 
    std::endl << "Good luck!!" << std::endl << std::endl;

    if (curState == ST_BeginGame && getUserReturn() == true) {
        while (curState == ST_BeginGame) {
            time_t now = time(0);
            tm* ltm = localtime(&now);  
            bool tempPresent = false;
            std::string customerMilk = "";
            std::string sweetenerPhrasing = "";
            std::string sweetenerSentence = "";
            Drink drink;
            Milk milk;
            Sweetener sweetener;
            AdjustmentOptions adjustmentOptions;

            drinkType = drink.generateDrinkType(drink.spokenType, drink.stmdMilkPresent);
            
            if (drink.stmdMilkPresent == true) { // get milk if the drink type requires it
                customerMilk = milk.generateMilk(milk.spokenMilk);
                tempPresent = tempPresence();
            }
            else { 
                customerMilk = "";
            }

            bool drinkSweetener = sweetener.sweetenerPrescence(drink.shortenedType, sweetener.sweetenerPresent);
            if (drinkSweetener) {
                sweetener.generateSweetenerType (sweetener.sweetenerPresent, sweetener.shortenedSweetener, sweetener.spokenSweetener);
                sweetenerPhrasing = sweetener.sweetenerAmount(sweetener.shortenedSweetener, sweetener.shortenedSweetener);
                sweetenerSentence = sweetener.generateSweetenerWording(sweetenerPhrasing);
            }
            else {
                sweetenerSentence = "";
                sweetener.spokenSweetener = "";
            }

            bool needsStrength = strengthPresence(drink.shortenedType);

            if (needsStrength) {
                generateStrength(adjustmentOptions.spokenStrength, adjustmentOptions.shortenedStrength);
            }

            if (tempPresent) {
                generateTemp(adjustmentOptions.spokenTemp, adjustmentOptions.shortenedTemp);
            }


            customerIntro = generateIntroduction();

            std::string time = std::to_string((ltm->tm_hour) % 12) + ":" + std::to_string(ltm->tm_min);
            std::cout << "\e[1mCoffee order: \e[0m" << std::endl << std::endl;

            std::cout << customerIntro << 
            adjustmentOptions.spokenTemp << adjustmentOptions.spokenStrength << customerMilk << drinkType << sweetenerSentence << std::endl << std::endl;


            std::string userStr;

            if (!(adjustmentOptions.shortenedStrength == "")) {
                std::getline(std::cin, userStr);
            }

            if (!(adjustmentOptions.shortenedStrength == userStr)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << adjustmentOptions.shortenedStrength;
                std::cout << std::endl;
            }


            std::string userTemp;

            if (!(adjustmentOptions.shortenedTemp == "")) {
                std::getline(std::cin, userTemp);
            }

            if (!(adjustmentOptions.shortenedTemp == userTemp)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << adjustmentOptions.shortenedTemp;
                std::cout << std::endl;
            }


            std::string userMilk;

            if (!(milk.shortenedType == "")) {
                std::getline(std::cin, userMilk);
            }

            if (!(milk.shortenedType == userMilk)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << milk.shortenedType;
                std::cout << std::endl;
            }


            std::string userDrink;

            std::getline(std::cin, userDrink);

            if (!(drink.shortenedType == userDrink)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << drink.shortenedType;
                std::cout << std::endl;
            }


            std::string userSweetener;

            if (!(sweetener.spokenSweetener == "")) {
                std::getline(std::cin, userSweetener);
            }

            if (!(sweetener.shortenedSweetener == userSweetener)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << sweetener.shortenedSweetener;
                std::cout << std::endl;
            }

            std::string userTime;
            std::getline(std::cin, userTime);

            if (!(time == userTime)) {
                curState = ST_GameOver;
                std::cout << "Wrong! Should be: " << time;
                std::cout << std::endl;
            }
            
            std::cout << std::endl << std::endl << std::endl << std::endl;
            adjustmentOptions.reset();
        }
    }

    return 0;
}


// UNUSED:

            // if (getUserReturn() == false) {
            //     curState = ST_GameOver;
            //     std::cout << std::endl << "Game Over" << std::endl << std::endl;
            //     break;
            // }
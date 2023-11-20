#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

enum States {
    ST_BeginGame,
    ST_RunningGame,
    ST_GameOver
};

struct adjustmentOptions {
    std::string temp;
    std::string strength;
    std::string size;
    int sugar;
};

struct strengthOptions {
    int standard = 0;
    int weak = 1;
    int strong = 2;
    int extraStrong = 3;
};

std::string generateTemp (bool stmdMilkPresent/*bool temp?*/) {


    if (stmdMilkPresent) {
        return 0;
    }
    // Generate temp if drink type requires it and steamed milk is present

}

int generateStrength (std::string drinkType, bool stmdMilkPresent/*bool temp?*/) {
    // Generate strength if drink type requires it
    // Cl, Cap, FW, Magic, LB, Iced latte, HC, Pic
    // strong espresso == double espresso
    // 

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
                    spokenType = " short mac";
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

            if (!(drinkTypeShort == "" && drinkTypeShort == "Pic" && drinkTypeShort == "Baby c" && 
                drinkTypeShort == "S Mac" && drinkTypeShort == "L Mac" && drinkTypeShort == "ESP")) {
                    sweetenerPresent = true;
                }
            else {
                int sweetenerChance = rand() % 3;
                if (sweetenerChance == 0) {
                    sweetenerPresent = true;
                }
            }
            return sweetenerPresent;
        }

        std::string generateSweetenerType (bool sweetenerPresent, std::string& shortenedSweetener, std::string& spokenSweetener) {

            int rdmSweetenerType = rand() % 4;
            int rdmWording = rand() % 2;
            // none, sugar, equal, honey,
            std::string spokenSweetener;

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

            return shortenedSweetener;
        }

        std::string sweetenerAmount(std::string sweetenerType, bool sweetenerPresent) {
            int rdmAmount = rand() % 4;
            int rdmWording = rand() % 2;
            std::string spokenWording;

            if (sweetenerType == "+honey") {
                if (rdmWording == 0) {
                    spokenWording = " some " + sweetenerType;
                }
                else if (rdmWording == 1) {
                    spokenWording = " a bit of " + sweetenerType;
                }
            }
            else {
                if (rdmAmount == 0) {
                    if (rdmWording == 0) {
                        spokenWording = " a " + sweetenerType;
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " one " + sweetenerType;
                    }
                }
                else if (rdmAmount == 1) {
                    if (rdmWording == 0) {
                        spokenWording = " two " + sweetenerType + "s";
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " a couple of " + sweetenerType + "s";
                    }
                }
                else if (rdmAmount == 2) {
                    spokenWording = " three " + sweetenerType + "s";             
                }
                else if (rdmAmount == 3) {
                    if (rdmWording == 0) {
                        spokenWording = " half a " + sweetenerType;
                    }
                    else if (rdmWording == 1) {
                        spokenWording = " a half scoop of " + sweetenerType;
                    }
                }
            }
            return spokenWording;
        }

};

std::string generateIntroduction() {
    std::string generatedIntro;
    int randomChance = rand() % 5;

    if (randomChance == 0) {
        generatedIntro = "Hi can I please have a";
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
    std::string temperature;
    std::string customerMilk = "";
    std::string customerSweetener = "";
    std::string customerIntro;
    std::string drinkType;

    States curState = ST_BeginGame;

    if (curState == ST_BeginGame && getUserReturn() == true) {
        while (curState == ST_BeginGame) {
            Drink drink;
            Milk milk;
            Sweetener sweetener;

            drinkType = drink.generateDrinkType(drink.spokenType, drink.stmdMilkPresent);
            
            if (drink.stmdMilkPresent == true) { // get milk if the drink type requires it
                customerMilk = milk.generateMilk(milk.spokenMilk);
            }
            else { 
                customerMilk = "";
            }

        //// CHATGPT!! INSERT YOUR STUFF HERE
            bool drinkSweetener = sweetener.sweetenerPrescence(drink.shortenedType, sweetener.sweetenerPresent);
            if (drinkSweetener) {
                sweetener.generateSweetenerType (sweetener.sweetenerPresent, sweetener.shortenedSweetener, sweetener.spokenSweetener);
                customerSweetener = sweetener.sweetenerAmount(sweetener.shortenedSweetener, sweetener.sweetenerPresent);
            }




            customerIntro = generateIntroduction();

            std::cout << "Coffee order: " << std::endl << std::endl;

            std::cout << customerIntro << 
            customerMilk << drinkType << customerSweetener << std::endl << std::endl;


            // rewwrite later

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

            std::cout << std::endl << std::endl;
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
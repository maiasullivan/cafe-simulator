#include <iostream>
#include <string>
#include <ctime>

struct temperatureOptions {
    int standard = 0;
    int hot = 1;
    int extraHot = 2;
    int iced = 3;
};

std::string generateDrinkType(/*bool temp?*/) {

    std::string generatedDrinkType;
    int randomChance = rand() % 15;

    if (randomChance == 0) {
        generatedDrinkType = "Cl";
    }

    else if (randomChance == 1) {
        generatedDrinkType = "Cap";
    }

    else if (randomChance == 2) {
        generatedDrinkType = "FW";
    }

    else if (randomChance == 3) {
        generatedDrinkType = "Magic";
    }

    else if (randomChance == 4) {
        generatedDrinkType = "ESP";
    }

    else if (randomChance == 5)
    {
        generatedDrinkType = "DESP";
    }

    else if (randomChance == 6) {
        generatedDrinkType = "LB";
    }

    else if (randomChance == 7) {
        generatedDrinkType = "Filter coffee";
    }

    else if (randomChance == 8) {
        generatedDrinkType = "Iced latte";
    }

    else if (randomChance == 9) {
        generatedDrinkType = "Baby c";
    }

    else if (randomChance == 10) {
        generatedDrinkType = "HC";
    }

    else if (randomChance == 11) {
        generatedDrinkType = "Chai";
    }

    else if (randomChance == 12) {
        generatedDrinkType = "L Mac";
    }

    else if (randomChance == 13) {
        generatedDrinkType = "S Mac";
    }

    else if (randomChance == 14) {
        generatedDrinkType = "Pic";
    }

    return generatedDrinkType;
}

std::string generateMilk() {

    std::string generatedMilk;
    int randomChance = rand() % 5;

    if (randomChance == 0) {
        generatedMilk = "FC";
        // no need to specify milk here
    }

    else if (randomChance == 1) {
        generatedMilk = "Sk";
    }

    else if (randomChance == 2) {
        generatedMilk = "Oat";
    }

    else if (randomChance == 3) {
        generatedMilk = "Alm";
    }

    else if (randomChance == 4) {
        generatedMilk = "Soy";
    }

    return generatedMilk;
}

std::string generateIntroduction() {

    std::string generatedIntro;
    int randomChance = rand() % 5;

    if (randomChance == 0) {
        generatedIntro = "Hi can I please have a ";
    }

    else if (randomChance == 1) {
        generatedIntro = "One ";
    }

    else if (randomChance == 2) {
        generatedIntro = "Can I get a ";
    }

    else if (randomChance == 3) {
        generatedIntro = "I'll grab one ";
    }

    else if (randomChance == 4) {
        generatedIntro = "I'll have a ";
    }

    return generatedIntro;
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string temperature;
    std::string customerMilk;
    std::string customerIntro;
    std::string drinkType;

    customerMilk = generateMilk();
    customerIntro = generateIntroduction();
    drinkType = generateDrinkType();

    std::cout << "Coffee order: " << std::endl << std::endl;

    std::cout << customerIntro << 
    customerMilk << " " << drinkType << std::endl << std::endl;

    return 0;
}
#pragma once
#include <iostream>

enum foodType {
    FRUITSVEGETABLESCEREALS,
    DAIRY,
    PORK,
    POULTRY,
    BEEF,
    FISH
};

class FoodOperation {
public:
    static foodType typefromString(std::string f) {
        if (f == "fruits vegetables cereals")
            return FRUITSVEGETABLESCEREALS;
        else if (f == "dairy")
            return DAIRY;
        else if (f == "pork")
            return PORK;
        else if (f == "poultry")
            return POULTRY;
        else if (f == "beef")
            return BEEF;
        else if (f == "fish")
            return FISH;
        throw "bad input";
    }

    static int getFoodOffset(foodType f) {
        switch (f)
        {
        case FRUITSVEGETABLESCEREALS:
            return 0;
            break;
        case DAIRY:
            return 1;
            break;
        case PORK:
            return 2;
            break;
        case POULTRY:
            return 3;
            break;
        case BEEF:
            return 4;
            break;
        case FISH:
            return 5;
            break;
        default:
            return 0;
            break;
        }
    }
};

class Food {
    int v[6] = { 1, 5, 11, 7, 15, 12 };
    int kg[6] = { 0, 0, 0, 0, 0, 0 };

    foodType t;

public:
    Food() {};

    void setType(foodType t) {
        this->t = t;
    }

    void updateKg(int v[6]) {
        for (int i = 0; i < 6; i++)
            this->kg[i] = v[i];
    }

    double getIndex() {
        int sum = 0;
        sum += v[FoodOperation::getFoodOffset(FRUITSVEGETABLESCEREALS)] * kg[0];
        sum += v[FoodOperation::getFoodOffset(DAIRY)] * kg[1];
        sum += v[FoodOperation::getFoodOffset(PORK)] * kg[2];
        sum += v[FoodOperation::getFoodOffset(POULTRY)] * kg[3];
        sum += v[FoodOperation::getFoodOffset(BEEF)] * kg[4];
        sum += v[FoodOperation::getFoodOffset(FISH)] * kg[5];

        return sum * 12 / 1000.0;
    }

};
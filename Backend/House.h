#pragma once
#include <iostream>

enum houseEnergy {
    ELECTRIC,
    GAZ,
    LEMN,
    PUBLIC,
    PELETI
};

enum houseType {
    SMALL,
    MEDIUM,
    LARGE
};

class HouseOperation {
public:
    static houseType typefromString(std::string h) {
        if (h == "large")
            return LARGE;
        else if (h == "medium")
            return MEDIUM;
        else if (h == "small")
            return SMALL;
        throw "bad input";
    }

    static int getEnergyOffset(houseEnergy h) {
        switch (h)
        {
        case ELECTRIC:
            return 0;
            break;
        case GAZ:
            return 1;
            break;
        case LEMN:
            return 2;
            break;
        case PUBLIC:
            return 3;
            break;
        case PELETI:
            return 4;
            break;
        default:
            return 0;
            break;
        }
    }

    static int getHouseSizeOffset(houseType t) {
        switch (t)
        {
        case SMALL:
            return 10;
            break;
        case MEDIUM:
            return 5;
            break;
        case LARGE:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }
};

class House {
    int v[16] = { 210, 245, 90, 550, 72, 180, 210, 72, 475, 54, 150, 175, 54, 400, 36 };
    int con[6] = { 0, 0, 0, 0, 0, 0 };

    houseType t;

public:
    House() {};

    void setType(houseType t) {
        this->t = t;
    }

    void updateCon(int v[6]) {
        for (int i = 0; i < 6; i++)
            con[i] = v[i];
    }

    double getIndex() {
        int sum = 0;
        sum += v[HouseOperation::getHouseSizeOffset(t) + HouseOperation::getEnergyOffset(ELECTRIC)] * con[0];
        sum += v[HouseOperation::getHouseSizeOffset(t) + HouseOperation::getEnergyOffset(GAZ)] * con[1];
        sum += v[HouseOperation::getHouseSizeOffset(t) + HouseOperation::getEnergyOffset(LEMN)] * con[2];
        sum += v[HouseOperation::getHouseSizeOffset(t) + HouseOperation::getEnergyOffset(PUBLIC)] * con[3];
        sum += v[HouseOperation::getHouseSizeOffset(t) + HouseOperation::getEnergyOffset(PELETI)] * con[4];
        return sum * 12 / 1000000.0;
    }
};
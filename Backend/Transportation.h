#pragma once
#include <iostream>

enum motorcycleType {
    SMALLMOTORCYCLE,
    MEDIUMMOTORCYCLE,
    LARGEMOTORCYCLE
};

class MotorcycleOperation {
public:
    static motorcycleType typefromString(std::string m)
    {
        if (m == "large")
            return LARGEMOTORCYCLE;
        else if (m == "medium")
            return MEDIUMMOTORCYCLE;
        else if (m == "small")
            return SMALLMOTORCYCLE;
        throw "bad input";
    }

    static int getTypeOffset(motorcycleType t) {
        switch (t) {
        case SMALLMOTORCYCLE:
            return 0;
            break;
        case MEDIUMMOTORCYCLE:
            return 1;
            break;
        case LARGEMOTORCYCLE:
            return 2;
            break;
        default:
            return 0;
            break;
        }
    }
};

class Motorcycle {
    int v[3] = { 93, 101, 132 };
    int km = 0;
    motorcycleType t;

public:
    Motorcycle() {};

    void settype(motorcycleType t) {
        this->t = t;
    }

    void setKm(int km) {
        this->km = km;
    }

    double getIndex() {
        if (km == 0)
            return 0;
        return v[MotorcycleOperation::getTypeOffset(t)] * this->km * 12 / 1000000.0;
    }

};

enum carType {
    SMALLCAR,
    MEDIUMCAR,
    LARGECAR
};

enum carFuel {
    DIESEL,
    PETROL,
    HYBRID,
    ELECTRICCAR
};

class CarOperation {
public:
    static carType typefromString(std::string c) {
        if (c == "large")
            return LARGECAR;
        else if (c == "medium")
            return MEDIUMCAR;
        else if (c == "small")
            return SMALLCAR;
        throw "bad input";
    }

    static int getFuelOffset(carFuel c) {
        switch (c)
        {
        case DIESEL:
            return 0;
            break;
        case PETROL:
            return 1;
            break;
        case HYBRID:
            return 2;
            break;
        case ELECTRICCAR:
            return 3;
            break;
        default:
            return 0;
            break;
        }
    }

    static carFuel fuelfromString(std::string c) {
        if (c == "diesel")
            return DIESEL;
        else if (c == "petrol")
            return PETROL;
        else if (c == "hybrid")
            return HYBRID;
        else if (c == "electric")
            return ELECTRICCAR;
        throw "bad input";
    }

    static int getCarSizeOffset(carType t)
    {
        switch (t)
        {
        case SMALLCAR:
            return 0;
            break;
        case MEDIUMCAR:
            return 3;
            break;
        case LARGECAR:
            return 6;
            break;
        }
    }
};

class Car {
    int v[9] = { 139, 140, 101, 167, 178, 109, 208, 272, 152 };
    int km = 0;
    carType t;
    carFuel f;

public:
    Car() {};

    void settype(carType t) {
        this->t = t;
    }

    void setFuel(carFuel f) {
        this->f = f;
    }

    void setKm(int km) {
        this->km = km;
    }

    double getIndex() {
        if (km == 0)
            return 0;
        return v[CarOperation::getCarSizeOffset(t) + CarOperation::getFuelOffset(f)] * this->km * 12 / 1000000.0;
    }

};

class Flight {
    int v = 134;
    int h = 0;

public:
    Flight() {};

    void setHours(int h) {
        this->h = h;
    }

    double getIndex() {
        return v * this->h / 1000.0;
    }

};

enum publicTransport {
    TRAM,
    BUS,
    SUBWAY
};

class PublicOperation {
public:

    static int getFuelOffset(publicTransport p) {
        switch (p)
        {
        case TRAM:
            return 0;
            break;
        case BUS:
            return 1;
            break;
        case SUBWAY:
            return 2;
            break;
        default:
            return 0;
            break;
        }
    }
};

class PublicTransport {
    int v[3] = { 10, 69, 5 };
    int km[3] = { 0, 0, 0 };

public:
    PublicTransport() {};

    void setKm(int v[3]) {
        for (int i = 0; i < 3; i++) {
            this->km[i] = v[i];
        }
    }

    double getIndex() {
        double sum = 0;

        sum += v[PublicOperation::getFuelOffset(TRAM)] * km[0] / 1000.0;
        sum += v[PublicOperation::getFuelOffset(BUS)] * km[1] / 1000.0;
        sum += v[PublicOperation::getFuelOffset(SUBWAY)] * km[2] / 1000.0;

        return sum * 12 / 1000.0;
    }
};
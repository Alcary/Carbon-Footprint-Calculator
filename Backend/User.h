#pragma once
#include <iostream>
#include "Transportation.h"
#include "Food.h"
#include "House.h"

class User {
private:
	int id;
	Flight flight;
	Motorcycle motorcycle;
	Car car;
	PublicTransport transport;
	Food food;
	House house;

public:
	User(int id) {
		this->id = id;
	}

	void setFlight(int hours) {
		flight.setHours(hours);
	}

	void setCar(carType t, carFuel f, int km) {
		car.settype(t);
		car.setFuel(f);
		car.setKm(km);
	}

	void setMotorcycle(motorcycleType m, int km) {
		motorcycle.settype(m);
		motorcycle.setKm(km);
	}

	void setPublicTransport(int km[3]) {
		transport.setKm(km);
	}

	void setFood(int v[6]) {
		food.updateKg(v);
	}

	void setHouse(houseType t, int con[6]) {
		house.setType(t);
		house.updateCon(con);
	}

	double total() {
		double sum = 0.0;

		sum += house.getIndex();
		sum += car.getIndex();
		sum += motorcycle.getIndex();
		sum += flight.getIndex();
		sum += food.getIndex();
		sum += transport.getIndex();

		return sum;
	}
};

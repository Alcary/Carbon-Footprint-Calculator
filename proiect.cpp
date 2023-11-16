#include <iostream>
#include <cstring>

using namespace std;

class Customer{
    public:
        std :: string fuelType;
        std :: string vehicleType;
        std :: string motorcycleType;
        int hOnPlane, kmByCar, kmByMotorcycle;

        Customer(){
            fuelType = "Default";
            vehicleType = "Default";
            motorcycleType = "Default";
            kmByCar = 0;
            kmByMotorcycle = 0;
            hOnPlane = 0;
        }

        std::string getFuelType() const {
            return fuelType;
        }

        void setFuelType(const std::string& fuel) {
            fuelType = fuel;
        }

        std::string getVehicleType() const {
            return vehicleType;
        }

        void setVehicleType(const std::string& vehicle) {
            vehicleType = vehicle;
        }

        std::string getMotorcycleType() const {
            return motorcycleType;
        }

        void setMotorcycleType(const std::string& motorcycle) {
            motorcycleType = motorcycle;
        }

        int getHoursOnPlane() const {
            return hOnPlane;
        }

        void setHoursOnPlane(int hours) {
            hOnPlane = hours;
        }

        int getKilometersByCar() const {
            return kmByCar;
        }

        void setKilometersByCar(int kilometers) {
            kmByCar = kilometers;
        }

        int getKilometersByMotorcycle() const {
            return kmByMotorcycle;
        }

        void setKilometersByMotorcycle(int kilometers) {
            kmByMotorcycle = kilometers;
        }
    
};

class Transportation{
    public:
        int getCarIndex(Customer customer){
            int index = 0;
            std :: string fuelType = customer.getFuelType();
            std :: string vehicleType = customer.getVehicleType();

            if(fuelType == "Diesel"){
                if(customer.vehicleType == "Small"){
                    index = 139;
                }
                else{ 
                    if(customer.vehicleType  == "Medium"){
                        index = 167;
                    }
                        else index = 208;
                }
            }
            if(fuelType == "Petrol"){
                if(vehicleType == "Small"){
                    index = 140;
                }
                else{ 
                    if(vehicleType  == "Medium"){
                        index = 178;
                    }
                        else index = 272;
                }
            }
            if(fuelType == "Hybrid"){
                if(vehicleType == "Small"){
                    index = 101;
                }
                else{ 
                    if(vehicleType  == "Medium"){
                        index = 109;
                    }
                        else index = 152;
                }
            }
            if(fuelType == "Electric"){
                if(vehicleType == "Small"){
                    index = 0;
                }
                else{ 
                    if(vehicleType  == "Medium"){
                        index = 0;
                    }
                        else index = 0;
                }
            }
            return index;
        }

        int getMotorcycleIndex(Customer customer){
            int index = 0;
            std :: string motorcycleType = customer.getMotorcycleType();
            if(motorcycleType == "Small"){
                index = 93;
            }
                else{
                    if(motorcycleType == "Medium"){
                        index = 101;
                    }
                    else
                        index = 132;
            }
            return index;
        }
        
        int getFlightIndex(Customer customer){
            int index = 134;
            return customer.getHoursOnPlane() * index;
        }

        double getValue(Customer customer){
            double finalValue = getFlightIndex(customer) + (getMotorcycleIndex(customer) * customer.getKilometersByMotorcycle()) / 1000.0 + (getCarIndex(customer) * customer.getKilometersByCar()) / 1000.0;
            return finalValue / 1000.0;
        }
};


int main(){
    Customer client;
    client.setFuelType("Diesel");
    client.setHoursOnPlane(30);
    client.setKilometersByCar(1000);
    client.setVehicleType("Small");
    Transportation calcul;
    cout<<calcul.getValue(client)<<"tone";

    return 0;
}
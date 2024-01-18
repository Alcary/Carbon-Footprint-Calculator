#include "crow.h"
#include "crow/middlewares/cors.h"
#include <string>
#include <iostream>
#include <vector>
#include "Transportation.h"
#include "House.h"
#include "Food.h"
#include "User.h"

int main()
{
    crow::App<crow::CORSHandler> app;

    auto& cors = app.get_middleware<crow::CORSHandler>();
    cors
        .global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests")
        .methods("POST"_method, "GET"_method)
        .prefix("/")
        .origin("*")
        .prefix("/nocors")
        .ignore();

    CROW_ROUTE(app, "/")
        ([]() {
        return "Check Access-Control-Allow-Methods header";
            });

    std::vector<User> users;

    CROW_ROUTE(app, "/createuser")([&users](const crow::request& req) {
        User user = User(users.size() + 1);
        users.push_back(user);
        return std::to_string(users.size());
        });

    CROW_ROUTE(app, "/car")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("type") != NULL &&
            req.url_params.get("fuel") != NULL &&
            req.url_params.get("km") != NULL) {

            int id = std::atoi(req.url_params.get("id"));

            carType type = CarOperation::typefromString(req.url_params.get("type"));
            carFuel fuel = CarOperation::fuelfromString(req.url_params.get("fuel"));
            int km = std::stoi(req.url_params.get("km"));

            users[id - 1].setCar(type, fuel, km);
            return "Car information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/motorcycle")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("typemoto") != NULL &&
            req.url_params.get("kmmoto") != NULL) {

            int id = std::stoi(req.url_params.get("id"));
            motorcycleType type = MotorcycleOperation::typefromString(req.url_params.get("typemoto"));
            int km = std::stoi(req.url_params.get("kmmoto"));

            users[id - 1].setMotorcycle(type, km);
            return "Motorcycle information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/flight")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("hours") != NULL) {

            int id = std::stoi(req.url_params.get("id"));
            int hours = std::stoi(req.url_params.get("hours"));

            users[id - 1].setFlight(hours);
            return "Flight information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/house")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("typehouse") != NULL &&
            req.url_params.get("cons") != NULL) {

            int id = std::stoi(req.url_params.get("id"));
            houseType type = HouseOperation::typefromString(req.url_params.get("typehouse"));
            std::string cons_param = req.url_params.get("cons");

            int cons_vector[6];
            int i = 0;
            std::stringstream ss(cons_param);
            std::string value;
            while (std::getline(ss, value, ',')) {
                cons_vector[i++] = (std::stoi(value));
            }

            users[id - 1].setHouse(type, cons_vector);
            return "House information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/food")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("foods") != NULL) {

            int id = std::stoi(req.url_params.get("id"));
            std::string food = req.url_params.get("foods");

            int food_vector[6];
            int i = 0;
            std::stringstream ss(food);
            std::string value;
            while (std::getline(ss, value, ',')) {
                food_vector[i++] = (std::stoi(value));
            }

            users[id - 1].setFood(food_vector);
            return "Food information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/publictransport")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL &&
            req.url_params.get("kmpublic") != NULL) {

            int id = std::stoi(req.url_params.get("id"));

            std::string km_param = req.url_params.get("kmpublic");

            int km_vector[3];
            int i = 0;
            std::stringstream ss(km_param);
            std::string value;
            while (std::getline(ss, value, ',')) {
                km_vector[i++] = (std::stoi(value));
            }

            users[id - 1].setPublicTransport(km_vector);
            return "Public Transport information set successfully";
        }
        return "Invalid Parameters";
        });

    CROW_ROUTE(app, "/total")([&users](const crow::request& req) {
        if (req.url_params.get("id") != NULL) {
            int id = std::stoi(req.url_params.get("id"));
            std::cout << "\n TOTAL:" << users[id - 1].total() << "\n";
            return std::to_string(users[id - 1].total());
        }
        return std::string("Invalid Parameters");
        });


    app.port(18080).run();
}
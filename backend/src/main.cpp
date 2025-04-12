#include <iostream>
#include <vector>
#include <string>
#include "crow.h"
#include "DatabaseAPI.h"

int main() {
    crow::SimpleApp app;
    DatabaseAPI dbAPI("sqlite3.db");

    CROW_ROUTE(app, "/api/data").methods("POST"_method)
    ([&dbAPI](const crow::request& req) {
        auto js = crow::json::load(req.body);
        if (!js) {
            return crow::response(400, "Invalid JSON");
        }

        const std::string name = js["name"].s();
        const std::string data = js["data"].s();
        
        if (dbAPI.insertValue(name, data) != 0) {
            return crow::response(500, "Database error.");
        }

        crow::json::wvalue result;
        result["result"] = "Value inserted";
        return crow::response(200, result);
    });

    CROW_ROUTE(app, "/api/data").methods("GET"_method)
    ([&dbAPI](const crow::request& req) {
        auto nameParam = req.url_params.get("name");
        if (nameParam == nullptr) {
            return crow::response(400, "Name param is empty.");
        }

        std::string name{nameParam};
        std::vector<std::string> v = dbAPI.fetchData(name);

        if (v.empty()) {
            return crow::response(404, "Data is empty.");
        }

        std::vector<crow::json::wvalue> json_data;
        for (std::string& d : v) json_data.push_back(d);

        crow::json::wvalue js;
        js["data"] = crow::json::wvalue::list(json_data);
        return crow::response(200, js);
    });

    app.port(8000)
       .multithreaded()
       .run();

    return 0;
}

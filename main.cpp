#include "crow.h"

int main() {
    crow::SimpleApp app; 

    CROW_ROUTE(app, "/").methods("GET"_method)([]() {
        auto page = crow::mustache::load_text("index.html");
        return page;
    });

    CROW_ROUTE(app, "/login").methods("GET"_method, "POST"_method)([]() {
        auto page = crow::mustache::load_text("login.html");
        return page;
    });

    app.port(8000).multithreaded().run();
    
}

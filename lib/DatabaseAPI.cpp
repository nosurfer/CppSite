#include <iostream>
#include "DatabaseAPI.h"

DatabaseAPI::DatabaseAPI(const std::string& dbName) {
    char* errMsg;

    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    std::cout << "Opened database successfully!" << std::endl;

    const char* queries[] = {
        R"(
            CREATE TABLE IF NOT EXISTS users (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                data TEXT NULL
            );
        )",
        R"(
            CREATE TABLE IF NOT EXISTS secret (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                secret TEXT NULL
            );
        )",
        R"(
            INSERT INTO secret (secret)
            VALUES ('I would have given you the flag if it were here');
        )"
    };

    for (const char* query : queries) {
        if (sqlite3_exec(db, query, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "Error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
}

DatabaseAPI::~DatabaseAPI() {
    sqlite3_close(db);
}

int DatabaseAPI::insertValue(const std::string& name, const std::string& data) {
    const char* query = "INSERT INTO users (name, data) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Value inserted!" << std::endl;
    }

    sqlite3_finalize(stmt);
    return 0;
}

std::vector<std::string> DatabaseAPI::fetchData(const std::string& name) {
    std::string query = "SELECT data FROM users WHERE name='" + name + "';";
    sqlite3_stmt* stmt;
    std::vector<std::string> v;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return v;
    }
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* data = sqlite3_column_text(stmt, 0);
        if (data != nullptr) {
            v.push_back(std::string(reinterpret_cast<const char*>(data)));
        }
    }

    sqlite3_finalize(stmt);
    return v;
}

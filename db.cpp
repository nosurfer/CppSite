#include <iostream>
#include <sqlite3.h>

class DatabaseAPI {
private:
    sqlite3* db;
public:
    DatabaseAPI(const std::string& dbName) {
        if (sqlite3_open(dbName.c_str(), &db)) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Opened database successfully!" << std::endl;
        }

        const char* createTable = R"(
            CREATE TABLE IF NOT EXISTS users (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                data TEXT
            );
        )";

        char* errMsg;
        if (sqlite3_exec(db, createTable, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "Can't create table: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }

    ~DatabaseAPI() {
        sqlite3_close(db);
    }



}
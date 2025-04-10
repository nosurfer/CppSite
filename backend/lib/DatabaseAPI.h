#pragma once

#include <sqlite3.h>
#include <vector>
#include <string>

class DatabaseAPI {
private:
    sqlite3* db;
public:
    DatabaseAPI(const std::string& dbName);

    ~DatabaseAPI();

    int insertValue(const std::string& name, const std::string& data);

    std::vector<std::string> fetchData(const std::string& name);
};

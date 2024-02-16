#include <iostream>
#include <string>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open_v2("ConstructCo.db", &db, SQLITE_OPEN_READWRITE, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    sqlite3_close(db);

    return 0;
}
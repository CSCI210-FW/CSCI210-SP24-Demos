#include <iostream>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open_v2("ConstructCo.db", &db, SQLITE_OPEN_READWRITE, NULL);

    sqlite3_close(db);

    return 0;
}
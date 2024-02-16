#include <iostream>
#include <string>
#include <sqlite3.h>

int genericRowCallback(void *, int, char **, char **); // void * is a memory address of unknown type, int is the num of cols in the result, char** is an array of strings with the column values, char** is an array of strings with the column names

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
    else
    {
        std::cout << "Database opened successfully." << std::endl;
    }
    std::string query = "select * from employee";
    rc = sqlite3_exec(db, query.c_str(), genericRowCallback, NULL, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "There was an error - select callback: " << sqlite3_errmsg(db) << std::endl;
        std::cout << query << std::endl;
    }
    std::string lname, fname, mi;
    int job, years;
    char formatDate[80];
    time_t currentDate = time(NULL);
    strftime(formatDate, 80, "%F %T", localtime(&currentDate));
    std::string hiredate(formatDate);
    lname = "Brown";
    fname = "Charlie";
    job = 504;
    years = 0;
    query = "insert into employee(emp_lname, emp_fname, emp_hiredate, job_code, emp_years) ";
    query += "values ('";
    query += lname + "', '";
    query += fname + "', '";
    query += hiredate + "', ";
    query += std::to_string(job) + ", ";
    query += std::to_string(years) + ");";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "There was an error - insert: " << sqlite3_errmsg(db) << std::endl;
        std::cout << query << std::endl;
    }
    else
    {
        int emp_num = sqlite3_last_insert_rowid(db);
        std::cout << fname << " " << lname << " inserted into the database as employee number " << emp_num << std::endl;
    }

    sqlite3_close(db);

    return 0;
}

int genericRowCallback(void *extData, int numCols, char **values, char **colNames)
{
    for (int i = 0; i < numCols; i++)
    {
        std::cout << colNames[i] << ": ";
        if (values[i] != NULL)
            std::cout << values[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return SQLITE_OK;
}

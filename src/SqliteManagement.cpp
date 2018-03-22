#include "SqliteManagement.h"

SqliteManagement* SqliteManagement::instance = 0;

SqliteManagement::SqliteManagement()
{
    this->sqliteDBAnalysis = new SqliteDBAnalysis ();
    //ctor
}

SqliteManagement::~SqliteManagement()
{
    //dtor
}

SqliteManagement* SqliteManagement::getInstance(){
    if (instance == 0) {
        instance = new SqliteManagement();
    }
    return instance;
}



void SqliteManagement::processSqliteDb (){
    std::cout<<"\n\nSqlite processing";
    std::cout<<"\nOpening sql database";
    int status;
    status=sqlite3_open(this->getDbFilePath()->c_str(), &sqliteDb);
    if (status){
        std::cerr<<"\nConnection failed, cant open database: "<<sqlite3_errmsg(sqliteDb);
    } else {
        std::cout<<"\nConnection established";
        std::cout<<"\nInitiating database queries";

        char *errorMessage = 0;

        //First query, retrieving table names with indexes
        std::string sql= "select DISTINCT(t1.tbl_name), t2.rootpage from SQLITE_MASTER t1 LEFT JOIN (select type, tbl_name, rootpage from SQLITE_MASTER t1 WHERE type = 'index') t2 ON t1.tbl_name = t2.tbl_name";

        const char* data = "Callback function called";

        status = sqlite3_exec(sqliteDb, sql.c_str(), &SqliteManagement::callbackTableNamesWithLastIndex, (void*)data, &errorMessage);
        if( status != SQLITE_OK ) {
            fprintf(stderr, "SQL error on first query: %s\n", errorMessage);
            sqlite3_free(errorMessage);
        } else {
            fprintf(stdout, "First query done successfully\n");
        }

        //Second queries, retrieving number of rows per table.

        for (unsigned i = 0; i < this->getSqliteDBAnalysis()->getTablesName().size(); ++i){
            sql= "select count(*) as rows from "+this->getSqliteDBAnalysis()->getTablesName()[i];

            data = "Callback function called";

            status = sqlite3_exec(sqliteDb, sql.c_str(), &SqliteManagement::callbackRowsPerTable, (void*)data, &errorMessage);
            if( status != SQLITE_OK ) {
                fprintf(stderr, "SQL error on second query: %s\n", errorMessage);
                sqlite3_free(errorMessage);
            } else {
                fprintf(stdout, "Second query done successfully\n");
            }
        }

    }
    std::cout<<"\n\n";
    sqlite3_close(sqliteDb);
}

int SqliteManagement::callbackTableNamesWithLastIndex(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for(i = 0; i<argc; i++){
        if (strcmp(azColName[i], "tbl_name")==0){
            SqliteManagement::getInstance()->getSqliteDBAnalysis()->addTableName(std::string(argv[i] ? argv[i] : "NULL"));
        }
        if (strcmp(azColName[i], "rootpage")==0){
            SqliteManagement::getInstance()->getSqliteDBAnalysis()->addTableLastIdGenerated(std::string(argv[i] ? argv[i] : "NULL"));
        }
    }

    printf("\n");
    return 0;
}

int SqliteManagement::callbackRowsPerTable(void *data, int argc, char **argv, char **azColName){
    fprintf(stderr, "%s: ", (const char*)data);

    SqliteManagement::getInstance()->getSqliteDBAnalysis()->addTableRowsNumber(std::string(argv[0]));

    printf("\n");
    return 0;
}

std::string  SqliteManagement::printSqliteDBAnalysis(){
    std::stringstream output;

    output << "Printing sqlite database information:\n\n"
        << "Database file size: "<<this->getDbFileSize()<<" bytes.\n"
        << "Printing tables and sizes information:\n";

    for (unsigned i = 0; i < this->getSqliteDBAnalysis()->getTablesName().size(); ++i){
        output << "\nTABLE NAME: "<<this->getSqliteDBAnalysis()->getTablesName()[i]
            << "\n\tLAST INDEX GENERATED: "<<this->getSqliteDBAnalysis()->getTablesLastIdsGenerated()[i]
            << "\n\tROWS: "<<this->getSqliteDBAnalysis()->getTablesRowsNumber()[i];
    }
    output<<"\n\nEND SQLITE DATABASE PRINTING\n\n";

    std::cout << output.str();

    return output.str();
}

void SqliteManagement::processDbFile (FILE *dbFile){
    this->processFile(dbFile);
}

void SqliteManagement::setDbFilePath (std::string* dbFilePath){
    this->setFilePath(dbFilePath);
}

std::string* SqliteManagement::getDbFilePath(){
    return this->getFilePath();
}

void SqliteManagement::setDbFileSize (long dbFileSize){
    this->setFileSize(dbFileSize);
}

long SqliteManagement::getDbFileSize(){
    return this->getFileSize();
}

void SqliteManagement::setSqliteDb (sqlite3* sqliteDb){
    this->sqliteDb = sqliteDb;
}

sqlite3* SqliteManagement::getSqliteDb(){
    return this->sqliteDb;
}

SqliteDBAnalysis* SqliteManagement::getSqliteDBAnalysis (){
    return this->sqliteDBAnalysis;
}

#include "SqliteManagement.h"

SqliteManagement* SqliteManagement::instance = 0;

SqliteManagement::SqliteManagement()
{
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
        int integerResponse = 0;

        //First query retrieving table names with indexes
        std::string sql= "select t1.tbl_name, t2.rootpage from SQLITE_MASTER t1 LEFT JOIN (select type, tbl_name, rootpage from SQLITE_MASTER t1 WHERE type = 'index') t2 ON t1.tbl_name = t2.tbl_name";

        const char* data = "Callback function called";

        status = sqlite3_exec(sqliteDb, sql.c_str(), &SqliteManagement::callbackTableNamesWithLastIndex, (void*)data, &errorMessage);
        if( status != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", errorMessage);
            sqlite3_free(errorMessage);
        } else {
            fprintf(stdout, "First query done successfully\n");
        }
    }
    std::cout<<"\n\n";
    sqlite3_close(sqliteDb);
}

int SqliteManagement::callbackTableNamesWithLastIndex(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}

int SqliteManagement::callbackLastIndexPerTable(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
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

SqliteDBAnalysis SqliteManagement::getSqliteDBAnalysis (){
    return this->sqliteDBAnalysis;
}

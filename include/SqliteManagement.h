#ifndef SQLITEMANAGEMENT_H
#define SQLITEMANAGEMENT_H
#include "FileMetadata.h"
#include "sqlite3.h"


class SqliteManagement : FileMetadata
{
    public:
        static SqliteManagement* getInstance();
        virtual ~SqliteManagement();
        bool readDatabase ();

        void processDbFile (FILE *logFile);

        void processSqliteDb ();

        //Getters and setters
        void setDbFilePath (std::string* dbFilePath);
        std::string* getDbFilePath();

        void setDbFileSize (long dbFileSize);
        long getDbFileSize();

        void setSqliteDb (sqlite3* sqliteDb);
        sqlite3* getSqliteDb();

        static int callbackTableNames(void *data, int argc, char **argv, char **azColName);

    protected:

    private:
        SqliteManagement();
        static SqliteManagement* instance;
        sqlite3* sqliteDb;
};
#endif // SQLITEMANAGEMENT_H

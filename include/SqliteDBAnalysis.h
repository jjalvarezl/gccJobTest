#ifndef SQLITEDBANALYSIS_H
#define SQLITEDBANALYSIS_H
#include <iostream>
#include <boost/container/vector.hpp>

class SqliteDBAnalysis
{
    public:
        SqliteDBAnalysis();
        virtual ~SqliteDBAnalysis();

        void addTableName (std::string tableName);
        void addTableSize (std::string tableSize);
        void addTableRowsNumber (std::string tableRowsNumber);
        void addTableLastIdGenerated (std::string tableLastIdGenerated);

        boost::container::vector<std::string> getTablesName ();
        boost::container::vector<std::string> getTablesRowsNumber ();
        boost::container::vector<std::string> getTablesSize ();
        boost::container::vector<std::string> getTablesLastIdsGenerated ();


    protected:

    private:
        boost::container::vector<std::string> tablesNames;
        boost::container::vector<std::string> tablesSizes;
        boost::container::vector<std::string> tablesLastIdsGenerated;
        boost::container::vector<std::string> tablesRowsNumber;
};

#endif // SQLITEDBANALYSIS_H

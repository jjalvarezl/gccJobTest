#ifndef SQLITEDBANALYSIS_H
#define SQLITEDBANALYSIS_H
#include <boost/container/vector.hpp>

class SqliteDBAnalysis
{
    public:
        SqliteDBAnalysis();
        virtual ~SqliteDBAnalysis();

        void addTableName (std::string tableName);
        void addTableSize (std::string tableSize);
        void addTableLastIdGenerated (std::string tableLastIdGenerated);

        boost::container::vector<std::string> getTablesName ();
        boost::container::vector<std::string> getTablesSize ();
        boost::container::vector<std::string> getTableLastIdsGenerated ();


    protected:

    private:
        boost::container::vector<std::string> tableNames;
        boost::container::vector<std::string> tableSizes;
        boost::container::vector<std::string> tableLastIdsGenerated;
};

#endif // SQLITEDBANALYSIS_H

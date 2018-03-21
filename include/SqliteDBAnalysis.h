#ifndef SQLITEDBANALYSIS_H
#define SQLITEDBANALYSIS_H
#include <boost/container/vector.hpp>

class SqliteDBAnalysis
{
    public:
        SqliteDBAnalysis();
        virtual ~SqliteDBAnalysis();

    protected:

    private:
        boost::container::vector<std::string> tableNames;
        boost::container::vector<std::string> tableSizes;
        boost::container::vector<std::string> tableLastIdsGenerated;
};

#endif // SQLITEDBANALYSIS_H

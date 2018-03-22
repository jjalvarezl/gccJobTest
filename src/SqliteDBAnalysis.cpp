#include "SqliteDBAnalysis.h"

SqliteDBAnalysis::SqliteDBAnalysis()
{
    //ctor
}

SqliteDBAnalysis::~SqliteDBAnalysis()
{
    //dtor
}


void SqliteDBAnalysis::addTableName (std::string tableName){
    this->tableNames.insert(this->tableNames.end(), tableName);
}

void SqliteDBAnalysis::addTableSize (std::string tableSize){
    this->tableSizes.insert(this->tableSizes.end(), tableSize);
}

void SqliteDBAnalysis::addTableLastIdGenerated (std::string tableLastIdGenerated){
    this->tableLastIdsGenerated.insert(this->tableLastIdsGenerated.end(), tableLastIdGenerated);
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesName (){
    return this->tableNames;
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesSize (){
    return this->tableSizes;
}

boost::container::vector<std::string> SqliteDBAnalysis::getTableLastIdsGenerated (){
    return this->tableLastIdsGenerated;
}

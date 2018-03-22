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
    this->tablesNames.insert(this->tablesNames.end(), tableName);
}

void SqliteDBAnalysis::addTableSize (std::string tableSize){
    this->tablesSizes.insert(this->tablesSizes.end(), tableSize);
}

void SqliteDBAnalysis::addTableLastIdGenerated (std::string tableLastIdGenerated){
    this->tablesLastIdsGenerated.insert(this->tablesLastIdsGenerated.end(), tableLastIdGenerated);
}

void SqliteDBAnalysis::addTableRowsNumber (std::string tableRowsNumber){
    this->tablesRowsNumber.insert(this->tablesRowsNumber.end(), tableRowsNumber);
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesName (){
    return this->tablesNames;
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesSize (){
    return this->tablesSizes;
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesLastIdsGenerated (){
    return this->tablesLastIdsGenerated;
}

boost::container::vector<std::string> SqliteDBAnalysis::getTablesRowsNumber (){
    return this->tablesRowsNumber;
}

#ifndef ZLIBMANAGEMENT_H
#define ZLIBMANAGEMENT_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "boost/filesystem.hpp"
#include "unzip.h"
#include "FileMetadata.h"
#include "LogMetadata.h"
#include "SqliteManagement.h"

class ZlibManagement
{
    public:
        static ZlibManagement* getInstance();
        void setCompressedFilePath(std::string* path);
        bool uncompressFile();

        boost::container::vector<LogMetadata*> getLogFiles();
        boost::container::vector<FileMetadata> getNormalFiles();

        std::string printZipFiles();
        std::string printLogFiles();

    protected:

    private:
        std::string* path;
        static ZlibManagement* instance;
        ZlibManagement();

        boost::container::vector<LogMetadata*> logFiles;
        boost::container::vector<FileMetadata> normalFiles;
};

#endif // ZLIBMANAGEMENT_H

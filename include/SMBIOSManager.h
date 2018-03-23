#ifndef SMBIOSMANAGER_H
#define SMBIOSMANAGER_H
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include "FileMetadata.h"

class SMBIOSManager: FileMetadata
{
    public:
        virtual ~SMBIOSManager();

        void processSMBIOSFile (FILE *SMBIOSFile);

        std::string* getHexPairByOffset (int offset);
        std::string* getHexPairsByOffsetRegions (int minorOffset, int majorOffset);

        //Setters and getters
        void setSMBIOSFilePath (std::string* SMBIOSFilePath);
        std::string* getSMBIOSFilePath();

        void setSMBIOSFileSize (long SMBIOSFileSize);
        long getSMBIOSFileSize();

        void setHexBinary (std::string* hexBinary);
        std::string* getHexBinary ();

        //SINGLETON
        static SMBIOSManager* getInstance();


    protected:

    private:
        SMBIOSManager();
        std::string* hexBinary;
        static SMBIOSManager* instance;
};

#endif // SMBIOSMANAGER_H

#ifndef LOGLINEMETADATA_H
#define LOGLINEMETADATA_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define INFO "INFO"
#define DEBUG "DEBUG"
#define ERROR "ERROR"

class LogLineMetadata
{
    public:
        LogLineMetadata();
        virtual ~LogLineMetadata();

        void addMatch();

        //Getters and setters
        void setLogLine (std::string* logLine);
        std::string* getLogLine ();

        void setMatchsNumber (int matchsNumber);
        int getMatchsNumber();

        void setLineSize (long lineSize);
        long getLineSize ();

        void setLogType (std::string* logType);
        std::string* getLogType ();

    protected:

    private:
        std::string* logLine;
        int matchsNumber;
        long lineSize;
        std::string* logType;
};

#endif // LOGLINEMETADATA_H

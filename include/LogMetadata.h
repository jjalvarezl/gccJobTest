#ifndef LOGMETADATA_H
#define LOGMETADATA_H
#include <boost/container/vector.hpp>
#include <stdlib.h>
#include "FileMetadata.h"
#include "LogLineMetadata.h"

class LogMetadata : FileMetadata
{
    public:
        LogMetadata();
        virtual ~LogMetadata();

        void processLogFile (FILE *logFile);
        void processLogLine (std::string* logLine, long lineSize);

        //Getters and setters
        void setLogFilePath (std::string* logFilePath);
        std::string* getLogFilePath();

        void setLogFileSize (long logFileSize);
        long getLogFileSize();

        void setNumberOfErrors (int numberOfErrors);
        int getNumberOfErrors ();

        void setNumberInfoLogs (int numberInfoLogs);
        int getNumberInfoLogs ();

        void setNumberDebugLogs (int numberDebugLogs);
        int getNumberDebugLogs ();

        void setNumberErrorLogs (int numberErrorLogs);
        int getNumberErrorLogs ();

        void setLongestLogLine (LogLineMetadata longestLogLine);
        LogLineMetadata getLongestLogLine ();

        void setMoreFrecuentError (LogLineMetadata moreFrecuentError);
        LogLineMetadata getMoreFrecuentError ();

        void setMoreThan10M (bool moreThan10M);
        bool isMoreThan10M ();

        boost::container::vector<LogLineMetadata> getLogLineCounter();

        void printLogLineCounter ();

    protected:

    private:
        int numberOfErrors;
        int numberInfoLogs;
        int numberDebugLogs;
        int numberErrorLogs;
        bool moreThan10M;
        LogLineMetadata longestLogLine;
        LogLineMetadata moreFrecuentError;
        long flagForLongestLogLine;
        int flagForMoreFrecuentError;
        boost::container::vector<LogLineMetadata> logLineCounter;
};

#endif // LOGMETADATA_H

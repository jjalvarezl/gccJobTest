#include "LogMetadata.h"

LogMetadata::LogMetadata():FileMetadata()
{
    this->numberDebugLogs = 0;
    this->numberErrorLogs = 0;
    this->numberInfoLogs = 0;
    this->moreThan10M=false;
    this->flagForMoreFrecuentError = 0;
    longestLogLine = new LogLineMetadata();
    moreFrecuentError.setLogLine(new std::string(""));
    moreFrecuentError.setMatchsNumber(0);
    //ctor
}

LogMetadata::~LogMetadata()
{
    //dtor
}

void LogMetadata::processLogFile (FILE *logFile){
    this->processFile(logFile);

    std::cout<<"Analizando: "<<this->getLogFilePath()->c_str();

    logFile = fopen( this->getLogFilePath()->c_str(), "r" );

    //Setting more than 10M
    if (this->getFileSize()> 10000000){
        this->setMoreThan10M(true);
    }

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, logFile)) != -1) {
        this->processLogLine(new std::string (line), static_cast<long>(read));
    }
}

void LogMetadata::processLogLine (std::string* logLine, long lineSize){

    LogLineMetadata logLineMetadata;
    if (logLine->find(std::string("INFO")) != std::string::npos){
        logLineMetadata.setLogType(new std::string("INFO"));
        this->numberInfoLogs++;
    }

    if (logLine->find(std::string("DEBUG")) != std::string::npos){
        logLineMetadata.setLogType(new std::string("DEBUG"));
        this->numberDebugLogs++;
    }

    if (logLine->find(std::string("ERROR")) != std::string::npos){
        logLineMetadata.setLogType(new std::string("ERROR"));
        this->numberErrorLogs++;
    }

    if (strcmp(logLineMetadata.getLogType()->c_str(),"") != 0){

        bool isAMatch = false;

        //setting the longest log line
        if (lineSize > this->flagForLongestLogLine){
            std::cout << "ENTRA EN EL FLAG DE LINEA MAS LARGA";
            this->flagForLongestLogLine = lineSize;
            this->longestLogLine->setLineSize(lineSize);
            this->longestLogLine->setLogLine(logLine);
            this->longestLogLine->setLogType(logLineMetadata.getLogType());
        }

        //setting the first log as most frecuent error in order to compare in the iterator
        if ((strcmp(this->moreFrecuentError.getLogLine()->c_str(), "") == 0) &&
            (strcmp(logLineMetadata.getLogType()->c_str(), "ERROR")== 0)){
            this->moreFrecuentError.setLineSize(lineSize);
            this->moreFrecuentError.setLogLine(logLine);
            this->moreFrecuentError.setLogType(logLineMetadata.getLogType());
            this->flagForMoreFrecuentError = 1;
        }


        //AQUÍ HAY ALGO QUE ESTÁ MAL CON ESTE CLASIFICADOR, REVISAR
        for (unsigned i = 0; i < logLineCounter.size() && !isAMatch; ++i){
            if (strcmp(logLineCounter[i].getLogLine()->c_str(), logLine->c_str()) == 0){
                logLineCounter[i].addMatch();

                //Setting the more frecuent error
                if ((logLineCounter[i].getMatchsNumber() > this->flagForMoreFrecuentError) && (strcmp (logLineCounter[i].getLogType()->c_str(), "ERROR")==0)){
                    this->moreFrecuentError = logLineCounter[i];
                    this->flagForMoreFrecuentError = logLineCounter[i].getMatchsNumber();
                }
                isAMatch = true;
            }
        }

        if (!isAMatch){
            logLineMetadata.setLogLine(logLine);
            logLineMetadata.setLineSize(lineSize);
            logLineMetadata.addMatch();
            this->logLineCounter.insert(logLineCounter.end(), logLineMetadata);
        }
    }
}

void LogMetadata::setLogFilePath (std::string* logFilePath){
    this->setFilePath(logFilePath);
}

std::string* LogMetadata::getLogFilePath(){
    return this->getFilePath();
}

void LogMetadata::setLogFileSize (long logFileSize){
    this->setFileSize(logFileSize);
}

long LogMetadata::getLogFileSize(){
    return this->getFileSize();
}

void LogMetadata::setMoreThan10M (bool moreThan10M){
    this->moreThan10M = moreThan10M;
}

bool LogMetadata::isMoreThan10M(){
    return this->moreThan10M;
}


void LogMetadata::setLongestLogLine (LogLineMetadata* longestLogLine){
    this->longestLogLine = longestLogLine;
}
LogLineMetadata* LogMetadata::getLongestLogLine (){
    return this->longestLogLine;
}

void LogMetadata::setMoreFrecuentError (LogLineMetadata moreFrecuentError){
    this->moreFrecuentError = moreFrecuentError;
}
LogLineMetadata LogMetadata::getMoreFrecuentError (){
    return this->moreFrecuentError;
}

boost::container::vector<LogLineMetadata> LogMetadata::getLogLineCounter(){
    return this->logLineCounter;
}

void LogMetadata::printLogLineCounter (){
    for (boost::container::vector<LogLineMetadata>::iterator it = logLineCounter.begin() ; it != logLineCounter.end(); ++it){
        std::cout <<"LINEA DE LOG: "<<it->getLogLine()->c_str()<<" N MATCHS: "<<it->getMatchsNumber();
    }
}

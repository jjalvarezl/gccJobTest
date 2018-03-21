#include "LogLineMetadata.h"

LogLineMetadata::LogLineMetadata()
{
    this->logLine = new std::string ("");
    this->logType = new std::string ("");
    this->matchsNumber = 0;
    //ctor
}

LogLineMetadata::~LogLineMetadata()
{
    //dtor
}

void LogLineMetadata::addMatch (){
    this->matchsNumber++;
}

void LogLineMetadata::setLogType(std::string* logType){
    this->logType = logType;
}

std::string* LogLineMetadata::getLogType (){
    return this->logType;
}


void LogLineMetadata::setLogLine (std::string* logLine){
    this->logLine = logLine;
}

std::string* LogLineMetadata::getLogLine (){
    return this->logLine;
}

void LogLineMetadata::setMatchsNumber (int matchsNumber){
    this->matchsNumber = matchsNumber;
}

int LogLineMetadata::getMatchsNumber (){
    return this->matchsNumber;
}

void LogLineMetadata::setLineSize (long lineSize){
    this->lineSize = lineSize;
}

long LogLineMetadata::getLineSize (){
    return this->lineSize;
}

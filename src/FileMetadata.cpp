#include "FileMetadata.h"

FileMetadata::FileMetadata()
{
    this->filePath = new std::string ("");
    this->fileSize = -1;
    //ctor
}

FileMetadata::~FileMetadata()
{
    //dtor
}

void FileMetadata::processFile (FILE *file) {
    fseek(file, 0, SEEK_END);
    this->fileSize=ftell(file);
}

void FileMetadata::setFilePath (std::string* filePath){
    this->filePath = filePath;
}

std::string* FileMetadata::getFilePath (){
    return this->filePath;
}

void FileMetadata::setFileSize (long fileSize){
    this->fileSize = fileSize;
}

long FileMetadata::getFileSize (){
    return this->fileSize;
}

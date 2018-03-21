#ifndef FILEMETADATA_H
#define FILEMETADATA_H
#include <string.h>
#include <stdio.h>
#include <iostream>

class FileMetadata
{
    public:
        FileMetadata();
        virtual ~FileMetadata();

        void processFile (FILE *file);

        //Getters and setters
        void setFilePath (std::string* filePath);
        std::string* getFilePath ();

        void setFileSize (long fileSize);
        long getFileSize ();

    protected:

    private:
        std::string* filePath;
        long fileSize;
};

#endif // FILEMETADATA_H

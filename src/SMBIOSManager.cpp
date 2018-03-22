#include "SMBIOSManager.h"

SMBIOSManager* SMBIOSManager::instance = 0;

SMBIOSManager::SMBIOSManager()
{
    this->hexBinary = new std::string ("");
    //ctor
}

SMBIOSManager::~SMBIOSManager()
{
    //dtor
}

SMBIOSManager* SMBIOSManager::getInstance(){
    if (instance == 0) {
        instance = new SMBIOSManager();
    }
    return instance;
}

void SMBIOSManager::processSMBIOSFile (FILE *SMBIOSFile){
    this->processFile(SMBIOSFile);

    FILE* fp = fopen(this->getFilePath()->c_str(), "rb");
    if (fp) { /* ignore if failed to open */
        int c;
        char out[4] = {0};
        while ((c = fgetc(fp)) != EOF) {
            int p = c / 16;
            out[0] = p + (p < 10 ? 48 : 87);
            out[1] = (c - p*16) + ((c - p*16) < 10 ? 48 : 87);

            printf(" %s", out);
            this->hexBinary->append(out);
        }
    }
}

void SMBIOSManager::setSMBIOSFilePath (std::string* SMBIOSFilePath){
    this->setFilePath(SMBIOSFilePath);
}

std::string* SMBIOSManager::getSMBIOSFilePath(){
    return this->getFilePath();
}

void SMBIOSManager::setSMBIOSFileSize (long SMBIOSFileSize){
    this->setFileSize(SMBIOSFileSize);
}

long SMBIOSManager::getSMBIOSFileSize(){
    return this->getFileSize();
}

void SMBIOSManager::setHexBinary (std::string* hexBinary){
    this->hexBinary = hexBinary;
}

std::string* SMBIOSManager::getHexBinary (){
    return this->hexBinary;
}

std::string* SMBIOSManager::getHexPairByOffset (int offset){
    int position = offset*2;

    if (position > this->hexBinary->length()){
        return new std::string ("-1");
    } else {
        std::stringstream sstm;
        sstm << this->hexBinary->at(position) << this->hexBinary->at(position+1);
        //std::string* returnValue = new std::string ();
        //returnValue = this->hexBinary->at(position) + this->hexBinary->at(position+1);
        return new std::string(sstm.str());
    }
}

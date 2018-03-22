#include "ZlibManagement.h"
#define dir_delimter '/'
#define MAX_FILENAME 512
#define READ_SIZE 8192

ZlibManagement* ZlibManagement::instance = 0;

ZlibManagement::ZlibManagement()
{
    path = new std::string("");
    //ctor
}

ZlibManagement* ZlibManagement::getInstance(){
    if (instance == 0) {
        instance = new ZlibManagement();
    }
    return instance;
}

void ZlibManagement::setCompressedFilePath(std::string* path){
    this->path = path;
}

boost::container::vector<LogMetadata*> ZlibManagement::getLogFiles(){
    return this->logFiles;
}

boost::container::vector<FileMetadata> ZlibManagement::getNormalFiles(){
    return this->normalFiles;
}


bool ZlibManagement::uncompressFile(){

    std::cout << "Start zip and all its contained files process";

    // Open the zip file
    unzFile *zipfile = (void**) unzOpen( this->path->c_str() );
    if ( zipfile == NULL )
    {
        printf( "%s: not found\n", this->path->c_str());
        return -false;
    }

    // Get info about the zip file
    unz_global_info global_info;
    if ( unzGetGlobalInfo( zipfile, &global_info ) != UNZ_OK )
    {
        printf( "could not read file global info\n" );
        unzClose( zipfile );
        return false;
    }

    // Buffer to hold data read from the zip file.
    char read_buffer[ READ_SIZE ];

    // Loop to extract all files
    uLong i;
    for ( i = 0; i < global_info.number_entry; ++i )
    {
        // Get info about current file.
        unz_file_info file_info;
        char filename[ MAX_FILENAME ];
        if ( unzGetCurrentFileInfo(
            zipfile,
            &file_info,
            filename,
            MAX_FILENAME,
            NULL, 0, NULL, 0 ) != UNZ_OK )
        {
            printf( "could not read file info\n" );
            unzClose( zipfile );
            return false;
        }

        // Check if this entry is a directory or file.
        const size_t filename_length = strlen( filename );
        if ( filename[ filename_length-1 ] == dir_delimter )
        {
            // Entry is a directory, so create it.
            printf( "dir:%s\n", filename );
            mkdir( filename, 0777 );
        }
        else
        {
            // Entry is a file, so extract it.
            printf( "file:%s\n", filename );
            if ( unzOpenCurrentFile( zipfile ) != UNZ_OK )
            {
                printf( "could not open file\n" );
                unzClose( zipfile );
                return false;
            }

            // Open a file to write out the data.
            FILE *out = fopen( filename, "wb" );

            if ( out == NULL )
            {
                printf( "could not open destination file\n" );
                unzCloseCurrentFile( zipfile );
                unzClose( zipfile );
                return false;
            }

            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile( zipfile, read_buffer, READ_SIZE );
                if ( error < 0 )
                {
                    printf( "error %d\n", error );
                    unzCloseCurrentFile( zipfile );
                    unzClose( zipfile );
                    return false;
                }

                // Write data to file.
                if ( error > 0 )
                {
                    fwrite( read_buffer, error, 1, out ); // You should check return of fwrite...
                }
            } while ( error > 0 );

            //Process opened file
            std::string *stringFilename = new std::string(filename);

            boost::filesystem::path p(filename);
            std::string extension = "";
            if (strcmp(p.stem().c_str(), "")  != 0 &&
                (strcmp((extension = boost::filesystem::extension(filename)).c_str(),".log")==0 ||
                 strcmp((extension = boost::filesystem::extension(p.stem())).c_str(),".log")==0)){
                LogMetadata* logMetadata = new LogMetadata();
                logMetadata->setLogFilePath(stringFilename);
                logMetadata->processLogFile(out);
                /*::cout <<"LOG: "<< "FILE NAME: "<<logMetadata.getLogFilePath()->c_str();
                std::cout <<"FILE SIZE: "<<logMetadata.getLogFileSize();
                std::cout <<"FILE EXT: "<<extension.c_str();
                std::cout <<"MORE THAN 10M: ";
                std::cout <<logMetadata.isMoreThan10M();
                std::cout <<"MORE FRECUENT ERROR: ";
                std::cout <<logMetadata.getMoreFrecuentError().getLogLine()->c_str()<<" ERROR MATCHS: "<<logMetadata.getMoreFrecuentError().getMatchsNumber();
                std::cout <<"LONGEST LOG LINE: ";
                std::cout <<""<<logMetadata.getLongestLogLine().getLogLine()->c_str()<<" SIZE: "<<logMetadata.getLongestLogLine().getLineSize();
                std::cout <<"END OF LOG ANALYSIS";*/
                this->logFiles.insert(this->logFiles.end(), logMetadata);
                //<<"VECTOR DE COINCIDENCIAS: "<<logMetadata->getLogLineCounter().front().getLogLine()->c_str();
                /*logMetadata->printLogLineCounter();
                exit(0);*/
            } else {
                extension = boost::filesystem::extension(filename);
                FileMetadata fileMetadata;
                fileMetadata.processFile(out);
                fileMetadata.setFilePath(stringFilename);
                std::cout << "NORMAL FILE: " << "FILE NAME: "<<fileMetadata.getFilePath()->c_str()<<" FILE SIZE: "<<fileMetadata.getFileSize()<<" FILE EXT: "<<extension.c_str();

                //If sqlite file
                if (strcmp(p.filename().c_str(), "Agent9.3.2.dat") == 0){
                    std::cout<<" ARANDA SQLITE FILE FOUNDED!!!!";
                    SqliteManagement::getInstance()->processDbFile(out);
                    SqliteManagement::getInstance()->setDbFilePath(new std::string (filename));
                    SqliteManagement::getInstance()->processSqliteDb();
                    SqliteManagement::getInstance()->printSqliteDBAnalysis();
                }

                this->normalFiles.insert(this->normalFiles.end(), fileMetadata);
            }
            fclose( out );
        }

        unzCloseCurrentFile( zipfile );

        // Go the the next entry listed in the zip file.
        if ( ( i+1 ) < global_info.number_entry )
        {
            if ( unzGoToNextFile( zipfile ) != UNZ_OK )
            {
                printf( "cound not read next file\n" );
                unzClose( zipfile );
                return false;
            }
        }
    }

    unzClose( zipfile );

    std::cout << "Finish zip and all its contained files process";

    return true;
}

std::string ZlibManagement::printZipFiles(){
    std::stringstream output;

    output << "Printing zip files structure:";

    for (unsigned i = 0; i < this->logFiles.size(); ++i){
        output << "\n\nFILE: "<<this->logFiles[i]->getLogFilePath()->c_str();
        output << "\n\tSIZE: "<<this->logFiles[i]->getLogFileSize()<<" bytes";
    }

    for (unsigned i = 0; i < this->normalFiles.size(); ++i){
        output << "\n\nFILE: "<<this->normalFiles[i].getFilePath()->c_str();
        output << "\n\tSIZE: "<<this->normalFiles[i].getFileSize()<<" bytes";
    }

    output<<"\n\nEND ZIP FILES DATA PRINTING\n\n";

    std::cout << output.str();

    return output.str();
}

std::string ZlibManagement::printLogFiles(){
    std::stringstream output;

    output << "Printing log files metadata:"<<this->logFiles.size();

    for (unsigned i = 0; i < this->logFiles.size(); ++i){
        boost::filesystem::path p(this->logFiles[i]->getLogFilePath()->c_str());

        output << "\n\n --------------------------------------------------------"<<i
            << "\nLOG FILE: "<<this->logFiles[i]->getLogFilePath()->c_str()
            << "\n\tLOG SIZE: "<<this->logFiles[i]->getLogFileSize()<<" bytes"
            << "\n\tNUMBER OF ERROR LINES: "<<this->logFiles[i]->getNumberErrorLogs()<<" times"
            << "\n\tNUMBER OF INFO LINES: "<<this->logFiles[i]->getNumberInfoLogs()<<" times"
            << "\n\tNUMBER OF DEBUG LINES: "<<this->logFiles[i]->getNumberDebugLogs()<<" times"
            << "\n\tIS MORE THAN 10M: "<<(this->logFiles[i]->isMoreThan10M()? "TRUE" : "FALSE")
            << "\n\tMORE FRECUENT ERROR: "<<this->logFiles[i]->getMoreFrecuentError()->getLogLine()->c_str()
            << "\n\t\tTIMES THAT THIS ERROR MATCHS: "<<this->logFiles[i]->getMoreFrecuentError()->getMatchsNumber()
            << "\n\tLONGEST LINE: "<<this->logFiles[i]->getLongestLogLine()->getLogLine()->substr(0,0)<<"(CAN NOT PRINT ALL LONG..)"
            << "\n\t\tTHIS LINE SIZE: "<<this->logFiles[i]->getLongestLogLine()->getLineSize()
            << "\n\tUNIQUE LOG LINES: writed on: "<<this->logFiles[i]->writeLogLineCounter(p.filename().c_str()).c_str();

            //output <<" AQUI ES QUE SE SALE ";

    }

    /*output << "\n\n --------------------------------------------------------"
            << "\nLOG FILE: "<<this->logFiles[2]->getLogFilePath()->c_str()
            << "\n\tLOG SIZE: "<<this->logFiles[2]->getLogFileSize()<<" bytes"
            << "\n\tNUMBER OF ERROR LINES: "<<this->logFiles[2]->getNumberErrorLogs()<<" times"
            << "\n\tNUMBER OF INFO LINES: "<<this->logFiles[2]->getNumberInfoLogs()<<" times"
            << "\n\tNUMBER OF DEBUG LINES: "<<this->logFiles[2]->getNumberDebugLogs()<<" times"
            << "\n\tIS MORE THAN 10M: "<<(this->logFiles[2]->isMoreThan10M()? "TRUE" : "FALSE")
            << "\n\tMORE FRECUENT ERROR: "<<this->logFiles[2]->getMoreFrecuentError()->getLogLine()->c_str()
            << "\n\t\tTIMES THAT THIS ERROR MATCHS: "<<this->logFiles[2]->getMoreFrecuentError()->getMatchsNumber()
            << "\n\tLONGEST LINE: "<<this->logFiles[2]->getLongestLogLine()->getLogLine()->substr(0,100)<<"(CAN NOT PRINT ALL LONG..)"
            << "\n\t\tTHIS LINE SIZE: "<<this->logFiles[2]->getLongestLogLine()->getLineSize()
            << "\n\tUNIQUE LOG LINES: ";
            for (unsigned j = 0; j < this->logFiles[2]->getLogLineCounter().size(); ++j){
                output <<"\n\t\tLINEA DE LOG: "<<this->logFiles[2]->getLogLineCounter()[j]->getLogLine()->substr(0,0)<<"--- N MATCHS: "<<this->logFiles[2]->getLogLineCounter()[j]->getMatchsNumber();
            }*/

    output<<"\n\nEND PRINTING LOG FILES METADATA\n\n";

    //std::cout << output.str();

    return output.str();
}

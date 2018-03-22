#ifndef MAIN_H
#define MAIN_H

#include<iostream>
/*#include "zlib-1.2.11/zlib.h"
#include "sqlite3/sqlite3.h"
#include "wxWidgets-3.0.4/include/wx/wx.h"
#include "boost_1_66_0/boost/iterator.hpp"*/
#include "MainView.h"
#include "ZlibManagement.h"
#include "InputPathDialog.h"

using namespace std;

/*const wxCmdLineEntryDesc gCmdLineDesc[] =
{
    { wxCMD_LINE_OPTION, "id", "WID", "Windows Process ID", wxCMD_LINE_VAL_NUMBER },
    { wxCMD_LINE_NONE }
};*/

class Main : public wxApp
{
    public:
        bool OnInit();
        virtual ~Main();
    protected:

    private:
};



#endif // MAIN_H

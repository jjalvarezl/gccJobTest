#include "Main.h"

bool Main::OnInit()
{
    ZlibManagement::getInstance()->setCompressedFilePath(new string("/etc/Aranda/Aranda Agent 9/Aranda.zip"));
    ZlibManagement::getInstance()->uncompressFile();

    MainView *mainView = new MainView(wxT("Job Test Solution"));
    mainView->Show(true);
    return true;
}

Main::~Main()
{
    //dtor
}

wxIMPLEMENT_APP(Main);

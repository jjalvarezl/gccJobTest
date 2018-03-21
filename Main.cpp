#include "Main.h"

bool Main::OnInit()
{
    ZlibManagement::getInstance()->setCompressedFilePath(new string("/etc/Aranda/Aranda Agent 9/Aranda.zip"));
    ZlibManagement::getInstance()->uncompressFile();

    wxCmdLineParser parser (gCmdLineDesc, argc, argv);
    parser.Parse();
    long value;
   if(parser.Found(wxT("WID"), &value)){
      wxMessageBox(wxString::Format("%d\n",value));
   }
    MainView *mainView = new MainView(wxT("Simple"));
    mainView->Show(true);
    return true;
}

Main::~Main()
{
    //dtor
}

wxIMPLEMENT_APP(Main);

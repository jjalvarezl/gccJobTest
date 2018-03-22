#include "Main.h"

bool Main::OnInit()
{
    InputPathDialog *inputPathDialog = new InputPathDialog(wxT("Job Test Solution"));
    inputPathDialog->Show(true);

    return true;
}

Main::~Main()
{
    //dtor
}

wxIMPLEMENT_APP(Main);

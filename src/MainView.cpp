#include "MainView.h"

MainView::MainView(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    Centre();

    frame_sizer = new wxBoxSizer( wxVERTICAL );
    this->SetSizer( frame_sizer );

    scrolledWindow = new wxScrolledWindow( this, wxID_ANY );
    scrolledWindow->SetScrollRate( 5, 5 );
    scrolledWindow->FitInside();
    frame_sizer->Add( scrolledWindow, 1, wxEXPAND );

    scrolledWindow_sizer = new wxBoxSizer( wxVERTICAL );
    scrolledWindow->SetSizer( scrolledWindow_sizer );

    notebookMain = new wxNotebook( scrolledWindow, wxID_ANY );
    notebookMain->InvalidateBestSize();


    //Adding panel BIOS to notebook
    wxPanel* panelBIOS = new wxPanel( notebookMain, wxID_ANY );
    notebookMain->AddPage( panelBIOS, wxT("BIOS") );


    //Adding panel Logs to notebook
    wxPanel* panelLogs = new wxPanel( notebookMain, wxID_ANY );
    notebookMain->AddPage( panelLogs, wxT("Logs") );

    //Adding panel Sqlite to notebook
    wxPanel* panelSqlite = new wxPanel( notebookMain, wxID_ANY );
    notebookMain->AddPage( panelSqlite, wxT("Sqlite") );

    //Adding panel Datos Zip to notebook
    wxPanel* panelZipData = new wxPanel( notebookMain, wxID_ANY );
    notebookMain->AddPage( panelZipData, wxT("Datos Zip") );

    //Adding page to notebook
    wxPanel* panelTab1 = new wxPanel( notebookMain, wxID_ANY );
    notebookMain->AddPage( panelTab1, wxT("Tab1") );


    scrolledWindow_sizer->Add( notebookMain, 0, wxEXPAND );
    scrolledWindow_sizer->Add( new wxButton( scrolledWindow, wxID_ANY, _("Button1"), wxDefaultPosition, wxSize(200,200) ), 0, wxEXPAND );
    scrolledWindow_sizer->Add( new wxButton( scrolledWindow, wxID_ANY, _("Button3") ), 1, wxEXPAND );
    scrolledWindow_sizer->Add( new wxButton( scrolledWindow, wxID_ANY, _("Button4") ), 0, wxEXPAND );

    panel_sizer = new wxBoxSizer( wxVERTICAL );
    panel_sizer->Add( hideme = new wxButton(panelTab1, 512, wxT("HideMe")), 0, wxEXPAND );
    hideme->Hide();
    panel_sizer->Add( new wxButton(panelTab1, 513, wxT("ShowMe")), 0, wxEXPAND );
    panelTab1->SetSizer (panel_sizer);


    //Panel sizer para logs
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlLogs = new wxTextCtrl (panelLogs, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlLogs->SetEditable(false);
    *textCtrlLogs << ZlibManagement::getInstance()->printLogFiles();
    panel_sizer->Add( textCtrlLogs, 0, wxEXPAND );
    panelLogs->SetSizer (panel_sizer);

    //Panel sizer para sqlite
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlSqlite = new wxTextCtrl (panelSqlite, wxID_ANY, wxT(""),wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlSqlite->SetEditable(false);
    *textCtrlSqlite << SqliteManagement::getInstance()->printSqliteDBAnalysis();
    panel_sizer->Add( textCtrlSqlite, 0, wxEXPAND );
    panelSqlite->SetSizer (panel_sizer);

    //Panel sizer para la estructura de zip
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlZipStructure = new wxTextCtrl (panelZipData, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlZipStructure->SetEditable(false);
    *textCtrlZipStructure << ZlibManagement::getInstance()->printZipFiles();
    panel_sizer->Add( textCtrlZipStructure, 0, wxEXPAND );
    panelZipData->SetSizer (panel_sizer);

    //ctor
}

MainView::~MainView()
{
    //dtor
}

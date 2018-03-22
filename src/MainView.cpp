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

    //Adding notebook to scrolled sizer.
    scrolledWindow_sizer->Add( notebookMain, 1, wxEXPAND );

    //Panel sizer para BIOS
    panel_sizer = new wxBoxSizer( wxHORIZONTAL );
    treeCtrlBIOS = new wxTreeCtrl(panelBIOS, wxID_ANY, wxDefaultPosition, wxSize(200,300));
    //Adding nodes
    wxTreeItemId rootId = treeCtrlBIOS->AddRoot("Root");
    wxTreeItemId child2Id = treeCtrlBIOS->AppendItem(rootId, "Node 2");
    treeCtrlBIOS->AppendItem(child2Id, "Child of node 2");
    treeCtrlBIOS->AppendItem(rootId, "Node 3");
    //Adding event
    treeCtrlBIOS->Connect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(MainView::nodeActivated), NULL, this);
    //Adding node information text container
    textCtrlBIOS = new wxTextCtrl (panelBIOS, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlBIOS->SetEditable (false);
    panel_sizer->Add(treeCtrlBIOS, 0, wxEXPAND);
    panel_sizer->Add(textCtrlBIOS, 1, wxEXPAND);
    panelBIOS->SetSizer (panel_sizer);

    //Panel sizer para logs
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlLogs = new wxTextCtrl (panelLogs, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlLogs->SetEditable(false);
    *textCtrlLogs << ZlibManagement::getInstance()->printLogFiles();
    panel_sizer->Add( textCtrlLogs, 1, wxEXPAND );
    panelLogs->SetSizer (panel_sizer);

    //Panel sizer para sqlite
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlSqlite = new wxTextCtrl (panelSqlite, wxID_ANY, wxT(""),wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlSqlite->SetEditable(false);
    *textCtrlSqlite << SqliteManagement::getInstance()->printSqliteDBAnalysis();
    panel_sizer->Add( textCtrlSqlite, 1, wxEXPAND );
    panelSqlite->SetSizer (panel_sizer);

    //Panel sizer para la estructura de zip
    panel_sizer = new wxBoxSizer( wxVERTICAL );
    textCtrlZipStructure = new wxTextCtrl (panelZipData, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200,300), wxTE_MULTILINE);
    textCtrlZipStructure->SetEditable(false);
    *textCtrlZipStructure << ZlibManagement::getInstance()->printZipFiles();
    panel_sizer->Add( textCtrlZipStructure, 1, wxEXPAND );
    panelZipData->SetSizer (panel_sizer);

    //ctor
}

void MainView::nodeActivated(wxTreeEvent& event) {
    wxTreeItemId myClickerId = event.GetItem();
    wxTreeItemData* treeData = treeCtrlBIOS->GetItemData(myClickerId);
    wxTreeItemId myNodeId = treeData->GetId();

    wxMessageBox( wxT("This is the message."), wxT("HOLA MUNDO"), wxICON_INFORMATION);
}

MainView::~MainView()
{
    treeCtrlBIOS->Disconnect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(MainView::nodeActivated), NULL, this);
    //dtor
}

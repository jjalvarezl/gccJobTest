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

    treeItemIdEntryPointStructure = treeCtrlBIOS->AddRoot("Entry Point structure");
            treeItemIdEntryPointStructure32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure, "32 bits");
                treeItemIdAnchorString32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Anchor String");
                treeItemIdEntryPointStructureChecksum32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Entry Point Structure Checksum");
                treeItemIdEntryPointLenght32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Entry Point Length");
                treeItemIdSMBIOSMajorVersion32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "SMBIOS Major Version");
                treeItemIdSMBIOSMinorVersion32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "SMBIOS Minor Version");
                treeItemIdMaximumStructureSize32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Maximum Structure Size");
                treeItemIdEntryPointRevision32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Entry Point Revision");
                treeItemIdFormattedArea32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Formatted Area");
                treeItemIdIntermediateAnchorString32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Intermediate Anchor String");
                treeItemIdIntermediateChecksum32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Intermediate Checksum");
                treeItemIdStructureTableLength32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Structure Table Length");
                treeItemIdStructureTableAddress32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Structure Table Address");
                treeItemIdNumberOfSMBIOSStructures32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "Number of SMBIOS Structures");
                treeItemIdSMBIOSBCDRevision32bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure32bits, "SMBIOS BCD Revision");
            treeItemIdEntryPointStructure64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure, "64 bits");
                treeItemIdAnchorString64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Anchor String");
                treeItemIdEntryPointStructureChecksum64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Entry Point Structure Checksum");
                treeItemIdEntryPointLenght64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Entry Point Length");
                treeItemIdSMBIOSMajorVersion64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "SMBIOS Major Version");
                treeItemIdSMBIOSMinorVersion64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "SMBIOS Minor Version");
                treeItemIdSMBIOSDocrev64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "SMBIOS Docrev");
                treeItemIdEntryPointRevision64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Entry Point Revision");
                treeItemIdReserved64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Reserved");
                treeItemIdStructureTableMaximumSize64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Structure Table Maximum Size");
                treeItemIdStructureTableAddress64bits = treeCtrlBIOS->AppendItem(treeItemIdEntryPointStructure64bits, "Structure Table Address");




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

    if (myClickerId == treeItemIdEntryPointStructure)
        wxMessageBox( wxT("Por favor abra un elemento contenido en ésta categoría"), wxT("Información"), wxICON_INFORMATION);

        if (myClickerId == treeItemIdEntryPointStructure32bits)
            textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(0,30)->c_str());

            if (myClickerId == treeItemIdAnchorString32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(0,3)->c_str());

            if (myClickerId == treeItemIdEntryPointStructureChecksum32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(4)->c_str());

            if (myClickerId == treeItemIdEntryPointLenght32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(5)->c_str());

            if (myClickerId == treeItemIdSMBIOSMajorVersion32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(6)->c_str());

            if (myClickerId == treeItemIdSMBIOSMinorVersion32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(7)->c_str());

            if (myClickerId == treeItemIdMaximumStructureSize32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(8,9)->c_str());

            if (myClickerId == treeItemIdEntryPointRevision32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(10)->c_str());

            if (myClickerId == treeItemIdFormattedArea32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(11,15)->c_str());

            if (myClickerId == treeItemIdIntermediateAnchorString32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(16, 20)->c_str());

            if (myClickerId == treeItemIdIntermediateChecksum32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(21)->c_str());

            if (myClickerId == treeItemIdStructureTableLength32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(22,23)->c_str());

            if (myClickerId == treeItemIdStructureTableAddress32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(24,27)->c_str());

            if (myClickerId == treeItemIdNumberOfSMBIOSStructures32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(28,29)->c_str());

            if (myClickerId == treeItemIdSMBIOSBCDRevision32bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(30)->c_str());

        if(myClickerId == treeItemIdEntryPointStructure64bits)
            textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(0,16)->c_str());

            if(myClickerId == treeItemIdAnchorString64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(0,4)->c_str());

            if(myClickerId == treeItemIdEntryPointStructureChecksum64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(5)->c_str());

            if(myClickerId == treeItemIdEntryPointLenght64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(6)->c_str());

            if(myClickerId == treeItemIdSMBIOSMajorVersion64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(7)->c_str());

            if(myClickerId == treeItemIdSMBIOSMinorVersion64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(8)->c_str());

            if(myClickerId == treeItemIdSMBIOSDocrev64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(9)->c_str());

            if(myClickerId == treeItemIdEntryPointRevision64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(10)->c_str());

            if(myClickerId == treeItemIdReserved64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(11)->c_str());

            if(myClickerId == treeItemIdStructureTableMaximumSize64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairByOffset(12)->c_str());

            if(myClickerId == treeItemIdStructureTableAddress64bits)
                textCtrlBIOS->SetValue(SMBIOSManager::getInstance()->getHexPairsByOffsetRegions(13,16)->c_str());


}

MainView::~MainView()
{
    treeCtrlBIOS->Disconnect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(MainView::nodeActivated), NULL, this);
    //dtor
}

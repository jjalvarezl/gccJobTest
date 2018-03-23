#ifndef MAINVIEW_H
#define MAINVIEW_H
#include<iostream>
#include "wx/wx.h"
#include "wx/notebook.h"
#include "wx/gbsizer.h"
#include "wx/cmdline.h"
#include "wx/treectrl.h"
#include "SqliteManagement.h"
#include "ZlibManagement.h"

class MainView : public wxFrame
{
    public:
        MainView(const wxString& title);
        virtual ~MainView();

        //Event for treeCtrl BIOS
        void nodeActivated (wxTreeEvent& event);

    protected:

    private:
        wxButton* hideme;
        wxSizer* panel_sizer, *frame_sizer, *scrolledWindow_sizer;
        wxScrolledWindow* scrolledWindow;

        //Window components
        wxNotebook* notebookMain;

        //Sizers for each tab
        wxSizer* logsPanelSizer, *sqlitePanelSizer, *zipStructurePanelSizer;

        //Text components for showing data
        wxTextCtrl *textCtrlLogs;
        wxTextCtrl *textCtrlSqlite;
        wxTextCtrl *textCtrlZipStructure;

        //BIOS Components
        wxTreeCtrl* treeCtrlBIOS;
        wxTextCtrl* textCtrlBIOS;

        //BIOS wxTreeCtrl items
        wxTreeItemId treeItemIdRootNode;
                wxTreeItemId treeItemIdEntryPointStructure;
                    wxTreeItemId treeItemIdEntryPointStructure32bits;
                        wxTreeItemId treeItemIdAnchorString32bits;
                        wxTreeItemId treeItemIdEntryPointStructureChecksum32bits;
                        wxTreeItemId treeItemIdEntryPointLenght32bits;
                        wxTreeItemId treeItemIdSMBIOSMajorVersion32bits;
                        wxTreeItemId treeItemIdSMBIOSMinorVersion32bits;
                        wxTreeItemId treeItemIdMaximumStructureSize32bits;
                        wxTreeItemId treeItemIdEntryPointRevision32bits;
                        wxTreeItemId treeItemIdFormattedArea32bits;
                        wxTreeItemId treeItemIdIntermediateAnchorString32bits;
                        wxTreeItemId treeItemIdIntermediateChecksum32bits;
                        wxTreeItemId treeItemIdStructureTableLength32bits;
                        wxTreeItemId treeItemIdStructureTableAddress32bits;
                        wxTreeItemId treeItemIdNumberOfSMBIOSStructures32bits;
                        wxTreeItemId treeItemIdSMBIOSBCDRevision32bits;
                    wxTreeItemId treeItemIdEntryPointStructure64bits;
                        wxTreeItemId treeItemIdAnchorString64bits;
                        wxTreeItemId treeItemIdEntryPointStructureChecksum64bits;
                        wxTreeItemId treeItemIdEntryPointLenght64bits;
                        wxTreeItemId treeItemIdSMBIOSMajorVersion64bits;
                        wxTreeItemId treeItemIdSMBIOSMinorVersion64bits;
                        wxTreeItemId treeItemIdSMBIOSDocrev64bits;
                        wxTreeItemId treeItemIdEntryPointRevision64bits;
                        wxTreeItemId treeItemIdReserved64bits;
                        wxTreeItemId treeItemIdStructureTableMaximumSize64bits;
                        wxTreeItemId treeItemIdStructureTableAddress64bits;

                wxTreeItemId treeItemStructureHeaderFormatDescription;
                    wxTreeItemId treeItemStructureHeaderFormatDescriptionType;
                    wxTreeItemId treeItemStructureHeaderFormatDescriptionHeader;
                    wxTreeItemId treeItemStructureHeaderFormatDescriptionHandle;

                wxTreeItemId treeItemBIOSInformationType0Structure;
                    wxTreeItemId treeItemBIOSInformationType0StructureType;
                    wxTreeItemId treeItemBIOSInformationType0StructureLenght;
                    wxTreeItemId treeItemBIOSInformationType0StructureHandle;
                    wxTreeItemId treeItemBIOSInformationType0StructureVendor;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSVersion;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSStartingAddressSegment;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSReleaseDate;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSROMSite;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSCharacteristics;
                    wxTreeItemId treeItemBIOSInformationType0StructureBIOSCharacteristicsExtensionBytes;
                    wxTreeItemId treeItemBIOSInformationType0StructureSystemBIOSMajorRelease;
                    wxTreeItemId treeItemBIOSInformationType0StructureSystemBIOSMinorRelease;
                    wxTreeItemId treeItemBIOSInformationType0StructureEmbeddedControllerFirmwareMajorRelease;
                    wxTreeItemId treeItemBIOSInformationType0StructureEmbeddedControllerFirmwareMinorRelease;
                    wxTreeItemId treeItemBIOSInformationType0StructureExtendedBIOSROMSize;


        //BIOS wxTreeCtrl items
};

#endif // MAINVIEW_H

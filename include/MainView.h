#ifndef MAINVIEW_H
#define MAINVIEW_H
#include<iostream>
#include "wx/wx.h"
#include "wx/notebook.h"
#include "wx/gbsizer.h"
#include "wx/cmdline.h"
#include "SqliteManagement.h"
#include "ZlibManagement.h"

class MainView : public wxFrame
{
    public:
        MainView(const wxString& title);
        virtual ~MainView();

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
};

#endif // MAINVIEW_H

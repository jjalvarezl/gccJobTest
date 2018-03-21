#ifndef MAINVIEW_H
#define MAINVIEW_H
#include<iostream>
#include "wx/wx.h"
#include "wx/notebook.h"
#include "wx/gbsizer.h"
#include "wx/cmdline.h"

class MainView : public wxFrame
{
    public:
        MainView(const wxString& title);
        virtual ~MainView();

    protected:

    private:
        wxButton* hideme;
        wxSizer* panel_sizer, *frame_sizer, *sw_sizer;
        wxScrolledWindow* sw;
        wxNotebook* nb;
};

#endif // MAINVIEW_H

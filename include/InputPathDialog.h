#ifndef INPUTPATHDIALOG_H
#define INPUTPATHDIALOG_H
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include "MainView.h"
#include "ZlibManagement.h"

class InputPathDialog : public wxDialog
{
    public:
        InputPathDialog(const wxString& title);
        virtual ~InputPathDialog();

        //Events
        void acceptButtonEvent(wxCommandEvent& event);// { event.Skip(); }
        void cancelButtonEvent(wxCommandEvent& event);// { event.Skip(); }

        //Getters and setters
        wxStaticText* getStaticTextInfo();
        void setStaticTextInfo(wxStaticText* staticTextInfo);

        wxTextCtrl* getTextCtrlZipPath ();
        void setTextCtrlZipPath(wxTextCtrl* textCtrlZipPath);

        wxButton* getButtonAccept();
        void setButtonAccept(wxButton* buttonAccept);

        wxButton* getButtonCancel();
        void setButtonCancel(wxButton* buttonCancel);


    protected:

    private:
        wxStaticText* staticTextInfo;
        wxTextCtrl* textCtrlZipPath;
        wxButton* buttonAccept;
        wxButton* buttonCancel;
};

#endif // INPUTPATHDIALOG_H

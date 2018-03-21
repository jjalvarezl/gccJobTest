/***************************************************************
 * Name:      JobTestingCodeBlocksMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    jjalvarezl ()
 * Created:   2018-03-19
 * Copyright: jjalvarezl ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "JobTestingCodeBlocksMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



JobTestingCodeBlocksDialog::JobTestingCodeBlocksDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

JobTestingCodeBlocksDialog::~JobTestingCodeBlocksDialog()
{
}

void JobTestingCodeBlocksDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void JobTestingCodeBlocksDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void JobTestingCodeBlocksDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

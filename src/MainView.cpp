#include "MainView.h"

MainView::MainView(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    Centre();

    frame_sizer = new wxBoxSizer( wxVERTICAL );
    this->SetSizer( frame_sizer );

    sw = new wxScrolledWindow( this, wxID_ANY );
    sw->SetScrollRate( 5, 5 );
    sw->FitInside();
    frame_sizer->Add( sw, 1, wxEXPAND );

    sw_sizer = new wxBoxSizer( wxVERTICAL );
    sw->SetSizer( sw_sizer );

    nb = new wxNotebook( sw, wxID_ANY );
    wxPanel* panel = new wxPanel( nb, wxID_ANY );
    nb->AddPage( panel, wxT("Tab1") );
    nb->InvalidateBestSize();

    sw_sizer->Add( nb, 0, wxEXPAND );
    sw_sizer->Add( new wxButton( sw, wxID_ANY, _("Button1"), wxDefaultPosition, wxSize(200,200) ), 0, wxEXPAND );
    sw_sizer->Add( new wxButton( sw, wxID_ANY, _("Button3") ), 1, wxEXPAND );
    sw_sizer->Add( new wxButton( sw, wxID_ANY, _("Button4") ), 0, wxEXPAND );

    panel_sizer = new wxBoxSizer( wxVERTICAL );
    panel_sizer->Add( hideme = new wxButton(panel, 512, wxT("HideMe")), 0, wxEXPAND );
    hideme->Hide();
    panel_sizer->Add( new wxButton(panel, 513, wxT("ShowMe")), 0, wxEXPAND );
    panel->SetSizer( panel_sizer );


    //ctor
}

MainView::~MainView()
{
    //dtor
}

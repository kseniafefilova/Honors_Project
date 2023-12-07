#include "bookGridPanel.h"
#include <wx/wx.h>

class ContentPanelsell : public wxPanel {
public:
  ContentPanelsell(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
    // Arrange them using a sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    // this->SetBackgroundColour(wxColor(85, 124, 85));

    wxStaticText *sellLend =
        new wxStaticText(this, wxID_ANY, "Sell or lend books");
    sellLend->SetForegroundColour(wxColour(250, 246, 240));
    wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL,
                  wxFONTWEIGHT_BOLD);
    sellLend->SetFont(myFont);
    sizer->Add(sellLend, 0, wxALL | wxALIGN_CENTER, 5);

    buyRentbutton = new wxButton(this, wxID_ANY, "Buy/Rent");
    sizer->Add(buyRentbutton, 0, wxALIGN_RIGHT | wxALL, 10);
    
    auto bookGrid = new BookGridPanel(this);
    sizer->Add(bookGrid, 1, wxEXPAND | wxALL, 5);

    aboutUs = new wxButton(this, wxID_ANY, "About Us");
    sizer->AddStretchSpacer();
    sizer->Add(aboutUs, 0, wxALIGN_LEFT | wxALL, 5);
    this->SetSizer(sizer);
  }
  wxButton *GetbuyRentbutton() { return buyRentbutton; }
  wxButton *GetAboutUsButton() { return aboutUs; }

private:
  wxButton *buyRentbutton;
  wxButton *aboutUs;
};
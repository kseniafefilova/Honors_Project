#include "bookGridPanel.h"
#include <wx/wx.h>

class ContentPanelbuy : public wxPanel {
public:
    ContentPanelbuy(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        // Arrange them using a sizer
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        //this->SetBackgroundColour(wxColor(85, 124, 85));

  wxStaticText* buyRent = new wxStaticText(this, wxID_ANY, "Buy or rent books");
  buyRent->SetForegroundColour(wxColour(250, 246, 240));
  wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
  buyRent->SetFont(myFont);
  sizer->Add(buyRent, 0, wxALL | wxALIGN_CENTER, 5);

  sellLendbutton =
    new wxButton(this, wxID_ANY, "Sell/Lend");
  sizer->Add(sellLendbutton, 0, wxALIGN_RIGHT|wxALL, 10);

  auto bookGrid = new BookGridPanel(this);
  sizer->Add(bookGrid, 1, wxEXPAND | wxALL, 5);
  
  aboutUs =
      new wxButton(this, wxID_ANY, "About Us");
  sizer->AddStretchSpacer();
  sizer->Add(aboutUs, 0, wxALIGN_LEFT|wxALL, 5);
  this->SetSizer(sizer);
}

    wxButton* GetsellLendbutton() { return sellLendbutton; }
    wxButton* GetAboutUsButton() { return aboutUs; }

private:
    wxButton* sellLendbutton;
    wxButton* aboutUs;
};

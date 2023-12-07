#include "bookGridPanel.h"
#include <wx/wx.h>

class ContentPanelbuy : public wxPanel {
public:
  ContentPanelbuy(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
        // Main sizer
      wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        

  wxStaticText* buyRent = new wxStaticText(this, wxID_ANY, "Buy or rent books");
  buyRent->SetForegroundColour(wxColour(250, 246, 240));
  wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
  buyRent->SetFont(myFont);
  sizer->Add(buyRent, 0, wxALL | wxALIGN_CENTER, 5);
  // Horizontal sizer for buttons
  wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
  myPagebutton = new wxButton(this, wxID_ANY, "My page");
  buttonSizer->Add(myPagebutton, 0, wxTOP | wxLEFT, 5); 
  buttonSizer->AddSpacer(700); // Adding space between buttons
  sellLendbutton = new wxButton(this, wxID_ANY, "Sell/Lend");
  buttonSizer->Add(sellLendbutton, 0, wxTOP | wxRIGHT, 5); 
  sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

  // Adding book grid panel to the Buy/Rent Panel
  auto bookGrid = new BookGridPanel(this);
  sizer->Add(bookGrid, 1, wxEXPAND | wxALL, 5);
  // Adding About Us button
  aboutUs =
      new wxButton(this, wxID_ANY, "About Us");
  sizer->AddStretchSpacer();
  sizer->Add(aboutUs, 0, wxALIGN_LEFT|wxALL, 5);
  this->SetSizer(sizer);
}

    wxButton* GetsellLendbutton() { return sellLendbutton; }
    wxButton* GetAboutUsButton() { return aboutUs; }
    wxButton* GetmyPagebutton() { return myPagebutton; }

private:
    wxButton* sellLendbutton;
    wxButton* aboutUs;
    wxButton* myPagebutton;
};

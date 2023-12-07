#include "bookGridPanel.h"
#include <wx/wx.h>

class ContentPanelsell : public wxPanel {
public:
  ContentPanelsell(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
    // Main sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    
    wxStaticText *sellLend =
        new wxStaticText(this, wxID_ANY, "Sell or lend books");
    sellLend->SetForegroundColour(wxColour(250, 246, 240));
    wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL,
                  wxFONTWEIGHT_BOLD);
    sellLend->SetFont(myFont);
    sizer->Add(sellLend, 0, wxALL | wxALIGN_CENTER, 5);
    // Horizontal sizer for buttons
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    myPagebutton = new wxButton(this, wxID_ANY, "My page");
    buttonSizer->Add(myPagebutton, 0, wxTOP | wxLEFT, 5); 
    buttonSizer->AddSpacer(700);
    buyRentbutton = new wxButton(this, wxID_ANY, "Buy/Rent");
    buttonSizer->Add(buyRentbutton, 0, wxTOP | wxRIGHT, 5); 
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10); 
    // Adding book grid panel to the Sell/Lend Panel
    auto bookGrid = new BookGridPanel(this);
    sizer->Add(bookGrid, 1, wxEXPAND | wxALL, 5);
    // Adding About Us button
    aboutUs = new wxButton(this, wxID_ANY, "About Us");
    sizer->AddStretchSpacer();
    sizer->Add(aboutUs, 0, wxALIGN_LEFT | wxALL, 5);
    this->SetSizer(sizer);
  }
  wxButton *GetbuyRentbutton() { return buyRentbutton; }
  wxButton *GetAboutUsButton() { return aboutUs; }
  wxButton* GetmyPagebutton() { return myPagebutton; }

private:
  wxButton *buyRentbutton;
  wxButton *aboutUs;
  wxButton* myPagebutton;
};
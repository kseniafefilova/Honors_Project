#ifndef BOOK_PURCHASE_PANEL_H
#define BOOK_PURCHASE_PANEL_H
#include "bookGridPanel.h"
#include "book.h"
#include <wx/wx.h>

class BookPurchasePanel : public wxPanel {
public:
  BookPurchasePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    // Main sizer
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
      
    wxStaticText* bookPurchase = new wxStaticText(this, wxID_ANY, "Book purchase");
    bookPurchase->SetForegroundColour(wxColour(250, 246, 240));
    wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    bookPurchase->SetFont(myFont);
    sizer->Add(bookPurchase, 0, wxALL | wxALIGN_CENTER, 5);
    // Horizontal sizer for buttons
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    myPagebutton = new wxButton(this, wxID_ANY, "My page");
    buttonSizer->Add(myPagebutton, 0, wxTOP | wxLEFT, 5);
    buttonSizer->AddSpacer(700);
    buyRentbutton = new wxButton(this, wxID_ANY, "Buy/Rent");
    buttonSizer->Add(buyRentbutton, 0, wxTOP | wxRIGHT, 5); 
    // Add button sizer to the sizer
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
    // Horizontal sizer for image and info
    wxBoxSizer* imageAndInfoSizer = new wxBoxSizer(wxHORIZONTAL);
    // Adding images
    wxStaticBitmap *image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("image_1.jpeg", wxBITMAP_TYPE_JPEG), wxPoint(60,70), wxSize(450, 450));
    imageAndInfoSizer->Add(image, 0, wxALL | wxALIGN_TOP | wxLEFT, 5);
    // Vertical sizer for info
    wxBoxSizer* infoSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* infoText_1 = new wxStaticText(this, wxID_ANY, "Digital Design, with an introduction to the Verilog HDL, VHDL and system Verilog");
    wxFont mySubTitleFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    infoText_1->SetFont(mySubTitleFont);
    infoText_1->SetForegroundColour(wxColour(250, 246, 240));
    infoText_1->Wrap(300);


    wxStaticText* infoText_2 = new wxStaticText(this, wxID_ANY, "Morris Mano, Michael Ciletti");
    infoText_2->SetFont(mySubTitleFont);
    infoText_2->SetForegroundColour(wxColour(250, 246, 240));
    infoText_2->Wrap(300);


    wxStaticText* infoText_3 = new wxStaticText(this, wxID_ANY, "CSC215");
    infoText_3->SetFont(mySubTitleFont);
    infoText_3->SetForegroundColour(wxColour(250, 246, 240));
    infoText_3->Wrap(300);
    // Adding info to the info sizer
    infoSizer->Add(infoText_1, 0, wxBOTTOM, 5);
    infoSizer->AddSpacer(20);
    infoSizer->Add(infoText_2, 0, wxBOTTOM, 5);
    infoSizer->AddSpacer(20);
    infoSizer->Add(infoText_3, 0, wxBOTTOM, 5);
    infoSizer->AddSpacer(30);
    // Adding request button to the sizer
    requestBookbutton = new wxButton(this, wxID_ANY, "Request book");
    infoSizer->Add(requestBookbutton, 0, wxALIGN_LEFT | wxBOTTOM | wxLEFT, 5);

    // Uniting sizers
    imageAndInfoSizer->Add(infoSizer, 0, wxALIGN_TOP | wxLEFT, 10);
    sizer->Add(imageAndInfoSizer, 0, wxALL | wxALIGN_CENTER, 10);

    this->SetSizer(sizer);
}

    wxButton* GetbuyRentbutton() { return buyRentbutton; }
    wxButton* GetrequestBookbutton() { return requestBookbutton; }
    wxButton* GetmyPagebutton() { return myPagebutton; };
private:
    wxButton* buyRentbutton;
    wxButton* requestBookbutton;
    wxButton* myPagebutton;
};
#endif
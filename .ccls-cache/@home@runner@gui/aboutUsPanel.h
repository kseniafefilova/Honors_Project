#include <wx/wx.h>
#include <wx/image.h>
#include <wx/sizer.h>

class AboutUsPanel : public wxPanel {
public:
    AboutUsPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY) {
        
        // Arrange using a sizer
        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        //this->SetBackgroundColour(wxColor(85, 124, 85));
        
        wxStaticText* aboutUsText = new wxStaticText(this, wxID_ANY, "About Us");
        aboutUsText->SetForegroundColour(wxColour(250, 246, 240));
        wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        aboutUsText->SetFont(myFont);
        sizer->Add(aboutUsText, 0, wxALL | wxALIGN_CENTER, 5);
        wxStaticText* subTitle = new wxStaticText(this, wxID_ANY, "How do we make an impact");
        subTitle->SetForegroundColour(wxColour(250, 246, 240));
        wxFont mySubTitleFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        subTitle->SetFont(mySubTitleFont);
        sizer->Add(subTitle, 0, wxALL | wxALIGN_CENTER, 5);
        sizer->AddStretchSpacer(1);

        
        wxBoxSizer *factsSizer = new wxBoxSizer(wxVERTICAL);
        wxStaticText* fact_1 = new wxStaticText(this, wxID_ANY, "Shopping second hand books  conserves natural resources.");
        fact_1->SetFont(mySubTitleFont);
        fact_1->SetForegroundColour(wxColour(250, 246, 240));
        fact_1->Wrap(300);
        

        wxStaticText* fact_2 = new wxStaticText(this, wxID_ANY, "Purchasing second hand books rather than new minimizes pollution.");
        fact_2->SetFont(mySubTitleFont);
        fact_2->SetForegroundColour(wxColour(250, 246, 240));
        fact_2->Wrap(300);
        

        wxStaticText* fact_3 = new wxStaticText(this, wxID_ANY, "Shopping second hand books helps to reduce trash.");
        fact_3->SetFont(mySubTitleFont);
        fact_3->SetForegroundColour(wxColour(250, 246, 240));
        fact_3->Wrap(300);
        

      // Create a horizontal box sizer for facts and image
      wxBoxSizer* factsAndImageSizer = new wxBoxSizer(wxHORIZONTAL);

      // Add the facts to the sizer
      factsSizer->Add(fact_1, 0, wxALL | wxALIGN_LEFT, 5);
      factsSizer->AddSpacer(10);  // Add some space between facts
      factsSizer->Add(fact_2, 0, wxALL | wxALIGN_LEFT, 5);
      factsSizer->AddSpacer(10);
      factsSizer->Add(fact_3, 0, wxALL | wxALIGN_LEFT, 5);

      factsAndImageSizer->Add(factsSizer, 0, wxALIGN_LEFT);

      // Add the image to the sizer
      wxJPEGHandler *handler = new wxJPEGHandler;
      wxImage::AddHandler(handler);
      wxStaticBitmap *image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("environment.jpeg", wxBITMAP_TYPE_JPEG), wxPoint(60,100), wxSize(400, 400));
      factsAndImageSizer->Add(image, 0, wxLEFT | wxRIGHT | wxALIGN_TOP, 10);


      // Add the combined sizer to the main sizer
      sizer->Add(factsAndImageSizer, 0, wxALL | wxALIGN_CENTER, 10);
      
        
      
        // Create a horizontal box sizer for buttons
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);



        sellLendbutton = new wxButton(this, wxID_ANY, "Sell/Lend");
        buttonSizer->Add(sellLendbutton, 0,  wxTOP | wxRIGHT, 5);

        buyRentbutton = new wxButton(this, wxID_ANY, "Buy/Rent");
        buttonSizer->AddSpacer(10);
        buttonSizer->Add(buyRentbutton, 0, wxTOP | wxLEFT, 5);
        
        // Add the button sizer to the main sizer
        sizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

        // Add a spacer to center the welcomeButton at the bottom
        sizer->AddStretchSpacer(1);

        welcomeButton = new wxButton(this, wxID_ANY, "Click this Button to login and save the Earth");
        sizer->Add(welcomeButton, 1, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

        this->SetSizer(sizer);
    }

    wxButton *GetbuyRentbutton() { return buyRentbutton; }
    wxButton *GetsellLendbutton() { return sellLendbutton; }
    wxButton *GetWelcomeButton() { return welcomeButton; }

private:
    wxButton *buyRentbutton;
    wxButton *sellLendbutton;
    wxButton *welcomeButton;
   
};

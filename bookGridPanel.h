#ifndef BOOK_GRID_PANEL_H
#define BOOK_GRID_PANEL_H
#include "book.h"
#include "bookPurchasePanel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <wx/generic/gridctrl.h>
#include <wx/grid.h>
#include <wx/image.h>
#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/bmpbuttn.h>  
#include <wx/event.h> 
using namespace std;

class BookGridPanel : public wxPanel {
public:
  BookGridPanel(wxWindow *parent);
  wxButton* GetPurchaseButton() { return purchaseButtons.at(0); }
  vector<wxBitmapButton*> purchaseButtons;
  // Vector of Book class objects 
  vector<Book> books{
      Book{"Digital Design, with an introduction to the Verilog HDL, VHDL and system Verilog",
           "Morris Mano, Michael Ciletti", "CSC215", "boo.jpg"},
      Book{"Introduction To MIPS Assembly Language Programming",
           "Charles W. Kann", "CSC215", "boo.jpg"},
      Book{"Discrete Mathematics and Its Applications, 7th Edition",
           "Kenneth H. Rosen", "CSC231", "boo.jpg"},
      Book{"Starting Out with C++", "Tony Gaddis", "CSC211",
           "boo.jpg"},
      Book{"Physics for scientists and engineers", "Douglas C. Giancoli",
           "PHY215", "boo.jpg"},
      Book{"The Advanced Reading-Writing Connection", "John Langan", "CRT100",
           "boo.jpg"}};

private:
  void CreateImageGrid();
};

BookGridPanel::BookGridPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY) {

  // Create the image grid
  CreateImageGrid();  

}

void BookGridPanel::CreateImageGrid() {
  wxGridSizer *gridSizer =
      new wxGridSizer(2, 3, 15, 15); // 2x3 grid with 15-pixel padding
  // Adding buttons to the book's images
  for (Book book : books) {
    string imagePath = book.GetImageName();

    wxBitmapButton *bitmapButton = new wxBitmapButton(
    this, wxID_ANY, wxBitmap(imagePath, wxBITMAP_TYPE_JPEG),
    wxDefaultPosition, wxSize(120, 120));

    purchaseButtons.push_back(bitmapButton);

    // Text with the book title
    wxStaticText *titleText = new wxStaticText(
        this, wxID_ANY, book.GetTitle(),
        wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    wxFont myFont(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    titleText->SetFont(myFont);
    titleText->SetForegroundColour(wxColour(250, 246, 240));
    titleText->Wrap(300);
    
    // A vertical sizer to arrange bitmap and text
    wxBoxSizer *verticalSizer = new wxBoxSizer(wxVERTICAL);
    verticalSizer->Add(bitmapButton, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5); 
    verticalSizer->Add(titleText, 0, wxALIGN_CENTER_HORIZONTAL);

    // Add the vertical sizer to the grid sizer
    gridSizer->Add(verticalSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 5);
    
  }

  this->SetSizer(gridSizer);
  gridSizer->Layout();
  
  // Saving a list of available books in txt file availableBooks
  ofstream outputFile("availableBooks.txt");

      if (!outputFile.is_open()) {
          cout << "Error opening file: " << "availableBooks.txt" << endl;
      }

      for (int i = 0; i < books.size(); i++) {
          outputFile << "BOOK " << i + 1 << endl;
          outputFile << "Title: " << books.at(i).GetTitle() << " ";
          outputFile << "Authors: " << books.at(i).GetAuthor() << " ";
          outputFile << "Course: " << books.at(i).GetSubject() << " ";
      }

      outputFile.close();
}

#endif
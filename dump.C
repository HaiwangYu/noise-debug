#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dump(const char* hist_name)
{
    const char* in_file_name = "input.root";
    auto in_file = TFile::Open(in_file_name, "READ");

    auto hist = (TH2F*) in_file->Get(hist_name);
    if(!hist) {
        std::cerr << "Can not find " << hist_name << std::endl;
        return;
    }
    stringstream ss;
    for (int ix=1; ix<=hist->GetXaxis()->GetNbins(); ++ix) {
        for (int iy=1; iy<=hist->GetYaxis()->GetNbins(); ++iy) {
            ss << hist->GetBinContent(ix, iy) << " ";
        }
        ss << endl;
    }
    ofstream fout("mag.txt");
    fout << ss.str();
    fout.close();
}

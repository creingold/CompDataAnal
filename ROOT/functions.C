{
TF1 *fPeak1 = new TF1("fPeak1","gaus",0,20);
TF1 *fPeak2 = new TF1("fPeak2","gaus",0,20);
TF1 *fBgrd = new TF1("fBgrd","pol1",0,20);

fPeak1->SetParameters(30,5,1);
fPeak2->SetParameters(20,15,1);
fBgrd->SetParameters(30,-2);

fPeak1->SetLineColor(3);
fPeak2->SetLineColor(4);

TF1 *fSum = new TF1("fSum","gaus(0)+gaus(3)+pol1(6)",0,20);
fSum->SetParameters(30,5,1,20,15,1,30,-2);
fSum->SetLineColor(1);


fSum->Draw();
fPeak1->Draw("same");
fPeak2->Draw("same");
fBgrd->Draw("same");
}

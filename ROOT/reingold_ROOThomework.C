/*
Craig Reingold
10/16/15
ROOT Homework

This ROOT macro will do the following:
 - Using random number generators, create a histogram that contains three Gaussians, centered at x = 20 , 50 , 80, area = 100 , sigma = 1, on a quadradic background ( -0.01 x^2 + x + 9 ). The total spectrum should have at least 2000 events and span the x-range from 0 to 100.
 - Fit the background using ShowBackground() , a quadratic function with and without excluding peaks
 - For each fitting procedure, plot the original spectrum, the background, and the spectrum after background subtraction.
*/

bool reject;

double quadReject( const int nPeaks , double *mins , double *maxs , double *x , double *par ){
	for ( int i = 0 ; i < nPeaks ; i++ ){
		if ( reject and x[0] > mins[i] and x[0] < maxs[i] ){
			TF1::RejectPoint();
			return 0;
		}
		
		return par[0] + par[1] * x[0] + par[2] * x[0] * x[0];
	}
}


int reingold_ROOThomework{

// Initalizing the Canvas

	TCanvas *c1 = new TCanvas("c1" , "Homework Plots" , 800 , 600 );
	c1 -> Divide(3,3);

// Defining the function with three Gaussians on a quadratic background.

	TF1 *func = new TF1("func", "pol2(0) + gaus(3) + gaus(6) + gaus(9)" , 0 , 100 );
	double param[12] = {9 , 1 , -0.01 , 100 , 20 , 1 , 100 , 50 , 1 , 100 , 80 , 1};
	func->SetParameters(param);
			//  quad, lin, const, A, mu, std , ... 
// Generting and filling the histograms

	TH1F *h0 = new TH1F("h0" , "Original Spectrum" , 100 , 0 , 100 );
	for ( int i = 0 ; i < 2000 ; i++ ){
		float rand = func->GetRandom();
		h0->Fill(rand);
	}
	
	for ( int j = 1 ; j < 4 ; j++ ){
		c1->cd(j);
		h0->Draw();
	}
// Fitting the background using ShowBackground()
	c1->cd(4);
	TH1 *hPeaks = (TH1*) h0->Clone();
	TH1 *hBkgrd = (TH1*) h0->Clone();

	hPeaks->SetName("hPeaks");
	hBkgrd->SetName("hBkgrd");

	hBkgrd = h0->ShowBackground(25);

	h0->Draw();
	hBkgrd->Draw("same");
	
	hPeaks->Add(hBkgrd,-1);
	c1->cd(7);
	hPeaks->Draw();

// Fitting the background without excluding the peaks

	c1->cd(5);
	TH1F *hPeaks2 = (TH1F*) h0->Clone();
	TH1F *hBkg2 = (TH1F*) h0->Clone();

	hPeaks2->SetName("hPeaks2");
	hBkg2->SetName("hBkg2");

	TF1 *quadBack = new TF1("quadBack" , "pol2(0)" , 0 , 100 );
	hBkg2->Fit(quadBack,"R+");
	
	hBkg2->Draw();

	c1->cd(8);

	hPeaks2->Add(quadBack , -1 );
	hPeaks2->Draw();

// Fitting the background excluding the peaks
	c1 -> cd(6);

	TSpectrum *spec = new TSpectrum(5);
	TH1F * hPeaks3 = (TH1F*) h0 -> Clone();
	TH1F * hBkg3 = (TH1F*) h0 ->Clone();
	hPeaks3->SetName("hPeaks");
	hBkg3->SetName("hBkg3");

	int peaksFound = spec->Search(hBkg3 , 2 , "" , 0.3 );

	double *peakLocations = spec->GetPositionX();
	
	// Fit ignoring the peak locations

	double ignoreMin[peaksFound] , ignoreMax[peaksFound];

	for ( int k = 0 ; k < peaksFound ; k  ++ ){
		ignoreMin[k] = peakLocations[k] - 20 ;
		ignoreMax[k] = peakLocations[k] + 20 ;
	}
	
	reject = true;
	TF1 * quadExclude = new TF1("quadExclude" , quadReject(peaksFound , ignoreMin , ignoreMax ) , 0 , 100 );

	hBkg3->Fit(quadExclude);
i
	hBkg3->Draw();

	return 0;
}

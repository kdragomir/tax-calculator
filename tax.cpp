#include <iostream>
using namespace std;
                //All the ranges of firstTaxBracket/head/married joint/ married sep
double compuTax(double income, int firstTaxBracket, int secondTaxBracket, int thirdTaxBracket, int  fourthTaxBracket, int fifthTaxBracket, int sixthTaxBracket) {
   double taxF =0.00;
   if(income >= firstTaxBracket|| income < firstTaxBracket)
   {if(income < firstTaxBracket){taxF = income*.1;}
   else{taxF=( firstTaxBracket *.1);} cout<< taxF<<endl;}

   if(income >= secondTaxBracket||(income < secondTaxBracket && income >firstTaxBracket))
   {if(income < secondTaxBracket){taxF = ((income - firstTaxBracket)*.15)+taxF;}
   else{taxF = taxF +((secondTaxBracket-firstTaxBracket)*.15);}cout<< taxF<<endl;}

   if(income >= thirdTaxBracket|| (income < thirdTaxBracket&& income > secondTaxBracket))
   {if(income < thirdTaxBracket){taxF = ((income - secondTaxBracket)*.25) +taxF;}
   else {taxF = taxF +( thirdTaxBracket- secondTaxBracket)*.25;}cout<< taxF<<endl;}

   if(income >= fourthTaxBracket|| (income < fourthTaxBracket && income > thirdTaxBracket))
   {if(income < fourthTaxBracket){taxF = ((income - thirdTaxBracket)*.28) +taxF;}
   else{taxF = taxF +( fourthTaxBracket- thirdTaxBracket)*.28;}cout<< taxF<<endl;}

   if(income >= fifthTaxBracket|| (income < fifthTaxBracket && income > fourthTaxBracket))
   {if(income < fifthTaxBracket){taxF = ((income - fourthTaxBracket)*.33) +taxF;}
   else{taxF = taxF +( fifthTaxBracket- fourthTaxBracket)*.33;}cout<< taxF<<endl;}

   if(income <= sixthTaxBracket && income > fifthTaxBracket){taxF = taxF +( sixthTaxBracket- fifthTaxBracket)*.35;}
   if(income > sixthTaxBracket){taxF = taxF +((income- sixthTaxBracket)*.396); cout<< taxF<<endl;}
   return taxF;
   }

int main()
{
  int status, contNue;
  double income;

  do
  {
   	 //Prompt user to enter filing status and taxable income
    	cout << "Enter the filing status\n"
       	        << "(0-firstTaxBracket filer, 1-head of household, \n"
                    << "2-married jointly, 3-married separately): ";
    	cin >> status;

    	cout << "Enter the table income: ";
    	cin >> income;

    	//Call function compuTax to compute tax
    	double tax;
    	if (status == 0)      tax = compuTax (income, 9225, 37450, 90750, 189300, 411500, 413200);
      else if (status == 1) tax = compuTax (income, 13150, 50200, 129600, 209850,411500, 43900);
      else if (status == 2) tax = compuTax (income, 18450, 74900, 151200, 230450, 411500, 464850);
      else if (status == 3) tax = compuTax (income, 9225, 37450, 75600, 115225, 205750, 232425);

    	// Display results
    	cout << "Tax is " << static_cast<int>(tax * 100) / 100.0  << endl;

    	//Continue the tax computing?
    	cout << "Do you like to continue? Type 1 to continue: ";
    	cin >> contNue;

   } while (contNue == 1);

   return 0;
}

//
// Created by kevin on 10/15/18.
//

#include "zipcode.h"
#include <iostream>
#include <string>

using namespace std;

int main (){
    using namespace edu::sbcc::cs140;
    string barcode = "110100101000101011000010011";
    Zipcode ziptest(barcode);
    string barcodeCalculated = ziptest.getBarcode();
    cout << "the barcode input was: " << barcode << endl;
    cout << "The zipcode is: " << ziptest.getZipcode() << endl;
    cout << "the barcode input is calculated to be: " << barcodeCalculated << endl;
    if (barcode == barcodeCalculated)
        cout << "barcode and barcodeCalculated match! Good job kev";
    else
        cout << "Oh no! barcode and barcodeCalculated don't match. Try again";

//string barcode = "101010101011100";
//char barchar = barcode[1];
//int barint = barchar - '0';
//cout << "barint = " << barint << endl;
//string barcodestr = "111111111111111111111111111";
//cout << "length is: " << barcodestr.length() << endl;

}
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
    cout << "The zipcode is: " << ziptest.getZipcode() << endl;
}
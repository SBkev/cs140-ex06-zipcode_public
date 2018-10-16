/**
 * CS 140 Object-Oriented Programming Using C++
 * CRN: [33323]
 * Assignment: EX06-Zipcode
 *
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 *
 * @keshields@pipeline.sbcc.edu
 */

#include "zipcode.h"
#include <iostream>

using namespace std;

namespace edu {
    namespace sbcc {
        namespace cs140 {
            const uint8_t Zipcode::ZERO_SUM = 11;
            const uint8_t Zipcode::BARCODE_VALUE[] = {7, 4, 2, 1, 0}; //values represented by bar code digits
            const uint32_t Zipcode::ZIPDIGIT_MULT[] = {10000, 1000, 100, 10, 1}; //multiplier for concatenating zipcode from zipdigit

            Zipcode::Zipcode(string barcode)
            {
                cout << "executing barcode constructor" << endl;
                if (barcode[0] != '1')
                {
                    cout << "Error. First barcode digit must be 1! First digit is: " << barcode[0] << endl;
                    return;
                }
                else if (barcode[barcode.length()-1] != '1')
                {
                    cout << "Error. Last barcode digit must be 1!" << endl;
                    return;
                }
                else if (barcode.length() != 27)
                {
                    cout << "Error. Barcode length is not 27!" << endl;
                    return;
                }
                else
                    _zipcode = barcodeToZipcode(barcode);
            }
            Zipcode::Zipcode(u_int32_t zipcode) {
                cout << "executing zipcode constructor" << endl;
                _zipcode = zipcode;
            }
            uint8_t Zipcode::barcodeToZipDigit(string barcode, int groupIndex)
            {
                //value "groupIndex" starts at 0
                int j=0;
                uint32_t sum = 0;
                cout << endl;
                cout << "evaluating group index " << groupIndex << endl;
                for (int i = groupIndex*5 + 1; i < groupIndex*5 + 6; i++ ,j++)
                {
                    cout << "'i' is: " << i << ". Barcode digit is: " << barcode[i] << endl;
                    cout << "'j' is: " << j << ". Barcode_Value is: " << int(BARCODE_VALUE[j]) << endl;
//                    cout << "product is: " << stoi(&barcode[i]) * BARCODE_VALUE[j] << endl;
                    string strconvert = &barcode[i];
                    cout << "str convert is: " << strconvert << endl;
                    sum += barcode[i] * BARCODE_VALUE[j];
                    cout << "sum is: " << int(sum)<< endl;
                }
                if (sum == ZERO_SUM)
                    sum = 0;
                cout << "the sum of groupIndex " << groupIndex << " is: " << int(sum) << endl;
                return sum;
            }

            uint32_t Zipcode::barcodeToZipcode(string barcode)
            {
                cout << "executing barcodeToZipcode function" << endl;
                uint32_t zipcode = 0;
                for (int i=0; i < 5; i++)
                {
                    zipcode += ZIPDIGIT_MULT[i] * barcodeToZipDigit(barcode, i);
                }
            }

            uint32_t Zipcode::getZipcode() {
                return _zipcode;
            }

            string Zipcode::zipcodeToBarcode(uint32_t zipcode)
            {
                return "110100101000101011000010011"; //TODO: just a placeholder. implement bruh!
            }

            string Zipcode::getBarcode() {
                return zipcodeToBarcode(_zipcode);
            }
        }
    }
}

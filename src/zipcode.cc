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
            const string Zipcode:: NULL_BARCODE = "111000110001100011000110001";
            const uint8_t Zipcode::BARCODE_VALUE[] = {7, 4, 2, 1, 0}; //values represented by bar code digits
            const uint32_t Zipcode::ZIPDIGIT_MULT[] = {10000, 1000, 100, 10, 1}; //multiplier for concatenating zipcode from zipdigit

            Zipcode::Zipcode(string barcode)
            {
                cout << "executing barcode constructor" << endl;

                if (barcode[0] != '1') {
                    cout << "Error. First barcode digit must be 1! First digit is: " << barcode[0] << endl;
                    barcode = NULL_BARCODE;
                }
                else if (barcode[barcode.length()-1] != '1') {
                    cout << "Error. Last barcode digit must be 1!" << endl;
                    barcode = NULL_BARCODE;
                }
                else if (barcode.length() != 27) {
                    cout << "Error. Barcode length is not 27!" << endl;
                    barcode = NULL_BARCODE;
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
                    char barchar = barcode[i];
                    int barint = barchar - '0'; //subtract ascii representation of 0
                    sum += barint * BARCODE_VALUE[j];
                }

                if (sum == ZERO_SUM)
                    sum = 0;
                cout << "the sum of groupIndex " << groupIndex << " is: " << (int)sum << endl;
                return sum;
            }

            uint32_t Zipcode::barcodeToZipcode(string barcode)
            {
                cout << "executing barcodeToZipcode function" << endl;
                uint32_t zipcode = 0;
                if (barcode == "000000000000000000000000000")
                    return zipcode;

                for (int i=0; i < 5; i++)
                {
                    zipcode += ZIPDIGIT_MULT[i] * barcodeToZipDigit(barcode, i);
                    cout << "zipcode is now: " << zipcode << endl;
                }
                cout << "Final zipcode is: " << zipcode << endl;
                return zipcode;
            }

            uint32_t Zipcode::getZipcode() {
                return _zipcode;
            }

            string Zipcode::zipcodeToBarcode(uint32_t zipcode) {
                string barcode = "0000000000000000000000000"; //kind of a magic string here. would be better to start with NULL_BARCODE, however rest of code depends on appending '1' values at end of code
                if (zipcode == 0)
                    return NULL_BARCODE;
                string zipcodeStr = to_string(zipcode);

                //now iterate through digits in string to convert
                for (int i = 0; i < zipcodeStr.length(); i++)
                    //iterate through each value of zipcode
                {
                    cout << "---------------------------------" << endl;
                    int zipDigit = zipcodeStr[i] - '0';
                    if (zipDigit == 0)
                        zipDigit = ZERO_SUM;
                    cout << "zipdigit starts at " << zipDigit << endl;
                    int barcodeIndex = 5 * i;
                    int numberOfTrue = 0;

                    for (int j = 0; j < sizeof(BARCODE_VALUE); j++) {
                        //run through each group of 5 barcode digits
                        if (numberOfTrue == 2)
                            break;
                        if (zipDigit - BARCODE_VALUE[j] >= 0) {
                            barcode[barcodeIndex + j] = '1';
                            cout << "zipDigit difference for " << (int)BARCODE_VALUE[j] << " is " << zipDigit - BARCODE_VALUE[j] << endl;
                            zipDigit = zipDigit - BARCODE_VALUE[j];
                            cout << "Value of zipdigit is: " << zipDigit << endl;
                            cout << endl;
                            numberOfTrue = numberOfTrue + 1;
                        } else
                            barcode[barcodeIndex + j] = '0';
                    }
                    cout << "Barcode is now: " << barcode << " after group "<< i << endl;

                    if (numberOfTrue > 2)
                        cout << "Error! numberOfTrue is > 2" << endl;
                }

                cout << "--------------------------------------------" << endl;
                cout << "barcode before insert/append is: " << barcode << endl;
                barcode.insert(0, "1");
                barcode.append("1");
                return barcode;
            }

            string Zipcode::getBarcode() {
                return zipcodeToBarcode(_zipcode); //TODO: implement this!
            }
        }
    }
}

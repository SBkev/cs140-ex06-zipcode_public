//
// Created by kevinsh on 10/13/2018.
//

#ifndef EX06_ZIPCODE_ZIPCODE_H
#define EX06_ZIPCODE_ZIPCODE_H

#include <cstdint>
#include <string>

using namespace std;

namespace edu {
    namespace sbcc {
        namespace cs140 {
            class Zipcode {
            private:
                uint32_t _zipcode = 0;
                static const uint8_t ZERO_SUM;
                static const uint8_t BARCODE_VALUE[];
                static const uint32_t ZIPDIGIT_MULT[];
                static const string NULL_ZIP;

                uint8_t barcodeToZipDigit (string barcode,int groupIndex);
                //converts 1 group of barcode digits to zip code digit
                //value "groupIndex" starts at 0

                uint32_t barcodeToZipcode(string barcode);
                //converts a barcode into a zipcode

                string zipcodeToBarcode(uint32_t zipcode);
                //converts a zipcode into a barcode

            public:
                explicit Zipcode (u_int32_t zipcode);
                explicit Zipcode (string barcode);
                //takes zipcode in barcode format
                uint32_t getZipcode (); //returns zipcode
                string getBarcode (); //returns barcode representation of zipcode
            };
        }
    }
}

#endif //EX06_ZIPCODE_ZIPCODE_H

//
// Created by kevinsh on 10/13/2018.
//

#ifndef EX06_ZIPCODE_ZIPCODE_H
#define EX06_ZIPCODE_ZIPCODE_H

#include <cstdint>
#include <string>

namespace edu {
    namespace sbcc {
        namespace cs140 {
            class Zipcode {
            private:
                static const uint8_t ZERO_SUM;
                //declaration
            public:
                int getZipcode (); //returns zipcode
                std::string getBarcode (); //returns barcode
            };
        }
    }
}



#endif //EX06_ZIPCODE_ZIPCODE_H

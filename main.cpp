#include <iostream>
#include <libusb-1.0/libusb.h>
#include <Usb.h>
#include <unistd.h>
#include "openaccessory.hpp"

int main() {
    OpenAccessory* oa;
    vector<uint8_t> in;
    try{
        OpenAccessory::init();
        cout << "Lib Loaded" << endl;
        oa = new OpenAccessory("Softcom", "Moonshot",
                               "442 Biometric Scanner", "1.0",
                               "https://www.softcom.ng",
                               "0123456789", USB_VENDOR_GOOGLE,
                               USB_PRODUCT_NEXUS_S);
        cout << "Dev Loaded" << endl;
    } catch (OpenAccessoryException &e) {
        cerr << e.what() << endl;
        cerr << "Exit Test with Failure 1" << endl;
        OpenAccessory::de_init();
        exit(-1);
    }

    try{
        while(1){
            oa->read_data(in);
            cout << in.data() << endl;
        }
    }
    catch(OpenAccessoryException& e){
        cerr << e.what() << endl;
        cerr << "Exit Test with Failure" << endl;
    }
    delete oa;
    OpenAccessory::de_init();
}

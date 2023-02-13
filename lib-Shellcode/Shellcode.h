#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Shellcode{

public:
    unsigned char *payload;
    int len;

    Shellcode(unsigned char *shellcode, int len){
        this->len = len;
        payload = new unsigned char[len];
        for (int i = 0; i < len; i++) {
            this->payload[i] = shellcode[i];
        }
    }
    
    unsigned char *getShellcode(){
        return payload;
    }

    int getLen(){
        return len;
    }

    unsigned char * XOR_decrypt(unsigned char key) {
        for (int i = 0; i < len; i++) {
            payload[i] = payload[i] ^ key;
        }
        return payload;
    }


    void XOR_encrypt(unsigned char key){
        for(int i = 0; i < len; i++){
            payload[i] ^= key;
        }
        for(int i = 0; i < len; i++){
            cout << "\\x" << hex << (int)payload[i];
        }
        cout << endl;
        }

};


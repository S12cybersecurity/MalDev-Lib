#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "tiny-AES-c/aes.c"

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
    //setters
    void setLen(int len){
        this->len = len;
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
            cout << "\\x" << hex << setfill('0') << setw(2) << (int)payload[i];
        }
        cout << endl;
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



    void AES_encrypt(unsigned char key[],unsigned char iv[]){
        // encrypt the shellcode, and print it out, add last byte a x90 to make it 16 bytes, append a /x90 to the end
        struct AES_ctx ctx;
        AES_init_ctx_iv(&ctx, key, iv);
        AES_CBC_encrypt_buffer(&ctx, this->getShellcode(), this->getLen());

        this->setLen(this->getLen() + 1);
        this->getShellcode()[this->getLen() - 1] = 0x90;


        for(int i = 0; i < this->getLen(); i++){
            printf("\\x%02x", this->getShellcode()[i]);
        }
        printf("\n");
        getch();

    }



    unsigned char* AES_decrypt(unsigned char key[],unsigned char iv[]){
        //decrypt the shellcode, and print it out
        // the last byte is the padding, so we don't print it out
        //the last 16 are not decrypted
        struct AES_ctx ctx;
        AES_init_ctx_iv(&ctx, key, iv);
        AES_CBC_decrypt_buffer(&ctx, this->getShellcode(), this->getLen());
        printf("\n");
        getch();
        return this->getShellcode();
    }

};


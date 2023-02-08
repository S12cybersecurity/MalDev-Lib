# MalDev-ShellcodeLib
Malware Library focused in Shellcode and Payloads used by Malware Development, actually you can encrypt and decrypt the payload shellcode with XOR ciphertext

# Code
This is a C++ code defining a class Shellcode. The class has a public member variable payload which is a pointer to an array of unsigned char, a public member variable len which is an integer and various public member functions.

The constructor Shellcode(unsigned char *shellcode, int len) initializes the class and accepts an array of unsigned char and an integer len as inputs. It sets this->len to len and dynamically allocates memory for payload to store len number of characters. The constructor also copies the elements from shellcode to this->payload.

The function getShellcode() returns the value of the payload member variable. The function getLen() returns the value of the len member variable.

The function XOR_decrypt(unsigned char key) performs XOR decryption on the payload using the input key and outputs the result in hexadecimal format.

The function XOR_encrypt(unsigned char key) performs XOR encryption on the payload using the input key and outputs the result in hexadecimal format.

![image](https://user-images.githubusercontent.com/79543461/217566774-ef538157-e349-49de-a9c6-ee8e13245eb8.png)

# Usage
To use this library you can do the links like this:

First of all its create the object sending de payload and the payload lenght.

![image](https://user-images.githubusercontent.com/79543461/217568181-b8a1d129-cd7a-4aac-abd7-924e285ac575.png)

With this done, you can use encrypt and decrypt the shellcode with this code...

![image](https://user-images.githubusercontent.com/79543461/217568886-cd48441a-21b1-424b-9368-e8ddcb46b5d0.png)


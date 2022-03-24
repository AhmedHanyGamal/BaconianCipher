/*
author: Ahmed Hany Gamal
This is a Baconian Cipher program which will cipher and decipher any given message.
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    while(true){
        string action;
        cout << "for encryption enter '1' \n" << "for decryption enter '2' \n" << "for exiting the program enter '0' \n";

        cout << "please enter your desired action: " << endl;
        cin >> action;

        //checks if the given input is more than 1 character long or not, because 1, 2, and 0 are only one character long
        if(action.size() != 1){
            cout << "Not a valid input :| , please enter a valid number" << endl;
            continue;
        }
        //encrypts the given message
        else if(action[0] == '1'){
            string message;
            int messageLen = 0, charNumEquivalent;
            cout << "Enter the message that you wish to encrypt: \n";
            cin.ignore();
            getline(cin, message);


            //turns the given message to upper case so that it is easier to handle
            for(int i = 0; i < message.size(); i++){
                message[i] = toupper(message[i]);
                if(message[i] != ' '){
                    messageLen++;
                }
            }

            //removes the spaces from the message
            char noSpaceMessage[messageLen];
            for(int i = 0, j = 0; i < message.size(); i++){
                if(message[i] != ' '){
                    noSpaceMessage[j] = message[i];
                    j++;
                }
            }

            //encrypts the message by taking each letter and seeing the binary number of it's equivalent number
            //then each 1 in the binary is turned into a 'b' and each 0 is turned into an 'a'
            //then the string is reversed, printed, and then reset
            string encryption = "";
            for(int i = 0; i < messageLen; i++){
                encryption = "";
                charNumEquivalent = int(noSpaceMessage[i] - 'A');
                for(int j = 0; j < 5; j++){
                    if(charNumEquivalent%2 == 1){
                        encryption += 'b';
                    }
                    else{
                        encryption += 'a';
                    }
                    charNumEquivalent /= 2;
                }
                reverse(encryption.begin(), encryption.end());
                cout << encryption << ' ';
            }
            cout << endl;
        }
        //decrypts the given message
        else if(action[0] == '2'){
        cout << "Enter the message that you wish to decrypt: \n";
        string message, noSpaceMessage = "", decryption = "";
        int decryptionNum = 0;
        cin.ignore();
        getline(cin, message);

        //removes the spaces from the message
        for(int i = 0; i < message.size(); i++){
            if(message[i] != ' '){
                noSpaceMessage += message[i];
            }
        }

        //decrypts the given message by treating 'b's as 1s in binary and 'a's as 0s
        //every 5 letters before decryption are 1 letter after
        int encryptionValue = 16;
        for(int i = 0; i < noSpaceMessage.size(); i++){
            if(i % 5 == 4){
                if(noSpaceMessage[i] == 'b'){
                    decryptionNum += encryptionValue;
                    decryption += char(decryptionNum + 'A');
                    decryptionNum = 0;
                    encryptionValue = 16;
                    continue;
                }
                else if(noSpaceMessage[i] == 'a'){
                    decryption += char(decryptionNum + 'A');
                    decryptionNum = 0;
                    encryptionValue = 16;
                    continue;
                }
            }
            else if(noSpaceMessage[i] == 'b'){
                decryptionNum += encryptionValue;
            }
            encryptionValue /= 2;
        }

        cout << decryption << endl;
        }
        //ends the program
        else if(action[0] == '0'){
            cout << "thank you for using our program \n";
            break;
        }
        //sends a message telling the user that his input is invalid if it is
        else{
            cout << "Not a valid input :| , please enter a valid number" << endl;
            continue;
        }

    }

    return 0;
}

/*
  Parke
  02/09/2023
  Brute Forcing Caesar Cipher
  We will take three messages from the user along with 3 shift values. The first message we will encrypt based on     the key given. The second one we will decrypt based on the key given. The final string we will perform a brute      force attack on it by trying to guess the shift value that was used to encrypt the message
*/

#include <iostream>
#include <string>
#include <vector>

char decrypt(char, int); // Part 3 function

int main() {
    // Part 1 Encryption
    std::string first_text;
    //std::cout << "Enter your message to be encrypted here: ";
    std::getline(std::cin, first_text);
    std::string secret_message = "";
    int first_key;
    //std::cout << "Enter your shift key: ";
    std::cin >> first_key;
    std::cin.ignore();
    for (auto b : first_text) {
        if (isspace(b)) {
            b = ' ';
            secret_message += b;
        }
        else if (tolower(b) >= 'a' && tolower(b) <= 'z') {
            b += first_key;
            if (tolower(b) >= 'a' && tolower(b) <= 'z') {
                secret_message += toupper(b);
            }
            else if (b > 'z') {
                b = b - 'z' + 'a' - 1;
                secret_message += toupper(b);
            }
        }
    }

    // Part 2 Decryption
    std::string second_text;
    //std::cout << "Enter message to be decrypted here: ";
    std::getline(std::cin, second_text);
    std::string decrypted_message = "";
    int second_key;
    //std::cout << "Enter your shift number: ";
    std::cin >> second_key;
    std::cin.ignore();
    for (auto c : second_text) {
        if (isspace(c)) {
            c = ' ';
            decrypted_message += c;
        }
        else if (toupper(c) >= 'A' && toupper(c) <= 'Z') {
            c -= second_key;
            if (toupper(c) >= 'A' && toupper(c) <= 'Z') {
                decrypted_message += tolower(c);
            }
            else if (c < 'A') {
                c = c + 'Z' - 'A' + 1;
                decrypted_message += tolower(c);
            }
        }
    }

    // Part 3 Brute Force Attack
    std::string cipher_text;
    //std::cout << "Enter in the ciphertext you want to crack: ";
    std::getline(std::cin, cipher_text);
    std::string cracked_text = "";

    // Average letter frequency in English language. alpha_values[0] corresponds to 'a', 
    // alpha_values[1] to 'b' and so on...
    double alpha_values[] = { .0684,.0139,.0146,.0456,.1267,
.0234,.0180,.0701,.0640,.0033,.0093,.0450,.0305,.0631,.0852,.0136,.0004,.0534,
.0659,.0850,.0325,.0084,.0271,.0007,.0315,.0004 };
    int alpha_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    double empty_array[25] = {};

    int i = 1;
    int j = 0;
    double our_num = 0;
    for (auto key : alpha_array) {
        //std::cout << "\nKey = " << key << "\t";
        for (auto letter : cipher_text) {
            letter = decrypt(letter, i);
            cracked_text += letter;
        }

        // This inner loop is using heuristics. Our simple approach tests the average frequency of a letter in a            // given language. For the english language, our first value in the alpha_values array corresponds to the           // letter 'a', our second corresponds to the letter 'b', and so on. We build a "score" so to speak of each          // cipher_text we have cracked by adding each alpha_value corresponding to each letter throughout the               // cracked text. We add each total score from each cracked_text to our empty_array, then find the max value         // in this array. This max_val is our key code used to encrypt the text! :)
        for (int i = 0; i < 246; i++) {
            if (tolower(cracked_text[i]) == 'a'){
                our_num += alpha_values[0];
            }
            else if (tolower(cracked_text[i]) == 'b') {
                our_num += alpha_values[1];
            }
            else if (tolower(cracked_text[i]) == 'c') {
                our_num += alpha_values[2];
            }
            else if (tolower(cracked_text[i]) == 'd') {
                our_num += alpha_values[3];
            }
            else if (tolower(cracked_text[i]) == 'e') {
                our_num += alpha_values[4];
            }
            else if (tolower(cracked_text[i]) == 'f') {
                our_num += alpha_values[5];
            }
            else if (tolower(cracked_text[i]) == 'g') {
                our_num += alpha_values[6];
            }
            else if (tolower(cracked_text[i]) == 'h') {
                our_num += alpha_values[7];
            }
            else if (tolower(cracked_text[i]) == 'i') {
                our_num += alpha_values[8];
            }
            else if (tolower(cracked_text[i]) == 'j') {
                our_num += alpha_values[9];
            }
            else if (tolower(cracked_text[i]) == 'k') {
                our_num += alpha_values[10];
            }
            else if (tolower(cracked_text[i]) == 'l') {
                our_num += alpha_values[11];
            }
            else if (tolower(cracked_text[i]) == 'm') {
                our_num += alpha_values[12];
            }
            else if (tolower(cracked_text[i]) == 'n') {
                our_num += alpha_values[13];
            }
            else if (tolower(cracked_text[i]) == 'o') {
                our_num += alpha_values[14];
            }
            else if (tolower(cracked_text[i]) == 'p') {
                our_num += alpha_values[15];
            }
            else if (tolower(cracked_text[i]) == 'q') {
                our_num += alpha_values[16];
            }
            else if (tolower(cracked_text[i]) == 'r') {
                our_num += alpha_values[17];
            }
            else if (tolower(cracked_text[i]) == 's') {
                our_num += alpha_values[18];
            }
            else if (tolower(cracked_text[i]) == 't') {
                our_num += alpha_values[19];
            }
            else if (tolower(cracked_text[i]) == 'u') {
                our_num += alpha_values[20];
            }
            else if (tolower(cracked_text[i]) == 'v') {
                our_num += alpha_values[21];
            }
            else if (tolower(cracked_text[i]) == 'w') {
                our_num += alpha_values[22];
            }
            else if (tolower(cracked_text[i]) == 'x') {
                our_num += alpha_values[23];
            }
            else if (tolower(cracked_text[i]) == 'y') {
                our_num += alpha_values[24];
            }
            else if (tolower(cracked_text[i]) == 'z') {
                our_num += alpha_values[25];
            }
        }
        empty_array[i] += our_num;
        j++;
        i++;
        cracked_text = "";
        our_num = 0;
    }

    // Output Results
    std::cout << "Part 1 Encrypt: " << secret_message << std::endl;
    std::cout << "\nPart 2 Decrypt: " << decrypted_message << std::endl;
    double max_val = 5;
    int index = 0;
    for (int i = 0; i < 25; i++) {
        if (empty_array[i] > max_val) {
            max_val = empty_array[i];
            index = i;
        }
    }
    //std::cout << "\n" << max_val << "\t" << index << std::endl;
    std::cout << "\nPart 3 KeyCode: " << index << std::endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
// Function: Attempts to decrypt letter by shifting it up the alphabet 'key' times   /
// Params: Letter as a char and key as an int value                                  /
// Return: Letter shifted 'key' times                                                /
//////////////////////////////////////////////////////////////////////////////////////
char decrypt(char letter, int key) {
    int position = (letter - key - 'A') % 26;
    if (position < 0)
        position += 26;
    return (char)position + 'a';
}

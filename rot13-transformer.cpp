/*****************************************************************
 *                          ROT13 Passcode Transformer
 * 
 * Author      : KeesOG
 * Description : This program reads a ROT13 encoded passcode from
 *               user input, transforms it using the ROT13 cipher,
 *               and outputs the transformed passcode.
 *****************************************************************/

#include <iostream>
using namespace std;

// Main function to process and transform the password using ROT13
int main(){
    string password; // User's original input
    string new_password; // Output for the transformed password

    cout << "Please enter rot13 passcode: " << endl;
    getline(cin, password); // Read user input

    // Loop through each character in the password
    for(size_t i = 0; i < password.length(); i++){
        char password_char = password[i]; // Current character
        int hex_value = 0;
        bool is_upper = false; // Track if character is uppercase
        bool is_number = false; // Track if character is a digit

        // Handle uppercase characters
        if(isupper(password_char)){
            is_upper = true;
            password_char = tolower(password_char);
        }

        // Handle digit characters
        if(isdigit(password_char)){
            hex_value = (int)password_char;
            is_number = true;
        }

        // Apply ROT13 transformation for non-digit characters
        if(!is_number){
            hex_value = (int)password_char + 13;
            if(hex_value > 122){ // Wrap around past 'z'
                hex_value = (hex_value - 122) + 96;
            }
        }

        char new_password_char = (char)hex_value; // Convert back to char
        if(is_upper){ // Restore to uppercase if needed
            new_password_char = toupper(new_password_char);
        }

        new_password.push_back(new_password_char); // Append to output
    }

    cout << "CRACKED PASSWORD: " << new_password << endl; // Display transformed password
}
	

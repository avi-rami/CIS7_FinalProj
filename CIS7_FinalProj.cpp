// Name: Avi Rami
// Date: 12/06/2022
// CIS 7 Final Project: Vigenere Cipher Decryption

#include <iostream>
#include <string>

using namespace std;

// function prototypes
string encrypt(string text, string key);
string decrypt(string text, string key);

int main()
{
	// introduces program with a welcome message
	cout << "Welcome to the Vigenere Cipher!" << endl;
	cout << "This program will encrypt and decrypt messages provided by you." << endl;

	// prompts user to choose either encryption or decryption
	int choice;
	cout << endl << "Enter 1 for encryption or 2 for decryption: "; cin >> choice; cin.ignore();

	// validates user choice and prompts for new input if choice is invalid
	while (choice != 1 && choice != 2)
	{
		cout << "Not a valid option. Please enter 1 for encryption or 2 for decryption: ";  cin >> choice; 
	}

	// uses user input to activate either encryption or decryption
	if (choice == 1)
	{
		cout << endl << "You have chosen encryption!" << endl;

		// Ask the user to enter the text to be encrypted
		cout << "Enter the text to encrypt (text should be a single string without spaces or symbols): ";
		string text;
		getline(cin, text);

		// Ask the user to enter the encryption key
		cout << "Enter the encryption key (key should be same format and length as text): ";
		string key;
		getline(cin, key);

		// calls encrypt function to create encrypted message, then prints the message
		string encrypted = encrypt(text, key);
		cout << "Encrypted text: " << encrypted << endl;
	}
	else if (choice == 2)
	{
		cout << endl << "You have chosen decryption!" << endl;

		// Ask the user to enter the text to be decrypted
		cout << "Enter the text to be decrypted (text should be a single string without spaces or symbols): ";
		string text;
		getline(cin, text);

		// Ask the user to enter the decryption key
		cout << "Enter the decryption key (key should be same format and length as text): ";
		string key;
		getline(cin, key);

		// calls decrypt function to create decrypted message, then prints the message
		string decrypted = decrypt(text, key);
		cout << "Decrypted text: " << decrypted << endl;
	}

	return 0;
}

// FUNCTION DEFINITIONS //

// Function to encrypt the given text using the Vigenere Cypher
string encrypt(string text, string key)
{
	// Make sure the key is uppercase
	for (int i = 0; i < key.length(); i++)
		key[i] = toupper(key[i]);

	// Create the ciphertext string
	string encrypted = "";
	for (int i = 0; i < text.length(); i++)
	{
		// Get the current plaintext character and make it uppercase
		char c = toupper(text[i]);

		// Shift the character by the key
		if (isalpha(c))
			encrypted += (c - 'A' + key[i % key.length()] - 'A') % 26 + 'A';
		else
			encrypted += c;
	}

	// Return the encrypted text
	return encrypted;
}

// Function to decrypt the given text using the Vigenere Cypher
string decrypt(string text, string key)
{
	// Convert the input text and key to uppercase
	for (int i = 0; i < text.length(); i++)
		text[i] = toupper(text[i]);

	for (int i = 0; i < key.length(); i++)
		key[i] = toupper(key[i]);

	// Create a string to store the decrypted text
	string decrypted = "";

	// Loop through each character in the text and decrypt it using the key
	for (int i = 0, j = 0; i < text.length(); i++)
	{
		char c = text[i];

		// If the character is not an alphabet, don't encrypt it
		if (c < 'A' || c > 'Z')
		{
			decrypted += c;
			continue;
		}

		// Encrypt the character using the Vigenere Cypher
		decrypted += (c - key[j] + 26) % 26 + 'A';
		j = (j + 1) % key.length();
	}

	// Return the decrypted text
	return decrypted;
}


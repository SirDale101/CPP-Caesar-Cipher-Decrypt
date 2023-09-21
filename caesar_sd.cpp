#include <iostream>
#include <string>
#include <fstream>
#include "enc_library_sd.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	//Reads file and puts it into a string
	string file_text;
        string cipher_text;
        ifstream file(argv[1]);

        if(file)
        {
                while(getline(file, file_text))
                {
                        cipher_text+= file_text;
                }
        }
        else
        {
                cout << "Error: Can't Find File" << endl;
		return 0;
        }
        file.close();
	int alphabet[26] = {0};

	//Get's frequency of characters and converts string to upper case
	for(int i =0; i < cipher_text.length(); i++)
	{
		char temp = cipher_text[i];
		if(is_alpha(temp) == true)
		{
			if(is_upper(temp) == true)
			{
				character_count(temp, alphabet);
			}
			else
			{
				char upper_temp = to_upper(temp);
				cipher_text[i] = upper_temp;
				character_count(upper_temp, alphabet);
			}
		}
	}
	int index = get_max_index(alphabet);
	int key = 0;
	print_analysis_array(key, index);

	//Turns string to char array
	int length = cipher_text.length();
	char cipher_array[length + 1];
	char plain_array[length + 1] = {0};
	for(int i = 0; i < length; i++)
	{
		cipher_array[i] = cipher_text[i];
	}

	//Decryption and user key choice
	char key_response;
	char decryption_response;
	label_decryption:
	cout << "The key is set to " << key << ". Would you like to continue with this key?(Y/N)" << endl;
	cin >> key_response;

	if(key_response == 'Y' || key_response == 'y')
	{
		decryption decryption_obj(cipher_array, key, plain_array, length);
		decryption_obj.decrypt();
		for(int i = 0; i < 100; i++)
		{
			cout << plain_array[i] << endl;
		}
		cout << "Would you like to continue with the decryption proccess?(Y/N)" << endl;
		cin >> decryption_response;

		if(decryption_response == 'Y' || decryption_response == 'y')
		{
			//Writes plain text to file
			ofstream file(argv[2]);
        		if(file)
			{
        			for(int i = 0; i < length; i++)
        			{
                			file << plain_array[i];
        			}
        		}
			file.close();
			cout << "Writing to file " << argv[2] << endl;
		}
		else if(decryption_response == 'N' || decryption_response == 'n')
		{
			cout << "Enter a new value for the key" << endl;
			cin >> key;
			decryption_response = '0';
			goto label_decryption;
		}
		else
		{
			cout << "Error: Invalid Input" << endl;
		}
	}
	else if(key_response == 'N' || key_response == 'n')
	{
		cout << "Enter a new value for the key" << endl;
                cin >> key;
                goto label_decryption;
	}
	else
	{
		cout << "Error: Invalid Input" << endl;
	}
	return 0;
}

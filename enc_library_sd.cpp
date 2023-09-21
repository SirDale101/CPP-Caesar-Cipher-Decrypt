#include "enc_library_sd.hpp"
#include <iostream>
using namespace std;

/** Turns ASCII into integer and stores value into an array
	*	@author S Dale
	*	@param[in] temp, a character of the cipher text
	*	@param[in] alphabet, an array used to store
	*	@date 13/01/2020
	*	@test character_count('C') -> 2
	*	@test character_count('A') -> 0
	*	@test character_count('T') -> 19
	*	@test character_count('4') -> -1
	*	@test character_count('/') -> -1
	*	@test character_count('a') -> -1
*/

void character_count(char temp, int* alphabet)
{
	int pos;
	pos = int(temp) - 65;
	alphabet[pos] = alphabet[pos] + 1;
}

/** Checks to see if character is an alphabetic
        *       @author S Dale
        *       @param[in] temp, a character of the cipher text
        *       @return boolean if character is alphabetic else it returns 0
        *       @date 13/01/2020
        *       @test is_alpha('A') -> 1
        *       @test is_alpha('L') -> 1
        *       @test is_alpha('w') -> 1
        *       @test is_alpha('4') -> 0
        *       @test is_alpha('/') -> 0
        *       @test is_alpha('k') -> 1
*/

bool is_alpha(char temp)
{
	bool bool_alpha;

	if(temp >= 'A' && temp <= 'Z' || temp >= 'a' && temp <= 'z')
		{
			bool_alpha = true;
		}
		else
		{
			bool_alpha = false;
		}
	return bool_alpha;
}

/** Checks to see if character is upper case
        *       @author S Dale
        *       @param[in] temp, a character of the cipher text
        *       @return boolean if character is upper-case else it returns 0
        *       @date 13/01/2020
        *       @test is_upper('A') -> 1
        *       @test is_upper('P') -> 1
        *       @test is_upper('g') -> 0
        *       @test is_upper('4') -> -1
        *       @test is_upper('/') -> -1
        *       @test is_upper('r') -> 0
*/

bool is_upper(char temp)
{
	bool bool_upper;
	if(temp >= 'A' && temp <= 'Z')
	{
		bool_upper = true;
	}
	else
	{
		bool_upper = false;
	}
	return bool_upper;
}

/** Coverts character to upper-case
        *       @author S Dale
        *       @param[in] temp, a character of the cipher text
        *       @return the new upper case character
        *       @date 13/01/2020
        *       @test to_upper('a') -> A
        *       @test to_upper('w') -> W
        *       @test to_upper('g') -> G
        *       @test to_upper('4') -> -1
        *       @test to_upper('/') -> -1
        *       @test to_upper('A') -> -1
*/

char to_upper(char temp)
{
	char output_upper = temp - 32;
	return output_upper;
}

/** Finds the largest value in the array and its position
        *       @author S Dale
        *       @param[in] alphabet, Array contating the frquency of characters
        *       @return the integer position of the largest value in the array
        *       @date 13/01/2020
        *       @test get_max_index('10') ->
        *       @test get_max_index('') ->
        *       @test get_max_index('') ->
        *       @test get_max_index('A') -> -1
        *       @test get_max_index('/') -> -1
        *       @test get_max_index('a') -> -1
*/

int get_max_index(int* alphabet)
{
        int largest = alphabet[0];
        int position, i;

        for(int i = 0; i < 26; i++)
        {
                if(alphabet[i] > largest)
                {
                        largest = alphabet[i];
                        position = i+1;
                }
        }
        return position;
}

/** Finds the largest value in the array and its position
        *       @author S Dale
        *       @param[in]
	*	@param[in]
        *       @date 13/01/2020
        *       @test print_analysis_array('') ->
        *       @test print_analysis_array('') ->
        *       @test print_analysis_array('') ->
        *       @test print_analysis_array('') ->
        *       @test print_analysis_array('') ->
        *       @test print_analysis_array('') ->
*/

void print_analysis_array(int& key, int index)
{
	int most_common = 0;
	most_common = index + 64;
	cout << "The most common character is " << char(most_common) << endl;
	key = most_common - 69;
	cout << "The most likley key would be " << key << endl;
}

decryption::decryption(char *cipher_array, int key, char *plain_array, int length)
{
        this->cipher_array = cipher_array;
        this->key = key;
        this->plain_array = plain_array;
        this->length = length;
}

/** Decrypts each character in the array and stores it in another array
        *       @author S Dale
        *       @param[in] length, The length of the array
        *       @param[in] cipher_array, Contains cipher text
	*       @param[in] plain_array, Contains decrypted text
	*       @param[in] key, the number of places moved from the original character
        *       @date 13/01/2020
        *       @test decryption::decrypt('F') -> T
        *       @test decryption::decrypt('O') -> C
        *       @test decryption::decrypt('*') -> -1
        *       @test decryption::decrypt('a') -> -1
        *       @test decryption::decrypt('3') -> -1
        *       @test decryption::decrypt('X') -> L
*/

void decryption::decrypt()
{
	int offset;
	int new_key;
	for(int i = 0; i < length; i++)
        {
                if(cipher_array[i] >= 'A' && cipher_array[i] <= 'Z')
                {
                        if(cipher_array[i] - key < 65)
                        {
                        offset = cipher_array[i] - 65;
                        new_key = key - offset;
                        plain_array[i] = 91 - new_key;
                        }
                        else
                        {
                                plain_array[i] = cipher_array[i] - key;
                        }
		}
		else if(cipher_array[i] == 32)
                {
			plain_array[i] = cipher_array[i];
                }

        }
}

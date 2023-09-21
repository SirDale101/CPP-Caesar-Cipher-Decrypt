#ifndef DECRYPTION_H
#define DECRYPTION_H

void character_count(char temp, int* alphabet);
bool is_alpha(char temp);
bool is_upper(char temp);
int get_max_index( int array[]);
char to_upper(char temp);
int get_max_index( int* alphabet);
void print_analysis_array(int& key, int index);

class decryption{
        char *cipher_array;
        int key;
	char *plain_array;
        int length;
public:
        decryption(char *cipher_array, int key, char *plain_array, int length);
        //void decrypt();
	void decrypt();
};

#endif

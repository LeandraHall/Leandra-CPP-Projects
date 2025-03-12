//Leandra Hall SCIS-123-01 4/7/2022

//This program should determine the number of vowels in an inputted string using a function
#include <iostream>
#include <string>

using namespace std;

//Int main function which includes the function prototype/call in addition to the vowel count
int main (){

  //Variable delcarations
  int count = 0;
  string sentence;
  bool isVowel(char chr);

  //user prompt
  cout << "Input a series of characters either all together or seperated by spaces " << endl;
  getline(cin, sentence);

  //Loop that interates through each character in the string and counts the character as a vowel if it is determined to be one
  for (int i = 0; i < sentence.length(); i++){
    if (isVowel(sentence[i]) == true){
      count = count + 1;
    }
  }

  //Prints out the number of vowels
  cout << "The nuumber of vowels is " << count << endl;
  return 0;
}

//The function isVowel that evaluates if an inputted character is a vowel
bool isVowel(char chr)
{
  if (chr == 'A' or chr == 'a'){
    return true;
  }
  if (chr == 'E' or chr == 'e'){
    return true;
  }
  if (chr == 'I' or chr == 'i'){
    return true;
  }
  if (chr == 'O' or chr == 'o'){
    return true;
  }
  if (chr == 'U' or chr == 'u'){
    return true;
  }
  else{
    return false;
  }
}

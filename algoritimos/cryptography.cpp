#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  string key = argv[1];

  if (key.size() != 26) {
    cout << "A chave tem que ter 26 caracters\n";
    return 1;
  }

  cout << "Palavra: ";
  string word;
  string crypt = "";

  getline(cin, word);

  for (int i = 0; i < 26; i++) {
    cout << key[i] << " ";
  }

  cout << "\n";

  char digit;
  for (int i = 0; i < word.size(); i++) {
    if (word[i] >= 65 && word[i] <= 90) {
      digit = key[word[i] - 65];
    } else if (word[i] >= 97 && word[i] <= 122) {
      digit = key[(word[i] - 32) - 65];
      digit += 32;
    } else {
      digit = word[i];
    }

    crypt += digit;
  }

  cout << "Palavra: " << word << "\n";
  cout << "Criptografia: " << crypt << "\n";

  return 0;
}

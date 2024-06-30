#include <fstream>
#include <iostream>

int main() {
  std::cout << "Open you text file\n";

  std::ifstream notebook;
  do {
    std::string link;
    std::cout << "Input link on you file.txt\n";
    std::cin >> link;

    notebook.open(link, std::ios::binary);  // C:\develop\Practice\Practice-19.5\words.txt
    if (!notebook.is_open()) std::cerr << "Invalid folder link. Try again\n";
  } while (!notebook.is_open());
  std::cout << "You have successfully opened the file. Text in you file: \n\n";

  char text_in_file[2];
  int size = sizeof(text_in_file);

  do {
    notebook.read(text_in_file, size);
    text_in_file[1] = 0;
    std::cout << text_in_file;

    int pos = notebook.tellg();
    pos--;
    notebook.seekg(pos);
  } while (notebook.gcount() == 2);

  notebook.close();
}
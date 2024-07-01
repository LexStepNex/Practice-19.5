#include <fstream>
#include <iostream>

void is_png(char str[], char control[], int sizeControl) {
  for (int i = 0; i < sizeControl; i++) {
    if (str[i] == control[i]) {
      if (i == 3) {
        std::cout << "This file PNG\n";
      }
    } else {
      std::cout << "This file NOT PNG\n";
      break;
    }
  }
}

int main() {
  std::cout << "Open you PNG file\n";

  std::ifstream picture;

  do {
    std::string link;
    std::cout << "Input link on you file.txt\n";
    std::cin >> link;

    int sizeLink = link.size();
    if (link[sizeLink - 3] == 'p' && link[sizeLink - 2] == 'n' &&
        link[sizeLink - 1] == 'g') {
      std::cout << "This file has the extension .png\n";
    } else {
      std::cout << "This file does not have a png extension\n";
    }

    picture.open(link, std::ios::binary);  // C:\develop\Practice\Practice-19.5\For_9.5.4.png
    if (!picture.is_open()) std::cerr << "Invalid folder link. Try again\n";
  } while (!picture.is_open());
  std::cout << "You have successfully opened the file. Text in you file: \n\n";

  char text_in_file[4];
  char contorlPng[4] = {-119, 'P', 'N', 'G'};
  int sizeControl = sizeof(contorlPng);

  picture.read(text_in_file, sizeof(text_in_file));

  is_png(text_in_file, contorlPng, sizeControl);

  picture.close();
}
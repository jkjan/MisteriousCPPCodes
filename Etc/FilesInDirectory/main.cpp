#include <iostream>
#include <dirent.h>
#include <cstring>
#include <fstream>

int main() {
    DIR *dir;
    struct dirent *ent;

    std::ofstream all;
    all.open("all.txt");

    if ((dir = opendir ("../../../../GitHubRepos/NLP/data/English/raw/cnn/stories")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            char word[1024];
            if (ent->d_name[0] != '.') {
                char dirname[1024] = "../../../../GitHubRepos/NLP/data/English/raw/cnn/stories/";
                std::ifstream file;
                file.open(strcat(dirname, ent->d_name));
                while (!file.eof()) {
                    file >> word;
                    all << word << " " ;
                }
                file.close();
                all << "\n";
            }
        }
        closedir (dir);
        all.close();
    } else {
        perror("no file");
        return EXIT_FAILURE;
    }

    return 0;
}

#include <iostream>
#include <dirent.h>
#include <cstring>
#include <fstream>

int main() {
    DIR *dir;
    struct dirent *ent;

    std::ofstream all;
    all.open("../../../../GitHubRepos/dev/blogducinema/queries/imagequeries.txt");
    all << "insert into image(file_image, name_image) values\n";
    if ((dir = opendir ("../../../../GitHubRepos/dev/blogducinema/res/img")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            char word[1024];
            if (ent->d_name[0] != '.') {
                char dirname[1024] = "../../../../GitHubRepos/dev/blogducinema/res/img/";
                std::ifstream file;
                all << "(\"D:/GitHubRepos/dev/blogducinema/res/img/" << ent->d_name << "\", \"" << ent->d_name << "\"),\n";
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

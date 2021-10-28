#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile {
protected:

    const string FILENAME;

public:

    TextFile(string filename) : FILENAME(filename) {
    }

    string getFilename();
//    bool isFileEmpty();
};

#endif // TEXTFILE_H

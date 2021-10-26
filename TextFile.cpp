#include "TextFile.h"

string TextFile::getFilename() {
    return FILENAME;
}

bool TextFile::isFileEmpty() {
    bool emptyFile = true;
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::app);

    if (textFile.good() == true) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            emptyFile = false;
    }

    textFile.close();
    return emptyFile;
}

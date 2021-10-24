#ifndef INCOMESFILE_H
#define INCOMESFILE_H


class IncomesFile {
    int getUserIdFromXmlFile();
    int getIncomeIdFromXmlFile();
    int getIncomeData();

public:
    IncomesFile();

    void writeIncomeToXmlFile();
    vector <Income> loadIncomesOfLoggedInUserFromXmlFile();
    int loadLastIncomeIdFromXmlFile();
};

#endif // INCOMESFILE_H

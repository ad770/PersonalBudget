#include "UsersFile.h"

vector <User> UsersFile::loadUsersDataFromXmlFile() {
    CMarkup xml;
    User user;
    vector <User> users;

    if (!xml.Load(getFilename())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("UsersFile");
        xml.Save(getFilename());
    }
    xml.FindElem("UsersFile");
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();

        xml.FindElem("UserId");
        user.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());

        users.push_back(user);

        xml.OutOfElem();
    }

    return users;
}

void UsersFile::writeUserDataToXmlFile(User user) {
    CMarkup xml;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
    } else {

        xml.FindElem("UsersFile");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId",user.getUserId());
        xml.AddElem("Login",user.getLogin());
        xml.AddElem("Password",user.getPassword());
        xml.AddElem("Name",user.getName());
        xml.AddElem("Surname",user.getSurname());

        xml.OutOfElem();
        xml.OutOfElem();

        xml.Save(getFilename());
    }
}

void UsersFile::changePasswordInXmlFile(User user) {
    CMarkup xml;
    int loggedInUserId = user.getUserId();
    bool check = false;
    if (!xml.Load(getFilename())) {
        cout << "Blad odczytu pliku!";
    } else {
        xml.FindElem("UsersFile");
        xml.IntoElem();
        xml.FindElem("User");
        xml.IntoElem();
        do {
            xml.FindElem("UserId");
            if (atoi(xml.GetData().c_str())!=loggedInUserId)
                xml.OutOfElem();
            else {
                xml.FindElem("Password");
                xml.SetData(user.getPassword());
                check = true;
                xml.OutOfElem();
                xml.OutOfElem();
                xml.OutOfElem();

                xml.Save(getFilename());
            }
        } while (check == false);
    }
}

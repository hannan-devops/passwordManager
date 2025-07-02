#include<iostream>

#include<fstream>

#include<string>

#include<cmath>

#include<cstdlib>

#include<ctime>




using namespace std;

string filename = "all_Profiles.txt";
string predefined_Security_Key = "password";

// FUNCTIONS PROTOTYPE




bool isEmailCorrect(string email);
bool isEmailValidSpace(string email);
bool isEmpty(string& data);
void passwordGenerator(string& password);
bool isPasswordEmpty(string password);
void removespace(string& phone);
bool isphoneEmpty(string phone);
bool isphonevalid(string phone);
void cleancnic(string& cnic);
bool iscnicEmpty(string cnic);
bool iscnicvalid(string cnic);
void yourPassword(string& password, int length, string input, int charlength);
void passwordStrength(string& password);
void crackTime(string& password);

void createprofile(string& email, string& password, string& phone, string& cnic, string filename);
bool emailExist(string email, string filename);
bool validSecurityKey(string securitykey);
void encryption(string& encrypt, int& key);
void menu();
bool emailNotExist(string email, string& password, int& key, char& recommend,string& securitykey, string filename);


void login(string& email, string& password, string& phone, string& cnic, string filename);


void decryption(string& password, int& key);
void usermenu(string& email, string& password, string& phone, string& cnic, string filename);
void viewAllPasswordEntries();
void showAllDecryptedPasswords();
void search();
void update(string& email, string& password, string& phone, string& cnic, string filename);

void deletePassword(string& email, string& password, string& phone, string& cnic, string filename);
void loginEmailInput(string& email, string& password, int& key, char& recommend, string& securitykey);
void emailInput(string& email);
void passwordInput(string& password, string& securitykey, char& recommend);
void phoneNoInput(string& phone);
void cnicInput(string& cnic);

void escapeDoubleQoutes(string& data);
void addingDoubleQoutes(string& data);
void removingDoubleQoutes(string& data);
void unescapeDoubleQoutes(string& data);



void exportPassword(string& email);
void importPassword(string& email);
// END HERE 





int main(){

   

    string email,password, phone, cnic;
    

    int choice;



    cout << "**************************************************\n";
    cout << "*                                                *\n";
    cout << "*                   MAIN MENU                    *\n";
    cout << "*                                                *\n";
    cout << "**************************************************\n";
    // Option 1
    
    
    
    do {
        menu(); // Display the menu
        
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        // Validate user input
        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n*** Invalid Option Chosen ***\n";
            cout << "\nEnter your choice (1-3): ";
            cin >> choice;
        }

        cin.ignore(1000, '\n'); // Clear input buffer
        cout << "\n------------------------------------------" << endl << endl;
        if (choice==3) {
            return 0;
        }
        if (choice == 1) {
            createprofile(email, password, phone, cnic, filename);
        }
        else if (choice == 2) {
            login(email, password, phone, cnic, filename);
            usermenu(email, password, phone, cnic, filename);
        }

        

    } while (choice != 3);
    
    
    
    
    
    
    
    
    
    

}

void menu() {

    //Option 1
    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |       Option 1: Create New Account     |\n";
    cout << "   +----------------------------------------+\n";

    //Option 2
    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |            Option 2: Login!            |\n";
    cout << "   +-----------------------------------------\n";

    //Option 3
    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |             Option 3:  Exit!           |\n";
    cout << "   +----------------------------------------+\n";

    

}


void createprofile(string& email, string& password, string& phone, string& cnic,string filename) {

    emailInput(email);

    char recommend;
    string securitykey;

    passwordInput(password, securitykey, recommend);

    phoneNoInput(phone);

    cnicInput(cnic);






    string encrypted = password;
    int key;

    //Password encryption
    encryption(encrypted,key);
  


    ofstream file(filename,ios::out | ios::app);

    file << email <<endl<< encrypted << endl << key << endl << recommend <<endl <<securitykey<<endl << phone << endl << cnic << endl;
    file << "------------------------------------------"<<endl;
    file.close();

    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |      Profile Created Successfully.     |\n";
    cout << "   +----------------------------------------+\n";
    cout << "\n";
    cout << "\n------------------------------------------" << endl << endl;
    file.close();
}



void login(string& email, string& password, string& phone, string& cnic, string filename) {
    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |                LOGIN  FORM             |\n";
    cout << "   +----------------------------------------+\n";
    cout << "\n";

    string securitykey;//decrypted
    int key;
    char recommend;

    loginEmailInput(email, password, key, recommend, securitykey);

    

    string passwordinput, securitykeyinput;
    char yesNo;

    string encrypted = password;
    decryption(password,key);

    if (recommend=='R') {
        cout << "\n";
        cout << "   +----------------------------------------+\n";
        cout << "   |        Automatically fill password.    |\n";
        cout << "   +----------------------------------------+\n";
        cout << "\n";

        cout << "Enter 'y' for yes and 'n' for no : ";
        cin >>yesNo ;
        if (yesNo == 'y')
        {
            cout << "\n";
            cout << "Option : 1 Enter Security Key To See Your Password. " << endl;
            cout << "Option : 2 Exit." << endl;
            int choice;
            cout << "\nEnter your choice (1-2): ";
            cin >> choice;
            while (cin.fail() || choice < 1 || choice>2)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\n*** Invalid Option Chosen ***\n";

                cout << "\nEnter your choice (1-2): ";
                cin >> choice;
            }
            cin.ignore(1000, '\n');
            cout << "\n------------------------------------------" << endl << endl;
            if (choice==1) {
                cout << "Enter Security Key : ";
                getline(cin, securitykeyinput);
                while (securitykey != securitykeyinput) {
                    cout << "\n*** Wrong Key ***\n";
                    cout << "\nEnter Security Key To See Your Password : ";
                    getline(cin, securitykeyinput);
                }
                cout << endl;

                cout << "Your password is : " << password;
            }
            else {
                return;
            }
            
            

        }
        else if (yesNo == 'n') {
            cout << "Enter Password : ";
            getline(cin, passwordinput);
            while (passwordinput != password) {
                cout << "\n";
                cout << "   +----------------------------------------+\n";
                cout << "   |      Incorrect Password. Try Again.    |\n";
                cout << "   +----------------------------------------+\n";
                cout << "\n";
                cout << "Enter Password : ";
                getline(cin, passwordinput);
            }
        }
    }
    



    else if (recommend == 'N') {
        cout << "Enter Password : ";
        getline(cin, passwordinput);
        while (passwordinput != password) {
            cout << "\n";
            cout << "   +----------------------------------------+\n";
            cout << "   |      Incorrect Password. Try Again.    |\n";
            cout << "   +----------------------------------------+\n";
            cout << "\n";
            cout << "Enter Password : ";
            getline(cin, passwordinput);
        }
    }

    cout << "\n";
    cout << "   +----------------------------------------+\n";
    cout << "   |          Successfully Loged In.        |\n";
    cout << "   +----------------------------------------+\n";
    cout << "\n";

    



}



void usermenu(string& email, string& password, string& phone, string& cnic, string filename) {
    cout << "Option 1 : Add New Password Entry\n"
            "Option 2 : View All Password Entries\n"
            "Option 3 : Search for a Password Entry\n"
            "Option 4 : Update a Password Entry\n"
            "Option 5 : Delete a Password Entry\n"
            "Option 6 : Export Passwords\n"
            "Option 7 : Import Passwords\n"
            "Option 8 : Logout\n";

    cout << "\n";

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>8)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-8): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;

    if (choice == 8) {
        return;
    }

    if (choice==1) {
        createprofile(email, password, phone, cnic, filename);
    }
    else if (choice==2) {
        viewAllPasswordEntries();
    }
    else if (choice == 3) {
        search();
    }
    else if (choice == 4) {
        update(email, password, phone, cnic, filename);
    }
    else if (choice == 5) {
        deletePassword(email, password, phone, cnic, filename);
        return;
    }
    else if (choice == 6) {
        exportPassword(email);
    }
    else if (choice==7) {
        importPassword(email);
    }

    if (choice == 8) {
        return;
    }

    while (choice!=8) {
        usermenu(email, password, phone, cnic, filename);
        return;
    }
    
    

}



void exportPassword(string& email) {

    string inputkey;
    cout << "\nSystem Security Key Required : ";
    getline(cin,inputkey);
    while (inputkey!=predefined_Security_Key) {
        cout << "\n*** Invalid Input ***\n";
        cout << "\nSystem Security Key Required : ";
        getline(cin, inputkey);
    }



    string line;

    fstream csv("Users_Data.csv", ios::out | ios::app);
    if (!csv) {
        cout << "Error opening CSV File.\n";
    }


    ifstream check("Users_Data.csv", ios::in);
    if (!check) {
        cout << "Error opening CSV File.\n";
    }
    while (getline(check, line, ',')) {
        if (line == email) {
            cout << "\nThe data of this account has already been exported.\n\n";
            return;
        }
        else {
            getline(check, line);
        }
    }
    check.close();




    ifstream file(filename, ios::in);
    if (!file) {
        cout << "Error opening files.";
    }

    



    cout << "Option 1 : Export Password As Encrypted.\n"
        "Option 2 : Export Password As Decrypted.\n";
    "Option 3 : Go Back.\n";

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>3)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;

    if (choice == 1) {
        while (getline(file, line)) {
            if (line == email) {
                csv << email << ",";
                getline(file, line);
                escapeDoubleQoutes(line);
                addingDoubleQoutes(line);
                csv << line << ",";
                for (int i = 0; i < 5; i++) {
                    getline(file, line);
                    csv << line << ",";
                }
                
                csv << "encrypted" << endl;

                cout << "\nYour data is exported successfully.\n";
                return;
            }
            else {
                for (int i = 0; i < 7; i++) {
                    getline(file, line);
                }
            }
        }
    }

    else if (choice == 2) {
        while (getline(file, line)) {
            if (line == email) {
                csv << email << ",";

                string password;
                int key;

                getline(file,password);
                file >> key;
                getline(file, line);

                decryption(password,key);

                escapeDoubleQoutes(password);
                addingDoubleQoutes(password);

                csv << password << ","<<key<<",";

                for (int i = 0; i < 4; i++) {
                    getline(file,line);
                    csv << line << ",";
                }


          

                csv << "decrypted" << endl;

                cout << "\nYour data is exported successfully.\n";
                return;
            }
            else {
                for (int i = 0; i < 7; i++) {
                    getline(file, line);
                }
            }
        }
    }
    else if (choice==3) {
        return;
    }



    


}

void importPassword(string& email) {
    string inputkey;
    cout << "\nSystem Security Key Required : ";
    getline(cin, inputkey);
    while (inputkey != predefined_Security_Key) {
        cout << "\n*** Invalid Input ***\n";
        cout << "\nSystem Security Key Required : ";
        getline(cin, inputkey);
    }


    cout << "Option 1 : Import This Account's Data And Display(csv format).\n"
        "Option 2 : Import An Account Which Is Deleted But Exported.\n";
    "Option 3 : Go Back.\n";

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>3)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-3): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;

    
    if (choice==1) {
        string line;
        bool flag = true;

        ifstream check("Users_Data.csv", ios::in);
        if (!check) {
            cout << "Error opening CSV File.\n";
        }
        while (getline(check, line, ',')) {
            if (line == email) {
                cout << line << ",";
                getline(check,line);
                cout << line << endl << endl;
                flag = false;
                break;
            }
            else {
                getline(check, line);
            }
        }
        check.close();
        if (flag) {
            cout << "\nThis account has never been exported.\n";
            return;
        }
        
    }
    else if (choice==2) {

        cout << "Option 1 : Enter Account E-mail\n"
            "Option 2 : Go Back.\n";


        int choose;
        cout << "Enter your choice (1-2): ";
        cin >> choose;
        while (cin.fail() || choose < 1 || choose>2)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n*** Invalid Option Chosen ***\n";

            cout << "\nEnter your choice (1-2): ";
            cin >> choose;
        }
        cin.ignore(1000, '\n');
        cout << "\n------------------------------------------" << endl << endl;

        if (choose==1) {
            string emailImport;
            emailInput(emailImport);

            string line;
            bool flag = true;

            ifstream check("Users_Data.csv", ios::in);
            if (!check) {
                cout << "Error opening CSV File.\n";
            }

            while (getline(check, line, ',')) {
                if (line == emailImport) {
                    string password,securitykey,phoneNo,cnicNo,category;
                    int key;
                    char recommend;
                    getline(check, password, ',');
                    cout<<password<<endl;

                    check >> key;
                    check.ignore(1);
                    cout << key << endl;
                    
                    check >> recommend;
                    check.ignore(1);
                    cout << recommend;

                    getline(check, securitykey, ',');
                    getline(check, phoneNo, ',');
                    getline(check, cnicNo, ',');
                    getline(check, category);

                    removingDoubleQoutes(password);
                    cout << password;
                    unescapeDoubleQoutes(password);
                    cout << password;

                    if (category=="decrypted") {
                        encryption(password,key);
                        cout<<password;
                    }

                    ofstream file(filename,ios::out | ios::app);
                    file << emailImport << endl;
                    file << password << endl;
                    file << key << endl;
                    file << recommend << endl;
                    file << securitykey  << endl;
                    file << phoneNo << endl;
                    file << cnicNo << endl;
                    file << "------------------------------------------" << endl;

                    flag = false;

                    break;
                }
                else {
                    getline(check, line);
                }
            }
            check.close();
            if (flag) {
                cout << "\nThis account has never been exported, so it cannot be imported.\n";
                return;
            }
            else{
                cout << "\nYour Account is Successfullly Backed Up.\n\n";
            }

        }
        
        



    }
    


}

void loginEmailInput(string& email, string& password, int& key, char& recommend, string& securitykey) {
    cout << "Enter E-mail  (@outlook.com or @gmail.com) : ";
    getline(cin, email);
    while (emailNotExist(email, password, key, recommend, securitykey, filename) || isEmpty(email) || !isEmailValidSpace(email) || !isEmailCorrect(email))
    {
        if (emailNotExist(email, password, key, recommend, securitykey, filename)) {
            cout << "\n";
            cout << "   ------------------------------------------\n";
            cout << "   |      Error!  E-mail does not exists    |\n";
            cout << "   ------------------------------------------\n";
            cout << "\n";
        }
        else if (isEmpty(email)) {
            cout << "\n";
            cout << "   ------------------------------------------\n";
            cout << "   |      Error!  E-mail cannot be empty    |\n";
            cout << "   ------------------------------------------\n";
            cout << "\n";
        }
        else if (!isEmailValidSpace(email)) {
            cout << "\n";
            cout << "   +----------------------------------------+\n";
            cout << "   |       E-mail cannot include spaces.    |\n";
            cout << "   +----------------------------------------+\n";
            cout << "\n";
        }
        else if (!isEmailCorrect(email)) {
            cout << "\n";
            cout << "   +----------------------------------------+\n";
            cout << "   |            E-mail is not valid!        |\n";
            cout << "   +----------------------------------------+\n";
            cout << "\n";
        }
        cout << "Enter E-mail  (@outlook.com or @gmail.com) : ";
        getline(cin, email);
    }
}

void emailInput(string& email) {
    cout << "Enter E-mail  (@outlook.com or @gmail.com) : ";
    getline(cin, email);

    while (emailExist(email, filename) || isEmpty(email) || !isEmailValidSpace(email) || !isEmailCorrect(email))
    {
        if (emailExist(email, filename)) {
            cout << "\n";
            cout << "   ------------------------------------------\n";
            cout << "   |      Error!  E-mail already exists      |\n";
            cout << "   ------------------------------------------\n";
            cout << "\n";
        }
        else if (isEmpty(email)) {
            cout << "\n";
            cout << "   ------------------------------------------\n";
            cout << "   |      Error!  E-mail cannot be empty    |\n";
            cout << "   ------------------------------------------\n";
            cout << "\n";
        }
        else if (!isEmailValidSpace(email)) {
            cout << "\n";
            cout << "   +----------------------------------------+\n";
            cout << "   |       E-mail cannot include spaces.    |\n";
            cout << "   +----------------------------------------+\n";
            cout << "\n";
        }
        else if (!isEmailCorrect(email)) {
            cout << "\n";
            cout << "   +----------------------------------------+\n";
            cout << "   |            E-mail is not valid!        |\n";
            cout << "   +----------------------------------------+\n";
            cout << "\n";
        }
        cout << "Enter E-mail  (@outlook.com or @gmail.com) : ";
        getline(cin, email);
    }
}

void passwordInput(string& password , string& securitykey, char& recommend) {
    cout << "\n";
    cout << "+------------------------------------+    +------------------------------------+    +------------------------------------+\n";
    cout << "|    1) Generate Strong Password.    |    |  2) Generate Your Random Password. |    |         3)  Enter Password         |\n";
    cout << "+------------------------------------+    +------------------------------------+    +------------------------------------+\n";
    cout << "\n";

    int choose;
    cout << "Enter Your Choice (1-3) : ";
    cin >> choose;

    while (cin.fail() || (choose < 1 || choose>3)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";
        cout << "Enter Your Choice (1-3) : ";
        cin >> choose;
    }
    cin.ignore(1000, '\n');




    if (choose == 1) {
        char accept = 'n';
        while (accept == 'n') {

            cout << endl;
            passwordGenerator(password);
            cout << endl;
            passwordStrength(password);
            cout << endl;
            crackTime(password);

            recommend = 'R';
            cout << "\n";
            cout << "\n";
            cout << "   +----------------------------------------------------+\n";
            cout << "   |         Do you want to accept this password?       |\n";
            cout << "   |                                                    |\n";
            cout << "   |         Type 'y' for yes and 'n'  for no           |\n";
            cout << "   +----------------------------------------------------+\n";
            cout << "\n";
            cout << "Enter y or n : ";
            cin >> accept;
            while (cin.fail() || (accept != 'y' && accept != 'n')) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\n*** Invalid Option Chosen ***\n";
                cout << "Enter y or n : ";
                cin >> accept;
            }
            cin.ignore(1000, '\n');
        }
        cout << "\n";
        cout << "Enter Security Key (4-digit): ";
        getline(cin, securitykey);
        while (validSecurityKey(securitykey)) {
            cout << "\n*** Invalid Option Chosen ***\n";
            cout << "Enter Security Key (4-digit): ";
            getline(cin, securitykey);
        }

    }
    else if (choose == 2) {

        recommend = 'R';


        int length;
        cout << "Enter length of password you want to generate: ";
        cin >> length;
        cin.ignore(1000, '\n');
        while (cin.fail() || length < 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nPassword Length Should Be 4 or greater than four.\n";
            cout << "\nEnter length of password you want to generate: ";
            cin >> length;
        }

        int charlength = 0;
        string input = "";

        while (charlength == 0) {
            cout << "\nDo not let input empty it will result in error.\n";
            cout << "Enter character you want to include in your password: ";
            getline(cin, input);

            for (int i = 0; input[i] != '\0'; i++) {
                charlength++;
            }


        }


        char accept = 'n';

        while (accept == 'n') {

            cout << endl;
            yourPassword(password, length, input, charlength);
            cout << endl;
            passwordStrength(password);
            cout << endl;
            crackTime(password);

            cout << "\n";
            cout << "\n";
            cout << "   +----------------------------------------------------+\n";
            cout << "   |         Do you want to accept this passwprd?       |\n";
            cout << "   |                                                    |\n";
            cout << "   |         Type 'y' for yes and 'n'  for no           |\n";
            cout << "   +----------------------------------------------------+\n";
            cout << "\n";
            cout << "Enter y or n : ";
            cin >> accept;
            while (cin.fail() || (accept != 'y' && accept != 'n')) {

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\n*** Invalid Option Chosen ***\n";
                cout << "Enter y or n : ";
                cin >> accept;
            }
        }
        cout << "\n";
        cin.ignore(1000,'\n');
        cout << "Enter Security Key (4-digit): ";
        getline(cin, securitykey);
        while (validSecurityKey(securitykey)) {
            cout << "\n*** Invalid Option Chosen ***\n";
            cout << "Enter Security Key (4-digit): ";
            getline(cin, securitykey);
        }
    }
    else {
        recommend = 'N';
        string OkCancel = "Cancel";
        while (OkCancel == "Cancel") {

            cout << "Enter Password: ";
            getline(cin, password);
            if (isPasswordEmpty(password)) {
                cout << "\n";
                cout << "   ******************************************\n";
                cout << "   *     Warning! your password is empty.   *\n";
                cout << "   ******************************************\n";
                cout << "\n";

            }
            passwordStrength(password);
            cout << "\n";
            crackTime(password);
            cout << "Enter Ok to confirm otherwise Cancel: ";
            getline(cin, OkCancel);
        }

        cout << "Enter Security Key (4-digit): ";
        getline(cin, securitykey);
        while (validSecurityKey(securitykey)) {
            cout << "\n*** Invalid Option Chosen ***\n";
            cout << "Enter Security Key (4-digit): ";
            getline(cin, securitykey);
        }
    }
}

void phoneNoInput(string& phone) {
    cout << "Enter Phone # (11-digit) : ";
    getline(cin, phone);
    removespace(phone);

    while (isphoneEmpty(phone) || !(isphonevalid(phone))) {
        if (isphoneEmpty(phone)) {
            cout << "\n";
            cout << "   **************************************************\n";
            cout << "   *           Error! Phone # can't be empty        *\n";
            cout << "   **************************************************\n";
            cout << "\n";
        }

        else if (!isphonevalid(phone)) {
            cout << "\n";
            cout << "   **************************************************\n";
            cout << "   *               Error! Invalid Phone #           *\n";
            cout << "   **************************************************\n";
            cout << "\n";
        }

        cout << "Enter Phone # (11-digit) : ";
        getline(cin, phone);
        removespace(phone);

    }
}

void cnicInput(string& cnic) {
    cout << "Enter 13 digit CNIC : ";
    getline(cin, cnic);
    cleancnic(cnic);
    while (iscnicEmpty(cnic) || !(iscnicvalid(cnic))) {
        if (iscnicEmpty(cnic)) {
            cout << "\n";
            cout << "   **************************************************\n";
            cout << "   *           Error! CNIC  can't be empty          *\n";
            cout << "   **************************************************\n";
            cout << "\n";
        }

        else if (!iscnicvalid(cnic)) {
            cout << "\n";
            cout << "   **************************************************\n";
            cout << "   *               Error! Invalid   CNIC            *\n";
            cout << "   **************************************************\n";
            cout << "\n";
        }

        cout << "Enter 13 digit CNIC : ";
        getline(cin, cnic);
        removespace(cnic);

    }
}

// Deletes Account

void deletePassword(string& email, string& password, string& phone, string& cnic, string filename) {
    cout << "   +----------------------------------------+\n";
    cout << "   |             Account Deletion.          |\n";
    cout << "   +----------------------------------------+\n";
    cout << "\n";

    ifstream file(filename,ios::in);
    if (!file) {
        cout << "Error opening files.";
        return;
    }



    string securitykeyinput;
    string securitykey;
    string line;

    bool flag = false;
    while (getline(file, line)) {

        if (line == email) {
            flag = true;

            
            getline(file, line);
            getline(file, line);
            getline(file, line);

            getline(file, line); //Reads Security Key For Confirm Account Deletion.
            securitykey = line;
            break;
        }
        for (int i = 0; i < 7; i++) {
            getline(file, line);
        }
        
    }
    file.close();

    if (!flag) { //If user after deleting want to confirm that the account is deleted or not then he will enter again and message will be shown to him that email not exist
        cout << "Email not found." << endl;
        return;
    }

    cout << "Enter your Security Key : ";
    getline(cin,securitykeyinput);


    while (securitykeyinput!=securitykey) {
        cout << "\n*** Wrong Input ***\n";
        cout << "\nEnter your Security Key : ";
        getline(cin, securitykeyinput);
    }

    file.open(filename,ios::in);

    fstream temp("temp.txt", ios::out);
    if (!temp) {
        cout << "File opening error.\n";
        return;
    }

    while (getline(file,line)) {
        if (line == email) {
            for (int i = 0; i < 7; i++) {
                getline(file, line);
            }
        }
        else {
            temp << line << endl;
            for (int i = 0; i < 7; i++) {
                getline(file, line);
                temp << line << endl;
            }
        }
    }

    file.close();
    temp.close();


    ofstream file1(filename, ios::out | ios::trunc);


    temp.open("temp.txt", ios::in);

    while (getline(temp, line)) {
        file1 << line << endl;
    }

    file1.close();
    temp.close();

    if (remove("temp.txt") == 0) {
        cout << "\nAccount Deleted Successfully.\n" << endl;
    }
    else {
        cout << "Error Occurred While Updating." << endl;
    }

}


void escapeDoubleQoutes(string& data) {
    string result = "";

    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == '"') {
            result += "\"\"";
        }
        else {
            result += data[i];
        }
    }

    data = result;
}

void unescapeDoubleQoutes(string& data) {
    string result = "";
    

    int length = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        length++;
    }

    for (int i = 0; i < length;i++) {
        if (data[i]=='"' && data[i+1]=='"') {
            result += '"';
            i++;
        }
        else {
            result += data[i];
        }
    }
    data = result;

}

void addingDoubleQoutes(string& data) {
    data = "\"" + data + "\"";
}


void removingDoubleQoutes(string& data) {
    
    int n = 0;

    for (int i = 0; data[i] != '\0';i++) {
        n++;
    }

    
    if (n > 1 && data[0] == '"' && data[n - 1] == '"') {
        
        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1];
        }
       
        data[n - 2] = '\0';
        data.resize(n - 2); 
    }
}

void search() {

    cout << "   +----------------------------------------+\n";
    cout << "   |     Search Password By Account Name    |\n";
    cout << "   +----------------------------------------+\n";

    string email, password, securitykey;//decrypted
    int key;
    char recommend;

    loginEmailInput(email, password, key, recommend, securitykey);

    ifstream file(filename, ios::in);

    if (!file) {
        cout << "Error Opening File." << endl;
        return ;
    }

    string line;

    while (getline(file, line)) {

        if (line == email) {
            getline(file, password);

            file>>key;
            getline(file,line);

            cout << "\nEncypted Password : "<<password<<endl;

            decryption(password, key);
            cout << "\nDecrypted Password : " << password <<endl<< endl;
            break;
        }

        for (int i = 0; i < 7; i++) {
            getline(file,line);
        }
        
    }

    file.close();
    cout << "\n";
    cout << "\n------------------------------------------" << endl << endl;
    cout << "Option 1 : Search Again.\n"
        "Option 2 : Exit.\n";

    int choice;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>2)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-2): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;
    if (choice == 1) {
        search();
    }
    else if (choice == 2) {
        return;
    }
}

void update(string& email, string& password, string& phone, string& cnic, string filename) {
    cout << "   +----------------------------------------+\n";
    cout << "   |          Update Your Details.          |\n";
    cout << "   +----------------------------------------+\n\n";

    cout << "Option 1 : E-mail\n"
        "Option 2 : Password\n"
        "Option 3 : Phone Number\n"
        "Option 4 : CNIC Number\n"
        "Option 5 : Exit\n";
    cout << "\n";

    int choice;
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>8)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;
    if (choice == 5) {
        return;
    }
    if (choice == 1) {
        fstream temp("temp.txt",ios::out);
   

        ifstream file(filename,ios::in);
        if (!file || !temp) {
            cout << "Error opening files.";
        }

        string line;


        while (getline(file,line)) {
            if (line==email) {
                emailInput(email);

                temp << email << endl;

                for (int i = 0; i < 7; i++) {
                    getline(file, line);
                    temp << line << endl;
                }
            }
            else {
                temp << line<<endl;
                for (int i = 0; i < 7; i++) {
                    getline(file, line);
                    temp << line << endl;
                }
            }

        }

        file.close();
        temp.close();

        ofstream file1(filename, ios::out | ios::trunc);

        temp.open("temp.txt",ios::in);

        while (getline(temp,line)) {
            file1 << line << endl;
        }

        file1.close();
        temp.close();

        if (remove("temp.txt")==0) {
            cout << "\nE-mail Updated Successfully." << endl<<endl;
        }
        else {
            cout << "Error Occurred While Updating." << endl;
        }
    }
    else if (choice == 2) {
        fstream temp("temp.txt", ios::out);


        ifstream file(filename, ios::in);
        if (!file || !temp) {
            cout << "Error opening files.";
        }

        string line;


        while (getline(file, line))
        {
            if (line == email) {
                temp << email << endl;

                char recommend;
                string securitykey;

                passwordInput(password,securitykey,recommend);

                string encrypted = password;
                int key;

                //Password encryption
                encryption(encrypted, key);
                temp << encrypted <<endl << key << endl<< recommend <<endl<<securitykey<<endl;

                for (int i = 0; i < 5; i++) {
                    getline(file, line);
                }

                temp << line<<endl;

                getline(file,line);
                temp << line << endl;

                getline(file,line);
                temp << line<<endl;

            }
            else {
                temp << line << endl;
                for (int i = 0; i < 7; i++) {
                    getline(file, line);
                    temp << line << endl;
                }
                
            }
        }

        file.close();
        temp.close();

        ofstream file1(filename, ios::out | ios::trunc);

        temp.open("temp.txt", ios::in);

        while (getline(temp, line)) {
            file1 << line << endl;
        }

        file1.close();
        temp.close();

        if (remove("temp.txt") == 0) {
            cout << "\nPassword Updated Successfully." <<endl<< endl;
        }
        else {
            cout << "Error Occurred While Updating." << endl;
        }

    }
    else if (choice == 3) {
        fstream temp("temp.txt", ios::out);


        ifstream file(filename, ios::in);
        if (!file || !temp) {
            cout << "Error opening files.";
        }

        string line;


        while (getline(file, line)) {
            if (line == email) {
                temp << line<<endl;

                for (int i = 0; i < 4; i++) {
                    getline(file, line);
                    temp << line << endl;
                }
                
                phoneNoInput(phone);
                

                temp << phone << endl;

                getline(file, line);//Will get old phone number

                getline(file, line);//read cnic
                temp << line << endl;

                getline(file, line);//read ----------
                temp << line << endl;

            }
            else {
                temp << line << endl;
                for (int i = 0; i < 7;i++) {
                    getline(file,line);
                    temp << line<<endl;
                }
            }

        }

        file.close();
        temp.close();

        ofstream file1(filename, ios::out | ios::trunc);

        temp.open("temp.txt", ios::in);

        while (getline(temp, line)) {
            file1 << line << endl;
        }

        file1.close();
        temp.close();

        if (remove("temp.txt") == 0) {
            cout << "Phone # Updated Successfully." << endl;
        }
        else {
            cout << "Error Occurred While Updating." << endl;
        }
    }
    else if (choice == 4) {
        fstream temp("temp.txt", ios::out);


        ifstream file(filename, ios::in);
        if (!file || !temp) {
            cout << "Error opening files.";
        }

        string line;


        while (getline(file, line)) {
            if (line == email) {
                temp <<email<< endl;

                for (int i = 0; i < 5; i++) {
                    getline(file, line);
                    temp << line << endl;
                }

                cnicInput(cnic);

                temp << cnic << endl;

                getline(file, line);// Reading Old cnci

                getline(file,line);
                temp << line << endl;

            }
            else {
                temp << line << endl;
                for (int i = 0; i < 7;i++) {
                    getline(file,line);
                    temp << line << endl;
                }
            }

        }

        file.close();
        temp.close();

        ofstream file1(filename, ios::out | ios::trunc);

        temp.open("temp.txt", ios::in);

        while (getline(temp, line)) {
            file1 << line << endl;
        }

        file1.close();
        temp.close();

        if (remove("temp.txt") == 0) {
            cout << "CNIC Updated Successfully." << endl;
        }
        else {
            cout << "Error Occurred While Updating." << endl;
        }
    }
    while (choice!=5) {
        update(email, password, phone, cnic, filename);
    }
    return;


}


void viewAllPasswordEntries() {
    ifstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening File.\n";
        return;
    }
    cout << "\n---- Encrypted Passwords ----\n\n";
    int i = 1;

    string password;


    string line;
    while (getline(file, line)) {
        getline(file, password);
           
        cout << "Password # " << i << " = " << password<<endl;
        i++;
        for (int i = 0; i < 6; i++) {
            getline(file,line);
        }

    }
    cout << "\n------------------------------------------" << endl << endl;
    file.close();

    cout << "\n";
    cout << "Option 1 : Show Decrypted Passwords.\n"
        "Option 2 : Continue.\n";

    int choice;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice>2)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n*** Invalid Option Chosen ***\n";

        cout << "\nEnter your choice (1-2): ";
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    cout << "\n------------------------------------------" << endl << endl;
    if (choice == 1) {
        showAllDecryptedPasswords();
    }
    else if (choice == 2) {
        return;
    }

}


void showAllDecryptedPasswords() {
    ifstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening File.\n";
        return;
    }
    cout << "\n\n---- Decrypted Passwords ----\n\n";
    int i = 1;

    string password;
    int key;

    string line;
    while (getline(file, line)) {
        
        getline(file, password);
        
        file >> key;
        getline(file, line);

        decryption(password, key);

        cout << "Password # " << i << " = " << password << endl;
        i++;
        
        for (int i = 0; i < 5; i++) {
            getline(file,line);
        }

    }
    file.close();
    cout << "\n------------------------------------------" << endl << endl;
}


void decryption(string& password,int & key) {
    int n = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        n++;
    }
    for (int i = 0; i < n / 2; i++) {
        char temp = password[i];
        password[i] = password[n - i - 1];
        password[n - i - 1] = temp;
    }
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= key;
    }

}

void encryption(string& encrypted,int& key) {
    
    // We are Shifting ASCII Value Using a Random Key.

    key = 1 + rand() % 10;
    for (int i = 0; encrypted[i] != '\0'; i++) {
        encrypted[i] += key;
    }

    //For Length Calculation.
    int n = 0;
    for (int i = 0; encrypted[i] != '\0'; i++) {
        n++;
    }

    //For Swapping For Better Encryption
    for (int i = 0; i < n / 2; i++) {
        char temp = encrypted[i];
        encrypted[i] = encrypted[n - i - 1];
        encrypted[n - i - 1] = temp;
    }
}

bool validSecurityKey(string securitykey) {
    int length = 0;
    for (int i = 0; securitykey[i] != '\0'; i++) {
        length++;
        if (securitykey[i] < '0' || securitykey[i]>'9') {
            return true;
        }
    }

    if (length != 4) {
        return true;
    }
    return false;
    
}

bool emailExist(string email, string filename) {
    ifstream file(filename,ios::in);

    string line;

    while (getline(file, line)) {
        
        if (line == email) {
            return true;
        }
        for (int i = 0; i < 7; i++) {
            getline(file,line);
        }
    }
    file.close();
    return false;
}

bool emailNotExist(string email,string& password,int& key,char& recommend,string& securitykey,string filename) {

    ifstream file(filename,ios::in);

    if (!file) {
        cout << "Error opening File.\n";
        return true;
    }

    string line;

    while (getline(file, line)) {

        if (line == email) {

            getline(file, password);  // Reads Encrypted password from file

            file >> key;             // Reads keys then move to next line by getline function.
            getline(file, line);
            

            file >> recommend;      //Reads recommendation char and move to next line.
            getline(file, line);

            getline(file,securitykey);

            return false;
        }
        for (int i = 0; i < 7;i++) {
            getline(file,line);
        }
    }


    file.close();
    return true;


}



bool isEmpty(string& data)
{
    int length = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        length++;
    }
    for (int i = 0; i < length; i++) {
        return false;
    }
    return true;
}


bool isEmailValidSpace(string email) {
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == ' ') {
            return false;
        }
    }
    return true;
}


bool isEmailCorrect(string email) {
    int length = 0;

    for (int i = 0; email[i] != '\0'; i++) {
        length++;
    }


    if (length < 11)
    {
        return false;
    }

    //For gmail.com
    bool gmailflag;
    int end = length - 1;
    int start = end - 9;

    string attribute1 = "";

    for (int i = start; i <= end; i++) {
        attribute1 += email[i];
    }



    if (attribute1 == "@gmail.com")
        gmailflag = true;
    else
        gmailflag = false;

    //For @outlook.com
    bool outlookflag = false;
    int end2 = length - 1;
    int start2 = end2 - 11;


    if (length>=13) {
        string attribute2 = "";

        for (int i = start2; i <= end2; i++) {
            attribute2 += email[i];
        }
        if (attribute2 == "@outlook.com")
            outlookflag = true;
        else
            outlookflag = false;
    }

    



    if (gmailflag || outlookflag)
    {
        return true;
    }
    else
        return false;
}



// Important Function

void passwordGenerator(string& password) {
    const char input[] = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        " "
        "0123456789"
        "!@#$%^&*()_+=-{}:|?><.,/;'[]~`"
        "\\";
    int inputsize = sizeof(input) - 1;

    password = "";
    srand(time(0));

    for (int i = 0; i < 12; i++) {
        password += input[rand() % inputsize];
    }

    cout << "Your Password: " << password << endl;

}


void yourPassword(string& password, int length, string input, int charlength) {



    password = "";
    srand(time(0));

    for (int i = 0; i < length; i++) {
        password += input[rand() % charlength];
    }
    cout << "Your Password: " << password << endl;
}


bool isPasswordEmpty(string password) {

    int length = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        length++;
    }
    for (int i = 0; i < length; i++) {
        return false;
    }
    return true;
}

void removespace(string& phone) {
    for (int i = 0; phone[i] != '\0'; i++) {
        if (phone[i] == ' ') {
            for (int j = i; phone[j] != '\0'; j++) {
                phone[j] = phone[j + 1];
            }
            i--;
        }

    }
}

bool isphoneEmpty(string phone) {
    int length = 0;

    for (int i = 0; phone[i] != '\0'; i++) {
        length++;
    }
    for (int i = 0; i < length; i++) {
        return false;
        //Not empty because loop runs one time.
    }
    return true; //yes it is empty
}

bool isphonevalid(string phone) {
    for (int i = 0; phone[i] != '\0'; i++) {
        if (phone[i] > '9' || phone[i] < '0') {
            return false;
        }
    }

    //Finding length of phone number using for loop
    int length = 0;
    for (int i = 0; phone[i] != '\0'; i++) {
        length++;
    }
    if (length != 11) {
        return false;
    }

    return true;
}

void cleancnic(string& cnic) {

    for (int i = 0; cnic[i] != '\0'; i++) {
        if (cnic[i] == ' ' || cnic[i] == '-') {
            for (int j = i; cnic[j] != '\0'; j++) {
                cnic[j] = cnic[j + 1];
            }
            i--;
        }
    }
}

bool iscnicEmpty(string cnic) {
    int length = 0;

    for (int i = 0; cnic[i] != '\0'; i++) {
        length++;
    }
    for (int i = 0; i < length; i++) {
        return false;
    }
    return true; 
}

bool iscnicvalid(string cnic) {

    for (int i = 0; cnic[i] != '\0'; i++) {
        if (cnic[i] > '9' || cnic[i] < '0') {
            return false;
        }
    }

    //Finding length of cnic number using for loop
    int length = 0;
    for (int i = 0; cnic[i] != '\0'; i++) {
        length++;
    }
    if (length != 13) {
        return false;
    }


    return true;
}

void passwordStrength(string& password) {                                                   
    int totallength = 0;
    int uppercaseLength = 0;
    int lowercaseLength = 0;
    int noOfSpecialCharacters = 0;
    int noOfDigits = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        totallength++;

        if (password[i] >= 65 && password[i] <= 90) {
            uppercaseLength++;
        }
        else if (password[i] >= 97 && password[i] <= 122) {
            lowercaseLength++;
        }
        else if (password[i] >= 48 && password[i] <= 57) {
            noOfDigits++;
        }
        else {
            noOfSpecialCharacters++;
        }

    }


    if (totallength <= 6) {
        cout << "Weak.";
    }

    else if (noOfDigits <= 10 && totallength == noOfDigits) {
        cout << "Weak.";
    }

    else if (totallength <= 10 && totallength == lowercaseLength) {
        cout << "Weak.";
    }
    else if (totallength <= 10 && totallength == uppercaseLength) {
        cout << "Weak";
    }
    //Medium
    else if (totallength <= 10) {
        cout << "Medium.";
    }
    else if (totallength>10 && lowercaseLength>0 && uppercaseLength>0 && noOfDigits>0) {
        cout << "Strong.";
    }
    else {
        cout << "Medium.";
    }



}



void crackTime(string& password) {
    int totallength = 0;
    int uppercaseLength = 0;
    int lowercaseLength = 0;
    int noOfSpecialCharacters = 0;
    int noOfDigits = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        totallength++;

        if (password[i] >= 65 && password[i] <= 90) {
            uppercaseLength++;
        }
        else if (password[i] >= 97 && password[i] <= 122) {
            lowercaseLength++;
        }
        else if (password[i] >= 48 && password[i] <= 57) {
            noOfDigits++;
        }
        else {
            noOfSpecialCharacters++;
        }

    }
    int charSetSize = 0;

    if (lowercaseLength > 0) charSetSize += 26;

    if (uppercaseLength > 0) charSetSize += 26;

    if (noOfDigits > 0) charSetSize += 10;

    if (noOfSpecialCharacters > 0) charSetSize += 32;

    long double totalcombinations = pow(charSetSize, totallength);
    long double crackingtimeInSeconds = totalcombinations / 1e11;


    if (crackingtimeInSeconds < 1) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds * 1000 << " milli seconds.";
    }
    else if (crackingtimeInSeconds < 60) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds << " seconds.";
    }
    else if (crackingtimeInSeconds < 3600) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds / 60 << " minutes.";
    }
    else if (crackingtimeInSeconds < 86400) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds / 3600 << " hours.";
    }
    else if (crackingtimeInSeconds < 2592000) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds / 86400 << " days.";
    }
    else if (crackingtimeInSeconds < 31104000) {
        cout << "Password can be cracked in : " << crackingtimeInSeconds / 2592000 << " months.";
    }
    else {
        cout << "Password can be cracked in : " << crackingtimeInSeconds / 31104000 << " years.";
    }
    cout << endl;
}

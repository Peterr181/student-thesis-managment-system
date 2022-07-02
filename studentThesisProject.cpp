#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <windows.h>
#include <string.h>
#include <algorithm>

using namespace std;

void menu();

class ManageMenu
{
protected:
    string userName; // hide admin name
    string password;

public:
    // virtual void menu(){}

    ManageMenu()
    {
        system("color 0A"); // change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        Sleep(100);
        cout << "\n\n\n\n\n\n\n\n\n\n\t  Enter Your Admin Password: ";
        cin >> password;

        system("CLS");

        menu(); // call to main function to load after executing the constructr
    }

    ~ManageMenu() {} // de
};

class Work
{

public:
    struct data
    {
        int id;
        char worktypee[5];
        char title[50];
        char authorsLastName[40];
        char authorsFirstName[50];
        int year;
        char promoterLastName[30];
        char promoterFirstName[40];
        char keyWords[50];
        char summary[1000];
    };

    data data1;

    Work()
    {
    }

    Work(data data)
    {
        data1 = data;
    }

    void show_shortData()
    {

        ifstream binaryFcounting_TypeWork;

        int size = 0;

        binaryFcounting_TypeWork.open("data.dat", ios::in | ios::binary);
        binaryFcounting_TypeWork.seekg(0, ios::end);
        size = (int)binaryFcounting_TypeWork.tellg();
        binaryFcounting_TypeWork.seekg(0, ios::beg);

        while(binaryFcounting_TypeWork.tellg() < size)
        {

            binaryFcounting_TypeWork.read((char *)&data1, sizeof(data));

            // 123 mgr A. Nowak ,,Algorytmy genetyczne w problemie TSP’’ 2008
            char znak;
            znak = toupper(data1.authorsFirstName[0]);

            cout << data1.id << " " << data1.worktypee
 << " " << znak << "."
                 << " "
                 << ",," << data1.title << "''"
                 << " " << data1.year << endl;
        }

        binaryFcounting_TypeWork.close();
    }

    void show_fullData()
    {

        ifstream binaryFcounting_TypeWork;

        int size = 0;

        binaryFcounting_TypeWork.open("data.dat", ios::in | ios::binary);
        binaryFcounting_TypeWork.seekg(0, ios::end);
        size = (int)binaryFcounting_TypeWork.tellg();
        binaryFcounting_TypeWork.seekg(0, ios::beg);

        while(binaryFcounting_TypeWork.tellg() < size)
        {

            binaryFcounting_TypeWork.read((char *)&data1, sizeof(data));

            cout << "---------------------------------------------------------------";

            cout << "\nID: " << data1.id << "\ntype: " << data1.worktypee
 << "\nAuthor: " << data1.authorsFirstName << " " << data1.authorsLastName << "\ntitle: " << data1.title << "\nKey words: " << data1.keyWords << "\nyear: " << data1.year << "\nPromotor: " << data1.promoterFirstName << " " << data1.promoterLastName << "\nsummary: " << data1.summary << "\n";

            cout << "---------------------------------------------------------------";
        }

        binaryFcounting_TypeWork.close();
    }
};

class Library : public Work
{

public:
    Work tab[1000]{};
    unsigned int Works;

    Library()
    {

        Works = 0;

        ifstream binaryFcounting_TypeWork;

        int size = 0;

        binaryFcounting_TypeWork.open("data.dat", ios::in | ios::binary);
        binaryFcounting_TypeWork.seekg(0, ios::end);
        size = (int)binaryFcounting_TypeWork.tellg();
        binaryFcounting_TypeWork.seekg(0, ios::beg);

        while(binaryFcounting_TypeWork.tellg() < size)
        {

            binaryFcounting_TypeWork.read((char *)&tab[Works].data1, sizeof(data));
            Works++;
        }
    }

    void get_data()
    {

        ofstream fcounting_TypeWork;

        fcounting_TypeWork.open("data.dat", ios::out | ios::binary | ios::app);
        cout << "Enter student's ID ";
        cin >> data1.id;
        cout << "Enter typee of work (inz,mgr,lic): ";
        while(true)
        {

            cin >> data1.worktypee
;

            if (strcmp(data1.worktypee, "lic") == 0)
            {

                break;
            }
            else if (strcmp(data1.worktypee, "mgr") == 0)
            {
                break;
            }
            else if (strcmp(data1.worktypee, "inz") == 0)
            {
                break;
            }
            else
            {
                cout << "Enter correct input (inz,mgr,lic): ";
            }
        }

        cin.ignore();
        cout << "Enter work title ";

        while(true)
        {

            cin.getline(data1.title, 50);

            if (strlen(data1.title) == 0)
            {
                cout << "Title can not be empty!";
            }
            else
            {
                break;
            }
        }

        cout << "Enter author's last name ";
        while(true)
        {

            cin.getline(data1.authorsLastName, 40);

            if (strlen(data1.authorsLastName) == 0)
            {
                cout << "Enter last name: ";
            }
            else
            {
                break;
            }
        }

        cout << "Enter authors first name ";
        cin.getline(data1.authorsFirstName, 50);

        cout << "Enter year ";
        while (true)
        {
            cin >> data1.year;
            if (data1.year > 2000)
            {

                break;
            }
            else
            {
                cout << "Enter year 2000 or higher:  ";
            }
        }

        cout << "Enter promoter last name: ";
        cin >> data1.promoterLastName;
        cin.ignore();
        cout << "Enter promoter first name ";

        cin.getline(data1.promoterFirstName, 40);

        cout << "Enter key words: ";
        cin.getline(data1.keyWords, 50);

        cout << "Enter work summary: ";
        cin.getline(data1.summary, 1000);

        if (fcounting_TypeWork.is_open())
        {

            fcounting_TypeWork.write((const char *)&data1, sizeof(data));

            fcounting_TypeWork.close();
        }
        Work dataa(data1);

        tab[Works] = dataa;
        Works++;

        // cout <<"\nID studenta: " << id <<"\ntype pracy studenta: " << worktypee <<"\ntitle pracy studenta: " << title <<"\nNazwisko Authora: " << authorsLastName <<"\nname Authora: " << authorsFirstName <<"\nyear wydania: " << year;
        cout << endl;
    }

    void edytuj()
    {

        ofstream fcounting_TypeWork;
        fcounting_TypeWork.open("data.dat", ios::out | ios::binary);
        int id_new;
        char type[5];
        char name[30];
        int target;
        int main_target;
        int id;
        int loc;
        char new_lastName[30];
        char new_keyWords[50];
        char new_promoterName[50];
        char new_promoterLastName[40];
        char newSummary[1000];
        char newTitle[50];
        int newYear;
        bool wID = false;

        cout << "\nEdit ID ---> 1";
        cout << "\nEdit typeWork ---> 2";
        cout << "\nEdit nameAuthor ---> 3";
        cout << "\nEdit lastNameAuthor  ---> 4";
        cout << "\nEdit keyWords ---> 5";
        cout << "\nEdit year ---> 6";
        cout << "\nEdit promoter name ---> 7";
        cout << "\nEdit promoter last name ---> 8";
        cout << "\nEdit summary ---> 9";
        cout << "\nEdit title ---> 10" << endl;

         cout <<"----------------------------------------------------------" << endl;

        cout << "\nEnter work ID: ";
        cin >> id;
        
       cout <<"----------------------------------------------------------" << endl;

        cout << "\n\n";

        for (int i = 0; i < Works; i++)
        {

            if (id == tab[i].data1.id)
            {

                cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
     << "\nAuthor: " << tab[i].data1.authorsFirstName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                break;
            }
            else
            {
                cout << "ID not found" << endl;
            }
        }

        for (int i = 0; i < Works; i++)
        {

            if (id == tab[i].data1.id)
            {
                cout << "\nEnter option's from 1-10 ";
                cin >> main_target;
                break;
            }
        }

        for (int i = 0; i < Works; i++)
        {

            if (main_target == 1)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new ID ";
                    cin >> id_new;

                    tab[i].data1.id = id_new;
                    break;
                }
            }

            else if (main_target == 2)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new work type: ";
                    cin >> type;

                    strcpy(tab[i].data1.worktypee, type);

                    break;
                }
            }
            else if (main_target == 3)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new author's first name: ";
                    cin >> name;

                    strcpy(tab[i].data1.authorsFirstName, name);
                    break;
                }
            }
            else if (main_target == 4)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new author's last name: ";
                    cin >> new_lastName;

                    strcpy(tab[i].data1.authorsLastName, new_lastName);
                    break;
                }
            }
            else if (main_target == 5)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new key words: ";
                    cin >> new_keyWords;

                    strcpy(tab[i].data1.keyWords, new_keyWords);
                    break;
                }
            }
            else if (main_target == 6)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new year: ";
                    cin >> newYear;

                    tab[i].data1.year = newYear;
                    break;
                }
            }
            else if (main_target == 7)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new promoter name ";
                    cin >> new_promoterName;
                    strcpy(tab[i].data1.promoterFirstName, new_promoterName);
                    break;
                }
            }
            else if (main_target == 8)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new promoter last name ";
                    cin >> new_promoterLastName;

                    strcpy(tab[i].data1.promoterLastName, new_promoterLastName);
                    break;
                }
            }
            else if (main_target == 9)
            {

                if (id == tab[i].data1.id)
                {

                    cin.ignore();
                    cout << "Enter new summary ";
                    gets(newSummary);

                    strcpy(tab[i].data1.summary, newSummary);
                    break;
                }
            }
            else if (main_target == 10)
            {

                if (id == tab[i].data1.id)
                {

                    cout << "Enter new work title";
                    cin >> newTitle;

                    strcpy(tab[i].data1.title, newTitle);
                    break;
                }
            }
        }

        if (fcounting_TypeWork.is_open())
        {

            for (int i = 0; i < Works; i++)
            {

                fcounting_TypeWork.write((const char *)&tab[i].data1, sizeof(data));
            }

            fcounting_TypeWork.close();
        }
    }

    char *tolow(char inp[])
    {
        char *ret = new char[strlen(inp)];
        for (int i = 0; i < strlen(inp); i++)
        {
            ret[i] = tolower(inp[i]);
        }

        return ret;
    }

    void search()
    {

        char authorsLastNameSzukaj[40];
        char promoterLastNameSzukaj[40];
        char titleSzukaj[40];
        char keyWordsSzukaj[100];
        char summarySzukaj[500];
        int yearPowstania;
        int option;

        cout << "\nSearch author's last name ---> 1";
        cout << "\nSearch promoter last name ---> 2";
        cout << "\nSearch title ---> 3";
        cout << "\nSearch key words  ---> 4";
        cout << "\nSearch summary ---> 5";
        cout << "\nSearch year ---> 6";

        cout << "\nEnter option depends on what you want to find in work: ";
        cin >> option;

        if (option == 1)
        {
            cout << "Enter author's last name to find:";
            cin >> authorsLastNameSzukaj;
            for (int i = 0; i < Works; i++)
            {
                if (strcmp(tolow(tab[i].data1.authorsLastName), tolow(authorsLastNameSzukaj)) == 0)
                {
                    cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
         << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                }
                else
                {
                    bool brejk = false;
                    int temp12 = 0;
                    for (int j = 0; j < strlen(tab[i].data1.authorsLastName); j++)
                    {
                        for (int k = temp12; k < strlen(authorsLastNameSzukaj); k++)
                        {
                            if (tolower(authorsLastNameSzukaj[k]) == tolower(tab[i].data1.authorsLastName[j]))
                            {
                                if (k == strlen(authorsLastNameSzukaj)-1)
                                {
                                    cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                         << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                                    brejk = true;
                                    break;
                                }
                                temp12 = k+1;
                            } else if (temp12 != 0) {
                                temp12 = 0;
                            }
                        }
                        if(brejk) {
                            break;
                        }
                    }
                }
            }
        }

        else if (option == 6)
        {
            cout << "Enter year to find: ";
            cin >> yearPowstania;

            for (int i = 0; i < Works; i++)
            {

                if (yearPowstania == tab[i].data1.year)
                {

                    cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
         << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                }
            }
        }
        else if (option == 2)
        {
            cout << "Enter promoter last name to find: ";
            cin >> promoterLastNameSzukaj;

            for (int i = 0; i < Works; i++)
            {
                for (int j = 0; j < strlen(tab[i].data1.promoterLastName); j++)
                {
                    for (int k = 0; k < strlen(promoterLastNameSzukaj); k++)
                    {
                        if (tolower(promoterLastNameSzukaj[k]) == tolower(tab[i].data1.promoterLastName[j]))
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                        }
                        else if (k == strlen(promoterLastNameSzukaj) - 1)
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                        }
                        break;
                    }
                }
            }
        }
        else if (option == 3)
        {
            cin.ignore();
            cout << "Enter title to find: ";
            cin >> titleSzukaj;
            for (int i = 0; i < Works; i++)
            {
                for (int j = 0; j < strlen(tab[i].data1.title); j++)
                {
                    for (int k = 0; k < strlen(titleSzukaj); k++)
                    {
                        if (tolower(titleSzukaj[k]) == tolower(tab[i].data1.title[j]))
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                        }

                        //             else if(k == strlen(titleSzukaj)-1){
                        // cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
             
                        //
                        //                       }
                        //                       break;
                    }
                }
            }
        }
        else if (option == 4)
        {
            cout << "Enter key word to find: ";
            cin >> keyWordsSzukaj;
            for (int i = 0; i < Works; i++)
            {
                for (int j = 0; j < strlen(tab[i].data1.keyWords); j++)
                {
                    for (int k = 0; k < strlen(keyWordsSzukaj); k++)
                    {
                        if (tolower(keyWordsSzukaj[k]) == tolower(tab[i].data1.keyWords[j]))
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                            break;
                        }
                        else if (k == strlen(keyWordsSzukaj) - 1)
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                        }
                        break;
                    }
                }
            }
        }

        else if (option == 5)
        {
            cin.ignore();
            cout << "Enter summary to find: ";
            gets(summarySzukaj);

            for (int i = 0; i < Works; i++)
            {
                for (int j = 0; j < strlen(tab[i].data1.summary); j++)
                {
                    for (int k = 0; k < strlen(summarySzukaj); k++)
                    {
                        if (tolower(summarySzukaj[k]) == tolower(tab[i].data1.summary[j]))
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                            break;
                        }
                        else if (k == strlen(summarySzukaj) - 1)
                        {
                            cout << "\nID: " << tab[i].data1.id << "\ntype: " << tab[i].data1.worktypee
                 << "\nAuthor: " << tab[i].data1.authorsFirstName << " " << tab[i].data1.authorsLastName << "\ntitle: " << tab[i].data1.title << "\nKey words: " << tab[i].data1.keyWords << "\nyear: " << tab[i].data1.year << "\nPromotor: " << tab[i].data1.promoterFirstName << " " << tab[i].data1.promoterLastName << "\nsummary: " << tab[i].data1.summary << "\n";
                        }
                        break;
                    }
                }
            }
        }
    }

    void counting_TypeWork()
    {

        int counterLic = 0;
        int counterMgr = 0;
        int counterInz = 0;

        for (int i = 0; i < Works; i++)
        {

            if (strcmp(tab[i].data1.worktypee, "lic") == 0)
            {

                counterLic++;
            }
            if (strcmp(tab[i].data1.worktypee, "mgr") == 0)
            {

                counterMgr++;
            }
            if (strcmp(tab[i].data1.worktypee, "inz") == 0)
            {

                counterInz++;
            }
        }

        cout << "Number of works with MGR title is: " << counterMgr << endl;
        cout << "Number of works with LIC title is: " << counterLic << endl;
        cout << "Number of works with INZ title is: " << counterInz << endl;
    }

    void repeating_keyWords()
    {

        bool check;
        vector<string> words;
        vector<int> count;

        for (int i = 0; i < Works; i++)
        {

            check = false;
            for (int j = 0; j < words.size(); j++)
            {
                char temp[words[j].length()];
                strcpy(temp, words[j].c_str());

                if (strcmp(tab[i].data1.keyWords, temp) == 0)
                {
                    check = true;
                    count[j]++;
                }
            }
            if (!check)
            {
                words.push_back(tab[i].data1.keyWords);
                count.push_back(1);
            }
        }
        sort(count.begin(), count.end(), greater<>());
        ;
        for (int j = 0; j < words.size(); j++)
        {

            cout << "Key word: " << words[j] << " shows this times:  " << count[j] << endl;
        }
    }

    void countPromoter_works()
    {

        int counter = 0;
        vector<pair<string, int>> vec;
        vector<string> nazw;
        vector<int> count;
        bool check;
        //
        //    nazw.push_back(tab[0].data1.promoterLastName);
        //    count.push_back(1);

        for (int i = 0; i < Works; i++)
        {
            check = false;
            for (int j = 0; j < nazw.size(); j++)
            {
                char temp[nazw[j].length()];
                strcpy(temp, nazw[j].c_str());

                if (strcmp(tab[i].data1.promoterLastName, temp) == 0)
                {
                    check = true;
                    count[j]++;
                }
            }

            if (!check)
            {
                nazw.push_back(tab[i].data1.promoterLastName);
                count.push_back(1);
            }
        }

        for (int j = 0; j < nazw.size(); j++)
        {

            cout << "Promoter: " << nazw[j] << " holding " << count[j] << " works" << endl;
        }
    }
};

void menu()
{

    int mainChoice;
    int inChoice;
    int gotoMenu;

    Library b1;
    Work p2;

    do
    {

        cout << "\t\t  The management system for student theses \n"
             << endl;
        cout << "-------------------------Main Menu--------------------------" << endl;
        cout << "Displaying the job list in a shortened format->1" << endl;
        cout << "Displaying the job list in a full format-> 2" << endl;
        cout << "Adding works to library-> 3" << endl;
        cout << "Edit data about work-> 4" << endl;
        cout << "Find work depend on option:-> 5" << endl;
        cout << "Additional functions -> 6" << endl;
        cout << "EXIT:-> 7" << endl;

        cout << "\nEnter Choice: ";
        cin >> mainChoice;

        if (mainChoice == 3)
        {

            b1.get_data();
        }
        else if (mainChoice == 1)
        {

            p2.show_shortData();
        }
        else if (mainChoice == 2)
        {

            p2.show_fullData();
        }
        else if (mainChoice == 4)
        {
            b1.edytuj();
        }
        else if (mainChoice == 5)
        {

            b1.search();
        }
        else if (mainChoice == 6)
        {

            int wyboor;
            cout << "Additional functions for student thesis program";
            cout << "\n1 <--- The function shows counting_TypeWork is working with division into individual types";
            cout << "\n2 <--- Displaying promoters and the amount of work for everyone";
            cout << "\n3 <--- Top 10 most repeating key words";

            cout << "\nEnter option between 1-3: ";
            cin >> wyboor;

            if (wyboor == 1)
            {
                b1.counting_TypeWork();
            }
            else if (wyboor == 2)
            {
                b1.countPromoter_works();
            }
            else if (wyboor == 3)
            {

                b1.repeating_keyWords();
            }
        }
        else if (mainChoice == 7)
        {

            cout << "\n\n\t--GOOD-BYE!--" << endl;
            Sleep(1100);
            system("CLS");
            break;
        }

        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");

    } while (gotoMenu == 1);
    system("CLS");
}

int main()
{

    // pr1.show_shortData();
    ManageMenu mn1;

    return 0;
}

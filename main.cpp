#include <utility>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <chrono>

#include "src/Message.h" 
#include "src/ChatTree.h" 

using namespace std;

int a2() {
    std::tm tm = {};
    std::istringstream ss("Jan 9 2014 12:35:34");
    ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
    // auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    // cout << &tp;
    if (ss.fail()) {
        std::cout << "Parse failed\n";
    } else {
        std::cout << "date" << std::put_time(&tm, "%c") << '\n';
    }


    // std::tm t = {};
    // std::stringstream ss("Jan 9 2014 12:35:34");
    // // ss.imbue(std::locale("de_DE.utf-8"));
    // ss >> std::get_time(&t, "%b %d %Y %H:%M:%S");
    // if (ss.fail()) {
    //     std::cout << "Parse failed\n";
    // } else {
    //     std::cout << "date" << std::put_time(&t, "%c") << '\n';
    // }

}

int maisdsdn()
{
    std::tm t = {};
    std::istringstream ss3("08-Oct-17 12:53 PM");
    //std::istringstream ss3("2011-Jan-18 23:12:34");
    ss3 >> std::get_time(&t, "%d-%b-%y %H:%M %P");
    // if (ss3.fail()) {
    //     std::cout << "Parse failed\n";
    // } else {
        std::cout << "date" << std::put_time(&t, "%p") << '\n';
    // }
    // cout << t.tm_min << endl;
    

    ///////////////////
    time_t now;
    struct tm newyear;
    double seconds;

    time(&now);  /* get current time; same as: now = time(NULL)  */

    std::tm t1 = {},t2 = {};
    // std::istringstream ss("2011-Jan-18 23:12:34");
    std::istringstream ss("08-Oct-17 12:50 PM"); //09-Apr-17 06:23 PM
    std::istringstream ss2("08-Oct-17 12:53 PM"); //09-Apr-17 06:23 PM
    ss >> std::get_time(&t1, "%d-%b-%y %H:%M %p");
    ss2 >> std::get_time(&t2, "%d-%b-%y %H:%M %p");

    seconds = difftime(mktime(&t2),mktime(&t1));

    printf ("%.f seconds since new year in the current timezone.\n", seconds);

    // std::istringstream ss(dateString); //09-Apr-17 06:23 PM
    std::tm tttt = {};
    std::istringstream ssss("08-Oct-17 12:53 PM"); //09-Apr-17 06:23 PM
    ssss >> std::get_time(&tttt, "%d-%b-%y %H:%M %p");

    if (ssss.fail()) {
        cout << "error parsing date: |" << "09-Apr-17 06:23 PM" << '|' <<  endl ;
        throw exception();
    } else {
        // cout << "date" << std::put_time(&t, "%Y") << '\n';
        // this->date = t;
    }
}

int main(){
    string str = "./data/Pharo - ai.csv";
    ifstream fe;
    fe.open(str.c_str());
    string line;
    vector<Message*> msgs;
    getline(fe, line); // remove header
    while(getline(fe, line)) {
        // cout << line << endl;
        // Message *m = ;
        msgs.push_back(new Message(line));
    }

    ChatTree *tree = new ChatTree();
    tree->insert(&msgs, 0, msgs.size()-1, 0);
}
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <chrono>
#include <stdlib.h>

using namespace std;
class Message {
    public: 
        string content, user, datestring;
        string attachement;
        std::tm date = {};

        Message(string u,string d,string c, string a) {
            content = c;
            user =u;
            attachement = a;
            this->parseDate(d);
        }

        Message(string line) {
            istringstream iss(line);
            string dstring;
            getline(iss, user, ';');
            getline(iss, dstring, ';');
            getline(iss, content, ';');
            getline(iss, attachement, ';');

            this->parseDate(dstring);
        }

        int timediff(Message *m){
            return (int) difftime(mktime(&date), mktime(&(m->date)));
        }

    private:
        void parseDate(string dString) {
            std::tm t = {};
            // std::istringstream ss("2011-Jan-18 23:12:34");
            // std::istringstream ss(dateString); //09-Apr-17 06:23 PM
            std::istringstream ss(dString); //09-Apr-17 06:23 PM
            ss >> std::get_time(&t, "%d-%b-%y %H:%M %P");

            // if (ss.fail()) {
            //     cout << "error parsing date: |" << dateString << '|' <<  endl ;
            //     throw exception();
            // } else {
                // cout << "date" << std::put_time(&t, "%Y") << '\n';
                this->date = t;
            // }
        }

};
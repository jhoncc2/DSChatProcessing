#include <vector>
#include <array>
#include <math.h>

// #include "Message.h"
using namespace std;

class ChatTree {

    private:
        static const int SEC_LIMIT = 60;
        int start, end;

    public: 
        static const int RATE = 86400; // 24 * 60 * 60
        vector<ChatTree*> trees;

        ChatTree() {
        }

        void insert(vector<Message*> *chat, int istart, int iend, int r) {
            int localratesec = (int) (RATE / pow(2,r));
            start = istart;
            end = iend;

            cout << localratesec << ';'<< start << '-' << end << endl;

            if (localratesec < SEC_LIMIT)
                return;

            if (end - start == 1) 
                return;

            Message *last =  (*chat)[start];
            int diffsec;
            int localini = start, localend = start;

            for (int i=start+1; i<=end; i++) {
                diffsec = last->timediff((*chat)[i]);
                if (diffsec < localratesec) {
                    localend++;
                } else {
                    ChatTree *t = new ChatTree();
                    t->insert(chat, localini, localend, r + 1);
                    localend ++;
                    localini = localend;
                }
                last = (*chat)[i];
            }

            ChatTree *t = new ChatTree();
            t->insert(chat, localini, localend, r + 1);
        }

        void print() {
            for(int i=0; i < trees.size(); i++) {
                // if ( trees[i] != NULL)
                    // cout << i << '-' << (trees[i])->getValue() << ',';
            }
            cout << endl;
        }

    private: 
        
};

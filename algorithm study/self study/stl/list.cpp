#include<iostream>
#include<list>

using namespace std;
bool predicate(int num) {
    return num >= 100 && num <= 200;
}

int main(void) {
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(108);
    lt.push_back(60);
    lt.push_back(10);
    lt.push_back(100);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(10);
    lt.push_back(109);

    list<int>::iterator it;
    cout << "origin" << endl;
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl << endl;

    // remove_if(predicate)
    cout << "remove_if (100~200)" << endl;
    lt.remove_if(predicate);
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl << endl;

    cout << "remove (10)" << endl;
    lt.remove(10);
    for(it = lt.begin(); it != lt.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl << endl;

    // splice
    list<string> lstr1;
    list<string> lstr2;

    lstr1.push_back("a");
    lstr1.push_back("b");
    lstr1.push_back("c");
    lstr1.push_back("d");
    lstr1.push_back("e");

    lstr2.push_back("X");
    lstr2.push_back("Y");
    lstr2.push_back("Z");

    list<string>::iterator iter;
    
    cout << "[lstr1] Origin : ";
    for (iter = lstr1.begin(); iter != lstr1.end(); ++iter) {
        cout << *iter << ' ';
    } 
    cout << endl;
    cout << "[lstr2] Origin : ";
    for (iter = lstr2.begin(); iter != lstr2.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl << endl << endl;

    iter = lstr2.begin();
    iter++; // lstr2의 두번째 원소를 가리킨다.

    lstr2.splice(iter, lstr1);
    cout << "[lstr1] Splice : ";
    for (iter = lstr1.begin(); iter != lstr1.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "lstr1.size( ) : " << lstr1.size() << endl;
    cout << endl << endl;

    cout << "[lstr2] Splice : ";
    for (iter = lstr2.begin(); iter != lstr2.end(); ++iter) {
        cout << *iter << " ";
    } 
    cout << endl;

    cout << "lstr2.size( ) : " << lstr2.size() << endl;
    cout << endl << endl;
}
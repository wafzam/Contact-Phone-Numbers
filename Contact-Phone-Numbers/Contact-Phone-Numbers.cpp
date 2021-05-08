
// Contact-Phone-Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include<fstream>
#include<set>
#include<iomanip>
using namespace std;
template<class T1, class T2> void showMultiMap(multimap<T1, T2> m) {
    cout << "\nContacts - Phones\n";
    for (auto row : m)
    {
        
        cout << setw(20) << left<< row.first << setw(10) << right << row.second << endl;
    }
}
template<class T>void showSet(set<T> s)
{
    cout << "Contacts - People" << endl;
        for (string l : s) 
            cout << " " << l << endl;
    
       
}
template<class T1, class T2> void showMap(map<T1, T2> m) {
    cout << "\nMap\n";
    for (auto row : m)
    {

        cout << row.first << "\t" << row.second << endl;
    }
}
int main()
{
    
    string fullName,number;
    string phoneNum, Name;
    ifstream infile("c:/temp/Contacts1.txt");
    set<string> contactName;
    multimap<string, string> Phonelist;
    map<string, string> numberName;
    while (getline(infile, Name), getline(infile, phoneNum))
    {
       
        Phonelist.insert(make_pair(Name, phoneNum));
        contactName.insert(Name);
        numberName.insert(make_pair(phoneNum, Name));
    }
    showSet(contactName);
    showMultiMap(Phonelist);
    
    cout << "Searching by Name -------------------------------------" << endl;
    do
    {
     
          cout << "Enter contact's name [xxx to end]:  ";
          getline(cin, fullName);
          double count=0;
          if (fullName == "xxx")
              break;
          auto it = Phonelist.begin() ;
          try
          {
              
              
              while (it != Phonelist.end())
              {

                  if (fullName == it->first)
                  {
                      cout << it->second << endl;
                      count++;
                  }
                  it++;
                  
              }
              
              
                  if (count == 0) {
                      throw(exception)"Sorry - Name not found :(";
                  }
                  
             
              
          }

    
          catch (const std::exception& msg)
          {
              cout << msg.what() << endl;
          }
    } while (fullName != "xxx");
    cout << endl;
    cout << "Searching by Phone Number---------------------------- -" << endl;
    do
    {
        cout << "Enter Phone number [xxx to end]: ";
        getline(cin, number);
        if (number == "xxx")
        {
            break;
        }
        double count2=0;
        auto it = numberName.begin();
        try
        {
            while (it != numberName.end())
            {
                if (number == it->first)
                {
                    cout << it->second << endl;
                    count2++;
                }
                it++;

            }
            if (count2 == 0) {
                throw(exception)"Sorry - Number was not found :{";
            }
        }
        catch (const std::exception& e)
        {
            cout << e.what() << endl;
       }
    } while (number != "xxx");
    cout << "All Done!";
    
  
}



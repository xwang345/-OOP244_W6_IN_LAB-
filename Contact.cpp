/*Student Name: Xiaochen Wang
//Student ID: 015297153
//
//W6_in_lab */
#include <iostream>
#include "Contact.h"

using namespace std;

namespace sict {
    Contact::Contact() {
        m_name[0] = '\0';
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;
    }

    bool Contact::isEmpty() const {
        bool ret = true;
        if (m_name[0] != '\0') {
            ret = false;
        }else if(m_phoneNumbers != nullptr){
            ret = false;
        }

        return ret;
    }

    Contact::~Contact() {
        delete[] m_phoneNumbers;
        m_phoneNumbers = nullptr;
    }

    Contact::Contact(const char *Name, long long* PhoneNum, int Num_of_Phone) {
        if (NULL != Name) {
            if (isEmpty()) {
                strcpy(m_name, Name);
                m_noOfPhoneNumbers = Num_of_Phone;

                //TODO allocate dynamic memory
                if (m_noOfPhoneNumbers > 0) {
                    long long *p = new long long[m_noOfPhoneNumbers];
                    for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                        p[i] = PhoneNum[i];
                    }
                    m_phoneNumbers = p;
                }else{
                    m_phoneNumbers = nullptr;
                }
            } else {
                for (int i = 0; i < 21; i++) {
                    m_name[i] = '\0';
                }
                m_phoneNumbers = nullptr;
                m_noOfPhoneNumbers = 0;
            }
        } else{
            for (int i = 0; i < 21; i++) {
                m_name[i] = '\0';
            }
            m_phoneNumbers = nullptr;
            m_noOfPhoneNumbers = 0;
        }
    }



    void Contact::display() const{
        if (isEmpty()) {
            cout << "Empty contact!" << endl;
        }else{
            cout << m_name << endl;
            for(int i = 0; i < m_noOfPhoneNumbers; i++){
                long long a = m_phoneNumbers[i];
                long long real_Phonenumbers;
                int last_PN;
                int b= 10000000;
                int c = int(a/b);
                int d, e;
                int temp;
                if(c>1001 && c<99999){
                    e = c % 1000;
                    d = c / 1000;
                    real_Phonenumbers = a % 1000000;
                    temp = a / 10000;
                    int first_PN = temp %1000;
                    last_PN = (int) (real_Phonenumbers % 10000);
                    cout << "(+" << d << ")" << " " << e << " " << first_PN
                         << "-" << last_PN << endl;
                }
            }
        }
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
class Skup {
    private:
        vector<T> s;
    public:
        Skup() {}
        ~Skup() { s.clear(); }
        int size() { return s.size(); }
        void push_back(T x) { s.push_back(x); }

        void ucitajElemente(T arr[], size_t arrSize) {
            for (int i = 0; i < arrSize; i++) {
                s.push_back(arr[i]);
            }
        }

        void prikazi() {
            for (int i = 0; i < s.size(); i++) {
                cout << s[i] << " "; 
            }
        }

        void unija(Skup<T> s1, Skup<T> s2) {
            Skup <T> u;
            vector<bool> v;

            // vektor koji odredjuje koje cemo uzet elemente iz s2
            for (int i = 0; i < s2.size(); i++) {
                v.push_back(false);
            }

            for (int i = 0; i < s1.size(); i++) {
                u.push_back(s1.s[i]);
            }
            
            // flaggamo elemente iz s2
            for (int i = 0; i < s2.size(); i++) {
                for (int j = 0; j < s1.size(); j++) {
                    if (s2.s[i] == u.s[j]) {
                        v[i] = true;
                    } 
                }
            }

            for (int i = 0; i < v.size(); i++) {
                if (v[i] == false) {
                    u.push_back(s2.s[i]);
                }
            }
            u.prikazi();
        }

        void presjek(Skup <T> s1, Skup <T> s2) {
            Skup <T> p;
            vector<T> copy;

            // skupimo sve elemente u jedan skup, sortiramo i trazimo dva ista uzastopna elementa
            for (int i = 0; i < s1.size(); i++) {
                copy.push_back(s1.s[i]);
            }
            for (int i = 0; i < s2.size(); i++) {
                copy.push_back(s2.s[i]);
            }
            sort(copy.begin(), copy.end());

            for (int i = 0; i < copy.size(); i++) {
                if (copy[i] == copy[i+1]) {
                    p.push_back(copy[i]);
                }
            }
            p.prikazi();
        }

        void razlika(Skup <T> s1, Skup <T> s2) {
            Skup <T> r;
            vector<T> copy;

            for (int i = 0; i < s1.size(); i++) {
                copy.push_back(s1.s[i]);
            }
            for (int i = 0; i < s2.size(); i++) {
                copy.push_back(s2.s[i]);
            }
            sort(copy.begin(), copy.end());

            for (int i = 0; i < copy.size(); i++) {
                if (copy[i] != copy[i+1] && copy[i] != copy[i-1]) {
                    r.push_back(copy[i]);
                }
            }
            r.prikazi();
        }
};      


int main() {
    Skup <int> s1;
    Skup <int> s2;
    Skup <int> s3;
    int arr[] = {1, 2, 3, 4};
    int arr2[] = {4, 5, 6};

    size_t arr1Size = sizeof(arr) / sizeof(*arr);
    size_t arr2Size = sizeof(arr2) / sizeof(*arr2);
    
    s1.ucitajElemente(arr, arr1Size);
    s2.ucitajElemente(arr2, arr2Size);

    // Ispod je samo kod za ispisivanje
    // =====================================
    cout << "Skup 1: ";
    s1.prikazi();
    cout << endl;
    cout << "Skup 2: ";
    s2.prikazi();
    cout << endl;
    cout << "Unija skupova s1 i s2: ";
    s3.unija(s1, s2);
    cout << endl;
    cout << "Presjek skupova s1 i s2: ";
    s3.presjek(s1, s2);
    cout << endl;
    cout << "Razlika skupova s1 i s2: ";
    s3.razlika(s1, s2);
    // =====================================

    return 0;
}
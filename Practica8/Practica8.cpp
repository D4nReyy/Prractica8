#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Transport {
    int number;
    string brand;
    union {
        int tonnage; // для грузового транспорта
        int seatingCapacity; // для пассажирского транспорта
        string* rentingCompany; // для легкового транспорта
    } info;
};

bool compareByRentingCompany(const Transport& a, const Transport& b) {
    return *a.info.rentingCompany < *b.info.rentingCompany;
}

void printCarsByBrand(const Transport* transports, int size, const string& desiredBrand) {
    cout << "Список легковых машин марки " << desiredBrand << ":\n";
    for (int i = 0; i < size; ++i) {
        if (transports[i].brand == desiredBrand) {
            cout << "Арендующая компания: " << *transports[i].info.rentingCompany << ", Номер машины: " << transports[i].number << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    const int numTransports = 5;
    string companyNames[numTransports] = { "Company A", "Company B", "Company C", "Company A", "Company C" };
    Transport transports[numTransports];

    transports[0].number = 1;
    transports[0].brand = "Toyota";
    transports[0].info.rentingCompany = &companyNames[0];

    transports[1].number = 2;
    transports[1].brand = "BMW";
    transports[1].info.rentingCompany = &companyNames[1];

    transports[2].number = 3;
    transports[2].brand = "Toyota";
    transports[2].info.rentingCompany = &companyNames[2];

    transports[3].number = 4;
    transports[3].brand = "Mercedes";
    transports[3].info.rentingCompany = &companyNames[0];

    transports[4].number = 5;
    transports[4].brand = "BMW";
    transports[4].info.rentingCompany = &companyNames[2];

    string desiredBrand = "Toyota";

    sort(transports, transports + numTransports, compareByRentingCompany);

    printCarsByBrand(transports, numTransports, desiredBrand);

    return 0;
}

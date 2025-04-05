#include "scooter.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace ScooterRental;

string Scooter::model() {
    return _model;
}

string Scooter::color() {
    return _color;
}

int Scooter::pricePerHour() {
    return _pricePerHour;
}

Scooter::Scooter(string model, string color, int pricePerHour) : _model(model), _color(color), _pricePerHour(pricePerHour) {}

ostream& ScooterRental::operator << (ostream & out, const Scooter& s) {
    out << s._model << " " << s._color << " " << s._pricePerHour << endl;
    return out;
}

istream& ScooterRental::operator >> (istream & in, Scooter& s) {
    in >> s._model >> s._color >> s._pricePerHour;
    return in;
}

Scooter* ScooterRental::load(int & count) {
    ifstream in("scooters.txt");
    if (!in.is_open())
        return nullptr;
    in >> count;
    if (count < 1)
        return nullptr;
    Scooter *arr = new Scooter[count];
    for (int i = 0; i < count; i++)
        in >> arr[i];
    in.close();
    return arr;
}

Scooter* ScooterRental::create(int & count) {
    count = 5;
    Scooter* arr = new Scooter[count];
    arr[0] = { "Scooter1", "Red", 10 };
    arr[1] = { "Scooter2", "Blue", 15 };
    arr[2] = { "Scooter3", "Green", 12 };
    arr[3] = { "Scooter4", "Yellow", 20 };
    arr[4] = { "Scooter5", "Black", 25 };
    return arr;
}

void ScooterRental::save(Scooter *arr, int count) {
    ofstream out("scooters.txt");
    out << count << endl;
    for (int i = 0; i < count; i++) {
        out << arr[i] << endl;
    }
    out.close();
}

void ScooterRental::add(Scooter** arr, int* count) {
    Scooter* temp = new (nothrow) Scooter[*count + 1];
    if (temp == nullptr) {
        cout << "Error: Unable to allocate memory" << endl;
        return;
    }
    for (int i = 0; i < *count; i++) {
        temp[i] = (*arr)[i];
    }
    string model;
    string color;
    int price;
    cout << "Enter scooter model: " << endl;
    cin >> model;
    cout << "Enter scooter color: " << endl;
    cin >> color;
    cout << "Enter price per hour: " << endl;
    cin >> price;
    temp[*count].setModel(model);
    temp[*count].setColor(color);
    temp[*count].setPricePerHour(price);
    delete[] * arr;
    *arr = temp;
    (*count)++;
}

void ScooterRental::del(Scooter *arr, int *count) {
    int n = 0;
    cout << "Enter the number of the scooter: " << endl;
    cin >> n;
    if (n < 1 || n > *count) {
        cout << "Not found" << endl;
        return;
    }

    for (int i = (n - 1); i < *count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*count)--;
}

void ScooterRental::edit(Scooter *arr, int count) {
    int n = 0;
    cout << "Enter the number of the scooter: " << endl;
    cin >> n;
    if (n < 1 || n > count) {
        cout << "Not found" << endl;
        return;
    }
    string temp = "";
    cout << "Enter new model: " << endl;
    cin >> temp;
    arr[n - 1].setModel(temp);
    cout << "New color: " << endl;
    cin >> temp;
    arr[n - 1].setColor(temp);
    int price = 0;
    cout << "New price per hour: " << endl;
    cin >> price;
    arr[n - 1].setPricePerHour(price);
}

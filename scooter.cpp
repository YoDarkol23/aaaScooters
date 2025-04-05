#include "scooter.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace Aaa;

string Scooter::model() {
    return _model;
}

string Scooter::color() {
    return _color;
}

int Scooter::priceHour() {
    return _priceHour;
}

Scooter::Scooter(string model, string color, int priceHour) : _model(model), _color(color), _priceHour(priceHour) {}

ostream& Aaa::operator << (ostream& out, const Scooter& s) {
    out << s._model << " " << s._color << " " << s._priceHour << endl;
    return out;
}

istream& Aaa::operator >> (istream& in, Scooter& s) {
    in >> s._model >> s._color >> s._priceHour;
    return in;
}

Scooter* Aaa::load(int& count) {
    ifstream in("scooters.txt");
    if (!in.is_open())
        return nullptr;
    in >> count;
    if (count < 1)
        return nullptr;
    Scooter* arr = new Scooter[count];
    for (int i = 0; i < count; i++)
        in >> arr[i];
    in.close();
    return arr;
}

Scooter* Aaa::create(int& count) {
    count = 5;
    Scooter* arr = new Scooter[count];
    arr[0] = { "Nimbus2001", "Red", 10 };
    arr[1] = { "Nimbus2002", "Blue", 15 };
    arr[2] = { "Nimbus2003", "Gold", 12 };
    arr[3] = { "Nimbus2004", "Silver", 20 };
    arr[4] = { "Nimbus2005", "Black", 25 };
    return arr;
}

void Aaa::save(Scooter* arr, int count) {
    ofstream out("scooters.txt");
    out << count << endl;
    for (int i = 0; i < count; i++) {
        out << arr[i] << endl;
    }
    out.close();
}

void Aaa::add(Scooter** arr, int* count) {
    Scooter* temp = new (nothrow) Scooter[*count + 1];
    if (temp == nullptr) {
        cout << "Error: oshibka" << endl;
        return;
    }
    for (int i = 0; i < *count; i++) {
        temp[i] = (*arr)[i];
    }
    string model;
    string color;
    int price;
    cout << "Enter model: " << endl;
    cin >> model;
    cout << "Ente color: " << endl;
    cin >> color;
    cout << "Enter price: " << endl;
    cin >> price;
    temp[*count].setModel(model);
    temp[*count].setColor(color);
    temp[*count].setPriceHour(price);
    delete[] * arr;
    *arr = temp;
    (*count)++;
}

void Aaa::del(Scooter* arr, int* count) {
    int n = 0;
    cout << "Enter the number: " << endl;
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

void Aaa::edit(Scooter* arr, int count) {
    int n = 0;
    cout << "Enter the number: " << endl;
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
    cout << "New price: " << endl;
    cin >> price;
    arr[n - 1].setPriceHour(price);
}

void Aaa::search(Scooter* arr, int count) {
    string model, color;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter color: ";
    cin >> color;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].model() == model && arr[i].color() == color) {
            cout << "Scooter found!" << endl;
            cout << arr[i] << endl;
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Not found!" << endl;
    }
}
void Aaa::show(Scooter* arr, int count) {
    cout << "List of scooters:" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

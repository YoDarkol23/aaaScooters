#include <iostream>
#include <string>

namespace Aaa {
    class Scooter {
        std::string _model;
        std::string _color;
        int _priceHour;

    public:
        Scooter() = default;
        Scooter(std::string model, std::string color, int priceHour);

        std::string model();
        std::string color();
        int priceHour();

        friend std::ostream& operator << (std::ostream& out, const Scooter& s);
        friend std::istream& operator >> (std::istream& in, Scooter& s);
        void setModel(const std::string& model) { _model = model; }
        void setColor(const std::string& color) { _color = color; }
        void setPriceHour(int price) { _priceHour = price; }
    };

    std::ostream& operator << (std::ostream& out, const Scooter& s);
    std::istream& operator >> (std::istream& in, Scooter& s);
   
    Scooter* load(int& count);
    Scooter* create(int& count);

        void save(Scooter* arr, int count);
        void add(Scooter** arr, int* count);
        void del(Scooter* arr, int* count);
        void edit(Scooter* arr, int count);
        void search(Scooter* arr, int count);
        void show(Scooter* arr, int count);
}

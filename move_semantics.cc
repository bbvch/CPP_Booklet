/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

#include <vector>

template <typename T> void swap(T &a, T &b) {
  T tmp(std::move(a));
  a = std::move(b);
  b = std::move(tmp);
}

struct Dummy {
  int *data;
  Dummy() : data(nullptr) {}
  Dummy(int myInt) : data(new int) { *data = myInt; };

  ~Dummy() { delete data; }
  // verhindert das Kopieren
  Dummy(const Dummy &) = delete;
  Dummy &operator=(const Dummy &) = delete;
  // unterstützt das Verschieben
  Dummy(Dummy &&other) // Move constructor
      : data(other.data) {
    other.data = nullptr;
  }
  Dummy &operator=(Dummy &&other) // Move operator
  {
    if (data)
      delete data;
    data = other.data;
    other.data = nullptr;
    return *this;
  }
};

int main(int, char **) {

  // Beispiele mit verschiebbaren Objekten
  // in Standard-Containern
  // Verwendung bei einem Standard-Container
  std::vector<Dummy> vd1;    // leerer Vektor
  vd1.push_back(Dummy(100)); // temporäres Objekt dem
  // Vektor übergeben
  vd1.emplace_back(200); // Variante ohne temporäres
  // Objekt
  Dummy di1(300);                // nicht temporäres Objekt
  vd1.push_back(std::move(di1)); // Inhalt von di1 in
  // Vektor verschieben
  // Nur ein komplettes Objekt erzeugen und dessen
  // Inhalt auf verschiedene Art und Weise weiterreichen
  std::vector<Dummy> vd2[3]; // Array aus 3 leeren
  // Vektoren
  vd2[0].push_back(Dummy(500)); // ein Element in
  // Vektor 0 einfügen
  vd2[1] = std::move(vd2[0]);                    // Vektor verschieben
  std::swap(vd2[1], vd2[2]);                     // Vektoren tauschen
  std::vector<Dummy> result = std::move(vd2[2]); // Element herausholen

  int x = 20;
  int y = 40;
  swap(x, y);
}

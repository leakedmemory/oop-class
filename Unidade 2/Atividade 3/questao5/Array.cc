#include "Array.h"

using namespace std;

ostream &operator<<(ostream &out , const Array & a)
{
  for (int i = 0 ; i < a.tam ; i++)
    out << a.arr[i] << " ";
  
  out << endl;

  return out;
}

istream &operator>>(istream &inp, Array & a)
{
  for (int i = 0 ; i < a.tam ; i++)
    inp >> a.arr[i];
  
  return inp;
}

Array::Array(int tam)
{
  this->tam = (tam > 0 ? tam : 10);

  arr = new int[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = 0;
}

Array::Array(const Array &obj) : tam(obj.tam)
{
  arr = new int[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = obj.arr[i];
}

Array::~Array()
{
  delete [] arr;
}

int Array::getSize() const
{
  return tam;
}

const Array &Array::operator=(const Array &obj)
{
  if (&obj != this) // evita auto-atribuição
  {
    if (this->tam != obj.tam)
    {
      delete [] this->arr;
      this->tam = obj.tam;
      this->arr = new int[this->tam];
    }

    for (int i = 0 ; i < this->tam ; i++)
      arr[i] = obj.arr[i];

  }

  return *this;
}

bool Array::operator==(const Array &obj) const
{
  if (this->tam != obj.tam)
    return false;

  for (int i = 0 ; i < this->tam ; i++)
    if (arr[i] != obj.arr[i])
      return false;
  
  return true;
}

int &Array::operator[](int i)
{
  if (i < 0 || i >= tam)
  {
    cerr << "Erro: Indice " << i << " fora de faixa." << endl;

    exit(1);
  }

  return arr[i];
}

int Array::operator[](int i) const
{
  if (i < 0 || i >= tam)
  {
    cerr << "Erro: Indice " << i << " fora de faixa." << endl;

    exit(1);
  }

  return arr[i];
}

Array Array::operator+(const Array &arr) const
{
    int tamanho = this->tam + arr.tam;
    Array retorno(tamanho);
    int *newArray = new int[tamanho];
    int util = 0;

    for (int index = 0; index < tamanho; index++) {
        if (index < this->tam) {
            newArray[index] = this->arr[index];
        } else {
            newArray[index] = arr[util];
            util++;
        }
    }

    retorno.arr = newArray;
    return retorno;
}

void Array::operator+=(const Array &arr)
{
    Array tmp(*this);
    delete [] this->arr;

    int tamanho = tmp.tam + arr.tam;
    this->arr = new int[tamanho];
    this->tam = tamanho;
    int util = 0;

    for (int index = 0; index < tamanho; index++) {
        if (index < tmp.tam) {
            this->arr[index] = tmp[index];
        } else {
            this->arr[index] = arr[util];
            util++;
        }
    }
}

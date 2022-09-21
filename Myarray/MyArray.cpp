#include<iostream>
using namespace std;

template<typename T>
class MyArray{
    private:
        T* array;
        int size;

    public:
        MyArray(int size) {
            this->size=size;
            array=new T[size];
        }
        T at(int i){
            if(i < size) return array[i];
            else return -1;
        }
        void at(int i, T x){
            if(i < size) array[i]=x;
        }
        int getSize(){
            return size;
        }
        T* getPointer(){
            return &array[0];
        }
        void copy(MyArray<T>* dst){
            if(dst->getSize()== size){
                for(int i=0; i<size; i++){
                    dst->at(i, array[i]);
                }
            }
        }
        T operator[](int i){
            if(i < size) return array[i];
            else return -1;
        }
        friend ostream& operator<<(ostream& os, MyArray<T>& a){
            os << "Array di dimenzione: " << a.getSize() << endl;
            for(int i=0; i<a.size; i++){
                cout << a.array[i] << endl;
            }
            return os;
        }
};

int main(){
    MyArray<int> a(10);
    for(int i=0; i<10; i++){
        a.at(i, i);
    }
    cout << a << endl;
    a.at(1, 10);
    cout << a << endl;
    cout << a.getPointer() << endl;
    cout << a.getSize() << endl;
    int l=a[5];
    cout << l << endl;
    MyArray<int>* b=new MyArray<int>(10);
    for(int i=0; i<10; i++){
        b->at(i, i);
    }
    a.copy(b);
    cout << *b << endl;
}
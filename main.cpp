#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

template <class T>


class MyArray{
private:

    T** pointer=NULL;
    int arr_length=0;
    int cur_row=0;
    int cur_column=0;
    int cur=0;
public:
    MyArray(int arr_length){
        this->arr_length=arr_length;
        pointer=new T*[arr_length];
        for (int i=0;i<arr_length;i++){
            pointer[i]=new T[arr_length];
        }
    }

    void set_elem(T elem,int pos){
        pointer[pos]=elem;
    }
    void auto_init(int range){
        for(int i=0;i<arr_length;i++){
            for (int j=0;j<arr_length;j++){
                pointer[i][j]=(T)rand()%range;
            }
        }
    }

    void add_arr(T arr[],int arr_size){
       /* if (cur_row==arr_length_in){
            cur_row=0;
            cur_column++;
        }
        for(int i=0;i<arr_size;i++){
            pointer[cur]=arr[i];
            cout<<"\n"<<arr[i];
            cur++;
        */

    }
    int get_size(){
        return this->cur;
    }
    void operator+(MyArray<T> elem){
        //int size_arr=elem.get_size;
        //int size_elem=elem.arr_length;
        if (elem.arr_length!=arr_length){
            cout<<"\nNot possible";
            return;
        }
        for(int i=0;i<arr_length;i++){
            for(int j=0;j<arr_length;j++){
                pointer[i][j]+=elem.pointer[i][j];
            }
        }
        return;
    }

    void operator*(MyArray<T> elem){
        if (elem.arr_length!=arr_length){
            cout<<"\n The size is out of range";
            return;
        }
        MyArray<T> tmp(arr_length);
        T t=0;

        for(int i=0;i<arr_length;i++){
            for (int j=0;j<arr_length;j++){
                t=0;
                for(int g=0;g<arr_length;g++){
                    t+=pointer[i][g]*elem.pointer[g][j];
                }
                tmp.pointer[i][j]=t;
            }

        }
        for(int i=0;i<arr_length;i++){
            for(int j=0;j<arr_length;j++){
                pointer[i][j]=tmp.pointer[i][j];
            }
        }
    }
    /*
    1 3 4      5 6 8
    2 7 8      1 3 4
    9 4 5      7 2 9


    36 23 56
    73 49 116
    83*/

   /* std::istream& operator >> (std::istream& in, T* elem){
        in >> p.name >> p.age;
        return in;
    }*/


    void print_arr(){
        cout<<"\n\n";
        for(int i=0;i<arr_length;i++){

            for (int j=0;j<arr_length;j++){
                cout<<"\t"<<pointer[i][j];
            }
            cout<<"\n";
        }

    }

    virtual ~MyArray(){
        //delete[] pointer;
        for(int i=0;i<arr_length;i++){
            delete[] pointer[i];
        }
        delete[] pointer;
    }
};


struct Product{
    string name;
    float price;
};

/*std::ostream& operator >> (std::ostream &os, Product* elem){
        int cur=elem.get_size();
        in >> elem[cur].name >> elem[cur].price;
        return;
}*/

/*std::ostream& operator cout<< (std::ostream &out,){
    elem.print_arr();

    return out;
}*/



int main()
{

    MyArray<int> dyn_arr(3);
    MyArray<int> dyn_arr2(3);
    dyn_arr.auto_init(10);
    dyn_arr2.auto_init(10);
    //dyn_arr=dyn_arr+dyn_arr2;

    dyn_arr.print_arr();

    dyn_arr2.print_arr();
    dyn_arr*dyn_arr2;
    //dyn_arr+dyn_arr2;
    dyn_arr.print_arr();

    return 0;
}

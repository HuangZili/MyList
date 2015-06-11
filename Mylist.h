#ifndef _mylist_h
#define _mylist_h

#include<iostream>
using namespace std;

template <class T>
int merge_inc(T *start,int length)//merge two arrays into one
{
    T *temp;
    temp=new T[length];
    int counter=0,counter1=0,counter2=0;
    while(counter<=length-1)
    {
        if ((*(start+counter1))>(*(start+length/2+counter2)))
        {
            *(temp+counter)=*(start+length/2+counter2);
            counter++;
            counter2++;
            if(counter2==length-length/2)
            {
                for(int i=counter1;i<=length/2-1;++i)
                {
                    *(temp+counter)=*(start+i);
                    counter++;
                }
                break;
            }
        }
        else
        {
            *(temp+counter)=*(start+counter1);
            counter++;
            counter1++;
             if(counter1==length/2)
            {
                for(int i=counter2;i<=length-length/2-1;++i)
                {
                    *(temp+counter)=*(start+length/2+i);
                    counter++;
                }
                break;
            }
        }
    }
    for(int i=0;i<length;++i)
    {
        *(start+i)=*(temp+i);
    }
    delete [] temp;
    return 0;
}

template <class T>
int merge_dec(T *start,int length)//merge two arrays into one
{
    T *temp;
    temp=new T[length];
    int counter=0,counter1=0,counter2=0;
    while(counter<=length-1)
    {
        if ((*(start+counter1))<(*(start+length/2+counter2)))
        {
            *(temp+counter)=*(start+length/2+counter2);
            counter++;
            counter2++;
            if(counter2==length-length/2)
            {
                for(int i=counter1;i<=length/2-1;++i)
                {
                    *(temp+counter)=*(start+i);
                    counter++;
                }
                break;
            }
        }
        else
        {
            *(temp+counter)=*(start+counter1);
            counter++;
            counter1++;
             if(counter1==length/2)
            {
                for(int i=counter2;i<=length-length/2-1;++i)
                {
                    *(temp+counter)=*(start+length/2+i);
                    counter++;
                }
                break;
            }
        }
    }
    for(int i=0;i<length;++i)
    {
        *(start+i)=*(temp+i);
    }
    delete [] temp;
    return 0;
}

template<class T>
int merge_sort(T *start,int length,bool inc)
{
    if(length==1)
    {
        return 1;
    }
    else
    {
        if(inc)
        {
            merge_sort(start,length/2,true);
            merge_sort(start+length/2,length-length/2,true);
            merge_inc(start,length);
            return 0;
        }
        else
        {
            merge_sort(start,length/2,false);
            merge_sort(start+length/2,length-length/2,false);
            merge_dec(start,length);
            return 0;
        }
    }
}

template<class T>
class MyList{
private:
	T *a;
	int size_of_list;
	int real_size;
	void double_space();//double the size_of_list when necessary.
public:
	MyList(){
		size_of_list = 100;
		a = new T [size_of_list];
		real_size=0;
	}
	MyList(int num, const T &item);//create a list by copying item for num times.
	MyList(const MyList &l);//create a list by copying another list.
    MyList(T* arr, int len);//create a list with an array.
    void display();
	void push(const T &item);//push item at the list of list.
	T pop();//pop the last item of the list.
	void insert(int index, const T &item);//insert item at the index position.
	void clean();//clean the list.
	int get_size();//return the real_size of the list.
	void erase(int start, int end); //delete the list items from position start to end.(including start and end)
	T get_item(int index);//get the item at the index position.
	MyList<T> get_item(int start, int end);//return the list items from position start to end.(including start and end)
	int count(const T &item);//how many items in the list is same as the given item?
	void remove(const T &item);//delete the first item that is same as the given item.

    template <class Type>
	friend MyList<Type> operator+ (const MyList<Type> &l1, const MyList<Type> &l2); //combine two lists.

    template <class Type>
    friend MyList<Type> operator + (const MyList<Type> &l1, const Type &item); //add item to the end of l1 and create a new list.

	MyList<T> &operator = (const MyList<T> &l);//assignment.
	MyList<T> &operator += (const T &item);//add item to the end of this list.
	MyList<T> &operator += (const MyList<T> &l);//add an list to the end of this list.
	T &operator [](int index);//return the item with index "index".

	template <class Type>
	friend ostream & operator<<(ostream &os, const MyList<Type> &obj);//print the list.
	void sort(bool);//sort a list.if bool is true, sort with an ascending order.
    void reverse();//reverse the whole list.
    ~MyList(){delete [] a;}

};

template <class T>
void MyList<T>::double_space()
{
    T *temp;
    temp=a;
    a=new T[size_of_list*2];
    size_of_list=size_of_list*2;
    for(int i=0;i<real_size;++i)
    {
        a[i]=temp[i];
    }
    delete [ ] temp;
}

template <class T>
MyList<T>::MyList(int num,const T &item)
{
    a=new T[num+100];//prevent the error num=0;
    size_of_list=num+100;
    real_size=num;
     for (int i=0;i<num;++i)
    {
        a[i]=item;
    }
}


template <class T>
MyList<T>::MyList(const MyList &l)
{
    a=new T[l.real_size+100];
    size_of_list=l.real_size+100;
    real_size=l.real_size;
     for (int i=0;i<l.real_size;++i)
    {
        a[i]=l.a[i];
    }
}

template <class T>
MyList<T>::MyList(T* arr, int len)
{
    a=new T[len+100];
    size_of_list=len+100;
    real_size=len;
     for (int i=0;i<len;++i)
    {
        a[i]=arr[i];
    }
}

template <class T>
void MyList<T>::push(const T &item)
{
    if(real_size==size_of_list)
    {
        double_space();
    }
    a[real_size]=item;
    real_size++;
}

template <class T>
T MyList<T>::pop()
{
    try{
        if(real_size==0)
        {
            throw 0;
        }
        else
        {
            real_size--;
            return a[real_size];
        }
    }
    catch(int condi)
    {
        if(condi==0)
        {
            cout<<"invalid pop operation"<<endl;
        }
    }

}

template <class T>
void MyList<T>::insert(int index, const T &item)
{
    if(real_size==size_of_list)
    {
        double_space();
    }
    if(index<-real_size)
    {
        cout<<"invalid index in the insert function"<<endl;
        return ;
    }
    if(index<0)
    {
        index=real_size+index;
    }
    if(index>=real_size)
    {
        a[real_size]=item;
        real_size++;
    }
    else
    {
        T *temp;
        temp=a;
        T *b;
        b=new T[size_of_list];
        for(int i=0;i<index;++i)
        {
            b[i]=a[i];
        }
        b[index]=item;
        for(int i=index;i<real_size;++i)
        {
            b[i+1]=a[i];
        }
        delete [] temp;
        a=b;
        real_size++;
    }
}

template <class T>
void MyList<T>::clean()
{
    real_size=0;
}

template <class T>
int MyList<T>::get_size()
{
    return real_size;
}

template <class T>
void MyList<T>::erase(int start, int end)
{
    if(start<0)
    {
        start=real_size+start;
    }
    if(end<0)
    {
        end=real_size+end;
    }
    try{
        if(start>=real_size||start<0)
        {
            throw 0;
        }
        if(end>=real_size||end<0)
        {
            throw 1;
        }
        if(start<=end)
        {
            T *temp;
            T *b;
            b=new T[real_size];
            for(int i=0;i<=start-1;++i)
            {
                b[i]=a[i];
            }
            for(int i=end+1;i<=real_size-1;++i)
            {
                b[start+i-end-1]=a[i];
            }
            real_size=real_size-(end-start+1);
            temp=a;
            a=b;
            delete [] temp;
        }
    }
    catch(int condi)
    {
        if(condi==0) {cout<<"invalid start in the erase function"<<endl;}
        if(condi==1) {cout<<"invalid end in the erase function"<<endl;}
    }
}


template <class T>
T MyList<T>::get_item(int index)
{
    if(index<0)
    {
        index=real_size+index;
    }
    try
    {
        if(index<0||index>=real_size)
        {
           throw 0;
        }
        else
        {
            return a[index];
        }
    }
    catch(int condi)
    {
        if(condi==0)
        {
             cout<<"invalid index in the insert function"<<endl;
             //return what??
        }
    }
}

template <class T>
MyList<T>  MyList<T>::get_item(int start, int end)
{
    if(start<0)
    {
        start=real_size+start;
    }
    if(end<0)
    {
        end=real_size+end;
    }
    try{
        if(start>=real_size||start<0)
        {
            throw 0;
        }
        if(end>=real_size||end<0)
        {
            throw 1;
        }
        if(start<=end)
        {
            MyList<T> answer(a+start,end-start+1);
            return answer;
        }
        else
        {
            MyList<T> answer;
            return answer;
        }
    }
    catch(int condi)
    {
        if(condi==0)
        {
            MyList<T> answer;
            cout<<"invalid start in the erase function"<<endl;
            return answer;
        }
        if(condi==1)
        {
            MyList<T> answer;
            cout<<"invalid end in the erase function"<<endl;
            return answer;
        }
    }
}


template <class T>
int MyList<T>::count(const T &item)
{
    int counter=0;
    for(int i=0;i<real_size;++i)
    {
        if(a[i]==item)
        {
            counter++;
        }
    }
    return counter;
}

template <class T>
void MyList<T>::remove(const T &item)
{
    int i,j;
    for(i=0;i<real_size;++i)
    {
        if(a[i]==item)
        {
            break;
        }
    }
    if(i==real_size)
    {
        return ;
    }
    else
    {
        for(j=i;j<=real_size-2;++j)
        {
            a[j]=a[j+1];
        }
        real_size--;
        return ;
    }
}

template <class T>
MyList<T> operator+ (const MyList<T> &l1, const MyList<T> &l2)
{
    MyList<T> *answer;
    answer=new MyList<T>;
    while (answer->size_of_list<(l1.real_size+l2.real_size))
    {
        answer->double_space();
    }
    for(int i=0;i<l1.real_size;++i)
    {
        answer->a[i]=l1.a[i];
    }
    for(int i=0;i<l2.real_size;++i)
    {
        answer->a[i+l1.real_size]=l2.a[i];
    }
    answer->real_size=l1.real_size+l2.real_size;
    return (*answer);
}

template <class T>
MyList<T> operator + (const MyList<T> &l1, const T &item)
{
   MyList<T> answer(l1);
   answer.a[l1.real_size]=item;
   answer.real_size++;
   return answer;
}

template <class T>
MyList<T> &MyList<T>::operator = (const MyList<T> &l)
{
    if(&l==this){return (*this);}
    else
    {
        while(size_of_list<l.real_size)
        {
            double_space();
        }
        for(int i=0;i<l.real_size;++i)
        {
            a[i]=l.a[i];
        }
        real_size=l.real_size;
        return (*this);
    }
}

template <class T>
MyList<T> &MyList<T>::operator += (const T &item)
{
    if(real_size==size_of_list)
    {
        double_space();
    }
    a[real_size]=item;
    real_size++;
    return (*this);
}

template <class T>
MyList<T> &MyList<T>::operator += (const MyList<T> &l)
{
    while(size_of_list<l.real_size+real_size)
    {
        double_space();
    }
    for(int i=0;i<l.real_size;++i)
    {
        a[i+real_size]=l.a[i];
    }
    real_size=real_size+l.real_size;
    return (*this);
}

template <class T>
T &MyList<T>::operator [](int index)
{
    if(index<0)
    {
        index=real_size+index;
    }
    try
    {
        if(index<0||index>=real_size)
        {
            throw 0;
        }
        else
        {
            return a[index];
        }
    }
    catch(int condi)
    {
        if(condi==0)
        {
            cout<<"list index out of range!"<<endl;
        }
    }
}

template <class T>
ostream & operator<<(ostream &os, const MyList<T> &obj)
{
    os<<"[";
    for(int i=0;i<=obj.real_size-2;++i)
    {
        os<<obj.a[i]<<",";
    }
    os<<obj.a[obj.real_size-1]<<"]";
    return os;
}


template <class T>
void MyList<T>::reverse()
{
    T *b;
    b=new T[size_of_list];
    for(int i=0;i<real_size;++i)
    {
        *(b+i)=a[real_size-1-i];
    }
    T *temp;
    temp=a;
    delete [] temp;
    a=b;
}


template<class T>
void MyList<T>::sort(bool less=true)
{
    if(less==true)
    {
        merge_sort(a,real_size,true);
    }
    else
    {
        merge_sort(a,real_size,false);
    }
}



template <class T>
void MyList<T>::display()
{
    cout<<"real size of list is "<<real_size<<endl;
    cout<<"size of list is "<<size_of_list<<endl;
    if(real_size>=8)
    {
        cout<<"elements of list "<<endl;
        for(int i=0;i<8;++i)
        {
            cout<<a[i]<<endl;
        }
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
    }
    else
    {
        cout<<"elements of list "<<endl;
        for(int i=0;i<real_size;++i)
        {
            cout<<a[i]<<endl;
        }
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
    }
}
#endif

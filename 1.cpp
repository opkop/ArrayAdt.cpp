#include<iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    Array(int);
    bool isEmpty();
    void append(int);
    void insert(int,int);
    void edit(int,int);
    void del(int);
    int get(int);
    int count();
    bool isFull();
    ~Array();
    int find(int);
};
int Array::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
            return i;
    }
    return -1;
}
Array::~Array()
{
    delete []ptr;
}
bool Array::isFull()
{
    return(lastIndex==capacity-1);
}
void Array::del(int index)
{
    int i;
    if(index<0||index>lastIndex)
        cout<<"Invalid Index"<<endl;
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
}
void Array::edit(int index,int data)
{
    if (index >= 0 && index < lastIndex + 1)
         ptr[index]=data;
}
int Array::get(int index)
{
   if (index >= 0 && index < lastIndex + 1)
        return (ptr[index]);
    cout << endl<< "Invalid or Empty array";
    return -1;
}
int Array::count()
{
    return(lastIndex+1);
}
void Array::insert(int index,int data)
{
    int i;
    if(lastIndex==capacity-1)
        cout<<"Array is full"<<endl;
    else if(index<0||index>lastIndex+1)
        cout<<"Invalid Index"<<endl;
    else
    {
        for(i=lastIndex;index<=i;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::append(int data)
{
    if(lastIndex==capacity-1)
        cout<<"Array is full"<<endl;
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
bool Array::isEmpty()
{
    return(lastIndex==-1);
}
Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
int main()
{
  Array obj(5);
  if(obj.isEmpty())
      cout<<"Array is empty"<<endl;
  obj.append(10);
  obj.append(20);
  obj.append(30);
  obj.append(40);
  for(int i=0;i<obj.count();i++)
  {
      cout<<obj.get(i)<<" ";
  }
  cout<<endl;
  obj.insert(1,15);
  for(int i=0;i<obj.count();i++)
  {
      cout<<obj.get(i)<<" ";
  }
  cout<<endl;
  obj.edit(2,17);
  for(int i=0;i<obj.count();i++)
  {
      cout<<obj.get(i)<<" ";
  }
  if (obj.isFull())
      cout << endl<< "Array is full"<< endl;
  obj.del(2);
   for(int i=0;i<obj.count();i++)
  {
      cout<<obj.get(i)<<" ";
  }
  obj.~Array();
  cout<<endl;
  cout<<"Same element in array index is:"<<" "<<obj.find(40);
}

#include<iostream>
#include<string.h>

using namespace std;

class TMString
{
private:
char *ptr;
int size;

public:
TMString();
TMString (const char *ptr);
virtual ~TMString();
TMString & operator=(const TMString &other);
TMString & operator=(const char *ptr);
friend ostream & operator<<(ostream &out,TMString &tmString);
int operator<(const TMString &other);
int operator<=(const TMString &other);
int operator>(const TMString &other);
int operator>=(const TMString &other);
int operator==(const TMString &other);
int operator!=(const TMString &other);
void operator+=(const TMString &other);
TMString operator+(const TMString &other);
};

TMString::TMString()
{
this->ptr=NULL;
this->size=0;
}


TMString::TMString (const char *ptr)
{
this->ptr=NULL;
if(ptr==NULL)return ;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);

}


TMString:: ~TMString()
{
if(this->ptr)  delete []this->ptr;
}
TMString & TMString:: operator=(const TMString &other)
{
if(this->ptr)delete[]this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL)return *this;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);
return *this;
}

TMString & TMString:: operator=(const char *ptr)
{
if(this->ptr)delete[]this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL)return *this;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return *this;
}
ostream & operator<<(ostream &out,TMString &tmString)
{
if(tmString.ptr==NULL)return out;
out<<tmString.ptr;
return out;
}

int TMString:: operator<(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return strcmp(this->ptr,other.ptr)<0;
}
int TMString:: operator<=(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 1;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return strcmp(this->ptr,other.ptr)<=0;
}
int TMString:: operator>(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 0;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return strcmp(this->ptr,other.ptr)>0;
}
int TMString:: operator>=(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return strcmp(this->ptr,other.ptr)>=0;
}
int TMString:: operator==(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 0;
return strcmp(this->ptr,other.ptr)==0;
}
int TMString:: operator!=(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 1;
return strcmp(this->ptr,other.ptr)!=0;
}

void TMString:: operator+=(const TMString &other)
{
if(this->ptr==NULL&&other.ptr==NULL)return;
else if(this->ptr==NULL)
{
(*this)=other;
return;
}
else if(other.ptr==NULL) return;
char *tmp=new char[this->size+other.size+1];
strcpy(tmp,this->ptr);
strcat(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}
TMString TMString:: operator+(const TMString &other)
{
TMString k;
if(this->ptr==NULL&&other.ptr==NULL)return k;
else if(this->ptr==NULL)
{
k=other;
return k;
}
else if(other.ptr==NULL)
{
k=(*this);
}
else
{
k=(*this);
k+=other;
return k;
}
return k;
}




int main()
{
/*TMString g="cool";
cout<<g<<endl;
TMString m;
m="very cool";
cout<<m<<endl;
TMString k;
k=m;
cout<<k<<endl;
*/
TMString a="cool";
TMString b="America";
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
cout<<"(a<b=)"<<(a<b)<<endl;
cout<<"(a<=b=)"<<(a<=b)<<endl;
cout<<"(a>b=)"<<(a>b)<<endl;
cout<<"(a>=b=)"<<(a>=b)<<endl;
cout<<"(a==b=)"<<(a==b)<<endl;
cout<<"(a!=b=)"<<(a!=b)<<endl;

cout<<"*********************"<<endl<<endl;
TMString c=a+b;
cout<<"c="<<c<<endl;
TMString g="Asha";
c+=g;
cout<<"c="<<c<<endl;


return 0;
}


#include <iostream>
#include <string>
using namespace std;
class bookInfo
{
    string title;
    string author;
    string genre;
    int publicationYear;
    int price;

public:
    void setTitle(string a)
    {

        title = a;
    }
    void setAuthor(string a)
    {

        author = a;
    }
    void setGenre(string a)
    {

        genre = a;
    }
    void setPublicationYr(int a)
    {
        publicationYear = a;
    }
    void setPrice(int a)
    {
        price = a;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getGenre()
    {
        return genre;
    }
    int getPublicyr()
    {
        return publicationYear;
    }
    int getPrice()
    {
        return price;
    }
    void displayBookinfo()
    {
        cout <<"The details of the book are as under :\n Title :"<<getTitle() << "\n Author : " << getAuthor() << "\n Genre :" << getGenre() << "\n Publication year :" << getPublicyr() << "\n Price :" <<getPrice();
    }
    void discountedPrice()
    {
        int discountedprice = price -( (price * 10) / 100);
        cout <<" \n\nbook price after discount will be :";
        cout<<discountedprice;
    }
};
int main()
{
    bookInfo book1, book2;
    book1.setTitle("The great gatsby");
    book1.setAuthor("haris naeem");
    book1.setGenre("horror");
    book1.setPublicationYr(1998);
    book1.setPrice(900);
    book1.displayBookinfo();
    book1.discountedPrice();
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <typeinfo>

class Book
{
public:
    Book(std::string firstName, std::string secondName, std::string middleName, std::string title, u_int16_t releaseYear)
        : title(title), releaseYear(releaseYear) 
    {
        authorName["first"] = firstName;
        authorName["second"] = secondName;
        authorName["middle"] = middleName;
    }

    std::unordered_map<std::string, std::string> getAuthorName()
    {
        return this->authorName;
    }
    void setAuthorName(std::unordered_map<std::string, std::string> name)
    {
        this->authorName = name;
    }

    std::string getTitle()
    {
        return this->title;
    }
    void setTitle(std::string title)
    {
        this->title = title;
    }

    u_int16_t getReleaseYear()
    {
        return this->releaseYear;
    }
    void setReleaseYear(u_int16_t year)
    {
        this->releaseYear = year;
    }

private:
    std::unordered_map<std::string, std::string> authorName;
    std::string title;
    u_int16_t releaseYear;
};

enum class State {addBook, deleteBook, findBook, exit};

int main(int argc, const char** argv)
{
    std::vector<Book> library;

    State state;

    int command;
    std::string buff;
    std::cout << "1. Add book\n2. Delete book by title and release year\n3. Find book by title\n4. Exit\n";
    std::cout << "Enter the command: ";
    std::getline(std::cin, buff);
    command = std::stoi(buff);
    switch (command)
    {
    case 1:
        state = State::addBook;
        break;
    case 2:
        state = State::deleteBook;
        break;
    case 3:
        state = State::findBook;
        break;
    case 4:
        state = State::exit;
        break;
    default:
        std::cout << "Incorrect command number\n";
        state = State::exit;
        break;
    }

    while(state != State::exit)
    {
        std::string firstName, secondName, middleName, title;
        u_int16_t year;
        bool flag = 0;
        switch (state)
        {
        case State::exit:
            break;
        case State::addBook:
            std::cout << "First name of author: ";
            std::getline(std::cin, firstName);
            std::cout << "Second name of author: ";
            std::getline(std::cin, secondName);
            std::cout << "Middle name of author: ";
            std::getline(std::cin, middleName);
            std::cout << "Title name: ";
            std::getline(std::cin, title);
            std::cout << "Release year: ";
            std::getline(std::cin, buff);
            year = std::stoi(buff);
            library.push_back(Book(firstName, secondName, middleName, title, year));
            std::cout << "Book " << library.back().getTitle() << " added successfully\n";
            break;
        case State::deleteBook:
            std::cout << "Title name: ";
            std::getline(std::cin, title);
            std::cout << "Title release year: ";
            std::getline(std::cin, buff);
            year = std::stoi(buff);
            flag = 0;
            for(auto i = library.begin(); i != library.end(); ++i)
                if (i->getTitle() == title && i->getReleaseYear() == year)
                {
                    library.erase(i);
                    flag = 1;
                }
            if (flag) std::cout << "Book was deleted successfully\n";
            else std::cout << "Cannot find a book with that data\n";
            break;
        case State::findBook:
            std::cout << "Title name: ";
            std::getline(std::cin, title);
            for (auto i = library.begin(); i != library.end(); ++i)
                if (i->getTitle().find(title) != std::string::npos)
                {
                    std::cout << i->getAuthorName()["first"] << " " << i->getAuthorName()["second"] << " " << i->getAuthorName()["middle"]
                              << std::endl << i->getTitle() << std::endl << i->getReleaseYear() << std::endl;
                }    
            break;
        default:
            std::cout << "Incorrect command number\n";
            break;
        }
        std::cout << "1. Add book\n2. Delete book by title and release year\n3. Find book by title\n4. Exit\n";
        std::cout << "Enter the command: ";
        std::getline(std::cin, buff);
        command = std::stoi(buff);
        switch (command)
        {
        case 1:
            state = State::addBook;
            break;
        case 2:
            state = State::deleteBook;
            break;
        case 3:
            state = State::findBook;
            break;
        case 4:
            state = State::exit;
            break;
        default:
            std::cout << "Incorrect command number\n";
            state = State::exit;
            break;
        }
    }

    return 0;
}
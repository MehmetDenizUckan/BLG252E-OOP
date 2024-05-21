#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
#include <iomanip>


class Book {

public:
  // Member variables (data)
  int book_id;
  int publication_year;
  int author_ID;
  int publisher_ID;
  std::string book_title;

  // Default constructor 
  Book() : book_id(0), publication_year(0), author_ID(0), publisher_ID(0), book_title("") {}

  // Parameterized constructor (initializes with provided values)
  Book(int b_id, int p_year, int a_ID, int pub_ID, std::string title)
      : book_id(b_id), publication_year(p_year), author_ID(a_ID), publisher_ID(pub_ID), book_title(title) {}

  // Method to print book details
  void Print() {
    std::cout << "Book ID: " << book_id << std::endl;
    std::cout << "Publication Year: " << publication_year << std::endl;
    std::cout << "Author ID: " << author_ID << std::endl;
    std::cout << "Publisher ID: " << publisher_ID << std::endl;
    std::cout << "Book Title: " << book_title << std::endl;
  }
};

std::map<int, std::string> publishers;
std::map<int, std::string> authors;
std::map<int, Book> books;

void readPublishers(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading." << std::endl;
        return;
    }

    int id;
    std::string name;
    while (infile >> id && std::getline(infile, name)) {
        if (name.front() == ' ') {
            name = name.substr(1); // Remove leading space
        }
        publishers[id] = name;
    }
    infile.close();
}

void readAuthors(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading." << std::endl;
        return;
    }

    int id;
    std::string name;
    while (infile >> id && std::getline(infile, name)) {
        if (name.front() == ' ') {
            name = name.substr(1); // Remove leading space
        }
        authors[id] = name;
    }
    infile.close();
}

void readBooks(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading." << std::endl;
        return;
    }

    int book_id, publication_year, author_ID, publisher_ID;
    std::string book_title;
    while (infile >> book_id >> publication_year >> author_ID >> publisher_ID && std::getline(infile, book_title)) {
        if (book_title.front() == ' ') {
            book_title = book_title.substr(1); // Remove leading space
        }
        books[book_id] = Book(book_id, publication_year, author_ID, publisher_ID, book_title);
    }
    infile.close();
}

int main() {
    readPublishers("PUBLISHERS.txt");
    readAuthors("AUTHORS.txt");
    readBooks("BOOKS.txt");

    if (books.empty()) {
        std::cerr << "No books were loaded." << std::endl;
        return 1;
    }

    std::cout << "LISTS OF ALL BOOKS GROUPED BY PUBLISHERS" << std::endl;
    std::cout << "========================================" << std::endl;

    for (const auto& publisher : publishers) {
        int pub_id = publisher.first;
        const std::string& pub_name = publisher.second;

        std::cout << "PUBLISHER ID    : " << std::setw(3) << pub_id << std::endl;
        std::cout << "PUBLISHER NAME  : " << pub_name << std::endl;

        int book_count = 0;
        for (const auto& book : books) {
            if (book.second.publisher_ID == pub_id) {
                book_count++;
            }
        }

        std::cout << "NUMBER OF BOOKS : " << book_count << std::endl;

        std::cout << std::setw(10) << "BOOK_ID"
                  << std::setw(20) << "PUBLICATION_YEAR"
                  << std::setw(30) << "AUTHOR_FULLNAME"
                  << std::setw(30) << "BOOK_TITLE"
                  << std::endl;

        for (const auto& book : books) {
            if (book.second.publisher_ID == pub_id) {
                std::cout << std::setw(10) << book.second.book_id
                          << std::setw(20) << book.second.publication_year
                          << std::setw(30) << authors[book.second.author_ID]
                          << std::setw(30) << book.second.book_title
                          << std::endl;
            }
        }

        std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
    }

    std::cout << "TOTAL NUMBER OF ALL BOOKS : " << books.size() << std::endl;
    std::cout << "Program Finished."<<std::endl;

    return 0;
}

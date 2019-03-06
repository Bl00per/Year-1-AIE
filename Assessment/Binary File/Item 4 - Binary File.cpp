#include <iostream>
#include <fstream>

const int buffer_title = 40;
const int buffer_author = 40;
const int buffer_borrower = 80;

struct bookRecords
{
	int call_number;
	char title[buffer_title] = { '\0' };
	char author[buffer_author] = { '\0' };
	int book_status;
	int due_date;
	char borrower[buffer_borrower] = { '\0' };
};

void WriteRecordToFile(bookRecords *bookrecord);
void ReadRecordToConsole(int record_number);

int main()
{
	bookRecords newBook = {
		0001112,
		"Harry Potter",
		"J.K Rowling",
		1,
	};

	bookRecords newBook2 = {
		12345678,
		"Lord of the Rings",
		"J.R.R Tolkien",
		2,
		2591999,
		"Johnny",
	};


	WriteRecordToFile(&newBook);
	WriteRecordToFile(&newBook2);

	int user_input = 0;

	std::cout << "Which book would you like to look up?: ";
	std::cin >> user_input;
	std::cout << std::endl;
	ReadRecordToConsole(user_input);


	system("Pause");
	return 0;
}

void WriteRecordToFile(bookRecords *bookrecord) {
	std::ofstream file("library.dat", std::ios::in | std::ios::out | std::ios::binary);

	if (file.good()) {
		std::cout << "File data.dat opened successfully\n";

	}
	else {
		std::ofstream file("library.dat", std::ios::out | std::ios::binary);
		std::cout << "creating data.dat\n";
		file.close();

		WriteRecordToFile(bookrecord);
		return;
	}

	file.seekp(0, std::ios::end);
	file.write((char*)bookrecord, sizeof(bookRecords));

	file.close();
}

void ReadRecordToConsole(int record_number)
{
	bookRecords readBookRecord;

	//open file from both read and write so you can seek
	std::ifstream file("library.dat", std::ios::in | std::ios::out | std::ios::binary);

	if (file.good()) {
		file.seekg(record_number * sizeof(bookRecords), std::ios::beg);
		file.read((char*)&readBookRecord, sizeof(bookRecords));

		std::cout << readBookRecord.call_number << "\n";
		std::cout << readBookRecord.title << "\n";
		std::cout << readBookRecord.author << "\n";
		std::cout << readBookRecord.book_status << "\n";
		std::cout << readBookRecord.due_date << "\n";
		std::cout << readBookRecord.borrower << "\n";
	}
	else {
		std::cout << "Error opening file\n";
	}

	file.close();
}
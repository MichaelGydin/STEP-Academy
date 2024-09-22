#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class LogFileException : public exception {
public:
    LogFileException(const string& message) : exception(message.c_str()) {}
};

class FileDoesNotExist : public LogFileException {
public:
    FileDoesNotExist(const string& message) : LogFileException("File does not exist: " + message) {}
};

class InvalidFileFormat : public LogFileException {
public:
    InvalidFileFormat(const string& message) : LogFileException("Invalid file format: " + message) {}
};

class FileEmpty : public LogFileException {
public:
    FileEmpty(const string& message) : LogFileException("Cannot delete from empty file: " + message) {}
};

class Log {
public:
    int code;
    string message;
    string type;

    Log(int c, const string& m, const string& t) : code(c), message(m), type(t) {}
};

class LogManager {
private:
    string filePath;

    void checkFileFormat() const {
        if (filePath.substr(filePath.find_last_of(".") + 1) != "txt") {
            throw InvalidFileFormat(filePath);
        }
    }

    void checkFileExists() const {
        ifstream file(filePath);
        if (!file.is_open()) {
            throw FileDoesNotExist(filePath);
        }
    }

    void checkFileNotEmpty() const {
        ifstream file(filePath);
        if (file.peek() == ifstream::traits_type::eof()) {
            throw FileEmpty(filePath);
        }
    }

public:
    LogManager(const string& path) : filePath(path) {
        checkFileFormat();
    }

    void setFilePath(const string& newPath) {
        filePath = newPath;
        checkFileFormat();
    }

    void writeLog(const Log& log) {
        ofstream file(filePath, ios::app);
        file << log.code << " " << log.message << " " << log.type << endl;
        file.close();
    }

    void readLogs() const {
        checkFileExists();

        ifstream file(filePath);
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void copyLogs(const string& destinationPath) {
        checkFileExists();

        ifstream srcFile(filePath);
        ofstream destFile(destinationPath);

        string line;
        while (getline(srcFile, line)) {
            destFile << line << endl;
        }

        srcFile.close();
        destFile.close();
    }

    void deleteLog(int code) {
        checkFileExists();
        checkFileNotEmpty();

        ifstream file(filePath);
        ofstream tempFile("temp.txt");

        string line;
        bool logDeleted = false;
        while (getline(file, line)) {
            if (stoi(line.substr(0, line.find(' '))) != code) {
                tempFile << line << endl;
            }
            else {
                logDeleted = true;
            }
        }

        file.close();
        tempFile.close();

        if (logDeleted) {
            remove(filePath.c_str());
            rename("temp.txt", filePath.c_str());
        }
        else {
            cout << "Log with code " << code << " not found." << endl;
            remove("temp.txt");
        }
    }

    void deleteAllLogs() {
        checkFileExists();
        checkFileNotEmpty();

        ofstream file(filePath, ios::trunc);
        file.close();
    }
};

int main() {
    try {
        LogManager logManager("logs.txt");

        logManager.writeLog(Log(101, "System started", "INFO"));
        logManager.writeLog(Log(102, "User login failed", "ERROR"));
        logManager.writeLog(Log(103, "Database connection established", "INFO"));

        cout << "Logs in the file:" << endl;
        logManager.readLogs();

        logManager.copyLogs("logs_backup.txt");

        logManager.deleteLog(102);

        cout << "Logs after deletion:" << endl;
        logManager.readLogs();

        logManager.deleteAllLogs();
        cout << "All logs deleted." << endl;

    }
    catch (const LogFileException& ex) {
        cout << ex.what() << endl;
    }
}

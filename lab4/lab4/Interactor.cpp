#include "Interactor.h"
#include <map>

void Interactor::Loop() {
    while (run) {
        int t;
        cout << "\nLoad from file - \"1\""
                "\nPrint - \"2\""
                "\nUpload to file - \"3\""
                "\nAdd element - \"4\""
                "\nRemove element - \"5\""
                "\nExit - \"0\"\n";
        cin >> t;

        switch (t) {
            case (0): {
                run = false;
                break;
            }
            case (1): {
                std::string path;
                cout << "Path to file:\n";
                cin >> path;
                _fileSystem->Read(path);
                break;
            }
            case (2): {
                double limiter;
                cout << "1 - From large rating\n2 - From small rating\n";
                int mode;
                cin >> mode;
                if (mode != 1 && mode != 2) {
                    continue;
                }
                cout << "Enter the limiter (-1 - without lim)\n";
                cin >> limiter;
                if (limiter == -1 && mode == 1) {
                    PrintInfo(true, -1);
                } else if (limiter == -1 && mode == 2) {
                    PrintInfo(false, 100000000);
                } else if (mode == 1) {
                    PrintInfo(true, limiter);
                } else {
                    PrintInfo(false, limiter);
                }
                break;
            }
            case (3): {
                std::string path;
                cout << "Path to file:\n";
                cin >> path;
                _fileSystem->Write(path);
                break;
            }
            case (4): {

                std::string fullname;
                std::string birthDate;
                std::string job;
                std::string rating;

                cout << "Fullname:\n";
                std::getline(std::cin, fullname);
                if (fullname.empty())
                    std::getline(std::cin, fullname);
                cout << "Date of birth:\n";
                std::getline(std::cin, birthDate);
                cout << "Job:\n";
                std::getline(std::cin, job);
                cout << "Rating:\n";
                std::getline(std::cin, rating);

                Elections e(_fileSystem->GetNextID(),fullname, birthDate, job, rating);
                _fileSystem->Save(e);
                break;
            }
            case(5): {
                int id;
                cout<<"ID:\n";
                std::cin>>id;
                _fileSystem->Remove(id);
                break;
            }
            default:
                break;
        }
    }
}

Interactor::Interactor(ElectionsRepo *fileSystem) {
    this->_fileSystem = fileSystem;
}

void Interactor::PrintInfo(bool lgToSmall, double limiter) {
    bool singleElementFlag = false;
    map<double, set<Elections>>::iterator i;
    map<double, set<Elections>>::iterator end;

    if (lgToSmall) {
        i = _fileSystem->GetEndIterator();
        end = _fileSystem->GetBeginIterator();
        if (i != end) {
            i--;
            end--;
            if (!i->second.empty() && i == end) {
                singleElementFlag = true;
            }
        }
    } else {
        i = _fileSystem->GetBeginIterator();
        end = _fileSystem->GetEndIterator();
    }

    cout << "***BEGIN***\n";
    while (i != end && ((i->first < limiter && !lgToSmall) || (i->first > limiter && lgToSmall))) {
        for (auto s : i->second) {
            cout << s.ToString() << "\n";
        }

        if (lgToSmall) {
            i--;
        } else {
            i++;
        }
    }
    if (singleElementFlag) {
        for (auto s : i->second) {
            cout << s.ToString() << "\n";
        }
    }
    cout << "***END***\n";
}

Interactor::~Interactor() {
    delete _fileSystem;
}


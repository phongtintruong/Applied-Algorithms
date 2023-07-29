#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <queue>

struct Person {
    std::string code;
    std::string dateOfBirth;
    std::string fatherCode;
    std::string motherCode;
    char isAlive;
    std::string regionCode;
};

int main() {
    std::unordered_map<std::string, Person> database;
    std::vector<Person> people;

    // Read the input database
    std::string line;
    while (std::getline(std::cin, line) && line != "*") {
        std::istringstream iss(line);
        Person person;
        iss >> person.code >> person.dateOfBirth >> person.fatherCode >> person.motherCode >> person.isAlive >> person.regionCode;
        database[person.code] = person;
        people.push_back(person);
    }

    // Process queries
    while (std::getline(std::cin, line) && line != "***") {
        std::istringstream iss(line);
        std::string query;
        iss >> query;

        if (query == "NUMBER_PEOPLE") {
            std::cout << people.size() << std::endl;
        } else if (query == "NUMBER_PEOPLE_BORN_AT") {
            std::string date;
            iss >> date;
            int count = 0;
            for (const auto& person : people) {
                if (person.dateOfBirth == date) {
                    count++;
                }
            }
            std::cout << count << std::endl;
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            std::string code;
            iss >> code;
            std::unordered_map<std::string, int> distance;
            std::queue<std::string> q;
            q.push(code);
            distance[code] = 0;

            int maxDistance = 0;
            while (!q.empty()) {
                std::string currentCode = q.front();
                q.pop();

                const Person& currentPerson = database[currentCode];
                if (currentPerson.fatherCode != "0000000" && distance.find(currentPerson.fatherCode) == distance.end()) {
                    distance[currentPerson.fatherCode] = distance[currentCode] + 1;
                    maxDistance = std::max(maxDistance, distance[currentPerson.fatherCode]);
                    q.push(currentPerson.fatherCode);
                }
                if (currentPerson.motherCode != "0000000" && distance.find(currentPerson.motherCode) == distance.end()) {
                    distance[currentPerson.motherCode] = distance[currentCode] + 1;
                    maxDistance = std::max(maxDistance, distance[currentPerson.motherCode]);
                    q.push(currentPerson.motherCode);
                }
            }

            std::cout << maxDistance << std::endl;
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            std::string fromDate, toDate;
            iss >> fromDate >> toDate;
            int count = 0;
            for (const auto& person : people) {
                if (person.dateOfBirth >= fromDate && person.dateOfBirth <= toDate) {
                    count++;
                }
            }
            std::cout << count << std::endl;
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            std::unordered_map<std::string, int> parentsCount;
            for (const auto& person : people) {
                if (person.fatherCode != "0000000") {
                    parentsCount[person.fatherCode]++;
                }
                if (person.motherCode != "0000000") {
                    parentsCount[person.motherCode]++;
                }
            }

            int maxSubsetSize = 0;
            for (const auto& person : people) {
                if (parentsCount[person.code] == 0) {
                    maxSubsetSize++;
                }
            }
            std::cout << maxSubsetSize << std::endl;
        }
    }

    return 0;
}

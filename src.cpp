/**************************************************************************
    Class:			CSCI 3333.01 Data Structures and Algorithms
                    Fall 2025
    Project 1:		Have Fun with Lists, Vectors, Sets/Multisets, and Maps
    Name:			Abel Rodriguez
    ID:             20627502
    Description: Use respectively a list, a vector, a set / multiset,
        and a map to count word frequencies in two files and
        record the time needed.
    Input files: bible.txt, world192.txt
    Output files: list_counting.txt, vector_counting.txt,
                  set_counting.txt, map_counting.txt
    Example format of output file with a list:
        word frequencies in bible.txt
        word     frequency
        ......
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        time used to count word frequencies with a list is : xxx seconds

        word frequencies in world192.txt
        word     frequency
        ......
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        time used to count word frequencies with a list is : xxx seconds
**************************************************************************/

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

// Helper function: convert string to lowercase
string toLower(const string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to count word frequencies from a list
void countWithList(const string &file1, const string &file2, const string &output) {
    list<string> words;
    map<string, int> freq;
    ifstream inFile;
    ofstream outFile(output);
    string word;
    time_t start_time, end_time;

    start_time = time(NULL);

    // ---- First file ----
    inFile.open(file1);
    while (inFile >> word) {
        words.push_back(toLower(word));
    }
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    // ---- Second file ----
    words.clear();
    freq.clear();
    inFile.open(file2);
    while (inFile >> word) {
        words.push_back(toLower(word));
    }
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    end_time = time(NULL);

    outFile << "++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile << "Time used with list: " << difftime(end_time, start_time) << " seconds\n";
    outFile.close();
}

// Function to count word frequencies from a vector
void countWithVector(const string &file1, const string &file2, const string &output) {
    vector<string> words;
    map<string, int> freq;
    ifstream inFile;
    ofstream outFile(output);
    string word;
    time_t start_time, end_time;

    start_time = time(NULL);

    inFile.open(file1);
    while (inFile >> word) words.push_back(toLower(word));
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    words.clear();
    freq.clear();

    inFile.open(file2);
    while (inFile >> word) words.push_back(toLower(word));
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    end_time = time(NULL);

    outFile << "++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile << "Time used with vector: " << difftime(end_time, start_time) << " seconds\n";
    outFile.close();
}

// Function to count word frequencies using a multiset
void countWithMultiset(const string &file1, const string &file2, const string &output) {
    multiset<string> words;
    map<string, int> freq;
    ifstream inFile;
    ofstream outFile(output);
    string word;
    time_t start_time, end_time;

    start_time = time(NULL);

    inFile.open(file1);
    while (inFile >> word) words.insert(toLower(word));
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    words.clear();
    freq.clear();

    inFile.open(file2);
    while (inFile >> word) words.insert(toLower(word));
    inFile.close();

    for (const auto &w : words) freq[w]++;
    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    end_time = time(NULL);

    outFile << "++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile << "Time used with multiset: " << difftime(end_time, start_time) << " seconds\n";
    outFile.close();
}

// Function to count word frequencies using a map directly
void countWithMap(const string &file1, const string &file2, const string &output) {
    map<string, int> freq;
    ifstream inFile;
    ofstream outFile(output);
    string word;
    time_t start_time, end_time;

    start_time = time(NULL);

    inFile.open(file1);
    while (inFile >> word) freq[toLower(word)]++;
    inFile.close();

    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    freq.clear();

    inFile.open(file2);
    while (inFile >> word) freq[toLower(word)]++;
    inFile.close();

    for (const auto &p : freq) outFile << p.first << ": " << p.second << "\n";

    end_time = time(NULL);

    outFile << "++++++++++++++++++++++++++++++++++++++++++++++\n";
    outFile << "Time used with map: " << difftime(end_time, start_time) << " seconds\n";
    outFile.close();
}

int main()
{
 string file1 = "bible.txt";
    string file2 = "world192.txt";

    countWithList(file1, file2, "list_counting.txt");
    countWithVector(file1, file2, "vector_counting.txt");
    countWithMultiset(file1, file2, "set_counting.txt");
    countWithMap(file1, file2, "map_counting.txt");

    cout << "Word counting done! Check the output files.\n";
    return 0;
}

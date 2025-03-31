#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
using namespace std;

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    unordered_map<int, Node<T>*> nodeMap; //maps story based on the number

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string desc;
            std::string eventNumStr, leftNumStr, rightNumStr;

            // Parse description
            std::getline(ss, desc, delimiter);

            // Parse event numbers as strings first
            if (!std::getline(ss, eventNumStr, delimiter) ||
                !std::getline(ss, leftNumStr, delimiter) ||
                !std::getline(ss, rightNumStr)) {
                std::cerr << "Error: Failed to parse line: " << line << "\n";
                continue; // Skip invalid lines
                }

            //converting all strings to integers.
            try {
                int eventNum = std::stoi(eventNumStr);
                int leftNum = std::stoi(leftNumStr);
                int rightNum = std::stoi(rightNumStr);

                //for initial debugging
                //cout << "Parsed: " << desc << ", " << eventNum << ", " << leftNum << ", " << rightNum << "\n";


                Story story(desc, eventNum, leftNum, rightNum);
                Node<Story>* node = new Node<Story>(story);
                nodeMap[eventNum] = node;
            }
            catch (const std::exception& e) {
                std::cerr << "Error converting numbers in line: " << line << " (" << e.what() << ")\n";
            }
        }

        // Link nodes to form the tree
        for (auto& pair : nodeMap) {
            Story& story = pair.second->data;
            if (nodeMap.find(story.leftEventNumber) != nodeMap.end()) {
                pair.second->left = nodeMap[story.leftEventNumber];
            }
            if (nodeMap.find(story.rightEventNumber) != nodeMap.end()) {
                pair.second->right = nodeMap[story.rightEventNumber];
            }
        }

        if (nodeMap.find(0) != nodeMap.end()) {
            root = nodeMap[0];
        } else {
            std::cerr << "Error: No root node (event 0) found in the story file.\n";
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (!root) {
            std::cout << "No story loaded. Please load a story first.\n";
            return;
        }

        Node<Story>* current = root;
        while (current) {
            // Display current description
            std::cout << "\n" << current->data.description << "\n";

            // Check if it's a leaf node (no children)
            if (!current->left && !current->right) {
                break; // End of story
            }

            // Display choices
            bool hasLeftChoice = false;
            bool hasRightChoice = false;

            if (current->left) {
                //cout << "1. " << current->left->data.description << "\n";
                hasLeftChoice = true;
            }
            if (current->right) {
                //cout << "2. " << current->right->data.description << "\n";
                hasRightChoice = true;
            }

            // Get user input
            int choice;
            while (!(std::cin >> choice) ||
                   (choice == 1 && !hasLeftChoice) ||
                   (choice == 2 && !hasRightChoice) ||
                   (choice != 1 && choice != 2)) {
                std::cout << "Invalid choice. Please enter 1 or 2";
                   }

            // Display the choice made
            std::cout << "You chose: " << choice << "\n";

            // Traverse based on user input
            if (choice == 1 && current->left) {
                current = current->left;
            } else if (choice == 2 && current->right) {
                current = current->right;
            }
        }

        // End of story
        std::cout << "\nThanks for playing!\nDo you want to play again? Yes(1), No(2)";
        int option;
        std::cin>> option;
        if (option == 1) {
            playGame();
        } else if (option == 2) { cout<<"Ok Goodbye!";}
    }
};

#endif


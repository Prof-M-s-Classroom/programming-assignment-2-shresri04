[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Shreya Sridharan]`  
### **Student ID:** `[828112084]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This file contains the main function and initializes the game. It then calls all the relevant methods to load and play it.`  
- **`GameDecisionTree.h`** → `This file defines the [GameDecisionTree] class, which is for ocnstructing and traversing through the decision tree.`  
- **`Node.h`** → `This file defines the [Node] class. This class represents each decision point in the game. `  
- **`Story.h`** → `This file defines the [Story] class. This structures the event descriptions and the decision numbers. `  
- **`story.txt`** → `This file stores the game events and choices as a text file, which are then loaded into the game to be played. `
---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? 
>`The function [loadStoryFromFile] reads the file line by line. It then splits each line using delimeter of ',' into an event number, and left/right event numbers. Story objects are created and stored in the nodeMap.`
- How are nodes linked based on left and right event numbers? 
>`The nodes are linked based on their left and right numbers.` 
- What happens if an event has `-1` as left or right children?  
>`If the event has -1 as a child, it is considered a leaf node.`

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
>`The game will start at the root node and disply all user options. The player can choose 1 for left, 2 for right. If the player chooses any other number, they will get an error message to try again.`
- What happens when the player reaches a leaf node? 
>`If the player reaches a leaf node, the game ends with an ending message. `
- Explain the special case where multiple events lead to the same outcome.  
>`Some events share the same ending. For example, if you say no to your friend at the beginning, or you leave the park, you will just go home.`
---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
> `The story.txt file is read line by line using ifstream. Each line is split using std::getline() along with the delimeter. Event numnbers are then converted from strings to integers. `
- How do you ensure nodes are properly linked?  
> `Nodes are stored in an unordered map and they are linked accordingly`
- Any challenges faced while handling file input?  
>`The program was unable to locate the file with just the input of story.txt, so I included the entire file path in the input.`

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

> My program would crash if I entered any number other than one or two, so I wrote an error handling output for that. 

> Also, initially choosing option 1 went to the forest instead of park. I had to fix it by ensuring nodes were correctly linked in the nodeMap. I included a temporary debugging line that would parse each line and output it so I could know which line it was messing up on. 
---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
>`Your friend texts you to hang out. Do you say yes or no?`

- You chose: 1

>`They text back: YAY! Should we go to the park (1) or the forest (2)?`

- You chose: 2

> `Ok! See you soon! You go to the forest. Your friend isn't there yet. Do you explore (1) or text your friend (2)?`

- You chose: 1

> `You get eaten by a giant spider.`
- The story ends here.
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n) n is the number of events`  
- **Searching for an event in the tree** → `O(1) unordered map is used`  
- **Game traversal efficiency** → `O(n) n is the depth of the tree`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

> I tested the case where the file path does not exist. Displays error that file cannot be accessed. 

> Tested cases where the player entered letters or number outside the range accepted. Displays message to enter a valid number. 

>I handled cases where one node shared multiple parents. Leads to the same outcomes
---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---

// College Student Homework Management System.cpp made by Sebastian Cieslak, Syed Jaffery, and Bryce Poonai
//references used:
//https://www.geeksforgeeks.org/vector-in-cpp-stl/
//https://www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string#:~:text=Apply%20isdigit()%20function%20that,the%20value%20of%20type%20int.
//https://www.geeksforgeeks.org/how-to-clear-console-in-cpp/#
//https://www.geeksforgeeks.org/problem-with-getline-after-cin/
//https://www.walletfox.com/course/sortvectorofcustomobjects.php

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;

int Assn_Count = 0;

struct Assignment {
	//assignment parameters
	string Name = "";
	string Course = "";
	int Due = 0;
	int Weight = 0;
	bool Complete = false;
	int Assn_ID = 0;

	//default constructor
	Assignment() {
		//user input vars
		string UserInput = "";
		int UserInput2 = 0;

		system("cls"); //clear screen
		//methods for getting parameter info
		cout << endl << "Assignment Entry Tool\n";
		cout << "Enter assignment name:\n";
		getline(cin >> ws, UserInput); this->Name = UserInput;

		cout << "Enter assignment course:\n";
		getline(cin, UserInput); this->Course = UserInput;

		cout << "Enter # of days assignment is due:\n";
		while (1) { //input validation
			cin >> UserInput2;
			if (!cin.fail()) { break; }
			else cout << "Invalid input, try again\n";
		}
		this->Due = UserInput2;

		cout << "Enter weight of assignment:\n";
		while (1) { //input validation
			cin >> UserInput2;
			if (!cin.fail()) { break; }
			else cout << "Invalid input, try again\n";
		}
		this->Weight = UserInput2;
		this->Assn_ID = Assn_Count;
		Assn_Count++;
	}

	//constructor
	Assignment(string Name, string Course, int Due, int Weight, bool Complete) {
		this->Name = Name;
		this->Course = Course;
		this->Due = Due;
		this->Weight = Weight;
		this->Complete = Complete;
		this->Assn_ID = Assn_Count;
		Assn_Count++;
	}

	//update assignment
	void Update() {
		//user input vars
		string UserInput = "";
		int UserInput2 = 0;

		//methods for updating parameters
			cout << endl << "Assignment Update Tool\n";
			cout << "Enter parameter to update:\n";
			Print(); //show parameters and its values

			while (1) {//input validation
				cin >> UserInput;
				if (UserInput == "Name" || UserInput == "name") { break; }
				else if (UserInput == "Course" || UserInput == "course") { break; }
				else if (UserInput == "Due" || UserInput == "due") { break; }
				else if (UserInput == "Weight" || UserInput == "weight") { break; }
				else if (UserInput == "Complete" || UserInput == "complete") { break; }
				else { cout << "Invalid input, try again\n"; }
			}

			if (UserInput == "Name" || UserInput == "name") {
				cout << "Enter new name to update Assignment Name: " << this->Name << endl;
				getline(cin >> ws, UserInput); this->Name = UserInput;
			}
			else if (UserInput == "Course" || UserInput == "course") {
				cout << "Enter new course to update Assignment Course: " << this->Course << endl;
				getline(cin >> ws, UserInput); this->Course = UserInput;
			}
			else if (UserInput == "Due" || UserInput == "due") {
				cout << "Enter new due date to update Assignment Due: " << this->Due << " days" << endl;
				while (1) { //input validation
					cin >> UserInput2;
					if (!cin.fail()) { break; }
					else cout << "Invalid input, try again\n";
				}
				this->Due = UserInput2;
			}
			else if (UserInput == "Weight" || UserInput == "weight") {
				cout << "Enter new weight to update Assignment Weight: " << this->Weight << endl;
				while (1) { //input validation
					cin >> UserInput2;
					if (!cin.fail()) { break; }
					else cout << "Invalid input, try again\n";
				}
				this->Weight = UserInput2;
			}
			else if (UserInput == "Complete" || UserInput == "complete") {
				cout << "Enter new complete status for Assignment Complete: " << this->Complete << endl;
				cout << "Is the assignment complete?(Y/N)\n";
				while (1) { //input validation
					cin >> UserInput;
					if (UserInput == "Y" || UserInput == "y") { this->Complete = true; break; }
					else if (UserInput == "N" || UserInput == "n") { this->Complete = false; break; }
					else cout << "Invalid input, try again\n";
				}
			}
	}

	//print assignment
	void Print() {
		cout << "- Name: " << this->Name << endl;
		cout << "- Course: " << this->Course << endl;
		cout << "- Due: " << this->Due << endl;
		cout << "- Weight: " << this->Weight << endl;
		cout << "- Complete: " << this->Complete << endl;
		cout << "- ID: " << this->Assn_ID << endl;
	}

};

//sort comparison function (to sort by parameter)
struct Comparison {
	string Parameter;
	Comparison(string Parameter) { this->Parameter = Parameter; }
	bool operator()(const Assignment& a, const Assignment& b) const {
		if (Parameter == "Name") {
			return a.Name < b.Name;
		}
		else if (Parameter == "Course") {
			return a.Course < b.Course;
		}
		else if (Parameter == "Due") {
			return a.Due < b.Due;
		}
		else if (Parameter == "Weight") {
			return a.Weight < b.Weight;
		}
		else if (Parameter == "Complete") {
			return a.Complete < b.Complete;
		}
	}
};


//add assignment
void Add(vector<Assignment>& Assignments) {
	Assignment* NewAssignment = new Assignment; //init with default constructor
	Assignments.push_back(*NewAssignment);	//save new entry
}

//add assignment (with parameters)
void Add(vector<Assignment>& Assignments, string Name, string Course, int Due, int Weight, bool Complete) {
	Assignment* NewAssignment = new Assignment(Name, Course, Due, Weight, Complete); //init with default constructor
	Assignments.push_back(*NewAssignment);	//save new entry
}

//search tool (by due, by course, by complete)
void Search(vector<Assignment>& Assignments) {
	string UserInput;
	int UserInput2 = 0;
	vector<int> tempVector;

	//methods for Search
	while (1) {
		system("cls"); //clear screen
		cout << "Assignment Search Tool\n";
		cout << "Search Parameters:\n";
		cout << "- Name\n- Course\n- Due\n- Complete\n";

		while (1) {//input validation
			cin >> UserInput;
			if (UserInput == "Name" || UserInput == "name") { break; }
			else if (UserInput == "Course" || UserInput == "course") { break; }
			else if (UserInput == "Due" || UserInput == "due") { break; }
			else if (UserInput == "Complete" || UserInput == "complete") { break; }
			else { cout << "Invalid input, try again\n"; }
		}

		//Name Search
		if (UserInput == "Name" || UserInput == "name") {
			cout << "Enter assignment name to search:\n";
			cin >> UserInput;
			for (int i = 0; i < Assignments.size(); i++) {
				if (Assignments.at(i).Name == UserInput) {
					tempVector.push_back(i); //save position of element that matches search criteria
				}
			}
			//print search results
			cout << "Matches found: " << tempVector.size() << endl;
			for (int i = 0; i < tempVector.size(); i++) {
				Assignments.at(tempVector.at(i)).Print();
				cout << endl;
			}
		}

		//Course Search
		else if (UserInput == "Course" || UserInput == "course") {
			cout << "Enter course name to search:\n";
			cin >> UserInput;
			for (int i = 0; i < Assignments.size(); i++) {
				if (Assignments.at(i).Course == UserInput) {
					tempVector.push_back(i); //save position of element that matches search criteria
				}
			}
			//print search results
			cout << "Matches found: " << tempVector.size() << endl;
			for (int i = 0; i < tempVector.size(); i++) {
				Assignments.at(tempVector.at(i)).Print();
				cout << endl;
			}
		}

		//Due Search
		else if (UserInput == "Due" || UserInput == "due") {
			cout << "Enter days due to search:\n";
			cin >> UserInput2;
			for (int i = 0; i < Assignments.size(); i++) {
				if (Assignments.at(i).Due <= UserInput2) {
					tempVector.push_back(i); //save position of element that matches search criteria
				}
			}
			//print search results
			cout << "Matches found: " << tempVector.size() << endl;
			for (int i = 0; i < tempVector.size(); i++) {
				Assignments.at(tempVector.at(i)).Print();
				cout << endl;
			}
		}

		//Complete Search
		else if (UserInput == "Complete" || UserInput == "complete") {
			bool boolSearch = false;

			cout << "Show Complete or Incomplete assignments:\n";
			while (1) {//input validation
				cin >> UserInput;
				if (UserInput == "Complete" || UserInput == "complete") {
					boolSearch = true;
					break;
				}
				else if (UserInput == "Incomplete" || UserInput == "incomplete") {
					boolSearch = false;
					break;
				}
			}

			for (int i = 0; i < Assignments.size(); i++) {
				if (Assignments.at(i).Complete == boolSearch) {
					tempVector.push_back(i); //save position of element that matches search criteria
				}
			}

			//print search results
			cout << "Matches found: " << tempVector.size() << endl;
			for (int i = 0; i < tempVector.size(); i++) {
				Assignments.at(tempVector.at(i)).Print();
				cout << endl;
			}

		}

		cout << "Search again?(y/n)\n";
		while (1) { //input validation
			cin >> UserInput;
			if (UserInput == "Y" || UserInput == "y") { break; }
			else if (UserInput == "N" || UserInput == "n") { break; }
			else cout << "Invalid input, try again\n";
		}
		if (UserInput == "N" || UserInput == "n") { break; }
		//if yes, let main while loop repeat and reset tempVector
		tempVector.clear();
	}

}

//Recursive print method
void printVector(vector<Assignment>::iterator begin, vector<Assignment>::iterator end) {
	if (begin != end) {
		cout << *begin << endl;
		printVector(++begin, end);
	}
}

//print(with sort: by due, name(alphabetical), course(alpabetical), weight, complete
void Print(vector<Assignment> &Assignments) {
	string UserInput;
	int UserInput2 = 0;

	while (1) {
		system("cls"); //clear screen
		vector<Assignment> tempAssignments = Assignments; //create copy of original vector
		cout << "Assignment Print Tool\n";
		cout << "Sort assignments by:\n";
		cout << "- Name\n- Course\n- Due\n- Weight\n- Complete\n- None(don't sort)\n";

		while (1) {//input validation
			cin >> UserInput;
			if (UserInput == "Name" || UserInput == "name") { break; }
			else if (UserInput == "Course" || UserInput == "course") { break; }
			else if (UserInput == "Due" || UserInput == "due") { break; }
			else if (UserInput == "Weight" || UserInput == "weight") { break; }
			else if (UserInput == "Complete" || UserInput == "complete") { break; }
			else if (UserInput == "None" || UserInput == "none") { break; }
			else { cout << "Invalid input, try again\n"; }
		}

		//sort by parameter, 3rd field uses the Comparison struct to do parameter comparison of Assignment elements for the sort algorithm
		if (UserInput == "Name" || UserInput == "name") {
			sort(tempAssignments.begin(), tempAssignments.end(), Comparison("Name"));
			cout << "Sorted by: Name\n";
		}
		else if (UserInput == "Course" || UserInput == "course") {
			sort(tempAssignments.begin(), tempAssignments.end(), Comparison("Course"));
			cout << "Sorted by: Course\n";
		}
		else if (UserInput == "Due" || UserInput == "due") {
			sort(tempAssignments.begin(), tempAssignments.end(), Comparison("Due"));
			cout << "Sorted by: Due\n";
		}
		else if (UserInput == "Weight" || UserInput == "weight") {
			sort(tempAssignments.begin(), tempAssignments.end(), Comparison("Weight"));
			cout << "Sorted by: Weight\n";
		}
		else if (UserInput == "Complete" || UserInput == "complete") {
			sort(tempAssignments.begin(), tempAssignments.end(), Comparison("Complete"));
			reverse(tempAssignments.begin(), tempAssignments.end());
			cout << "Sorted by: Complete\n";
		}
		else if (UserInput == "None" || UserInput == "none") {
			cout << "Sorted by: Unsorted\n";
			//no sort
		}

		//print resultant vector (Recursion)
		printVector(tempAssignments.begin(), tempAssignments.end()); 

		cout << "Print again?(y/n)\n";
		while (1) { //input validation
			cin >> UserInput;
			if (UserInput == "Y" || UserInput == "y") { break; }
			else if (UserInput == "N" || UserInput == "n") { break; }
			else cout << "Invalid input, try again\n";
		}
		if (UserInput == "N" || UserInput == "n") { break; }
		//if yes, let main while loop repeat
	}
}

//update assignment
void Update(vector<Assignment>& Assignments) {
	string UserInput;
	int UserInput2 = 0;
	int Position = 0;

	while (1) {
		system("cls"); //clear screen
		cout << "Assignment Update Tool\n";
		cout << "Print assignments?(y/n) (you need to know your assignment ID in order to make an update)\n";
		while (1) {
			cin >> UserInput;
			if (UserInput == "Y" || UserInput == "y") { break; }
			else if (UserInput == "N" || UserInput == "n") { break; }
			else cout << "Invalid input, try again\n";
		}
		if (UserInput == "Y" || UserInput == "y") { Print(Assignments); system("cls"); }
		cout << "Enter assignment ID:\n";
		while (1) { //input validation
			cin >> UserInput2;
			if (!cin.fail()) { break; }
			else cout << "Invalid input, try again\n";
		}

		//find position of desired assignment
		for (int i = 0; i < Assignments.size(); i++) {
			if (Assignments.at(i).Assn_ID == UserInput2) {
				Position = i;
			}
		}
		Assignments.at(Position).Update();
		cout << "Update again?(y/n)\n";
		while (1) { //input validation
			cin >> UserInput;
			if (UserInput == "Y" || UserInput == "y") { break; }
			else if (UserInput == "N" || UserInput == "n") { break; }
			else cout << "Invalid input, try again\n";
		}
		if (UserInput == "N" || UserInput == "n") { break; }
		//if yes, let main while loop repeat
	}
}

//delete completed assignments
void Clear(vector<Assignment>& Assignments) {
	int i = 0;
	while (i < Assignments.size()) { //iterate through vector
		if (Assignments.at(i).Complete == true) {
			Assignments.erase(Assignments.begin() + i);
			i--; //if element is removed, the next element will shift into this place. check this position again
		}
		i++;
	}
}

//save to file
void Save(vector<Assignment>& Assignments) {
	ofstream SaveFile("Assignments_Backup.txt"); //create and open a text file

	for (int i = 0; i < Assignments.size(); i++) { //write to file, with comma delimters (so we can read file to program later)
		SaveFile << Assignments.at(i).Name << ",";
		SaveFile << Assignments.at(i).Course << ",";
		SaveFile << Assignments.at(i).Due << ",";
		SaveFile << Assignments.at(i).Weight << ",";
		SaveFile << Assignments.at(i).Complete << "," <<endl;
	}

	SaveFile.close();
}

//read from file
void Read(vector<Assignment>& Assignments) {
	string TextLine;

	ifstream ReadFile("Assignments_Backup.txt"); //read file

	while (getline(ReadFile, TextLine)) {
		int i = 0;
		vector<char> v(TextLine.begin(), TextLine.end());
		vector<string> s;
		while (i < v.size()) {//iterate through vector
			if (v.at(i) == ',') { 
				string Temp(v.begin(), v.begin() + i); //convert range of chars inbetween delimiters into string
				s.push_back(Temp);
				v.erase(v.begin(), v.begin() + i + 1);
				i = 0;
			} 
			i++;
		}
		Add(Assignments, s.at(0), s.at(1), stoi(s.at(2)), stoi(s.at(3)), stoi(s.at(4))); //use constructor to add Assignment with derived paramater-fields, stoi(string to int) conversions done where needed
	}

	ReadFile.close(); //end of read file
}

int main()
{
	string UserInput;
	vector<Assignment> Assignments; //pointer to vector (so we can pass into functions)
	Add(Assignments, "Webassign", "MTH322", 5, 1, true);
	Add(Assignments, "Discussion Board", "ART200", 3, 1, false);
	Add(Assignments, "Lab2", "EET441", 12, 3, true);
	Add(Assignments, "Final Quiz", "Art200", 2, 5, true);

	//menu
	while (1) {
		system("cls"); //clear screen
		cout << "HOMEWORK MANAGEMENT SYSTEM\n";
		cout << "Menu options:\n";
		cout << "- Add (add assignment)\n- Update(update assignment)\n- Clear(delete completed assignments)\n- Search\n- Print\n- Save(save to file)\n- Read(read from file)\n- Exit\n";

		while (1) {//input validation
			cin >> UserInput;
			if (UserInput == "Add" || UserInput == "add") { break; }
			else if (UserInput == "Update" || UserInput == "update") { break; }
			else if (UserInput == "Clear" || UserInput == "clear") { break; }
			else if (UserInput == "Search" || UserInput == "search") { break; }
			else if (UserInput == "Print" || UserInput == "print") { break; }
			else if (UserInput == "Save" || UserInput == "save") { break; }
			else if (UserInput == "Read" || UserInput == "read") { break; }
			else if (UserInput == "Exit" || UserInput == "exit") { break; }
			else { cout << "Invalid input, try again\n"; }
		}

		//menu commands
		if (UserInput == "Add" || UserInput == "add") {
			Add(Assignments);
		}
		else if (UserInput == "Update" || UserInput == "update") {
			Update(Assignments);
		}
		else if (UserInput == "Clear" || UserInput == "clear") {
			Clear(Assignments);
		}
		else if (UserInput == "Search" || UserInput == "search") {
			Search(Assignments);
		}
		else if (UserInput == "Print" || UserInput == "print") {
			Print(Assignments);
		}
		else if (UserInput == "Save" || UserInput == "save") {
			Save(Assignments);
		}
		else if (UserInput == "Read" || UserInput == "read") {
			Read(Assignments);
		}
		else if (UserInput == "Exit" || UserInput == "exit") {
			return 1;
		}
	}
	return 1;
}


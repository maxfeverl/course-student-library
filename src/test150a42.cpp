// ask4hy150a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
void command_prompt() {
	cout << "\n------------------------------------\n";
	cout << "Commands: \n\n";
	cout << char(254) << " insert_course \n" << char(254) << " insert_course_from_file [filename] \n" << char(254);
	cout << " insert_student \n";
	cout << char(254) << " insert_student_from_file [filename]\n" << char(254) << " enroll [course_code][student_id]\n";
	cout << char(254) << " disenroll [course_code][student_id]\n" << char(254) << " enrolled_in_course [course_code]\n";
	cout << char(254) << " add_grade\n" << char(254) << " print_students [student_id]\n" << char(254) << " course_stats [course_code]\n";
	cout << "------------------------------------\n\n";
	cout << "Input : ";
}

class course
{
private:

	string course_name;
	string course_value;
	string course_ID;

public:
	void insert_course(string str1, string str2, string val);
	void insert_course_from_file(string str);
	void print_course();
	int check(string str);
	int check_under_grad_course(string str) {

		if (str == course_ID) {
			if (course_value == "undergraduate")return 1;
			else return 0;
		}
	}
	void retur(string str)
	{
		if (str == course_ID)
		{
			cout <<"Course name : "<< course_name<<endl;
		}
	}

};

void course::insert_course(string str1, string str2, string val) {
	course_name = str1;
	course_value = str2;
	course_ID = val;

}

void course::print_course() {
	cout << course_name;
	cout << "," << course_ID;
	cout << "," << course_value << endl;
}

void course::insert_course_from_file(string str) {

	int count = 0, count1, p = 0;
	string line, temp;
	ifstream myfile(str);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (int i = 0; i < line.size(); i++) if (line[i] == ',')count++;
			if (count != 2) { cout << "Wrong input"; exit(1); }
			count = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != ',')
				{
					count++;
					if (p == 2)
					{
						temp = line.substr(i, line.size() - i);
						for (int j = 0; j < temp.size(); j++)
						{
							if (temp[j] == '\t') { temp.erase(j, 1); }
							else break;
						}
						p = 0; course_ID = temp; break;
					}
				}
				else {
					temp = line.substr(i - count, count); count = 0;
					for (int k = 0; k < temp.size(); k++)
					{
						if (temp[k] == '\t') { temp.erase(k, 1); }
						else break;
					}
					if (p == 0) { course_name = temp; p++; }
					else if (p == 1) { course_value = temp; p++; count1 = i; }

				}
			}
			count = 0;
			cout << course_name << "," << course_value << "," << course_ID << endl;
		}
	}
	else cout << "Unable to open file";
}

int course::check(string str)
{

	if (course_ID == str || course_name == str || course_value == str)return 1;

}

class student
{
private:

	string student_name;
	string student_ID;
	string student_Value;

public:

	void insert_student(string str1, string str2, string val);
	void insert_student_from_file(string str);
	void student::print_student();
	int check(string str);
	int check_under_grad_stud(string str) {

		if (str == student_ID) {
			if (student_Value == "undergraduate")return 1;
			else return 0;
		}
	}


};

int student::check(string str)
{

	if (student_ID == str || student_name == str || student_Value == str)return 1;

}

void student::print_student() {
	cout << student_name;
	cout << "," << student_ID;
	cout << "," << student_Value << endl;
}

class undergraduate_student : public student
{
private:

	string enrolled_student;
	string enrolled_class;

public:

	void enroll(string str, string str1)
	{
		enrolled_class = str;
		enrolled_student = str1;
		
	}

	int check(string str, string str1)
	{
		if (enrolled_class == str&&enrolled_student == str1)
		{
			 return 0;
		}
		return 1;
	}
	
	int check_enroll_under(string str)
	{
		if (enrolled_class == str)
		{
			return 1;
		}
		else return 0;
	}

	void printunder()
	{
		cout << enrolled_class<<",";
		cout << enrolled_student << endl;
	}

	void retur_enroll_under(string str)
	{
		if (enrolled_class == str)
		{
			cout << enrolled_student << endl;
		}
	}

	undergraduate_student new_under(string str,string str1) {

		undergraduate_student *p1;
		p1 = new undergraduate_student;
		p1->enroll(str,str1);
		return *p1;
	}

};

class graduate_student : public student
{
private:

	string enrolled_student;
	string enrolled_class;

public:

	void enroll(string str, string str1)
	{
		enrolled_class = str;
		enrolled_student = str1;
		
	}

	int check(string str, string str1)
	{
		if (enrolled_class == str&&enrolled_student == str1)
		{
			 return 0;
		}
		return 1;
	}

	int check_enroll_grad(string str)
	{
		if (enrolled_class == str)
		{
			return 1;
		}
		else return 0;
	}

	void retur_enroll_grad(string str)
	{
		if (enrolled_class == str)
		{
			cout << enrolled_student << endl;
		}
	}

	void printgrad()
	{
		cout << enrolled_class << ",";
		cout << enrolled_student << endl;
	}

	graduate_student new_grad(string str, string str1) {

		graduate_student *p1;
		p1 = new graduate_student;
		p1->enroll(str, str1);
		return *p1;
	}


	string retur(string str) {
		if (enrolled_student == str)
			return enrolled_class;
	}

};

void student::insert_student(string str1, string str2, string val)
{
	student_name = str1;
	student_ID = str2;
	student_Value = val;
}

void student::insert_student_from_file(string str)
{
	int count = 0, count1, p = 0;
	string line, temp;
	ifstream myfile(str);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (int i = 0; i < line.size(); i++) if (line[i] == ',')count++;
			if (count != 2) { cout << "Wrong input"; exit(1); }
			count = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != ',')
				{
					count++;
					if (p == 2)
					{
						temp = line.substr(i, line.size() - i);
						for (int j = 0; j < temp.size(); j++)
						{
							if (temp[j] == '\t') { temp.erase(j, 1); }
							else break;
						}
						p = 0; student_Value = temp; break;
					}
				}
				else {
					temp = line.substr(i - count, count); count = 0;
					for (int k = 0; k < temp.size(); k++)
					{
						if (temp[k] == '\t') { temp.erase(k, 1); }
						else break;
					}
					if (p == 0) { student_name = temp; p++; }
					else if (p == 1) { student_ID = temp; p++; count1 = i; }

				}
			}
			count = 0;
			cout << student_name << "," << student_ID << "," << student_Value << endl;
		}
	}
	else cout << "Unable to open file";
}


int main() {

	string input, input2, input3, course_name, course_val, course_ID,course_ID1,course_ID2, tempcour, tempstud,tempname,tempgrade;
	int i = 0, p = 0, k = 0, count,count2=0,count3=0,check,grade;
	vector<course>course_info;
	vector<student>student_info;
	vector<undergraduate_student>enrollunder_info;
	vector<graduate_student>enrollgrad_info;
	vector<string>grades_info;
	undergraduate_student under;
	graduate_student grad;
	course *init;
	student *stud;
	tempgrade = "1as23";
	
	while (1)
	{
		p = 0;
		tempcour = "\0", tempstud = "\0";
		command_prompt();
		getline(cin, input);
		if (input == "insert_course")
		{
			init = new course;
			cout << "Type the name of the course : ";
			getline(cin, course_name);
			cout << "Type the ID of the course : ";
			getline(cin, course_ID);
			cout << "Type the value of the course : ";
			getline(cin, course_val);
			init->insert_course(course_name, course_ID, course_val);
			course_info.push_back(*init);

		}
		else if (input == "insert_course_from_file")
		{
			int count = 0, count1, p = 0;
			string line, temp;
			ifstream myfile("test.csv");
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					for (int i = 0; i < line.size(); i++) if (line[i] == ',')count++;
					if (count != 2) { cout << "Wrong input"; exit(1); }
					count = 0;
					for (int i = 0; i < line.size(); i++) {
						if (line[i] != ',')
						{
							count++;
							if (p == 2)
							{
								temp = line.substr(i, line.size() - i);
								for (int j = 0; j < temp.size(); j++)
								{
									if (temp[j] == '\t') { temp.erase(j, 1); }
									else break;
								}
								p = 0; course_ID = temp; break;
							}
						}
						else {
							temp = line.substr(i - count, count); count = 0;
							for (int k = 0; k < temp.size(); k++)
							{
								if (temp[k] == '\t') { temp.erase(k, 1); }
								else break;
							}
							if (p == 0) { course_name = temp; p++; }
							else if (p == 1) { course_val = temp; p++; count1 = i; }

						}
					}
					count = 0;
					init = new course;
					init->insert_course(course_name, course_ID, course_val);
					course_info.push_back(*init);
				}
			}
			else cout << "Unable to open file";

		}
		else if (input == "insert_student")
		{
			stud = new student;
			cout << "Type the name of the student : ";
			getline(cin, course_name);
			cout << "Type the ID of the student : ";
			getline(cin, course_ID);
			cout << "Type the value of the student : ";
			getline(cin, course_val);
			stud->insert_student(course_name, course_ID, course_val);
			student_info.push_back(*stud);


		}
		else if (input == "insert_student_from_file")
		{
			int count = 0, count1, p = 0;
			string line, temp;
			ifstream myfile("test_student.csv");
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					for (int i = 0; i < line.size(); i++) if (line[i] == ',')count++;
					if (count != 2) { cout << "Wrong input"; exit(1); }
					count = 0;
					for (int i = 0; i < line.size(); i++) {
						if (line[i] != ',')
						{
							count++;
							if (p == 2)
							{
								temp = line.substr(i, line.size() - i);
								for (int j = 0; j < temp.size(); j++)
								{
									if (temp[j] == '\t') { temp.erase(j, 1); }
									else break;
								}
								p = 0; course_ID = temp; break;
							}
						}
						else {
							temp = line.substr(i - count, count); count = 0;
							for (int k = 0; k < temp.size(); k++)
							{
								if (temp[k] == '\t') { temp.erase(k, 1); }
								else break;
							}
							if (p == 0) { course_name = temp; p++; }
							else if (p == 1) { course_val = temp; p++; count1 = i; }

						}
					}
					count = 0;
					stud = new student;
					stud->insert_student(course_name, course_val, course_ID);
					student_info.push_back(*stud);
				}
			}
			else cout << "Unable to open file";

		}
		else if (input.compare(0, 7, "enroll ") == 0 && input.size() > 9)
		{
			count = 0;
			for (int i = 0; i < input.size(); i++)if (input[i] == ' ') { p++; }
			if (p != 2) { cout << "Wrong input\n"; }
			else
			{
				for (int j = 7; j < input.size(); j++)
				{
					if (isalnum(input[j]) && p != 0)tempcour = tempcour + input[j];
					else p = 0;
					if ((isalnum(input[j])) && p == 0)tempstud = tempstud + input[j];
				}
				cout << tempcour << " " << tempstud << endl;
				
			}
			count = 0;
			if (course_info.size() != 0 && student_info.size() != 0)
			{
				count = 0;
				for (int i = 0; i < course_info.size(); i++) if (course_info[i].check(tempcour) == 1)count ++;
				for (int i = 0; i < student_info.size(); i++)if (student_info[i].check(tempstud) == 1)count ++;
				if (count == 2)
				{
					count = 0;
					for (int i = 0; i < student_info.size(); i++)
						if (student_info[i].check_under_grad_stud(tempstud) == 1)
						{
							if (enrollunder_info.size() == 0)
							{
								enrollunder_info.push_back(under.new_under(tempcour, tempstud)); break;
							}
							else
							{
								for (int j = 0; j < enrollunder_info.size(); j++)
									if (enrollunder_info[j].check(tempcour, tempstud) == 1)
									{
										enrollunder_info.push_back(under.new_under(tempcour, tempstud)); break;
									}
									else {cout << "Already in!"; break;}
							}

						}
						else if (student_info[i].check_under_grad_stud(tempstud) == 0)
						{
							if (enrollgrad_info.size() == 0)
							{
								for (int k = 0; k < course_info.size(); k++)
									if (course_info[k].check_under_grad_course(tempcour) == 0)
									{
										enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud)); break;
									}
									else if (course_info[k].check_under_grad_course(tempcour) == 1)
									{
										enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud)); count2++; break;
									}
								
							}
							else
							{
								check = 0;
								for (int j = 0; j < enrollgrad_info.size(); j++)if (enrollgrad_info[j].check(tempcour, tempstud) == 0) { check = 1; }
									if (check == 0)
									{
										for (int k = 0; k < course_info.size(); k++)
											if (course_info[k].check_under_grad_course(tempcour)==0)
											{
												
												enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud)); break;
											}
											else if(course_info[k].check_under_grad_course(tempcour) == 1)
											{
											
												if (count2 == 2) 
												{
													
													
													cout << "You are enrolled in 2 undergraduate course already\n";
													cout << "Do you want to disenroll from 1 to add the one you entered?\n";
													cout << "Type y for yes or n for no\n";
													cout << "Input : ";
													getline(cin, input2);
													if (input2 == "n")break;
													else if (input2 == "y")
													{
														
														cout << "You are enrolled in the following undergraduate courses : ";
														for (int l = 0; l < enrollgrad_info.size(); l++)
														{
															course_ID = enrollgrad_info[l].retur(tempstud);
															for (int y = 0; y < course_info.size(); y++)
																if (course_info[y].check_under_grad_course(course_ID) == 1 && count3 == 0) { cout << course_ID << "|"; course_ID1 = course_ID; count3++; }
																else if (course_info[y].check_under_grad_course(course_ID) == 1 && count3 == 1) { cout << course_ID; course_ID2 = course_ID; break; }
																
														}
														count3 = 0;
														cout << "\nEnter the one you want to disenroll from ";
														while (1) {
															cout << "Input : ";
															getline(cin, input2);
															if (course_ID1 == input2)
															{
																
																for (int l = 0; l < enrollgrad_info.size(); l++)
																	if (enrollgrad_info[l].check(course_ID1, tempstud) == 0)
																		enrollgrad_info.erase(enrollgrad_info.begin()+l);
																enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud));
																break;
															}
															else if (course_ID2 == input2)
															{
																
																for (int l = 0; l < enrollgrad_info.size(); l++)
																	if (enrollgrad_info[l].check(course_ID2, tempstud) == 0)
																		enrollgrad_info.erase(enrollgrad_info.begin() + l);
																enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud));
																break;
															}
															else cout << "Wrong input\n";
														}
													}
												
												}
												else
												{
													enrollgrad_info.push_back(grad.new_grad(tempcour, tempstud)); count2++; break;
												}
												count = 0;
											}
										
									}
									else { cout << "Already in!\n"; break; }
							}
						}
				}
				else cout << "No student or course found\n";
		    }
			else cout << "Wrong input\n";

		}
		else if (input.compare(0, 10, "disenroll ") == 0 && input.size() > 12)
		{
			count = 0;
			for (int i = 0; i < input.size(); i++)if (input[i] == ' ') { p++; }
			if (p != 2) { cout << "Wrong input\n"; }
			else
			{
				for (int j = 10; j < input.size(); j++)
				{
					if (isalnum(input[j]) && p != 0)tempcour = tempcour + input[j];
					else p = 0;
					if ((isalnum(input[j])) && p == 0)tempstud = tempstud + input[j];
				}
				cout << tempcour << "|" << tempstud << endl;

			}
			if (course_info.size() != 0 && student_info.size() != 0) 
			{
				for (int i = 0; i < enrollunder_info.size(); i++)if (enrollunder_info[i].check(tempcour, tempstud) == 0)count = 1;
				for (int i = 0; i < enrollgrad_info.size(); i++)if (enrollgrad_info[i].check(tempcour, tempstud) == 0)count = 2;
				if (count == 1)
				{
					for (int l = 0; l < enrollunder_info.size(); l++)
						if (enrollunder_info[l].check(tempcour, tempstud) == 0)
							enrollunder_info.erase(enrollunder_info.begin() + l);

				}
				else if (count == 2)
				{
					for (int l = 0; l < enrollgrad_info.size(); l++)
						if (enrollgrad_info[l].check(tempcour, tempstud) == 0)
							enrollgrad_info.erase(enrollgrad_info.begin() + l);
					count2--;

				}
				else if (count == 0)
				{
					cout << "Not found!\n";
				}
			}
			else cout << "No enrolled students!\n";

		}
		else if (input.compare(0, 19, "enrolled_in_course ") == 0 && input.size() > 19)
		{
			count = 0;
			for (int i = 0; i < input.size(); i++)if (input[i] == ' ') { p++; }
			if (p != 1) { cout << "Wrong input\n"; }
			else
			{
				for (int j = 19; j < input.size(); j++)
				{
					if (isalnum(input[j]) && p != 0)tempcour = tempcour + input[j];
					else p = 0;
					
				}
				cout << tempcour << endl;

			}
			if (course_info.size() != 0 && student_info.size() != 0)
			{
				for (int i = 0; i < course_info.size(); i++)if (course_info[i].check(tempcour) == 1)count = 1;
				if (count == 1)
				{
					count = 0;
					for (int i = 0; i < course_info.size(); i++)
						course_info[i].retur(tempcour);
					cout << "Course ID : " << tempcour << endl;
					if (enrollunder_info.size() != 0) 
					{
						for (int i = 0; i < enrollunder_info.size(); i++)
							if (enrollunder_info[i].check_enroll_under(tempcour) == 1)count++;
					}
					if (enrollgrad_info.size() != 0) 
					{
						for (int i = 0; i < enrollgrad_info.size(); i++)
							if (enrollgrad_info[i].check_enroll_grad(tempcour) == 1)count++;
					}
					cout << "Number of enrolled students : " << count << endl;
					cout << "Student enrolled : " << endl;
					for (int i = 0; i < enrollunder_info.size(); i++)enrollunder_info[i].retur_enroll_under(tempcour);
					for (int i = 0; i < enrollgrad_info.size(); i++)enrollgrad_info[i].retur_enroll_grad(tempcour);
					cout << endl;
					count = 0;
				}
				else cout << "No course with that ID\n";


			}
			else cout << "No enrolled students\n";
		}
		else if (input == "add_grade")
		{
			count = 0;
			cout << "Type the student ID : ";
			getline(cin, tempstud);
			cout << endl << "Type the course ID : ";
			getline(cin, tempcour);
			cout << endl << "Type the grade : ";
			getline(cin, tempgrade);
			    for (int i = 0; i < tempgrade.size(); i++)if (!isdigit(tempgrade[i]))count++;
	
			    if(count!=0)
			    {
					cout << "Please enter digits!!!\n";
				}
				else
				{
					cout << endl;

					for (int i = 0; i < enrollunder_info.size(); i++)
						if (enrollunder_info[i].check(tempcour, tempstud) == 0)count++;
					for (int i = 0; i < enrollgrad_info.size(); i++)
						if (enrollgrad_info[i].check(tempcour, tempstud) == 0)count++;
					if (count != 0)
					{
						tempgrade = tempcour + " " + tempstud + " " + tempgrade;
						grades_info.push_back(tempgrade);




					}
					else cout << "No enrolled ID's found\n";
				}
		}

		else if (input == "print") {

			for (int i = 0; i < course_info.size(); i++)
				course_info[i].print_course();
			for (int i = 0; i < student_info.size(); i++)
				student_info[i].print_student();
			for (int i = 0; i < enrollgrad_info.size(); i++)
				enrollgrad_info[i].printgrad();
			for (int i = 0; i < enrollunder_info.size(); i++)
				enrollunder_info[i].printunder();

		}
		else cout << "Wrong input\n" << endl;


		cout << endl << course_info.size() << endl << student_info.size() << endl << enrollunder_info.size() << endl << enrollgrad_info.size();


		if (input == "q") return 0;




	}








	return 0;
}


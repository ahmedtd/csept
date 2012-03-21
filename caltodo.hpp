#ifndef CALTODO
#define CALTODO

#include <stdlib.h>
#include<iostream>

using namespace std;

class Caltodo
{
// outline of class for a Caltodo - does not use iCal lib yet
public:

	Caltodo(string descriptionInput){

		description = descriptionInput;
		isCompleted = false;
	}

	string getDueDate(){
		return dueDate;
	}

	string getDescription(){
		return description;
	}

	bool getIsCompleted(){
		return isCompleted;
	}

	string getCategories(){
		return categories;
	}


	void setDescription(string descriptionInput){
		description = descriptionInput;
	}

	void setDueDate(string dueDateInput){
		dueDate = dueDateInput;
	}

	void setCategories(string categoriesInput){
		categories = categoriesInput;
	}

	void setIsCompleted(bool isCompletedInput){
		isCompleted=isCompletedInput;
	}

	void toggleCompleted();
	void editTodo();


private:
	string dueDate;
	string description; 
	bool isCompleted;
	string categories;
    
};
    


void Caltodo::toggleCompleted(){

	if(getIsCompleted() == false)
		setIsCompleted(true);
	else
		setIsCompleted(false);
}

void Caltodo::editTodo(){
	string reply;
	cout<<"\nEdit due date? (Y/N) ";
	cin>>reply;
	if(reply == "Y"){
		cout<<"\nNew due date: ";
		string duedate;
		cin>>duedate;
		setDueDate(duedate);
	}

	cout<<"\nEdit assignment description? (Y/N) ";
	cin>>reply;
	if(reply == "Y"){
		cout<<"\nNew assignment description: ";
		string description;
		cin>>description;
		setDescription(description);
	}

	cout<<"\nEdit completed status? (Y/N) ";
	cin>>reply;
	if(reply == "Y"){
		toggleCompleted();
		cout<<"\nAssignment is now ";
		if(getIsCompleted()==false)
			cout<<"not finished.";
		else
			cout<<"finished.";
	}

	cout<<"\nEdit category/event attached to? (Y/N) ";
	cin>>reply;
	if(reply == "Y"){
		cout<<"\nNew category: ";
		string category;
		cin>>category;
		setCategories(category);
	}

}


#endif
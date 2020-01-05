#include <stdio.h>
#include <stdlib.h>
#include "Patients.h"
#include "Doctors.h"


int mainWindow() {
	int option = 0;
	do {
		system("cls");
		printf("**************************************************\n");
		printf("***  Managment System of the Private Hospital  ***\n");
		printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
		printf("**************************************************\n");
		printf("	1. ADMINISTRATION\n");
		printf("	2. RECEPTION\n\n\n\n");
		printf("	0. EXIT\n");
		printf("**************************************************\n\n");
		printf("Choose your option: ");
		scanf_s("%d", &option);
	} while (option > 3 || option < 0);
	return option;
}

//Administration part of the program

int adminWindow() {
	int option = 0;
	do {
		system("cls");
		printf("**************************************************\n");
		printf("***  Managment System of the Private Hospital  ***\n");
		printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
		printf(">>>               ADMINISTRATION               <<<\n");
		printf("**************************************************\n");
		printf("	1. REGISTER DOCTOR\n");
		printf("	2. MEDICAL LIST\n\n\n\n");
		printf("	0. RETURN\n");
		printf("**************************************************\n\n");
		printf("Choose your option: ");
		scanf_s("%d", &option);
	} while (option > 2 || option < 0);
	return option;
}

Doctor* regDoc() {
	char c;
	unsigned int Number = 0;
	char FullName[50] = "Err";
	int Age = 0;
	char NameOfSpeciality[50] = "Err";
	int YearsOfExperience = 0;
	char Location[50] = "Err";
	char Phone[50] = "Err";
	double Salary = 0.0;
	char WorkingHours[50] = "0-0";
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>             REGISTERING DOCTOR             <<<\n");
	printf("**************************************************\n");
	printf("	\nInternal No of the doctor: ");
	scanf_s("%du", &Number);

	printf("	Full name: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(FullName, 50, stdin);
	FullName[strcspn(FullName, "\n")] = 0;

	printf("	Age: ");
	scanf_s("%d", &Age);

	printf("	Name of Speciality: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(NameOfSpeciality, 50, stdin);
	NameOfSpeciality[strcspn(NameOfSpeciality, "\n")] = 0;

	printf("	Years of Experience: ");
	scanf_s("%d", &YearsOfExperience);

	printf("	Location: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(Location, 50, stdin);
	Location[strcspn(Location, "\n")] = 0;

	printf("	Phone: ");
	fgets(Phone, 50, stdin);
	Phone[strcspn(Phone, "\n")] = 0;

	printf("    Salary: ");
	scanf_s("%lf", &Salary);

	printf("    Working Hours: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(WorkingHours, 50, stdin);
	WorkingHours[strcspn(WorkingHours, "\n")] = 0;

	printf("\n**************************************************\n\n");
	Doctor* doc = CreateDoc(Number, FullName, Age, NameOfSpeciality, YearsOfExperience, Location, Phone, Salary, WorkingHours);
	return doc;
}

void ListDoc(DNode* head) {
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>              LIST OF DOCTORS               <<<\n");
	printf("**************************************************\n");
	DPrintList(head);
}

//Reception part of the program

int receptionWindow() {
	int option = 0;
	do {
		system("cls");
		printf("**************************************************\n");
		printf("***  Managment System of the Private Hospital  ***\n");
		printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
		printf(">>>                 RECEPTION                  <<<\n");
		printf("**************************************************\n");
		printf("	1. PACIENT SEARCH\n\n\n\n");
		printf("	0. RETURN\n");
		printf("**************************************************\n\n");
		printf("Choose your option: ");
		scanf_s("%d", &option);
	} while (option > 1 || option < 0);
	return option;
}

Patient* PatFind(PNode* head) {
	char c;
	unsigned int id = -1;
	char Name[50] = "";
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>             SEARCHING PATIENTS             <<<\n");
	printf("**************************************************\n");
	printf("	\nPut Patient's ID Number or Name: ");
	printf("	\nID No of patient: ");
	scanf_s("%du\n", &id);
	printf("	Full name: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(Name, 50, stdin);
	Name[strcspn(Name, "\n")] = 0;
	printf("\n**************************************************\n\n");

	Patient* pat = PatSearch(head, id, Name);
	return pat;
}

int PatFound() {
	int option = 0;
	do {
		system("cls");
		printf("**************************************************\n");
		printf("***  Managment System of the Private Hospital  ***\n");
		printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
		printf(">>>              PATIENT RECORD                <<<\n");
		printf("**************************************************\n");
		printf("	1. EDIT RECORD\n");
		printf("	2. LIST RECORD\n");
		printf("	3. REMOVE RECORD\n\n\n\n");
		printf("	0. RETURN\n");
		printf("**************************************************\n\n");
		printf("Choose your option: ");
		scanf_s("%d", &option);
	} while (option > 3 || option < 0);
	return option;
}

void PatPrint(Patient* pat) {
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>              PATIENT RECORD                <<<\n");
	printf("**************************************************\n");
	PrintPat(pat);
}

void PatEdit(PNode* head, Patient* pat) {
	char c;
	unsigned int Number = 0;
	char FullName[50] = "Err";
	char IDNumber[15] = "ERR0";
	int Age = 0;
	char Gender[3] = "-";
	char Location[50] = "Err";
	char Phone[50] = "Err";
	char HealthProblem[50] = "Err";
	char DateFirstCons[12] = "00/00/0000";
	char DateLastCons[12] = "00/00/0000";
	char DateNextCons[12] = "00/00/0000";
	char ClinicalCond[50] = "Err";
	char DoctorsName[50] = "Err";
	char NameOfSpeciality[50] = "Err";
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>             UPDATE THE PATIENT             <<<\n");
	printf("**************************************************\n");
	printf("	\nInternal No of the patient: ");
	scanf_s("%du", &Number);

	printf("	Full name: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(FullName, 50, stdin);
	FullName[strcspn(FullName, "\n")] = 0;

	printf("	ID Number: ");
	fgets(IDNumber, 15, stdin);
	IDNumber[strcspn(IDNumber, "\n")] = 0;

	printf("	Age: ");
	scanf_s("%d", &Age);

	printf("	Gender [M/F]: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(Gender, 3, stdin);
	Gender[strcspn(Gender, "\n")] = 0;

	printf("	Location: ");
	fgets(Location, 50, stdin);
	Location[strcspn(Location, "\n")] = 0;

	printf("	Phone: ");
	fgets(Phone, 50, stdin);
	Phone[strcspn(Phone, "\n")] = 0;

	printf("	Health Problem: ");
	fgets(HealthProblem, 50, stdin);
	HealthProblem[strcspn(HealthProblem, "\n")] = 0;

	printf("	Date of the first consultation [dd/mm/yyyy]: ");
	fgets(DateFirstCons, 12, stdin);
	DateFirstCons[strcspn(DateFirstCons, "\n")] = 0;

	printf("	Date of the last consultation [dd/mm/yyyy]: ");
	fgets(DateLastCons, 12, stdin);
	DateLastCons[strcspn(DateLastCons, "\n")] = 0;

	printf("	Date of the next consultation [dd/mm/yyyy]: ");
	fgets(DateNextCons, 12, stdin);
	DateNextCons[strcspn(DateNextCons, "\n")] = 0;

	printf("	Clinical Condition: ");
	fgets(ClinicalCond, 50, stdin);
	ClinicalCond[strcspn(ClinicalCond, "\n")] = 0;

	printf("	Doctor's name: ");
	fgets(DoctorsName, 50, stdin);
	DoctorsName[strcspn(DoctorsName, "\n")] = 0;

	printf("	Name of speciality: ");
	fgets(NameOfSpeciality, 50, stdin);
	NameOfSpeciality[strcspn(NameOfSpeciality, "\n")] = 0;

	printf("\n**************************************************\n\n");
	Patient* new = CreatePat(Number, FullName, IDNumber, Age, Gender, Location, Phone, HealthProblem, DateFirstCons, DateLastCons, DateNextCons, ClinicalCond, DoctorsName, NameOfSpeciality);
	PatUpdate(head, pat, new);
}

int PatNotFound() {
	int option = 0;
	do {
		system("cls");
		printf("**************************************************\n");
		printf("***  Managment System of the Private Hospital  ***\n");
		printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
		printf(">>>            PATIENT NOT FOUND               <<<\n");
		printf("**************************************************\n");
		printf("	1. ADD PATIENT\n\n\n\n");
		printf("	0. RETURN\n");
		printf("**************************************************\n\n");
		printf("Choose your option: ");
		scanf_s("%d", &option);
	} while (option > 1 || option < 0);
	return option;
}

void PatAdd(PNode** head) {
	char c;
	unsigned int Number = 0;
	char FullName[50] = "Err";
	char IDNumber[15] = "ERR0";
	int Age = 0;
	char Gender[3] = "-";
	char Location[50] = "Err";
	char Phone[50] = "Err";
	char HealthProblem[50] = "Err";
	char DateFirstCons[12] = "00/00/0000";
	char DateLastCons[12] = "00/00/0000";
	char DateNextCons[12] = "00/00/0000";
	char ClinicalCond[50] = "Err";
	char DoctorsName[50] = "Err";
	char NameOfSpeciality[50] = "Err";
	system("cls");
	printf("**************************************************\n");
	printf("***  Managment System of the Private Hospital  ***\n");
	printf("***        ESTG-IPVC - Viana do Castelo        ***\n");
	printf(">>>              ADD THE PATIENT               <<<\n");
	printf("**************************************************\n");
	printf("	\nInternal No of the patient: ");
	scanf_s("%du", &Number);

	printf("	Full name: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(FullName, 50, stdin);
	FullName[strcspn(FullName, "\n")] = 0;

	printf("	ID Number: ");
	fgets(IDNumber, 15, stdin);
	IDNumber[strcspn(IDNumber, "\n")] = 0;

	printf("	Age: ");
	scanf_s("%d", &Age);

	printf("	Gender [M/F]: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(Gender, 3, stdin);
	Gender[strcspn(Gender, "\n")] = 0;

	printf("	Location: ");
	fgets(Location, 50, stdin);
	Location[strcspn(Location, "\n")] = 0;

	printf("	Phone: ");
	fgets(Phone, 50, stdin);
	Phone[strcspn(Phone, "\n")] = 0;

	printf("	Health Problem: ");
	fgets(HealthProblem, 50, stdin);
	HealthProblem[strcspn(HealthProblem, "\n")] = 0;

	printf("	Date of the first consultation [dd/mm/yyyy]: ");
	fgets(DateFirstCons, 12, stdin);
	DateFirstCons[strcspn(DateFirstCons, "\n")] = 0;

	printf("	Date of the last consultation [dd/mm/yyyy]: ");
	fgets(DateLastCons, 12, stdin);
	DateLastCons[strcspn(DateLastCons, "\n")] = 0;

	printf("	Date of the next consultation [dd/mm/yyyy]: ");
	fgets(DateNextCons, 12, stdin);
	DateNextCons[strcspn(DateNextCons, "\n")] = 0;

	printf("	Clinical Condition: ");
	fgets(ClinicalCond, 50, stdin);
	ClinicalCond[strcspn(ClinicalCond, "\n")] = 0;

	printf("	Doctor's name: ");
	fgets(DoctorsName, 50, stdin);
	DoctorsName[strcspn(DoctorsName, "\n")] = 0;

	printf("	Name of speciality: ");
	fgets(NameOfSpeciality, 50, stdin);
	NameOfSpeciality[strcspn(NameOfSpeciality, "\n")] = 0;

	printf("\n**************************************************\n\n");
	Patient* new = CreatePat(Number, FullName, IDNumber, Age, Gender, Location, Phone, HealthProblem, DateFirstCons, DateLastCons, DateNextCons, ClinicalCond, DoctorsName, NameOfSpeciality);
	PInsert(head, new);
}

//General functions

void serialize(DNode* d, PNode* p) {
	serializeD(d);
	serializeP(p);
}

void deserialize(DNode** d, PNode** p) {
	deserializeD(&d);
	deserializeP(&p);
}

void freeLists(DNode* d, PNode* p){
	DListFree(d);
	PListFree(p);
}

int main() {
	DNode* DL = NULL;
	PNode* PL = NULL;
	deserialize(&DL, &PL);
	do {
		switch(mainWindow()){
		case 0: return;
		case 1:
			switch (adminWindow()) {
			case 0: break;
			case 1:
				DInsert(&DL, regDoc());
				break;
			case 2:
				ListDoc(DL);
				getch();
				break;
			}
			break;
		case 2:
			switch (receptionWindow()) {
			case 0: break;
			case 1:
				Patient* pat = PatFind(PL);
				if (pat) {
					switch (PatFound()) {
					case 0: break;
					case 1: 
						PatEdit(PL, pat);
						break;
					case 2:
						PatPrint(pat);
						getch();
						break;
					case 3:
						PatDelete(&PL, pat);
						break;
					}
				}
				else {
					switch (PatNotFound()) {
					case 0: break;
					case 1: 
						PatAdd(&PL);
						break;
					}
				}
			}
			break;
		}
		serialize(DL, PL);
	} while (1);
	freeLists(DL, PL);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Doctors.h"

typedef struct dnode{
	DNode* next;
	Doctor* object;
} DNode;

typedef struct doctor {
	unsigned int Number;
	char* FullName;
	int Age;
	char* NameOfSpeciality;
	int YearsOfExperience;
	char* Location;
	char* Phone;
	double Salary;
	char* WorkingHours;
} Doctor;

//Doctor struct functions

Doctor* CreateDoc(unsigned int no, char* na, int a, char* nos, int yoe, char* lo, char* ph, double sa, char* wh) {
	Doctor* doc = (Doctor*)malloc(sizeof(Doctor));
	if (doc) {
		doc->Number = no;
		doc->FullName = _strdup(na);
		doc->Age = a;
		doc->NameOfSpeciality = _strdup(nos);
		doc->YearsOfExperience = yoe;
		doc->Location = _strdup(lo);
		doc->Phone = _strdup(ph);
		doc->Salary = sa;
		doc->WorkingHours = _strdup(wh);
	}
	return doc;
}

void PrintDoc(Doctor* doc) {
	printf("ID: %d | Name: %s | Age: %d | Name of Speciality: %s | Years of Experience: %d | Location: %s | PhoneNo: %s | Salary: %.2f | Working Hours: %s \n", 
		   doc->Number, doc->FullName, doc->Age, doc->NameOfSpeciality, doc->YearsOfExperience, doc->Location, doc->Phone, doc->Salary, doc->WorkingHours);
}

//Doctor's LinkedList functions

DNode* DListInit(Doctor* doc) {
	DNode* head = (DNode*)malloc(sizeof(DNode));
	if (head) {
		head->next = NULL;
		head->object = doc;
	}
	return head;
}

void DInsertFirst(DNode** head, Doctor* obj) {
	DNode* nHead = (DNode*)malloc(sizeof(DNode));
	if (nHead) {
		nHead->next = *head;
		nHead->object = obj;
		*head = nHead;
	}
}

void DPrintList(DNode* head) {
	DNode* tmp = head;
	if (head == NULL) {
		printf("\n		   LIST IS EMPTY\n");
		return;
	}
	int i = 1;
	do {
		PrintDoc(tmp->object);
		i++;
		tmp = tmp->next;
	} while (tmp != NULL);
}

void DInsert(DNode** head, Doctor* obj) {
	if ( *head == NULL) {
		*head = DListInit(obj);
		return;
	}

	DNode* nHead = (DNode*)malloc(sizeof(DNode));
	DNode* tmp = *head;
	while ((tmp->next) != NULL) {
		tmp = tmp->next;
	}

	if (nHead) {
		tmp->next = nHead;
		nHead->next = NULL;
		nHead->object = obj;
	}
}


void DocSearch(DNode* head, int no) {
	while (head->object->Number != no) {
		head = head->next;
	}
	PrintDoc(head->object);
}


void DListFree(DNode* DL) {
	DNode* prev = NULL;
	while (DL != NULL) {
		prev = DL;
		DL = DL->next;
		DFree(prev->object);
		free(prev);
	}
}

void DFree(Doctor* doc) {
	free(doc->FullName);
	free(doc->Location);
	free(doc->NameOfSpeciality);
	free(doc->Phone);
	free(doc->WorkingHours);
	free(doc);
}

void serializeD(DNode* DL) {
	FILE* DocsF;
	fopen_s(&DocsF,"docF.dat", "w");

	if (DocsF == NULL) return;
	while (DL != NULL) {
		Doctor* doc = DL->object;
		fprintf(DocsF, "%d | %s | %d | %s | %d | %s | %s | %.2f | %s | \n",
		doc->Number, doc->FullName, doc->Age, doc->NameOfSpeciality, doc->YearsOfExperience, doc->Location, doc->Phone, doc->Salary, doc->WorkingHours);
		DL = DL->next;
	}

	fclose(DocsF);
}

void deserializeD(DNode** DL) {
	FILE* DocF;
	fopen_s(&DocF, "DocF.dat", "r");
	char c[1000];
	char delimiter[] = " | ";
	char* context = NULL;
	if (DocF == NULL) return;

	system("cls");
	printf("		Please wait\n		.... loading .... \n");
	while (fgets(c, 1000, DocF)) {
		printf("%s", c);
		unsigned int Number = atoi(strtok_s(c, delimiter, &context));
		char* FullName = strtok_s(NULL, delimiter, &context);
		int Age = atoi(strtok_s(NULL, delimiter, &context));
		char* NameOfSpeciality = strtok_s(NULL, delimiter, &context);
		int YearsOfExperience = atoi(strtok_s(NULL, delimiter, &context));
		char* Location = strtok_s(NULL, delimiter, &context);
		char* Phone = strtok_s(NULL, delimiter, &context);
		double Salary = atof(strtok_s(NULL, delimiter, &context));
		char* WorkingHours = strtok_s(NULL, delimiter, &context);
		Doctor* doc = CreateDoc(Number, FullName, Age, NameOfSpeciality, YearsOfExperience, Location, Phone, Salary, WorkingHours);
		DInsert(DL, doc);
		getch();
	}

	fclose(DocF);
}
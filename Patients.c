#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Patients.h"

typedef struct pnode {
	PNode* next;
	Patient* object;
} PNode;

typedef struct patient {
	unsigned int Number;
	char* FullName;
	char* IDNumber;
	int Age;
	char* Gender;
	char* Location;
	char* Phone;
	char* HealthProblem;
	char* DateFirstCons;
	char* DateLastCons;
	char* DateNextCons;
	char* ClinicalCond;
	char* DoctorsName;
	char* NameOfSpeciality;
} Patient;

//Patient struct functions

Patient* CreatePat(unsigned int no, char* na, char* idn, int a, char* g, char* lo, char* ph, char* hp, char* dfc, char* dlc, char* dnc, char* cc, char* dna, char* nos){
	Patient* pat = (Patient*)malloc(sizeof(Patient));
	if (pat) {
		pat->Number = no;
		pat->FullName = _strdup(na);
		pat->IDNumber = _strdup(idn);
		pat->Age = a;
		pat->Gender = _strdup(g);
		pat->Location = _strdup(lo);
		pat->Phone = _strdup(ph);
		pat->HealthProblem = _strdup(hp);
		pat->DateFirstCons = _strdup(dfc);
		pat->DateLastCons = _strdup(dlc);
		pat->DateNextCons = _strdup(dnc);
		pat->ClinicalCond = _strdup(cc);
		pat->DoctorsName = _strdup(dna);
		pat->NameOfSpeciality = _strdup(nos);
	}
	return pat;
}

void PrintPat(Patient* pat) {
	printf("ID: %d | Name: %s | ID Number: %s | Age: %d | Gender: %s | Location: %s | PhoneNo: %s | Health Problem: %s | \nDate of the First Consultation: %s | Date of the Last Consultation: %s | Date of the Next Consultation: %s | Clical Condition: %s |\nDoctor's name: %s | Name of Speciality: %s \n\n", 
			pat->Number, pat->FullName, pat->IDNumber, pat->Age, pat->Gender, pat->Location, pat->Phone, pat->HealthProblem, pat->DateFirstCons, pat->DateLastCons, pat->DateNextCons, pat->ClinicalCond, pat->DoctorsName, pat->NameOfSpeciality);
}

//Patient's LinkedList functions

PNode* PListInit(Patient* obj) {
	PNode* head = (PNode*)malloc(sizeof(PNode));
	if (head) {
		head->next = NULL;
		head->object = obj;
	}
	return head;
}

void PInsertFirst(PNode** head, Patient* obj) {
	PNode* nHead = (PNode*)malloc(sizeof(PNode));
	if (nHead) {
		nHead->next = *head;
		nHead->object = obj;
		*head = nHead;
	}
}

void PPrintList(PNode* head) {
	if (head == NULL) {
		printf("\n		   LIST IS EMPTY\n");
		return;
	}

	PNode* tmp = head;
	int i = 1;
	do {
		PrintPat(tmp->object);
		i++;
		tmp = tmp->next;
	} while (tmp != NULL);
}

void PInsert(PNode** head, Patient* obj) {
	if (*head == NULL) {
		*head = PListInit(obj);
		return;
	}

	PNode* nHead = (PNode*)malloc(sizeof(PNode));
	PNode* tmp = *head;
	if (*head) {
		while ((tmp->next) != NULL) {
			tmp = tmp->next;
		}

		if (nHead) {
			tmp->next = nHead;
			nHead->next = NULL;
			nHead->object = obj;
		}
	}
}


Patient* PatSearch(PNode* head, int no, char* name) {
	if (head) {
		while (1) {
			if (head->object->Number == no) break;
			if (strcmp(head->object->FullName, name) == 0) break;
			head = head->next;
			if (head == NULL) return NULL;
		}
		return head->object;
	}
	return NULL;
}

void PatDelete(PNode** head, Patient* pat) {
	int no = pat->Number;
	char* name = pat->FullName;
	PNode* current = *head;
	PNode* previous = NULL;

	while (1) {
		if (current == NULL) return;
		if (current->object->Number == no) break;
		if (strcmp(current->object->FullName, name) == 0) break;
		previous = current;
		current = current->next;
	}

	if (current == *head) {
		*head = (*head)->next;
		PFree(current->object);
		free(current);
	}
	else {
		previous->next = current->next;
		PFree(current->object);
		free(current);
	}
}

void PatUpdate(PNode* head, Patient* pat, Patient* new) {
	int no = pat->Number;
	char* name = pat->FullName;
	if (head) {
		while (1) {
			if (head->object->Number == no) break;
			if (strcmp(head->object->FullName, name) == 0) break;
			head = head->next;
			if (head == NULL) return;
		}
		free(head->object);
		head->object = new;
	}
}

void PListFree(PNode* PL) {
	PNode* prev = NULL;
	while (PL != NULL) {
		prev = PL;
		PL = PL->next;
		PFree(prev->object);
		free(prev);
	}
}

void PFree(Patient* pat) {
	free(pat->FullName);
	free(pat->Gender);
	free(pat->Location);
	free(pat->Phone);
	free(pat->HealthProblem);
	free(pat->DateFirstCons);
	free(pat->DateLastCons);
	free(pat->DateNextCons);
	free(pat->ClinicalCond);
	free(pat->DoctorsName);
	free(pat->NameOfSpeciality);
	free(pat);
}

void serializeP(PNode* PL) {
	FILE* PatF;
	fopen_s(&PatF, "patF.dat", "w");

	while (PL != NULL) {
		Patient* pat = PL->object;
		fprintf(PatF, "%d | %s | %s | %d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | \n",
			pat->Number, pat->FullName, pat->IDNumber, pat->Age, pat->Gender, pat->Location, pat->Phone, pat->HealthProblem, pat->DateFirstCons, pat->DateLastCons, pat->DateNextCons, pat->ClinicalCond, pat->DoctorsName, pat->NameOfSpeciality);
		PL = PL->next;
	}

	fclose(PatF);
}

void deserializeP(PNode** PL) {
	FILE* PatF;
	fopen_s(&PatF, "patF.dat", "r");
	char c[1000];
	char delimiter[] = " | ";
	char* context = NULL;
	if (PatF == NULL) return;
	
	system("cls");
	printf("		Please wait\n		.... loading .... \n");
	while (fgets(c,1000,PatF)) {
		printf("%s", c);
		unsigned int number = atoi(strtok_s(c, delimiter, &context));
		char* name = strtok_s(NULL, delimiter, &context);
		char* id = strtok_s(NULL, delimiter, &context);
		int age = atoi(strtok_s(NULL, delimiter, &context));
		char* gender = strtok_s(NULL, delimiter, &context);
		char* location = strtok_s(NULL, delimiter, &context);
		char* phone = strtok_s(NULL, delimiter, &context);
		char* hp = strtok_s(NULL, delimiter, &context);
		char* dfc = strtok_s(NULL, delimiter, &context);
		char* dlc = strtok_s(NULL, delimiter, &context);
		char* dns = strtok_s(NULL, delimiter, &context);
		char* cc = strtok_s(NULL, delimiter, &context);
		char* docname = strtok_s(NULL, delimiter, &context);
		char* nos = strtok_s(NULL, delimiter, &context);
		Patient* pat = CreatePat(number, name, id, age, gender, location, phone, hp, dfc, dlc, dns, cc, docname, nos);
		PInsert(&PL, pat);
	}

	fclose(PatF);
}
#pragma once

typedef struct pnode PNode;
typedef struct patient Patient;

Patient* CreatePat(unsigned int no, char* na, char* idn, int a, char* g, char* lo, char* ph, char* hp, char* dfc, char* dlc, char* dnc, char* cc, char* dna, char* nos);
void PrintPat(Patient* pat);

PNode* PListInit(Patient* obj);
void PInsertFirst(PNode** head, Patient* obj);
void PPrintList(PNode* head);
void PInsert(PNode** head, Patient* obj);

Patient* PatSearch(PNode* head, int no, char* name);
void PatDelete(PNode** head, Patient* pat);
void PatUpdate(PNode* head, Patient* pat, Patient* new);

void PListFree(PNode* PL);
void PFree(Patient* pat);
void serializeP(PNode* PL);
void deserializeP(PNode** PL);

#pragma once

typedef struct dnode DNode;
typedef struct doctor Doctor;

Doctor* CreateDoc(unsigned int no, char* na, int a, char* nos, int yoe, char* lo, char* ph, double sa, char* wh);
void PrintDoc(Doctor* doc);

DNode* DListInit(Doctor* doc);
void DInsertFirst(DNode** head, Doctor* obj);
void DPrintList(DNode* head);
void DInsert(DNode** head, Doctor* obj);

void DocSearch(DNode* head, int no);

void DListFree(DNode* DL);
void DFree(Doctor* doc);
void serializeD(DNode* DL);
void deserializeD(DNode* DL);
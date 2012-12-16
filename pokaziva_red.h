Programska-rjesenja
===================

Programska_rjesenja_strukture_podataka

struct qu {
    klijent value;
    qu *next;
};

struct que{
       qu *front, *rear;
};

typedef que Queue;
typedef qu *element;


klijent FrontQ(Queue *Q) {
    return Q->front->next->value;
}

void EnQueueQ(klijent x, Queue *Q) {
    element novi = new qu;
    novi->value = x;
    novi->next = NULL;

    Q->rear->next = novi;
    Q->rear = novi;
}

void DeQueueQ(Queue *Q) {
    element brisi = Q->front;
    Q->front = Q->front->next;
    delete brisi;
}

void InitQ(Queue *Q) {
    element novi = new qu;
    novi->next = NULL;

    Q->front = novi;
    Q->rear = novi;
}

bool IsEmptyQ(Queue *Q) {
    return Q->rear == Q->front;
}

void PrintQ(Queue *Q) {
    element tekuci;
    tekuci = Q->front;
    int j = 1;
    do {
        tekuci = tekuci->next;
        cout << "Klijent " << j << " (" << tekuci->value.ime << "): " << endl;
        cout << "----------------------" << endl;
        cout << "Jedinica vremena: " << tekuci->value.a << " /";
        cout << "Vremenska jedinica transakcije: " << tekuci->value.b << endl;
        cout << "Prioritet: ";
        if (tekuci->value.c == 1) cout << "Umirovljenik <" << tekuci->value.c << "> /";
        else if (tekuci->value.c == 2) cout << "Invalid <" << tekuci->value.c << "> /";
        else if (tekuci->value.c == 3) cout << "Trudnica <" << tekuci->value.c << "> /";
        else if (tekuci->value.c == 4) cout << "VIP klijent <" << tekuci->value.c << "> /";
        else if (tekuci->value.c == 5) cout << "Ostali klijenti <" << tekuci->value.c << "> /";
        else if (tekuci->value.c == 6) cout << "Nije klijent banke <" << tekuci->value.c << "> ";
        
        cout << "Transakcija klijenta: ";
        if (tekuci->value.d == 1) cout << "Uplata <" << tekuci->value.d << "> " ;
        else if (tekuci->value.d == 2) cout << "Isplata <" << tekuci->value.d << "> ";
        else if (tekuci->value.d == 3) cout << "Placanje racuna <" << tekuci->value.d << "> ";
        else if (tekuci->value.d == 4) cout << "Krediti <" << tekuci->value.d << "> ";
        cout << endl << endl;
    
        j++;
    } while(tekuci != Q->rear);
}

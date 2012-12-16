Programska-rjesenja
===================

Programska_rjesenja_strukture_podataka

typedef int element;
struct qu {
    klijent elements[10000];
    element front, rear;
};

typedef struct qu Queue;

klijent FrontQ(Queue *Q) {
    return Q->elements[Q->front];
}

int AddOne(int n) {
    return (n+1)%10000;
}

void EnQueueQ(klijent x, Queue *Q) {
    Q->rear = AddOne(Q->rear);
    Q->elements[Q->rear] = x;
}

void DeQueueQ(Queue *Q) {
    Q->front = AddOne(Q->front);
}

void InitQ(Queue *Q) {
    Q->front = 0;
    Q->rear = 9999;
}

bool IsEmptyQ(Queue *Q) {
    return Q->front == AddOne(Q->rear);
}

void PrintQ(Queue *Q) {
    int j = 1;
    for (int i = Q->front; i != AddOne(Q->rear); i = AddOne(i)) {
        cout << "Klijent " << j << " (" << Q->elements[i].ime << "): " << endl;
        cout << "----------------------" << endl;
        cout << "Jedinica vremena: " << Q->elements[i].a << " /";
        cout << "Vremenska jedinica transakcije: " << Q->elements[i].b << endl;
        cout << "Prioritet: ";
        if (Q->elements[i].c == 1) cout << "Umirovljenik <" << Q->elements[i].c << "> /";
        else if (Q->elements[i].c == 2) cout << "Invalid <" << Q->elements[i].c << "> /";
        else if (Q->elements[i].c == 3) cout << "Trudnica <" << Q->elements[i].c << "> /";
        else if (Q->elements[i].c == 4) cout << "VIP klijent <" << Q->elements[i].c << "> /";
        else if (Q->elements[i].c == 5) cout << "Ostali klijenti <" << Q->elements[i].c << "> /";
        else if (Q->elements[i].c == 6) cout << "Nije klijent banke <" << Q->elements[i].c << "> ";
        
        cout << "Transakcija klijenta: ";
        if (Q->elements[i].d == 1) cout << "Uplata <" << Q->elements[i].d << "> " ;
        else if (Q->elements[i].d == 2) cout << "Isplata <" << Q->elements[i].d << "> ";
        else if (Q->elements[i].d == 3) cout << "Placanje racuna <" << Q->elements[i].d << "> ";
        else if (Q->elements[i].d == 4) cout << "Krediti <" << Q->elements[i].d << "> ";
        cout << endl << endl;
        j++;
    }
}

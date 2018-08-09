#include <stdio.h>

#define MaxDomkow 1000001
#define MaxSciezek 1000000
#define Zawsze 36501

typedef struct TEdge
{
    int v;
    int next;
};

TEdge edge[MaxSciezek];
int firstEdge[MaxDomkow];
int domki,sciezki;
char osiagalne[MaxDomkow];
int stopienWejscia[MaxDomkow];
int result[MaxDomkow];

void wczytaj()
{
    int i, v, w;

    scanf("%d %d", &domki, &sciezki);

    for(i = 0; i <= domki; i++){
		firstEdge[i] = -1;
		osiagalne[i] = 0;
		stopienWejscia[i] = 0;
		result[i] = 0;
	}

    for(i = 0; i < sciezki; i++)
    {
    scanf("%d %d", &v, &w);
    if (v == domki+1) v = 0;
    if (w == domki+1) w = 0;

    edge[i].v = v;
    edge[i].next = firstEdge[w];
    firstEdge[w] = i;
    }
}

void znajdzOsiagalne()
{
    int q[MaxDomkow], qs, qe;
    int v, w, pos;

    osiagalne[0] = 1;
    q[0] = 0;
    qs = 0, qe = 1;

    while (qs < qe)
    {
    v = q[qs++];
    pos = firstEdge[v];
    while (pos != -1)
    {
        w = edge[pos].v;
        if (!osiagalne[w])
        {
        q[qe++] = w;
        osiagalne[w] = 1;
        }
        pos = edge[pos].next;
    }
    }
}

void obliczStopienWierzcholka()
{
    int i, pos;

    for(i = 0; i <= domki; i++)
    if (osiagalne[i])
    {
        pos = firstEdge[i];
        while (pos != -1)
        {
        stopienWejscia[ edge[pos].v ]++;
        pos = edge[pos].next;
        }
    }
}

void dodaj(int v, int w)
{
    if (result[w] == Zawsze)
    result[v] = Zawsze;
    else
    {
    result[v] = result[v] + result[w];
    if (result[v] >= Zawsze)
        result[v] = Zawsze;
    }
}

void obliczWynikiDlaWierzcholkow()
{
    int q[MaxDomkow], qe, qs;
    int v, w, pos, i;

    if (stopienWejscia[0] != 0)
    {
    for(i = 0; i <= domki; i++)
        result[i] = Zawsze;
        return;
    }

    q[0] = 0;
    qs = 0, qe = 1;
    result[0] = 1;

    while (qs < qe)
    {
    v = q[qs++];

    pos = firstEdge[v];

    while (pos != -1)
    {
        w = edge[pos].v;
        if (osiagalne[w])
        {
        dodaj(w, v);
        stopienWejscia[w]--;
        if (stopienWejscia[w] == 0)
            q[qe++] = w;
        }
        pos = edge[pos].next;
    }
    }

    for(i = 0; i <= domki; i++)
    if (stopienWejscia[i] != 0)
        result[i] = Zawsze;
}

void rozwiaz()
{
    int i, maxFound, maxCount;

    maxFound = 0;
    maxCount = 0;

    for(i = 1; i <= domki; i++)
    if (osiagalne[i])
        if (result[i] > maxFound)
        maxFound = result[i];

    for(i = 1; i <= domki; i++)
    if (osiagalne[i] && result[i] == maxFound)
        maxCount++;

    if (maxFound == Zawsze)
    printf("zawsze\n");
    else printf("%d\n", maxFound);

    printf("%d\n", maxCount);

    for(i = 1; i <= domki; i++)
    if (osiagalne[i] && result[i] == maxFound)
        printf("%d ", i);
    printf("\n");
}

int main()
{
    wczytaj();
    znajdzOsiagalne();
    obliczStopienWierzcholka();
    obliczWynikiDlaWierzcholkow();
    rozwiaz();

    return 0;
}
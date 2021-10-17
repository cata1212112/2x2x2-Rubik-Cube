#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <deque>

using namespace std;

ifstream in("rubik.in");

struct Permutare
{
    char v[24];
} start,fin,nxt,acm;

typedef Permutare (*Moves) (Permutare a);

unordered_map<string, bool> mup;
unordered_map<string, bool> mup_back;
unordered_map<string, string > mup_moves;
unordered_map<string, string > mup_back_moves;
int cnt = 0;

queue<Permutare> q;
queue<Permutare> q_back;
unordered_map<string, int> mp;

string s[24] = {"flu", "fru", "fdl", "fdr", "lfu", "lfd", "lub", "ldb", "ruf", "rdf", "rdb", "rub", "ufl", "ufr", "urb", "ulb", "bul", "bur", "bdl", "bdr", "dlf", "drf", "dbr", "dbl"};

Permutare Circular(Permutare perm, int poz1,int poz2,int poz3,int poz4)
{
    Permutare acm = perm;
    char aux = acm.v[poz1];
    acm.v[poz1] = acm.v[poz4];
    acm.v[poz4] = acm.v[poz3];
    acm.v[poz3] = acm.v[poz2];
    acm.v[poz2] = aux;

    return acm;
}

Permutare Circular_INVERSE(Permutare perm, int poz1,int poz2,int poz3,int poz4)
{
    Permutare acm = perm;
    char aux = acm.v[poz1];
    acm.v[poz1] = acm.v[poz2];
    acm.v[poz2] = acm.v[poz3];
    acm.v[poz3] = acm.v[poz4];
    acm.v[poz4] = aux;

    return acm;
}

Permutare Rotate_F(Permutare perm)///VERIFICAT
{

    Permutare acm = perm;
    acm = Circular_INVERSE(acm, mp["flu"], mp["fru"], mp["fdr"], mp["fdl"]);
    acm = Circular_INVERSE(acm, mp["ufr"], mp["rdf"], mp["dlf"], mp["lfu"]);
    acm = Circular_INVERSE(acm, mp["ufl"], mp["ruf"], mp["drf"], mp["lfd"]);
    return acm;
}

Permutare Rotate_R(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;

    acm = Circular(acm, mp["ruf"], mp["rub"], mp["rdb"], mp["rdf"]);
    acm = Circular(acm, mp["ufr"], mp["bur"], mp["dbr"], mp["fdr"]);
    acm = Circular(acm, mp["urb"], mp["bdr"], mp["drf"], mp["fru"]);
    return acm;
}

Permutare Rotate_L(Permutare perm)/// VERIFICAT
{
    Permutare acm = perm;
    acm = Circular(acm, mp["lfu"], mp["lub"], mp["ldb"], mp["lfd"]);
    acm = Circular(acm, mp["ulb"], mp["bdl"], mp["dlf"], mp["flu"]);
    acm = Circular(acm, mp["ufl"], mp["bul"], mp["dbl"], mp["fdl"]);
    return acm;
}

Permutare Rotate_U(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular(acm, mp["ulb"], mp["urb"], mp["ufr"], mp["ufl"]);
    acm = Circular(acm, mp["bul"], mp["rub"], mp["fru"], mp["lfu"]);
    acm = Circular(acm, mp["bur"], mp["ruf"], mp["flu"], mp["lub"]);
    return acm;
}

Permutare Rotate_D(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular(acm, mp["dlf"], mp["dbl"], mp["dbr"], mp["drf"]);
    acm = Circular(acm, mp["bdl"], mp["rdb"], mp["fdr"], mp["lfd"]);
    acm = Circular(acm, mp["bdr"], mp["rdf"], mp["fdl"], mp["ldb"]);
    return acm;
}

Permutare Rotate_B(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular(acm, mp["bul"], mp["bdl"], mp["bdr"], mp["bur"]);
    acm = Circular(acm, mp["urb"], mp["lub"], mp["dbl"], mp["rdb"]);
    acm = Circular(acm, mp["ulb"], mp["ldb"], mp["dbr"], mp["rub"]);
    return acm;
}

////////////////
Permutare Rotate_F_I(Permutare perm)///VERIFICAT
{

    Permutare acm = perm;
    acm = Circular(acm, mp["flu"], mp["fru"], mp["fdr"], mp["fdl"]);
    acm = Circular(acm, mp["ufr"], mp["rdf"], mp["dlf"], mp["lfu"]);
    acm = Circular(acm, mp["ufl"], mp["ruf"], mp["drf"], mp["lfd"]);
    return acm;
}

Permutare Rotate_R_I(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;

    acm = Circular_INVERSE(acm, mp["ruf"], mp["rub"], mp["rdb"], mp["rdf"]);
    acm = Circular_INVERSE(acm, mp["ufr"], mp["bur"], mp["dbr"], mp["fdr"]);
    acm = Circular_INVERSE(acm, mp["urb"], mp["bdr"], mp["drf"], mp["fru"]);
    return acm;
}

Permutare Rotate_L_I(Permutare perm)/// VERIFICAT
{
    Permutare acm = perm;
    acm = Circular_INVERSE(acm, mp["lfu"], mp["lub"], mp["ldb"], mp["lfd"]);
    acm = Circular_INVERSE(acm, mp["ulb"], mp["bdl"], mp["dlf"], mp["flu"]);
    acm = Circular_INVERSE(acm, mp["ufl"], mp["bul"], mp["dbl"], mp["fdl"]);
    return acm;
}

Permutare Rotate_U_I(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular_INVERSE(acm, mp["ulb"], mp["urb"], mp["ufr"], mp["ufl"]);
    acm = Circular_INVERSE(acm, mp["bul"], mp["rub"], mp["fru"], mp["lfu"]);
    acm = Circular_INVERSE(acm, mp["bur"], mp["ruf"], mp["flu"], mp["lub"]);
    return acm;
}

Permutare Rotate_D_I(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular_INVERSE(acm, mp["dlf"], mp["dbl"], mp["dbr"], mp["drf"]);
    acm = Circular_INVERSE(acm, mp["bdl"], mp["rdb"], mp["fdr"], mp["lfd"]);
    acm = Circular_INVERSE(acm, mp["bdr"], mp["rdf"], mp["fdl"], mp["ldb"]);
    return acm;
}

Permutare Rotate_B_I(Permutare perm)///VERIFICAT
{
    Permutare acm = perm;
    acm = Circular_INVERSE(acm, mp["bul"], mp["bdl"], mp["bdr"], mp["bur"]);
    acm = Circular_INVERSE(acm, mp["urb"], mp["lub"], mp["dbl"], mp["rdb"]);
    acm = Circular_INVERSE(acm, mp["ulb"], mp["ldb"], mp["dbr"], mp["rub"]);
    return acm;
}

Moves Miscari[] =
{
    Rotate_B,
    Rotate_D,
    Rotate_F,
    Rotate_L,
    Rotate_R,
    Rotate_U,
    Rotate_B_I,
    Rotate_D_I,
    Rotate_F_I,
    Rotate_L_I,
    Rotate_R_I,
    Rotate_U_I
};

char v[12] = {'B', 'D', 'F', 'L', 'R', 'U','b', 'd', 'f', 'l', 'r', 'u'};

int Gata(Permutare perm)
{
    char acm = perm.v[0];
    for (int i=1; i<=3; i++) if (perm.v[i] != acm) return 0;

    acm = perm.v[4];
    for (int i=5; i<=7; i++) if (perm.v[i] != acm) return 0;

    acm = perm.v[8];
    for (int i=9; i<=11; i++) if (perm.v[i] != acm) return 0;

    acm = perm.v[12];
    for (int i=13; i<=15; i++) if (perm.v[i] != acm) return 0;

    acm = perm.v[16];
    for (int i=17; i<=19; i++) if (perm.v[i] != acm) return 0;

    acm = perm.v[20];
    for (int i=21; i<=23; i++) if (perm.v[i] != acm) return 0;

    return 1;
}

void Afiseaza(string dap, string dap_2)
{
    for (int i=0; i<dap.size(); i++) cout << dap[i] << " ";
    for (int i=0; i<dap_2.size(); i++)
    {
        if (dap_2[i] >= 'A' && dap_2[i] <= 'Z') cout << char(dap_2[i] + 32) << " ";
        else cout <<  char(dap_2[i] - 32) << " ";
    }
}

void BFS()
{
    int cnt = 0;
    while (!q.empty() && !q_back.empty())
    {
        cnt++;
        ///cout << cnt << "\n";
        acm = q.front();
        if (Gata(acm))
        {
            for (int i=0; i<mup_moves[acm.v].size(); i++) cout << mup_moves[acm.v][i] << " ";
            return ;
        }
        q.pop();
        if (mup[acm.v] == 0)
        {
            mup[acm.v] = 1;
            if (mup_back[acm.v] == 1)
            {
                cout << "GATA\n";
                Afiseaza(mup_moves[acm.v], mup_back_moves[acm.v]);
                return ;
            }
            for (int i=0; i<12; i++)
            {
                nxt = acm;
                nxt = Miscari[i](nxt);
                mup_moves[nxt.v] = mup_moves[acm.v] + v[i];
                ///if (cnt == 2) cout << mup_moves[nxt.p.v] << "\n";
                q.push(nxt);
            }
        }

        acm = q_back.front();
        q_back.pop();
        if (mup_back[acm.v] == 0)
        {
            mup_back[acm.v] = 1;
            if (mup[acm.v] == 1)
            {
                cout << "GATA\n";
                Afiseaza(mup_moves[acm.v], mup_back_moves[acm.v]);
                return ;
            }
            for (int i=0; i<12; i++)
            {
                nxt = acm;
                nxt = Miscari[i](nxt);
                mup_back_moves[nxt.v] = v[i] + mup_back_moves[acm.v];
                q_back.push(nxt);
            }
        }
    }
}

int main()
{
    for (int i=0; i<24; i++)
    {
        mp[s[i]] = i;
    }
    for (int i=0; i<24; i++)
    {
        in >> start.v[i];
    }
    q.push(start);
    mup_moves[start.v] = "";
    char vr[] = {'n', 'n', 'n', 'n', 'r', 'r', 'r', 'r', 'p', 'p', 'p', 'p', 'v', 'v', 'v', 'v', 'g', 'g', 'g', 'g', 'a', 'a', 'a', 'a'};
    for (int i=0; i<24; i++) fin.v[i] = vr[i];
    mup_back_moves[fin.v] = "";
    q_back.push(fin);
     BFS();
    return 0;
}

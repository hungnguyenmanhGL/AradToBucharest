#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxCities = 20;
enum ENUM_CITIES { Arad = 0, Bucharest, Craiova, Drobeta, Eforie, Fagaras, Giurgiu, Hirsova, Iasi, Lugoj, Mehadia, 
					Neamt, Oradea, Pitesti, RimnicuVilcea, Sibiu, Timisoara, Urziceni, Vaslui, Zerind };
priority_queue <vector<int>> sln;
int estDis[maxCities] = {366,0,160,242,161,176,77,151,226,244,241,234,380,100,193,253,329,80,199,374};

string GetCityName(int curCity)//h
{
    switch (curCity)
    {
    case Arad: return "Arad"; break;
    case Bucharest: return "Bucharest"; break;
    case Craiova: return "Craiova"; break;
    case Drobeta: return "Drobeta"; break;
    case Eforie: return "Eforie"; break;
    case Fagaras: return "Fagaras"; break;
    case Giurgiu: return "Giurgiu"; break;
    case Hirsova: return "Hirsova"; break;
    case Iasi: return "Iasi"; break;
    case Lugoj: return "Lugoj"; break;
    case Mehadia: return "Mehadia"; break;
    case Neamt: return "Neamt"; break;
    case Oradea: return "Oradea"; break;
    case Pitesti: return "Pitesti"; break;
    case RimnicuVilcea: return "RimVil"; break;
    case Sibiu: return "Sibiu"; break;
    case Timisoara: return "Timisoara"; break;
    case Urziceni: return "Urziceni"; break;
    case Vaslui: return "Vaslui"; break;
    case Zerind: return "Zerind"; break;
    }

}

struct path
{
    int f;
    vector <int> curPath;
};

struct ComparePath
{
    bool operator()(const path& a, const path& b)
    {
        return a.f > b.f;
    }
};

bool DesReached(int i)
{
    if (i == Bucharest) return true;
    else
    {
        return false;
    }
}

void aStarSearch(int map[maxCities][maxCities])
{
    priority_queue <path, vector<path>, ComparePath> sln;
    vector <path> out;
    
    path start;
    start.f = 0;
    start.curPath.push_back(Arad);
    sln.push(start);

    while (!sln.empty())
    {
        path temp = sln.top();
        int cur = temp.curPath.back();
        cout << cur << endl;
        if (cur != Bucharest) {
            int backCount = 0;
            for (int j = 0; j < maxCities; j++)
            {
                if (map[cur][j] > 0) {
                    for (int t = 0; t < temp.curPath.size(); t++)
                    {
                        if (map[cur][j] == temp.curPath.at(t)) backCount++;//check if city already in path
                    }

                    if (backCount > 0) break;
                    else
                    {
                        for (int i = 0; i < temp.curPath.size(); i++)
                        {
                            cout << GetCityName(temp.curPath.at(i)) + "->";
                        }
                        cout << endl;

                        path p;
                        p.f = map[cur][j] + estDis[cur] + temp.f;
                        p.curPath = temp.curPath;
                        p.curPath.push_back(map[cur][j]);
                        sln.push(p);
                    }
                }
            }
            sln.pop();
        }

        if (cur == Bucharest)
        {
            for (int i = 0; i < temp.curPath.size(); i++)
            {
                cout << GetCityName(temp.curPath.at(i)) + "->";
            }
            cout << endl;
            sln.pop();
        }        
    }


}

void main()
{
    int map[maxCities][maxCities];
    for (int i = 0; i < maxCities; i++)
    {
        for (int j = 0; j < maxCities; j++)
        {
            if (i == j) map[i][j] = 0;
            else map[i][j] = -1;
        }
    }

    //hard code time
    map[Arad][Sibiu] = 140; map[Arad][Zerind] = 75; map[Arad][Timisoara] = 118;
    map[Sibiu][Fagaras] = 99; map[Sibiu][RimnicuVilcea] = 80;
    map[Zerind][Oradea] = 71;
    map[Timisoara][Lugoj] = 111;
    map[Fagaras][Bucharest] = 211;
    map[RimnicuVilcea][Pitesti] = 97; map[RimnicuVilcea][Craiova] = 146;
    map[Oradea][Sibiu] = 151;
    map[Lugoj][Mehadia] = 70;
    map[Pitesti][Bucharest] = 101; map[Pitesti][Craiova] = 138;
    map[Craiova][Drobeta] = 120;
    map[Mehadia][Drobeta] = 75;


    for (int i = 0; i < maxCities; i++)
    {
        for (int j = 0; j < maxCities; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    aStarSearch(map);
}
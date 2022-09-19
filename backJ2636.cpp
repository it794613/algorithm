#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;



int x,y;
int map[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
queue<pair<int,int>> q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(){
    while(!q.empty()){
        int temp_x = q.front().first;
        int temp_y = q.front().second;
        q.pop();
        for(int a=0;a<4;a++){
            int next_x = temp_x + dx[a];
            int next_y = temp_y + dy[a];
            if(next_x >=0 && next_x < x && next_y >=0 && next_y < y && map[next_y][next_x]== 1 && visited[next_y][next_x]== false){
                q.push(make_pair(next_x, next_y));
                visited[next_y][next_x]=true;
                map[next_y][next_x]=0;
            }
        }
    }
}

int main(){
    cin >> x >> y;
    for(int a=0;a<y;a++){
        for(int b=0;b<x;b++){
            cin >> map[a][b];
        }
    }
    for(int a=0;a<y;a++){
        for(int b=0;b<x;b++){
            if(map[a][b] == 1 && visited[a][b]==true){
                for(int c=0;c<4;c++){
                    int next_x = b + dx[a];
                    int next_y = a + dy[a];
                    if(next_y >= 0 && next_y < y && next_x >= 0 && next_x < x && map[next_y][next_x] == 0){
                        q.push(make_pair(a,b));
                        visited[a][b]=true;
                        map[a][b]=0;
                    }
                }
            }
        }
    }
    bfs();
    for(int a=0;a<y;a++){
        cout << "\n";
        for(int b=0;b<x;b++){
            cout << map[a][b];
        }
    }
}
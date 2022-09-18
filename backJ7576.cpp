#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

typedef struct coord{
    int x, y;
}coord;

int map[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int x,y;
queue<coord> q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(){
    while(!q.empty()){
        coord temp = q.front();
        q.pop();
        for(int a=0;a<4;a++){
            coord next;
            next.x = temp.x + dx[a];
            next.y = temp.y + dy[a];
            if(next.y >=0 && next.y < y && next.x >= 0 && next.x < x && map[next.y][next.x]== 0 && visited[next.y][next.x]==false){
                q.push(next);
                visited[next.y][next.x]= true;
                map[next.y][next.x] = map[temp.y][temp.x] + 1;
            }
        }
    }
}

int main(){
    cin >> x >> y;
    int maxNumber = -1;
    int result = 0;
    for(int a=0;a<y;a++){
        for (int b=0;b<x;b++){
            cin >> map[a][b];
        }
    }
    for(int a=0;a<y;a++){
        for(int b=0;b<x;b++){
            if(visited[a][b]== false && map[a][b]==1){
                coord start;
                start.y = a;
                start.x = b;
                q.push(start);
            }
        }
    }
    bfs();
    for(int a=0;a<y;a++){
        for(int b=0;b<x;b++){
            if(map[a][b] == 0){
                result = 1;
            }
            else{
                if(maxNumber < map[a][b]){
                    maxNumber = map[a][b];
                }
            }
        }
    }
    if(result == 1){
        cout<< -1;
    }else{
        cout<< maxNumber - 1;
    }
}
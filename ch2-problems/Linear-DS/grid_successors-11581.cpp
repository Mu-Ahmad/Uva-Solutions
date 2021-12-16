#include <iostream>
using namespace std;

bool isFinite(int grid[3][3]){
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (grid[i][j]) return true;
      
  return false;
}

void doSomething(int g[3][3]){
  int h[3][3];

	h[0][0] = (g[0][1] + g[1][0]) % 2;
	h[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	h[0][2] = (g[0][1] + g[1][2]) % 2;

	h[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	h[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	h[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

	h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;
	
	for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
    g[i][j] = h[i][j];
}

int main() {
    int grid[3][3];
    int t; cin >> t; cin.ignore();
    
    while(t--){
      cin.ignore();
      string line;
      for(int i=0; i<3; i++){
        cin >> line;
      //  cout << line << '\n';
        for(int j=0; j<3; j++)
          if (line[j] == '1') grid[i][j] = 1;
          else grid[i][j] = 0;
      }
      
      int ans = -1;
      
      while (isFinite(grid)) {
        doSomething(grid);
        ans++;
      } 
      cout << ans << '\n';
    }
    
    return 0;
}
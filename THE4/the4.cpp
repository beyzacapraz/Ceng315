#include "the4.h"
// do not add extra libraries here

int divide_land(int X, int Y, bool** possible_plots){
    
    
    int** dp = new int*[X+ 1];
    for (int i = 0; i <= X; ++i) {
        dp[i] = new int[Y + 1]();
        
    }


    for (int i = 1; i <= X; ++i) {
        for (int j = 1; j <= Y; ++j) {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (possible_plots[i][j]) {
                dp[i][j] = 0; 
            }
            else{
                dp[i][j] = i*j;
            }
        }
    }

    
    for (int i = 1; i <= X; ++i) {
        for (int j = 1; j <= Y; ++j) {
            for (int x = 1; x < i; ++x) {
                dp[i][j] = std::min(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for (int y = 1; y < j; ++y) {
                dp[i][j] = std::min(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        }
    }
    
    return dp[X][Y];
}

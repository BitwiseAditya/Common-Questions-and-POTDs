
/*Rotten Oranges

Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

Your task is to determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: If it is impossible to rot every orange then simply return -1.

Examples:

Input: mat[][] = [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
Output: 2
Explanation: 

Oranges at positions (0,0), (0,3), (1,3), and (2,3) will rot adjacent fresh oranges in successive time frames.
All fresh oranges become rotten after 2 units of time.
Input: mat[][] = [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
Output: -1
Explanation: Oranges at positions (0,0), (0,3), (1,3), and (2,3) rot some fresh oranges,
but the fresh orange at (2,0) can never be reached, so not all oranges can rot.
Constraints:
1 ≤ mat.size() ≤ 500
1 ≤ mat[0].size() ≤ 500
mat[i][j] = {0, 1, 2} 

 */
import java.util.*;

class Triplet {
    int row;
    int coloumn;
    int time;

    Triplet(int row, int coloumn, int time) {
        this.row = row;
        this.coloumn = coloumn;
        this.time = time;
    }
}

public class RottenOrangess {
    public int orangesRot(int[][] mat) {
        // code here
        Queue<Triplet> q = new LinkedList<>();
        int rows = mat.length;
        int cols = mat[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 2) {
                    q.offer(new Triplet(i, j, 0));
                }
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            Triplet t = q.poll();
            int row = t.row;
            int col = t.coloumn;
            int time = t.time;
            ans = Integer.max(ans, time);
            if (col + 1 < cols && mat[row][col + 1] == 1) {
                q.offer(new Triplet(row, col + 1, time + 1));
                mat[row][col + 1] = 2;
            }
            if (col - 1 >= 0 && mat[row][col - 1] == 1) {
                q.offer(new Triplet(row, col - 1, time + 1));
                mat[row][col - 1] = 2;
            }
            if (row + 1 < rows && mat[row + 1][col] == 1) {
                q.offer(new Triplet(row + 1, col, time + 1));
                mat[row + 1][col] = 2;
            }
            if (row - 1 >= 0 && mat[row - 1][col] == 1) {
                q.offer(new Triplet(row - 1, col, time + 1));
                mat[row - 1][col] = 2;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
}

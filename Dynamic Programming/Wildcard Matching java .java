class Solution {
    public boolean isMatch(String s, String p) {

        boolean[][] dp = new boolean[p.length()+1][s.length()+1];


        for (int row = dp.length-1; row >= 0; row--)
         {
            for (int col = dp[0].length-1; col >= 0; col--) 
            {
                if (row == dp.length-1 && col == dp[0].length-1) 
                {
                    dp[row][col] = true; // right bottom most corner
                }
                
                 else if (row == dp.length-1)
                {
                    dp[row][col] = false; // Rest of last row
                } 
                
                else if (col == dp[0].length-1) 
                {
                    if (p.charAt(row) == '*') 
                    { // If *, check below
                        dp[row][col] = dp[row+1][col];
                    } 

                    else 
                    {
                        dp[row][col] = false;
                    }

                }
                
                else 
                {
                    if (p.charAt(row) == '?')
                    { // ? matches 1 valid character
                        dp[row][col] = dp[row+1][col+1]; // Check diagonally down
                    } 
                    
                    else if (p.charAt(row) == '*') 
                    {
                        dp[row][col] = dp[row+1][col] || dp[row][col+1]; // Check right and below
                    }
                    
                    else if (p.charAt(row) == s.charAt(col)) 
                    {
                        dp[row][col] = dp[row+1][col+1]; // Check diagonally down
                    } 
                    
                    else 
                    {
                        dp[row][col] = false; // else set false
                    }
                }
            }
        }

        return dp[0][0];
    }
}
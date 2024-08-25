/* Chef is playing a game with his friend Misha. They have a pile containg N coins. Players take alternate turns, removing some coins from the pile. 
On each turn, a player can remove either one coin or coins equal to some prime power (i.e. px coins, where p - prime number and x - positive integer). 
Game ends when the pile becomes empty. The player who can not make a move in his turn loses.

Chef plays first. Your task is to find out who will win the game, provided that both of the player play optimally.

--------------------------------------------------------------------

n = 1, 2, 3, 4, 5 - Player 1 wins by taking all the coins
        n = 6, any number of coins taken by Player 1 converts it to a game where n < 6 where he goes second. Player 2 wins.
        If n = (0 mod 6) Player 2 wins,
            Player 1 wins otherwise.

        Let us assume this is true for all n upto n = 6k
        Now, for n = 6k + 1, 6k + 2, 6k + 3, 6k + 4, 6k + 5, Player 1 takes enough coins to keep n = 6k coins so that he is the second player on n = 6k coins.

        By the induction hypothesis, n = 6k is winning for the second player so Player 1 wins.

        If n = 6k + 6, Player 1 can only win by ensuring the number of coins left is a multiple of 6 (by the induction hypothesis).
        This can only be done by taking a multiple of 6 number of coins. This isn't allowed. Any legal move is losing for Player 1.

This proves the hypothesis. */ 

void whoWins(int noOfCoins){
	//code - here
	if (noOfCoins%6 == 0){
		cout << "Moni" << endl;
	}else{
		cout << "Raman" << endl;
	}
}

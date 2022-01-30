 bool winnerOfGame(string colors) {
        int countA = 0, countB = 0, alice = 0, bob = 0;
        char prev = 'X';
        for (auto ch : colors) {
            if (prev != ch) {
                if (countA - 2 > 0) alice += countA - 2;
                else if (countB - 2 > 0)    bob += countB - 2;
                countA = countB = 0;
            } 
            if (ch == 'A')  countA++;
            else    countB++;
            prev = ch;
        }
        if (countA - 2 > 0) alice += countA - 2;
        else if (countB - 2 > 0)    bob += countB - 2;
        
        return true ? (alice > bob) : false;
    }
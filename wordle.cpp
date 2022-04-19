// John Leeds
// 2/18/2022
// Wordle solver
// Source for word lists: https://github.com/bnprks/wordle_solver
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int charToInt(char x){
    return int(x) - 'a';
}

bool charInArray(char chars[], int l, char val){
    for ( int i = 0; i<l; i++ ){
        if ( chars[i] == val ) return true;
    }
    return false;
}

bool charInString(string word, char val, int l = 5){
    for ( int i = 0; i<l; i++ ){
        if ( word[i] == val ){
            return true;
        }
    }
    return false;
}

class Node{
    public:
        // Constructors
        Node(string data){
            word = data;
            next = nullptr;
        }
        Node(string data, Node* link){
            word = data;
            next = link;
        }
        // not constructors
        char getChar(int i){
            return word[i];
        }
        string getWord(){
            return word;
        }
        void setNext(Node* link){
            next = link;
        }
        void resetNext(){
            next = nullptr;
        }
        Node* getNext(){
            return next;
        }

    private:
        string word;
        Node* next;
};

class LinkedList{
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
        LinkedList(Node* first){
            head = first;
            tail = first;
        }
        // create a linked list from a file
        LinkedList(string fileName){
            head = NULL;
            tail = NULL;
            ifstream myFile(fileName);
            string str;
            while ( getline(myFile, str) ){
                append(str);
            }
            myFile.close();
        }
        Node* getHead(){
            return head;
        }
        Node* getTail(){
            return tail;
        }
        // returns true if a value is in the linked list
        bool inLL(string val){
            Node* node = head;
            while ( node != NULL ){
                if ( node->getWord() == val )
                    return true;
                node = node->getNext();
            }
            return false;
        }
        void append(string word){
            Node* temp = new Node(word);
            if ( head == NULL ){
                head = temp;
                tail = temp;
            }
            else{
                tail->setNext(temp);
                tail = tail->getNext();
            }
        }
        int length(){
            int c = 0;
            Node* tmp = head;
            while ( tmp != NULL ){
                c++;
                tmp = tmp->getNext();
            }
            return c;
        }
        void remove(Node* prev){
            Node* next = prev->getNext();
            next = next->getNext();
            prev->setNext(next);
        }
        void removeHead(){
            head = head->getNext();
        }
        void removeTail(){
            Node* node = head;
            Node* node2 = node->getNext();
            while ( node2->getNext() != nullptr ){
                node = node->getNext();
                node2 = node2->getNext();
            }
            node->resetNext();
        }
        void printLL(){
            Node* node = head;
            while ( node != NULL ){
                cout << node->getWord() << " ";
                node = node->getNext();
            }
            cout << endl;
        }
        void printLL(int num){
            Node* node = head;
            for (int i = 0; i < num; i++){
                cout << node->getWord() << " ";
                node = node->getNext();
            }
            cout << endl;
        }
    private:
        Node* head; // should this be NULL?
        Node* tail;
};

class CharInfo{
    public:
        void resetInfo(){
            for ( int i = 0; i<26; i++ ){ chars[i] = 0; }   
        }
        void updateInfo(LinkedList words){
            Node* word = words.getHead();
            while ( word != NULL ){
                for ( int i = 0; i<5; i++ ){
                    chars[charToInt(word->getChar(i))]++;
                }
                word = word->getNext();
            }
        }
        int frequency(int i){
            return chars[i];
        }
        void printChars(){
            for ( int i = 0; i<26; i++ ){
                cout << chars[i] << endl;
            }
        }
        int getWordScore(string word){
            int score = 0;
            char usedChars[5];
            for ( int i = 0; i<5; i++ ){
                if ( i > 0 ){ // don't check for first letter
                    if ( charInArray(usedChars, i, word[i]) == false )
                        score += frequency(charToInt(word[i]));
                }
                else
                    score += frequency(charToInt(word[i]));
                usedChars[i] = word[i];
            }
            return score;
        }
        void updateKnowns(string guess, string results){
            for ( int i = 0; i<5; i++ ){
                string letter = "";
                letter.push_back(guess[i]);
                if ( results[i] == 'X' ){
                    notInWord.append(letter);
                }
                else if ( results[i] == 'Y' ){
                    yellows[i].append(letter);
                    if ( inWord.inLL(letter) == false ){
                        inWord.append(letter);
                    }
                }
                else if ( results[i] == 'G' ){
                    correctPos[i] = guess[i];
                }
            }
        }
        char* getCorrectPos(){
            char* CPptr;
            CPptr = correctPos;
            return CPptr;
        }
        LinkedList* getInWord(){
            LinkedList* IWptr;
            IWptr = &inWord;
            return IWptr;
        }
        LinkedList* getNotInWord(){
            LinkedList* NIWptr;
            NIWptr = &notInWord;
            return NIWptr;
        }
        LinkedList* getYellows(){
            LinkedList* Yptr;
            Yptr = yellows;
            return Yptr;
        }

    private:
        // represents frequency of the 26 letters
        int chars[26] = {};
        char correctPos[5] = {'*', '*', '*', '*', '*'}; // can i just do {'*'}?
        LinkedList inWord;
        LinkedList notInWord;
        LinkedList yellows[5];
};

// checks the green letters
// Returns true if it should be removed
bool wrongCorrectPos(string word, char correctPos[]){
        for ( int i = 0; i<5; i++ ){
        if ( correctPos[i] != '*' && correctPos[i] != word[i] ){
            return true;
        }
    }
    return false;
}

// checks if a letter is repeated when it is already known to be yellow in that spot
bool repeatYellow(string word, LinkedList yellows[]){
    for ( int i = 0; i<5; i++ ){
        string letter = "";
        letter.push_back(word[i]);
        if ( yellows[i].inLL(letter) ){
            return true;
        }
    }
    return false;
}

// checks the gray letters (known not to be in the word)
bool checkWrongChars(string word, LinkedList* notInWord){
    Node* node = notInWord->getHead();
    while ( node != NULL ){
        char val = node->getWord()[0];
        if ( charInString(word, val) )
            return true;
        node = node->getNext();
    }
    return false;
}

// ensures that yellow characters are in the word somewhere
bool checkCharsInWord(string word, LinkedList* inWord){
    Node* node = inWord->getHead();
    while ( node != NULL ){
        char val = node->getWord()[0];
        if ( charInString(word, val) == false )
            return true;
        node = node->getNext();
    }
    return false;
}

bool isRemoved(string word, CharInfo data){
    if ( 
         wrongCorrectPos(word, data.getCorrectPos()) ||
         repeatYellow(word, data.getYellows()) ||
         checkWrongChars(word, data.getNotInWord()) ||
         checkCharsInWord(word, data.getInWord())
       )
        return true;
    return false;
}

void filterLL(CharInfo data, LinkedList* words){
    Node* node = words->getHead();
    Node* prev = words->getHead();
    int c = 0;
    bool headFlag = true; // checks if the current node is still the head
    while ( node != NULL ){
        if ( isRemoved(node->getWord(), data) ){
            if ( node->getNext() == nullptr ){ // tail
                words->removeTail();
                break;
            }
            else if ( headFlag ){ // head
                words->removeHead();
                node = words->getHead();
                prev = words->getHead();
            }
            else{ // not head or tail
                node = node->getNext();
                words->remove(prev);
            }
        }
        else{
            node = node->getNext();
            if ( headFlag == false )
                prev = prev->getNext();
            headFlag = false;
        }
        c++;
    }
}

string getBestWord(LinkedList words, CharInfo data){
    int max = 0;
    string bestWord;
    Node* word = words.getHead();
    while ( word != NULL){
        int score = data.getWordScore(word->getWord());
        if ( score > max ){
            max = score;
            bestWord = word->getWord();
        }
        word = word->getNext();
    }
    return bestWord;
}

string guessResults(){
    cout << "Enter 5 characters representing the results of your guess." <<
        " Enter 'G' for green (correct position), 'Y' for yellow (incorrect position),"
        << " or 'X' if the letter was not in the word." << endl;
    string results;
    cin >> results;
    string capResults;
    for (int i = 0; i<5; i++){
        capResults.push_back(toupper(results[i]));
    }
    return capResults;
}

void test(){
    // charToInt
    cout << "charToInt: 0, 10, 25" << endl;
    cout << charToInt('a') << ", " << charToInt('k') <<
        ", " << charToInt('z') << endl;
    // charInArray
    cout << "--------\ncharInArray: true, false" << endl;
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << charInArray(letters, 5, 'e') << ", " << charInArray(letters, 5, 'f') << endl;
    // LinkedList.remove
    cout << "--------\nLinkedList.remove: 1 2 3 4 5 --> 1 2 4 5" << endl;
    LinkedList letterLL;
    for ( int i = 1; i<6; i++ ){
        letterLL.append(to_string(i));
    }
    letterLL.printLL();
    Node* prevRemove = letterLL.getHead()->getNext();
    letterLL.remove(prevRemove);
    letterLL.printLL();
    // CharInfo.updateKnowns
    cout << "--------\nCharInfo.updateKnowns: v * * * e, a z, b c d w x y" << endl;
    CharInfo testCharInfo;
    testCharInfo.updateKnowns("abcde", "YXXXG");
    testCharInfo.updateKnowns("vwxyz", "GXXXY");
    char* knowns = testCharInfo.getCorrectPos();
    LinkedList* inWord = testCharInfo.getInWord();
    LinkedList* notInWord = testCharInfo.getNotInWord();
    for ( int i = 0; i < 5; i++ ){ cout << knowns[i] << " ";}
    cout << endl;
    inWord->printLL();
    notInWord->printLL();
    // deleting from linked list
    cout << "--------\nDeleting from linked list: 2 3 4 5 6 7 8 9 10, 2 3 4 5 6 7 8 9, 2 3 4 6 7 8 9" << endl;
    LinkedList deleteLL;
    for (int i = 1; i<11; i++){
        deleteLL.append(to_string(i));
    }
    deleteLL.printLL();
    deleteLL.removeHead();
    deleteLL.printLL();
    deleteLL.removeTail();
    deleteLL.printLL();
    Node* node = deleteLL.getHead();
    while (node->getWord() != "4"){
        node = node->getNext();
    }
    deleteLL.remove(node);
    deleteLL.printLL();
    // stuff to be removed
    cout << "--------\nChecking if element should be removed: " << endl;
    CharInfo removeCharInfo;
    removeCharInfo.updateKnowns("abcde", "GYXXY");
    cout << "Known info: pos[0] == a.  Testing word bbbbb - return 1" << endl;
    cout << wrongCorrectPos("bbbbb", removeCharInfo.getCorrectPos()) << endl;
    cout << "Testing word abbbb - return 0" << endl;
    cout << wrongCorrectPos("abbbb", removeCharInfo.getCorrectPos()) << endl;
    cout << "Checking a repeat yellow" << endl;
    cout << "Word: abcde - return 1" << endl;
    cout << repeatYellow("abcde", removeCharInfo.getYellows()) << endl;
    cout << "Word: acbde - return 0" << endl;
    cout << repeatYellow("acbde", removeCharInfo.getYellows()) << endl;
    cout << "Checking a letter that is known gray" << endl;
    cout << "Word: caaaa - return 1" << endl;
    cout << checkWrongChars("caaaa", removeCharInfo.getNotInWord()) << endl;
    cout << "Word: aaaaa - return 0" << endl;
    cout << checkWrongChars("aaaaa", removeCharInfo.getNotInWord()) << endl;
    cout << "Making sure all yellows are in the word" << endl;
    cout << "Word: baaaa - return 1" << endl;
    cout << checkCharsInWord("baaaa", removeCharInfo.getInWord()) << endl;
    cout << "Word: eaaaa - return 1" << endl;
    cout << checkCharsInWord("eaaaa", removeCharInfo.getInWord()) << endl;
    cout << "Word: beaaa - return 0" << endl;
    cout << checkCharsInWord("beaaa", removeCharInfo.getInWord()) << endl;
    cout << "--------\ntesting isRemoved" << endl;
    cout << "word: abzez (yellow in repeat spot) - 1" << endl;
    cout << isRemoved("abzzz", removeCharInfo) << endl;
    cout << "word: bzbez (green wrong) - 1" << endl;
    cout << isRemoved("bzbez", removeCharInfo) << endl;
    cout << "word: acbez (uses a gray)  - 1" << endl;
    cout << isRemoved("acbez", removeCharInfo) << endl;
    cout << "word: azbzz (doesn't use all yellows) - 1" << endl;
    cout << isRemoved("azbzz", removeCharInfo) << endl;
    cout << "word: azbez (correct) - 0" << endl;
    cout << isRemoved("azbez", removeCharInfo) << endl;
}

void playGame(){
    LinkedList words("guesses.txt");
    LinkedList answers("answers.txt");
    LinkedList* wordsptr = &words;
    LinkedList* answersptr = &answers;
    string results;
    string guess;
    CharInfo data;

    for ( int i = 0; i<6; i++ ){
        data.updateInfo(words);
        int answersLength = answers.length();
        cout << "--------\nGuess " << i+1 << "\n--------" << endl;
        cout << "Number of guessable words: " << words.length() <<
            "\nNumber of possible answers: " << answersLength << endl;
        if ( answersLength <= 10 )
            guess = getBestWord(answers, data);
        else
            guess = getBestWord(words, data);

        cout << "You should guess: " << guess << endl;
        results = guessResults();
        if ( results == "GGGGG" ){
            cout << "Found the word in " << i+1 << " guesses." << endl;
            break;
        }
        data.updateKnowns(guess, results); 

        filterLL(data, wordsptr);
        filterLL(data, answersptr);
  /*      
        char* corPos = data.getCorrectPos();
        LinkedList* iw = data.getInWord();
        LinkedList* niw = data.getNotInWord();
        LinkedList* y = data.getYellows();
        cout << "CORRECT POSITION: " << endl;
        for (int i = 0; i<5; i++){ cout << corPos[i] << " "; } cout << endl;
        cout << "IN WORD: " << endl;
        iw->printLL();
        cout << "NOT IN WORD: " << endl;
        niw->printLL();
        cout << "YELLOWS: " << endl;
        for (int i = 0; i<5; i++){y[i].printLL();}
*/
        
        data.resetInfo();
    }
}

string autoGetResults(string answer, string guess){
    string results;
    for ( int i = 0; i<5; i++ ){
        if ( answer[i] == guess[i] )
            results.push_back('G');
        else if ( charInString(answer, guess[i]) )
            results.push_back('Y');
        else
            results.push_back('X');
    }
    return results;
}

int autoPlayGame(string answer){
    LinkedList words("guesses.txt");
    LinkedList answers("answers.txt");
    LinkedList* wordsptr = &words;
    LinkedList* answersptr = &answers;
    string results;
    string guess;
    CharInfo data;
    int c = 1;
    while ( results != "GGGGG" ){
        data.updateInfo(words);
        if ( answers.length() <= 10 ){
            guess = getBestWord(answers, data);
        }
        else
            guess = getBestWord(words, data);

        results = autoGetResults(answer, guess);
        if ( results == "GGGGG" )
            return c;
        data.updateKnowns(guess, results);
        filterLL(data, wordsptr);
        filterLL(data, answersptr);
        data.resetInfo();
        c++;
    }
    return -1;
}

void analysis(){
    LinkedList possibilities("answers.txt");
    Node* word = possibilities.getHead();
    int data[9] = {0};
    int sum = 0;
    int maxSum;
    cout << "Enter max sum: ";
    cin >> maxSum;
    while ( word != NULL && sum < maxSum ){
        int guesses = autoPlayGame(word->getWord());
        if ( guesses > 6 )
            cout << word->getWord() << endl;
        sum += guesses;
        data[guesses-1] += 1;
        word = word->getNext();
    }
    cout << "Total answers: " << possibilities.length() << endl;
    cout << "Total guesses: " << sum << endl;
    float avg = sum/possibilities.length();
    cout << "Average guesses: " << avg << endl;
    cout << "# guesses: frequency" << endl;
    cout << "----------------------" << endl;
    for ( int i = 0; i<9; i++ ){
        cout << i+1 << ": " << data[i] << endl;
    }
}

int main(){
//    test();
    analysis();
    //playGame();
}

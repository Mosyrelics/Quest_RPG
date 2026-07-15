/* 
Paths of Fate
DIbuat oleh: Moses Marvian Arsata
NIM: 535250050
*/

// kepala
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// deklarasi
string continues; // string sebagai opsi melanjutkan
string character; // string menyimpan nama karakter
int health = 100, mana = 100, gold = 500; // int menyimpan stats
int roleChoice; // int menyimpan kelas player
int choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9; // int menyimpan pilihan player
bool hasStarted = false; // bool menyimpan apakah game sudah start

void next(){ // function untuk memberi perintah tekan enter untuk melanjutkan
    while(true){ // looping untuk input
        if(hasStarted == false){ // jika cerita belum mulai
            cout << "-----------------------------------------------------------";
            cout << endl << "Press enter to continue. ";
        } else { // jika cerita sudah mulai
            cout << "-----------------------------------------------------------";
            cout << endl << "Press enter to continue." << endl;
            cout << "Or type: E to view stats. C to view abilities. Q to view your progress. ";
        }
        getline(cin,continues); // mengambil input
        cout << endl << "===========================================================" << endl;
        if(hasStarted == true){ // jika cerita sudah mulai, maka akan ada fungsi lain
            if(continues == "e" || continues == "E"){ // jika tombol 'e' ditekan, maka akan mengeluarkan stats
                cout << endl << character << endl << "-----------------------------------------------------------" << endl;
                cout << "HP: " << health << endl;
                cout << "Mana: " << mana << endl;
                cout << "Gold: " << gold << endl;
            } else if(continues == "c" || continues == "C"){ // jika tombol 'c' ditekan, maka akan mengeluarkan skill player
                cout << endl;
                if(roleChoice == 1){
                    cout << "Fighter ability: Ability to dodge attacks and fight back enemies.";
                } else if(roleChoice == 2){
                    cout << "Mage ability: Ability to cast spells, which could make a path or could be used on either enemies or self.";
                } else if(roleChoice == 3){
                    cout << "Agility ability: Ability to do risky path that requires good parkour skill.";
                }
                cout << endl;
            } else if(continues == "q" || continues == "Q"){ // jika tombol 'q' ditekan, maka akan memperlihatkan progress
                cout << endl << "Your progress" << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << "Chapter 1: ";
                if(choice1 > 0 && choice1 <= 2 && choice2 > 0 && choice2 <= 2 && choice3 > 0 && choice3 <= 2){
                    cout << "COMPLETE" << endl;
                } else {
                    cout << "INCOMPLETE" << endl;
                }
                cout << "Chapter 2: ";
                if(choice4 > 0 && choice4 <= 2 && choice5 > 0 && choice5 <= 2 && choice6 > 0 && choice6 <= 2){
                    cout << "COMPLETE" << endl;
                } else {
                    cout << "INCOMPLETE" << endl;
                }
                cout << "Chapter 3: ";
                if(choice7 > 0 && choice7 <= 3 && choice8 > 0 && choice8 <= 3 && choice9 > 0 && choice9 <= 3){
                    cout << "COMPLETE" << endl;
                } else {
                    cout << "INCOMPLETE" << endl;
                }
            } else { // jika input lain, maka akan break
                break;
            }
        } else {
            break;
        }
    }
    cout << endl;
}

void checkHP(int hp){ // function untuk mengecek dan mengubah HP
    health += hp; // menambahkan HP
    if(health > 100){ // HP tidak akan melebihi 100
        health = 100;
    }
    if(health <= 0){ // HP tidak akan kurang dari 0
        health = 0;
    }
    cout << "Current HP: " << health << endl; // mengeluarkan info HP
}

void checkMana(int manas){ // function untuk mengecek dan mengubah mana
    mana += manas; // menambahkan mana
    if(mana > 100){ // mana tidak akan lebih dari 100
        mana = 100;
    }
    if(mana <= 0){ // mana tidak akan kurang dari 0
        mana = 0;
        cout << character << " don't have enough mana, so " << character << " lose 15 HP." << endl; // jika player punya 0 mana, maka akan kurang 15 HP
        health -= 15;
    }
    cout << "Current mana: " << mana << endl; // mengelurakan info mana
}

void checkGold(int golds){ // function untuk mengecek dan mengubah gold
    gold += golds; // menambahkan gold
    if(gold <= 0){ // gold tidak akan kurang dari 0
        gold = 0;
    }
    cout << "Current gold: " << gold << endl; // mengeluarkan info gold
}

void encounters(){ // function untuk sistem event encounter
    int numberEncounter = (rand() % 100) + 1; // random encounter 20/30/50
    string encounter;
    if(numberEncounter <= 20){ // deskripsi encounter
        encounter = "Heads or Tails";
    } else if(numberEncounter <= 50){
        encounter = "Rock Paper Scissors";
    } else {
        encounter = "Random math question";
    }
    cout << character << " have encountered an event: " << encounter << "!" << endl;
    next();
    cout << "If you win, " << character << " will get 300 gold. But, if you lose, " << character << " will lose 200 gold and 25 mana." << endl;
    next();
    if(numberEncounter <= 20){ // sistem heads or tails
        int flip = (rand() % 2) + 1;
        int answer;
        cout << "Pick your prediction:" << endl;
        cout << "1. Heads" << endl;
        cout << "2. Tails" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Answer (1/2): ";
        while (true){
            cin >> answer;
            if(answer == 1 || answer == 2){
                break;
            } else {
                while (cin.fail()){
                    cin.clear();    
                    cin.ignore(1000,'\n'); 
                }
                cout << "Invalid input, please type again: ";
            }
        }
        cout << endl << "===========================================================" << endl;
        if(flip == 1){
            if(answer == 1){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        } else {
            if(answer == 2){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        }
    } else if(numberEncounter <= 50){ // sistem rock paper scissors
        int botPick = (rand() % 3) + 1;;
        int answer;
        cout << "Pick your choice:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissor" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Answer (1/2/3): ";
        while (true){
            cin >> answer;
            if(answer == 1 || answer == 2 || answer == 3){
                break;
            } else {
                while (cin.fail()){
                    cin.clear();    
                    cin.ignore(1000,'\n'); 
                }
                cout << "Invalid input, please type again: ";
            }
        }
        cout << endl << "===========================================================" << endl;
        if(botPick == 1){
            if(answer == 1){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        } else if(botPick == 2) {
            if(answer == 2){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
         } else {
            if(answer == 3){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        }
    } else { // sistem random math
        int mathOperator = (rand() % 4) + 1;
        int answer;
        int number1 = (rand() % 100) + 1;
        int number2 = (rand() % 100) + 1;
        if(mathOperator == 1){
            cout << "Please answer this question: " << number1 << " + " << number2;
        } else if(mathOperator == 2){
            cout << "Please answer this question: " << number1 << " - " << number2;
        } else if(mathOperator == 3){
            cout << "Please answer this question: " << number1 << " * " << number2;
        } else {
            cout << "Please answer this question: " << number1 << " / " << number2;
        }
        cout << endl <<"-----------------------------------------------------------" << endl;
        cout << endl << "Answer: ";
        while(true){
            cin >> answer;
            if(answer <= 999999999999){
                break;
            } else {
                while (cin.fail()){
                    cin.clear();    
                    cin.ignore(1000,'\n'); 
                }
                cout << "Invalid input, please type again: ";
            }
        }
        cout << endl << "===========================================================" << endl;
        if(mathOperator == 1){
            if(number1+number2 == answer){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        } else if(mathOperator == 2){
            if(number1-number2 == answer){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        } else if(mathOperator == 3){
            if(number1*number2 == answer){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        } else {
            if(number1/number2 == answer){
                cout << endl << "You answered correctly! Here is 300 gold!" << endl;
                checkGold(300);
            } else {
                cout << endl << "You answered wrong! " << character << " lose 200 gold!" << endl;
                checkGold(-200);
            }
        }
    }
    cin.ignore(1000,'\n');
    next();
    cout << "Encounter over. Story will continue." << endl;
    next();
}


void basecamp(){ // function untuk sistem basecamp sebagai shop
    int buy; // variabel input yang ingin dibeli
    cout << character << " have reached the basecamp. In here, you can buy items." << endl;
    next();
    while(true){
        cout << "SHOP" << endl << "-----------------------------------------------------------" << endl;
        cout << "Gold: " << gold << " / HP: " << health << " / Mana: " << mana << endl;
        cout << "1. Health potion (+25 HP): 250 gold" << endl;
        cout << "2. Mana potion (+35 mana): 300 gold" << endl;
        cout << "3. Mega potion (+15 HP & 20 mana): 350 gold" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Type 1/2/3 to buy, or type 4 to quit: ";
        while(true){
            cin >> buy;
            if(buy == 1 || buy == 2 || buy == 3 || buy == 4){
                break;
            } else {
                while (cin.fail()){
                    cin.clear();    
                    cin.ignore(1000,'\n'); 
                }
                cout << "Invalid input, please type again: ";
            }
        }
        cout << endl << "===========================================================" << endl;
        if(buy == 1){ // mengecek apa yang dibeli
            if(gold >= 250){
                cout << endl << "You have bought Health Potion! +25 HP" << endl;
                checkHP(25);
                checkGold(-250);
                cin.ignore(1000,'\n');
                next();
            } else {
                cout << endl << "Not enough gold!" << endl;
                cin.ignore(1000,'\n');
                next();
            }
        } else if(buy == 2){
            if(gold >= 300){
                cout << endl << "You have bought Mana potion! +35 mana" << endl;
                checkMana(35);
                checkGold(-300);
                cin.ignore(1000,'\n');
                next();
            } else {
                cout << endl << "Not enough gold!" << endl;
                cin.ignore(1000,'\n');
                next();
            }
        } else if(buy == 3){
            if(gold >= 350){
                cout << endl << "You have bought Mega Potion! +15 HP & +20 mana" << endl;
                checkHP(15);
                checkMana(20);
                checkGold(-350);
                cin.ignore(1000,'\n');
                next();
            } else {
                cout << endl << "Not enough gold!" << endl;
                cin.ignore(1000,'\n');
                next();
            }
        } else {
            cout << endl << "You have exited the basecamp. The story will now continue." << endl;
            cin.ignore(1000,'\n'); 
            next();
            break;
        }
    }
}

int main(){ // perjalanan program utama
    
    srand(static_cast<unsigned int>(time(0))); // generasi random

    // judul game
    cout << "Paths of Fate" << endl;
    next();
    cout << "Welcome to Paths of Fate. In this game, you will have to choose your decisions based on the encounters you get." << endl;
    next();

    cout << "Please name your character." << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name: ";
    getline(cin,character);
    cout << endl << "===========================================================" << endl;
    cout << endl << character << ". What an interesting name." << endl;
    next();

    cout << "Please pick " << character << "'s role. (This will be crucial when picking decisions)" << endl;
    cout << "1. Fighter (Ability to fight)" << endl;
    cout << "2. Mage (Abilty to cast spells on situation)" << endl;
    cout << "3. Agility (Ability to do parkour)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Type here (1-3): ";
    while (true){
        cin >> roleChoice;
        if(roleChoice == 1 || roleChoice == 2 || roleChoice == 3){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl;
    cout << endl <<"Very well. " << character << " will begin with 100 HP, 100 mana, and 500 gold. The story will begin now." << endl;
    hasStarted = true;
    cin.ignore(1000,'\n'); 
    next();

    // prologue
    cout << "There once lived a peaceful kingdom called Kingdom of Aeloria. But one day, chaos begins when the Nexus of Aeloria was destroyed by the Shadowland of Velbranth." << endl;
    next();
    cout << character << " has been given the mission to restore the elemental power taken by the Shadowland of Velbranth. " <<  endl;
    next();
    cout << character << " and the troops began their journey to raid the Shadowland of Velbranth." << endl;
    next();

    // chapter 1
    cout << "CHAPTER 1: THE JOURNEY TO THE SHADOWLAND" << endl;
    next();
    cout << "When " << character << " and the troops on their way to the Shadowland of Velbranth, there is two path that can be taken." << endl;
    next();

    // choice 1
    cout << "The path are:" << endl;
    cout << "1. The river with risky jumps, but in the end have planks that can help the troops." << endl;
    cout << "2. The forest with alot of bushes." << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice1;
        if(choice1 == 1 || choice1 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice1 == 1){
        if(roleChoice == 1){
            cout << character << " tried to cross the river, but " << character << "'s skill isn't well trained to do risky jumps." << endl;
            checkMana(-20);
            checkHP(-15);
        } else {
            if(roleChoice == 2){
                cout << character << " used magic ability to move the planks from the other side to create path." << endl;
            } else {
                cout << character << " jumped across the river and lead the troops by making the path with the planks." << endl;
            }
            checkMana(-10);
        }
    } else {
        if(roleChoice == 1){
            cout << "When walking in the forest, horde of Velbranth suddenly appears from the bushes. With " << character << "'s skill, " << character << " and the troops are able to stop them." << endl;
            checkMana(-10);
        } else {
            cout << "When walking in the forest, horde of Velbranth suddenly appears from the bushes. " << character << " were ambushed, but the troops able to fight the horde." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " and the troops continues their path." << endl;
    next();
    cout << "In the hill, there is a bridge that could be taken, but it looks to be ruined, or there is a safer path, but the path is blocked, so it requires energy to unblock it." << endl;
    next();

    // choice 2
    cout << "Which path should " << character << " take?" << endl;
    cout << "1. Broken Bridge" << endl;
    cout << "2. Longer path" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice2;
        if(choice2 == 1 || choice2 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice2 == 1){
        cout << character << " walked the bridge, but suddenly the bridge collapses." << endl;
        checkMana(-20);
        checkHP(-15);
    } else {
            cout << character << " and the troops decided to take the safer path." << endl;
            checkMana(-10);
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << "When " << character << " continues their journey, suddenly there is a random event." << endl;
    next();

    encounters(); // encounter
    
    cout << character << " and the troops continues their journey to the gloomy forest." << endl;
    next();
    cout << "In the gloomy forest, the forest is dark, so " << character << " and the troops walk slowly." << endl;
    next();
    cout << "Suddenly, " << character << " and the troops are surrounded by the hordes." << endl;
    next();

    // choice 3
    cout << "There are two choices:" << endl;
    cout << "1. Fight them" << endl;
    cout << "2. Escape through risky path" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice3;
        if(choice3 == 1 || choice3 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice3 == 1){
        if(roleChoice == 1){
            cout << character << " and troops fights." << endl;
            checkMana(-10);
        } else {
            if(roleChoice == 2){
                cout << character << " used magic ability to freeze the hordes." << endl;
                checkMana(-10);
            } else {
                cout << character << " and troops fights, but " << character << " got injured." << endl;
                checkMana(-20);
                checkHP(-15);
            }
        }
    } else {
        if(roleChoice == 3){
            cout << character << " and the troops escaped through risky path by using " << character << "'s skill." << endl;
            checkMana(-10);
        } else {
            cout << character << " and the troops tried to escape through risky path, but failed, so they are forced to fight back." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " continues their journey and saw the safe zone." << endl;
    next();
    basecamp(); // basecamp

    // chapter 2
    cout << "CHAPTER 2: THE MYSTERIOUS FOREST" << endl;
    next();
    cout << character << " and the troops walk further the forest." << endl;
    next();
    cout << "In this forest, alot of mysterious things appears randomly, which start making " << character << " feel discomfort." << endl;
    next();
    cout << "The eerie sounds in the forest somehow feels haunting." << endl;
    next();
    cout << "Suddenly, a hostile creature approaches " << character << "." << endl;
    next();

    // choice 4
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. Use magic to curse the creature" << endl;
    cout << "2. Fight them" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice4;
        if(choice4 == 1 || choice4 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice4 == 1){
        if(roleChoice == 2){
            cout << character << "'s spells able to make the enemy passive." << endl;
            checkMana(-10);
        } else {
            cout << "Unfortunately, " << character << "'s skills isn't able to do magic spells, so " << character << " is forced to fight back." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    } else {
        if(roleChoice == 1){
            cout << character << " and the troops fights." << endl;
            checkMana(-10);
        } else {
            cout << character << " and the troops fights, but " << character << " got injured." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " continues their path to the deep cave." << endl;
    next();
    cout << "The cave is very dark, so " << character << " had to lit torch." << endl;
    next();
    cout << "When walking the cave, suddenly the torch goes out and some hostile beings comes out of the strange shelter." << endl;
    next();

    // choice 5
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. There is a narrow hole, which can be opened with strength" << endl;
    cout << "2. Fight them" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice5;
        if(choice5 == 1 || choice5 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice5 == 1){
        if(roleChoice == 3){
            cout << character << "'s ability able to dig the hole to continue the journey safely." << endl;
            checkMana(-10);
        } else {
            cout << character << " dig the hole, but because " << character << "'s ability isn't enough to dig the hole faster, " << character << " and the troops were attacked a few times." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    } else {
        if(roleChoice == 1){
            cout << character << " and the troops fights." << endl;
            checkMana(-10);
        } else {
            if(roleChoice == 2){
                cout << character << "'s magic ability isn't enough to stop the creature. But, the troops are able to stop the creature." << endl;
                checkMana(-20);
                checkHP(-15);
            } else {
                cout << character << " and troops fights, but " << character << " got injured." << endl;
                checkMana(-20);
                checkHP(-15);
            }
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " and the troops continues their journey." << endl;
    next();
    cout << "The Shadowland of Velbranth can be seen by the vision." << endl;
    next();
    cout << "Suddenly, a random event appears in the journey." << endl;
    next();

    encounters(); // encounter
    
    cout << character << " and the troops takes a break somewhere in the shelter." << endl;
    next();
    cout << "Suddenly, a random boulder starts to approaching the shelter." << endl;
    next();

    // choice 6
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. Use magic spell to halt the boulder" << endl;
    cout << "2. Use agility skill to push the large stone" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-2): ";
    while (true){
        cin >> choice6;
        if(choice6 == 1 || choice6 == 2){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice6 == 1){
        if(roleChoice == 2){
            cout << character << " freezes the boulder from moving." << endl;
            checkMana(-10);
        } else {
            cout << character << "'s skill isn't able to stop the boulder from moving, so " << character << " and the troops were injured." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    } else {
        if(roleChoice == 3){
            cout << character << " and the troops together pushes the stone to block the boulder." << endl;
            checkMana(-10);
        } else {
            cout << character << "'s skill isn't able to push the stone faster, so " << character << " and the troops were injured." << endl;
            checkMana(-20);
            checkHP(-15);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " and the troops continues their journey and saw a village near Shadowland of Velbranth's gate." << endl;
    next();
    cout << character << " and the troops approaches the village first to get ready for the raid." << endl;
    next();

    basecamp(); // basecamp

    // chapter 3
    cout << "CHAPTER 3: THE SHADOWLAND" << endl;
    next();
    cout << character << "and the troops began approaches the gate." << endl;
    next();
    cout << "The troops began raiding the base. " << character << " approached where the elemental powers are." << endl;
    next();
    cout << "Suddenly, the guards approached " << character << "." << endl;
    next();

    // choice 7
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. Fight them" << endl;
    cout << "2. Use magic spell" << endl;
    cout << "3. Find other risky path" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-3): ";
    while (true){
        cin >> choice7;
        if(choice7 == 1 || choice7 == 2 || choice7 == 3){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice7 == 1){
        if(roleChoice == 1){
            cout << character << " fights the guard." << endl;
            checkMana(-15);
        } else {
            cout << character << "'s skill isn't able to fight the guards, but somehow the guards fall back." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else if(choice7 == 2){
        if(roleChoice == 2){
            cout << character << "'s spell has weaken the guards." << endl;
            checkMana(-15);
        } else {
            cout << character << " isn't able to do the spells, but somehow able to run away from guards and hide." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else {
        if(roleChoice == 3){
            cout << character << " is able to lure down the guards and go with the riskier path." << endl;
            checkMana(-15);
        } else {
            cout << character << "'s skill isn't able to do risky path, so " << character << " got injured." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " continues their path to the castle." << endl;
    next();
    cout << "The door to the elemental powers were founded." << endl;
    next();
    cout << "But the door is locked." << endl;
    next();

    // choice 8
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. Attack the door" << endl;
    cout << "2. Use magic spell" << endl;
    cout << "3. Do the risky jumps" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-3): ";
    while (true){
        cin >> choice8;
        if(choice8 == 1 || choice8 == 2 || choice8 == 3){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice8 == 1){
        if(roleChoice == 1){
            cout << character << " attacks the door and it opens." << endl;
            checkMana(-15);
        } else {
            cout << character << "'s strength isn't enough to open the door, but somehow the door opens on it's own." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else if(choice8 == 2){
        if(roleChoice == 2){
            cout << character << "'s spell unlocks the door." << endl;
            checkMana(-15);
        } else {
            cout << character << " isn't able to do the spells, but somehow the door opens on it's own." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else {
        if(roleChoice == 3){
            cout << character << " finds the path to the room. But after reaching the room, the door somehow opens on it's own." << endl;
            checkMana(-15);
        } else {
            cout << character << "'s skill isn't able to do risky movement, so " << character << " got injured. But somehow, the door opens on it's own." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " approaches the nexus of elemental power." << endl;
    next();
    cout << "Suddenly, " << character << " has been approached by the weird creatures of shadowland." << endl;
    next();

    // choice 9
    cout << "There are things that " << character << " can do:" << endl;
    cout << "1. Fight them" << endl;
    cout << "2. Use magic spell" << endl;
    cout << "3. Destroy the pillar near the door" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Pick your choice (1-3): ";
    while (true){
        cin >> choice9;
        if(choice9 == 1 || choice9 == 2 || choice9 == 3){
            break;
        } else {
            while (cin.fail()){
                cin.clear();    
                cin.ignore(1000,'\n'); 
            }
            cout << "Invalid input, please type again: ";
        }
    }
    cout << endl << "===========================================================" << endl << endl;
    if(choice9 == 1){
        if(roleChoice == 1){
            cout << character << " fights the hostile with the elemental power support." << endl;
            checkMana(-15);
        } else {
            cout << character << " fights the hostile back with the elemental support, but still got injured." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else if(choice9 == 2){
        if(roleChoice == 2){
            cout << character << "'s spell has made the hostile unconscious with the elemental power support." << endl;
            checkMana(-15);
        } else {
            cout << character << " somehow able to make hostile unconscious with elemental power support, but " << character << " got weaken." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    } else {
        if(roleChoice == 3){
            cout << character << " is able to destroy the pillar with the elemental power support and crushes the hostile." << endl;
            checkMana(-15);
        } else {
            cout << character << " somehow able to destroy the pillar with the elemental power support and crushes some hostile, but still requires to fight some hostiles back." << endl;
            checkMana(-25);
            checkHP(-25);
        }
    }
    if(health == 0){
        cout << endl << "===========================================================" << endl << endl;
        cout << "Game over. " << character << " has fallen.";
        return 0;
    }
    cin.ignore(1000,'\n');
    next();

    cout << character << " took the elemental power fully and exit the Shadowland of Velbranth with their troops." << endl;
    next();
    cout << character << " returns to the Kingdom of Aeloria with their troops and restores the nexus power." << endl;
    next();
    cout << "With the nexus power restored, the Kingdom of Aeloria went back to peace." << endl;
    next();

    // credits
    cout << "THE END" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Made by Moses Marvian Arsata" << endl;
    return 0;
}
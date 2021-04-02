#include <stdio.h> //Mengimpor file stdio.h
#include <time.h> // Mengimpor file time.h

//16020053 Karina Widya Ramadhani
//16020071 Ariansyah
//16020129 Muhammad Ihsan Abdul Hakim

//global int
int x,y;
int a,b;
int up = 0, down = 0;
int left = 0, right = 0;
int robothealth = 100;
int kecoakhealth = 0;
int count = 0;
int q = 0, w = 0;

//fungsi perpangkatan
float pangkat(int i, int l){
    if(l==0){
        return 1;
    }
    else
        return i * pangkat(i,l-1);
}
// Absoulte Function
int Abs(int m){
    if (m>=0){
    return m = m;
    }
    else;
    return m*(-1);
}
//vektor jarak a kuadrat + b kuadrat
int vektor(int p, int q){
    return (pangkat(p,2) + pangkat(q,2));
}
void findPos(int dir)
{
    //Counts each direction
    if (dir == 7){
        q++;
    }
    else if (dir == 8){
        q--;
    }
    else if (dir == 6){
        w--;
    }
    else if (dir == 9){
        w++;
    }
    //In case of illegal character in the string
    if (q<0 || w<0)
    {
        printf("Robot diluar jangkauan, silahkan ulangi kembali.\n");
    }
    else if (w == a && q == b)
    {
        printf("Robot menabrak kecoak, silahkan ulangi kembali.\n");
    }
    else{
        if (dir == 7){
            up++;
        }
        else if (dir == 8){
            down++;
        }
        else if (dir == 6){
            left++;
        }
        else if (dir == 9){
            right++;
        }
    }
     //Final position of robot
    x = right - left;
    y = up - down;
    q = y;
    w = x;
    ;
}
   /* Intializes random number generator */
void spawn()
{
    time_t t;
    kecoakhealth = 20;
    srand((unsigned) time(&t));
    /* Random koordinat untuk spawn kecoak dengan syarat syarat tertentu */
    while(1){
        a = x + 1 + rand() % 20 - rand()%20;
        b = y + 1 + rand() % 20 - rand()%20;
        if (a>0 && b>0 && a!=x && b!=y)
        {
            break;
        }
    }
    printf("\nKecoak baru telah muncul");
}
    // The accuracy of robot firing
void Fire(int h, int v){

    if(vektor(h,v) <= pangkat(3,2)){
        kecoakhealth -= 5;
        printf("Serangan kena, HP kecoak berkurang menjadi %d\n", kecoakhealth);
    }
    else
        printf("Diluar jangkauan\n");

    if(kecoakhealth <= 0 && robothealth> 0){
        printf("Mission Complete\n");
    }
    else if (robothealth == 0){
        printf("Game Over\n");
    }
}
void InactivateRobot(){
    printf("\nGame Over\n");
    printf("Kamu berhasil membasmi %d kecoak\n", count);
}
void KecoakMoveset(){
    //Cek jarak
    if (vektor(a-x,b-y)<=2)
    //Kecoak attack
    {
        printf("Kecoak Attack\n");
        robothealth-=3;
        printf("Sisa HP robot %d\n", robothealth);
    }
    else{
    //Kecoak move
        if (a-x>1 || a-x<-1){
            if(a<x){
                ++a;
            }
            if(a>x){
                --a;
            }
        }
        if (b-y>1 || b-y<-1){
            if(b<y){
                ++b;
            }
            if(b>y){
                --b;
            }
        }
        printf("Kecoak terbang mendekati robot\n");
        printf("Kecoak sekarang berada di koordinat ");
        printf("(%d,%d)\n", a,b);
    }
    
}

void Menu(){
    printf("\n=============================");
    printf("\nPosisi robot: ");
    printf("(%d,%d)", x,y);
    printf("\nKecoak terdeteksi di: ");
    printf("(%d,%d)", a,b);

    printf("\nJarak robot dengan kecoak");
    printf("\nJarak horizontal : %d", abs(a-x));
    printf("\nJarak vertikal: %d\n", abs(b-y));

    printf("\nHP Robot : %d", robothealth);
    printf("\nHP Kecoak : %d\n", kecoakhealth);

    printf("\nRobot Control\n");
    printf("1. Moving\n");
    printf("2. Shooting\n");
    printf("3. Inactivating\n");
    printf("\nChoose your choice: ");
}

int main(){
    int dir;
    int choice;
    spawn();
    while (robothealth > 0){
        if (kecoakhealth <= 0){
            printf("Kecoak is dead\n");
            spawn();
            ++count;
        }
        Menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nPress 7 to Go Forward");
            printf("\nPress 8 to Go Backward");
            printf("\nPress 9 to Go Right");
            printf("\nPress 6 to Go Left");
            printf("\nEnter the Direction String:  ");
            scanf("%d", &dir);

            //Function call to calculate position
            findPos(dir);
            break;
        case 2:
            //Function call to take hit and miss of shooting programm
            Fire(x-a,y-b);
            break;
        case 3:
            robothealth = -1;
            printf("Robot dimatikan");
            break;
        }
        if (kecoakhealth < 20 && kecoakhealth >0 ){
            KecoakMoveset();
        }
    }
    if (robothealth = 0){
        printf("Robot telah meninggal\n");
    }
    InactivateRobot();
    return 0;
}

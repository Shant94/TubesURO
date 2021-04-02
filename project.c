#include <stdio.h> //Mengimpor file stdio.h
#include <stdlib.h> // Mengimpor file stdlib.h
#include <time.h> // Mengimpor file time.h

//global int
int x,y;
int a,b;
int up = 0, down = 0;
int left = 0, right = 0;
int robothealth = 100;
int kecoakhealth = 0;
int count = 0;

//fungsi perpangkatan
float pangkat(int i, int l){
    if(l==0){
        return 1;
    }
    else
        return i * pangkat(i,l-1);
}
//vektor jarak a kuadrat + b kuadrat
int vektor(int p, int q){
    return (pangkat(p,2) + pangkat(q,2));
}
void findPos(char *dir)
{
    int i;

    for (i = 0; dir[i] != '\0' ; i++) {

        //Counts each direction1
        if (dir[i] == 'U' || dir[i] == 'u')
            up++;
        else if (dir[i] == 'D' || dir[i] == 'd')
            down++;
        else if (dir[i] == 'L' || dir[i] == 'l')
            left++;
        else if (dir[i] == 'R' || dir[i] == 'r')
            right++;

          //In case of illegal character in the string
        else
        {
            printf("Position Unable to Find, Enter Correct Direction.");
            break;
        }
    }

    //Final position of robot
    x = right - left;
    y = up - down;
   ;
}


    /* Intializes random number generator */
void spawn()
{
    time_t t;
    kecoakhealth = 20;
    srand((unsigned) time(&t));
    /* Print 2 random numbers from 0 to 100 */
    a = rand() % 100;
    b = rand() % 100;
    printf("\nKecoak baru telah muncul");


}
    // The accuracy of robot firing
void Fire(int h, int v){
    int hit = 0;
    int miss = 0;

    if(vektor(h,v) <= pangkat(3,2)){
    hit += 1;
    kecoakhealth -= 5;
    }
    else
        miss += 1;

    if(hit >= 20 & kecoakhealth <= 0|| robothealth> 0){
        printf("Mission Complete\n");
    }
    else if (robothealth == 0){
        printf("Game Over\n");
    }
}
void InactivateRobot(){
    printf("Game Over\n");
    printf("Kamu berhasil membasmi %d kecoak", count);
}
void KecoakMoveset(){
    //Cek jarak
    if (vektor(a-x,b-y)<=2)
    //Kecoak attack
    {
        printf("Kecoak Attack");
        robothealth-=2;
        printf("Sisa HP robot %d", robothealth);
    }
    else{
    //Kecoak move
        if (a-x>1 || a-x<-1){
            if(a<x){
                a+=1;
            }2
            if(a>x){
                a-=1;
            }
        }
        if (b-y>1 || b-y<-1){
            if(b<y){
                b+=1;
            }
            if(b>y){
                b-=1;
            }
        }
        printf("Kecoak terbang/n Kecoak sekarang berada di koordinat (");
        printf("%d", (a));
        printf(",%d", (b));
        printf(")");
    }
}
void Menu(){
    printf("\nPosisi robot: (");
    printf("%d", (x));
    printf(",%d", (y));
    printf(")");

    printf("\nKecoak terdeteksi di (");
    printf("%d,", a);
    printf("%d)", b);

    printf("\nJarak robot dengan kecoak");
    printf("\nJarak horizontal : %d", a-x);
    printf("\nJarak vertikal: %d\n", b-y);

    printf("\nHP Robot : %d", robothealth);
    printf("\nHP Kecoak : %d\n", kecoakhealth);

    printf("\nRobot Control\n");
    printf("1. Moving\n");
    printf("2. Shooting\n");
    printf("3. Inactivating\n");
    printf("\nChoose your choice: ");
}

int main(){
    char *dir;
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
            printf("Enter the Direction String:  ");
            scanf("%s", &dir);

            //Function call to calculate position
            findPos(&dir);
            break;
        case 2:
            //Function call to take hit and miss of shooting programm
            Fire(x-a,y-b);
            break;
        case 3:
            break;
        default:
        break;
        }
        if (kecoakhealth < 20 && kecoakhealth >0 ){
            KecoakMoveset();
        }
    }
    printf("Robot telah meninggal\n");
    InactivateRobot();
    return 0;
}

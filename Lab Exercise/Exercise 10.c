#include<stdio.h>
// Function Calculates the specific line 
int giveLine(int zNo, int lineNumber){
    if(zNo==1)
        lineNumber = lineNumber + 0;
    else if(zNo==2)
        lineNumber = lineNumber + 12;
    else if(zNo==3)
        lineNumber = lineNumber + 24;
    else if(zNo==4)
        lineNumber = lineNumber + 36;
    else if (zNo==5)
        lineNumber = lineNumber + 48;
    else{
        printf("Sorry no more fortunes for you :(");
        return 0;
    }
    FILE *file = fopen("data.for", "rb+");
    int count = 0;
    if(file!=NULL){
        char line[256]; // Assigns a size for the line or fortune sentence
        while (fgets(line, sizeof line, file) != NULL){   // traverses through the list 
            if (count == lineNumber-1){  // if the counter corresponds to the linenumber 
                printf("%s", line);
                fclose(file);
                return 0;
            }   
            else
                count++;   
        }   
        fclose(file);
    }
}
int zodiac(int month, int day){
    FILE* input = fopen("data.in","rb");
    int fMonth, fYear, fDay;
    int Aqu=0, Pis=0, Ari=0, Tau=0, Gem=0, Can=0, Leo=0, Vir=0, Lib=0, Sco=0, Sag=0, Cap=0;    
    int AqL=1, PiL=2, ArL=3, TaL=4, GeL=5, CaL=6, LeL=7, ViL=8, LiL=9, ScL=10, SaL=11, CapL=12; 
    if(month == 1 && day >= 20 || month == 2 &&  day<= 18){
        // Aquarius
        printf("Aquarius: "); 
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 1 && fDay >= 20 || fMonth == 2 &&  fDay <= 18)
                Aqu++;
        }
        giveLine(Aqu, AqL);
        fclose(input);
        return 0;
    }
    else if(month == 2 && day >= 19 || month == 3 &&  day <= 20){
        // Pisces
        printf("Pisces: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 2 && fDay >= 19 || fMonth == 3 &&  fDay <= 20)
                Pis++;
        }
        giveLine(Pis, PiL);
        fclose(input);
        return 0;
    }
    else if(month == 3 && day >= 21 || month == 4 &&  day<= 19){
        // Aries
        printf("Aries: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 3 && fDay >= 21 || fMonth == 4 &&  fDay <= 19)
                Ari++;
        }
        giveLine(Ari, ArL);
        fclose(input);
        return 0;
    }
    else if(month == 4 && day >= 20 || month == 5 &&  day<= 20){
        // Taurus
        printf("Taurus: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 4 && fDay >= 20 || fMonth == 5 &&  fDay <= 20)
                Tau++;
        }
        giveLine(Tau, TaL);
        fclose(input);
        return 0;
    }
    else if(month == 5 && day >= 21 || month == 6 &&  day<= 20){
        // Gemini   
        printf("Gemini: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 5 && fDay >= 21 || fMonth == 6 &&  fDay <= 20)
                Gem++;
        }
        giveLine(Gem, GeL);
        fclose(input);
        return 0;
    }
    else if(month == 6 && day >= 21 || month == 7 &&  day<= 22){
        // Cancer
        printf("Cancer: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 6 && fDay >= 21 || fMonth == 7 &&  fDay <= 22)
                Can++;
        }
        giveLine(Can, CaL);
        fclose(input);
        return 0;
    }
    else if(month == 7 && day >= 23 || month == 8 &&  day<= 22){
        // Leo
        printf("Leo: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 7 && fDay >= 23 || fMonth == 8 &&  fDay <= 22)
                Leo++;
        }
        giveLine(Leo, LeL);
        fclose(input);
        return 0;
    }
    else if(month == 8 && day >= 23 || month == 9 &&  day<= 22){
        // Virgo   
        printf("Virgo: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 8 && fDay >= 23 || fMonth == 9 &&  fDay <= 22)
                Vir++;
        }
        giveLine(Vir, ViL);
        fclose(input);
        return 0;
    }
    else if(month == 9 && day >= 23 || month == 10 &&  day<= 22){
        // Libra
        printf("Libra: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 9 && fDay >= 23 || fMonth == 10 &&  fDay <= 22)
                Lib++;
        }
        giveLine(Lib, LiL);
        fclose(input);
        return 0;
    }
    else if(month == 10 && day >= 23 || month == 11 &&  day<= 21){
        // Scorpio
        printf("Scorpio: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 10 && fDay >= 23 || fMonth == 11 &&  fDay <= 21)
                Sco++;
        }
        giveLine(Sco, ScL);
        fclose(input);
        return 0;
    }
    else if(month == 11 && day >= 22 || month == 12 &&  day<= 21){
        // Sagittarius
        printf("Sagittarius: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 11 && fDay >= 22 || fMonth == 12 &&  fDay <= 21)
                Sag++;
        }
        giveLine(Sag, SaL);
        fclose(input);
        return 0;
    }
    else if(month == 12 && day >= 22 || month == 1 &&  day<= 19){
        // Capricorn
        printf("Capricorn: ");
        while(fscanf(input, "%04d-%02d-%02d", &fYear, &fMonth, &fDay)!=EOF){
            if(fMonth == 12 && fDay >= 22 || fMonth == 1 &&  fDay <= 19)
                Cap++;
        }
        giveLine(Cap, CapL);
        fclose(input);
        return 0;
    }
}
int main(){
    FILE* input = fopen("data.in","ab+");
    int day, year, month;
    printf("Enter input: "); scanf("%04d-%02d-%02d", &year, &month, &day);
    fprintf(input, "%04d-%02d-%02d\n", year, month, day);
    fclose(input);
    zodiac(month, day);
}
// IAEDcalc.C 1.0
// Created by Nuno Florência(ist1105865) || IST-LETI 2022/23
//
// Contacts
// Email: nuno.v.florencia@gmail.com
// GitHub: spokiris
// IG: nuno.florencia


#include <stdio.h>
#include <math.h>

float proj() {
    float p1, p2, tp;
    while (1) {
        printf("nota p1: ");
        scanf("%f", &p1);
        printf("nota p2: ");
        scanf("%f", &p2);
        printf("nota TP: ");
        scanf("%f", &tp);
        if (0 <= p1 && p1 <= 20 && 0 <= p2 && p2 <= 20 && 0 <= tp && tp <= 20) {
            break;
        } else {
            printf("As notas têm de estar entre 0 e 20.\n");
        }
    }
    float avg = (p1 + p2) / 2;
    float min = (avg < tp) ? avg : tp;
    float sqrt_abs = sqrt(fabs(avg - tp) / 2);
    return min + sqrt_abs;
}

float labs() {
    float labs;
    while (1) {
        printf("nota labs: ");
        scanf("%f", &labs);
        if (0 <= labs && labs <= 20) {
            break;
        } else {
            printf("A nota tem de estar entre 0 e 20.\n");
        }
    }
    return labs;
}

float exame() {
    float exa;
    while (1) {
        printf("nota exame: ");
        scanf("%f", &exa);
        if (0 <= exa && exa <= 20) {
            break;
        } else {
            printf("A nota tem de estar entre 0 e 20.\n");
        }
    }
    return exa;
}

float calcula() {
    float l = labs();
    float e = exame();
    float p = proj();
    return l * 0.3 + e * 0.3 + p * 0.4;
}

float calcula_exame() {
    float tg;
    while (1) {
        printf("nota final target: ");
        scanf("%f", &tg);
        if (0 <= tg && tg <= 20) {
            break;
        } else {
            printf("A nota tem de estar entre 0 e 20.\n");
        }
    }
    float p = proj();
    float l = labs();
    float na = p * 0.4 + l * 0.3;
    if (na >= tg) {
        printf("ARDEU!!!\nprecisas de %.2f\n", na);
    } else {
        return (tg - na) / 0.3;
    }
}

int main() {
    printf("-enter \"h\" para exibir definicoes\n");
    
    while (1) {
        
        printf("IAEDcalc> ");
        char user_input;
        scanf(" %c", &user_input);
        
        if (user_input == 'e') {
            float nota_necessaria = calcula_exame();
            
            if (nota_necessaria != 0) {
                printf("Nota necessária no exame: %.2f\n", nota_necessaria);
            }
        } 
        else if (user_input == 'c') {
            float nota_final = calcula();
            printf("Nota final: %.2f\n", nota_final);
        } 
        else if (user_input == 'q') {
            break;
        } 
        else if (user_input == 'h') {
            printf("-enter \"e\" para calcular a nota necessária no exame\n"
                   "-enter \"c\" para calcular a nota final\n");
        } 
        else {
            printf("-enter \"h\" para mostrar as definicoes validas");
        }
    }
    return 0;
}



#include <stdio.h>
#include <ctype.h>
#define TARIF0 35
#define TARIF1 37
#define TARIF2 40
#define TARIF3 45

double totalSalary(int clock, double tarif);
double taxes(double cash);
void output(double totalAmountOfCharges, double taxes, double netSalary);
double menu(); //Switch function matching TARIFS or -1 if 5(end)
int checkMenu(); //Only numbers 1-5 are allowed

int main()
{
    int clock;
    double totalAmountOfCharges, numberOfTaxes, netSalary;
    double tarif = 10.0;


    printf("Ile godzin pracowałeś w tym tygodniu?\n");
    scanf("%d", &clock);
    while ((tarif = menu()) != -1.0)
    {
        totalAmountOfCharges = totalSalary(clock, tarif);
        numberOfTaxes = taxes(totalAmountOfCharges);
        netSalary = totalAmountOfCharges - numberOfTaxes;
        output(totalAmountOfCharges, numberOfTaxes, netSalary);
    }
    printf("Do widzenia.\n");

    return 0;
}


double menu()
{
    int numberMenu;
    double tarifMenu;

    printf("\n***********************************************************************\n");
    printf("Podaj liczbe odpowiadajaca zadanej stawce wynagrodzenia lub opcji:\n");

    printf("1) $%.2d                  2) $%.2d \n", TARIF0, TARIF1);
    printf("3) $%.2d                  4) $%.2d \n5) KONIEC\n", TARIF2, TARIF3);
    printf("***********************************************************************\n");
    while (numberMenu = checkMenu())
    {
        switch (numberMenu)
        {
            case 1:
                tarifMenu = TARIF0;
                break;
            case 2:
                tarifMenu = TARIF1;
                break;
            case 3:
                tarifMenu = TARIF2;
                break;
            case 4:
                tarifMenu = TARIF3;
                break;
            case 5:
                tarifMenu = -1;
                break;
            default:
                tarifMenu = 0;
        }
        if (tarifMenu != 0)
            break;
        else
            printf("Wprowadzono nieprawidłową wartość!!!\n");
    }
    return tarifMenu;
}

int checkMenu()
{
    int check;

    while (scanf("%d", &check))
    {
        if ((check >= 1) && (check <= 5))
            break;
        else
        {
            printf("Wprowadzono nieprawidłową wartość!\n");
            continue;
        }
    }
    return check;
}


double totalSalary(int clock, double tarif)
{
    if (clock > 40)
        return ((clock - 40) * 1.5 * tarif) + tarif * 40;
    else
        return tarif * clock;
}

double taxes(double cash)
{
    double taxes;

    taxes = cash * 0.15;
    if (cash > 300 && cash <= 450)
        taxes += (cash - 300) * 0.2;
    else if (cash > 450)
        taxes += (cash - 450) * 0.25;
    return taxes;
}

void output(double totalAmountOfCharges, double taxes, double netSalary)
{
    printf("Brutto = %.2lf.\n", totalAmountOfCharges);
    printf("Podatki %.2lf.\n", taxes);
    printf("Netto = %.2lf\n", netSalary);
}


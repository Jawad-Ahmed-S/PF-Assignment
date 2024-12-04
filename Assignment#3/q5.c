#include <stdio.h>
#include <stdlib.h>

// Due to Lengthy code i have not included input verfication so kindly input the correct types.
int AddSupplies(char **supplies, int *nsupplies)
{
    nsupplies = realloc(nsupplies, (*nsupplies + 1) * sizeof(int));
    if (!nsupplies)
    {
        printf("Memory allocation failed for nsupplies\n");
        return -1;
    }
    supplies = realloc(supplies, (*nsupplies + 1) * sizeof(char *));
    if (!supplies)
    {
        printf("Memory allocation failed for supplies\n");
        return -1;
    }
    supplies[*(nsupplies)-1] = (char *)calloc(10, sizeof(char));
    if (!supplies[*nsupplies - 1])
    {
        printf("Memory allocation failed for supply entry\n");
        return -1;
    }

    printf("Enter the supply: ");
    scanf("%s", supplies[*nsupplies - 1]);

    printf("Added\n");
    return 0;
}
void UpdateSupplies(char **supplies, int nsupplies)
{
    int i;
    printf("Enter the index of the supply to update (0 to %d): ", nsupplies - 1);
    scanf("%d", &i);

    if (i < 0 || i >= nsupplies)
    {
        printf("Invalid index. Please try again.\n");
        return;
    }

    printf("Enter the updated name: ");
    scanf("%s", supplies[i]);

    printf("Supply updated successfully.\n");
}
int DeleteSpecie(char **supplies, int *nsupplies, char **speciesName)
{
    for (int i = 0; i < *nsupplies; i++)
    {
        free(supplies[i]);
        free(speciesName[i]);
    }
    free(supplies);
    *nsupplies = 0;
    printf("All supplies deleted\n");

    return 0;
}
int DisplayInventory(char ***supplies, int *nsupplies, char **speciesName, int nAnimals)
{

    printf("\n\n");
    for (int i = 0; i < nAnimals; i++)
    {
        printf("%s : \n", speciesName[i]);
        for (int j = 0; j < nsupplies[i]; j++)
        {
            printf("%s ,\t", supplies[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{

    printf("Due to Lengthy code i have not included input verfication so kindly input the correct types.\n\n");
    int nAnimals;
    printf("Enter the number of pets");
    scanf("%d", &nAnimals);
    char **speciesName = (char **)calloc(nAnimals, sizeof(char *));
    for (int i = 0; i < nAnimals; i++)
    {
        speciesName[i] = (char *)calloc(10, sizeof(char));
    }
    for (int i = 0; i < nAnimals; i++)
    {
        printf("%d- Enter Specie name : ", i + 1);
        scanf("%s", speciesName[i]);
    }

    int *nsupplies = (int *)calloc(nAnimals, sizeof(int));

    char ***supplies = (char ***)calloc(nAnimals, sizeof(char **));
    for (int i = 0; i < nAnimals; i++)
    {
        printf("Enter the number of supplies for %s", speciesName[i]);
        scanf("%d", (nsupplies + i));
        supplies[i] = (char **)calloc(nsupplies[i], sizeof(char *));

        for (int j = 0; j < nsupplies[i]; j++)
        {
            supplies[i][j] = (char *)calloc(10, sizeof(char));
        }
    }

    for (int i = 0; i < nAnimals; i++)
    {
        for (int j = 0; j < nsupplies[i]; j++)
        {
            printf("Enter supply for %s\n", speciesName[i]);
            scanf("%s", supplies[i][j]);
        }
    }
    int operation;
    int indDelete = 0;
    int ind;
    while (1)
    {

        printf("1) Display Inventory\n");
        printf("2) Delete Specie\n");
        printf("3) Add Supply\n");
        printf("4) Update Supplies\n");

        printf("\nWhat you want to perform?");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            DisplayInventory(supplies, nsupplies, speciesName, nAnimals);
            break;

        case 2:

            for (int i = 0; i < nAnimals; i++)
            {
                printf("%d- %s\n", i + 1, speciesName[i]);
            }
            printf("which specie you want to delete. (Enter index)");
            scanf("%d", &indDelete);
            DeleteSpecie(supplies[indDelete - 1], nsupplies, speciesName);

            for (int i = indDelete - 1; i < (nAnimals); i++)
            {

                speciesName[i] = speciesName[i + 1];
                supplies[i] = supplies[i + 1];
                nsupplies[i] = nsupplies[i + 1];
            }
        case 3:

            AddSupplies(*supplies, nsupplies);
        case 4:
            for (int i = 0; i < nAnimals; i++)
            {
                printf("%d- %s\n", i + 1, speciesName[i]);
            }
            printf("Which specie's supply you want to update? (Enter index): ");
            scanf("%d", &ind);
            if (ind < 1 || ind > nAnimals)
            {
                printf("Invalid species index. Please try again.\n");
                break;
            }

            UpdateSupplies(supplies[ind - 1], nsupplies[ind - 1]);
            break;
        }
    }

    free(speciesName);
    free(nsupplies);
    for (int i = 0; i < nAnimals; i++)
    {
        for (int j = 0; j < nsupplies[i]; j++)
        {
            free(supplies[i][j]);
        }
        free(supplies[i]);
    }
    return 0;
}
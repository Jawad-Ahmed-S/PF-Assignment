#include <stdio.h>
#include <stdlib.h>

// Due to Lengthy code i have not included input verfication so kindly input the correct types.
struct deviceSpecific
{
   int resoution;
   int bandwidth;
   int playback;
};
struct video
{
   char title[20];
   int ratings;
   int runtime;
   char encodingFormat[20];
};
void printSystem(int nUsers, int *nCategories, int ***Users, int *nDeviceSizes, struct deviceSpecific **deviceMatrix, int numCategories, int *nvideos, struct video **V)
{
   for (int i = 0; i < nUsers; i++)
   {
      printf("\n\nUser %d : \n", i + 1);
      printf("========== \n");
      for (int j = 0; j < nCategories[i]; j++)
      {
         printf("Category %d : \n", j + 1);
         printf("--------- \n");

         printf("Veiw Time : %d \n", Users[i][j][0]);
         printf("Like Dislike Ratio : %d \n", Users[i][j][1]);
      }
   }

   for (int i = 0; i < nUsers; i++)
   {
      printf("\n\nUser %d : \n", i + 1);
      printf("========== \n");
      for (int j = 0; j < nDeviceSizes[i]; j++)
      {
         printf("Device %d : \n", j + 1);
         printf("--------- \n");

         printf("Resolution : %d \n", deviceMatrix[i][j].resoution);
         printf("Bandwidth : %d \n", deviceMatrix[i][j].bandwidth);
         printf("Playback : %d \n", deviceMatrix[i][j].playback);
      }
   }

   for (int i = 0; i < numCategories; i++)
   {
      printf("\n\nCategory %d : \n", i + 1);
      printf("========== \n");
      for (int j = 0; j < nvideos[i]; j++)
      {
         printf("Video %d : \n", j + 1);
         printf("--------- \n");

         printf("Title : %s \n", V[i][j].title);
         printf("Ratings : %d \n", V[i][j].ratings);
         printf("Runtime : %d \n", V[i][j].runtime);
         printf("Encoding formats : %s \n", V[i][j].encodingFormat);
      }
   }
}
int main()
{
   printf("Due to Lengthy code i have not included input verfication so kindly input the correct types.");

   int nUsers;
   printf("enter the number of users");
   scanf("%d", &nUsers);
   int ***Users = (int ***)calloc(nUsers, sizeof(int **));
   int *nCategories = (int *)calloc(nUsers, sizeof(int));
   int **Categories;
   for (int i = 0; i < nUsers; i++)
   {
      printf("Enter the number of Categories for User %d : ", i + 1);
      scanf("%d", &nCategories[i]);
      Categories = (int **)calloc(nCategories[i], sizeof(int *));
      Users[i] = Categories;
   }
   int *engagement;
   for (int i = 0; i < nUsers; i++)
   {
      for (int j = 0; j < nCategories[i]; j++)
      {
         engagement = (int *)calloc(2, sizeof(int));
         Users[i][j] = engagement;

         printf("Enter the veiw time for user %d - Category %d", i + 1, j + 1);
         scanf("%d", &Users[i][j][0]);
         printf("Enter the like dislike ratio for user %d - Category %d", i + 1, j + 1);
         scanf("%d", &Users[i][j][1]);
      }
   }

   int *nDeviceSizes = (int *)calloc(nUsers, sizeof(int));
   struct deviceSpecific **deviceMatrix = (struct deviceSpecific **)calloc(nUsers, sizeof(struct deviceSpecific *));

   for (int i = 0; i < nUsers; i++)
   {
      printf("Enter the number of screen sizes you want to include");
      scanf("%d", &nDeviceSizes[i]); /// add another pointer for devicees
      for (int j = 0; j < nDeviceSizes[i]; j++)
      {

         deviceMatrix[i] = (struct deviceSpecific *)malloc(sizeof(struct deviceSpecific));
         printf("Enter the resolution for device %d", j + 1);
         scanf("%d", &deviceMatrix[i][j].resoution);
         printf("Enter the bandwidth for device %d", j + 1);
         scanf("%d", &deviceMatrix[i][j].bandwidth);
         printf("Enter the playback for device %d", j + 1);
         scanf("%d", &deviceMatrix[i][j].playback);
      }
   }
   int numCategories;
   printf("Enter the number of categories: ");
   scanf("%d", &numCategories);

   struct video **V = (struct video **)calloc(numCategories, sizeof(struct video *));
   int *nvideos = (int *)calloc(numCategories, sizeof(int));
   for (int i = 0; i < numCategories; i++)
   {
      printf("How many content pieces are in Category %d", i + 1);
      scanf("%d", &nvideos[i]);
      V[i] = (struct video *)calloc(nvideos[i], sizeof(struct video));

      for (int j = 0; j < nvideos[i]; j++)
      {
         printf("Enter the title for Catgory %d - Video %d :", i + 1, j + 1);
         scanf("%s", V[i][j].title);
         printf("Enter the Ratings for Catgory %d - Video %d :", i + 1, j + 1);
         scanf("%d", &V[i][j].ratings);
         printf("Enter the runtime for Catgory %d - Video %d :", i + 1, j + 1);
         scanf("%d", &V[i][j].runtime);
         printf("Enter the encoding formats for Catgory %d - Video %d :", i + 1, j + 1);
         scanf("%s", V[i][j].encodingFormat);
      }
   }

   printSystem(nUsers, nCategories, Users, nDeviceSizes, deviceMatrix, numCategories, nvideos, V);
   return 0;
}
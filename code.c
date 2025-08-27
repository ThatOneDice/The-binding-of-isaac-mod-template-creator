//unnecessary but idk what am i gonna write
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

int main() {
    //files
    FILE *metadata;
    FILE *lua;

    //preparing the name
    char name[50] = "mod template";
    printf("Insert the name of the mod youre making (50 character limit, '_' is space since the normal space doesnt work): ");
    scanf("%s", &name);
    for (int i = 0; i != 50; i++) {
        if (name[i] == '_') {
            name[i] = ' ';
        }
    }
    printf("\n%s", name);
    CreateDirectory(name, NULL);

    //making the metadata
    char metadatapath[70] = " ";
    sprintf(metadatapath, ".\\%s\\metadata.xml", name);

    metadata = fopen(metadatapath, "w");
    fprintf(metadata, "<metadata>\n\t<name>%s</name>\n\t<directory>%s</directory>\n\t<description/>\n\t<version>1.0</version>\n\t<visibility/>\n</metadata>", name, name);
    fclose(metadata);

    //asking the user what type of mod they want to do
    printf("\nWhat type of mod are you planning to make \n\n 1. Blank\n 2. An item mod (active)\n 3. An item mod (passive)\n\n Each type of file will provide a main.lua file just incase\n Your choice (number): ");
    int choice;
    scanf("%d", &choice);

    //make the lua file
    char luapath[70] = " ";
    sprintf(luapath, ".\\%s\\main.lua", name);
    lua = fopen(luapath, "w");
    fclose(lua);

    //going trough 4 cases
    if (choice == 1) {
        exit(1);
    } else if (choice == 3) {
        char itempath[70] = " ";
        sprintf(itempath, ".\\%s\\content", name);
        CreateDirectory(itempath, NULL);

        char itemxmlpath[150] = " ";
        sprintf(itemxmlpath, ".\\%s\\content\\items.xml", name);
        FILE *items;
        items = fopen(itemxmlpath, "w");
        fprintf(items, "<items gfxroot=\"gfx/items/\" version=\"1\">\n\t<passive id=\"1\" name=\"name\" gfx=\"gfx.png\" description=\"description\" quality=\"0\" cache=\"damage\"/>\n</items>");
        printf("Check the items.xml folder in the content folder and edit it to your favor\n Add your asset files in resources\\gfx\\collectibles");

        char gfxpath[1500] = " ";
        sprintf(gfxpath, ".\\%s\\resources", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx\\items", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx\\items\\collectibles", name);
        CreateDirectory(gfxpath, NULL);
        exit(1);
    } else if (choice == 2) {
        char itempath[150] = " ";
        sprintf(itempath, ".\\%s\\content", name);
        CreateDirectory(itempath, NULL);

        char itemxmlpath[150] = " ";
        sprintf(itemxmlpath, ".\\%s\\content\\items.xml", name);
        FILE *items;
        items = fopen(itemxmlpath, "w");
        fprintf(items, "<items gfxroot=\"gfx/items/\" version=\"1\">\n\t<active id=\"1\" name=\"name\" gfx=\"gfx.png\" description=\"description\" quality=\"0\" maxcharges=\"1\" chargetype=\"normal\"/>\n</items>");
        printf("Check the items.xml folder in the content folder and edit it to your favor\n Add your asset files in resources\\gfx\\collectibles");
        
        char gfxpath[1500] = " ";
        sprintf(gfxpath, ".\\%s\\resources", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx\\items", name);
        CreateDirectory(gfxpath, NULL);
        sprintf(gfxpath, ".\\%s\\resources\\gfx\\items\\collectibles", name);
        CreateDirectory(gfxpath, NULL);
        exit(1);
    } else {
        printf("Invalid choice provided, exiting");
        exit(1);
    }
}

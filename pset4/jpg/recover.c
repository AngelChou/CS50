/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <cs50.h>
 #include <stdio.h>
 #include <string.h>

int main(int argc, char* argv[])
{
    // open card file
    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not open \'card.raw\'.\n");
        return 1;
    }
    
    int i = 0;
    char buffer[512] = {0};
    char head[3] = {0xff, 0xd8, 0xff};
    bool found = false;
    bool isHead = false;
    FILE* img = NULL;
    
    // repeat until end of card
    while (1)
    {
        // read 512 bytes into a buffer
        if (fread(&buffer, sizeof(buffer), 1, file) != 1)
            break;
        
        // start of a new jpg?
        if (!isHead && memcmp(buffer, head, sizeof(head)) == 0)
        {
            found = true;
            isHead = true;
        }

        if (isHead)
        {
            // close previous img ptr
            if (img != NULL)
                fclose(img);
            
            char title[8] = {0};
            sprintf(title, "%03d.jpg", i++);
            
            img = fopen(title, "a");
            if (img == NULL)
            {
                fclose(file);
                fprintf(stderr, "Could not create %s.\n", title);
                return 2;
            }
            
            fwrite(buffer, sizeof(buffer), 1, img);
            isHead = false;
        }
        else if(found)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    
    fclose(img);
    fclose(file);
    return 0;
}

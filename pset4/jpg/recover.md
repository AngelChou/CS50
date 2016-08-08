# recover

## TODO
- Open memory card file
- Find beginning of jpg
- Open a new jpg
- Write 512 bytes until new jpg is found
- Detect end of file

## JPEGs
- JPEGs are just sequences of bytes
- Each JPEG starts with either:
  - 0xff 0xd8 0xff 0xe0
  - 0xff 0xd8 0xff 0xe1
- Stored side-by-side on the CF card

## memory card 
Each block represents 512 bytes

## reading files

## 512 at a time
```c
fread(&data, size, number, inptr);
```
- &data: buffer
- size
- number
- inptr: memory card

## making a new JPG
- filenames: ###.jpg
- named in the order in which they are found, starting at 0.
  - (So keep track!)
- ```sprintf(title, "%d.jpg", 2);```
  - title: char array to store the resultant string
  - Hmm... this gives 2.jpg, not 002.jpg
    - How long is each array?
- ```FILE* img = fopen(title, "a");```

## writing files
```fwrite(&data, size, number, outptr);```
- &data: pointer to the struct that contains the bytes you're reading from
- size
- number
- outptr: FILE* to write to

## end of file?
```fread(&data, size, number, inptr);```
- Returns how many item of size size were read
  - Ideally, it returns number
- Use it directly in a condition!
```if(fread(&buf, sizeof(DOG), 2, ptr) == 1)```

## pseudocode
- open card file
- repeat until end of card
  - read 512 bytes into a buffer
  - start of a new jpg?
    - yes → ...
    - no → ...
  - already found a jpg?
    - no → ...
    - yes → ..
- close any remaining files

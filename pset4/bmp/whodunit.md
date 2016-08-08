# whodunit

## TODO
- Open file
- Update header info for outfile
- Read clue scanline, pixel by pixel
- Change pixel color as necessary
- Write into verdict scanline, pixel by pixel

## copy.c
- Opens a file
- Updates header info for outfile
- Reads each scanline, pixel by pixel
- Writes each pixel into the output file's scanline
```shell
cp copy.c whodunit.c
```

## Opening Files
```c
FILE* inptr = fopen("foo.bmp", "r");
```
- Opens foo.bmp for reading
```c
FILE* outptr = fopen("bar.bmp", "w");
```
- Opens bar.bmp for writing

## bitmap
- Just an arrangement of bytes!
- **bmp.h**
  
## Header
- biSizeImage
  - total size of image (in bytes)
  - includes pixels and padding
- biWidth
  - width of image (in pixels)
  - does not include padding
- biHeight
  - height of image (in pixels)
- structs
  - BITMAPFILEHEADER, BITMAPINFOHEADER
  
## updating header info
- new bmp → new header info
- is anything changing?
  - file size
  - image size
  - width
  - height
  
## reading files
```c
fread(&data, size, number, inptr);
```
- &data: pointer to a struct which will contain the bytes you're reading
- size: size of each element to read (sizeof)
- number: number of elements to read
- inptr: FILE* to read from
```c
fread(&data, sizeof(DOG), 2, inptr);
fread(&data, 2 * sizeof(DOG), 1, inptr);
```

## pixel color
- Each color is represented by 3 bytes:
  - amount of blue
  - amount of green
  - amount of red
- Example
  - ff0000 → blue
  - ffffff → white

## smiley.bmp
- color:
  - ffffff: white
  - 0000ff: red
- 8 pixel width → no need to padding

### RGBTRIPLE
- struct to represent pixels
- make a green pixel
```c
RGBTRIPLE triple;
triple.rgbtBlue = 0x00;
triple.rgbtGreen = 0xff;
triple.rgbtRed = 0x00;
```
- check color of the pixel
```c
if (triple.rgbtBlue == 0xff)
{
  printf("I'm feeling blue!");
}
```
- remove all red 
  - xxxxff → xxxx00
- change red to white
  - 0000ff → ffffff

## writing files
```c
fwrite(&data, size, number, outptr);
```
- &data: pointer to a struct that contain the bytes you're reading from
- size: size of each element to read (sizeof)
- number: number of elements to read
- outptr: FILE* to write to 

## padding
- Each pixel is 3 bytes
- Size of each scanline must be a multiple of 4 bytes
- If the number of pixels isn't a multiple of 4, we need "padding"
  - Padding is just zero (0x00)
- Padding isn't an RGBTRIPLE
  - we can't fread padding
- Clue and verdict has the same width
  - So the padding is the same!
```c
padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4)
```

## writing padding
```c
fputc(chr, outptr);
```
- chr: char to write
- outptr: FILE* to write to
```c
fputc(0x00, outptr);
```
## file position indicator
```c
fseek(inptr, amount, from);
```
- inptr: FILE* to seek in
- amount: number of bytes to move cursor
- from:
  - ```SEEK_CUR``` (current position in file)
  - ```SEEK_SET``` (begining of file)
  - ```SEEK_END``` (end of file)

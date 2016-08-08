# resize

## TODO
- Open file
- Update header info for outfile
- Read each scanline, pixel by pixel
- Resize horizontally
- Remember padding!
- Resize vertically

## copy.c
- Opens a file
- Update header info for outfile
- Read each scanline, pixel by pixel
- Writes each pixel into the output file's scanline
```shell
cp copy.c resize.c
```

## updating header info
- new bmp → new header info
- is anything changing?
  - file size
  - image size
  - width
  - height

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
  
## reading files
```c
fread(&data, size, number, inptr);
```
- &data: pointer to a struct which will contain the bytes you're reading
- size: size of each element to read (sizeof)
- number: number of elements to read
- inptr: FILE* to read from

## resize horizontally
n = 2: rgb → rrggbb

## writing files
```c
fwrite(&data, size, number, outptr);
```
- &data: pointer to a struct that contain the bytes you're reading from
- size
- number
- outptr: FILE* to write to 

## padding
- Each pixel is 3 bytes
- Size of each scanline must be a multiple of 4 bytes
- If the number of pixels isn't a multiple of 4, we need "padding"

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

## resize vertically
- Several different ways to do this!
  1. "Rewrite" methods
    - Remember pixels is an array.
    - Write array as many times as needed.
  2. "Re-copy" methods
    - Go back to the start of the original row
    - Repeat the horizontal resizing
    
## resize
- Every pixel repeated n times
- Every row repeated n times
- n = 3: b → bbb | bbb | bbb
- n = 2: rgb | gbr → rrggbb | ggbbrr



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

## resize horizontally
n = 2: rgb → rrggbb

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



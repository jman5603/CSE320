# Binary Image Decoder

For this project, we are given a series of files that contain lines of binary characters, up to 1000 characters per line. The first line of any of these files is a key to use to decode the binary. The task was to use this key on each line of the file, and decode it using an exclusive-or operation, then rotating the line to the left by the number of lines that had come before it. Each character in this new line was then transformed into either a ' ' for 0, or a 'X' for 1. Then, we pushed this decoded line onto a stack, and printed out the result. 

# Example input:
01010100011000
01011011101000
01001011100110
11001011100111
10101011111111
10101011100111
00101011111110
10101101100111
10110000111111
01000110001010
01010001010010
01010101111110

# Expected Output: 
 XX        XX 
 X X      X X 
 X  X    X  X 
 X  XXXXXX  X 
 XXXXXXXXXXXX 
XXXX  XX  XXXX
XXXXXXXXXXXXXX
XXXXXX  XXXXXX
 XXXXXXXXXXXX 
  XXXXXXXXXX  
    XXXXXX    

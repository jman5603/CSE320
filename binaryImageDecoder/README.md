# Binary Image Decoder

For this project, we are given a series of files that contain lines of binary characters, up to 1000 characters per line. The first line of any of these files is a key to use to decode the binary. The task was to use this key on each line of the file, and decode it using an exclusive-or operation, then rotating the line to the left by the number of lines that had come before it. Each character in this new line was then transformed into either a ' ' for 0, or a 'X' for 1. Then, we pushed this decoded line onto a stack, and printed out the result. 

For testing, compile the decoder.c file, then call it with a filename on the command line. For example, if the executable is named `decoder`, and I wanted to decode `cat.enc`, I would type:
`./decoder cat.enc` (note the space)

#!/usr/bin/env python
# Create a string that contains the block character
# and then print it.

vert_bar=0x2503
horiz_bar=0x2501
no_break_space=0x00a0
middle=0x254b
top_middle=0x2533
top_left=0x250F
top_right=0x2513
bottom_right=0x251B
bottom_left=0x2517
bottom_middle=0x253B
left_middle=0x2523
right_middle=0x252B

print unichr(top_left)+unichr(horiz_bar)+unichr(top_middle)+unichr(horiz_bar)+unichr(top_right)
print unichr(vert_bar)+unichr(no_break_space)+unichr(vert_bar)+unichr(no_break_space)+unichr(vert_bar)
print unichr(left_middle)+unichr(horiz_bar)+unichr(middle)+unichr(horiz_bar)+unichr(right_middle)
print unichr(vert_bar)+unichr(no_break_space)+unichr(vert_bar)+unichr(no_break_space)+unichr(vert_bar)
print unichr(bottom_left)+unichr(horiz_bar)+unichr(bottom_middle)+unichr(horiz_bar)+unichr(bottom_right)

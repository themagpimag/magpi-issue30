#!/usr/bin/env python
import random

def build_maze(maze):
  deep = len(maze)
  wide = len(maze[0])
  print "Am building a",wide,"by",deep,"maze"
  
  x = 0
  y = 0
  maze[y][x]= 4
  total = wide*deep
  blocks_tagged = 1

  while (blocks_tagged < total):
    options=[]
    if (x > 0):
      if (maze[y][x-1] == 0):
        options.append("left")
    if (x < wide-1):
      if (maze[y][x+1] == 0):
        options.append("right")
    if (y > 0):
      if (maze[y-1][x] == 0):
        options.append("up")
    if (y < deep-1):
      if (maze[y+1][x] == 0):
        options.append("down")
        
    if (options):
      choice_index = random.randrange(len(options))
      choice = options[choice_index]
      blocks_tagged +=1
      
      if (choice == 'down'):
        if (maze[y][x] == 3):
          maze[y][x] =1         
        if (maze[y][x] == 4):
          maze[y][x] =2
        y = y + 1
        maze[y][x] = 4

      if (choice == 'up'):
        y = y -1
        maze[y][x]=2

      if (choice == 'right'):
        if (maze[y][x] == 4):
          maze[y][x] = 3
        if (maze[y][x] == 2):
          maze[y][x] = 1
        x = x+1
        maze[y][x] = 4

      if (choice == 'left'):
        x = x -1
        maze[y][x] = 3       
    else:
      while(1):
        y = random.randrange(deep)
        x = random.randrange(wide)
        if (maze[y][x] > 0):
          break
     


def print_asci_maze(maze):
  deep = len(maze)
  wide = len(maze[0])
  right_wall = (0,2,4)
  bottom_wall = (0,3, 4)
    
  # print top border
  row = "+s+"
  for index in range (0,wide-1):
    row +="-+"
  print row

  for index1 in range (0,deep):
    # print upper half of row
    row = "|"
    for index in range (0,wide):
      if (maze[index1][index] in right_wall):
        row += " |"
      else:
        row += "  "
    print row
    # print lower half of row
    row = "+"
    for index in range (0,wide):
      if (index == wide-1) and (index1==deep-1):
        row +="f+"
      else:
        if (maze[index1][index] in bottom_wall):
          row +="-+"
        else:
          row += " +"
    print row



def main():
  print  """\n\nMaze Builder. Inspired By
  "The Creative Atari" 1983\n\n"""

  width = 0
  depth = 0
  while (width < 2) or (width > 10):
    width = int(raw_input("What should the width be (2-10)?"))
  while (depth < 2) or (depth > 10):
    depth = int(raw_input("What should the depth be (2-10)?"))
  print  "Your maze will be",width,"by",depth

  # set up a list of lists referenced as maze[row][column]
  maze = [0 for index in range (0, depth)]
  for index in range (0, depth):
    maze[index] = [0]*width

  build_maze(maze)
  print_asci_maze(maze)

if __name__ == '__main__':
  main()

import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "build/python_bindings")))
import py_game_of_life as gol
import pygame

BACKGROUND_COLOR = (0,0,0) #black
GRID_BORDER_COLOR = (50,50,50)
ALIVE_COLOR = (0,255,0)
DEAD_COLOR = (30,30,30)

CELL_SIZE = 20

NUM_OF_ROWS = 20
NUM_OF_COLS = 20

WIDTH = NUM_OF_ROWS*CELL_SIZE
HEIGHT = NUM_OF_COLS*CELL_SIZE

SCREEN_SIZE = WIDTH, HEIGHT
def draw_grid(screen, grid):
    for row in range(0,NUM_OF_ROWS):
        for col in range(0,NUM_OF_COLS):
            rect = pygame.Rect(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE)
            color = ALIVE_COLOR if grid[row][col] == 1 else DEAD_COLOR
            pygame.draw.rect(screen, color, rect)
    for x in range(0,WIDTH,CELL_SIZE):
        pygame.draw.line(screen, GRID_BORDER_COLOR, (x,0),(x, HEIGHT))
    for y in range(0,HEIGHT, CELL_SIZE):
        pygame.draw.line(screen, GRID_BORDER_COLOR, (0,y),(WIDTH, y))
    # Update the display
    pygame.display.flip()

def get_mouse_position(pos):
    x,y = pos
    row = y // CELL_SIZE
    col = x // CELL_SIZE
    return row,col #row - y, column - x

def update_selected_grid(grid):
    selected = set()
    for row in range(0,NUM_OF_ROWS):
        for col in range(0,NUM_OF_COLS):
            if(grid[row][col]):
                selected.add((row, col))
    return selected
def main():
    pygame.init()

    screen = pygame.display.set_mode(SCREEN_SIZE)
    pygame.display.set_caption("Game Of Life")
    clock = pygame.time.Clock()

    g = gol.Grids(NUM_OF_ROWS,NUM_OF_COLS)
    grids = g.get_grid()
    is_running = False
    selected_grid = set()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    if(is_running):
                        curr_grids = g.get_grid()
                        selected_grid = update_selected_grid(curr_grids)
                    is_running = not is_running

                if event.key == pygame.K_ESCAPE:
                    print("Escape key pressed\nExiting")
                    pygame.quit()
                    return
        
            if event.type == pygame.MOUSEBUTTONUP and not is_running:
                row, col = get_mouse_position(pygame.mouse.get_pos())
                if (row, col) in selected_grid:
                    selected_grid.remove((row,col))  
                else:
                    selected_grid.add((row,col))
                g.set_grid(list(selected_grid))

        # Fill the screen with a color (black in this case)
        screen.fill(BACKGROUND_COLOR)
        if(is_running):
            g.update_grid()
     
        grids = g.get_grid()
        draw_grid(screen, grids)

        # Cap the frame rate at 60 frames per second
        clock.tick(30)

if __name__ == "__main__":
    main()


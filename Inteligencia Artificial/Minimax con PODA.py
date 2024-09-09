def evaluate(state, player):
    if state == 0:                     
        if player == MAX:
            return -100  # Gana MAX
        else:
            return +100  # Gana MIN 
    else:
        return 0  # El juego aún no termina

def gameOver(remainingCubes, player):
    if(remainingCubes == 0): 
        if(player == MAX): # If MAX's turn led to 0 cubes on the table 
            print('='*20)
            print('Im sorry, you lost!')
            print('='*20)
        else: 
            print('='*69)
            print('Hey congrats! You won MiniMax. Didnt see that coming!')
            print('='*69)
        return True

# M input validation
def validateM(message):
    while True:
        try:
            inp = input(message)
            if(inp == 'q' or inp == 'Q'): quit() # Exit tha game
            M = int(inp)
        except ValueError:
            print('Try again with an integer!')
            continue
        else:
            if(M >= 4): # We can not accept less than 4
                return M
            else:
                print('Please try again with an integer bigger than 3.')
                continue

# K input validation
def validateK(message):
    while True:
        try:
            inp = input(message)
            if(inp == 'q' or inp == 'Q'): quit()
            K = int(inp)
        except ValueError:
            print('Try again with an integer!')
            continue
        if(K > 2) and (K < M): # acceptable K limits are 2+1 & M-1 respectively.
            return K
        else:
            print(f'You need to insert an integer in the range of 3 to {M-1}!')

# Game play input validation
# Input is considered valid only if its one of the 3 availiable options and does not cause a negative amount of cubes on the table.
def validateInput(message):
    while True:
        try:
            inp = input(message)
            if(inp == 'q' or inp == 'Q'): quit()
            inp = int(inp) # in the cause of not integer input it causes an error
        except ValueError:
            print(f'Try again with an integer!')
            continue
        if(inp in choices):
            if(M - inp >=0):
                return inp # Accepted input
            else:
                print(f'There are no {inp} availiable cubes. Try to pick up less..')
        else:
            print(f'Wrong choice, try again. Availiable options are: 1 or 2 or {K}: ')

def plural(choice):
    if(choice == 1):
        return 'cube'
    else:
        return 'cubes'

# ==================== 1. MiniMax for the optimal choice from MAX ==================
# It recursively expands the whole tree and returns the list [score, move], 
# meaning the pair of best score tighten to the actual move that caused it.

# state: estado actual del juego (número de cubos restantes en la mesa)
# depth: profundidad del árbol de juego
# isMaximizingPlayer: True si es el turno del jugador que maximiza, False si es el turno del jugador que minimiza
# alpha: mejor valor para el jugador que maximiza
# beta: mejor valor para el jugador que minimiza
# max_depth: profundidad máxima del árbol de juego

def MiniMax(state, depth, isMaximizingPlayer, alpha, beta, max_depth):
    # Evaluación del nodo hoja o profundidad máxima alcanzada
    if state <= 0 or depth == max_depth:
        return evaluate(state, isMaximizingPlayer), None  # Devuelve la evaluación y ningún movimiento

    # Si es el turno de MAX
    if isMaximizingPlayer:
        bestVal = -float('inf') # Inicializa el mejor valor para el jugador que maximiza
        bestMove = None
        for choice in [1, 2, K]: # Recorre los posibles movimientos
            if state - choice >= 0: # Verifica que el movimiento sea válido
                value, _ = MiniMax(state - choice, depth + 1, False, alpha, beta, max_depth)  # Llamada recursiva para ver que pasa si el jugador elige 1, 2 o K cubos 
                if value > bestVal:  # Actualiza el mejor valor y el mejor movimiento
                    bestVal = value
                    bestMove = choice
                alpha = max(alpha, bestVal)  # Actualiza el valor de alpha
                if beta <= alpha:   # Realiza la poda: si beta es menor o igual que alpha, se corta la rama
                    break
        return bestVal, bestMove  # Retorna la mejor evaluación y el mejor movimiento

    # Si es el turno de MIN
    else:
        bestVal = float('inf')  # Inicializa el mejor valor para el jugador que minimiza
        bestMove = None # Inicializa el mejor movimiento
        for choice in [1, 2, K]: # Recorre los posibles movimientos
            if state - choice >= 0: # Verifica que el movimiento sea válido
                value, _ = MiniMax(state - choice, depth + 1, True, alpha, beta, max_depth)  
                if value < bestVal:
                    bestVal = value
                    bestMove = choice
                beta = min(beta, bestVal)
                if beta <= alpha: # Realiza la poda: si beta es menor o igual que alpha, se corta la rama
                    break
        return bestVal, bestMove  # Retorna la mejor evaluación y el mejor movimiento

    
# ====================== 2. MAIN EXECUTION ======================
print('+'*126)
print('INSTUCTIONS: There are M availiable cubes on the table. Both players are allowed to remove 1, 2 or K cubes at the same time.')
print('You will set the M & K variables. Since tree prunning has not been implemented, its Minimax after all, we suggest you set M < 20 for the execution to be smooth.')
print('Press q to exit the game.')
print('The player who removes the last cube off the table will be the winner. The first player is the PC. Good luck!')
print('+'*126)

MAX = +1
MIN = -1
M = validateM('Please insert an initial number of cubes (M) availiable on the table: ') # M = state/depth/remainingCubes
K = validateK('Please insert an integer K, 2 < K < M, that will act as the 3rd option for the ammount of cubes both players can get off the table: ')
choices = [1, 2, K]

print(f'\nThe game begins with {M} cubes availiable on the table and each player can pick 1, 2 ή {K}:')
while(M > 0):
    # ===== PC's turn =====
    print('Please wait for the PC to make its mind..')
    score, move = MiniMax(M, 0, True, -float('inf'), float('inf'), max_depth=5)  
    M = M - choices[move]

    print(f'\nPc chose to remove {choices[move]} {plural(choices[move])} off the table. Remaining cubes are {M}.')
    if((gameOver(M, MAX))): break # Game over check

    # ===== Παίζει ο χρήστης =====
    else:    
        userChoice = validateInput(f'\nHow many cubes would you like to pick up (1, 2 ή {K}): ')
        # In valid the game goes on. In any other case it gets stacked on the validation function till a proper input is given.

        M = M - int(userChoice)  
        print(f'\nYou chose to remove {userChoice} {plural(int(userChoice))} from the table. Remaining cubes are {M}.')
        if((gameOver(M, MIN))): break # Game over check.
        
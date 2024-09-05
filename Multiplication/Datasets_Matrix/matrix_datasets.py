import random
import os
# Función para genrar una matriz de tamaño filas x columnas con números aleatorios
def generate_matrix(rows, cols, min_val=0, max_val=10):
    return [[random.randint(min_val, max_val) for _ in range(cols)] for _ in range(rows)]

def save_matrices_to_file(filename, *matrices):
    #Guardar multiples matrices en un solo archivo.
    with open(filename, 'a') as f:
        for matrix in matrices: 
            #Guardar dimensiones de la matriz
            f.write(f"{len(matrix)} {len(matrix[0])}\n")
            for row in matrix: 
                f.write(" ".join(map(str, row)) + "\n")

def generate_square_matrices(size, filename, min_val, max_val, count):

    for i in range(count):
        #Genera dos matrices cuadradas y las guarda en un archivo.
        A = generate_matrix(size, size, min_val, max_val) # Matriz A
        B = generate_matrix(size, size, min_val, max_val) # Matriz B
        save_matrices_to_file(filename, A, B)

#Generar y guardar matrices rectangulares que cumplan con las reglas de multiplicación
# A: rows_A x cols_A, B: cols_A x cols_B
def generate_rectangular_matrices( rows_A, cols_A, cols_B, filename, min_val, max_val, count):
    # Genera dos matrices rectangulares compatibles para multiplicación
    for i in range(count):
        A = generate_matrix(rows_A, cols_A, min_val, max_val) # Matriz A
        B = generate_matrix(cols_A, cols_B, min_val, max_val) # Matriz B
        save_matrices_to_file(filename, A, B)

def main():
    # ¿Qué tipo de matrices quieres generar?
    matrix_type = int(input("1. ¿Qué tipo de matrices quieres generar cuadradas(1) o rectangulares(2) ? "))
    # ¿Cuántas matrices quieres generar?
    count = int(input("2. ¿Cuántas matrices quieres generar? "))
    # ¿Cual es el tamaño de las matrices?
    if matrix_type == 1:
        size = int(input("3. ¿Cuál es el tamaño de las matrices cuadradas (ej. 3 para 3x3)? "))
    elif matrix_type == 2:
        rows_A = int(input("3a. Número de filas de la primera matriz: "))
        cols_A = int(input("3b. Número de columnas de la primera matriz (y filas de la segunda): "))
        cols_B = int(input("3c. Número de columnas de la segunda matriz: "))

    # ¿Cuál es la magnitud de los números?
    min_val = int(input("4a. Valor mínimo de los números: "))
    max_val = int(input("4b. Valor máximo de los números: "))

    # ¿Cuál es el nombre del archivo?
    filename = input("5. ¿Cuál es el nombre del archivo base? ")

    # Asegurar que el archivo tenga extensión '.txt'
    if not filename.endswith(".txt"):
        filename += ".txt"
    
    #Obtener el path absoluto para asegurarse de que el archivo se guarda en el mismo directorio
    filepath = os.path.join(os.getcwd(), filename)

    #Limpia el archivo si existe antes de comenzar a escribir
    open(filepath,'w').close()

    #Generar matrices basadas en la entrada del usuario
    if matrix_type == 1: 
        generate_square_matrices(size, filepath, min_val, max_val, count)
    elif matrix_type == 2: 
        generate_rectangular_matrices(rows_A,cols_A,cols_B, filepath, min_val, max_val, count)
    else: 
        print("Tipo de matrices no válido.")

    print(f"Todas las matrices guardadas en {filepath}")

if __name__ == "__main__":
    main()
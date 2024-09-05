import random
import os

# Función para generar un arreglo aleatorio
def generate_random_array(size, min_val=1, max_val=100):
    return [random.randint(min_val, max_val) for _ in range(size)]

# Función para generar un arreglo ascendente
def generate_ascending_array(size, min_val=1):
    return list(range(min_val, min_val + size))

# Función para generar un arreglo descendente
def generate_descending_array(size, min_val=1):
    return list(range(min_val + size - 1, min_val - 1, -1))

# Función para generar un arreglo parcialmente ordenado con un nivel de desorden específico
def generate_partially_sorted_array(size, min_val=1, max_val=100, disorder_percentage=25):
    arr = generate_ascending_array(size, min_val)
    # Calcular cuántos elementos desordenar según el porcentaje dado
    partial_shuffle_count = int(size * (disorder_percentage / 100))
    random_indices = random.sample(range(size), partial_shuffle_count)
    for i in random_indices:
        arr[i] = random.randint(min_val, max_val)
    return arr

# Función para guardar los arreglos en un archivo
def save_arrays_to_file(filename, arrays):
    with open(filename, 'a') as f:  # Abrimos el archivo en modo 'append'
        for array in arrays:
            f.write(f"{len(array)}\n")  # Guardar el tamaño del arreglo
            f.write(" ".join(map(str, array)) + "\n")  # Guardar los elementos del arreglo
        print(f"Arreglos guardados en {filename}")

# Interfaz interactiva para generar los datasets de arreglos
def main():
    # ¿Cuántos arreglos quieres generar?
    count = int(input("1. ¿Cuántos arreglos quieres generar? "))

    # ¿Cuál es el tamaño de los arreglos?
    size = int(input("2. ¿Cuál es el tamaño de los arreglos? "))

    # ¿Qué tipo de orden quieres?
    order_type = int(input("3. ¿Cómo quieres que estén ordenados los arreglos? ¿(1)ascendente, (2)descendente, (3)parcialmente ordenado, (4)desordenado)? "))

    # ¿Cuál es la magnitud de los números?
    min_val = int(input("4a. Valor mínimo de los números: "))
    max_val = int(input("4b. Valor máximo de los números: "))

    # ¿Cuál es el nombre del archivo?
    filename = input("5. ¿Cuál es el nombre del archivo base? ").strip()

    # Asegurar que el archivo tenga extensión '.txt'
    if not filename.endswith(".txt"):
        filename += ".txt"

    # Obtener el path absoluto para guardar el archivo en el mismo directorio
    filepath = os.path.join(os.getcwd(), filename)

    # Limpia el archivo si existe antes de comenzar a escribir
    open(filepath, 'w').close()

    # Si el tipo de orden es parcialmente ordenado, preguntamos el porcentaje de desorden
    disorder_percentage = 0
    if order_type == 3:
        disorder_percentage = int(input("6. ¿Qué porcentaje de desorden quieres (0-100)? "))

    # Generar los arreglos basados en la elección del usuario
    arrays = []
    for _ in range(count):
        if order_type == 1:
            array = generate_ascending_array(size, min_val)
        elif order_type == 2:
            array = generate_descending_array(size, min_val)
        elif order_type == 3:
            array = generate_partially_sorted_array(size, min_val, max_val, disorder_percentage)
        elif order_type == 4:
            array = generate_random_array(size, min_val, max_val)
        else:
            print("Tipo de orden no válido. Elige entre 'ascendente', 'descendente', 'parcialmente ordenado' o 'desordenado'.")
            return
        arrays.append(array)

    # Guardar todos los arreglos en el archivo
    save_arrays_to_file(filepath, arrays)

if __name__ == "__main__":
    main()

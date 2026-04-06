import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def run_test(algorithm_func, data, name):
    times = []
    print(f"Algoritmo: {name}")
    
    for i in range(5):
        data_copy = data.copy()
        
        start_time = time.time()
        sorted_data = algorithm_func(data_copy)
        end_time = time.time()
        
        exec_time = end_time - start_time
        times.append(exec_time)
        print(f"Execução {i+1}: {exec_time:.5f}s")
    
    avg_time = sum(times) / len(times)
    print(f"Média: {avg_time:.5f}s\n")
    return sorted_data, avg_time

def main():
    try:
        with open('arq.txt', 'r') as f:
            content = f.read()
            numbers = [int(x) for x in content.split()]
            
        # Bubble Sort (Lento)
        _, _ = run_test(bubble_sort, numbers, "Bubble Sort")
        
        # Quick Sort (Rápido)
        sorted_numbers, _ = run_test(quick_sort, numbers, "Quick Sort")
        
        # 8. Salvar o resultado
        with open('arq-ordenado.txt', 'w') as f:
            f.write(" ".join(map(str, sorted_numbers)))
            
        print("Arquivo 'arq-ordenado.txt' gerado com sucesso.")

    except FileNotFoundError:
        print("Erro: O arquivo 'arq.txt' não foi encontrado.")
    except ValueError:
        print("Erro: O arquivo contém caracteres que não são números inteiros.")

if __name__ == "__main__":
    main()
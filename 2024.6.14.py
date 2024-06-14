####71
import numpy as np

arr = np.array([3, 1, 2])
sorted_indices = np.argsort(arr)
print(sorted_indices)

####73
movie_similarities = np.array([0.1, 0.5, 0.2, 0.4])
sorted_indices = np.argsort(-movie_similarities)[:2]
print(sorted_indices)

####4_p75
def calculate_average(numbers):
    """返回數列的平均值"""
    total = sum(numbers)
    count = len(numbers)
    average = total / count
    return average

numbers_list = [10, 20, 30, 40, 50]
average_result = calculate_average(numbers_list)
print(f"The average is: {average_result}")

####76
def greet(name, greeting = "Hello"):
    """打印問候語與名字"""
    print(f"{greeting}, {name}!")
    
greet("Alice")
greet("Bob", "Hi")

def multiply(*args):
    """返回所有參數的乘積"""
    result = 1
    for number in args:
        result *= number
    return result
product_result = multiply(2, 3, 4)
print(f"The product is: {product_result}")

####77
def print_dict(dictionary):
    """打印字典的鍵和值"""
    for key, value in dictionary.items():
        print(f"{key}: {value}")
        
sample_dict = {"name": "Alice", "age": 30, "city": "New York"}
print_dict(sample_dict)
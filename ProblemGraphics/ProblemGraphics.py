import numpy
import matplotlib.pyplot as plt

def graph():
    fin = open("C:\\Users\\GolAnd071\\source\\repos\\Inf_01_03_2022\\ProblemBubbleSort\\test_data.txt", "r")
    x = list(map(int, fin.readline().split()))
    y = list(map(int, fin.readline().split()))
    y1 = list(map(int, fin.readline().split()))
    plt.plot(x, y, color='blue')
    plt.plot(x, y1, color='red')
    plt.show()

if (__name__ == '__main__'):
    graph()

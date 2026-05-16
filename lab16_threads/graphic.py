import matplotlib.pyplot as plt
import pandas as pd

with open('data.txt', 'r', encoding='utf-8') as f:
    lines = f.readlines()

data = []
for line in lines:
    if line.strip():
        parts = [part.split(': ')[1] for part in line.split(';')]
        data.append([float(x) for x in parts])

df = pd.DataFrame(data, columns=['Size', 'Threads', 'Time'])

plt.figure(figsize=(10, 6))

for threads, group in df.groupby('Threads'):
    plt.plot(group['Size'], group['Time'], marker='o', label=f'Потоков: {threads}')

plt.xlabel('Размер матрицы')
plt.ylabel('Время выполнения')
plt.legend(title="Кол-во потоков", bbox_to_anchor=(1.05, 1), loc='upper left')
plt.grid(True, linestyle='--', alpha=0.7)
plt.tight_layout()
plt.savefig('images/matrix_g.png')

plt.show()

# Koriscenjem hipa implementirati algoritam sortiranja hip-sort.

import heapq

# Max-heap
H = [21, 1, 45, 78, 3, 5]
heapq.heapify(H) # rasporedjuje elemente
print(H)

heapq.heappush(H, 8)
print(H)

# Heapsort
def heapsort(iterable):
    h = []
    for value in iterable:
        heapq.heappush(h, value)
    return [heapq.heappop(h) for i in range(len(h))]

H = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
print(heapsort(H))
def binary_search(lista, item):
    if not lista:
        return False

    meio = len(lista) // 2
    if lista[meio] == item:
        return True
    elif lista[meio] < item:
        return binary_search(lista[meio + 1:], item)
    else:
        return binary_search(lista[:meio], item)
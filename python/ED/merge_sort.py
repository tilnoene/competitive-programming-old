def merge(v, inicio, meio, fim, aux):
    i = inicio; j = meio+1; k = 0;

    while (i <= meio and j <= fim):
        if (v[i] <= v[j]):
            aux[k] = v[i]
            k = k + 1
            i = i + 1
        else:
            aux[k] = v[j]
            k = k + 1
            j = j + 1 

    while (i <= meio):
        aux[k] = v[i]
        k = k + 1
        i = i + 1

    while (j <= fim):
        aux[k] = v[j]
        k = k + 1
        j = j + 1
    i = inicio; k = 0;

    while (i <= fim):
        v[i] = aux[k]
        i = i + 1
        k = k + 1
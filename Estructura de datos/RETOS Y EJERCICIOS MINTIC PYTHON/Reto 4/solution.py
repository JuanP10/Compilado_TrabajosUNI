# POR FAVOR LEA TODAS LAS INDICACIONES SUMINISTRADAS EN EL 
# ENUNCIADO ANTES DE EMPEZAR A IMPLEMENTAR SU SOLUCIÓN

def tiene_cartas_altas(cartas_siguientes):
    # ACÁ INICIA LA FUNCIÓN
    cartaalta = False
    for j in cartas_siguientes:
        if j == "A" or j == "J" or j == "Q" or j == "K":
            cartaalta = True
            break
    return(cartaalta)
    # ACÁ TERMINA LA FUNCIÓN
    # ESTA VEZ TU DEFINES TUS RETORNOS

def juego(baraja):
    # ACÁ INICIA LA FUNCIÓN
    baraja = list(baraja)
    baraja.append("hola")
    posicionA = [p for p, v in enumerate(baraja) if v == "A"]
    posicionJ = [p for p, v in enumerate(baraja) if v == "J"]
    posicionQ = [p for p, v in enumerate(baraja) if v == "Q"]
    posicionK = [p for p, v in enumerate(baraja) if v == "K"]
    contA = 0
    contJ = 0
    contQ = 0
    contK = 0
    
    cont1 = 0
    cont2 = 0
    
    for i in posicionA:
        segmentoA = baraja[i+1:i+2]
        for j in segmentoA:
            if j == "A" or j == "J" or j == "Q" or j == "K":
                break
            elif j != "A" or j != "J" or j != "Q" or j != "K":
                contA += 1
                if i % 2 == 0:
                    cont1 += 1 
                elif i % 2 != 0:
                    cont2 += 1
    
    contp = 0
    for i in posicionJ:
        segmentoJ = baraja[i+1:i+4]
        for j in segmentoJ:
            if contp < 2:
                if j == "A" or j == "J" or j == "Q" or j == "K":
                    contp = 0
                    break
                elif j != "A" or j != "J" or j != "Q" or j != "K":
                    contp += 1
            elif contp == 2:
                contJ += 2
                contp = 0
                if i % 2 == 0:
                    cont1 += 2 
                elif i % 2 != 0:
                    cont2 += 2
                break
            
    
    contp = 0
    for i in posicionQ:
        segmentoQ = baraja[i+1:i+5]
        for j in segmentoQ:
            if contp < 3:
                if j == "A" or j == "J" or j == "Q" or j == "K":
                    contp = 0
                    break
                elif j != "A" or j != "J" or j != "Q" or j != "K":
                    contp += 1
            elif contp == 3:
                contQ+= 3
                contp = 0
                if i % 2 == 0:
                    cont1 += 3 
                elif i % 2 != 0:
                    cont2 += 3
                break
    
    contp = 0
    for i in posicionK:
        segmentoK = baraja[i+1:i+6]
        for j in segmentoK:
            if contp < 4:
                if j == "A" or j == "J" or j == "Q" or j == "K":
                    contp = 0
                    break
                elif j != "A" or j != "J" or j != "Q" or j != "K":
                    contp += 1
            elif contp == 4:
                contK+= 4
                contp = 0
                if i % 2 == 0:
                    cont1 += 4 
                elif i % 2 != 0:
                    cont2 += 4
                break
    
    
    
    lista1 = [cont1]
    lista2 = [cont2]
    total_puntos = (lista1 + lista2)
    total_puntos = tuple(total_puntos)
    return total_puntos
    
    # ACÁ TERMINA LA FUNCIÓN
    # ESTA VEZ TU DEFINES TUS RETORNOS
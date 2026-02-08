# No Prefix Set
# NODE_DESVIO significa os nós de desvio 
# Por ser uma R-WAY ela não armazena as letras no Nós propriamente, ficam nos caminhos 
# Se torna desvantajoso para entradas pequenas pois reserva
# muito espaço que fica inutilizado na memória
# Adição da quantidade de número de filhos, isso serve para ver se não há prefixo no final
# 

RESTRICAO_N = 10

class RWAY_Node:
    __slots__ = ('NODE_DESVIO', 'FIM_PALAVRA', 'NUMERO_FILHOS')
    def __init__(self):
        self.NODE_DESVIO = [None] * RESTRICAO_N
        self.FIM_PALAVRA = False
        self.NUMERO_FILHOS = 0

class RWAY_Trie:
    def __init__(self):
        self.RAIZ = RWAY_Node()

    def insertion(self, palavra):
        node = self.RAIZ

        for letra in palavra:
            index = ord(letra) - ord('a')

            if node.FIM_PALAVRA:
                return False
        
            if node.NODE_DESVIO[index] is None:
                node.NODE_DESVIO[index] = RWAY_Node()
                node.NUMERO_FILHOS += 1

            node = node.NODE_DESVIO[index]

        if node.FIM_PALAVRA:
            return False

        if node.NUMERO_FILHOS > 0:
            return False

        node.FIM_PALAVRA = True

        return True

def noPrefix(palavras):
    trie = RWAY_Trie()

    for palavra in palavras:
        if not trie.insertion(palavra):
            print("BAD SET")
            print(palavra)
            return
    print("GOOD SET")



palavras = ["bbb", "bajbj", "defgab", "abcde", "caca", "bbbbbbbbbb", "jabjjjad", "cacaca"]

noPrefix(palavras)
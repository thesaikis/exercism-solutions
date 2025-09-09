COLORS = ["black","brown","red","orange","yellow","green","blue","violet","grey","white"]

def label(colors):
    match (COLORS.index(colors[0]) * 10 + COLORS.index(colors[1])) * (10 ** COLORS.index(colors[2])):
        case n if n > 10 ** 9: return f"{n//10**9} gigaohms"
        case n if n > 10 ** 6: return f"{n//10**6} megaohms"
        case n if n > 10 ** 3: return f"{n//10**3} kiloohms"
        case n:                return f"{n} ohms"

import sys


def unit_or_units(num):
    if num == 1:
        return "unit"
    else:
        return "units"


def current_inventory(items, total_value):
    if len(items) > 0:
        for key, value in items.items():
            print(f"{key}: {value} {unit_or_units(value)}"
                  f" ({(value/total_value)*100:.1f}%)")


def abundant(most_or_least, items):
    the_value = -1
    if most_or_least == "most":
        for key, value in items.items():
            if value > the_value:
                the_value = value
                abundant = key
        if len(items) > 0:
            print(f"Most abundant: {abundant} ({the_value}"
                  f" {unit_or_units(the_value)})")
    else:
        for key, value in items.items():
            if the_value == -1 or value < the_value:
                the_value = value
                abundant = key
        if len(items) > 0:
            print(f"Least abundant: {abundant} ({the_value}"
                  f" {unit_or_units(the_value)})")


def m_s_r(mod_scr_res, items):
    moderate = dict()
    scarce = dict()
    restock = []
    for key, value in items.items():
        if value >= 5:
            moderate[key] = value
        else:
            scarce[key] = value
        if value <= 1:
            restock += [key]
    if mod_scr_res == "moderate":
        print(f"Moderate: {moderate}")
    elif mod_scr_res == "scarce":
        print(f"Scarce: {scarce}")
    else:
        print(f"Restock needed: {restock}")


def dictionary_prop(items):
    dict_keys = []
    dict_values = []
    for key, value in items.items():
        dict_keys += [key]
        dict_values += [value]
    return (dict_keys, dict_values)


def ft_inventory_system():
    items = dict()
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
              '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}
    param = True
    try:
        sys.argv[1]
    except IndexError:
        param = False
    if param is True:
        for arg in sys.argv[1:]:

            i = 0
            while (i < len(arg) and arg[i] != ":"):
                i += 1
            if i != len(arg) and arg[i] == ":":
                the_key = arg[:i]
                number = 0
                while i < len(arg):
                    try:
                        if digits.get(arg[i]) is not None:
                            number = (number * 10) + digits.get(arg[i])
                    except ValueError:
                        break
                    i += 1
                if i == len(arg):
                    items[the_key] = number
    total_value = 0
    for item in items.values():
        total_value += item
    unique_items = len(items)
    print("=== Inventory System Analysis ===")
    print(f"Total items in inventory: {total_value}")
    print(f"Unique item types: {unique_items}")

    print("\n=== Current Inventory ===")
    current_inventory(items, total_value)

    print("\n=== Inventory Statistics ===")
    abundant("most", items)
    abundant("least", items)

    print("\n===Item Categories ===")
    m_s_r("moderate", items)
    m_s_r("scarce", items)

    print("\n=== Management Suggestions ===")
    m_s_r("restock", items)

    print("\n===Dictionary Properties Demo ===")
    all_keys, all_values = dictionary_prop(items)
    print(f"Dictionary keys: {all_keys}")
    print(f"Dictionary values: {all_values}")
    print("Sample lookup - 'sword' in inventory: "
          f"{items.get('sword') is not None}")


# if __name__ == "__main__":
#     ft_inventory_system()

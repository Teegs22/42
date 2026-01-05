def ft_count_harvest_recursive():
    global days, i
    try:
        days
        i
    except NameError:
        days = int(input("Days until harvest: "))
        i = 1
    if i <= days:
        print("Day ", i)
        i += 1
        ft_count_harvest_recursive()
    else:
        print("Harvest time!")
# if __name__ == "__main__":
#    ft_count_harvest_recursive()

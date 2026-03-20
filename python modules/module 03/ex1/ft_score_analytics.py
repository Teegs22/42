import sys


def score_analytics():
    print("=== Player Score Analytics ===")
    length = len(sys.argv)
    my_list = []
    total = 0
    i = 1
    while i < length:
        try:
            if isinstance(sys.argv[i], int):
                my_list += [int(sys.argv[i])]
                total += int(sys.argv[i])
                i += 1
        except ValueError:
            i += 1
    length = len(my_list)
    if length == 0:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score 2> ...")
    else:
        print("Total players:", length)
        print("Total score:", total)
        print(f"Average score: {total/length:.1f}")
        print("High score:", max(my_list))
        print("Low score:", min(my_list))
        print("Score range:", max(my_list) - min(my_list))


# if __name__ == "__main__":
#    score_analytics()

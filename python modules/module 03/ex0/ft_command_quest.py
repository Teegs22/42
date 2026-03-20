import sys


def command_quest():
    print("=== Command quest ===")
    total_args = len(sys.argv)
    if total_args == 1:
        print("No arguments provided!")
    print("Program name:", sys.argv[0])
    if total_args > 1:
        print("Arguments received:", total_args - 1)
    i = 1
    while i < total_args:
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1
    print("total arguments:", total_args)


# if __name__ == "__main__":
#    command_quest()

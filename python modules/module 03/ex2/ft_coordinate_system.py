import sys
import math


def ft_coordinate_system():
    print("===Game Coordinate System ===\n")
    incorrectparam = False
    my_tuple = tuple((10, 20, 5))
    try:
        arg = sys.argv[1]
        param = True
    except IndexError:
        param = False
    if param is True:
        try:
            my_tuple = tuple(int(x) for x in arg.split(","))
            print(f'Parsing coordinates: "{arg}"')
            print(f"Parsed position: {my_tuple}")
        except ValueError as e:
            print(f'Parsing invalid coordinates: "{arg}"')
            print(f"Error parsing coordinates: {e}")
            print("Error details - Type: ValueErrr, Args: "
                  f"(\"{e}\".)")
            incorrectparam = True

    if incorrectparam is False:
        if param is False:
            print("Position created: (10, 20, 5)")
        try:
            result = float(math.sqrt((my_tuple[0])**2 +
                                     (my_tuple[1])**2 +
                                     (my_tuple[2])**2))
            print(f"Distance between (0, 0, 0) and  {my_tuple}: {result:.2f}")
            print("\nUnpacking demonstration:")
            print(f"Player at x={my_tuple[0]}, y={my_tuple[1]}"
                  f", z={my_tuple[2]}")
            print(f"Coordinates: X={my_tuple[0]},"
                  f"Y={my_tuple[1]}, Z={my_tuple[2]}")
        except ValueError:
            pass

# if __name__ == "__main__":
#     ft_coordinate_system()

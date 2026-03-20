def garden_orperations(error_type):
    if error_type == "ValueError":
        try:
            int("abc")
        except ValueError as e:
            print("Caught ValueError:", e)
    elif error_type == "ZeroDivisionError":
        try:
            10 / 0
        except ZeroDivisionError as e:
            print("Caught ZeroDivisionError:", e)
    elif error_type == "FileNotFoundError":
        try:
            file = open("missing.txt")
            file.close()
        except FileNotFoundError as e:
            print("Caught except FileNotFoundError:", e)
    elif error_type == "KeyError":
        try:
            my_dictionary = {"word": 1}
            print(my_dictionary["Hello"])
        except KeyError as e:
            print("Caught KeyError:", e)
    else:
        try:
            int("abc")
            10 / 0
            open("missing.txt")
            my_dictionary = {"word": 1}
            print(my_dictionary["Hello"])
        except (ValueError, ZeroDivisionError, KeyError, FileNotFoundError):
            print("Caught an error, but program continues!")


def test_error_types():
    print("=== Garden Error Types Demo ===")
    print("\nTesting ValueError...")
    garden_orperations("ValueError")
    print("\nTesting ZeroDivisionError...")
    garden_orperations("ZeroDivisionError")
    print("\nTesting FileNotFoundError...")
    garden_orperations("FileNotFoundError")
    print("\nTesting KeyError...")
    garden_orperations("KeyError")
    print("\nTesting multiple errors together...")
    garden_orperations("all")
    print("\nAll error types tested successfully!")


# if __name__ == "__main__" :
#     test_error_types()

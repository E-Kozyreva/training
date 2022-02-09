from vpython import *
import random


def data_for_size():
    print("Select one of the function:")
    print("1.Choose the size of the object yourself.")
    print("2.Generate a size.")
    answer = int(input("Enter your answer here: "))

    if answer == 1:
        x = int(input("Enter the coordinates for the X axis: "))
        y = int(input("Enter the coordinates for the Y axis: "))
        z = int(input("Enter the coordinates for the Z axis: "))

        return x, y, z

    elif answer == 2:
        # Generate random size
        x = random.randint(1, 1_000)
        y = random.randint(1, 1_000)
        z = random.randint(1, 1_000)

        return x, y, z

    else:
        print("You enter a wrong answer.")
        data_for_size()


def choosing_a_color():
    print("\nSelect one of the functions:")
    print("1.Choose the color of the object yourself.")
    print("2.Generate a color.")
    answer = int(input("Enter your answer here: "))

    if answer == 1:
        # Forming the color
        r = int(input("Enter the intensity of the RED color radiation: "))
        g = int(input("Enter the intensity of the GREEN color radiation"))
        b = int(input("Enter the intensity of the BLUE color radiation"))

        return r, g, b

    elif answer == 2:
        # Generate the color
        available_colors_rgb = [0.0, 0.1, 0.2,
                                0.3, 0.4, 0.5,
                                0.6, 0.7, 0.8,
                                0.9, 1]

        r = random.choice(available_colors_rgb)
        g = random.choice(available_colors_rgb)
        b = random.choice(available_colors_rgb)

        return r, g, b

    else:
        print("You enter a wrong answer.")
        choosing_a_color()


def creating_a_cone():
    x, y, z = data_for_size()
    rad = int(input("\nEnter radius: "))
    r, g, b = choosing_a_color()

    element = cone(pos=vector(r, g, b),
                   size=vector(x, y, z),
                   radius=rad)

    dx = 0.01

    while True:
        rate(1/dx)
        element.rotate(angle=1*dx, axis=vector(0, 1, 0))


creating_a_cone()

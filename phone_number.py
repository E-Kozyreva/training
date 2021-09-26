# Enter the number of numbers
count_phone_numbers = int(input())

# Basic tools
all_phone_numbers, type_1, type_2 = [], [], []
checking_1, checking_2, flag = [], [], False

# Available digits in the number
numbers_in_phone = [str(num) for num in range(0, 10)]

# Read the entered numbers
for number in range(count_phone_numbers):
    phone_number = input()
    all_phone_numbers.append(phone_number)

# Available number formats for input
for letter in '(xxx) xxx-xxxx':
    type_1.append(letter)

for letter in 'xxx-xxx-xxxx':
    type_2.append(letter)

# Checking by conditions
for phone_number in all_phone_numbers:

    # Checking the number by the first type
    if len(phone_number) == 14:
        for letter in range(14):
            if phone_number[letter] in numbers_in_phone and type_1[letter] == 'x':
                checking_1.append('number')
            elif phone_number[letter] == type_1[letter] and type_1[letter] != 'x':
                checking_1.append('element')

        if len(checking_1) == 14:
            print(phone_number)
            flag = True

        checking_1.clear()

    # Checking the number by the second type
    elif len(phone_number) == 12:
        for letter in range(12):
            if phone_number[letter] in numbers_in_phone and type_2[letter] == 'x':
                checking_2.append('number')
            elif phone_number[letter] == type_2[letter] and type_2[letter] != 'x':
                checking_2.append('element')

        if len(checking_2) == 12:
            print(phone_number)
            flag = True

        checking_2.clear()

# If there is no suitable number
if not flag:
    print('All phone numbers are incorrect')

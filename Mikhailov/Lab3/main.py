'''
Лабораторная работа № 3:
Методы шифрования: гомофоническая замена
'''

# метод, который шифрует текст
def Encription():
    # сначала идем по самому сообщению
    for i in range(len(message)):
        # далее высчитываем код буквы для шифрования
        for j in range(len(Alphabet)):
            # находим букву в словарике и если количество уже встреченной этой буквы больше
            # количества алфавитов замены, обнуляем счётчик
            addcount = 0
            flagForExecution = True

            if message[i] == Alphabet[j]:
                count = j

                if DictOfChar[message[i]] < numberOfAlphabets:
                    addcount = 32 * DictOfChar[message[i]]

                if DictOfChar[message[i]] < numberOfAlphabets:
                    DictOfChar[message[i]] = int(DictOfChar[message[i]]) + int(1)
                else:
                    DictOfChar[message[i]] = 1

                # и, наконец, записываем в лист с зашифрованным сообщением номер буквы
                Ciphertext.append(int(j) + int(addcount))
                flagForExecution = False

    print('Зашифрованный вариант слова \"' + str(message) + '\" : ' + str(Ciphertext))
    print('Продолжить? +/-')

    choose = input()
   # if choose == '+':

    if choose == '-':
        return 'exit'

# метод, реализующий расшифрование
def Deciphering():
    print('kwa')
    return 'llll'

mess = 'go'

print('Введите преобразуемый текст')
message = input()
numberOfMethod = 0

while mess != 'exit':
    while numberOfMethod != 3:
        print('Выберете метод шифрования: ')
        print('1 - полиалфавитный метод ' + '\n' +
              '2 - полиграммная замена' + '\n' +
              '3 - гомофонический метод' + '\n' +
              '4 - моноалфавитная замена' + '\n' +
              'Введите номер метода: ')
        numberOfMethod = int(input())

        if numberOfMethod != 1 and numberOfMethod != 2 and numberOfMethod != 3 and numberOfMethod != 4:
            print('Такого номера нет в списке! Попробуйте ещё раз: ')

        else:
            if numberOfMethod != 3:
                print('Ошибка! Данный метод не реализован!')
                continue

        print('Выберите действие: ' + '\n' +
              '1 - зашифровать ' + '\n' +
              '2 - расшифровать' + '\n')

        chooseAct = int(input())

    print('Введите количество числовых алфавитов: ')
    numberOfAlphabets = int(input())

    Alphabet = ['_', 'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и',
                'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х',
                'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']

    # в словаре будем подсчитывать количество раз, сколько встретилась буква в слове.
    # если буква встретилась уже больше количества заданных алфавитов, обнуляем счётчик для этой буквы
    DictOfChar = {'_': 0, 'а': 0, 'б': 0, 'в': 0, 'г': 0, 'д': 0, 'е': 0, 'ж': 0, 'з': 0, 'и': 0,
                  'к': 0, 'л': 0, 'м': 0, 'н': 0, 'о': 0, 'п': 0, 'р': 0, 'с': 0, 'т': 0, 'у': 0,
                  'ф': 0, 'х': 0, 'ц': 0, 'ч': 0, 'ш': 0, 'щ': 0, 'ъ': 0, 'ы': 0, 'ь': 0, 'э': 0,
                  'ю': 0, 'я': 0}

    Ciphertext = []

    # реализация шифрования
    if chooseAct == 1:
        mess = Encription()
    if chooseAct == 2:
        mess = Deciphering()
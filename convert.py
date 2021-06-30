with open("./words.txt", "r") as infile:
    words = set([word.strip().upper() for word in infile.readlines()])

with open('./words_upper.txt', 'w') as outfile:
    for word in words:
        outfile.write(f'{word}\n')

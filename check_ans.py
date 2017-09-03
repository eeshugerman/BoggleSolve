with open('ans.txt') as f:
    ans = f.readlines()

with open('check.txt') as f:
    check = f.readlines()

with open('english_words.txt') as f:
    eng_words = f.readlines()


ans = [w.strip() for w in ans]

check = [w.strip() for w in check]



missed = []
for word in check:
    if word not in ans:
        missed.append(word)

print '{} words found'.format(len(ans))
print 'missed {} words:'.format(len(missed))
for word in missed:
    print word

in_dict = []
for word in missed:
    if word in eng_words:
        in_dict.append(word)

print '{} of which are in dictionary'.format(len(in_dict))

count = 0
for word in ans:
    count +=1

print '{} found words are in dictionary'.format(count)

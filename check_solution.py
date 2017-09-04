with open('solution.txt') as f:
    sol = f.readlines()

with open('ref_solution.txt') as f:
    ref_sol = f.readlines()

with open('english_words.txt') as f:
    eng_words = f.readlines()


eng_words = [w.strip() for w in eng_words]
sol = [w.strip() for w in sol]
ref_sol = [w.strip() for w in ref_sol]


in_dict = []
for word in sol:
    if word in eng_words:
        in_dict.append(word)
print '{} words found, {} of which are in dictionary'.format(len(sol), len(in_dict))

print ''

missed = []
for word in ref_sol:
    if word not in sol:
        missed.append(word)
in_dict = []
for word in missed:
    if word in eng_words:
        in_dict.append(word)
print 'missed {} words, {} of which are in dictionary:'.format(len(missed), len(in_dict))
for word in in_dict:
    print word
print ''


extra = []
for word in sol:
    if word not in ref_sol:
        extra.append(word)
print '{} extra words:'.format(len(extra))
for word in extra:
    print word

in_dict = []
for word in extra:
    if word in eng_words:
        in_dict.append(word)
print '{} of which are in dictionary'.format(len(in_dict))

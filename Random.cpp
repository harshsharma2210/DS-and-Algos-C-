# shuffled anagram
def shuffled_anagram(word):
    # input the word, return an anagram or None
    counter = {}

    for letter in word:
        if letter not in counter:
            counter[letter] = 0
        counter[letter] += 1

    def max_freq_remain_ch(ch_ctr, not_this_ch):
        curr_max_freq = 0
        curr_max_ch = None
        for ch in ch_ctr:
            if ch != not_this_ch and ch_ctr[ch] > curr_max_freq:
                curr_max_freq = ch_ctr[ch]
                curr_max_ch = ch

        return curr_max_ch

    result = ""
    n = len(word)
    for i in range(n):
        ch_to_add = max_freq_remain_ch(counter, word[i])
        if ch_to_add == None:
            return None
        else:
            result = result + ch_to_add
            counter[ch_to_add] = counter[ch_to_add] - 1

    return result

num_test_cases = int(input())

for i in range(num_test_cases):
    curr_str = input()
    return_str = shuffled_anagram(curr_str)
    if return_str:
        print(return_str)
    else:
        print("IMPOSSIBLE"
def rotateString(s):
    return s[1:] + s[:1]


def checkAnagram(rotated_string, original_string):
    os_str = 0
    for i in range(len(rotated_string)):
        if rotated_string[i] == original_string[os_str]:
            break
        else:
            os_str += 1
    return len(rotated_string) == os_str


tc = int(input())
for i in range(tc):
    s = input()
    rotated_string = rotateString(s)
    for j in range(len(s)):
        result = "IMPOSSIBLE"
        if rotated_string and checkAnagram(rotated_string, s):
            result = rotated_string
            break
        else:
            rotated_string = rotateString(rotated_string)

    print(f'Case #{i+1}: {result}')

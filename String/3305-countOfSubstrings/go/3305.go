package main

import "fmt"

func countOfSubstrings(word string, k int) int {
	vowels := map[byte]struct{}{'a': {}, 'e': {}, 'i': {}, 'o': {}, 'u': {}}

	count := func(cur_k int) int {
		res := 0
		cur_vowels := make(map[byte]int)
		consonants := 0
		j := 0
		for i := range word {
			for j < len(word) && (len(cur_vowels) < len(vowels) || consonants < cur_k) {
				if _, is_vowel := vowels[word[j]]; is_vowel {
					cur_vowels[word[j]]++
				} else {
					consonants++
				}
				j++
			}

			if len(cur_vowels) == len(vowels) && consonants >= cur_k {
				res += len(word) - j + 1
			}

			if v, exist := cur_vowels[word[i]]; exist {
				if v > 1 {
					cur_vowels[word[i]]--
				} else {
					delete(cur_vowels, word[i])
				}
			} else {
				consonants--
			}
		}
		return res
	}

	return count(k) - count(k+1)
}

func main() {
	word := "ieaouqqieaouqq"
	fmt.Println(countOfSubstrings(word, 1))
}
Class {
	#name : #RomanNumerals,
	#superclass : #Object,
	#category : #'Exercise@RomanNumerals'
}

RomanNumerals >> romanNumber: anInteger [
    |res remain|
    res := ''.
    remain := anInteger.

    dict := {1000 -> 'M'. 900 -> 'CM'. 500 -> 'D'. 400 -> 'CD'. 100 -> 'C'. 90 -> 'XC'. 50 -> 'L'. 40 -> 'XL'. 10 -> 'X'. 9 -> 'IX'. 5 -> 'V'. 4 -> 'IV'. 1 -> 'I'} asOrderedDictionary.

    dict keys do: [:key |
        (remain >= key) ifTrue: [
            [remain >= key] whileTrue: [
                res := res, (dict at: key).
                remain := remain - key.
            ].
        ].
    ].
    
    ^ res
]


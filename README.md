# Password-Strength-Checker

This program allows passwords to be added to a text file and ran through code that queries its strength.
There are specific forms of C that I wanted to test myself with, so I went the long route instead of using simpler code.

The program calls for the three test files and tests them depending of the tests they ask for. The files specify length of passwords and phrases, letter case, symbols, and etc. 

The program returns the # of tests passed, failed and which tests it failed. If a password passes 4 tests, it is considered strong, and the program displays so.

The output follows

------------------

Processing Proposed passwords #1.txt

Maximum password length: 12
Minimum password length: 10
Pass phrases are NOT allowed
Optional Tests are NOT allowed


Potential password: password
The password must be at least 10 characters long.
The password must contain letters, numbers, AND symbols.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false

Potential password: mypassword
The password must contain letters, numbers, AND symbols.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: false
Strong? : false

Potential password: thisismypassword
The password must be fewer than 12 characters.
The password must contain letters, numbers, AND symbols.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false

Potential password: passssword
The password may not contain sequences of three or more repeated characters.
The password must contain letters, numbers, AND symbols.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false

Processing Proposed passwords #2.txt

Maximum password length: 15
Minimum password length: 10
Pass phrases are allowed (Minimum passphrase length: 20)
Optional Tests are allowed (Minimum optional tests to pass: 2)


Potential password: This is my password phrase1
The password must be fewer than 15 characters.
The password must contain at least two digits.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: true
Strong? : false
Total optional tests passed: 3

Potential password: Tinypw1
The password must be at least 10 characters long.
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Ireallydontlikehavingtomakeupnewpasswordsallthetime1
The password must be fewer than 15 characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Iloveyouxxxooo1
The password may not contain sequences of three or more repeated characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Boom**********!
The password may not contain sequences of three or more repeated characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 3

Potential password: IHATEPWORDS1!
The password must contain at least one lowercase letter.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 0
Passed Required Tests: 4
Is a Pass phrase: false
Strong? : true
Total optional tests passed: 1

Potential password: ihatepwords1!
The password must contain at least one uppercase letter.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 0
Passed Required Tests: 4
Is a Pass phrase: false
Strong? : true
Total optional tests passed: 1

Potential password: IHatePwords!
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: IHatePwords
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Just exactly how many words can you include in a password phrase?
The password must be fewer than 15 characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: true
Strong? : false
Total optional tests passed: 3

Processing Proposed passwords #3.txt

Maximum password length: 15
Minimum password length: 10
Pass phrases are allowed (Minimum passphrase length: 20)
Optional Tests are allowed (Minimum optional tests to pass: 4)


Potential password: my pass phrase does not need to pass tests
The password must be fewer than 15 characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least one uppercase letter.
The password must contain at least two digits.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: true
Strong? : false
Total optional tests passed: 2

Potential password: short pass phrase
The password must be fewer than 15 characters.
The password must contain letters, numbers, AND symbols.
The password must contain at least one uppercase letter.
The password must contain at least two digits.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: true
Strong? : false
Total optional tests passed: 2

Potential password: x
The password must be at least 10 characters long.
The password must contain letters, numbers, AND symbols.
The password must contain at least one uppercase letter.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 1

Potential password: x1
The password must be at least 10 characters long.
The password must contain letters, numbers, AND symbols.
The password must contain at least one uppercase letter.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 2
Passed Required Tests: 2
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 1

Potential password: Zxcvbnmnas7
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Zxcvbnmnas~
The password must contain letters, numbers, AND symbols.
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 1
Passed Required Tests: 3
Is a Pass phrase: false
Strong? : false
Total optional tests passed: 2

Potential password: Zxcvbnmnas7~
The password must contain at least two digits.
The password must contain at least two special characters.
Failed Required Tests: 0
Passed Required Tests: 4
Is a Pass phrase: false
Strong? : true
Total optional tests passed: 2

[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-uvnflmuc.0hx" 1>"/tmp/Microsoft-MIEngine-Out-khkluyry.xhj"
vscode ➜ /workspaces/cpp-2 $ 

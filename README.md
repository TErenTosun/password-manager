# password-manager-plus
A (rather primitive) password manager made with C++. It can generate, save and show your passwords.

## Password Creation
### Level System
- Level 1:  8 characters, 1 uppercase
- Level 2:  10 characters, 2 uppercase and 1 special character (e.g. !'^+%&/()= and so on)
- Level 3:  12 characters, 3 uppercase and 2 special characters.

## Password Managing
Saves user passwords into a database.dat file and gets passwords from that said file when needed.
To save the password you must enter;
  - the domain of the site you've made an account in. (e.g. facebook.com)
  - your account's username
  - your password

To retrieve your password from the database enter the domain of the site your account was made in.
The program searches the database and if it finds an entry with that domain name, it returns your account information.

To compile, just run make and it should compile.

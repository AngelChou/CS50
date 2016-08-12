# C$50 Finance / register

## PHP
- variables
  - start with $
  - weakly typed
- associative arrays!
  - $arr = ["a" => 1, "b" => 2, "c" => 3];
  - $arr["a"] equals 1
 - mix HTML with php code
   - <?php //phpcode ?>

## permissions
- folders: ```chmod 711 folder```
- images, HTML, CSS, js: ```chmod 644 file```
  - users shouldn't execute an image!
- php: ```chmod 600 file```
  - users shouldn't see your PHP code!
- ```chmod 644 img/* js/*```
  - everything in the img, js directories readable by everyone

## distribution code
- includes
  - config.php
  - helpers.php
- public
  - php logic here
  - render templates
- views
  - display forms, text, etc.
  - placeholders for variables

## includes/helpers.php
- apologize
- dump
- logout
- lookup($symbol)
  - returns a stock symbol
- redirect
- render
  - outputs a template

## render
- public/hello.php
```php
render("views/hello.php", ["name" => "Milo"]);
```
- views/hello.php
```html
<p>
  Hello, <?= htmlspecialchars($name) ?>
</p>
```
↓
```html
<p>
  Hello, Milo
</p>
```

- public/hello.php
```php
render("views/hello.php", ["msg" => "Who's a good boy?", "name" => "Milo"]);
```
- views/hello.php
```html
<p>
  <?= htmlspecialchars($msg) ?>
  <?= htmlspecialchars($name) ?> is!
</p>
```
↓
```html
<p>
  Who's a good boy?
  Milo is!
</p>
```

## TODO
- register
- quote
- portfolio
- buy
- sell
- history
- extra feature

## register
- display form
- valid passwords?
- add user to database
- log them in

## display form
- copy **login.php** and ** login_form.php**
- ```<form action="register.php" method="post">```
  - send data to **register.php** instead
- Need to make a password **confirmation** field

## valid passwords?
- make sure **$_POST["password"]** and **$_POST["confirmation"]** aren't blank
  - else, apologize
- make sure **$_POST["password"]** and **$_POST["confirmation"]** are the same
  - else, apologize
  - **"omg" == "omg"** in PHP!
  - goodbye, **strcmp**

## apologies
  - ```apologize("Passwords do not match!");```

## usernames
- make sure **$_POST["username"]** isn't blank
  - else, apologize
- usernames are a **UNIQUE** field in the database
- **query** returns **false** on failure
```php
$result = query(...)
if ($result === false)
```
  - then an error occurred (e.g., duplicate username)

## SQL Queries: INSERT
```SQL
INSERT INTO users (username, hash, cash) VALUES ("zamyla", '$1$50$Suq.MOtQj51maacfKvFsW1', 10000.0000)
```
- insers a new row into **users**

## query
- ? is a placeholder
- ```query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], crypt($_POST["password"]));```
- ```query("SELECT * FROM users WHERE username = ?", $_POST["username"]);```

## logging in
- once they register successfully, log them in automatically
- find out their id
```SQL
$rows = query("SELECT LAST_INSERT_ID() AS id");
$id = $rows[0]["id"];
```
- store their id in session
  - ```$_SESSION["id"]```
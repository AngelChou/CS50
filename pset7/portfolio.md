# C$50 Finance / portfolio

## portfolio
- make portfolio table
- display portfolio table

## portfolio table
- users
  - **id**
  - username
  - hash
  - cash
- portfolios
  - **id**
  - symbol
  - shares
  
## displaying the portfolio
- query returns an array of rows
```php
$rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
foreach ($row as $row)
{
  print("<tr>");
  print("<td>{$row["symbol"]}</td>");
  print("<td>{$row["shares"]}</td>");
  print("</tr>");
}
```

## displaying the portfolio
- **index.php is the *controller*
  - ```render("portfolio.php", ...);```
- **portfolio.php** is the *view*
  - what variables does it need?
- report, at minimum:
  - each of the stocks in a user's portfolio
    - number of shares
    - current value (price times number)
  - user's current cash balance

# C$50 Finance / quote

## quote
- display form
  - get stock symbol
- retrieve stock quote
- display stock quote

## display form
- quote template: form for stock lookup
  - **quote_form.php**
  - form input: **symbol** the user wants to look up
- form actions: send to controller
  - **quote.php**

## lookup
```$s = lookup("AAPL")```
- returns an associative array
  - symbol
  - name
  - price

## displaying stock information
- another template: quote.php
- at minimum, display quote
- ensure the stock is valid
  - else: apologize, as usual
```print("Price: " . $s["price"]);```
but, need to format to 2 to 4 decimal places: number_format.
